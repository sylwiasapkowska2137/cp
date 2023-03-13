//Sylwia Sapkowska
#include <bits/stdc++.h>
#pragma GCC optimize("O3", "unroll-loops")
#include "race.h"
using namespace std;
typedef long long ll;
typedef pair<int, ll> T;
const ll oo = 1e18;

int best_path(int n, int k, int H[][2], int L[]){
	vector<vector<T>>g(n+1);
	for (int i = 0; i<n-1; i++){
		H[i][0]++;H[i][1]++;
	}
	for (int i = 0; i<n-1; i++){
		g[H[i][0]].emplace_back(H[i][1], L[i]);
		g[H[i][1]].emplace_back(H[i][0], L[i]);
	}
	vector<int>used(n+1), sz(n+1);
	function<int(int, int)>dfssize = [&](int v, int pa){
		sz[v] = 1;
		for (auto [x, c]: g[v]){
			if (x == pa || used[x]) continue;
			sz[v] += dfssize(x, v);
		}
		return sz[v];
	};
	function<int(int, int, int)>get_centroid = [&](int v, int pa, int ms){
		for (auto [x, c]: g[v]){
			if (x == pa || used[x]) continue;
			if (sz[x] * 2 > ms) return get_centroid(x, v, ms);
		}
		return v;
	};
	ll ans = oo;
	vector<ll>depth(n+1), sum(n+1), mn(k+1, oo);
	mn[0] = 0;
	vector<int>now, to_clear;
	function<void(int)>centroid = [&](int v){
		v = get_centroid(v, v, dfssize(v, v));
		function<void(int, int)>dfs = [&](int u, int pa){
			now.emplace_back(u);
			for (auto [x, c]: g[u]){
				if (x == pa || used[x]) continue;
				depth[x] = depth[u]+1;
				sum[x] = sum[u]+c;
				dfs(x, u);
			}
		};
		for (auto [x, c]: g[v]){
			if (used[x]) continue;
			now.clear();
			depth[x] = 1;
			sum[x] = c;
			dfs(x, v);
			for (auto u: now){
				if (k >= sum[u]) {
					ans = min(ans, depth[u] + mn[k-sum[u]]);
				}
			}
			for (auto u: now){
				if (sum[u] <= k){
					mn[sum[u]] = min(mn[sum[u]], depth[u]);
					to_clear.emplace_back(sum[u]);
				}
				depth[u] = 0;
				sum[u] = 0;
			}
		}
		for (auto x: to_clear) mn[x] = oo;
		to_clear.clear();
		used[v] = 1;
		for (auto [x, c]: g[v]){
			if (!used[x]){
				centroid(x);
			}
		}
	};
	centroid(1);
	if (ans == oo) ans = -1;
	return ans;
}

