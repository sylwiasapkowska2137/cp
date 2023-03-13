#include <bits/stdc++.h>

using namespace std;

int random(int a, int b) { return rand() % (b - a + 1) + a; }

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

int main(int argc, char *argv[]) {
    srand(time(0) * atoi(argv[1]));

    int n = random(1, 50);
    int maxLen = 3000;
    int maxValue = 1000000;
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

    printf("%d %d %d %d %d\n", n, p.x, p.y, q.x, q.y);

    for (int i = 0; i < rects.size(); i++) {
        Rect r = rects[i];
        printf("%d %d %d %d\n", r.lx, r.ly, r.rx, r.ry);
    }
}