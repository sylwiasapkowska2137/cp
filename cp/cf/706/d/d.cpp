/*
	Author: sysia
	07.01.2022 12:34:13
*/

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

const int MAX = 30;

struct Node{
	int syn[2] = {-1, -1};
	int cnt = 0;
};

struct Trie{
	vector<Node>tab;
	vpii parent;
	
	void init(){
		Node elem;
		tab.pb(elem);
		parent.pb({-1, -1});
	}
	
	void add(int x){
		int v = 0;
		repd(i, MAX, 0){
			bool a = x&(1<<i);
			if (tab[v].syn[a] == -1){
				Node elem;
				tab[v].syn[a] = sz(tab);
				parent.pb({v, a});
				tab.pb(elem);
			}
			v = tab[v].syn[a];
			tab[v].cnt++;
		}
		
	}
	
	void remove(int x){
		int v = 0;
		repd(i, MAX, 0) {
			bool a = x&(1<<i);
			v = tab[v].syn[a];
		}
		while (v > 0){
			tab[v].cnt--;
			if (!tab[v].cnt) tab[parent[v].st].syn[parent[v].nd] = -1;
			v = parent[v].st;
		}
	}
	
	int Find(int x){
		int v = 0;
		int ans = 0;
		repd(i, MAX, 0){
			ans*=2;
			bool a = (x&(1<<i));
			if (tab[v].syn[a^1] == -1){
				v = tab[v].syn[a];
				ans += (a);
			} else {
				v = tab[v].syn[a^1];
				ans += (a^1);
			}
		}
		return max(x, (ans^x));
	}
	
	
	void print(){
		rep(i, 0, sz(tab)){
			rep(j, 0, 2){
				if (tab[i].syn[j] != -1){
					debug(i);
					debug(tab[i].syn[j]);
					debug(j);
					cerr << "\n";
				}
			}
		}
		rep(i, 0, sz(tab)) debug(tab[i].cnt);
		cerr << "\n";
	}
} TRIE;

void solve(){
	int q; cin >> q;
	TRIE.init();
	TRIE.add(0);
	while (q--){
		char type; cin >> type;
		int x; cin >> x;
		if (type == '+'){
			TRIE.add(x);
		} else if (type == '-'){
			TRIE.remove(x);
		} else {
			cout << TRIE.Find(x) << "\n";
		}
		//TRIE.print();
		//cerr << "\n";
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
