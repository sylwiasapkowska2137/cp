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
	int q; cin >> q;
	pqg<pii>IND, VAL;
	int cnt = 0, ile = 0, cnt2 = 0;
	vb vis(q+1, 0);
	vpii tmp;
	while (q--){
		int c;
		cin >> c;
		if (c == 1){
			int x; cin >> x;
			tmp.pb({x, cnt});
			IND.push({cnt, x});
			cnt++;
			cnt2++;
		} else if (c == 2){
			while (!IND.empty() && vis[IND.top().st]) IND.pop();
			while (!VAL.empty() && vis[VAL.top().nd]) VAL.pop();
			if (ile>0){
				cout << VAL.top().st << "\n";
				vis[VAL.top().nd] = 1;
				VAL.pop();
				ile--;
			} else {
				cout << IND.top().nd << "\n";
				vis[IND.top().st] = 1;
				IND.pop();
			}
			cnt2--;
		} else {
			ile = cnt2;
			for (auto v: tmp) VAL.push(v);
			tmp.clear();
		}
		//debug(ile);
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
