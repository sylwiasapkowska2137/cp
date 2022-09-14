#include <bits/stdc++.h>
using namespace std;

#define st first
#define nd second
#define pii pair<int,int>
#define LL long long

const int MAX = 2e3+7;
bool vis[MAX][MAX];
queue <pii> q;
pii graf[MAX][MAX];
map <LL, int> res;
int ox[] = {-1, 0, 1, 0};
int oy[] = {0, -1, 0, 1};
int n, m;

void bfs(){
	vis[1][1] = true;
	q.push({1, 1});
	while (!q.empty()){
		pii v = q.front();
		q.pop();
		for (int i = 0; i<4; i++){
			pii sasiad = {v.st+ox[i], v.nd+oy[i]};
			if (sasiad.st >=1 && sasiad.st <=n && sasiad.nd >=1 && sasiad.nd <= m){
				if (!vis[sasiad.st][sasiad.nd]){
					vis[sasiad.st][sasiad.nd] = true;
					if (ox[i]+oy[i]<0) graf[sasiad.st][sasiad.nd] = {graf[v.st][v.nd].st+1,graf[v.st][v.nd].nd};
					else graf[sasiad.st][sasiad.nd] = {graf[v.st][v.nd].st, graf[v.st][v.nd].nd+1};
					q.push(sasiad);	
				}
			}
		}
		
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int k;
	pii t;
	cin >> n >> m >> k;
	char x;
	for (int i = 1; i<=n; i++){
		for (int j = 1; j<=m; j++){
			cin >> x;
			if (x == 'X') vis[i][j] = true;
		}
	}
	bfs();
	while (k--){
		cin >> t.st >> t.nd;
		LL tmp = (LL)t.nd*(LL)graf[n][m].st+(LL)t.st*(LL)graf[n][m].nd;
		res[tmp]++;
	}
	auto it = res.begin();
	cout << it->st << " " << it->nd << "\n";
	return 0;
}
