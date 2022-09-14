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

void solve(){
	int n = p(5, 100);
	int m = p(n, 1000);
	set<pii>s;
	cout << n << " " << m << " " << p(1, n) << "\n";
	rep(i, 1, n+1){
		int a = p(1, n);
		while (a == i) a = p(1, n);
		s.insert({min(i, a), max(i, a)});
	}
	rep(i, n+1, m+1){
		while (1){
			int a = p(1, n);
			int b = p(1, n);
			if (a == b) continue;
			if (a > b) swap(a, b);
			if (s.find({a, b}) == s.end()){
				s.insert({a, b});
				break;
			}
		}
	}
	for (auto x: s){
		cout << x.st << " " << x.nd << "\n";
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
