#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define pii pair<int, int>
#define st first
#define nd second
#define debug(x) cerr << x << " "
#define pb push_back
#define rep(i, a, b) for (int i = a; i<b; i++)
#define repd(i, a, b) for (int i = a; i>=b; i--)

struct segtree{
	vector<int>tab;
	int size = 1;
	
	void init(int n, vector<int>freq){
		while (size < n) size*=2;
		tab.assign(2*size+1, 0); 
		rep(i, 0, freq.size()) tab[i+size] = freq[i]*i;
		repd(i, size-1, 1) tab[i] = tab[2*i]+tab[2*i+1];
	}
	
	
	int suma(int l, int r){
		l = l+size-1;
		r = r+size+1;
		int ans = 0;
		while (r-l>1){
			if (!(l&1)) ans += tab[l+1];
			if (r&1) ans += tab[r-1];
			l/=2;r/=2;
		}
		return ans;
	}
};

void solve(){
	int n;cin >> n;
	vector<int>a(n);
	map<int, int>mapa;
	rep(i, 0, n) {
		cin >> a[i];
		mapa[a[i]]++;
	}
	vector<int>freq(n+1, 0);
	for (auto x: mapa){
		freq[x.nd]++;
	}
	int ilewiekszych = 0;
	for (auto x: freq) ilewiekszych+=x;
	//cerr << "\n";
	segtree seg;
	seg.init(n+1, freq);
	int ans = n;
	rep (c, 1, n+1){
		ilewiekszych -= freq[c];
		//debug(ilewiekszych);
		//debug(seg.suma(0, c-1));
		int x = seg.suma(0, c-1)+seg.suma(c+1, n+1)-c*ilewiekszych;
		//debug(seg.suma(c+1, n+1)-c*ilewiekszych);
		//debug(x);
		
		//cerr << "\n";
		ans = min(ans, x);
		
	}
	cout << ans << "\n";
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int t;
	cin >> t;
	while (t--) solve();
	
	return 0;
}
