#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<int, int>pii;
typedef vector<int> vi;
typedef vector<LL> vll;
typedef vector<pii> vpii;

#define debug(x) cerr << x << " "
#define st first
#define nd second
#define all(x) x.begin(), x.end()
#define sz(x) (int)((x).size())
#define rep(i, a, b) for (int i = a; i<b; i++)
#define repd(i, a, b) for (int i = a; i>=b; i--)
#define pb push_back

const int MAX = 5e5+7;
vi graf[MAX];
int depth[2][MAX];

void dfs(int v, int k,int pa = -1){
	for (auto x: graf[v]){
		if (x!=pa){
			depth[k][x] = depth[k][v]+1;
			dfs(x, k, v);
		}
	}
}

void solve(){
	int n, k; cin >> n >> k;
	vpii ans;
	if (k == 1){
		if (n == 2){
			cout << "1 2\n";
		} else {
			cout << "-1\n";
		}
		return;
	}
	int left = n-k-1;
	ans.pb({1, 2});
	ans.pb({1, 3});
	int x = 4;
	rep(i, 0, left){
		ans.pb({1, x});
		x++;
	}

	int L = 3, R = 2;
	rep(i, 0, k-2){
		if (i&1) {
			ans.pb({L, x});
			L = x;
		} else {
			ans.pb({R, x});
			R = x;
		}
		x++;
	}
	sort(all(ans));
	for (auto X: ans){
		graf[X.st].pb(X.nd);
		graf[X.nd].pb(X.st);
		//cout << X.st << " " << X.nd << "\n";
	}
	//return;
	dfs(1, 0);
	int maxi = 0;
	rep(i, 1, n+1) maxi = max(maxi, depth[0][i]);
	rep(i, 1, n+1){
		if (depth[0][i] == maxi){
			dfs(i, 1);
			break;
		}
	}
	maxi = 0;
	rep(i, 1, n+1) maxi = max(maxi, depth[1][i]);
	if (maxi == k) {
		for (auto X: ans){
			cout << X.st << " " << X.nd << "\n";
		}
	} else cout << "-1\n";
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	solve();
	
	return 0;
}
