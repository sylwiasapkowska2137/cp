/*
	Author: sysia
	16.01.2022 11:55:32
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

const int MAX = 107;
int dp[MAX][MAX][MAX];

void solve(){
	string a, b, virus; cin >> a >> b >> virus;
	int A = sz(a);
	int B = sz(b);
	int V = sz(virus);
	dp[0][0][0] = 0;
	rep(i, 0, A){
		rep(j, 0, B){
			rep(k, 0, V){
				if (a[i] == b[j] && b[j] == virus[k]){
					dp[i+1][j+1][k+1] = max(dp[i+1][j+1][k+1], dp[i][j][k]+1);
				} else if (a[i] == b[j]){
					dp[i+1][j+1][k] = max(dp[i][j][k]+1, dp[i+1][j+1][k]);
				} else {
					dp[i+1][j+1][k] = max(dp[i+1][j+1][k], max(dp[i][j+1][k], dp[i+1][j][k]));
				}
			}
		}
	}
	rep(i, 0, V){
		debug(dp[A][B][i]);
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
