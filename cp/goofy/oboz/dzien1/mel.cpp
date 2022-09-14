#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
 
using namespace std;
 
typedef long long LL;
typedef long double LD;
 
typedef pair<int, int> pii;
typedef pair<LL,LL> pll;
typedef pair<LD,LD> pdd;
 
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<LD> vld;
typedef vector<LL> vll;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
 
template<class T> using pq = priority_queue<T>;
template<class T> using pqg = priority_queue<T, vector<T>, greater<T>>;
 
#define rep(i, a, b) for (int i=a; i<(b); i++)
#define repd(i,a,b) for (int i = (a); i >= b; i--)
#define sz(x) (int)(x).size()
#define pb push_back
#define st first
#define nd second
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()
#define memo(x) memset(x, 0, sizeof(x))
#define debug(x) cerr << x << " "


void solve(){
	int n; cin >> n;
	vi a(n), scaler(n);
	rep(i, 0, n) {
		cin >> a[i];
		scaler[i] = a[i];
	}
	sort(all(scaler));
	scaler.erase(unique(all(scaler)), scaler.end());
	map<int, int>mapa;
	rep(i, 0, sz(scaler)) mapa[scaler[i]] = i;
	rep(i, 0, n) a[i] = mapa[a[i]];
	
	//longest increasing subarray ending and starting at fixed position
	vi starting(n), ending(n);
	ending[0] = 1;
	rep(i, 1, n){
		if (a[i]>a[i-1]) ending[i] = ending[i-1]+1;
		else ending[i] = 1;
	}
	starting[n-1] = 1;
	repd(i, n-2, 0){
		if (a[i]<a[i+1]) starting[i] = starting[i+1]+1;
		else starting[i] = 1;
	}
	/*
	//dbg
	rep(i, 0, n) debug(a[i]);
	cerr << "\n";
	rep(i, 0, n) debug(start[i]);
	cerr << "\n";
	rep(i, 0, n) debug(end[i]);
	cerr << "\n";
	*/
	
	//no swaps
	int ans = 1;
	rep(i, 0, n) ans = max(ans, starting[i]);
	
	//with one swap
	
	//1. zamiana sąsiadow
	rep(i, 1, n){
		//i z i-1
		if (a[i]>=a[i-1]) continue;
		//i-2, i, i-1, i+1
		int tmp = 2;
		if (i-2>=0 && a[i-2]<a[i]) tmp += ending[i-2];
		if (i+1<n && a[i-1]<a[i+1]) tmp += starting[i+1];
		ans = max(ans, tmp);
	}
	//debug(ans);
	//2. zamiana na koncach
	
	rep(i, 1, n){
		int left = i-1-ending[i-1];
		//debug(i);
		//debug(left);
		if (left<=0) continue;
		//[left-1] i [left+1, i-1] left [i+1];
		
		int tmp = ending[left-1];
		
		if (a[left-1]<a[i]) tmp++;
		else tmp = 1;
		ans = max(ans, tmp);
		
		if (a[i]<a[left+1]) tmp+=(i-left-1);
		else tmp = i-left-1;
		ans = max(ans, tmp);
		
		if (a[i-1]<a[left]) tmp++;
		else tmp = 1;
		ans = max(ans, tmp);
		
		if (i+1<n){
			if (a[left]<a[i+1])tmp += starting[i+1];
			else tmp = starting[i+1];
		
		}
		
		//debug(tmp);
		//cerr << "\n";
		ans = max(ans, tmp);
	}
	cerr << "\n";
	
	
	
	debug(ans);
	
	//3. zamiana z czymstam
	set<int>s;
	rep(i, 0, n) s.insert(a[i]);
	rep(i, 1, n-1){
		int X = *s.ub(a[i-1]);
		if (X<a[i+1]) ans = max(ans, ending[i-1]+starting[i+1]+1);
	}
	
	cout << ans << "\n";
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int t = 1;
	//cin >> t;
	while (t--) solve();
	
	return 0;
}
