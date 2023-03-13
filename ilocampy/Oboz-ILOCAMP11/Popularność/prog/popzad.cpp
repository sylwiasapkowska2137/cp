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

bool isPopular(int id, std::vector<int> &subsetRef) {
	int sumOutgoing = 0, sumIncoming = 0;
	for (int i = 0; i < subsetRef.size(); i++) {
		if (following[subsetRef[id]][subsetRef[i]] == true) {
			sumOutgoing++;
		} else if (following[subsetRef[i]][subsetRef[id]] == true) {
			sumIncoming++;
		}
	}
	
	if (sumIncoming == subsetRef.size() - 1 && sumOutgoing == 0) {
		return true;
	} else {
		return false;
	}
}

int checkPopularity(int current, int next, std::vector<int> &subsetRef) {
	if (following[subsetRef[current]][subsetRef[next]] == true) {
		if (next < subsetRef.size() - 1) {
			return checkPopularity(next, next + 1, subsetRef);
		} else {
			if (isPopular(next, subsetRef)) {
				return subsetRef[next];
			} else {
				return -1;
			}
		}
	} else {
		if (next < subsetRef.size() - 1) {
			return checkPopularity(current, next + 1, subsetRef);
		} else {
			if (isPopular(current, subsetRef)) {
				return subsetRef[current];
			} else {
				return -1;
			}
		}
	}
}

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
			printf("%d\n", checkPopularity(0, 1, subset));
		}
	}
	assert(1 <= mSUM && mSUM <= MAXMSUM);
	
	return 0;
}