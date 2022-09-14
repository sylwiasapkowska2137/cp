#include <bits/stdc++.h>
//#pragma GCC optimize("Ofast")
//#pragma GCC optimize ("unroll-loops")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

//szablon czesciowo skopiowany z profilu https://codeforces.com/profile/Geothermal
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
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
LL losuj(LL a, LL b){ return a+rng()%(b-a+1);}

void solve(){
	int n, k; cin >> n >> k;
	if(k==1){
		if(n==2){
			cout << "1 2\n";
			return;
		}
		else{
			cout << "-1\n";
			return;
		}
	}
	else{
		k-=2;
		int x=2;
		while(k+x<=n){
			cout << "1 " << x << "\n";
			x++;
		}
		queue<int>q;
		q.push(2); q.push(3);
		while(x<=n){
			cout << q.front() << " " << x << "\n";
			q.push(x);
			q.pop();
			x++;
		}
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
