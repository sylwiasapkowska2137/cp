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

void solve(){
	int n; cin >> n;
    vector<int> beg(n, 1), end(n, 1), bal(n);
    map<int, int> cnt;
    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        for (auto ch : s) {
            bal[i] += (ch == '(' ? +1 : -1);
            if (bal[i] < 0) beg[i] = false;
        }
        int tb = 0;
        reverse(s.begin(), s.end());
        for (auto ch : s) {
            tb += (ch == '(' ? -1 : +1);
            if (tb < 0) end[i] = false;
        }
        if (end[i]) cnt[bal[i]]++;
    }
    long long ans = 0;
    for (int i = 0; i < n; i++) {
        if (beg[i]) ans += cnt[-bal[i]];
        if (beg[i] && end[i]) ans--;
    }
    cout << ans << '\n';
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
	
	return 0;
}
