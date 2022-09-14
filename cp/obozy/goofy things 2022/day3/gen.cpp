#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<int, int>pii;
typedef vector<int> vi;
typedef vector<LL> vll;
typedef vector<pii> vpii;

#define debug(x) cerr << x << " "
#define st first
#define nd second
#define all(x) x.begin(), x.end()
#define sz(x) (int)((x).size())
#define rep(i, a, b) for (int i = a; i<b; i++)
#define repd(i, a, b) for (int i = a; i>=b; i--)
#define pb push_back

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int p(int a, int b){
	return a+rng()%(b-a+1);
}

void solve(){
	int M = 5e5;
	int n = p(2,M);
	int k = p(1, n-1);
	cout << n << " " << k << "\n"; 
}

void solve2(){
	int n = p(1000, 2000);
	int m = p(n-1, n*(n-1)/2);
	int q = p(1, 100000);
	cout << n << " " << m << " " << q <<  "\n";
	vi idx;
	vi bar(n+1);
	rep(i, 1, n+1) {
		bar[i] = p(0, 1);
		bar[1] = 1;
		bar[3] = 1;
		cout << bar[i] << " ";
		if (bar[i]) idx.pb(i);
	}
	cout << "\n";
	rep(i, 2, n+1){
		int a = p(1, i-1);
		cout << a << " " << i << " " << p(1e8, 1e9) <<  "\n";
	}
	rep(i, n-1, m){
		int a = p(1, n);
		int b = p(1, n);
		cout << a << " " << b << " " << p(1e8, 1e9) <<  "\n";
	}
	while (q--){
		int a = p(0, sz(idx)-1);
		int b = p(0, sz(idx)-1);
		cout << idx[a] << " " << idx[b] << "\n";
	}
	
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	solve2();
	
	return 0;
}
