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

struct segtree{
	vll tab;
	int size = 1;
	
	void init(int n){
		while (size < n) size*=2;
		tab.assign(2*size+1, 0LL);
	}
	
	void clear(){
		tab.assign(sz(tab), 0);
	}
	
	void update(int pos, int val){
		pos+=size;
		tab[pos]+=val;
		while (pos>0){
			pos/=2;
			tab[pos] = tab[2*pos]+tab[2*pos+1];
		}
	}
	
	LL query(int l, int r){
		l = l+size-1;
		r = r+size+1;
		LL ans = 0LL;
		while (r-l>1){
			if (!(l&1)) ans += tab[l+1];
			if (r&1) ans += tab[r-1];
			l/=2;r/=2;
		}
		return ans;
	}
};

bool cmp(pii a, pii b){
	if (a.st == b.st) return a.nd > b.nd;
	return a < b;
}

LL pairs(LL x){
	return x*(x+1)/2;
}

void solve(){
	int n; cin >> n;
	vi a(n), b(n);
	rep(i, 0, n) cin >> a[i];
	rep(i, 0, n) cin >> b[i];
	int ans = 0;
	rep(i, 0, n){
		rep(j, i, n){
			if ((a[i]<=a[j] && b[i]>=b[j]) || (a[i]>=a[j] && b[i]<=b[j])) {
				ans++;
				debug(i);
				debug(j);
				cerr << "\n";
			}
			if (a[i] == a[j] && b[i] == b[j]) {
				ans++;
				debug(i);
				debug)k			
			}
		}
	}
	cout << ans-n << "\n";
}


int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int t = 1;
	//cin >> t;
	while (t--) solve();
	
	return 0;
}
