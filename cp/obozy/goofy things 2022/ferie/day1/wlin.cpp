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

set<char>sam = {'a', 'e', 'i', 'o', 'u'};

void solve(){
	int n; cin >> n;
	string s; cin >> s;
	if (n == 1){
		cout << "1\n";
		return;
	}
	int cnt = 0;
	rep(i, 0, n) if (sam.count(s[i])) cnt++;
	if (!cnt){
		cout << "1\n";
		return;
	}
	debug(cnt);
	if (!sam.count(s[0]) && cnt){
		cout << "0\n";
		return;
	}
	if (sam.count(s[0]) && cnt == 1){
		cout << n << "\n";
		return;
	}
	vi tab;
	tab.pb(-1);
	rep(i, 0, n){
		if (sam.count(s[i])){
			tab.pb(i);
		}
	}
	cout << tab[(cnt+3)/2]-tab[(cnt+1)/2] << "\n";
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int t = 1;
	//cin >> t;
	while (t--) solve();
	
	return 0;
}
