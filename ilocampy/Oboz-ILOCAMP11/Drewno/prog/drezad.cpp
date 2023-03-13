#include <iostream>
#include <cstdio>
#include <cassert>
#include <vector>
#include <algorithm>
#include <cmath>

const int MAXN = 10 * 1000;
const int MAXL = 10 * 1000;
const int MAXM = 500 * 1000;
const unsigned long long int MAXD = 1000 * 1000 * 1000 * 1000 * 1000 * 1000;

short int forests[MAXN + 5];
int sqrtTab[MAXL + 5][105];
int sqrtVal;

inline int getSqrtPos(int pos) {
	return (pos - 1) / sqrtVal;
}

void prepareSqrtTab(int n) {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= forests[i]; j++) {
			sqrtTab[j][getSqrtPos(i)] += forests[i] / j;
		}
	}
}

int findAnswerFor(int a, int b, unsigned long long int d) {
	int begin = 1, end = MAXL;
	int middle = 0;
	long long int currentAns;
	int beforeBegin, beforeEnd;
	int sqrtBegin, sqrtEnd;
	int afterBegin, afterEnd;
	bool beforeCheck, sqrtCheck, afterCheck;

	if (a == getSqrtPos(a) * sqrtVal) {
		beforeCheck = false;
	} else {
		beforeCheck = true;
		beforeBegin = a;
		beforeEnd = (getSqrtPos(a) + 1) * sqrtVal - 1;
	}

	if (b + 1 == (getSqrtPos(b) + 1) * sqrtVal) {
		afterCheck = false;
	} else {
		afterCheck = true;
		afterBegin = getSqrtPos(b) * sqrtVal;
		afterEnd = b;
	}

	if (getSqrtPos(a) + beforeCheck + afterCheck <= getSqrtPos(b)) {
		sqrtCheck = true;
		sqrtBegin = getSqrtPos(a) + beforeCheck;
		sqrtEnd = getSqrtPos(b) - afterCheck;
	} else {
		sqrtCheck = false;
	}

	while ((begin + end) / 2 != middle) {
		middle = (begin + end) / 2;
		currentAns = 0;

		if (a == b) {
			currentAns = forests[a] / middle;
		} else {
			if (beforeCheck) {
				for (int i = beforeBegin; i <= beforeEnd; i++) {
					currentAns += forests[i] / middle;
				}
			}
			if (sqrtCheck) {
				for (int i = sqrtBegin; i <= sqrtEnd; i++) {
					currentAns += sqrtTab[middle][i];
				}
			}
			if (afterCheck) {
				for (int i = afterBegin; i <= afterEnd; i++) {
					currentAns += forests[i] / middle;
				}
			}
		}

		if (currentAns >= d) {
			begin = middle;
		} else {
			end = middle;
		}
	}

	if (begin == end && begin == 1 && currentAns < d) {
		return -1;
	}

	if (begin != end) {
		currentAns = 0;

		if (a == b) {
			currentAns = forests[a] / middle;
		} else {
			if (beforeCheck) {
				for (int i = beforeBegin; i <= beforeEnd; i++) {
					currentAns += forests[i] / end;
				}
			}
			if (sqrtCheck) {
				for (int i = sqrtBegin; i <= sqrtEnd; i++) {
					currentAns += sqrtTab[end][i];
				}
			}
			if (afterCheck) {
				for (int i = afterBegin; i <= afterEnd; i++) {
					currentAns += forests[i] / end;
				}
			}
		}
		if (currentAns >= d) {
			return end;
		}
	}

	return begin;
}

int main() {
	int n;
	scanf("%d", &n);
	sqrtVal = std::sqrt(n);
	assert(1 <= n && n <= MAXN);
	long long int sumOfAll = 0;
	for (int i = 1; i <= n; i++) {
		scanf("%hd", &forests[i]);
		sumOfAll += forests[i];
		assert(1 <= forests[i] && forests[i] <= MAXL);
	}

	prepareSqrtTab(n);

	int m;
	scanf("%d", &m);
	assert(1 <= m && m <= MAXM);
	int a, b;
	unsigned long long int d;
	for (int i = 0; i < m; i++) {
		scanf("%d%d%llu", &a, &b, &d);
		assert(1 <= a && a <= n);
		assert(1 <= b && b <= n);
		assert(a <= b);
		assert(1 <= d && d <= MAXD);
		if (sumOfAll < d) {
			printf("%d\n", -1);
		} else {
			a--; b--;
			printf("%d\n", findAnswerFor(a, b, d));
		}
	}

    return 0;
}