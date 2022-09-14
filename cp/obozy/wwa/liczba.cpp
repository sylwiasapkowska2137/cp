#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define pii pair<int, int>
#define st first
#define nd second
#define pb push_back
#define debug(x) cerr << x << " "

const int MAXD = 507, MAXS = 5007;
pii parent[MAXD][MAXS];
bool vis[MAXD][MAXS];

void bfs(int d, int s){
	queue<pii>q;
	q.push({0, 0});
	parent[0][0] = {-1, -1};
	vis[0][0] = 1;
	while (!q.empty()){
		pii v = q.front(); //reszta z dzielenia przez d + suma cyfr
		q.pop();
		for (int digit = 0; digit<10; digit++){
			pii x = {v.st*10+digit, v.nd+digit};
			if (x.st >= d) x.st%=d;
			if (!vis[x.st][x.nd] && x.nd <= s){
				parent[x.st][x.nd] = v;
				q.push(x);
				vis[x.st][x.nd] = 1;
				//debug(x.st);
				//debug(x.nd);
				//cerr << "\n";
			}
		}
	}
}

int main(){ //<3
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int d, s;
	cin >> d >> s;
	bfs(d, s);
	//debug("a");
	pii koniec = {0, s};
	if (!vis[0][s]){
		cout << "-1\n";
		return 0;
	}
	int prev = s, curr;
	stack<int>S;
	while (koniec.st != -1){
		S.push(prev-koniec.nd);
		prev = koniec.nd;
		koniec = parent[koniec.st][koniec.nd];
	}
	while (S.size()>1){
		cout << S.top();
		S.pop();
	}
	cout << "\n";
	return 0;
}
