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

string s, sum, ans;
bool ok;

void solve(int i, int j, string b){
	if (i < 0 && j < 0) {
		ok = 1;
		ans = b;
		return;
	}
	if (i >= 0)	if (sum[j] >= s[i]) solve(i-1, j-1, b+(char)(sum[j]-s[i]+'0'));
	
	if (j >= 1 && sum[j-1] == '1') {
		int sv = (sum[j-1]-'0')*10+(sum[j]-'0');
		int av = s[i]-'0';
		int nv=sv-av;
		int minv = (i == 0 ? 1 : 0);
		if (nv >= minv && nv <= 9) solve(i-1, j-2, b+to_string(nv));
	}
	if (i < 0 && j >= 0) solve(i, j-1, b+sum[j]);
}

void solve(){
	ok = 0;
	cin >> s >> sum;
	solve(sz(s)-1, sz(sum)-1, "");
	
	reverse(all(ans));
	int i=0;
	while (i < ans.size()) {
		if (ans[i] == '0') ans.erase(ans.begin());
		else break;
	}
	if (ok && sz(ans)>=1) cout << ans << "\n";
	else cout << "-1\n";
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--) solve();
	
	return 0;
}
