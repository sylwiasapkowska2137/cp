//Sylwia Sapkowska
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
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

#define ordered_set tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>


const int MAX = 1e5+1;
vector<int>graf[MAX];
int val[MAX], ans[MAX];
ordered_set s[MAX]; //{cnt[kolor], kolor}
set<pair<int, int>>ile[MAX]; //kolor, cnt[kolor]
vector<pair<int, int>>query[MAX];

void dfs(int v, int pa = -1){
	for (auto x: graf[v]){
		if (x!=pa){
			dfs(x, v);
			if ((int)s[v].size() < (int)s[x].size()){
				swap(s[v], s[x]);
				swap(ile[v], ile[x]);
			}
			for (auto elem:s[x]){
				//chcemy przerzucic elem do s[v]
				auto it = ile[v].lower_bound({elem.second, 0});
				if (it != ile[v].end() && it->first == elem.second){
					ile[v].insert({elem.second, it->second+elem.first});
					s[v].insert({it->second+elem.first, elem.second});
					s[v].erase({it->second, elem.second});
					ile[v].erase(it);
				} else {
					s[v].insert(elem);
					ile[v].insert({elem.second, elem.first});
				}
			}
			s[x].clear();
			ile[x].clear();
		}
	}
	auto it = ile[v].lower_bound({val[v], 0});
	if (it == ile[v].end() || it->first != val[v]){
		ile[v].insert({val[v], 1});
		s[v].insert({1, val[v]});
	} else {
		s[v].erase({it->second, it->first});
		ile[v].insert({it->first, it->second+1});
		s[v].insert({it->second+1, it->first});
		ile[v].erase(it);
	}
	//debug(v, s[v]);
	for (auto [k, i]:query[v]){
		//debug(v, k, s[v].order_of_key({k+1, 0}));
		ans[i] = (int)s[v].size()-s[v].order_of_key({k, 0});
	}
}

void read(int &number){
    bool negative = false;
    register int c;
    number = 0;
    c = getchar();
    if (c=='-'){
        negative = true;
        c = getchar();
    }
    for (; (c>47 && c<58); c=getchar())
        number = number *10 + c - 48;
    if (negative) number *= -1;
}

void solve(){
	int n, q; read(n); read(q);
	for (int i = 1; i<=n; i++) read(val[i]);
	for (int i = 1; i<n; i++){
		int a, b; read(a); read(b);
		graf[a].push_back(b);
		graf[b].push_back(a);
	}
	for (int i = 0; i<q; i++){
		int v, k; read(v); read(k);
		query[v].push_back({k, i});
	}
	dfs(1);
	for (int i = 0; i<q; i++) cout << ans[i] << "\n";
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
	
	return 0;
}
