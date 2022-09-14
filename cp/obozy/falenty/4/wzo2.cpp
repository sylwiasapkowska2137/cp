//Sylwia Sapkowska
#include <bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
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

// #define int long long
// const int oo = 1e18, oo2 = 1e9+7, K = 30;
// const int mod = 998244353;
const int oo = 1e9+7;

void radix_sort(vector <pair<pair<int, int>, int>> &a){
    
	int n = a.size();
    vector <int> cnt(n), pos(n);
    vector <pair<pair<int, int>, int>> a2(n);
	{
        for (auto x: a) cnt[x.first.second]++;   
        pos[0] = 0;
        for (int i = 1; i<n; i++) pos[i] = pos[i-1]+cnt[i-1];
        for (auto x: a){
            a2[pos[x.first.second]] = x;
            pos[x.first.second]++;
        }
        swap(a, a2);
    }
	cnt.assign(n, 0);
    pos.assign(n, 0);
    a2.assign(n, {{0, 0}, 0});
	{
		for (auto x: a) cnt[x.first.first]++;
		pos[0] = 0;
		for (int i = 1; i<n; i++) pos[i] = pos[i-1]+cnt[i-1];
		for (auto x: a){
			a2[pos[x.first.first]] = x;
			pos[x.first.first]++;
		}
		swap(a, a2);
	}
}

vector<int>p, c;

void suffix_array(string &s){
	s += "$";
	int n = (int)s.size();
	//k = 0;
	vector<pair<char, int>>a;
	for (int i = 0; i<n; i++) a.emplace_back(s[i], i);
	sort(a.begin(), a.end());
	p.resize(n);
	c.resize(n);
	for (int i = 0; i<n; i++) p[i] = a[i].second;
	c[p[0]] = 0;
	for (int i = 1; i<n; i++){
		if (a[i].first == a[i-1].first) c[p[i]] = c[p[i-1]];
		else c[p[i]] = c[p[i-1]]+1;
	}
	int k = 0;
    
	while ((1<<k) < n){
		//k -> k+1
        vector<pair<pair<int, int>, int>>a;
		for (int i = 0; i<n; i++) a.push_back({{c[i], c[(i+(1<<k))%n]}, i});
		radix_sort(a);
        // sort(a.begin(), a.end());
		for (int i = 0; i<(int)a.size(); i++) p[i] = a[i].second;
		c[p[0]] = 0;
		for (int i = 1; i<n; i++){
			if (a[i].first == a[i-1].first) c[p[i]] = c[p[i-1]];
			else c[p[i]] = c[p[i-1]]+1;
		}
		k++;
	}
}

struct min_queue{
	deque<pair<int, int>>q;

	void clear(){while (q.size()) q.pop_back();}

	int min(){return (q.size() ? q.front().first : 0);}

	void add(int v, int idx){
		while (q.size() && q.back().first >= v) q.pop_back();
		q.push_back({v, idx});
	}

	void remove(int idx){
		while (q.size() && q.front().second <= idx) q.pop_front();
	}
};

void solve(){
	int n, ck; cin >> n >> ck;
    string s; cin >> s;
    if (ck == 1){
        cout << n << "\n";
        return;
    }
    n++;
    suffix_array(s);
    // debug(p);
    // debug(c);
    vector<int>lcp(n);
	int k = 0;
	for (int i = 0; i<n-1; i++){
		int pi = c[i];
		int j = p[pi-1];
		while (s[i+k] == s[j+k])k++;
		lcp[pi] = k;
		k = max(0, k-1);
	}
    // TreeMax t(n+1, lcp);
    int ans = -1;
    min_queue Q;
    ck = min(ck, n);
    // debug(ck);
    // debug(lcp);
    for (int i = 0; i<ck-1; i++) Q.add(lcp[i], i);
    // debug(Q.q);
    for (int i = ck-1; i<n; i++){
        ans = max(ans, Q.min());
        Q.remove(i-(ck-1));
        Q.add(lcp[i], i);
        // debug(Q.q);
    }
    ans = max(ans, Q.min());
    if (ans <= 0) cout << "-1\n";
    else cout << ans << "\n";
}


int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
	
	return 0;
}
