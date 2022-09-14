#include <bits/stdc++.h>
using namespace std; 
typedef vector<int> vi;
#define rep(i, a, b) for (int i=a; i<(b); i++)
#define sz(x) (int)(x).size()
#define all(x) x.begin(), x.end()

int ans = 0;

void solve1(int M, int v, vi &a, int n){
	vi pref(n+1, 0), first(2*n+1, -1);
	rep(i, 0, n){
		pref[i+1] = pref[i];
		if (a[i+1] == v) pref[i+1]++;
		else if (a[i+1] == M) pref[i+1]--;
	}
	rep(i, 0, n+1){
		int x = pref[i]+n;
		if (first[x] == -1){
			first[x] = i;
		} else {
			ans = max(ans, i-first[x]);
		}
	}
}

void solve2(int x, vi &a, int n){
	vi b(n+1, 0);
	int tmp = 0, l = 1;
	rep(r, 1, n+1){
		b[a[r]]++;
		if (b[a[r]] == x) tmp++;
		else {
			while (b[a[r]] > x) {
				b[a[l]]--; 
				if (b[a[l]] == x-1) tmp--;
				l++;
			}
		}
		if (tmp >= 2) ans = max(ans, r-l+1);
	}
}

void solve(){
	int n; cin >> n;
	vi a(n+1), cnt(n+1, 0);
	rep(i, 1, n+1) {
		cin >> a[i];
		cnt[a[i]]++;
	}
	int maxi = *max_element(all(cnt));
	int ile = 0, M;
	rep(i, 1, n+1) {
		if (cnt[i] == maxi) {
			ile++;
			M = i;
		}
	}
	if (ile >= 2){
		cout << n << "\n";
		return;
	}
	int s = max(1,(int)sqrt(n));
	rep(i, 1, n+1){
		if (cnt[i] == maxi) continue;
		if (cnt[i] >= s) solve1(M, i, a, n);
	}
	rep(i, 1, s) solve2(i, a, n);
	cout << ans << "\n";
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	solve();
	
	return 0;
}
