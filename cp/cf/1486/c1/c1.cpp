/*
	Author: sysia
	07.01.2022 13:32:23
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

int query(int l, int r){
	if (l >= r) return -1;
	cout << "? " << l << " " << r << "\n";
	cout.flush();
	int x; cin >> x;
	return x;
}

int answer(int x){
	cout << "! " << x << "\n";
	cout.flush();
	exit(0);
}

void solve(){
	int n; cin >> n;
	int smax = query(1, n);
	if (n == 2){
		if (smax == 1) answer(2);
		else answer(1);
	}
	int left = query(1, smax);
	//int right = query(smax, n);
	if (smax == 1 || left != smax){
		int l = smax, r = n;
		while (r-l>1){
			int mid = (l+r)/2;
			if (query(smax, mid) == smax) r = mid;
			else l = mid;
		}
		answer(r);
	} else {
		int l = 1, r = smax;
		while (r-l > 1){
			int mid = (l+r)/2;
			if (query(mid, smax) == smax) l = mid;
			else r = mid;
		}
		answer(l);
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
