#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define debug(x) cerr << x << " "
#define pii pair<int, int>
#define st first
#define nd second
#define pb push_back

const int MAX = 1e5+7;
pii tab[2][MAX];
vector<pii>p;
int k, n;

LL dist(pii a, pii b){
	LL x = (LL)(a.st-b.st)*(LL)(a.st-b.st);
	LL y = (LL)(a.nd-b.nd)*(LL)(a.nd-b.nd);
	return x+y;
}

int iloczyn(pii a, pii b, pii c){
	pair<LL, LL> x = {b.st-a.st, b.nd-a.nd};
	pair<LL, LL> y = {c.st-a.st, c.nd-a.nd};
	if (x.st * y.nd - x.nd * y.st > 0) return 1;
	if (x.st * y.nd - x.nd * y.st < 0) return -1;
	return 0;
}

bool cmp(pii a, pii b){
	if (iloczyn(tab[k][1], a, b) == (-1)) return 0;
	if (iloczyn(tab[k][1], a, b) == 1) return 1;
	return dist(a, tab[k][1]) < dist(b, tab[k][1]);
}

int binsearch(pii x){
	int ans = -1, start = 1, koniec = p.size()-1;
	while (koniec > start){
		int m = (start+koniec)/2;
		if (iloczyn(p[0], p[m], x)<=0) {
			koniec = m-1;
		} else {
			start = m;
			ans = m;
		}
	}
	return ans;
}

void solve(){
	for (int i = 2; i<=n; i++){
		if (tab[k][i].st == tab[k][1].st) if (tab[k][i].nd < tab[k][1].nd) swap(tab[k][1], tab[k][i]);
		if (tab[k][i].st < tab[k][1].st) swap(tab[k][1], tab[k][i]);
	}
	sort(tab[k]+2, tab[k]+n+1, cmp);
	tab[k][n+1] = tab[k][1];
	
	p.clear();
	for (int i = 1; i<=n+1; i++){
		while (p.size()>1 && iloczyn(p[p.size()-2], p.back(), tab[k][i])<=0) p.pop_back();
		p.pb(tab[k][i]);
	}
	p.pop_back();
	int l = k^1, ans = 0;
	
	
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	for (int i = 1; i<=n; i++) cin >> tab[0][i].st >> tab[0][i].nd;
	for (int i = 1; i<=n; i++) cin >> tab[1][i].st >> tab[1][i].nd;
	
	solve();
	k = 1;
	//solve();
	
	return 0;
}
