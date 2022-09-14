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

vi tab;

void fastscan(int &number){
	bool negative = 0;
	register int c;
	number = 0;
	c = getchar();
	if (c=='-'){
		negative = 1;
		c = getchar();
	}
	for (; (c>47 && c<58); c=getchar()) number = number*10 + c - 48;
	if (negative)  number *= -1;
}

void solve(){
	sort(all(tab));
	int n = sz(tab);
	rep(i, 0, n-2){
		if (tab[i]+tab[i+1]>tab[i+2]){
			cout << tab[i] << " " << tab[i+1] << " " << tab[i+2] << "\n";
			exit(0);
		}
	}
	cout << "NIE\n";
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	while (1) {
		int x; fastscan(x);
		if (!x) {
			solve();
			exit(0);
		}
		tab.pb(x);
	}
	
	return 0;
}
