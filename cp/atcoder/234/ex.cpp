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

const LL MAX = 2e5;
vll Move = {-MAX-1, -MAX, -MAX+1, -1, 0, 1, MAX-1, MAX, MAX+1};

void solve(){
	int n; LL K; cin >> n >> K;
	vpll p(n);
	map<LL, vi>area;
	rep(i, 0, n){
		cin >> p[i].st >> p[i].nd;
		area[(p[i].st/K)*MAX+(p[i].nd/K)].pb(i);
	}
	vpii ans;
	rep(i, 0, n){
		LL pole = (p[i].st/K)*MAX+(p[i].nd/K);
		for (auto d: Move){
			LL curr = pole+d;
			for (auto idx: area[curr]){
				if (i >= idx) continue;
				LL dist = (p[idx].st-p[i].st)*(p[idx].st-p[i].st)+(p[idx].nd-p[i].nd)*(p[idx].nd-p[i].nd);
				if (dist <= K*K) ans.pb({i+1, idx+1});
			}
		}
	}
	sort(all(ans));
	cout << sz(ans) << "\n";
	for (auto x: ans) cout << x.st << " " << x.nd << "\n";
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int t = 1;
	//cin >> t;
	while (t--) solve();
	
	return 0;
}
