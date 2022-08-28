import { join } from "path";
import fetchIssues, { type Issue } from "./utils/fetchIssues";
import { parse } from "yaml";

const issues = await fetchIssues();
const template = await Bun.file(join(import.meta.dir, '..', 'README.template.md')).text();

let INP = "";
let RO = "";

for (const issue of issues) {
    if (issue.user.login !== 'xHyroM') continue;

    const body = parse(issue.body);
    const content = `- [${body.branch}](https://github.com/xhyrom-forks/bun/tree/${body.branch}) ${body.pr ? `| [#${body.pr}](https://github.com/oven-sh/bun/pull/${body.pr})` : ''}\n`;
    const pullRequest = await (await fetch(`https://api.github.com/repos/oven-sh/bun/pulls/${body.pr}`, {
        headers: {
            'Content-Type': 'application/json',
            'Accept': 'application/vnd.github+json',
            'User-Agent': 'xhyrom-forks-bun-global_info',
            'Authorization': `token ${process.env.GITHUB_TOKEN}`
        },
    })).json() as Issue;
    if (pullRequest.state === 'closed') {
        // FINISH
    }

    if (issue.state === 'open') {
        INP += content;

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
    } else {
        RO += content;
    }
}

await Bun.write(join(import.meta.dir, '..', 'README.md'), template.replace('{INP}', INP).replace('{RO}', RO));
