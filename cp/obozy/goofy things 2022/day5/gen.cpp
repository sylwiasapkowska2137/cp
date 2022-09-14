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


mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int p(int a, int b){
	return a+rng()%(b-a+1);
}
//https://codeforces.com/blog/entry/94522

void solve(){
	int n = p(100000, 100000);
	int m = p(1, 300);
	int q = p(100000, 100000);
	cout << n << " " << m << " " << q << "\n";
	rep(i, 0, n) cout << p(0,1e9) << " ";
	cout << "\n";
	while (q--){
		int type = p(1, 2);
		cout << type << " ";
		if (type == 1){
			int a = p(1, n);
			cout << a << " " << p(a, n) << "\n";
		} else cout << p(1, n) << " " << p(0, 1e9) << "\n";
	}
}

void solve2(){
	int n = p(5, 10);
	cout << n << " " << p(1,5) <<  "\n";
	rep(i, 0, n) cout << p(1, 5) << " ";
	cout << "\n";
	rep(i, 0, n) cout << p(1, 5) << " ";
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
