import { join } from "path";
import fetchIssues, { type Issue } from "./utils/fetchIssues";
import { parse } from "yaml";

type PullRequest = Issue & {
    merged_at: string | null;
}

const issues = await fetchIssues();
const template = await Bun.file(join(import.meta.dir, '..', 'README.template.md')).text();

let INP = "";
let RO = "";

for (const issue of issues) {
    if (issue.user.login !== 'xHyroM') continue;

    const body = parse(issue.body);
    const content = `- [${body.branch}](https://github.com/xhyrom-forks/bun/tree/${body.branch}) ${body.pr ? `| [#${body.pr}](https://github.com/oven-sh/bun/pull/${body.pr})` : ''}`;
    const pullRequest = await (await fetch(`https://api.github.com/repos/oven-sh/bun/pulls/${body.pr}`, {
        headers: {
            'Content-Type': 'application/json',
            'Accept': 'application/vnd.github+json',
            'User-Agent': 'xhyrom-forks-bun-global_info',
            'Authorization': `token ${process.env.GITHUB_TOKEN}`
        },
    })).json() as PullRequest;

    if (pullRequest.state === 'closed' && issue.state === 'open') {
        // FINISH
        await fetch(`https://api.github.com/repos/xhyrom-forks/bun/issues/${issue.number}`, {
            method: 'PATCH',
            headers: {
                'Content-Type': 'application/json',
                'Accept': 'application/vnd.github+json',
                'User-Agent': 'xhyrom-forks-bun-global_info',
                'Authorization': `token ${process.env.GITHUB_TOKEN}`
            },
            body: JSON.stringify({
                state: 'closed',
                labels: ['read-only'],
                title: `[RO] ${body.branch}`,
            })
        });

        issue.state = 'closed'
    }

    if (issue.state === 'open') {
        INP += `${content}  \n`;

        if (issue.locked) continue;

        await fetch(`https://api.github.com/repos/xhyrom-forks/bun/issues/${issue.number}/comments`, {
            method: 'POST',
            headers: {
                'Content-Type': 'application/json',
                'Accept': 'application/vnd.github+json',
                'User-Agent': 'xhyrom-forks-bun-global_info',
                'Authorization': `token ${process.env.GITHUB_TOKEN}`
            },
            body: JSON.stringify({
                body: `Closes after [#${body.pr}](https://github.com/oven-sh/bun/pull/${body.pr})`
            })
        });


        await fetch(`https://api.github.com/repos/xhyrom-forks/bun/issues/${issue.number}/lock`, {
            method: 'PUT',
            headers: {
                'Content-Type': 'application/json',
                'Accept': 'application/vnd.github+json',
                'User-Agent': 'xhyrom-forks-bun-global_info',
                'Authorization': `token ${process.env.GITHUB_TOKEN}`
            },
            body: JSON.stringify({
                lock_reason: 'off-topic'
            })
        });

        await fetch(`https://api.github.com/repos/xhyrom-forks/bun/issues/${issue.number}`, {
            method: 'PATCH',
            headers: {
                'Content-Type': 'application/json',
                'Accept': 'application/vnd.github+json',
                'User-Agent': 'xhyrom-forks-bun-global_info',
                'Authorization': `token ${process.env.GITHUB_TOKEN}`
            },
            body: JSON.stringify({
                labels: ['in progress'],
                title: `[INP] ${body.branch}`,
            })
        });
    } else {
        RO += `${content} ${pullRequest.merged_at ? '🎉 landed' : ':( closed'}  \n`;
    }
}

await Bun.write(join(import.meta.dir, '..', 'README.md'), template.replace('{INP}', INP).replace('{RO}', RO));
