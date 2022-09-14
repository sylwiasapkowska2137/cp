//Sylwia Sapkowska
//template from https://codeforces.com/profile/Geothermal
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
using ordered_set = tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>;
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

const int MAX = 3e5+7;
string s;
int n;

LL check(int l, int r, pair<char, char>others){
	if (r < l) return 0;
	LL ans = 0LL;
	map<int, LL>mapa;
	mapa[0] = 1;
	int a = 0, b = 0;
	rep(i, l, r+1){
		if (s[i] == others.st) a++;
		else b++;
		ans += mapa[a-b];
		mapa[a-b]++;
	}
	/*
	debug(l);
	debug(r);
	debug(ans);
	cerr << "\n";
	*/
	return ans;
}

LL checkall(){
	map<pii, LL>abc;
	LL res = 0LL;
	int cnt[] = {0, 0, 0};
	abc[{0, 0}] = 1;
	rep(i, 0, n){
		cnt[s[i]-'a']++;
		pii curr = {cnt[0]-cnt[1], cnt[0]-cnt[2]};
		res += abc[curr];
		abc[curr]++;
	}
	return res;
}

LL checktwo(char c){
	int l = 0,r = 0;
	LL res = 0LL;
	while (l<n){
		if (s[l]!=c){
			l++;
			continue;
		}
		r = l;
		while (r < n && s[r]==c) {
			r++;
			res += (LL)(r-l);
		}
		l = r;
	}
	return res;
}

void solve(){
	//cin >> s;
	rep(i, 0, 100000){
		s+="abc";
	}
	n = sz(s);
	
	LL res = checkall();
	for (char c = 'a'; c<='c'; c++) res += checktwo(c);
	
	map<char, pair<char, char>>convert;
	convert['a'] = {'b', 'c'};
	convert['b'] = {'a', 'c'};
	convert['c'] = {'a', 'b'};
	for (char c = 'a'; c<='c'; c++){ //without character c
		vi tab;
		tab.pb(-1);
		rep(i, 0, n) if (s[i] == c) tab.pb(i);
		tab.pb(n);
		rep(i, 1, sz(tab)) res += check(tab[i-1]+1, tab[i]-1, convert[c]);
	}
	
	cout << res << "\n";
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int t = 1;
	//cin >> t;
	while (t--) solve();
	
	return 0;
}
