#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
 
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

const int MAX = 2007, MAXN = 1e5+7;
LL wyspa[MAX][MAX], pref[MAX][MAX];
int n, h;

struct point{
	LL a, b, c, d, val;
};

point rec[MAXN];

bool warunek(int x){
	rep(i, 0, n+1){
		rep(j, 0, n+1) pref[i][j] = 0LL;
	}
	
	rep(i, 1, x+1){
		point curr = rec[i];
		pref[curr.a][curr.b]+=curr.val;
		pref[curr.a][curr.d+1]-=curr.val;
		pref[curr.c+1][curr.b]-=curr.val;
		pref[curr.c+1][curr.d+1]+=curr.val;
	}
	/*
	cerr << "\n";
	rep(i, 1, n+1){
		rep(j, 1, n+1){
			debug(pref[i][j]);
		}
		cerr << "\n";
	}
	cerr << "\n";
	*/
	rep(i, 1, n+1){
		rep(j, 1, n+1){
			pref[i][j] += pref[i-1][j]+pref[i][j-1]-pref[i-1][j-1];
			//debug(pref[i][j]);
			if (pref[i][j]>wyspa[i][j]) return 1;
		}
		//cerr << "\n";
	}
	return 0;
}


int binsearch(int start, int koniec){
	while (koniec != start){
		int mid = (start+koniec)/2;
		if (warunek(mid)) koniec = mid;
		else start = mid+1;
	}
	return koniec;
}

void solve(){
	cin >> n;
	rep(i, 1, n+1){
		rep(j, 1, n+1) cin >> wyspa[i][j];
	}
	cin >> h;
	
	rep(i, 1, h+1){
		point curr;
		cin >> curr.a >> curr.b >> curr.c >> curr.d >> curr.val;
		rec[i] = curr;
	}
	int x = binsearch(1, h);
	if (warunek(x)) cout << x << "\n";
	else cout << "-1\n";
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int t = 1;
	//cin >> t;
	while (t--) solve();
	
	return 0;
}
