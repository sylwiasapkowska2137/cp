#include <bits/stdc++.h>

using namespace std;

const int N = 200005, REPEATS = 20;

int n, t;
long long x[N], y[N];
bool taken[N];
vector<pair<int, int> > out;

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

vector<int> addLine2(int p1, int p2, const vector<int> &remaining) {
    vector<int> added;
    for (int i = 0; i < remaining.size(); i++) {
        if (det(p1, p2, remaining[i]) == 0 && !taken[remaining[i]]) {
            taken[remaining[i]] = true;
            added.push_back(remaining[i]);
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
        for (int i = 1; i <= k; i++) {
            out.push_back({0, 0});
        }
        return true;
    }
    if (remaining.size() == 1 && k > 0) {
        out.push_back({remaining.back(), remaining.back()});
        return true;
    }
    if (k == 0) {
        return false;
    }
    vector<pair<int, int> > used;
    for (int i = 0; i < remaining.size(); i++) {
        for (int j = i + 1; j < remaining.size(); j++) {
            vector<int> added = addLine2(remaining[i], remaining[j], remaining);
            vector<int> newRemaining;
            for (int l = 0; l < remaining.size(); l++) {
                if (!taken[remaining[l]]) {
                    newRemaining.push_back(remaining[l]);
                }
            }
            if (added.size() >= remaining.size() / k) {
                bool notUsed = true;
                for (int m = 0; m < used.size(); m++) {
                    if (det(used[m].first, used[m].second, remaining[i]) == 0 && det(used[m].first, used[m].second, remaining[j]) == 0) {
                        notUsed = false;
                        break;
                    }
                }
                if (notUsed) {
                    used.push_back({remaining[i], remaining[j]});
                    out.push_back({remaining[i], remaining[j]});
                    if (backtrack(k - 1, newRemaining) == true) {
                        return true;
                    }
                    out.pop_back();
                }
            }
            removeLine(added);
        }
    }
    return false;
}

pair<int, int> randomLine() {
    vector<int> tmp;
    for (int i = 1; i <= n; i++) {
        if (!taken[i]) {
            tmp.push_back(i);
        }
    }
    random_shuffle(tmp.begin(), tmp.end());
    return {tmp[0], tmp[1]};
}

int main() {
    srand(54226);
    int k;

    scanf("%d %d", &n, &k);
    assert(1 <= n && n <= 200000);
    assert(1 <= k && k <= 5);

    map<pair<int, int>, bool> bylo;
    for (int i = 1; i <= n; i++) {
        scanf("%lld %lld", &x[i], &y[i]);
        assert(-1e9 <= x[i] && x[i] <= 1e9);
        assert(-1e9 <= y[i] && y[i] <= 1e9);
        if (!bylo.count({x[i], y[i]})) {
            taken[i] = false;
        } else {
            taken[i] = true;
        }
        bylo[{x[i], y[i]}] = true;

    }
    bool bad = false;
    while (k > 0 && getRemaining() > k * k) {
        bool foundLine = false;
        for (int r = 1; r <= REPEATS; r++) {
//                 vector<int> points = findRandomPoints(k + 1);
            pair<int, int> line = randomLine();
            vector<int> added = addLine(line.first, line.second);

            if (added.size() > k) {
                foundLine = true;
                out.push_back({line.first, line.second});
                break;
            } else {
                removeLine(added);
            }
        }
        if (!foundLine) {
            bad = true;
            break;
        } else {
            k--;
        }
    }
    if (bad || (getRemaining() > 0 && k == 0)) {
        printf("NIE\n");
        return 0;
    }
//         assert(getRemaining() <= 25);
    bool good = false;
    vector<int> remaining;
    for (int i = 1; i <= n; i++) {
        if (!taken[i]) {
            remaining.push_back(i);
        }
    }

    if (backtrack(k, remaining)) {
        good = true;
    }
    if (good) {
        printf("TAK\n");
        for (int i = 0; i < out.size(); i++) {
            if (out[i].first == out[i].second) {
                printf("%lld %lld %lld %lld\n", x[out[i].first], y[out[i].first], 351531LL, 5461616LL);
            } else {
                printf("%lld %lld %lld %lld\n", x[out[i].first], y[out[i].first], x[out[i].second], y[out[i].second]);
            }
        }
    } else {
        printf("NIE\n");
    }

    return 0;
}