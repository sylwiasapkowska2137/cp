#include <bits/stdc++.h>
using namespace std;

#define LL long long
#define debug(x) cerr << x << " "
#define pb push_back
#define pii pair<int, int>
#define st first
#define nd second

const int MAX = 307*307;
int x[] = {-1, 1, 0, 0};
int y[] = {0, 0, -1, 1};
bool ch[n+1][m+1];
int n, m;
vector <int> graf[MAX];

void skojarzenie(){
	mt.assign(k, -1);
    vector<bool> used1(n, false);
    for (int v = 0; v < n; ++v) {
        for (int to : g[i]) {
            if (mt[to] == -1) {
                mt[to] = v;
                used1[v] = true;
                break;
            }
        }
    }
    for (int v = 0; v < n; ++v) {
        if (used1[v])
            continue;
        used.assign(n, false);
        try_kuhn(v);
    }

    for (int i = 0; i < k; ++i)
        if (mt[i] != -1)
            printf("%d %d\n", mt[i] + 1, i + 1);
}

void solve(){
	char c;
	cin >> n >> m;
	for (int i = 1; i<=n; i++){
		for (int j = 1; j<=m; j++){
			cin >> c;
			if ((i+j) % 2 == 1){
				
			}
			if (c) ch[i][j] = 1;
		}
	}
	
	skojarzenie();
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while (t--)solve();
	return 0;
}
