#include "generator.h"

#include <memory>

template <class F, class S>
std::ostream &operator<<(std::ostream &os, const std::pair<F, S> &pair) {
    os << pair.first << " " << pair.second;
    return os;
}

using graph_t = std::vector<std::pair<int, int>>;

Test exampleTest();
Test cornerCase1();
Test cornerCase2();
Test randomTest(int n, int maxValue, int maxLen);

Test small1() {
    Test test;
    test.addLine(2, -6, 10, -5, -10);
    test.addLine(-5, 0, -3, 1);
    test.addLine(-7, -2, -4, -1);
    return test;
}

Test small2() {
    Test test;
    test.addLine(1, 5, 6, 7, 8);
    test.addLine(-4, -3, -3, -2);
    return test;
}

Test small3() {
    Test test;
    test.addLine(4, 8, 3, 8, 3);
    test.addLine(2, -2, 5, 0);
    test.addLine(2, -7, 3, -4);
    test.addLine(-6, -4, -3, -2);
    test.addLine(-8, 5, -6, 8);
    return test;
}

Test small4() {
    Test test;
    test.addLine(3, -10, -6, -2, -2);
    test.addLine(-6, -8, -5, -5);
    test.addLine(-6, -4, -4, -3);
    test.addLine(-8, 1, -7, 2);
    return test;
}

Test small5() {
    Test test;
    test.addLine(5, -9, 7, 10, 3);
    test.addLine(3, 3, 5, 6);
    test.addLine(-9, 2, -7, 3);
    test.addLine(-10, 4, -7, 6);
    test.addLine(5, 2, 6, 3);
    test.addLine(3, 7, 4, 9);
    return test;
}

int main() {
    Generator gen("osi");

    gen.beginGroup();
    gen.addTest(exampleTest());
    gen.endGroup();

    //1
    gen.beginGroup();
    {
        gen.addTest(cornerCase1());
        gen.addTest(cornerCase2());
        gen.addTest(small1());
        gen.addTest(small2());
    }
    gen.endGroup();

    //2
    gen.beginGroup();
    {
        Generator::setSeed(2001000);
        gen.addTest(randomTest(5, 10, 3));
        Generator::setSeed(2001001);
        gen.addTest(randomTest(20, 50, 10));
        Generator::setSeed(2002002);
        gen.addTest(randomTest(20, 50, 30));
        gen.addTest(small3());
//         gen.addTest(small4());
//         gen.addTest(small5());
    }
    gen.endGroup();

    //3
    gen.beginGroup();
    {
        Generator::setSeed(3001001);
        gen.addTest(randomTest(100, 1000, 10));
        Generator::setSeed(3002002);
        gen.addTest(randomTest(100, 1000, 300));
    }
    gen.endGroup();

    //4
    gen.beginGroup();
    {
        Generator::setSeed(4001001);
        gen.addTest(randomTest(300, 100000, 10000));
        Generator::setSeed(4002002);
        gen.addTest(randomTest(300, 100000, 10000));
    }
    gen.endGroup();

    //5
    gen.beginGroup();
    {
        Generator::setSeed(5001001);
        gen.addTest(randomTest(400, 1000000, 30000));
        Generator::setSeed(5002002);
        gen.addTest(randomTest(400, 1000000, 50000));
    }
    gen.endGroup();

    //6
    gen.beginGroup();
    {
        Generator::setSeed(6001003);
        gen.addTest(randomTest(400, 1000000, 200000));
        Generator::setSeed(6002002);
        gen.addTest(randomTest(400, 1000000, 1531));
    }
    gen.endGroup();

    gen.generate();
}

using namespace std;

int random(int a, int b);

Test exampleTest() {
    Test test;
    test.addLine(2, 1, 3, 8, 3);
    test.addLine(2, 1, 4, 4);
    test.addLine(5, 3, 7, 5);
    return test;
}

Test cornerCase1() {
    Test test;
    test.addLine(1, -1, 0, 1, 0);
    test.addLine(5, 5, 6, 6);
    return test;
}

Test cornerCase2() {
    Test test;
    test.addLine(4, 0, 0, 10, 10);
    test.addLine(1, -1, 2, 2);
    test.addLine(-2, -2, 3, -1);
    test.addLine(-3, -3, -3, 2);
    test.addLine(-4, 2, 3, 3);
    return test;
}

struct Rect {
    int lx;
    int ly;
    int rx;
    int ry;
    Rect() {
        lx = ly = rx = ry = 0;
    }
    Rect(int _lx, int _ly, int _rx, int _ry) {
        lx = _lx;
        ly = _ly;
        rx = _rx;
        ry = _ry;
    }
};

struct Point {
    int x, y;
    Point() {
        x = y = 0;
    }
    Point(int _x, int _y) {
        x = _x;
        y = _y;
    }
};

Point randomPoint(int maxValue) {
    return Point(random(-maxValue, maxValue), random(-maxValue, maxValue));
}

bool containsPoint(Rect a, Point p) {
    return a.lx <= p.x && p.x <= a.rx && a.ly <= p.y && p.y <= a.ry;
}

bool rectContainsPoint(const vector<Rect> &rects, Point p) {
    for (int i = 0; i < rects.size(); i++) {
        if (containsPoint(rects[i], p)) {
            return true;
        }
    }
    return false;
}

bool contains(Rect a, Rect b) {
    return b.lx >= a.lx && b.rx <= a.rx && b.ly >= a.ly && b.ry <= a.ry;
}

bool intervalIntersect(int a, int b, int c, int d) {
    return !(b <= c || d <= a);
}

bool intersect(Rect a, Rect b) {
    return intervalIntersect(a.lx, a.rx, b.lx, b.rx) && intervalIntersect(a.ly, a.ry, b.ly, b.ry);
}

bool coIncide(Rect a, Rect b) {
    return contains(a, b) || contains(b, a) || intersect(a, b);
}

Rect randomRect(int maxValue, int maxLen) {
    int rx = random(-maxValue + maxLen, maxValue);
    int ry = random(-maxValue + maxLen, maxValue);
    int lx = rx - random(1, maxLen);
    int ly = ry - random(1, maxLen);
    return Rect(lx, ly, rx, ry);
}

bool coincides(Rect rect, const vector<Rect> &rects) {
    for (int i = 0; i < rects.size(); i++) {
        if (coIncide(rect, rects[i])) {
            return true;
        }
    }
    return false;
}

Test randomTest(int n, int maxValue, int maxLen) {
    vector<Rect> rects;
    for (int i = 0; i < n; i++) {
        Rect rect;
        do {
            rect = randomRect(maxValue, maxLen);
        } while (coincides(rect, rects));
        rects.push_back(rect);
    }
    Point p;
    do {
        p = randomPoint(maxValue);
    } while (rectContainsPoint(rects, p));
    Point q;
    do {
        q = randomPoint(maxValue);
    } while (rectContainsPoint(rects, q));

    Test test;
    test.addLine(n, p.x, p.y, q.x, q.y);
    for (int i = 0; i < rects.size(); i++) {
        test.addLine(rects[i].lx, rects[i].ly, rects[i].rx, rects[i].ry);
    }
    return test;
}

int random(int a, int b) {
    return Generator::random() % (b - a + 1) + a;
}
