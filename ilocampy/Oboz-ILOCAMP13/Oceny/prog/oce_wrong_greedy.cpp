// Greedy, pretty smart but not enough, O(n log(n))
#include <bits/stdc++.h>

using namespace std;

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

int main() {
    int n, x;
    vector<int> A, B;
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

    printf("%d\n", answer);
    
    return 0;
}
