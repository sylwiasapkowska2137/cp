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

string s;
vi pos(30, 0);

bool cmp(string a, string b){
	rep(i, 0, min(sz(a), sz(b))){
		if (a[i] == b[i]) continue;
		if (pos[a[i]-'a'] < pos[b[i]-'a']) return 0;
		else return 1;
	}
	return sz(a) > sz(b);
}

void solve(){
	cin >> s;
	rep(i, 0, 26) pos[s[i]-'a'] = i;
	int n; cin >> n;
	vector<string>a(n);
	rep(i, 0, n) {
		cin >> a[i];
	}
	sort(all(a), cmp);
	reverse(all(a));
	for (auto x: a) cout << x << "\n";
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int t = 1;
	//cin >> t;
	while (t--) solve();
	
	return 0;
}
