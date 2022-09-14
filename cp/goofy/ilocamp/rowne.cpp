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
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
LL losuj(LL a, LL b){ return a+rng()%(b-a+1);}

const int MAX = 1e6+7, INF = 1e9+7;
int ile[MAX];

void solve(){
	int n; cin >> n;
	set<int>s;
	rep(i, 0, n){
		int x; cin >> x;
		ile[x]++;
		s.insert(x);
	}
	int diff = sz(s);
	vi one, two;
	int mini = INF;
	rep(i, 1, MAX){
		if (ile[i]){
			mini = min(mini, ile[i]);
			bool ok = 0;
			for (int j = 2*i; j<MAX; j+=i) ok |= ile[j];
			if (ok) one.pb(ile[i]);
			two.pb(ile[i]);
		}
	}
	sort(all(one));
	sort(all(two));
	//for (auto x: one) debug(x);
	//cerr << "\n";
	//for (auto x: two) debug(x);
	//cerr << "\n";
	int sum = 0;
	set<pii>s1, s2;
	rep(i, 0, sz(one)){
		sum += one[i];
		s1.insert({sum, i+1});
	}
	sum = 0;
	rep(i, 1, sz(two)){
		sum+=two[i];
		s2.insert({sum, i});
	}
	cout << diff << " ";
	rep(i, 1, n+1){
		auto it = s1.ub({i, INF});
		auto it2 = s2.ub({i-mini, INF});
		int curr, curr2;
		if (it == s1.begin()) curr = 0;
		else curr = (*(--it)).nd;
		if (it2 == s2.begin()) curr2 = 0;
		else curr2 = (*(--it2)).nd;
		cout << diff-max(curr, curr2) << " ";
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int t = 1;
	//cin >> t;
	while (t--) solve();
	
	return 0;
}
