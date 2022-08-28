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
    const content = `- [${body.branch}](https://github.com/xhyrom-forks/bun/tree/${body.branch}) ${body.pr ? `| [${body.pr}](https://github.com/oven-sh/bun/pull/${body.pr})` : ''}\n`;
    if (issue.state === 'open') {
        RO += content;
    } else {
        INP += content;
    }
}

await Bun.write(join(import.meta.dir, '..', 'README.md'), template.replace('{INP}', INP).replace('{RO}', RO));
