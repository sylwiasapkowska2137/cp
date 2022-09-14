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

int ti(char c){
	return (int)(c-'a');
}

const int K = 20;
bool good[K][K];
bool good2[K][K][K];

void solve(){
	string s, t; cin >> s >> t;
	
	vector<int>cnts(K, 0), cntt(K, 0);
	vector<int>S[K], T[K];
	int k = 0;
	for (auto c: s) {
		cnts[ti(c)]++;
		S[ti(c)].push_back(k++);
	}
	k = 0;
	for (auto c: t) {
		cntt[ti(c)]++;
		T[ti(c)].push_back(k++);
	}
	int q; cin >> q;
	for (char c = 'a'; c<='r'; c++){
		for (char d = c+1; d<='r'; d++){
			int A = ti(c);
			int B = ti(d);
			if (cnts[A] != cntt[A] || cnts[B] != cntt[B]) {
				good[A][B] = 0;
				continue;
			}
			vector<pair<int, int>>first, second;
			for (auto x: S[A]) first.emplace_back(x, 1);
			for (auto x: S[B]) first.emplace_back(x, 0);
			for (auto x: T[A]) second.emplace_back(x, 1);
			for (auto x: T[B]) second.emplace_back(x, 0);
			sort(first.begin(), first.end());
			sort(second.begin(), second.end());
			good[A][B] = 1;
			for (int i = 0; i<(int)first.size(); i++) good[A][B] &= (first[i].second == second[i].second);
		}
	}
	
	for (char c = 'a'; c<='r'; c++){
		for (char d = c+1; d<='r'; d++){
			for (char e = d+1; e<='r'; e++){
				if (good[ti(c)][ti(d)] && good[ti(c)][ti(e)] && good[(ti(d))][ti(e)]){
					good2[ti(c)][ti(d)][ti(e)] = 1;
				}
			}
		}
	}
	while (q--){
		string Q; cin >> Q;
		if ((int)Q.size() == 1){
			if (cntt[ti(Q[0])] == cnts[ti(Q[0])]) cout << "Y";
			else cout << "N";
			continue;
		}
		if ((int)Q.size() == 2){
			if (good[ti(Q[0])][ti(Q[1])]) cout << "Y";
			else cout << "N";
			continue;
		}
		int z = (int)Q.size();
		bool ok = 1;
		for (int i = 0; i<z; i++){
			for (int j = i+1; j<z; j++){
				for (int k = j+1; k<z; k++){
					if (!good2[ti(Q[i])][ti(Q[j])][ti(Q[k])]) {
						ok = 0;
						break;
					}
				}
				if (!ok) break;
			}
			if (!ok) break;
		}
		if (ok) cout << "Y";
		else cout << "N";
	}	
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
	
	return 0;
}
