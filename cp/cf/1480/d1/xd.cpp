#include <bits/stdc++.h>

using namespace std;

#define pb push_back
const int nax = 1e5 + 5;
vector< int > G[nax];
int a, b, m, n, col[nax];
bitset< nax > odw;

void edge()
{
    G[a].pb(b);
    G[b].pb(a);
}

bool dfs(int v, int pa = -1, bool cl = 1)
{
    odw[v] = 1;
    col[v] = cl;
    for (auto a : G[v])
    {
        if (!odw[a]) dfs(a, v, !cl);
    }
    for (auto x: G[a]){
		if (col[v] == col[x]) return 0;
	}
    return 1;
}

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        cin >> a >> b;
        edge();
    }
    for (int i = 1; i <= n; i++)
    {
        if (odw[i] == 0)
        {
            if (dfs(i, 1) == 0)
            {
                cout << "IMPOSSIBLE";
                return 0;
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        cout << col[i] + 1 << " ";
    }
}
