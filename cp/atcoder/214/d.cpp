#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define pii pair<int, int>
#define st first
#define nd second
#define pb push_back
#define debug(x) cerr << x << " "
#define rep(i, a, b) for (int i = a; i<b; i++)

const int MAX = 1e5+7;
int REP[MAX], Size[MAX];
LL ans = 0;


struct e{
	int a, b, c;
};

bool cmp(e a, e b){
	return a.c < b.c;
}

int Find(int a){
	if (a == REP[a]) return a;
	return REP[a] = Find(REP[a]);
}

void Union(int a, int b, int c){
	if (a>b) swap(a, b);
	a = Find(a);
	b = Find(b);
	REP[b] = a;
	ans += ((LL)Size[a]*(LL)Size[b]*(LL)c);
	Size[a] += Size[b];
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n, a, b, c;
	cin >> n;
	vector<e>edges;
	rep(i, 1, n+1) REP[i] = i;
	rep(i, 1, n+1) Size[i] = 1;
	rep(i, 1, n){
		cin >> a >> b >> c;
		edges.pb({a, b, c});
	}
	sort(edges.begin(), edges.end(), cmp);
	for (auto x: edges)	Union(x.a, x.b, x.c);
	cout << ans << "\n";
	return 0;
}



