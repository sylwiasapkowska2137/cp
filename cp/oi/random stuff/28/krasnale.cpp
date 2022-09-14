#include <bits/stdc++.h>
//#pragma GCC optimize ("O3")
//#pragma GCC target ("sse4")
using namespace std;
 
typedef long long LL;
typedef long double LD;
 
typedef pair<int, int> pii;
typedef pair<LL,LL> pll;
typedef pair<LD,LD> pdd;
 
typedef vector<int> vi;
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

const int MAX = 5e5+7;
vi graf[MAX], GRAF[MAX], in;
set<pii>s;

void skieruj(){
	queue<int>q;
	for (auto x: graf[1]){
		if (in[x]>0){
			GRAF[1].pb(x);
			q.push(x);
			in[x]--;
			
		} else {
			GRAF[x].pb(1);
			in[1]--;
		}
		s.erase({1, x});
	}
	//in[2] = graf[2].size();
	for (auto x: graf[2]){
		pii tmp = {min(x, 2), max(x, 2)};
		if (s.find(tmp)!=s.end()){
			GRAF[x].pb(2);
			s.erase({2, x});
		}
	}
	while (!q.empty()){
		int v = q.front();q.pop();
		for (auto x: graf[v]){
			if (s.find({min(x, v), max(x, v)})!=s.end()){
				if (in[v]>0){
					GRAF[x].pb(v);
					in[v]--;
					
				} else {
					GRAF[v].pb(x);
					in[x]--;
					q.push(x);
				}
				s.erase({min(x, v), max(x, v)});
			}
		}
	}
}

void solve(){
	int n, m;
	cin >> n >> m;
	in.resize(n+1);
	rep(i, 0, m){
		int a, b; cin >> a >> b;
		if (a > b)swap(a, b);
		graf[a].pb(b);
		graf[b].pb(a);
		s.insert({a, b});
	}
	rep(i, 1, n+1) in[i] = graf[i].size()/2;
	skieruj();
	in.assign(n+1, 0);
	rep(i, 1, n+1){
		debug(i);
		for (auto x: GRAF[i]) in[x]++;
		for (auto x: GRAF[i]) debug(x);
		cerr << "\n";
	}
	vi topo, ans(n+1);
	queue<int>k;
	rep(i, 1, n+1) if (!in[i]) k.push(i);
	while (!k.empty()){
		int v = k.front();k.pop();
		topo.pb(v);
		for (auto x: GRAF[v]){
			in[x]--;
			if (!in[x]) k.push(x);
		}
	}
	
	for (auto x: topo) debug(x);
	cerr << "\n";
	rep(i, 0, sz(topo)){
		ans[topo[i]] = i+1;
	}
	rep(i, 1, n+1) debug(ans[i]);
	cerr << "\n";
	vi less(n+1, 0), bigger(n+1, 0);
	rep(v, 1, n+1){
		for (auto x: graf[v]){
			if (ans[v] < ans[x]){
				bigger[v]++;
			} else {
				less[v]++;
			}
		}
	}
	rep(i, 3, n+1){
		if (less[i]!=bigger[i]){
			cout << "NIE\n";
			return;
		}
	}
	
	cout << "TAK\n";
	rep(i, 1, n+1) cout << ans[i] << " ";
	cout << "\n"; 
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int t = 1;
	//cin >> t;
	while (t--) solve();
	
	return 0;
}
