#pragma GCC optimize ("Ofast,inline")
// Olaf Surgut 28.02.2023 18:12:27
#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 7;

int n;
vector<int> adj[N];

pair<int, int> dp[N]; // <ans, len>

pair<int, int> merge(pair<int, int> a, pair<int, int> b) {
	auto [aa, bb] = a;
	auto [cc, dd] = b;
	
	return make_pair(min({aa, cc, max(bb, dd)}), min(bb, dd));
}

void dfs1(int u, int f) {
	if ((int) adj[u].size() == (f != -1)) {
		dp[u] = make_pair(n, 1);
		return;
	}

	dp[u] = make_pair(n, n);
	for (int v : adj[u]) if (v != f) {
		dfs1(v, u);

		dp[u] = merge(dp[u], dp[v]);
	}

	dp[u].second++;
}

int ans;
void dfs2(int u, int f) {
	vector<pair<int, int>> A, B;
	
	const int s = (int) adj[u].size();

	pair<int, int> now = make_pair(n, n);
	for (int v : adj[u]) {
		A.push_back(dp[v]);
		B.push_back(dp[v]);

		now = merge(now, dp[v]);
	}

	now.second++;

	ans = max(ans, min(now.first, now.second));

	for (int i = 1; i < (int) A.size(); i++)
		A[i] = merge(A[i], A[i - 1]);
	
	for (int i = (int) B.size() - 2; i >= 0; i--)
		B[i] = merge(B[i], B[i + 1]);

	for (int i = 0; i < s; i++) {
		int v = adj[u][i];

		if (v == f)
			continue;

		if (i == 0 && i + 1 == s)
			dp[u] = make_pair(n, 0);
		else
		if (i == 0)
			dp[u] = B[i + 1];
		else
		if (i + 1 == s)
			dp[u] = A[i - 1];
		else
			dp[u] = merge(A[i - 1], B[i + 1]);

		dp[u].second++;	

		dfs2(v, u);
	}
}

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr);
	
	int t; cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 0; i < n - 1; i++) {
			int u, v; cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}

		ans = 0;

		dfs1(1, -1);
		dfs2(1, -1);
		cout << ans << '\n';

		for (int i = 1; i <= n; i++)
			adj[i].clear();
	}
}

