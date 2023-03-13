//Sylwia Sapkowska
#include <bits/stdc++.h>
#include "werewolf.h"
#pragma GCC optimize("O3", "unroll-loops")
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
#ifndef DEBUG
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif

typedef pair<int, int> T;
typedef vector<int> vi;
const int oo = 1e9+7;

struct Reach{
	vector<int>rep, pre = {0};
	vector<vector<int>>g;
	int s, cnt, nn, tt = 0;
	bool ff;

	Reach(int n, int _f){
		ff = _f; nn = n; 
		s = 2*n+3;
		cnt = n+1;
		rep.assign(s, 0);
		iota(rep.begin(), rep.end(), 0);
		g.resize(s);
	}

	int f(int a){return rep[a] == a ? a : rep[a] = f(rep[a]);}

	void u(int a, int b){
		int A = a, B = b;
		a = f(a); b = f(b);
		if (a == b) return;
		rep[a] = cnt;
		rep[b] = cnt;
		g[cnt].emplace_back(a);
		g[cnt].emplace_back(b);
		cnt++;
	}

	void dfs(int v){
		if (v <= nn) pre.emplace_back(v);
		for (auto x: g[v]) dfs(x);
	}

	void unionL(vector<vector<int>>&adj){
		for (int i = 1; i<=nn; i++){
			for (auto j: adj[i]){
				if (j < i){
					u(j, i);
				}
			}
		}
		dfs(cnt-1);
	}

	void unionR(vector<vector<int>>&adj){
		for (int i = nn; i>=1; i--){
			for (auto j: adj[i]){
				if (j > i){
					u(j, i);
				}
			}
		}
		dfs(cnt-1);
	}
};

struct Tree{
    vector<int>tab;
    int size = 1;

    Tree(int n){
        while (size < n) size*=2;
        tab.assign(2*size, 0);
    }

    void update(int x){
        x += size;
        tab[x] = 1;
        while (x){
            x/=2;
            tab[x]++;
        }
    }

    int query(int l, int r){
        int ans = 0;
        for (l += size-1, r += size+1; r-l>1; l/=2, r/=2){
            if (!(l&1)) ans += tab[l+1];
            if (r&1) ans += tab[r-1];
        }
        return ans;
    }
};

struct interval{
    int a, b, idx;
    interval(){}
    interval(int _a, int _b, int _idx){a = _a, b = _b, idx = _idx;}
}; 


vi check_validity(int n, vi X, vi Y, vi S, vi E, vi L, vi R){
    vector<vector<int>>g(n+1);
    int m = (int)X.size();
    for (int i = 0; i<m; i++){
		X[i]++;Y[i]++;
		g[X[i]].emplace_back(Y[i]);
		g[Y[i]].emplace_back(X[i]);
    }
	Reach A(n, 1), B(n, 0);
	A.unionL(g);
	debug(A.pre);
	cerr << "\n";
	B.unionR(g);
	debug(B.pre);
	return vi{69};
	int q = (int)S.size();
	vector<vector<interval>>sweep(n+1);
	for (int i = 0; i<q; i++){
		L[i]++;R[i]++;
	// 	swap(c, d);
	// 	debug(a, b, c, d);
    //     sweep[b].emplace_back(c, d, i+1);
    //     sweep[a-1].emplace_back(c, d, -(i+1));
    }
    Tree t(n+1);
	vector<int>pos(n+1);
	for (int i = 0; i<n; i++) pos[B.pre[i]] = i+1;
    vector<int>ans(q);
    for (int i = 0; i<=n; i++){
        if (i<n) t.update(pos[A.pre[i]]);
        for (auto [l, r, idx] : sweep[i]){
            if (idx > 0) ans[idx-1] += t.query(l, r);
            else ans[-idx-1] -= t.query(l, r); 
        }
    }
	for (int i = 0; i<=q; i++){
		if (ans[i]) {
			ans[i] = 1;
		}
	}
	return ans;
}
