#include "generator.h"

#include <memory>
#include <set>
#include <cstdlib>

template <class F, class S>
std::ostream &operator<<(std::ostream &os, const std::pair<F, S> &pair) {
    os << pair.first << " " << pair.second;
    return os;
}

const int MAXN = 10 * 1000;
const int MAXL = 10 * 1000;
const int MAXM = 500 * 1000;
const long long int MAXD = 1000 * 1000 * 1000 * 1000 * 1000 * 1000;

using query = std::pair<std::pair<int, int>, int>;
using queryVec = std::vector<query>;
using intVec = std::vector<int>;


Test exampleTest();

Test randomTest(int n, int m, long long int maxD);

int main() {
    Generator gen("dre");

    gen.beginGroup();
    gen.addTest(exampleTest());
    gen.endGroup();


    // 1
    gen.beginGroup();
    {
        Generator::setSeed(2134);
        gen.addTest(randomTest(15, 10, 30));
    }
    gen.endGroup();

    // 2
    gen.beginGroup();
    {
        Generator::setSeed(45434);
        gen.addTest(randomTest(30, 30, 100));
    }
    gen.endGroup();

    // 3
    gen.beginGroup();
    {
        Generator::setSeed(52341);
        gen.addTest(randomTest(50, 100, 500));
    }
    gen.endGroup();

    // 4
    gen.beginGroup();
    {
        Generator::setSeed(12341);
        gen.addTest(randomTest(100, 215, 1000));
    }
    gen.endGroup();

    // 5
    gen.beginGroup();
    {
        Generator::setSeed(8657);
        gen.addTest(randomTest(1 * 1000, 3 * 1000, 100 * 1000));
    }
    gen.endGroup();

    // 6
    gen.beginGroup();
    {
        Generator::setSeed(6234723);
        gen.addTest(randomTest(8 * 1000, 10 * 1000, 1000 * 1000 * 1000));
    }
    gen.endGroup();

    // 7
    gen.beginGroup();
    {
        Generator::setSeed(12398912);
        gen.addTest(randomTest(10 * 1000, 100 * 1000, MAXD));
    }
    gen.endGroup();

    // 8
    gen.beginGroup();
    {
        Generator::setSeed(8657);
        gen.addTest(randomTest(10 * 1000, 100 * 1000, 100 * 1000));
    }
    gen.endGroup();
    
    gen.generate();
}

Test createTestFromData(intVec trees, queryVec queries);
intVec createRandomForest(int size, int maxValue);
queryVec createRandomQueries(int n, int m, long long int maxD);

Test exampleTest() {
    Test test;
    test.addLine(5);
    test.addLine(10, 10, 10, 2, 3);
    test.addLine(3);
    test.addLine(1, 3, 1);
    test.addLine(4, 5, 2);
    test.addLine(4, 4, 3);
    return test;
}

Test randomTest(int n, int m, long long int maxD) {
    intVec trees = createRandomForest(n, std::min(n / 3 + Generator::random() % MAXL, (unsigned int) MAXL));
    queryVec queries = createRandomQueries(n, m, maxD);

    return createTestFromData(trees, queries);
}

Test createTestFromData(intVec trees, queryVec queries) {
    Test test;
    test.addLine(trees.size());
    test.addLine(trees);
    test.addLine(queries.size());
    for (int i = 0; i < queries.size(); i++) {
        test.addLine(queries[i].first.first, queries[i].first.second, queries[i].second);
    }
    return test;
}

intVec createRandomForest(int size, int maxValue) {
    intVec result;
    for (int i = 0; i < size; i++) {
        result.push_back(Generator::random() % maxValue + 1);
    }
    return result;
}

queryVec createRandomQueries(int n, int m, long long int maxD) {
    queryVec result;
    for (int i = 0; i < m; i++) {
        int one = Generator::random() % n + 1;
        int other = Generator::random() % n + 1;
        if (one > other) {
            std::swap(one, other);
        }

        int queryD = Generator::random() % maxD + 1;
        result.push_back(std::make_pair(std::make_pair(one, other), queryD));
    }
    return result;
}


