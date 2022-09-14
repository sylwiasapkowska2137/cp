//Sylwia Sapkowska
#include <bits/stdc++.h>
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
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
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
#define PI 3.14159265359

int p(int a, int b){
	return a+rng()%(b-a+1);
}

bool cmp(pair<int, char>a, pair<int, char>b){
	return a.nd < b.nd;
}

void solve(){
	string s; cin >> s;
	int n = sz(s);
	map<char, int>cnt;
	vector<pair<int, char>> occ;
	rep(i, 0, n){
		cnt[s[i]]++;
		if (cnt[s[i]] == 1){
			occ.pb({i, s[i]});
		}
	}
	vector<pair<int, char>> occ2 = occ;
	sort(all(occ2), cmp);
	rep(i, 0, sz(occ)){
		if (occ[i] != occ2[i]){
			debug(occ[i].nd);
			debug(occ2[i].nd);
			char a = occ[i].nd;
			char b = occ2[i].nd;
			string t = s;
			rep(j, 0, n){
				if (s[j] == a) t[j] = b;
				if (s[j] == b) t[j] = a;
			}
			cout << min(t, s) << "\n";
			return;
		}
	}
	cout << s << "\n";
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int t = 1;
	//cin >> t;
	while (t--) solve();
	
	return 0;
}
