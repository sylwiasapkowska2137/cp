#include <bits/stdc++.h>

using namespace std;

const int N = 20005, REPEATS = 100;

int n, t;
long long x[N], y[N];
bool taken[N];

vector<int> findRandomPoints(int cnt) {
    vector<int> all;
    for (int i = 1; i <= n; i++) {
        if (!taken[i]) {
            all.push_back(i);
        }
    }
    random_shuffle(all.begin(), all.end());
    vector<int> ret;
    for (int i = 0; i < cnt; i++) {
        ret.push_back(all[i]);
    }
    return ret;
}

long long det(int a, int b, int c) {
    return x[a] * y[b] + x[b] * y[c] + x[c] * y[a] - y[a] * x[b] - y[b] * x[c] - y[c] * x[a];
}

bool collinear(vector<int> points) {
    for (int i = 2;i < points.size(); i++) {
        if (det(points[0], points[1], points[i]) != 0) {
            return false;
        }
    }
    return true;
}

int getRemaining() {
    int ret = 0;
    for (int i = 1; i <= n; i++) {
        if (!taken[i]) {
            ret++;
        }
    }
    return ret;
}

vector<int> addLine(int p1, int p2) {
    vector<int> added;
    for (int i = 1; i <= n; i++) {
        if (det(p1, p2, i) == 0 && !taken[i]) {
            taken[i] = true;
            added.push_back(i);
        }
    }
    return added;
}

void removeLine(vector<int> added) {
    for (int i = 0; i < added.size(); i++) {
        taken[added[i]] = false;
    }
}

bool backtrack(int k, vector<int> remaining) {
    random_shuffle(remaining.begin(), remaining.end());
    if (remaining.size() == 0) {
        return true;
    }
    if (remaining.size() == 1 && k > 0) {
        return true;
    }
    if (k == 0) {
        return false;
    }

    for (int i = 0; i < remaining.size(); i++) {
        for (int j = i + 1; j < remaining.size(); j++) {
            vector<int> added = addLine(i, j);
            vector<int> newRemaining;
            for (int l = 0; l < remaining.size(); l++) {
                if (!taken[remaining[l]]) {
                    newRemaining.push_back(remaining[l]);
                }
            }
            if (added.size() >= remaining.size() / k && backtrack(k - 1, newRemaining) == true) {
                return true;
            }
            removeLine(added);
        }
    }
    return false;
}

int main() {
    srand(54226);
    scanf("%d", &t);
    int k;

    while (t--) {
        scanf("%d %d", &n, &k);

        map<pair<int, int>, bool> bylo;
        for (int i = 1; i <= n; i++) {
            scanf("%lld %lld", &x[i], &y[i]);
            if (!bylo.count({x[i], y[i]})) {
                taken[i] = false;
            } else {
                taken[i] = true;
            }
            bylo[{x[i], y[i]}] = true;

        }
        while (k > 0 && getRemaining() > k * k) {
            bool foundLine = false;
            for (int r = 1; r <= REPEATS; r++) {
//                 vector<int> points = findRandomPoints(k + 1);
                
                if (collinear(points)) {
                    foundLine = true;
                    addLine(points[0], points[1]);
                    break;
                }
            }
            if (!foundLine) {
                break;
            } else {
                k--;
            }
        }
        assert(getRemaining() <= 25);
        bool good = false;
        if (k == 0 && getRemaining() == 0) good = true;
        if (k > 0) {
            vector<int> remaining;
            for (int i = 1; i <= n; i++) {
                if (!taken[i]) {
                    remaining.push_back(i);
                }
            }
            if (backtrack(k, remaining)) {
                good = true;
            }
        }
        if (good) {
            printf("TAK\n");
        } else {
            printf("NIE\n");
        }
    }

    return 0;
}