#include <bits/stdc++.h>
//#pragma GCC optimize("Ofast")
//#pragma GCC optimize ("unroll-loops")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

//szablon czesciowo skopiowany z profilu https://codeforces.com/profile/Geothermal
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
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
LL losuj(LL a, LL b){ return a+rng()%(b-a+1);}

void solve(){
	int n; cin >> n;
	string s; cin >> s;
	bool rev=0;
	queue<pair<int, pii>>Q; // wartosci postaci {czy odwrocone,{lewy, prawy}}
	Q.push({0,{0,n-1}});
	LL ans = 0;
	set<char>S = {'a','e','i','o','u'};
	while(!Q.empty()){
		bool rev = Q.front().st;
		int l = Q.front().nd.st, r = Q.front().nd.nd;
		Q.pop();
		if(l==r){
			ans++;
			continue;
		}
		if(rev==0){
			if(S.count(s[l])) Q.push({1,{l+1,r}});
			if(!S.count(s[r])) Q.push({0,{l,r-1}});
		}
		else{
			if(!S.count(s[l])) Q.push({1,{l+1,r}});
			if(S.count(s[r])) Q.push({0,{l,r-1}});
		}
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
