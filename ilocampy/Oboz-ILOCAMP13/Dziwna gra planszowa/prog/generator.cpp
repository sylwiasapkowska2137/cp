#include "generator.h"

#include <memory>

template <class F, class S>
std::ostream &operator<<(std::ostream &os, const std::pair<F, S> &pair) {
    os << pair.first << " " << pair.second;
    return os;
}

using graph_t = std::vector<std::pair<int, int>>;

const int MIN_N = 3;
const int MAX_N = 1000 * 1000 * 1000;
const int MAX_T = 500000;

Test exampleTest();

Test cornerCases();
Test small();
Test firstCase(int tests, int minLength, int maxLength);
Test secondCase(int tests, int minLength, int maxLength);
Test bothCases(int tests, int minLength, int maxLength);

int main() {
    Generator gen("dgp");

    gen.beginGroup();
    gen.addTest(exampleTest());
    gen.endGroup();

    //1
    gen.beginGroup();
    {
        gen.addTest(cornerCases());
    }
    gen.endGroup();

    //2
    gen.beginGroup();
    {
        gen.addTest(small());
    }
    gen.endGroup();

    //Complexity O(t*n*m) passes
    //3
    gen.beginGroup();
    {
        int tests = 300;
        int minLength = MIN_N;
        int maxLength = 300;

        Generator::setSeed(13314242);
        gen.addTest(firstCase(tests, minLength, maxLength));
    }
    gen.endGroup();

    //4
    gen.beginGroup();
    {
        int tests = 300;
        int minLength = MIN_N;
        int maxLength = 300;

        Generator::setSeed(444);
        gen.addTest(secondCase(tests, minLength, maxLength));
    }
    gen.endGroup();

    //5
    gen.beginGroup();
    {
        int tests = 300;
        int minLength = MIN_N;
        int maxLength = 300;

        Generator::setSeed(50505);
        gen.addTest(bothCases(tests, minLength, maxLength));
    }
    gen.endGroup();

    //Complexity O(t*max(n, m)) passes
    //6
    gen.beginGroup();
    {
        int tests = 10;
        int minLength = MIN_N;
        int maxLength = 1000000;

        Generator::setSeed(60606);
        gen.addTest(firstCase(tests, minLength, maxLength));
    }
    gen.endGroup();

    //7
    gen.beginGroup();
    {
        int tests = 10;
        int minLength = MIN_N;
        int maxLength = 1000000;

        Generator::setSeed(7070707);
        gen.addTest(secondCase(tests, minLength, maxLength));
    }
    gen.endGroup();

    //8
    gen.beginGroup();
    {
        int tests = 10;
        int minLength = MIN_N;
        int maxLength = 1000000;

        Generator::setSeed(80808);
        gen.addTest(bothCases(tests, minLength, maxLength));
    }
    gen.endGroup();

    //Complexity O(t) passes
    //9
    gen.beginGroup();
    {
        int tests = MAX_T;
        int minLength = MIN_N;
        int maxLength = MAX_N;

        Generator::setSeed(9090909);
        gen.addTest(firstCase(tests, minLength, maxLength));
    }
    gen.endGroup();

    //10
    gen.beginGroup();
    {
        int tests = MAX_T;
        int minLength = MIN_N;
        int maxLength = MAX_N;

        Generator::setSeed(100100100);
        gen.addTest(secondCase(tests, minLength, maxLength));
    }
    gen.endGroup();

    //11
    gen.beginGroup();
    {
        int tests = MAX_T;
        int minLength = MIN_N;
        int maxLength = MAX_N;

        Generator::setSeed(110110110);
        gen.addTest(bothCases(tests, minLength, maxLength));
    }
    gen.endGroup();

    gen.generate();
}

using namespace std;

int random(int a, int b);

Test exampleTest() {
    Test test;
    test.addLine(2);
    test.addLine(5, 8, 2, 4, 4, 7);
    test.addLine(5, 4, 2, 2, 2, 4);
    return test;
}

Test cornerCases() {
    Test test;
    test.addLine(6);
    test.addLine(3, 3, 2, 1, 2, 3);
    test.addLine(3, 3, 1, 1, 2, 3);
    test.addLine(3, 3, 2, 2, 3, 1);
    test.addLine(3, 3, 3, 2, 1, 3);
    test.addLine(3, 3, 3, 3, 1, 3);
    test.addLine(3, 3, 3, 3, 1, 2);
    return test;
}

Test small() {
    Test test;
    test.addLine(10);
    test.addLine(4, 7, 1, 3, 4, 5);
    test.addLine(4, 7, 1, 3, 3, 5);
    test.addLine(4, 7, 1, 3, 2, 7);
    test.addLine(7, 6, 2, 4, 3, 1);
    test.addLine(7, 6, 4, 4, 5, 1);
    test.addLine(20, 20, 8, 4, 8, 17);
    test.addLine(20, 20, 8, 4, 8, 16);
    test.addLine(20, 20, 14, 9, 11, 18);
    test.addLine(20, 20, 8, 4, 10, 18);
    test.addLine(20, 20, 8, 4, 8, 17);
    return test;
}

vector<int> packToVector(int n, int m, int rp, int cp, int rj, int cj) {
    vector<int> ret;
    ret.push_back(n);
    ret.push_back(m);
    ret.push_back(rp);
    ret.push_back(cp);
    ret.push_back(rj);
    ret.push_back(cj);
    return ret;
}

bool tooClose(int rp, int cp, int rj, int cj) {
    return abs(rp - rj) + abs(cp - cj) < 2;
}

vector<int> testCaseFirstCase(int n, int m) {
    int rp, cp, rj, cj;

    do {
        rp = random(1, n);
        cp = random(1, m);
        rj = random(1, n);
        cj = random(1, m);
    } while (tooClose(rp, cp, rj, cj) || (abs(rj - rp) + abs(cj - cp)) % 2 == 1);

    return packToVector(n, m, rp, cp, rj, cj);
}

vector<int> testCaseSecondCase(int n, int m) {
    int rp, cp, rj, cj;

    do {
        rp = random(1, n);
        cp = random(1, m);
        rj = random(1, n);
        cj = random(1, m);
    } while (tooClose(rp, cp, rj, cj) || cj - cp < abs(rj - rp));

    return packToVector(n, m, rp, cp, rj, cj);
}

vector<int> testCaseBothCases(int n, int m) {
    int rp, cp, rj, cj;

    do {
        rp = random(1, n);
        cp = random(1, m);
        rj = random(1, n);
        cj = random(1, m);
    } while(tooClose(rp, cp, rj, cj));

    return packToVector(n, m, rp, cp, rj, cj);
}

Test firstCase(int t, int minLength, int maxLength) {
    Test test;

    test.addLine(t);
    for (int i = 1; i <= t; i++) {
        int n = random(minLength, maxLength);
        int m = random(minLength, maxLength);
        test.addLine(testCaseFirstCase(n, m));
    }

    return test;
}

Test secondCase(int t, int minLength, int maxLength) {
    Test test;

    test.addLine(t);
    for (int i = 1; i <= t; i++) {
        int n = random(minLength, maxLength);
        int m = random(minLength, maxLength);
        test.addLine(testCaseSecondCase(n, m));
    }

    return test;
}

Test bothCases(int t, int minLength, int maxLength) {
    Test test;

    test.addLine(t);
    for (int i = 1; i <= t; i++) {
        int n = random(minLength, maxLength);
        int m = random(minLength, maxLength);
        test.addLine(testCaseBothCases(n, m));
    }

    return test;
}

int random(int a, int b) {
    return Generator::random() % (b - a + 1) + a;
}
