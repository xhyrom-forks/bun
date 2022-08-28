export interface Issue {
    number: number;
    state: 'open' | 'closed';
    user: {
        login: string;
    }
    body: string;
    title: string;
}

export default async(repository: string = 'xhyrom-forks/bun') => {
    const issues: Issue[] = [];
    let page = 1;

    while(true) {
        const res = await (await fetch(`https://api.github.com/repos/${repository}/issues?per_page=100&page=${page}&state=all`, {
            headers: {
                'Content-Type': 'application/json',
                'User-Agent': 'xhyrom-forks-bun-global_info',
                'Authorization': `token ${process.env.GITHUB_TOKEN}`
            }
        })).json() as Issue[];

        for (const issue of res) {
            if ('pull_request' in issue) continue;

            issues.push(issue);
        }

        page++;
        if (res.length === 0) break;
    }

    return issues;
}