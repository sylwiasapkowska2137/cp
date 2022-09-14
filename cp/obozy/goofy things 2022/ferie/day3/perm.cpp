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

const int MAX = (1<<21)+69;
vi prime(MAX+2, 1);
vi curr;
set<int>notused;

void sito(){
	prime[0] = 0;
	prime[1] = 0;
	rep(i, 2, MAX){
		if (prime[i] && (LL)i*(LL)i < (LL)(MAX)){
			for (LL j = i*i; j<(LL)MAX; j+=i){
				prime[j] = 0;
			}
		}
	}
}

void backtrack(int sz){
	if (sz == (1<<20)){
		if (prime[curr[0]+curr.back()]){
			for (auto x: curr) cout << x << ", ";
			exit(0);
		}
		return;
	}
	rep(i, 1, (1<<20)+1){
		if (notused.find(i) == notused.end() && prime[curr.back()+i]){
			curr.pb(i);
			notused.erase(i);
			backtrack(sz+1);
			notused.insert(i);
			curr.pop_back();
		}
	}
}

void solve(){
	int n = (1<<20);
	sito();
	rep(i, 1, n+1) notused.insert(i);
	rep(i, 1, n+1){
		curr.pb(i);
		backtrack(i);
		curr.pop_back();
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
