#include <bits/stdc++.h>
#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
 
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

void solve(){
	int n, k; cin >> n >> k;
	LL ab = 0, ac = 0, bc = 0, x;
	cout << "or 1 2\n";cout.flush();
	cin >> x; ab+=x;
	cout << "and 1 2\n";cout.flush();
	cin >> x; ab+=x;
	
	cout << "or 1 3\n";cout.flush();
	cin >> x; ac+=x;
	cout << "and 1 3\n";cout.flush();
	cin >> x; ac+=x;
	
	cout << "or 2 3\n";cout.flush();
	cin >> x; bc+=x;
	cout << "and 2 3\n";cout.flush();
	cin >> x; bc+=x;
	LL suma = (ab+bc+ac)/2;
	LL a = suma-bc, b = suma-ac, c = suma-ab;
	vll tab;
	tab.pb(a);
	tab.pb(b);
	tab.pb(c);
	rep(i, 4, n+1){
		LL t = 0;
		cout << "or 1 "<< i << " \n";cout.flush();
		cin >> x; t+=x;
		cout << "and 1 "<< i << " \n";cout.flush();
		cin >> x; t+=x;
		tab.pb(t-a);
	}
	sort(all(tab));
	cout << "finish " << tab[k-1] << "\n"; cout.flush();
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int t = 1;
	//cin >> t;
	while (t--) solve();
	
	return 0;
}
