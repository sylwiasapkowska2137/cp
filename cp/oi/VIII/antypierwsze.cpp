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

vll tab = {1, 2, 4, 6, 12, 24, 36, 48, 60, 120, 180, 240, 360, 720, 840, 1260, 1680, 2520, 5040, 7560, 10080, 15120, 20160, 25200, 27720, 45360, 50400, 55440, 83160, 110880, 166320, 221760, 277200, 332640, 498960, 554400, 665280, 720720, 1081080, 1441440, 2162160, 2882880, 3603600, 4324320, 6486480, 7207200, 8648640, 10810800, 14414400, 17297280, 21621600, 32432400, 36756720, 43243200, 61261200, 73513440, 110270160, 122522400, 147026880, 183783600, 245044800, 294053760, 367567200, 551350800, 698377680, 735134400, 1102701600, 1396755360, 2095133040, 2205403200, 2327925600, 2793510720, 3491888400, 4655851200, 5587021440, 6983776800, 10475665200, 13967553600, 20951330400, 27935107200, 41902660800, 48886437600, 64250746560, 73329656400, 80313433200, 97772875200, 128501493120, 146659312800, 160626866400, 240940299600, 293318625600, 321253732800, 481880599200, 642507465600, 963761198400, 1124388064800, 1606268664000, 1686582097200, 1927522396800, 2248776129600, 3212537328000, 3373164194400, 4497552259200, 6746328388800, 8995104518400, 9316358251200, 13492656777600, 18632716502400, 26985313555200, 27949074753600, 32607253879200, 46581791256000, 48910880818800, 55898149507200, 65214507758400, 93163582512000, 97821761637600, 130429015516800, 195643523275200, 260858031033600, 288807105787200, 391287046550400};

void solve(){
	LL x; cin >> x;
	cout << *(--(ub(all(tab), x))) << "\n";
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int t = 1;
	//cin >> t;
	while (t--) solve();
	
	return 0;
}
