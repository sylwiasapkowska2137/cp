#include "generator.h"

#include <memory>
#include <set>
#include <queue>

template <class F, class S>
std::ostream &operator<<(std::ostream &os, const std::pair<F, S> &pair) {
    os << pair.first << " " << pair.second;
    return os;
}

using graph_t = std::vector<std::pair<int, int>>;
using namespace std;

const int MIN_N = 1, MAX_N = 1000000,
          MAX_VALUE = 1e9, MIN_VALUE = -MIN_VALUE;

Test exampleTest();
Test cornerCase1();
Test cornerCase2();
Test cornerCase3();
Test twoElements1();
Test twoElements2();
Test twoElements3();
Test twoElements4();
Test twoElements5();
Test small1();
Test small2();
Test small3();
Test small4();
Test randomTest(int n, int k, int minValue, int maxValue);
Test antiWrongTest(int n, int k, int minValue, int maxValue);
Test largeAnswer1(int n, int minValue, int delta1, int delta2);
Test largeAnswer2(int n, int minValue, int delta);
Test cornerLarge1(int n);
Test cornerLarge2(int n);
Test cornerLarge3(int n);
Test totalRandom(int n, int minValue, int maxValue);
int getAnswer(vector<int> A, vector<int> B);
int getWrongAnswer(vector<int> A, vector<int> B);

int main() {
    Generator gen("oce");

    gen.beginGroup();
    gen.addTest(exampleTest());
    gen.endGroup();

    //1
    gen.beginGroup();
    {
        gen.addTest(cornerCase1());
        gen.addTest(cornerCase2());
        gen.addTest(cornerCase3());
        gen.addTest(twoElements1());
        gen.addTest(twoElements2());
        gen.addTest(twoElements3());
        gen.addTest(twoElements4());
        gen.addTest(twoElements5());
        gen.addTest(small1());
        gen.addTest(small2());
    }
    gen.endGroup();

    //2
    gen.beginGroup();
    {
        gen.addTest(small3());
        gen.addTest(small4());
        Generator::setSeed(2001001);
        gen.addTest(antiWrongTest(10, 5, -10, 10));
        Generator::setSeed(2002002);
        gen.addTest(antiWrongTest(20, 40, 0, 100));
        Generator::setSeed(2003003);
        gen.addTest(randomTest(30, 30, -50, 50));
    }
    gen.endGroup();

    //3, n <= 1000
    gen.beginGroup();
    {
        int n = 1000;
        Generator::setSeed(3001001);
        gen.addTest(randomTest(n, 100, -10000, 10000));
        Generator::setSeed(3002002);
        gen.addTest(antiWrongTest(n, 20, -10000, 10000));
        Generator::setSeed(3003003);
        gen.addTest(antiWrongTest(n, 5000, -10000, 10000));
        gen.addTest(largeAnswer1(n, -10000, 5, 3));
    }
    gen.endGroup();

    //4, n <= 30000
    gen.beginGroup();
    {
        int n = 30000;
        Generator::setSeed(4001001);
        gen.addTest(randomTest(n, 100000, MIN_VALUE, MAX_VALUE));
        Generator::setSeed(4002002);
        gen.addTest(antiWrongTest(n, 100, MIN_VALUE, MAX_VALUE));
        Generator::setSeed(4003003);
        gen.addTest(antiWrongTest(n, 3 * n, MIN_VALUE, MAX_VALUE));
        gen.addTest(largeAnswer1(n, MIN_VALUE, 100, 55));
        gen.addTest(largeAnswer2(n, MIN_VALUE, 100));
    }
    gen.endGroup();

    //5, n <= 100000, n * sqrt(n)
    gen.beginGroup();
    {
        int n = 100000;
        Generator::setSeed(5001001);
        gen.addTest(randomTest(n, 1000, MIN_VALUE, MAX_VALUE));
        Generator::setSeed(5002002);
        gen.addTest(antiWrongTest(n, 1000, MIN_VALUE, MAX_VALUE));
        Generator::setSeed(5003003);
        gen.addTest(antiWrongTest(n, 10 * n, MIN_VALUE, MAX_VALUE));
        gen.addTest(largeAnswer1(n, MIN_VALUE, 10000, 5015));
        gen.addTest(largeAnswer2(n, MIN_VALUE, 1000));
    }
    gen.endGroup();

    //6, n <= 1000000
    gen.beginGroup();
    {
        int n = 500000;
        Generator::setSeed(6001001);
        gen.addTest(randomTest(n, 1000000, MIN_VALUE, MAX_VALUE));
        Generator::setSeed(6002002);
        gen.addTest(antiWrongTest(n, 250000, MIN_VALUE, MAX_VALUE));
        Generator::setSeed(6003003);
        gen.addTest(antiWrongTest(n, 50 * n, MIN_VALUE, MAX_VALUE));
        gen.addTest(largeAnswer1(n, MIN_VALUE, 1000000, 5));
        gen.addTest(largeAnswer2(n, MIN_VALUE, 853));
    }
    gen.endGroup();

    //7, n <= 1000000
    gen.beginGroup();
    {
        int n = 500000;
        Generator::setSeed(7001001);
        gen.addTest(randomTest(n, 1000000, MIN_VALUE, MAX_VALUE));
        Generator::setSeed(7002002);
        gen.addTest(antiWrongTest(n, 250000, MIN_VALUE, MAX_VALUE));
        gen.addTest(largeAnswer1(n, MIN_VALUE, 1000000, 351));
        gen.addTest(largeAnswer2(n, MIN_VALUE, 622));
        Generator::setSeed(7003003);
        gen.addTest(cornerLarge1(n));
        gen.addTest(cornerLarge2(n));
        gen.addTest(cornerLarge3(n));
        Generator::setSeed(7004004);
        gen.addTest(totalRandom(n, -1000, 1000));

    }
    gen.endGroup();


    gen.generate();
}

using namespace std;

int random(int a, int b);

Test exampleTest() {
    Test test;
    test.addLine(5);
    test.addLine(5, 3, 7, 7, 10);
    test.addLine(1, 6, 6, 9, 9);
    return test;
}

Test cornerCase1() {
    Test test;
    test.addLine(1);
    test.addLine(1);
    test.addLine(5);
    return test;
}

Test cornerCase2() {
    Test test;
    test.addLine(1);
    test.addLine(2);
    test.addLine(-6);
    return test;
}

Test cornerCase3() {
    Test test;
    test.addLine(1);
    test.addLine(0);
    test.addLine(0);
    return test;
}

Test twoElements1() {
    Test test;

    test.addLine(2);
    test.addLine(1, 3);
    test.addLine(2, 2);

    return test;
}

Test twoElements2() {
    Test test;

    test.addLine(2);
    test.addLine(2, 5);
    test.addLine(1, 6);

    return test;
}

Test twoElements3() {
    Test test;

    test.addLine(2);
    test.addLine(5, 3);
    test.addLine(6, 4);

    return test;
}

Test twoElements4() {
    Test test;

    test.addLine(2);
    test.addLine(MIN_VALUE, MAX_VALUE);
    test.addLine(MAX_VALUE - 1, MIN_VALUE + 1);

    return test;
}

Test twoElements5() {
    Test test;

    test.addLine(2);
    test.addLine(MAX_VALUE - 1, MIN_VALUE + 1);
    test.addLine(MIN_VALUE, MAX_VALUE);

    return test;
}

Test small1() {
    Test test;

    test.addLine(5);
    test.addLine(-2, 0, 4, 3, 7);
    test.addLine(-1, 1, 2, 5, 4);

    return test;
}

Test small2() {
    Test test;

    test.addLine(9);
    test.addLine(0, 1, 2, 3, 4, 9, 10, 11, 12);
    test.addLine(4, 5, 6, 7, 8, 6, 8, 12, 13);

    return test;
}

Test small3() {
    Test test;

    test.addLine(5);
    test.addLine(1, 5, 14, 9, 13);
    test.addLine(-5, 12, 8, 18, 20);

    return test;
}


Test small4() {
    Test test;

    test.addLine(8);
    test.addLine(-12, -12, -7, -6, -9, -5, -3, -3);
    test.addLine(-14, -8, -11, -10, -5, -4, -4, -2);

    return test;
}

Test testFromVectors(pair<vector<int>, vector<int> > p) {
    Test test;

    assert(p.first.size() == p.second.size());
    test.addLine(p.first.size());
    test.addLine(p.first);
    test.addLine(p.second);

    return test;
}

Test largeAnswer1(int n, int minValue, int delta1, int delta2) {
    assert(delta1 >= delta2);
    vector<int> A(n), B(n);
    A[0] = minValue;
    B[0] = A[0] + delta1;
    for (int i = 1; i < n; i++) {
        A[i] = A[i - 1] + delta2;
        B[i] = B[i - 1] + delta2;
    }

    for (int i = 1; i < n; i += 2) {
        swap(A[i], B[i]);
    }

    return testFromVectors({A, B});
}

Test largeAnswer2(int n, int minValue, int delta) {
    vector<int> A(n), B(n);
    A[0] = minValue;
    for (int i = 1; i < n; i++) {
        A[i] = A[i - 1] + delta;
    }
    B[0] = A.back() + delta;
    for (int i = 1; i < n; i++) {
        B[i] = B[i - 1] + delta;
    }
    for (int i = n / 2 + 1; i < n; i++) {
        swap(A[i], B[i]);
    }
    return testFromVectors({A, B});
}

vector<int> randomSequence(int n, int minValue, int maxValue) {
    vector<int> ret;
    for (int i = 0; i < n; i++) {
        ret.push_back(random(minValue, maxValue));
    }
    sort(ret.begin(), ret.end());
    for (int i = 1; i < n; i++) {
        if (ret[i] <= ret[i - 1]) {
            ret[i] = ret[i - 1] + 1;
        }
    }
    return ret;
}

pair<vector<int>, vector<int> > seqsWithSolution(int n, int k, int minValue, int maxValue) {
    vector<int> A = randomSequence(n, minValue, maxValue);
    vector<int> B = randomSequence(n, minValue, maxValue);
    for (int i = 0; i < k; i++) {
        int pos = random(0, n - 1);
        swap(A[pos], B[pos]);
    }
    return make_pair(A, B);
}

Test randomTest(int n, int k, int minValue, int maxValue) {
    return testFromVectors(seqsWithSolution(n, k, minValue, maxValue));
}

Test antiWrongTest(int n, int k, int minValue, int maxValue) {
    pair<vector<int>, vector<int> > p;
    do {
        p = seqsWithSolution(n, k, minValue, maxValue);
//         for (int i = 0; i < p.first.size(); i++) {
//             cerr << p.first[i] << " ";
//         }
//         cerr << endl;
//         for (int i = 0; i < p.second.size(); i++) {
//             cerr << p.second[i] << " ";
//         }
//         cerr << endl << getWrongAnswer(p.first, p.second) << " " << getAnswer(p.first, p.second) << endl;
    } while (getWrongAnswer(p.first, p.second) == getAnswer(p.first, p.second));

    return testFromVectors(p);
}

Test cornerLarge1(int n) {
    vector<int> A(n), B(n);
    for (int i = 0; i < n; i++) {
        A[i] = random(0, 1) == 0 ? MIN_VALUE : MAX_VALUE;
        B[i] = random(0, 1) == 0 ? MIN_VALUE : MAX_VALUE;
    }
    return testFromVectors({A, B});
}

Test cornerLarge2(int n) {
    vector<int> A(n), B(n);
    for (int i = 0; i < n; i++) {
        A[i] = B[i] = 0;
    }
    return testFromVectors({A, B});
}

Test cornerLarge3(int n) {
    vector<int> A(n), B(n);
    for (int i = 0; i < n; i++) {
        A[i] = B[i] = i;
    }
    return testFromVectors({A, B});
}


Test totalRandom(int n, int minValue, int maxValue) {
    vector<int> A(n), B(n);
    for (int i = 0; i < n; i++) {
        A[i] = random(minValue, maxValue);
        B[i] = random(minValue, maxValue);
    }
    return testFromVectors({A, B});
}

int random(int a, int b) {
    return Generator::random() % (b - a + 1) + a;
}



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

int getWrongAnswer(vector<int> A, vector<int> B) {
    return min(min(wrong1(A, B), wrong2(A, B)), wrong3(A, B));
}

int getAnswer(vector<int> A, vector<int> B) {
    int n = A.size();
    int dp[n], dp_swap[n];

    for (int i = 0; i < n; i++) {
        dp[i] = dp_swap[i] = 1e9;
    }
    dp[0] = 0;
    dp_swap[0] = 1;

    for (int i = 1; i < n; i++) {
        if (A[i] > A[i - 1] && B[i] > B[i - 1]) {
            dp[i] = min(dp[i], dp[i - 1]);
            dp_swap[i] = min(dp_swap[i], dp_swap[i - 1] + 1);
        }
        if (A[i] > B[i - 1] && B[i] > A[i - 1]) {
            dp[i] = min(dp[i], dp_swap[i - 1]);
            dp_swap[i] = min(dp_swap[i], dp[i - 1] + 1);
        }
    }

    int answer = min(dp[n - 1], dp_swap[n - 1]);

    if (answer >= 1e9) {
        return -1;
    } else {
        return answer;
    }
}
