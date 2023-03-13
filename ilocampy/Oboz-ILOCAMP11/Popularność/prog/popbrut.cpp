#include <iostream>
#include <cstdio>
#include <cassert>
#include <vector>
#include <algorithm>
#include <set>

const int MAXN = 2000;
const int MAXM = 1000 * 1000;
const int MAXMSUM = 1000 * 1000;

bool following[MAXN + 2][MAXN + 2];
int n, m, l, x;

int main() {
	scanf("%d", &n);
	assert(1 <= n && n <= MAXN);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			scanf("%d", &x);
			assert(x == 0 || x == 1);
			assert(i != j || x == 0);
			if (x) {
				following[i][j] = true;
			}
		}
	}
	
	std::vector<int> subset;
	scanf("%d", &m);
	assert(1 <= m && m <= MAXM);
	int mSUM = 0;
	for (int i = 0; i < m; i++) {
		scanf("%d", &l);
		assert(1 <= l && l <= MAXN);
		mSUM += l;
		
		subset.clear();
		std::set<int> checkSet;
		for (int j = 0; j < l; j++) {
			scanf("%d", &x);
			assert(1 <= l && l <= MAXN);
			assert(checkSet.insert(x).second == true);
			subset.push_back(x);
		}
		
		if (subset.size() == 1) {
			printf("%d\n", subset[0]);
		} else {
			int result = -1;
			for (int j = 0; j < subset.size(); j++) {
				int incoming = 0;
				int outgoing = 0;
				for (int k = 0; k < subset.size(); k++) {
					if (following[subset[k]][subset[j]] == true) {
						incoming++;
					}
					if (following[subset[j]][subset[k]] == true) {
						outgoing++;
					}
				}
				if (outgoing == 0 && incoming == subset.size() - 1) {
					result = subset[j];
					break;
				}
			}
			printf("%d\n", result);
		}
	}
	assert(1 <= mSUM && mSUM <= MAXMSUM);
	
	return 0;
}