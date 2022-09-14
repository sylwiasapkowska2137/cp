//Sylwia Sapkowska
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
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

typedef long double LD;

const LL INF = 1e18;

struct line{
	LL a, b, idx; 
	line(){}
	line (LL _a, LL _b, int _idx){
		a = _a, b = _b, idx = _idx;
	}
	LL f(LL x){
		return a*x+b;
	}
	LL inter(line l){
		if (a == l.a) return INF;
		LD x = (LD)(((LD)(b-l.b))/((LD)(l.a-a)));
		//debug(x);
		return floor(x);
	}
};

pair<LL, int> check(int C, vector<LL>&pref, int n){
    vector<LL>dp(n+1, 0);
    vector<int>dp2(n+1);
    deque<line>dq;
	dq.push_back({0, 0, 0});
    for (int i = 1; i<=n; i++){
        LL val = pref[n]-pref[i];
		while (dq.size() >= 2 && dq.back().f(val) <= dq[dq.size()-2].f(val)) dq.pop_back();
		dp[i] = dq.back().f(val) + pref[i]*val - C;
		dp2[i] = dp2[dq.back().idx]+1;
		line curr = line{-pref[i], dp[i], i};
		while (dq.size() >= 2 && curr.inter(dq.front()) >= dq.front().inter(dq[1])) dq.pop_front();
		dq.push_front(curr);
    }
    LL ans = -1;
    int ile = 0;
    for (int i = 1; i<=n; i++){
        if (dp[i] > ans){
            ans = dp[i];
            ile = dp2[i];
        }
    }
    return {ans, ile};
}

void solve(){
	int n, k; cin >> n >> k;
	vector<int>a(n+1);
	for (int i = 1; i<=n; i++) {
		cin >> a[i];
	}
	vector<LL>pref(n+1, 0LL);
	for (int i = 1; i<=n; i++) pref[i] = pref[i-1]+a[i];
	
    const int INF2 = (1<<20);
    int L = 0, R = INF2, ans = 0;
    while (R>=L){
        int mid = (L+R)/2;
        pair<LL, int> x = check(mid, pref, n);
        //debug(mid, x);
        if (x.second >= k){
            ans = mid;
            L = mid+1;
        } else R = mid-1;
    }
    //debug(ans);
	pair<LL, int>y = check(ans, pref, n);
	cout << y.first+k*ans << "\n";
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
	
	return 0;
}
