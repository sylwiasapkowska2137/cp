#include "generator.h"

#include <memory>

template <class F, class S>
std::ostream &operator<<(std::ostream &os, const std::pair<F, S> &pair) {
    os << pair.first << " " << pair.second;
    return os;
}

using graph_t = std::vector<std::pair<int, int>>;

const int MAX_VALUE = 1000 * 1000 * 1000;

Test exampleTest();

Test cornerCase1();
Test cornerCase2();
Test cornerCase3();
Test small1();
Test small2();
Test small3();
Test small4();
Test randomTest(int n, int k, int maxValue);
Test randomWithLines(int n, int k, int maxValue, int maxA, int maxB);
Test randomOneBadPoint(int n, int k, int maxValue, int maxA, int maxB);
Test equalPointsOnLines(int n, int k, int maxValue, int maxA, int maxB);
Test dominatingLine(int n, int k, int maxValue, int maxA, int maxB, int prob);
Test lessLinesThanNeeded(int n, int k, int maxValue, int maxA, int maxB);
Test moreLinesThanNeeded(int n, int k, int maxValue, int maxA, int maxB);
using namespace std;
int main() {
    Generator gen("pro");

    gen.beginGroup();
    gen.addTest(exampleTest());
    gen.endGroup();

    //1
    gen.beginGroup();
    {
        cerr << "Group 1\n";
        gen.addTest(cornerCase1());
        gen.addTest(cornerCase2());
        gen.addTest(cornerCase3());
        gen.addTest(small1());
        gen.addTest(small2());
    }
    gen.endGroup();

    //2
    gen.beginGroup();
    {
        cerr << "Group 2\n";
        cerr << "Test 2a\n";
        gen.addTest(small3());
        cerr << "Test 2b\n";
        Generator::setSeed(2001001);
        gen.addTest(randomTest(10, 3, 20));
        cerr << "Test 2c\n";
        Generator::setSeed(2002002);
        gen.addTest(randomWithLines(100, 4, 1000, 20, 20));
        cerr << "Test 2d\n";
        Generator::setSeed(2003003);
        gen.addTest(moreLinesThanNeeded(100, 2, 1000, 20, 20));
        cerr << "Test 2e\n";
        Generator::setSeed(2004004);
        gen.addTest(randomTest(25, 5, 5));
        cerr << "Test 2f\n";
        Generator::setSeed(2005005);
        gen.addTest(randomWithLines(25, 5, 5, 1, 5));
        cerr << "Test 2g\n";
        Generator::setSeed(2006006);
        gen.addTest(equalPointsOnLines(25, 5, 5, 1, 5));
        cerr << "Test 2h\n";
        gen.addTest(small4());
    }
    gen.endGroup();

    //3
    gen.beginGroup();
    {
        cerr << "Group 3\n";
        Generator::setSeed(3001001);
        gen.addTest(randomWithLines(1000, 5, MAX_VALUE, 100000, 315));
        cerr << "Group 3a\n";
        Generator::setSeed(3002002);
        gen.addTest(randomWithLines(1000, 5, MAX_VALUE, 31351, 513));
        cerr << "Group 3b\n";
        Generator::setSeed(3003003);
        gen.addTest(randomOneBadPoint(1000, 4, MAX_VALUE, 100000, 500));
        cerr << "Group 3c\n";
        Generator::setSeed(3004004);
        gen.addTest(dominatingLine(1000, 5, MAX_VALUE, 1000, 50, 50));
        cerr << "Group 3d\n";
        Generator::setSeed(3005005);
        gen.addTest(randomWithLines(25, 5, 30, 1, 5));
        cerr << "Group 3e\n";
        Generator::setSeed(3006006);
        gen.addTest(randomWithLines(25, 5, 30, 3, 10));
        cerr << "Group 3f\n";
        Generator::setSeed(3007007);
        gen.addTest(randomWithLines(25, 5, 30, 5, 15));
    }
    gen.endGroup();

    //4
    gen.beginGroup();
    {
        cerr << "Group 4\n";
        Generator::setSeed(4001001);
        gen.addTest(randomTest(20000, 5, 10));
        Generator::setSeed(4002002);
        gen.addTest(randomWithLines(20000, 3, MAX_VALUE, 100000, 1000000));
        Generator::setSeed(4003003);
        gen.addTest(dominatingLine(20000, 5, MAX_VALUE, 1000, 1000000, 1000));
        Generator::setSeed(4004004);
        gen.addTest(randomOneBadPoint(25, 5, 100, 5, 30));
        Generator::setSeed(4005005);
        gen.addTest(lessLinesThanNeeded(25, 6, 100, 5, 30));
    }
    gen.endGroup();

    //5
    gen.beginGroup();
    {
        cerr << "Group 5\n";
        int n = 100000;
        Generator::setSeed(5001001);
        gen.addTest(randomWithLines(n, 3, MAX_VALUE, 1000351, 10531000));
        Generator::setSeed(5002002);
        cerr << "Test 5b\n";
        gen.addTest(equalPointsOnLines(n, 5, MAX_VALUE, 10, 100));
        Generator::setSeed(5003003);
        cerr << "Test 5c\n";
        gen.addTest(randomOneBadPoint(n, 5, MAX_VALUE, 5531515, 315151));
        Generator::setSeed(5004004);
        cerr << "Test 5d\n";
        gen.addTest(randomWithLines(25, 5, 100, 10, 50));
    }
    gen.endGroup();

    //6
    gen.beginGroup();
    {
        cerr << "Group 6\n";
        int n = 200000;
        Generator::setSeed(6001001);
        gen.addTest(randomTest(n, 5, MAX_VALUE));
        Generator::setSeed(6002002);
        gen.addTest(randomWithLines(n, 5, MAX_VALUE, 5000, 10000000));
        Generator::setSeed(6003003);
        gen.addTest(randomWithLines(n, 5, MAX_VALUE, 100, 50));
        Generator::setSeed(6004004);
        gen.addTest(randomTest(25, 5, 30));
    }
    gen.endGroup();

    //7
    gen.beginGroup();
    {
        cerr << "Group 7\n";
        int n = 200000;
        Generator::setSeed(7001001);
        gen.addTest(randomTest(n, 5, MAX_VALUE));
        Generator::setSeed(7002002);
        gen.addTest(moreLinesThanNeeded(n, 3, MAX_VALUE, 1000, 500000));
        Generator::setSeed(7003003);
        gen.addTest(randomWithLines(n, 5, MAX_VALUE, 1, 3));
        Generator::setSeed(7004004);
        gen.addTest(equalPointsOnLines(n, 5, MAX_VALUE, 3000, 2000));
        Generator::setSeed(7005005);
        gen.addTest(dominatingLine(n, 5, MAX_VALUE, 353151, 3053135, 1000));
    }
    gen.endGroup();

    gen.generate();
}

using namespace std;

int random(int a, int b);

Test exampleTest() {
    Test test;
    test.addLine(3, 2);
    test.addLine(1, 0);
    test.addLine(0, 0);
    test.addLine(0, 1);
    return test;
}

Test cornerCase1() {
    Test test;
    test.addLine(1, 1);
    test.addLine(10, 20);
    return test;
}

Test cornerCase2() {
    Test test;
    test.addLine(2, 2);
    test.addLine(-1, 2);
    test.addLine(2, 3);
    return test;
}

Test cornerCase3() {
    Test test;
    test.addLine(3, 1);
    test.addLine(0, 1);
    test.addLine(-1, 5);
    test.addLine(13, 5);
    return test;
}

Test small1() {
    Test test;
    test.addLine(10, 3);
    test.addLine(1, 2);
    test.addLine(4, 2);
    test.addLine(5, 2);
    test.addLine(1, 4);
    test.addLine(-2, 5);
    test.addLine(0, -3);
    test.addLine(1, -2);
    test.addLine(3, 0);
    test.addLine(5, -2);
    test.addLine(2, -1);
    return test;
}

Test small2() {
    Test test;
    test.addLine(10, 3);
    test.addLine(1, -2);
    test.addLine(1, 0);
    test.addLine(2, 1);
    test.addLine(0, 1);
    test.addLine(-1, 2);
    test.addLine(1, 2);
    test.addLine(-1, 4);
    test.addLine(3, -2);
    test.addLine(1, 3);
    test.addLine(1, 5);
    return test;
}

Test small3() {
    Test test;

    test.addLine(25, 5);
    for (int i = 1; i <= 5; i++) {
        for (int j = 1; j <= 5; j++) {
            test.addLine(i, j);
        }
    }

    return test;
}

Test small4() {
    Test test;
    test.addLine(2, 1);
    test.addLine(MAX_VALUE - 1, MAX_VALUE);
    test.addLine(-MAX_VALUE + 1, -MAX_VALUE);
    return test;
}

Test randomTest(int n, int k, int maxValue) {
    Test test;

    test.addLine(n, k);
    for (int i = 1; i <= n; i++) {
        test.addLine(random(-maxValue, maxValue), random(-maxValue, maxValue));
    }
    return test;
}

int NWD(int a, int b) {
    return b ? NWD(b, a % b) : a;
}

struct Line {
    int px;
    int py;
    int dx;
    int dy;
    Line(int _px, int _py, int _dx, int _dy) {
        px = _px;
        py = _py;
        dx = _dx;
        dy = _dy;
    }
    void wypisz() {
//         cerr << px << " " << py << " " << dx << " " << dy << endl;
    }
};

vector<Line> getRandomLines(int k, int maxValue) {
    vector<Line> lines;
    for (int i = 1; i <= k; i++) {
        int xA = random(-maxValue, maxValue);
        int yA = random(-maxValue, maxValue);
        int xB = random(-maxValue, maxValue);
        int yB = random(-maxValue, maxValue);
//         cerr << xA << " " << yA << " " << xB << " " << yB << endl;
        xB -= xA;
        yB -= yA;
        int nwd = NWD(xB, yB);
        xB /= nwd;
        yB /= nwd;

        lines.push_back(Line(xB, yB, xA, yA));
        lines.back().wypisz();
    }
    return lines;
}

pair<int, int> randomPointOnLine(Line line, int maxValue) {

    long long x, y;
    int maxK = (maxValue - line.dx) / line.px;
    int minK = (-maxValue - line.dx) / line.px;
//     cerr << minK << " " << maxK << endl;
    if (minK > maxK) {
        swap(minK, maxK);
    }
    do {
        int k = random(minK, maxK);
//         line.wypisz();
        x = (long long)k * line.px + line.dx;
        y = (long long)k * line.py + line.dy;
//         cerr << x << " " << y << " " << maxValue << endl;
    } while (abs(x) > maxValue || abs(y) > maxValue);
    return {x, y};
//     int maxX, minX;
//     if (line.first == 0) {
//         minX = -maxValue, maxX = maxValue;
//     } else {
//         maxX = (maxValue - line.second) / line.first;
//         minX = (-maxValue - line.second) / line.first;
//     }
//
//     if (minX > maxX) {
//         swap(minX, maxX);
//     }
//     long long x, y;
//     do {
//         x = random(minX, maxX);
//         y = (long long)line.first * x + line.second;
// //         cerr << x << " " << y << ":(\n";
//     } while (abs(y) > maxValue);
//     return {x, y};
}

Test randomWithLines(int n, int k, int maxValue, int maxA, int maxB) {
    Test test;
    test.addLine(n, k);
    vector<Line> lines = getRandomLines(k, maxValue);
    for (int i = 1; i <= n; i++) {
        int line = random(0, lines.size() - 1);
        pair<int, int> p = randomPointOnLine(lines[line], maxValue);
        test.addLine(p.first, p.second);
    }

    return test;
}

Test randomOneBadPoint(int n, int k, int maxValue, int maxA, int maxB) {
    Test test;
    test.addLine(n, k);
    vector<Line> lines = getRandomLines(k, maxValue);
    for (int i = 1; i < n; i++) {
        int line = random(0, lines.size() - 1);
        pair<int, int> p = randomPointOnLine(lines[line], maxValue);
        test.addLine(p.first, p.second);
    }

    test.addLine(random(-maxValue, maxValue), random(-maxValue, maxValue));

    return test;
}

Test equalPointsOnLines(int n, int k, int maxValue, int maxA, int maxB) {
    assert(n % k == 0);
    Test test;
    test.addLine(n, k);
    vector<Line> lines = getRandomLines(k, maxValue);
    int pointsPerLine = n / k;
    vector<pair<int, int> > allPoints;
    for (int i = 0; i < k; i++) {
//         lines[i].wypisz();
        for (int j = 1; j <= pointsPerLine; j++) {
            allPoints.push_back(randomPointOnLine(lines[i], maxValue));
        }
    }
    random_shuffle(allPoints.begin(), allPoints.end());
    for (int i = 0; i < allPoints.size(); i++) {
        test.addLine(allPoints[i].first, allPoints[i].second);
    }
    return test;
}

Test dominatingLine(int n, int k, int maxValue, int maxA, int maxB, int prob) {
    Test test;
    test.addLine(n, k);
    vector<Line> lines = getRandomLines(k, maxValue);
    for (int i = 1; i <= n; i++) {
        int line = 0;
        if (random(0, prob) == 0) {
            line = random(1, lines.size() - 1);
        }
        pair<int, int> point = randomPointOnLine(lines[line], maxValue);
        test.addLine(point.first, point.second);
    }
    return test;
}

Test lessLinesThanNeeded(int n, int k, int maxValue, int maxA, int maxB) {
    Test test;
    test.addLine(n, k - 1);
    vector<Line> lines = getRandomLines(k, maxValue);
    for (int i = 1; i <= n; i++) {
        int line = random(0, lines.size() - 1);
        pair<int, int> p = randomPointOnLine(lines[line], maxValue);
        test.addLine(p.first, p.second);
    }
    return test;
}

Test moreLinesThanNeeded(int n, int k, int maxValue, int maxA, int maxB) {
    Test test;
    test.addLine(n, k + 1);
    vector<Line> lines = getRandomLines(k, maxValue);
    for (int i = 1; i <= n; i++) {
        int line = random(0, lines.size() - 1);
        pair<int, int> p = randomPointOnLine(lines[line], maxValue);
        test.addLine(p.first, p.second);
    }

    return test;
}

int random(int a, int b) {
    return Generator::random() % (b - a + 1) + a;
}
