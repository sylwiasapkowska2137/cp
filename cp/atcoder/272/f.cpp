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

#define int long long
const int oo = 1e18, oo2 = 1e9+7, K = 30;
const int mod = 998244353;


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

void suffix_array(string s){
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

struct H {
    typedef uint64_t ull;
    ull x;
    H(ull x = 0) : x(x) {}
#define OP(O, A, B)                         \
    H operator O(H o)                       \
    {                                       \
        ull r = x;                          \
        asm(A "addq %%rdx, %0\n adcq $0,%0" \
            : "+a"(r)                       \
            : B);                           \
        return r;                           \
    }
    OP(+, , "d"(o.x))
    OP(*, "mul %1\n", "r"(o.x)
       : "rdx")
    H operator-(H o)
    {
        return *this + ~o.x;
    }
    ull get() const { return x + !~x; }
    bool operator==(H o) const { return get() == o.get(); }
    bool operator<(H o) const { return get() < o.get(); }
};
static const H C = (long long)1e11 + 3;

struct HashInterval {
    vector<H> ha, pw;
    HashInterval() {}
    void init(string &str)
    {
        ha.resize(str.size() + 1);
        pw.resize(str.size() + 1);
        pw[0] = 1;
		for (int i = 0; i<(int)str.size(); i++)
            ha[i + 1] = ha[i] * C + str[i],
                   pw[i + 1] = pw[i] * C;
    }
    H operator()(int a, int b)
    {
        b++;
        return ha[b] - ha[a] * pw[b - a];
    }
};

void solve(){
	int n; cin >> n;
	string s; cin >> s;
	string t; cin >> t;
	suffix_array(s);
	vector<int>S = p;
	p.clear();c.clear();
	suffix_array(t);
	vector<int>T = p;
	// debug(S);
	// debug(T);
	// return;
	set<pair<int, int>>eq;
	int ptr1 = 0, ptr2 = 0;
	vector<pair<int, int>>merged;
	HashInterval SS; SS.init(s);
	HashInterval TT; TT.init(t);
	for (int i = 1; i<=n+n+2; i++){
		if (ptr1 > n){
			merged.emplace_back(T[ptr2], 1);
			ptr2++;
			continue;
		}
		if (ptr2 > n){
			merged.emplace_back(S[ptr1], 0);
			ptr1++;
			continue;
		}
		//compare suffixes starting with S[ptr1] and T[ptr2]
		if (s[S[ptr1]] != t[T[ptr2]]){
			if (s[S[ptr1]] < t[T[ptr2]]){
				merged.emplace_back(S[ptr1], 0);
				ptr1++;
			} else {
				merged.emplace_back(T[ptr2], 1);
				ptr2++;
			}
			continue;
		}
		int L = 0, R = min(n-S[ptr1]-1, n-T[ptr2]-1);
		int ans = 0;
		// debug(L, R);
		while (R >= L){
			int mid = (L+R)/2;
			if (SS(S[ptr1], S[ptr1]+mid) == TT(T[ptr2], T[ptr2]+mid)){
				ans = mid;
				L = mid+1;
			} else {
				R = mid-1;
			}
		}
		// debug(ans, S[ptr1]+ans);
		if (ans == min(n-S[ptr1]-1, n-T[ptr2]-1) && ans == max(n-S[ptr1]-1, n-T[ptr2]-1)){
			// cerr << "equal " << S[ptr1] << " " << T[ptr2] << "\n";
			eq.insert({S[ptr1], T[ptr2]});
			merged.emplace_back(S[ptr1], 0);
			ptr1++;
			continue;
		}
		// debug(s[S[ptr1] + ans + 1], t[T[ptr2]+ans+1]);
		if (s[S[ptr1] + ans + 1] < t[T[ptr2]+ans+1]){
			merged.emplace_back(S[ptr1], 0);
			ptr1++;
		} else {
			merged.emplace_back(T[ptr2], 1);
			ptr2++;
		}
	}
	// debug(S);
	// debug(T);
	debug(merged);
	int sum = 0;
	int ans = 0;
	for (int i = 0; i<(int)merged.size(); i++){
		int ok = 1;
		if (i){
			if (merged[i-1].second != merged[i].second){
				pair<int, int> curr = {merged[i-1].first, merged[i].first};
				if (merged[i].second == 0) swap(curr.first, curr.second);
				auto it = eq.lower_bound(curr);
				if (it != eq.end() && *it == curr) ok = 0;
			}
		}
		if (merged[i].second) {
			ans += sum;
			// debug(sum);
		}
		if (ok == 0) {
			ans--;
			// debug(i);		
		}
		// debug(sum, ans);
		if (!merged[i].second) sum++;
	}
	if (s.back() == t.back()){
		int ile = 1;
		for (int i = n-2; i>=1; i--) {
			if (s[i] == t[i]) ile++;
			else break;
		}
		for (int i = 0; i<n; i++){
			if (s[i] == t[i]){
				continue;
			}
			if (s[i] < t[i]){
				// debug(i);
				ans += (n-2-i)*ile;
			} else break;
		}
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
