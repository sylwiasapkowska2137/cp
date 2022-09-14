#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace std;
using namespace __gnu_pbds;

void __print(int x){cerr << x;}
void __print(long long x){cerr << x;}
void __print(long double x){cerr << x;}
void __print(char x) {cerr << "\'" << x << "\'";}
void __print(const char *x) {cerr << "\'" << x << "\'";}
void __print(const string &x) {cerr << "\"" << x << "\"";};


#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>

template<typename T, typename V>
void __print(const pair<T, V> &x){
	cerr << "{";
	__print(x.first);
	cerr << ", ";
	__print(x.second);
	cerr << "}";
}

template<typename T>
void __print(const T &t){
	int f = 0;
	cerr << "{";
	for (auto &i: t){
		cerr << (f++?", ":""), __print(i);
	}
	cerr << "}";
}

void _print(){cerr << "]\n";}

template<typename T, typename... V>
void _print(T t, V... v){
	__print(t);
	if (sizeof...(v)) cerr << ", ";
	_print(v...);
}

#define int long long
#define debug(x...) cerr << "[" << #x << "] = [", _print(x)

struct stan{
	int L[2], R[2];
	int s;
	stan(){
		memset(L, 0, sizeof(L));
		memset(R, 0, sizeof(R));
		s = 0;
	}
};

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int p(int a, int b){
	return a+rng()%(b-a+1);
}

void solve(){
	int n = p(2, 5);
	cout << n << "\n";
	vector<int>a(n);
	iota(a.begin(), a.end(), 1);
	shuffle(a.begin(), a.end(), rng);
	for (int i = 0; i<n; i++){
		if (i == 0){
			cout << a[i+p(0, 1)] << " ";
			continue;
		}
		if (i == n-1){
			cout << a[i+p(-1, 0)] << " ";
			continue;
		}
		cout << a[i+p(-1, 1)] << " ";		
	}
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	solve();
	
	return 0;
}
