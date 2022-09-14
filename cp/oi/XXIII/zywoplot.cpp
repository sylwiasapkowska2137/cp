//Sylwia Sapkowska
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

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

struct E{
	pair<int, int>a, b;
	int c;
	E(){}
	E(pair<int, int> _a, pair<int, int> _b, int _c){
		a = _a, b = _b, c = _c;
	}
};

vector<vector<pair<int, int>>>rep;
const int MAX = 1007;
bool pion[MAX][MAX], poziom[MAX][MAX];
int added, ans;

pair<int, int> Find(pair<int, int>a){
	if (a == rep[a.first][a.second]) return a;
	return rep[a.first][a.second] = Find(rep[a.first][a.second]);
}

void Union(pair<int, int>a, pair<int, int>b, int c){
	pair<int, int> A = Find(a);
	pair<int, int> B = Find(b);
	if (A == B) return;
	//debug(A, B);
	if (tie(A.first, A.second) > tie(B.first, B.second)) {
		swap(A, B);
		swap(a, b);
	}	
	//debug(a, b);
	rep[B.first][B.second] = A;
	added++;
	ans += c;
	if (a.first == b.first) pion[a.first][min(a.second, b.second)] = 1;
	else poziom[min(a.first, b.first)][a.second] = 1;
}

void solve(){
	int n, m; cin >> n >> m;
	vector<E>e;
	swap(n, m);
	for (int i = 0; i<m; i++){
		for (int j = 1; j<n; j++){
			char c; cin >> c;
			if (c == 'C'){
				e.push_back({{j, i}, {j, i+1}, 1});
			} else {
				e.push_back({{j, i}, {j, i+1}, 0});
			}
		}
	}

	for (int i = 1; i<m; i++){
		for (int j = 0; j<n; j++){
			char c; cin >> c;
			if (c == 'C') e.push_back({{j, i}, {j+1, i}, 1});
			else e.push_back({{j, i}, {j+1, i}, 0}); 
		}
	}
	sort(e.begin(), e.end(), [&](auto a, auto b){
		if (a.c == b.c){
			int A = min({a.a.first, a.b.first, n-a.a.first, n-a.b.first});
			int AA =  min({a.a.second, a.b.second, m-a.a.second, m-a.b.second});
			int B = min({b.a.first, b.b.first, n-b.a.first, n-b.b.first});
			int BB =  min({b.a.second, b.b.second, m-b.a.second, m-b.b.second});
			return A+AA<B+BB;
		}
		return a.c > b.c;
	});
	rep.resize(n+2, vector<pair<int, int>>(m+2));
	for (int i = 0; i<=n+1; i++){
		for (int j = 0; j<=m+1; j++){
			rep[i][j] = {i, j};
		}
	}
	for (int i = 0; i<n; i++){
		Union({i, 0}, {i+1, 0}, 0);
		Union({i, m}, {i+1, m}, 0);
	}
	for (int i = 0; i<m; i++){
		Union({0, i}, {0, i+1}, 0);
		Union({n, i}, {n, i+1}, 0);
	}
	
	//cerr << "\n";
	added = 0;
	memset(pion, 0, sizeof(pion));
	memset(poziom, 0, sizeof(poziom));
	for (auto [a, b, c]:e){
		//debug(a, b, c);
		Union(a, b, c);
	}
	cout << added << " " << ans << "\n";
	for (int j = 0; j<m; j++){
		for (int i = 1; i<n; i++){
			if (pion[i][j]) cout << "Z";
			else cout << ".";
		}
		cout << "\n";
	}
	for (int i = 1; i<m; i++){
		for (int j = 0; j<n; j++){
			if (poziom[j][i]) cout << "Z";
			else cout << ".";
		}
		cout << "\n";
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
	
	return 0;
}
