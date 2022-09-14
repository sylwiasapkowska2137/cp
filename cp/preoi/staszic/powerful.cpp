#include <bits/stdc++.h>
using namespace std;

#define LL long long
#define ULL unsigned LL 
#define debug(x) cerr << x << " "
#define pb push_back

const int MAX = 1e6+7, S = 450;
LL freq[MAX];
vector<int>a;
struct q{int l, r, i;};
vector<q> query;
vector<LL>ans;
LL cnt = 0;

bool cmp(q a, q b){
	if (a.l/S == b.l/S) return a.r < b.r;
	return a.l < b.l;
}

void add(int v){
	LL tmp = (LL)(a[v]*freq[a[v]]*freq[a[v]]);
	cnt-=tmp;
	freq[a[v]]++;
	tmp = (LL)(a[v]*freq[a[v]]*freq[a[v]]);
	cnt+=tmp;
}

void remove(int v){
	ULL tmp = (ULL)(a[v]*freq[a[v]]*freq[a[v]]);
	cnt-=tmp;
	freq[a[v]]--;
	tmp = (LL)(a[v]*freq[a[v]]*freq[a[v]]);
	cnt+=tmp;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, t;
	cin >> n >> t;
	a.resize(n+1);
	for (int i = 1; i<=n; i++) cin >> a[i];
	query.resize(t);
	ans.resize(t);
	for (int i = 0; i<t; i++){
		cin >> query[i].l >> query[i].r;
		query[i].i = i;
	}
	sort(query.begin(), query.end(), cmp);
	int L = 0, R = 0;
	for (auto x: query){
		while(L > x.l) add(--L);
		while (R < x.r)	add(++R);
		while (L < x.l)	remove(L++);
		while (R > x.r)	remove(R--);
		ans[x.i] = cnt;
	}
	for (int i = 0; i<t; i++) cout << ans[i] << "\n";
	return 0;
}	
