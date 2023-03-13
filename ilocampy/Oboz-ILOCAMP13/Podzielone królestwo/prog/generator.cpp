#include "generator.h"

#include <memory>

using graph_t = std::vector<std::pair<int, int>>;
using namespace std;

const int MIN_N = 1;
const int MAX_N = 500000;

template <class F, class S>
std::ostream &operator<<(std::ostream &os, const std::pair<F, S> &pair) {
    os << pair.first << " " << pair.second;
    return os;
}

Test exampleTest();
Test cornerCase1();
Test cornerCase2();
Test cornerCase3();
Test cornerCase4();
Test combineGraphs(graph_t G1, graph_t G2, int n, int p, int j);
Test alternatingPath(int n);
Test testFromPair(pair<graph_t, graph_t> pa, int p, int j);
graph_t randomGraph(int n, int m);
pair<graph_t, graph_t> randomGraphsWithPath(int n, int m1, int m2, int from, int to);
pair<graph_t, graph_t> graphsWithLargeResult(int n, int m1, int m2, int estRes, int from, int to);
int random(int a, int b);
Test small1();
Test small2();
Test small3();
Test small4();

int main() {
    Generator gen("pod");

    gen.beginGroup();
    gen.addTest(exampleTest());
    gen.endGroup();

    //1
    gen.beginGroup();
    {
        gen.addTest(cornerCase1());
        gen.addTest(cornerCase2());
        gen.addTest(cornerCase3());
        gen.addTest(cornerCase4());
        gen.addTest(small1());
        gen.addTest(small2());
    }
    gen.endGroup();

    //2
    gen.beginGroup();
    {
        gen.addTest(small3());
        gen.addTest(small4());
        int n = 20;
        Generator::setSeed(20002000);
        gen.addTest(combineGraphs(randomGraph(n, 25), randomGraph(n, 26), n, 1, n));
        Generator::setSeed(20002001);
        gen.addTest(testFromPair(randomGraphsWithPath(n, 15, 10, n, 1), n, 1));
    }
    gen.endGroup();

    //3, n, m <= 3000, n^2 42 pkt.
    gen.beginGroup();
    {
        int n = 1000;
        Generator::setSeed(3003000);
        gen.addTest(combineGraphs(randomGraph(n, 1500), randomGraph(n, 500), n, 151, 288));
        Generator::setSeed(3003001);
        gen.addTest(testFromPair(randomGraphsWithPath(n / 2, 2500, 3000, 15, 77), 15, 77));
        Generator::setSeed(3003001);
        gen.addTest(testFromPair(randomGraphsWithPath(n / 2, 100, 50, 15, 77), 15, 77));


    }
    gen.endGroup();

    //4, n, m <= 30000, n*k, where k is result 57 pkt.
    gen.beginGroup();
    {
        int n = 10000;
        Generator::setSeed(4004004);
        gen.addTest(combineGraphs(randomGraph(n, 10000), randomGraph(n, 9825), n, 4521, 1666));
        Generator::setSeed(4004001);
        gen.addTest(testFromPair(randomGraphsWithPath(3 * n, 2000, 3000, 1261, 9333), 1261, 9333));

    }
    gen.endGroup();

    // 5, n, m <= 10^5 // n * sqrt(n) (if exists) - 71 pkt.
    gen.beginGroup();
    {
        int n = 50000;
        Generator::setSeed(5005000);
        gen.addTest(combineGraphs(randomGraph(n, 2 * n), randomGraph(n, 2 * n), n, 40194, 351));
        Generator::setSeed(5005001);
        gen.addTest(testFromPair(randomGraphsWithPath(2 * n, 10000, 5000, n - 1, n - 2), n - 1, n - 2));
        gen.addTest(alternatingPath(n - 1));
        Generator::setSeed(5005003);
        gen.addTest(testFromPair(graphsWithLargeResult(2 * n, 10000, 10000, 20000, 1, n), 1, n));

    }
    gen.endGroup();

    // 6, n, m <= MAX_N
    gen.beginGroup();
    {
        int n = MAX_N;
        Generator::setSeed(6006000);
        gen.addTest(combineGraphs(randomGraph(n / 2, n - 30), randomGraph(n / 2, n - 3), n, 1, n / 2));
        Generator::setSeed(6006001);
        gen.addTest(testFromPair(randomGraphsWithPath(n, n / 3, n / 2, n - 1, 1), n - 1, 1));

        Generator::setSeed(6006002);
        gen.addTest(testFromPair(graphsWithLargeResult(n, 56506, 67000, 122000, 1, n), 1, n));
        Generator::setSeed(6006003);
        gen.addTest(testFromPair(graphsWithLargeResult(n, 205320, 215100, 420400, 1, n), 1, n));
    }
    gen.endGroup();

    // 7, maxTests
    gen.beginGroup();
    {
        int n = 500000;
        gen.addTest(alternatingPath(n - 1));
        Generator::setSeed(7007000);
        gen.addTest(combineGraphs(randomGraph(n, n), randomGraph(n, n), n, 1, n));

        Generator::setSeed(7007001);
        gen.addTest(testFromPair(graphsWithLargeResult(n, 405022, 340433, n - 1, 1, n), 1, n));
        Generator::setSeed(7007002);
        gen.addTest(testFromPair(graphsWithLargeResult(n, 200022, 300433, n - 1, 1, n), 1, n));
    }
    gen.endGroup();

    gen.generate();
}

Test cornerCase1() {
    Test test;

    test.addLine(1, 1, 1);
    test.addLine(0);
    test.addLine(0);

    return test;
}

Test cornerCase2() {
    Test test;

    test.addLine(2, 1, 2);
    test.addLine(0);
    test.addLine(0);

    return test;
}

Test cornerCase3() {
    Test test;

    test.addLine(2, 1, 2);
    test.addLine(1);
    test.addLine(1, 2);
    test.addLine(0);

    return test;
}

Test cornerCase4() {
    Test test;

    test.addLine(2, 2, 1);
    test.addLine(0);
    test.addLine(1);
    test.addLine(2, 1);

    return test;
}

Test small1() { // Output 3
    Test test;

    test.addLine(8, 3, 8);
    test.addLine(5);
    test.addLine(1, 2);
    test.addLine(3, 4);
    test.addLine(3, 5);
    test.addLine(5, 7);
    test.addLine(6, 8);
    test.addLine(7);
    test.addLine(6, 3);
    test.addLine(6, 8);
    test.addLine(2, 8);
    test.addLine(5, 1);
    test.addLine(4, 5);
    test.addLine(7, 4);
    test.addLine(8, 7);

    return test;
}

Test small2() { // Output 5
    Test test;

    test.addLine(10, 4, 6);
    test.addLine(9);
    test.addLine(2, 1);
    test.addLine(2, 3);
    test.addLine(5, 1);
    test.addLine(7, 4);
    test.addLine(9, 3);
    test.addLine(9, 6);
    test.addLine(9, 10);
    test.addLine(10, 5);
    test.addLine(10, 6);

    test.addLine(10);
    test.addLine(1, 2);
    test.addLine(2, 1);
    test.addLine(1, 7);
    test.addLine(3, 5);
    test.addLine(4, 3);
    test.addLine(7, 10);
    test.addLine(8, 7);
    test.addLine(8, 4);
    test.addLine(8, 6);
    test.addLine(9, 6);
    return test;
}

Test small3() { // Output 5
    Test test;

    test.addLine(16, 1, 16);
    test.addLine(15);
    test.addLine(1, 6);
    test.addLine(6, 7);
    test.addLine(2, 7);
    test.addLine(3, 2);
    test.addLine(3, 4);
    test.addLine(4, 8);
    test.addLine(8, 12);
    test.addLine(5, 12);
    test.addLine(5, 9);
    test.addLine(9, 14);
    test.addLine(14, 10);
    test.addLine(10, 13);
    test.addLine(13, 15);
    test.addLine(11, 15);
    test.addLine(16, 11);

    test.addLine(15);
    test.addLine(6, 1);
    test.addLine(7, 6);
    test.addLine(7, 2);
    test.addLine(2, 3);
    test.addLine(4, 3);
    test.addLine(8, 3);
    test.addLine(12, 8);
    test.addLine(12, 5);
    test.addLine(9, 5);
    test.addLine(14, 9);
    test.addLine(10, 14);
    test.addLine(13, 10);
    test.addLine(15, 13);
    test.addLine(15, 11);
    test.addLine(11, 16);

    return test;
}

Test small4() { // Output 3
    Test test;

    test.addLine(15, 1, 15);
    test.addLine(14);
    test.addLine(1, 2);
    test.addLine(2, 3);
    test.addLine(3, 8);
    test.addLine(8, 9);
    test.addLine(6, 12);
    test.addLine(7, 10);
    test.addLine(8, 1);
    test.addLine(10, 11);
    test.addLine(11, 12);
    test.addLine(11, 10);
    test.addLine(12, 11);
    test.addLine(11, 14);
    test.addLine(14, 13);
    test.addLine(13, 15);
    test.addLine(14);
    test.addLine(3, 1);
    test.addLine(2, 3);
    test.addLine(4, 5);
    test.addLine(6, 4);
    test.addLine(5, 7);
    test.addLine(8, 5);
    test.addLine(8, 6);
    test.addLine(9, 2);
    test.addLine(10, 11);
    test.addLine(11, 10);
    test.addLine(11, 12);
    test.addLine(12, 11);
    test.addLine(14, 15);
    test.addLine(14, 13);

    return test;
}

Test alternatingPath(int n) {
    Test test;

    test.addLine(n, 1, n);
    test.addLine(n / 2);
    for (int i = 1; i < n; i += 2) {
        test.addLine(i, i + 1);
    }
    test.addLine(n / 2);
    for (int i = 2; i < n; i += 2) {
        test.addLine(i, i + 1);
    }

    return test;
}

Test combineGraphs(graph_t G1, graph_t G2, int n, int p, int j) {
    Test test;

    test.addLine(n, p, j);
    test.addLine(G1.size());
    for (int i = 0; i < G1.size(); i++) {
        test.addLine(G1[i]);
    }
    test.addLine(G2.size());
    for (int i = 0; i < G2.size(); i++) {
        test.addLine(G2[i]);
    }

    return test;
}

Test testFromPair(pair<graph_t, graph_t> pa, int p, int j) {
    int n = 0;
    for (int i = 0; i < pa.first.size(); i++) {
        n = max(n, max(pa.first[i].first, pa.first[i].second));
    }

    for (int i = 0; i < pa.second.size(); i++) {
        n = max(n, max(pa.second[i].first, pa.second[i].second));
    }
    return combineGraphs(pa.first, pa.second, n, p, j);
}

// Totally random graph
graph_t randomGraph(int n, int m) {
    graph_t ret;
    for (int i = 0; i < m; i++) {
        int a, b;
        do {
            a = random(1, n);
            b = random(1, n);
        } while (a == b);
        ret.push_back({a, b});
    }
    return ret;
}

graph_t getPath(int from, int to, int n, int m1, int m2, int dist) {
    graph_t ret;

    int edges = dist;
    int nodesOnPath[edges + 1];
    for (int i = 0; i <= edges; i++) {
        nodesOnPath[i] = -1;
    }
    nodesOnPath[0] = from;
    nodesOnPath[edges] = to;
    for (int i = 1; i < edges; i++) {
        do {
            nodesOnPath[i] = random(1, n);
        } while (nodesOnPath[i - 1] == nodesOnPath[i] || nodesOnPath[i] == nodesOnPath[i + 1]);
    }
    for (int i = 1; i <= edges; i++) {
        int whichGraph = random(0, 1);
        if (whichGraph == 0 && m1 > 0) {
            m1--;
            ret.push_back({nodesOnPath[i - 1], nodesOnPath[i]});
        } else {
            m2--;
            ret.push_back({nodesOnPath[i - 1] + n, nodesOnPath[i] + n});
        }
    }
    return ret;
}

//nodes dont repeat on the path
graph_t getPath2 (int from, int to, int n, int m1, int m2, int dist) {
    graph_t ret;

    int edges = dist;
    int tmp[n + 1];
    for (int i = 1; i <= n; i++) {
        tmp[i] = i;
    }
    random_shuffle(tmp + 1, tmp + 1 + n);
    for (int i = 1; i <= n; i++) {
        if (tmp[i] == from) {
            swap(tmp[i], tmp[1]);
        }
        if (tmp[i] == to) {
            swap(tmp[i], tmp[edges + 1]);
        }
    }
    int nodesOnPath[edges + 1];
    for (int i = 0; i <= edges; i++) {
        nodesOnPath[i] = tmp[i + 1];
    }
    assert(nodesOnPath[0] == from);
    assert(nodesOnPath[edges] == to);

    for (int i = 1; i <= edges; i++) {
        int whichGraph = random(0, 1);
        if (whichGraph == 0 && m1 > 0) {
            m1--;
            ret.push_back({nodesOnPath[i - 1], nodesOnPath[i]});
        } else {
            m2--;
            ret.push_back({nodesOnPath[i - 1] + n, nodesOnPath[i] + n});
        }
    }
    return ret;
}

graph_t getRandomPath(int from, int to, int n, int m1, int m2) {
    return getPath(from, to, n, m1, m2, random(1, m1 + m2));
}

// Creates random path from beginNode to endNode and adds random edges to the rest of both graphs
pair<graph_t, graph_t> randomGraphsWithPath(int n, int m1, int m2, int from, int to) {
    graph_t G1, G2;
    graph_t path = getRandomPath(from, to, n, m1, m2);
    for (int i = 0; i < path.size(); i++) {
        if (path[i].first > n) {
            G2.push_back({path[i].first - n, path[i].second - n});
            m2--;
        } else {
            G1.push_back(path[i]);
            m1--;
        }
    }
    graph_t G1rest = randomGraph(n, m1);
    graph_t G2rest = randomGraph(n, m2);
    for (auto e : G1rest) {
        G1.push_back(e);
    }
    for (auto e : G2rest) {
        G2.push_back(e);
    }
    return {G1, G2};
}

pair<graph_t, graph_t> graphsWithLargeResult(int n, int m1, int m2, int estRes, int from, int to) {
    assert(estRes <= m1 + m2);
    graph_t G1, G2;
    graph_t path = getPath2(from, to, n, m1, m2, estRes);
    for (int i = 0; i < path.size(); i++) {
        if (path[i].first > n) {
            G2.push_back({path[i].first - n, path[i].second - n});
            m2--;
        } else {
            G1.push_back(path[i]);
            m1--;
        }
    }
    graph_t G1rest = randomGraph(n, m1);
    graph_t G2rest = randomGraph(n, m2);
    for (auto e : G1rest) {
        G1.push_back(e);
    }
    for (auto e : G2rest) {
        G2.push_back(e);
    }
    return {G1, G2};
}

Test exampleTest() {
    Test test;
    test.addLine(6, 1, 5);
    test.addLine(7);
    test.addLine(1, 3);
    test.addLine(3, 2);
    test.addLine(2, 1);
    test.addLine(6, 3);
    test.addLine(4, 3);
    test.addLine(4, 6);
    test.addLine(5, 4);
    test.addLine(6);
    test.addLine(3, 1);
    test.addLine(3, 4);
    test.addLine(2, 4);
    test.addLine(6, 3);
    test.addLine(6, 4);
    test.addLine(6, 5);
    return test;
}

int random(int a, int b) {
    return Generator::random() % (b - a + 1) + a;
}
