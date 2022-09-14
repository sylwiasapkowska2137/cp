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
 
void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ", "; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? ", " : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif
 
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
#define memo(x, val) memset(x, val, sizeof(x))
#define PI 3.14159265359

int p(int a, int b){
	return a+rng()%(b-a+1);
}

const int INF = 1e9+7;
vector<vector<char>>tab, tab2;
int ans = INF;
vector<vi>dist[2];
pii bomba;
int n;
int x[] = {-1, 1, 0, 0}, y[] = {0, 0, -1, 1};

void bfs(pii &s, pii &e, pii from, int k){
	queue<pii>q;
	dist[k].assign(n+2, vi(n+2, INF));
	dist[k][s.st][s.nd] = 0;
	q.push(s);
	while (!q.empty()){
		pii v = q.front();q.pop();
		rep(i, 0, 4){
			pii s = {v.st+x[i], v.nd+y[i]};
			if (s.st >= 1 && s.nd >= 1 && s.st <= n && s.nd <= n){
				if (dist[k][s.st][s.nd] == INF && tab2[s.st][s.nd] != '#' && tab2[s.st][s.nd]!='X'){
					dist[k][s.st][s.nd] = dist[k][v.st][v.nd]+1;
					if (!k) q.push(s);
					else {
						if (dist[0][s.st][s.nd] >= dist[1][s.st][s.nd]) q.push(s);
					}
				}
			}
		}
	}
	if (ans > dist[k][e.st][e.nd]){
		ans = dist[k][e.st][e.nd];
		bomba = from;
	}
}

bool add_changes(pii v){
	pii curr = v;
	bool ok = 0;
	while (curr.st >= 1 && tab[curr.st][curr.nd] != 'X'){
		if (tab[curr.st][curr.nd] == '#') ok = 1;
		tab2[curr.st][curr.nd] = '.';
		curr.st--;
	}
	curr = v;
	while (curr.nd >= 1 && tab[curr.st][curr.nd] != 'X'){
		if (tab[curr.st][curr.nd] == '#') ok = 1;
		tab2[curr.st][curr.nd] = '.';
		curr.nd--;
	}
	curr = v;
	while (curr.st <= n && tab[curr.st][curr.nd] != 'X'){
		if (tab[curr.st][curr.nd] == '#') ok = 1;
		tab2[curr.st][curr.nd] = '.';
		curr.st++;
	}
	curr = v;
	while (curr.nd <= n && tab[curr.st][curr.nd] != 'X'){
		if (tab[curr.st][curr.nd] == '#') ok = 1;
		tab2[curr.st][curr.nd] = '.';
		curr.nd++;
	}
	return ok;
}

void restore(pii s, pii e){
	add_changes(bomba);
	bfs(s, e, bomba, 1);
	string res;
	pii curr = e;
	while (curr != s){
		rep(i, 0, 4){
			pii s = {curr.st+x[i], curr.nd+y[i]};
			if (s.st >= 1 && s.nd >= 1 && s.st <= n && s.nd <= n){
				if (dist[1][s.st][s.nd]+1 == dist[1][curr.st][curr.nd]){
					if (i == 0){
						res += "D";
					} else if (i == 1){
						res += "G";
					} else if (i == 2){
						res += "P";
					} else {
						res += "L";
					}
					curr = s;
					break;
				}
			}
		}
	}
	reverse(all(res));
	cout << res << "\n";
}

void solve(){
	cin >> n;
	tab.resize(n+2, vector<char>(n+2));
	tab2.resize(n+2, vector<char>(n+2));
	pii s, e;
	int cnt = 0;
	rep(i, 1, n+1){
		rep(j, 1, n+1){
			cin >> tab[i][j];
			tab2[i][j] = tab[i][j];
			if (tab[i][j] == 'P') s = {i, j};
			if (tab[i][j] == 'K') e = {i, j};
			if (tab[i][j] == '#') cnt++;
		}
	}
	if (!cnt){
		rep(i, 1, n+1){
			rep(j, 1, n+1){
				if (tab[i][j] != 'X'){
					bfs(s, e, {i, j}, 0);
					if (ans == INF){
						cout << "NIE\n";
						return;
					}
					cout << ans << "\n";
					//cout << bomba.st << " " << bomba.nd << "\n";
					//restore(s, e);
					return;
				}
			}
		}
		cout << "NIE\n";
		return;
	}

	bfs(s, e, s, 0);
	rep(i, 1, n+1){
		rep(j, 1, n+1){
			if (tab[i][j] == 'X') continue;
			//bomba
			bool x = add_changes({i, j});
			if (!x) {
				rep(k, 1, n+1) {
					tab2[i][k] = tab[i][k];
					tab2[k][j] = tab[k][j];
				}
				continue;
			}
			bfs(s, e, {i, j}, 1); 
			//napraw tab2
			rep(k, 1, n+1) {
				tab2[i][k] = tab[i][k];
				tab2[k][j] = tab[k][j];
			}
		}
	}
	if (ans == INF){
		cout << "NIE\n";
		return;
	}
	cout << ans << "\n";
	//cout << bomba.st << " " << bomba.nd << "\n";
	//restore(s, e);
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	solve();
	
	return 0;
}
