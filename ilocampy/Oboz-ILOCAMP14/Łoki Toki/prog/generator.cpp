#include "generator.h"

#include <memory>
#include <vector>
using namespace std;

int R(int a, int b);

Test example() {
    Test test;
    test.addLine(5, 3);
    test.addLine(2, 2, 3);
    test.addLine(3, 1, 3, 5);
    test.addLine(2, 2, 1);
    test.addLine(0);
    test.addLine(1, 2);
    return test;
}

Test randomTest(int n, int m, long long s) {
    Test test;
    
    assert(n <= 25 && 0 <= s && s <= 1000000000LL * 1000000000LL);
    
    assert(m <= n*(n-1) / 2);
    
    test.addLine(n, s);
    
    bool t[n+5][n+5];
    
    for (int i=1; i<=n; i++)
        for (int j=1; j<=n; j++)
            t[i][j] = false;
    
    for (int i=1; i<=m; i++) {
        int a = R(1, n);
        int b = R(1, n);
        
        while (t[a][b] == true || a == b) {
            a = R(1, n);
            b = R(1, n);
        }
        
        t[a][b] = true;
        t[b][a] = true;
    }
    
    for (int i=1; i<=n; i++) {
        int sum = 0;
        vector <int> v;
        for (int j=1; j<=n; j++)
            if (t[i][j]) {
                v.push_back(j);
                sum++;
            }
        test.addLine(sum, v);
    }
    
    return test;
}

Test corner1() {
    Test test;
    
    test.addLine(3, 1);
    test.addLine(2, 2, 3);
    test.addLine(1, 1);
    test.addLine(1, 1);
    
    return test;
}

Test corner2() {
    Test test;
    
    test.addLine(4, 5);
    test.addLine(2, 2, 4);
    test.addLine(2, 1, 3);
    test.addLine(2, 2, 4);
    test.addLine(2, 3, 1);
    
    return test;
}

vector <pair <int, int> > makeLine(int m) {
    vector <pair <int, int> > v;
    
    for (int i=2; i<=m; i++)
        v.push_back(make_pair(i-1, i));
    
    return v;
}

Test makeAlmostLineGraphTest(int n, int m, long long s) {
    Test test;
    
    assert(n <= 25 && 0 <= s && s <= 1000000000LL * 1000000000LL);
    
    test.addLine(n, s);
    
    bool t[n+5][n+5];
    vector <pair <int, int> > v = makeLine(n);
    
    for (int i=1; i<=n; i++)
        for (int j=1; j<=n; j++)
            t[i][j] = false;
    
    for (int i=0; i<m-n+1; i++) {
        int odl = R(2, 5);
        int a = R(1, n-odl);
        v.push_back(make_pair(a, a+odl));
    }
    
    for (int i=0; i<v.size(); i++)
        t[v[i].first][v[i].second] = t[v[i].second][v[i].first] = true;
    
    for (int i=1; i<=n; i++) {
        int sum = 0;
        vector <int> V;
        for (int j=1; j<=n; j++)
            if (t[i][j]) {
                V.push_back(j);
                sum++;
            }
        test.addLine(sum, V);
    }
    
    return test;
}

int main() {
    Generator gen("lok");

    gen.beginGroup();
    gen.addTest(example());
    gen.endGroup();

    gen.beginGroup();
    {
        gen.addTest(corner1());
        gen.addTest(corner2());
        Generator::setSeed(101);
        gen.addTest(randomTest(5, 7, 2));
        Generator::setSeed(102);
        gen.addTest(randomTest(5, 8, 3));
        Generator::setSeed(103);
        gen.addTest(randomTest(6, 10, 10));
        Generator::setSeed(104);
        gen.addTest(randomTest(2, 1, 0));
    }
    gen.endGroup();

    // 2
    gen.beginGroup();
    {
        Generator::setSeed(201);
        gen.addTest(randomTest(10, 15, 100));
        Generator::setSeed(202);
        gen.addTest(randomTest(10, 20, 10));
        Generator::setSeed(203);
        gen.addTest(randomTest(10, 25, 97));
        Generator::setSeed(204);
        gen.addTest(randomTest(10, 40, 87));
    }
    gen.endGroup();

    // 3
    gen.beginGroup();
    {
        Generator::setSeed(301);
        gen.addTest(randomTest(14, 20, 100));
        Generator::setSeed(302);
        gen.addTest(randomTest(15, 30, 1001));
        Generator::setSeed(303);
        gen.addTest(randomTest(15, 41, 970));
        Generator::setSeed(304);
        gen.addTest(randomTest(16, 97, 875));
    }
    gen.endGroup();

    // 4
    gen.beginGroup();
    {
        Generator::setSeed(401);
        gen.addTest(randomTest(20, 30, 10034));
        Generator::setSeed(402);
        gen.addTest(randomTest(19, 40, 1001000));
        Generator::setSeed(403);
        gen.addTest(randomTest(20, 51, 970876));
        Generator::setSeed(404);
        gen.addTest(randomTest(20, 153, 875444));
        Generator::setSeed(405);
        gen.addTest(makeAlmostLineGraphTest(20, 25, 875444));
        Generator::setSeed(406);
        gen.addTest(makeAlmostLineGraphTest(20, 100, 916305));
    }
    gen.endGroup();

    // 5
    gen.beginGroup();
    {
        Generator::setSeed(501);
        gen.addTest(randomTest(20, 45, 1000000000));
        Generator::setSeed(502);
        gen.addTest(randomTest(19, 99, 1001444671));
        Generator::setSeed(503);
        gen.addTest(randomTest(20, 26, 970000000));
        Generator::setSeed(504);
        gen.addTest(randomTest(20, 80, 875999657));
    }
    gen.endGroup();

    // 6
    gen.beginGroup();
    {
        Generator::setSeed(601);
        gen.addTest(randomTest(24, 40, 1000000000LL * 9876531LL));
        Generator::setSeed(602);
        gen.addTest(randomTest(25, 60, 1001444671LL * 1000LL));
        Generator::setSeed(603);
        gen.addTest(randomTest(25, 56, 1000000000LL * 1000000000LL));
        Generator::setSeed(604);
        gen.addTest(randomTest(25, 298, 1000000000LL * 98712319LL));
    }
    gen.endGroup();

    // 7
    gen.beginGroup();
    {
        Generator::setSeed(701);
        gen.addTest(randomTest(24, 275, 999999999LL * 87654312LL));
        Generator::setSeed(702);
        gen.addTest(randomTest(25, 41, 1001444671LL * 123LL));
        Generator::setSeed(703);
        gen.addTest(randomTest(25, 37, 123));
        Generator::setSeed(704);
        gen.addTest(randomTest(25, 54, 123987));
    }
    gen.endGroup();

    gen.generate();
}


int R(int a, int b) {
    return Generator::random() % (b - a + 1) + a;
}

