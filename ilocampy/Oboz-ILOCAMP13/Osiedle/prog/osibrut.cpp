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
            intersects(a, b, pg, pd) || intersects(a, b, pd, ld) ||
            intersects(a, b, ld, pg) || intersects(a, b, lg, pd)) {
            return true;
        }
    }
    return false;
}

void createGraph() {
    for (int i = 0; i < n; i++) {
        points.push_back(Point(xl[i], yl[i], i));
        points.push_back(Point(xr[i], yr[i], i));
        points.push_back(Point(xl[i], yr[i], i));
        points.push_back(Point(xr[i], yl[i], i));
    }
    for (int i = 0; i < points.size(); i++) {
        for (int j = 0; j < i; j++) { //nie patrzymy na punkt będący przeciwległym rogiem prostokąta
            if (!intersect(points[i], points[j]) && canConnect(points[i], points[j])) {
                V[i].push_back({j, dist(points[i], points[j])});
                V[j].push_back({i, dist(points[i], points[j])});
            }
        }
    }
    points.push_back(Point(xp, yp));
    for (int i = 0; i < points.size() - 1; i++) {
        if (!intersect(points.back(), points[i]) && canConnect(points.back(), points[i])) {
            int x = points.size() - 1;
            V[x].push_back({i, dist(points.back(), points[i])});
            V[i].push_back({x, dist(points.back(), points[i])});
        }
    }
    points.push_back(Point(xk, yk));
    for (int i = 0; i < points.size() - 1; i++) {
        if (!intersect(points.back(), points[i]) && canConnect(points.back(), points[i])) {
            int x = points.size() - 1;
            V[x].push_back({i, dist(points.back(), points[i])});
            V[i].push_back({x, dist(points.back(), points[i])});
        }
    }
}

void dijkstra() {
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
//         cerr << w << " " << dists[w] << endl;
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
    for (int i = 0; i < n; i++) {
        scanf("%d %d %d %d", &xl[i], &yl[i], &xr[i], &yr[i]);
    }

    createGraph();
    dijkstra();

    printf("%.9f\n", dists[4 * n + 1]);

    return 0;
}