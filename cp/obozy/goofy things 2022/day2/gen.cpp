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
	LL n = p(1, 10000), q = p(1000, 7000), k = p(1, 10000000);
	cout << n << " " << q << " " << k << "\n";
	rep(i, 0, n){
		cout << p(1, 10000000) << " ";
	}
	cout << "\n";
	while (q--){
		int a = p(1, n);
		int b = p(a, n);
		cout << a << " " << b << "\n";
	}
}

void solve2(){
	int n = p(1, 60);
	int m = p(1, 60);
	int M = 1e6;
	cout << n << " " << m << "\n";
	rep(i, 0, n) cout << p(-M, M) << " ";
	cout << "\n";
	rep(i, 0, m) cout << p(-M, M) << " ";
	cout << "\n";
}

void solve3(){
	int n = p(2, 10);
	int m = p(0, 20);
	cout << n << " " << m << "\n";
	rep(i, 1, n+1) cout << p(1, 2) << " ";
	cout << "\n";
	rep(i, 0, m){
		int a = p(1, n);
		int b = p(1, n);
		while (a == b) b = p(1, n);
		cout << a << " " << b << "\n";
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	solve3();
	
	return 0;
}
