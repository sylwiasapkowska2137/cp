//Wrong solution taking minimum from few incorrect solutions

#include <bits/stdc++.h>

using namespace std;

int wrong1(vector<int> A, vector<int> B) {
    int n = A.size();
    int answer = 0;

    for (int i = 1; i < n; i++) {
        if (A[i] <= A[i - 1] || B[i] <= B[i - 1]) {
            swap(A[i], B[i]);
            answer++;
        }
        if (A[i] <= A[i - 1] || B[i] <= B[i - 1]) {
            return -1;
        }
    }

    return answer;
}

int wrong2(vector<int> A, vector<int> B) {
    int n = A.size();
    int answer = 0;

    for (int i = n - 2; i >= 0; i--) {
        if (A[i] >= A[i + 1] || B[i] >= B[i + 1]) {
            swap(A[i], B[i]);
            answer++;
        }
        if (A[i] >= A[i + 1] || B[i] >= B[i + 1]) {
            return -1;
        }
    }

    return answer;
}

int solveSeparately(vector<int> A, vector<int> B) {
    set<int> wrongPositions;
    priority_queue<pair<int, int> > cheapestPositions;
    for (int i = 1; i < (int)A.size(); i++) {
        if (A[i - 1] >= A[i] || B[i - 1] >= B[i]) {
            wrongPositions.insert(i - 1);
        }
    }

    if (wrongPositions.empty()) {
        return 0;
    }

    auto last = wrongPositions.end();
    for (auto it = wrongPositions.begin(); it != wrongPositions.end(); it++) {
        if (last == wrongPositions.end()) {
            last = it;
            cheapestPositions.push({(*it) + 1, *it});
            continue;
        }
        cheapestPositions.push({-((*it) - *last), *it});
        cheapestPositions.push({-((*it) - *last), *last});
        last = it;
    }
    cheapestPositions.push({-(A.size() - 1 - *last), *last});

    int ans = 0;

    while (!cheapestPositions.empty()) {
        int cost = -cheapestPositions.top().first;
        int position = cheapestPositions.top().second;
        cheapestPositions.pop();

        auto it = wrongPositions.find(position);
        if (it == wrongPositions.end()) {
            continue;
        }
        int leftCost;
        auto itPrev = it;
        itPrev--;
        if (it != wrongPositions.begin()) {
            leftCost = (*it) - *itPrev;
        } else {
            leftCost = (*it) + 1;
        }

        int rightCost;
        auto itNext = it;
        itNext++;
        if (itNext != wrongPositions.end()) {
            rightCost = (*itNext) - *it;
        } else {
            rightCost = A.size() - 1 - *it;
        }

        if (leftCost == cost) {
            ans += cost;
            if (it != wrongPositions.begin()) {
                wrongPositions.erase(itPrev);
            }
            wrongPositions.erase(it);
        } else if (rightCost == cost) {
            ans += cost;
            if (itNext != wrongPositions.end()) {
                wrongPositions.erase(itNext);
            }
            wrongPositions.erase(it);
        } else {
            cheapestPositions.push({-leftCost, position});
            cheapestPositions.push({-rightCost, position});
        }
    }

    return ans;
}

int wrong3(vector<int> A, vector<int> B) { //Smart greedy
    for (int i = 1; i < (int)A.size(); i++) {
        if ((A[i] <= A[i - 1] || B[i] <= B[i - 1]) &&
            (A[i] <= B[i - 1] || B[i] <= A[i - 1])) {
            return -1;
        }
    }

    int answer = 0;
    int from = 0;
    for (int i = 1; i < (int)A.size(); i++) {
        if((A[i - 1] < A[i] && B[i - 1] < B[i]) &&
           (B[i - 1] < A[i] && A[i - 1] < B[i])) {
            answer += solveSeparately(vector<int>(A.begin() + from, A.begin() + i),
                                      vector<int>(B.begin() + from, B.begin() + i));
            from = i;
        }
    }
    answer += solveSeparately(vector<int>(A.begin() + from, A.end()),
                              vector<int>(B.begin() + from, B.end()));

    return answer;
}

int main() {
    vector<int> A, B;
    int n, x;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        A.push_back(x);
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        B.push_back(x);
    }

    for (int i = 1; i < (int)A.size(); i++) {
        if ((A[i] <= A[i - 1] || B[i] <= B[i - 1]) &&
            (A[i] <= B[i - 1] || B[i] <= A[i - 1])) {
            printf("NIE\n");
            return 0;
        }
    }

    int answer = min(min(wrong1(A, B), wrong2(A, B)), wrong3(A, B));
    printf("%d\n", answer);

    return 0;
}
