#include <bits/stdc++.h>
using namespace std;

#define LL long long
#define debug(x) cerr << x << " "
#define pii pair<int, int>
#define st first
#define nd second
#define pb push_back


const int MAXN = 1e6+7, MAXQ = 1e5+7, A = 1007, S = 450;
struct query{
	int l, r, i;
};
int tab[MAXN], freq[A], ans[MAXQ];
query a[MAXQ];
int cnt;

bool cmp(query a, query b){
	if (a.l/S == b.l/S) return a.r < b.r;
	return a.l < b.l;
}

void add(int v){//indeks v
	freq[tab[v]]++;
	if (freq[tab[v]] == 1) cnt++; 
}

void remove(int v){
	freq[tab[v]]--;
	if (freq[tab[v]] == 0) cnt--; 
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n, q;
	cin >> n >> q;
	for (int i = 1; i<=n; i++)cin >> tab[i];
	for (int i = 1; i<=q; i++){
		cin >> a[i].l >> a[i].r;
		a[i].i = i;
	}
	sort(a+1, a+q+1, cmp);
	int L = 0, R = 0;
	for (int i = 1; i<=q; i++) {
		query x = a[i];
		while (L>x.l) add(--L);
		while (R < x.r) add(++R);
		while (L < x.l)	remove(L++);
		while (R > x.r)	remove(R--);
		ans[x.i] = cnt;
	}
	for (int i = 1; i<=q; i++) cout << ans[i] << "\n";
	return 0;
}
