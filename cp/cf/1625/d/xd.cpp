#include <bits/stdc++.h>
using namespace std;

const int N = 3e5 + 5, M = 35 * N;
int a[N], son[M][2], idx;

void init() {
	memset(son, 0, sizeof (int) * 2 * idx);
	idx = 0;
}

void push(int x) {
	int cur = 0;
	for (int i = 30; i >= 0; i --) {
		int &to = son[cur][x >> i & 1];
	    to ?: to = ++ idx;
	    cur = to;
	}
}

int find(int x) {
	int cur = 0, ans = 0;
	for (int i = 30; i >= 0; i --) {
		int &to = son[cur][~ x >> i & 1];
		to ? ans += 1 << i, cur = to : cur = son[cur][x >> i & 1];
	}
	return ans;
}

int main() {
	int n, k;
	cin >> n >> k;
	if (k == 0) {
		cout << n << endl;
		for (int i = 1; i <= n; i ++) {
			cin >> a[i];
			cout << i << ' ';
		}
		return 0;
	}
	int pos = 30;
	while ((k >> pos & 1) == 0) {
		pos --;
	}
	map <int, vector<int>> mp;
	map <int, int> place;
	for (int i = 1; i <= n; i ++) {
		cin >> a[i];
		mp[a[i] >> pos + 1].push_back(a[i]);
		place[a[i]] = i;
	}
	vector <int> ans;
	for (auto it : mp) {
		init();
		auto v = it.second;
		for (auto ij : v) {
			push(ij);
		}
		int xx = - 1;
		for (auto ij : v) {
			xx = max(xx, find(ij));
			if (xx >= k) {
				ans.push_back(xx ^ ij);
				ans.push_back(ij);
				break;
			}
		}
		if (xx < k) {
			ans.push_back(v[0]);
		}
	}
	if (ans.size() < 2) {
		cout << - 1;
	} else {
		cout << ans.size() << endl;
		for (auto it : ans) {
			cout << place[it] << ' ';
		}		
	}
	return 0;
}
