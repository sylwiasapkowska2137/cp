#include <bits/stdc++.h>

using namespace std;

const int N = 705;
const double INF = 1e9, eps = 1e-9;

int n;
int xl[N], xr[N], yl[N], yr[N];
int xp, yp, xk, yk;
vector<pair<int, double > > V[4 * N + 5];
double dists[4 * N + 5];
bool vis[4 * N + 5];
priority_queue<pair<double, int> > Q;
int canBe[4 * N];
int current;
bool used[2 * N];

struct Point {
    long long x;
    long long y;
    int rectId;
    Point(int _x, int _y, int _rectId) {
        x = _x;
        y = _y;
        rectId = _rectId;
    }
    Point(int _x, int _y) {
        x = _x;
        y = _y;
        rectId = -1;
    }
};

vector<Point> points;

long long det(Point a, Point b, Point c) {
    return a.x * b.y + b.x * c.y + c.x * a.y - a.y * b.x - b.y * c.x - c.y * a.x;
}

double dist(const Point &a, const Point &b) {
    return sqrtl((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

int sign(long long x) {
    if (x > 0) return 1;
    if (x == 0) return 0;
    if (x < 0) return -1;
}

Point onDiag(Point p) {
    int id = p.rectId;
    if (p.x == xl[id] && p.y == yl[id]) {
        return Point(xr[id], yr[id]);
    }
    if (p.x == xl[id] && p.y == yr[id]) {
        return Point(xr[id], yl[id]);
    }
    if (p.x == xr[id] && p.y == yl[id]) {
        return Point(xl[id], yr[id]);
    }
    if (p.x == xr[id] && p.y == yr[id]) {
        return Point(xl[id], yl[id]);
    }
    assert(false);
}

bool intersects(Point a, Point b, Point c, Point d) {
    long long det1 = sign(det(a, b, c));
    long long det2 = sign(det(a, b, d));
    long long det3 = sign(det(c, d, a));
    long long det4 = sign(det(c, d, b));
    if (det1 == 0 || det2 == 0 || det3 == 0 || det4 == 0) {
        return false;
    }
    return (det1 == -det2 && det3 == -det4);
}

bool liesOn(Point a, Point c) {
    if (a.rectId < 0) {
        return false;
    }
    Point tmp = a;
    Point b = onDiag(a);
    swap(a.x, b.x);
    return intersects(a, b, tmp, c);
}

bool canConnect(Point a, Point b) {
    return !liesOn(a, b) && !liesOn(b, a);
}

bool intersect(Point a, Point b) {
    for (int i = 0; i < n; i++) {
        Point ld = Point(xl[i], yl[i]);
        Point pg = Point(xr[i], yr[i]);
        Point lg = Point(xl[i], yr[i]);
        Point pd = Point(xr[i], yl[i]);
        if (intersects(a, b, ld, lg) || intersects(a, b, lg, pg) ||
            intersects(a, b, pg, pd) || intersects(a, b, pd, ld)) {
            return true;
        }
    }
    return false;
}

bool cmpR(pair<int, pair<Point, int> > p1, pair<int, pair<Point, int> > p2) {
    Point a = p1.second.first;
    Point b = p2.second.first;
//     cerr << "Porownuje " << a.x << " " << a.y << " z " << b.x << " " << b.y << endl;
    if (a.x - points[current].x == 0 && b.x - points[current].x == 0) {
        if (a.y == b.y) {
//             cerr << (p1.first < p2.first) << endl;
            return p1.first < p2.first;
        }
//         cerr << (a.y < b.y) << endl;
        return a.y < b.y;
    }
    if (det(points[current], a, b) == 0) {
//         cerr << (p1.first < p2.first) << endl;
        return p1.first < p2.first;
    }
//     cerr << (det(points[current], a, b) > 0) << endl;
    return det(points[current], a, b) > 0;
}

bool cmpL(pair<int, pair<Point, int> > p1, pair<int, pair<Point, int> > p2) {
    Point a = p1.second.first;
    Point b = p2.second.first;
    if (a.x - points[current].x == 0 && b.x - points[current].x == 0) {
        if (a.y == b.y) {
            return p1.first < p2.first;
        }
        return a.y > b.y;
    }
    if (det(points[current], a, b) == 0) {
        return p1.first < p2.first;
    }
    return det(points[current], a, b) > 0;
}

bool cmpU(pair<int, pair<Point, int> > p1, pair<int, pair<Point, int> > p2) {
    Point a = p1.second.first;
    Point b = p2.second.first;
    if (a.y - points[current].y == 0 && b.y - points[current].y == 0) {
        if (a.x == b.x) {
            return p1.first < p2.first;
        }
        return a.x > b.x;
    }
    if (det(points[current], a, b) == 0) {
        return p1.first < p2.first;
    }
    return det(points[current], a, b) > 0;
}

bool cmpD(pair<int, pair<Point, int> > p1, pair<int, pair<Point, int> > p2) {
    Point a = p1.second.first;
    Point b = p2.second.first;
    if (a.y - points[current].y == 0 && b.y - points[current].y == 0) {
        if (a.x == b.x) {
            return p1.first < p2.first;
        }
        return a.x < b.x;
    }
    if (det(points[current], a, b) == 0) {
        return p1.first < p2.first;
    }
    return det(points[current], a, b) > 0;
}

bool eq(Point a, Point b) {
    return a.x == b.x && a.y == b.y;
}

void connectPointsWith(int w) {
    current = w;
    for (int i = 0; i < points.size(); i++) {
        canBe[i] = 0;
    }
    //Right half
    bool bad = false;
    bool onlyUpperHalf = false;
    bool onlyLowerHalf = false;
    vector<pair<int, pair<Point, int> > > events;
    for (int i = 0; i < n; i++) {
        if (xl[i] == points[w].x) {
            if (yl[i] < points[w].y && yr[i] > points[w].y) {
                bad = true;
                break;
            }
            if (yl[i] < points[w].y && yr[i] == points[w].y) {
                onlyUpperHalf = true;
            }
            if (yl[i] == points[w].y && yr[i] > points[w].y) {
                onlyLowerHalf = true;
            }
        }
        if (xl[i] > points[w].x) {
            events.push_back({2, {Point(xl[i], yl[i]), 2 * i}});
            events.push_back({0, {Point(xl[i], yr[i]), 2 * i}});
        }
        if (xr[i] > points[w].x) {
            events.push_back({2, {Point(xr[i], yl[i]), 2 * i + 1}});
            events.push_back({0, {Point(xr[i], yr[i]), 2 * i + 1}});
        }
//         if (yr[i] < points[w].y) {
//
//         }
    }
    for (int i = 0; i < points.size(); i++) {
        if ((points[i].x == points[w].x ||
            (points[i].x >= points[w].x && (!onlyUpperHalf || points[i].y >= points[w].y) &&
            (!onlyLowerHalf || points[i].y <= points[w].y) && !bad)) && !eq(points[i], points[w])) {
            events.push_back({1, {points[i], i}});
        }
    }
    sort(events.begin(), events.end(), cmpR);
    for (int i = 0; i < 2 * n; i++) {
        used[i] = false;
    }
    priority_queue<pair<int, int> > Q;
    for (int i = 0; i < events.size(); i++) {
        int type = events[i].first;
        Point p = events[i].second.first;
        int id = events[i].second.second;
        if (type == 2) {
            Q.push({-p.x, id});
            used[id] = true;
        } else if (type == 1) {
            while (!Q.empty() && !used[Q.top().second]) {
                Q.pop();
            }
            if (Q.empty() || -Q.top().first >= p.x) {
                canBe[id]++;
            }
        } else {
            used[id] = false;
        }
    }
    //Left half
    bad = false;
    onlyUpperHalf = false;
    onlyLowerHalf = false;
    events.clear();

    for (int i = 0; i < n; i++) {
        if (xr[i] == points[w].x) {
            if (yl[i] < points[w].y && yr[i] > points[w].y) {
                bad = true;
                break;
            }
            if (yl[i] < points[w].y && yr[i] == points[w].y) {
                onlyUpperHalf = true;
            }
            if (yl[i] == points[w].y && yr[i] > points[w].y) {
                onlyLowerHalf = true;
            }
        }
        if (xl[i] < points[w].x) {
            events.push_back({0, {Point(xl[i], yl[i]), 2 * i}});
            events.push_back({2, {Point(xl[i], yr[i]), 2 * i}});
        }
        if (xr[i] < points[w].x) {
            events.push_back({0, {Point(xr[i], yl[i]), 2 * i + 1}});
            events.push_back({2, {Point(xr[i], yr[i]), 2 * i + 1}});
        }
    }
    for (int i = 0; i < points.size(); i++) {
        if ((false ||
            (points[i].x < points[w].x && (!onlyUpperHalf || points[i].y >= points[w].y) &&
            (!onlyLowerHalf || points[i].y <= points[w].y) && !bad)) && !eq(points[i], points[w])) {
            events.push_back({1, {points[i], i}});
        }
    }
    sort(events.begin(), events.end(), cmpL);
    for (int i = 0; i < 2 * n; i++) {
        used[i] = false;
    }
    while (!Q.empty()) { Q.pop(); }
    for (int i = 0; i < events.size(); i++) {
        int type = events[i].first;
        Point p = events[i].second.first;
        int id = events[i].second.second;
        if (type == 2) {
            Q.push({p.x, id});
            used[id] = true;
        } else if (type == 1) {
            while (!Q.empty() && !used[Q.top().second]) {
                Q.pop();
            }
            if (Q.empty() || Q.top().first <= p.x) {
                canBe[id]++;
            }
        } else {
            used[id] = false;
        }
    }
    //Upper half
    bad = false;
    onlyUpperHalf = false;
    onlyLowerHalf = false;
    events.clear();

    for (int i = 0; i < n; i++) {
        if (yl[i] == points[w].y) {
            if (xl[i] < points[w].x && xr[i] > points[w].x) {
                bad = true;
                break;
            }
            if (xl[i] < points[w].x && xr[i] == points[w].x) {
                onlyUpperHalf = true;
            }
            if (xl[i] == points[w].x && xr[i] > points[w].x) {
                onlyLowerHalf = true;
            }
        }
        if (yl[i] > points[w].y) {
            events.push_back({2, {Point(xr[i], yl[i]), 2 * i}});
            events.push_back({0, {Point(xl[i], yl[i]), 2 * i}});
        }
        if (yr[i] > points[w].y) {
            events.push_back({2, {Point(xr[i], yr[i]), 2 * i + 1}});
            events.push_back({0, {Point(xl[i], yr[i]), 2 * i + 1}});
        }
    }

    for (int i = 0; i < points.size(); i++) {
//         cerr << i << " " << points[i].y << " " << points[w].y << endl;
        if ((points[i].y == points[w].y ||
            (points[i].y >= points[w].y && (!onlyUpperHalf || points[i].x >= points[w].x) &&
            (!onlyLowerHalf || points[i].x <= points[w].x) && !bad)) && !eq(points[i], points[w])) {
            events.push_back({1, {points[i], i}});
        }
    }
    sort(events.begin(), events.end(), cmpU);
    for (int i = 0; i < 2 * n; i++) {
        used[i] = false;
    }
    while (!Q.empty()) { Q.pop(); }
    for (int i = 0; i < events.size(); i++) {
        int type = events[i].first;
        Point p = events[i].second.first;
        int id = events[i].second.second;
        if (type == 2) {
            Q.push({-p.y, id});
            used[id] = true;
        } else if (type == 1) {
            while (!Q.empty() && !used[Q.top().second]) {
                Q.pop();
            }
//             if (id == 2) {
//                 cerr << -Q.top().first << " " << p.y << endl;
//             }
            if (Q.empty() || -Q.top().first >= p.y) {
                canBe[id]++;
            }
        } else {
            used[id] = false;
        }
    }
    //Lower half
    bad = false;
    onlyUpperHalf = false;
    onlyLowerHalf = false;
    events.clear();

    for (int i = 0; i < n; i++) {
        if (yr[i] == points[w].y) {
            if (xl[i] < points[w].x && xr[i] > points[w].x) {
                bad = true;
                break;
            }
            if (xl[i] < points[w].x && xr[i] == points[w].x) {
                onlyUpperHalf = true;
            }
            if (xl[i] == points[w].x && xr[i] > points[w].x) {
                onlyLowerHalf = true;
            }
        }
        if (yl[i] < points[w].y) {
            events.push_back({2, {Point(xl[i], yl[i]), 2 * i}});
            events.push_back({0, {Point(xr[i], yl[i]), 2 * i}});
        }
        if (yr[i] < points[w].y) {
            events.push_back({2, {Point(xl[i], yr[i]), 2 * i + 1}});
            events.push_back({0, {Point(xr[i], yr[i]), 2 * i + 1}});
        }
    }

    for (int i = 0; i < points.size(); i++) {
        if ((false ||
            (points[i].y < points[w].y && (!onlyUpperHalf || points[i].x >= points[w].x) &&
            (!onlyLowerHalf || points[i].x <= points[w].x) && !bad)) && !eq(points[i], points[w])) {
            events.push_back({1, {points[i], i}});
        }
    }
    sort(events.begin(), events.end(), cmpD);
    for (int i = 0; i < 2 * n; i++) {
        used[i] = false;
    }
    while (!Q.empty()) { Q.pop(); }
    for (int i = 0; i < events.size(); i++) {
        int type = events[i].first;
        Point p = events[i].second.first;
        int id = events[i].second.second;
//         cerr << "Punkt: " << p.x << " " << p.y << " " << type << " " << id << " " << endl;
        if (type == 2) {
            Q.push({p.y, id});
            used[id] = true;
        } else if (type == 1) {
            while (!Q.empty() && !used[Q.top().second]) {
                Q.pop();
            }
            if (Q.empty() || Q.top().first <= p.y) {
                canBe[id]++;
            }
        } else {
            used[id] = false;
        }
    }

//     cerr << "Podsumowanie dodanych krawedzi dla w = " << w << endl;
    for (int i = 0; i < points.size(); i++) {
//         cerr << i << " " << canBe[i] << " " << canConnect(points[i], points[w]) << endl;
        if (canBe[i] == 2 && canConnect(points[i], points[w])) {
            V[w].push_back({i, dist(points[i], points[w])});
        }
    }

//     for (int i = 0; i < points.size(); i++) {
//         cerr << "Krawedzie wierzcholka " << i << ":\n";
    //         for (int j = 0; j < V[i].size(); j++) {
    //             cerr << V[i][j].first << " ";
    //         }
//         cerr << endl;
//     }
}

void createGraph() {
    for (int i = 0; i < n; i++) {
        points.push_back(Point(xl[i], yl[i], i));
        points.push_back(Point(xr[i], yr[i], i));
        points.push_back(Point(xl[i], yr[i], i));
        points.push_back(Point(xr[i], yl[i], i));
    }
    points.push_back(Point(xp, yp));
    points.push_back(Point(xk, yk));
    for (int i = 0; i < points.size(); i++) {
        connectPointsWith(i);
    }
}

void dijkstra() {
//     cerr << "Dijkstra\n";
    int nodes = 4 * n + 2;
    for (int i = 0; i < nodes; i++) {
        dists[i] = INF;
    }
    dists[nodes - 2] = 0;
    Q.push({0, nodes - 2});
    while (!Q.empty()) {
        int w = Q.top().second;
        Q.pop();
        if (vis[w]) continue;
//         cerr << "w = " << w << endl;
        vis[w] = true;
        for (int i = 0; i < V[w].size(); i++) {
            int u = V[w][i].first;
            double edge = V[w][i].second;
//             cerr << "u = " << u << " " << dists[w] + edge << endl;
            if (dists[u] > dists[w] + edge - eps) {
                dists[u] = dists[w] + edge;
                Q.push({-dists[u], u});
            }
        }
    }
}

int main() {

    scanf("%d %d %d %d %d", &n, &xp, &yp, &xk, &yk);
    if (xp == xk && yp == yk) {
        printf("0.0\n");
        return 0;
    }
    for (int i = 0; i < n; i++) {
        scanf("%d %d %d %d", &xl[i], &yl[i], &xr[i], &yr[i]);
    }

    createGraph();
    dijkstra();

    printf("%.9f\n", dists[4 * n + 1]);

    return 0;
}