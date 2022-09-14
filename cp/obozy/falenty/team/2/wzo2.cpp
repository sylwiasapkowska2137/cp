//Sylwia Sapkowska
#include <bits/stdc++.h>
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


const int oo = 1e9+7;
const int mx = 1e6+7;
const int mx2 = 80007;
const int N = 5e5+100;
const int K = 20;

int st[N][K], lg[N];
int check[mx+7];

int que(int l, int r) {
	int j = lg[r-l+1];
	return min(st[l][j], st[r-(1<<j)+1][j]);
}

vector<int> factors(int x){
	vector<int>ans;
	while (check[x]){
		ans.emplace_back(check[x]);
		x/=check[x];
	}
	ans.emplace_back(x);
	return ans;
}

vector<int>prime;
int get(int x){
	return (int)(lower_bound(prime.begin(), prime.end(), x)-prime.begin());
}

void solve(){
	int n; cin >> n;
	vector<int>a(n+1);
	
	for (long long i = 2; i<mx; i++){
		if (check[i]) continue;
		prime.emplace_back(i);
		for (long long j = i*i; j<(long long)mx; j+=i){
			check[j] = i;
		}
	}
	for (int i = 1; i<=n; i++) cin >> a[i];
	string s; cin >> s;
	s = "$"+s;
	for (int i = 1; i<=n; i++){
		if (a[i] == 1) {
			s[i] = 'M';
		}
	}

	vector<vector<int>>curr(mx2);
	vector<int>mn(n+1, oo);
	for (int i = 1; i<=n; i++){
		vector<int>d = factors(a[i]);
		if (s[i] == 'M'){
			for (auto x: d){
				curr[get(x)].emplace_back(i);
			}
		} else {
			for (auto x: d){
				int y = get(x);
				if (curr[y].empty()){
					mn[i] = -1;
					break;
				}
				mn[i] = min(mn[i], curr[y].back());
				curr[y].pop_back();
			}
		}
	}
	lg[1] = 0;
	for (int i = 2; i<N; i++) lg[i] = lg[i/2]+1;
	for (int i = 1; i<=n; i++) st[i][0] = mn[i];
	for (int j = 1; j<K; j++){
		for (int i = 0; i+(1<<j) <= n; i++){
			st[i][j] = min(st[i][j-1], st[i+(1<<(j-1))][j-1]);
		}
	}
    long long ans = 0;
    for (int i = 1; i<=n; i++){
        int L = i, R = n, curr = -1;
        while (R >= L){
            int mid = (L+R)/2;
            if (que(i, mid) >= i) {
                L = mid+1;
                curr = mid;
            } else {
                R = mid-1;
            }
        }
        if (curr != -1) ans += curr-i+1;
    }
    cout << ans << "\n";
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
	
	return 0;
}
