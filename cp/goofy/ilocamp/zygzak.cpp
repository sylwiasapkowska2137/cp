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

const int size = 1e6+7;
int tab[2*size+1], tab2[2*size+1];

int query(int l, int r){
	l = l+size-1;
	r = r+size+1;
	int ans = 0LL;
	while (r-l>1){
		if (!(l&1)) ans = max(ans, tab[l+1]);
		if (r&1) ans = max(ans, tab[r-1]);
		l/=2;r/=2;
	}
	return ans;
}

void update(int pos, int val){
	pos+=size;
	tab[pos] = max(tab[pos], val);
	while (pos>0){
		pos/=2;
		tab[pos] = max(tab[2*pos], tab[2*pos+1]);
	}
}

int query2(int l, int r){
	l = l+size-1;
	r = r+size+1;
	int ans = 0LL;
	while (r-l>1){
		if (!(l&1)) ans = max(ans, tab2[l+1]);
		if (r&1) ans = max(ans, tab2[r-1]);
		l/=2;r/=2;
	}
	return ans;
}

void update2(int pos, int val){
	pos+=size;
	tab2[pos] = max(tab2[pos], val);
	while (pos>0){
		pos/=2;
		tab2[pos] = max(tab2[2*pos], tab2[2*pos+1]);
	}
}

void solve(){
	int n; cin >> n;
	rep(i, 0, n){
		int x; cin >> x;
		update2(x, query(x+1, size)+1);
		update(x, query2(0, x-1)+1);
	}
	cout << max(query(0, size), query2(0, size)) << "\n";
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	solve();
	
	return 0;
}

