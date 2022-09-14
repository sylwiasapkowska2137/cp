//Sylwia Sapkowska
#include <bits/stdc++.h>
#pragma GCC target("popcnt")
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

const int MAX = 1e4+1;
const int S = 1e4, MAXQ = 1e6+7;
bitset<MAX>bit;
bitset<MAXQ>ans;

struct Q{
	int b, s, i;
	Q(){}
	Q(int _b, int _s, int _i){
		b = _b, s = _s, i = _i;
	}
};

vector<Q>query[S+7];

//src: ulubiona stronka
void read(int &number)
{
    //variable to indicate sign of input number
    bool negative = false;
    register int c;
 
    number = 0;
 
    // extract current character from buffer
    c = getchar();
    if (c=='-')
    {
        // number is negative
        negative = true;
 
        // extract the next character from the buffer
        c = getchar();
    }
 
    // Keep on extracting characters if they are integers
    // i.e ASCII Value lies from '0'(48) to '9' (57)
    for (; (c>47 && c<58); c=getchar())
        number = number *10 + c - 48;
 
    // if scanned input has a negative sign, negate the
    // value of the input number
    if (negative)
        number *= -1;
}

void solve(){
	int n; read(n);
	vector<int>a(n+1);
	for (int i = 1; i<=n; i++) {
		read(a[i]);
	}
	int q; read(q);
	for (int i = 0; i<q; i++){
		int l, r, s; read(l); read(r); read(s);
		query[l].emplace_back(r, s, i);
	}
	ans.reset();
	for (int i = 1; i<=n; i++) {
		if (query[i].empty()) continue;
		sort(query[i].begin(), query[i].end(), [](auto x, auto y){return x.b < y.b;});
		bit.reset();
		bit[0] = 1;
		int ptr = 0;
		for (int j = i; j<=n; j++){
			bit |= (bit << a[j]);
			while (ptr < (int)query[i].size() && query[i][ptr].b == j){
				ans.set(query[i][ptr].i, bit[query[i][ptr].s]);
				ptr++;
			}
			if (ptr == (int)query[i].size()) break;
		}
	}
	for (int i = 0; i<q; i++){
		if (ans[i]) cout << "TAK\n";
		else cout << "NIE\n";
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
	
	return 0;
}
