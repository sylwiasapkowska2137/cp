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
	int n = 5, q = 5;
	cout << n << " " << q << "\n";
	rep(i, 1, n+1) cout << p(1, 2) << " ";
	cout << "\n";
	q *= 2;
	int i = 1;
	while (q--){
		int a = p(1, n);
		cout << a << " " << p(a, n) << " ";
		i++;
		if (i&1) cout << "\n";
	}
}

void solve2(){
	int n = p(1, 1000);
	cout << n << " " << p(1, 300) <<  "\n";
	rep(i, 0, n) cout << p(1, 1e9) << " ";
	cout << "\n";
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	solve2();

	
	return 0;
}
