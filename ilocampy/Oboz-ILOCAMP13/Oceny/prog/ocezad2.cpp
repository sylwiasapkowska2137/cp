// Another O(n) smart greedy solution
#include <bits/stdc++.h>

using namespace std;

int solveSeparately(vector<int> A, vector<int> B) {
    vector<int> wrongPositions;
    wrongPositions.push_back(-1);
    for (int i = 1; i < (int)A.size(); i++) {
        if (A[i - 1] >= A[i] || B[i - 1] >= B[i]) {
            wrongPositions.push_back(i - 1);
        }
    }
    wrongPositions.push_back((int)A.size() - 1);

    int ans1 = 0;
    for (int i = 1; i < (int)wrongPositions.size(); i += 2) {
        ans1 += wrongPositions[i] - wrongPositions[i - 1];
    }
    int ans2 = 0;
    for (int i = 2; i < (int)wrongPositions.size(); i += 2) {
        ans2 += wrongPositions[i] - wrongPositions[i - 1];
    }

    return min(ans1, ans2);
}

int main() {
    vector<int> A, B;
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        A.push_back(x);
    }
    for (int i = 0; i < n; i++) {
        int x;
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
