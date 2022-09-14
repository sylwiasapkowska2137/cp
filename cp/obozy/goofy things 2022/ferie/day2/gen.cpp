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

void solve(){
	int n = p(1, 8), m = p(1, 10);
	cout << n << " " << m << "\n";
	rep(i, 0, n) cout << p(-2, 2) << " ";
	cout << "\n";
	while (m--){
		int t = p(1, 2);
		cout << t << " ";
		if (t == 1){
			cout << p(1, n) << " " << p(-2, 2) << "\n";
		} else {
			int a = p(1, n);
			int b = p(1, n);
			if (a > b) swap(a, b);
			cout << a << " " << b << "\n";
		}
	}
	
}

void solve2(){
	int n = p(1e4, 1e5);
	cout << n << "\n";
	rep(i, 2, n+1){
		cout << p(1, i-1) << " " << i << "\n";
	}
	int MAX = 5;
	rep(i, 1, n+1) cout << p(1, MAX) << " ";
	cout << "\n";
	int q = p(1e5-5, 1e5);
	cout << q << "\n";
	while (q--){
		int t = p(1, 2);
		if (t == 1){
			cout << "Q " << p(1, n) << "\n";
		} else {
			cout << "U " << p(1, n) << " " << p(1, MAX) << "\n";
		}
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	solve2();
	
	return 0;
}
