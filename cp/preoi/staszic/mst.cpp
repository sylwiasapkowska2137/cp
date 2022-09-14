#include <bits/stdc++.h>
using namespace std;

#define LL long long
#define ULL unsigned LL
#define LD long double
#define debug(x) cerr << x << " "
#define st first
#define nd second
#define pii pair<int, int>
#define pb push_back
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

struct edge{
	int a, b, c, i;
	edge(int a, int b, int c, int i): a(a), b(b), c(c), i(i) {}
};

bool cmp (edge a, edge b){
	return (a.c < b.c);
}

vector <int> rep, ile;
vector<edge> tab;

int Find(int a){
	if (rep[a] == a) return a;
	rep[a] = Find(rep[a]);
	return rep[a];
}

void Union(int a, int b){
	a = Find(a);
	b = Find(b);
	if (a!=b){
		if (ile[a]<ile[b]) swap(a, b);
		rep[b] = a;
		if (ile[a]==ile[b]) ile[a]++;
	}
}

int main(){
	fastio;
	
	int n, m, a, b, c;
	cin >> n >> m;
	rep.resize(n+1);
	ile.resize(n+1);
	for (int i = 0; i<m; i++){
		cin >> a >> b >> c;
		tab.pb({a, b, c, i});
	}
	for (int i = 0; i<=n; i++){
		rep[i] = i;
		ile[i] = 0;
	}
	sort(tab.begin(), tab.end(), cmp);
	LL ans = 0;
	for (auto x: tab){
		if (Find(x.a) != Find(x.b)){
			ans+=x.c;
			Union(x.a, x.b);
		}
	}
	cout << ans;
	return 0;
}


