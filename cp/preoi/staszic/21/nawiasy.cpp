//Sylwia Sapkowska
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
using ordered_set = tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
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

LL losuj(LL a, LL b){ 
	return a+rng()%(b-a+1);
}

const LL INF = 1e18;

struct segtree{
	vll tab, lazy;
	int size = 1;
	
	void init(int n, vll a){
		while (size < n) size*=2;
		tab.assign(2*size, INF);
		lazy.assign(2*size, 0);
		rep(i, 1, sz(a)) tab[i+size] = a[i];
		repd(i, size-1, 1) tab[i] = min(tab[2*i], tab[2*i+1]);
	}
	
	void push(int x, int lx, int rx){
		if (lx == rx) return;
		tab[2*x]+=lazy[x];
		tab[2*x+1]+=lazy[x];
		lazy[2*x]+=lazy[x];
		lazy[2*x+1]+=lazy[x];
		lazy[x] = 0;
	}
	
	void update(int x, int lx, int rx, int l, int r, int val){
		if (lx > r || rx < l) return;
		if (lx >= l && rx <= r){
			tab[x] += val;
			lazy[x]+=val;
			return;
		}
		push(x, lx, rx);
		int m = (lx+rx)/2;
		update(2*x, lx, m, l, r, val);
		update(2*x+1, m+1, rx, l, r, val);
		tab[x] = min(tab[2*x], tab[2*x+1]);
	}
	
	LL query(int x, int lx, int rx, int l, int r){
		if (lx > r || rx < l) return INF;
		if (lx >= l && rx <= r) return tab[x];
		push(x, lx, rx);
		int m = (lx+rx)/2;
		return min(query(2*x, lx, m, l, r), query(2*x+1, m+1, rx, l, r));
	}
};

void fastscan(int &number)
{
    //variable to indicate sign of input number
    bool negative = false;
    register int c;
 
    number = 0;
 
    // extract current character from buffer
    c = getchar();
    if (c=='-')
    {
        // number is negative
        negative = true;
 
        // extract the next character from the buffer
        c = getchar();
    }
 
    // Keep on extracting characters if they are integers
    // i.e ASCII Value lies from '0'(48) to '9' (57)
    for (; (c>47 && c<58); c=getchar())
        number = number *10 + c - 48;
 
    // if scanned input has a negative sign, negate the
    // value of the input number
    if (negative)
        number *= -1;
}

void solve(){
	
	int n; fastscan(n);
	vi tab(n+1);
	rep(i, 1, n+1) fastscan(tab[i]);
	segtree seg;
	vll pref(n+1, 0);
	rep(i, 1, n+1) pref[i] = pref[i-1]+tab[i];
	seg.init(n+1, pref);
	int y = pref[n];
	while(1){
		int a; fastscan(a);
		if (a < 0) break;
		if (!a) {
			int x = seg.query(1, 0, seg.size-1, 1, n);
			if (x == 0 && y == 0) cout << "TAK\n";
			else cout << "NIE\n";
		} else {
			if (tab[a] == 1) {
				tab[a] = -1;
				y-=2;
				seg.update(1, 0, seg.size-1, a, n, -2);
			} else {
				tab[a] = 1;
				y+=2;
				seg.update(1, 0, seg.size-1, a, n, 2);
			}
		}
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	solve();
	
	return 0;
}
