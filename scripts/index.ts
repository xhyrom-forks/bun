import { join } from "path";
import fetchIssues from "./utils/fetchIssues";
import { parse } from "yaml";

const issues = await fetchIssues();
const template = await Bun.file(join(import.meta.dir, '..', 'README.template.md')).text();

let INP = "";
let RO = "";

for (const issue of issues) {
    if (issue.user.login !== 'xHyroM') continue;

    const body = parse(issue.body);
    const content = `- [${body.branch}](https://github.com/xhyrom-forks/bun/tree/${body.branch}) ${body.pr ? `| [#${body.pr}](https://github.com/oven-sh/bun/pull/${body.pr})` : ''}\n`;
    if (issue.state === 'open') {
        RO += content;
    } else {
        INP += content;

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
        })
    }
}

await Bun.write(join(import.meta.dir, '..', 'README.md'), template.replace('{INP}', INP).replace('{RO}', RO));
