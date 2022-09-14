#include <bits/stdc++.h>
using namespace std;

#define LL long long
#define pb push_back
#define pii pair <int, int>
#define st first
#define nd second
#define debug(x) cerr << x << " "

const int MAX = 200;
bool vis[MAX][MAX];
int dist[MAX][MAX];
int x[] = {1, -1, 0, 0};
int y[] = {0, 0, -1, 1};

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n, m;
	cin >> n >> m;
	queue<pii>q;
	char ch;
	for (int i = 1; i<=n; i++){
		for (int j = 1; j<=m; j++){
			cin >> ch;
			if (ch == '1'){
				q.push({i, j});
				vis[i][j] = 1;
			}
		}
	}
	
	while (!q.empty()){
		pii v = q.front();
		q.pop();
		for (int i = 0; i<4; i++){
			pii s = {v.st+x[i], v.nd+y[i]};
			if (s.st > 0 && s.st <= n && s.nd > 0 && s.nd <= m){
				if (!vis[s.st][s.nd]){
					vis[s.st][s.nd] = 1;
					dist[s.st][s.nd] = dist[v.st][v.nd]+1;
					q.push(s);
				}
			}
		}
	}
	for (int i = 1; i<=n; i++){
		for (int j = 1; j<=m; j++) cout << dist[i][j] << " ";
		cout << "\n";
	}
}
