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

int X[] = {-1, -1, 1, 1};
int Y[] = {-1, 1, -1, 1};

void solve(){
	int n, d; cin >> n >> d;
	vi a(n+1);
	rep(i, 1, n+1) cin >> a[i];
	queue<pii>q;
	set<pii>vis;
	rep(i, 1, n){
		if (abs(a[i]-a[i+1]) <= d){
			q.push({i, i+1});
			vis.insert({i, i+1});
		}
	}
	rep(i, 2, n){
		if (abs(a[i-1]-a[i+1]) <= d){
			q.push({i-1, i+1});
			vis.insert({i-1, i+1});
		}
	}
	set<pii>ans;
	
	while (!q.empty()){
		pii v = q.front();q.pop();
		ans.insert(v);
		rep(i, 0, 4){
			pii x = {v.st+X[i], v.nd+Y[i]};
			
			if (x.st >= 1 && x.nd >= 1 && x.nd <= n && x.st <= n && x.st < x.nd){
				if (abs(a[x.st]-a[x.nd]) <= d && vis.find(x) == vis.end()){
					q.push(x);
					vis.insert(x);
				}
			}
		}
	}
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
