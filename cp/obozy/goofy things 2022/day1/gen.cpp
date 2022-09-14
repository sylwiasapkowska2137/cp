#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef vector<int> vi;
typedef pair<int, int>pii;

#define rep(i, a, b) for (int i = a; i<b; i++)
#define repd(i, a, b) for(int i = a; i>=b; i--)
#define st first
#define nd second
#define debug(x) cerr << x << " "
#define sz(x) (int)((x).size())
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int p(int a, int b){
	return a+rng()%(b-a+1);
}

void solve(){
	LL n = p(1000,2000);
	int r = min(200000LL, n*(n-1)/2);
	int m = p(n, r);
	cout << n << " " << m << "\n";
	set<pii>s;
	rep(i, 0, m){
		int a = p(1, n);
		int b = p(1, n);
		while (a == b) b = p(1, n);
		if (a > b) swap(a, b);
		while (s.find({a, b}) != s.end()){
			a = p(1, n);
			b = p(1, n);
			while (a == b) b = p(1, n);
			if (a > b) swap(a, b);
		}
		s.insert({a, b});
	}
	for (auto x: s) {
		cout << x.st << " " << x.nd << "\n";
	}
	int q = p(100, 100);
	cout << q << "\n";
	while (q--){
		int v = p(1, n);
		int d = p(0, 10);
		int c = p(1, 5);
		cout << v << " " << d << " " << c << '\n';
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	solve();
	return 0;
}
