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
	int n = p(5, 10);
	int q = p(1, 20);
	cout << n << " " << q << "\n";
	set<pii>s;
	rep(i, 0, q){
		int t = p(1, 3);
		while (s.empty() && t == 2) t = p(1, 3);
		while (sz(s) == n*(n-1)/2 && t == 1) t = p(1, 3);
		if (t == 1){
			cout << "+ ";
			int a = p(1, n);
			int b = p(1, n);
			while (a==b) b = p(1, n);
			if (a > b) swap(a, b);
			while (s.find({a, b}) != s.end()){
				a = p(1, n);
				b = p(1, n);
				while (a==b) b = p(1, n);
				if (a > b) swap(a, b);
			}
			cout << a << " " << b << "\n";
			s.insert({a, b});
		} else if (t == 2){
			cout << "- ";
			vpii tab;
			for (auto x: s){
				tab.pb(x);
			}
			int idx = p(0, sz(tab)-1);
			cout << tab[idx].st << " " << tab[idx].nd << "\n";
			s.erase(tab[idx]);
		} else cout << "?\n";
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	solve();
	
	return 0;
}
