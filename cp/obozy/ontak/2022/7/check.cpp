//Sylwia Sapkowska
#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;

void __print(int x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ", "; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? ", " : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif

#define int long long
const int oo = 1e18, K = 30;

void solve(){
	int n; cin >> n;
	vector<int>x(n), y(n);
	for (int i = 0; i<n; i++) cin >> x[i] >> y[i];
	vector<int>mx1(3), mx2(3), my1(3), my2(3);
	for (int i = 0; i<n; i++){
		if (x[i] > 0 && y[i] > 0){
			mx1[0] = max(mx1[0], x[i]);
			my1[0] = max(my1[0], y[i]);
		} 
		if (x[i] > 0 && y[i] < 0){
			mx1[1] = max(mx1[1], x[i]);
			my2[0] = max(my2[0], -y[i]);
		}
		if (x[i] < 0 && y[i] > 0){
			mx2[0] = max(mx2[0], -x[i]);
			my1[1] = max(my1[1], y[i]);
		}
		if (x[i] < 0 && y[i] < 0){
			mx2[1] = max(mx2[1], -x[i]);
			my2[1] = max(my2[1], -y[i]);
		}
	}
	debug(mx1, my1, mx2, my2);
	int ans = oo;
	vector<int>moves;
	for (int i = 0; i<3; i++){
		for (int j = 0; j<3; j++){
			for (int k = 0; k<3; k++){
				for (int l = 0; l<3; l++){
					moves = {mx1[i], my1[j], mx2[k], my2[l]};
					int tmp = 0;
					tmp += min(2*moves[0]+moves[2], 2*moves[2]+moves[0]);
					tmp += min(2*moves[1]+moves[3], 2*moves[3]+moves[1]);
					bool ok = 1;
					if (tmp != 10) continue;
					debug(moves);
					for (int p = 0; p<n; p++){
						if (x[p] > 0 && y[p] > 0){
							ok &= (moves[0] >= x[p] || moves[1] >= y[p]);
						}
						if (x[p] > 0 && y[p] < 0){
							ok &= (moves[0] >= x[p] || moves[2] >= -y[p]);
						}
						if (x[p] < 0 && y[p] > 0){
							ok &= (moves[3] >= -x[p] || moves[1] >= y[p]);
						}
						if (x[p] < 0 && y[p] < 0){
							ok &= (moves[3] >= -x[p] || moves[2] >= -y[p]);
						}
						debug(p);
						if (!ok) break;
					}
					// debug(tmp);
					if (ok){
						// debug(moves, tmp);
						ans = min(ans, tmp);
					}
				}
			}
		}
	}
	cout << ans << "\n";
	// //x_i ≥ 0
	// int a = 0, b = 0, c = 0, d = 0;
	// for (int i = 0; i<n; i++){
	// 	if (y[i] > 0){
	// 		a = max(a, x[i]);
	// 		d = max(d, y[i]);
	// 	}
	// 	if (y[i] < 0){
	// 		b = max(b, x[i]);
	// 		c = min(c, y[i]);
	// 	}
	// }
	// // debug(a, b, c, d);
	// c = abs(c);
	// int ans = min({max(a, b), min(2*c+d, 2*d+c)});
	// if (a <= b) ans = min(ans, a+c);
	// if (a >= b) ans = min(ans, b+d);
	// cout << ans << endl;
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
	
	return 0;
}
