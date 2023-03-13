#include "generator.h"

#include <memory>

template <class F, class S>
std::ostream &operator<<(std::ostream &os, const std::pair<F, S> &pair) {
    os << pair.first << " " << pair.second;
    return os;
}

using graph_t = std::vector<std::pair<int, int>>;

using namespace std;

Test randomTest(int n, int m, int minValue, int maxValue);
Test exampleTest();
Test single();
Test single2();
Test xorZeroSmall();
Test smallFunctionalTest();
Test allQueries(int n, int minValue, int maxValue);
Test manyEvenIntervals(int n, int m, int goodIntervals, int minValue, int maxValue, int maxLen);

int main() {
    Generator gen("jab");

    gen.beginGroup();
    gen.addTest(exampleTest());
    gen.endGroup();
    // 1
    gen.beginGroup();
    {
        gen.addTest(single());
        gen.addTest(single2());
        gen.addTest(xorZeroSmall());
    }
    gen.endGroup();
    // 2
    gen.beginGroup();
    {
        Generator::setSeed(31531431);
        gen.addTest(smallFunctionalTest());
        gen.addTest(allQueries(10, 1, 4));
        gen.addTest(manyEvenIntervals(20, 20, 7, 1, 10, 4));
    }
    gen.endGroup();
//     return 0;
    // 3
    gen.beginGroup();
    {
        Generator::setSeed(48141341);
        gen.addTest(manyEvenIntervals(1000, 1000, 30, 1, 500, 50));
        gen.addTest(manyEvenIntervals(1000, 1000, 300, 1, 50, 20));
        gen.addTest(allQueries(33, 5, 10));
    }
    gen.endGroup();

    // 4
    gen.beginGroup();
    {
        Generator::setSeed(513859131);
        gen.addTest(randomTest(50000, 40000, 1, 1000000));
        gen.addTest(manyEvenIntervals(50000, 40000, 1000, 10, 1000000, 10000));
        gen.addTest(manyEvenIntervals(50000, 40000, 10000, 10, 100, 200));
    }
    gen.endGroup();

    // 5
    gen.beginGroup();
    {
        Generator::setSeed(3851375613);
        gen.addTest(allQueries(1000, 20, 150));
        gen.addTest(manyEvenIntervals(1000000, 1000000, 1000, 1, 100, 200));
        gen.addTest(manyEvenIntervals(1000000, 1000000, 50000, 1, 1000000000, 50000));
    }
    gen.endGroup();

    // 6
    gen.beginGroup();
    {
        Generator::setSeed(848383838);
        gen.addTest(randomTest(1000000, 1000000, 1, 1000000000));
        gen.addTest(randomTest(1000000, 1000000, 1, 5));
        gen.addTest(manyEvenIntervals(1000000, 1000000, 500000, 1, 1000000000, 1000));
        gen.addTest(manyEvenIntervals(1000000, 1000000, 1000, 1, 10000, 100));
    }
    gen.endGroup();

    // 7
    gen.beginGroup();
    {
        Generator::setSeed(513985131);
        gen.addTest(manyEvenIntervals(1000000, 1000000, 3141, 1, 1000000000, 10000));
        gen.addTest(manyEvenIntervals(1000000, 1000000, 54211, 1, 1000, 1000000));
        gen.addTest(manyEvenIntervals(1000000, 1000000, 531513, 1, 1000000, 100));
    }
    gen.endGroup();

    // 8
    gen.beginGroup();
    {
        Generator::setSeed(513985131);
        gen.addTest(manyEvenIntervals(1000000, 1000000, 1000, 1, 1000000000, 1000));
        gen.addTest(manyEvenIntervals(1000000, 1000000, 10000, 1, 10000, 50000));
        gen.addTest(manyEvenIntervals(1000000, 1000000, 1000000, 1, 100000, 500000));
    }
    gen.endGroup();

    gen.generate();
}

int random(int a, int b);
graph_t randomTree(int count);
void addNodes(graph_t &graph, int count, int maxBack);
void shuffleGraph(graph_t &graph);
Test graphToTest(const graph_t &graph);

int random(int a, int b) {
    return Generator::random() % (b - a + 1) + a;
}

Test exampleTest() {
    Test test;
    test.addLine(6, 3);
    test.addLine(2, 5, 3, 5, 3, 2);
    test.addLine(3, 5);
    test.addLine(2, 5);
    test.addLine(2, 6);
    return test;
}

Test single() {
    Test test;
    test.addLine(1, 1);
    test.addLine(2);
    test.addLine(1, 1);
    return test;
}

Test single2() {
    Test test;
    test.addLine(1, 1);
    test.addLine(1);
    test.addLine(1, 1);
    return test;
}

Test xorZeroSmall() {
    Test test;
    test.addLine(6, 3);
    test.addLine(5, 3, 1, 2, 2, 1);
    test.addLine(1, 3);
    test.addLine(3, 6);
    test.addLine(2, 4);
    return test;
}

Test smallFunctionalTest() {
    Test test;
    test.addLine(15, 10);
    test.addLine(5, 2, 3, 8, 5, 8, 13, 5, 13, 2, 3, 1, 5, 13, 8);
    test.addLine(5, 7);
    test.addLine(4, 9);
    test.addLine(6, 13);
    test.addLine(10, 15);
    test.addLine(2, 10);
    test.addLine(5, 7);
    test.addLine(4, 9);
    test.addLine(6, 13);
    test.addLine(10, 15);
    test.addLine(2, 10);
    return test;
}

vector<int> randomSequence(int size, int minValue, int maxValue) {
    vector<int> ret(size);
    for (int i = 0; i < size; i++) {
        ret[i] = random(minValue, maxValue);
    }
    return ret;
}

Test allQueries(int n, int minValue, int maxValue) {
    Test test;
    test.addLine(n, n * (n - 1) / 2 + n);
    test.addLine(randomSequence(n, minValue, maxValue));
    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j++) {
            test.addLine(i, j);
        }
    }
    return test;
}

Test manyEvenIntervals(int n, int m, int goodIntervals, int minValue, int maxValue, int maxLen) {
    Test test;
    
    test.addLine(n, m);
//     cerr << n << " " << m << endl;
    vector<pair<int, int> > intervals;
    for (int i = 0; i < goodIntervals; i++) {
        int b = random(1, n - 1);
        int a = random(max(1, b - maxLen + 1), b);
        if ((b - a + 1) % 2 == 1)
            b++;
        intervals.push_back({a, b});
    }
    
    sort(intervals.begin(), intervals.end());
    
    int lastDetermined = 0;
    vector<int> s;
//     cerr << "Rozwazam: \n";
    for (int i = 0; i < goodIntervals; i++) {
        int a = intervals[i].first;
        int b = intervals[i].second;
//         cerr << a << " " << b << endl;
        while (lastDetermined < a - 1) {
            s.push_back(random(minValue, maxValue));
//             cerr << "Wpycham: " << s.back() << endl;
            lastDetermined++;
        }
        if (lastDetermined >= b) {
            continue;
        }
        int shuffleBegin = lastDetermined + 1;
        while (lastDetermined < (a + b) / 2) {
            s.push_back(random(minValue, maxValue));
//             cerr << "Dodaje randomowe: " << s.back() << endl;
            lastDetermined++;
        }
        int ref = lastDetermined + 1;
        for (int j = ref; j <= b; j++) {
            s.push_back(s[ref - (j - ref) - 2]);
//             cerr << "Uzupelniam: " << s.back() << endl;
        }
        lastDetermined = b;
        random_shuffle(s.begin() + shuffleBegin - 1, s.begin() + b);
    }
//     cerr << "Juz nie rozwazam\n";
    while (lastDetermined < n) {
        s.push_back(random(minValue, maxValue));
        lastDetermined++;
    }
    
    for (int i = goodIntervals + 1; i <= m; i++) {
        int b = random(1, n - 1);
        int a = random(1, b);
        intervals.push_back({a, b});
    }
    
    random_shuffle(intervals.begin(), intervals.end());
    
    test.addLine(s);
    for (int i = 0; i < s.size(); i++) {
//         cerr << s[i] << " ";
    }
    for(int i = 0; i < intervals.size(); i++) {
        test.addLine(intervals[i].first, intervals[i].second);
//         cerr << intervals[i] << endl;
    }
    
    return test;
}

Test randomTest(int n, int m, int minValue, int maxValue) {
    Test test;
    test.addLine(n, m);
    test.addLine(randomSequence(n, minValue, maxValue));
    for (int i = 1; i <= m; i++) {
        int b = random(1, n);
        int a = random(1, b);
        test.addLine(a, b);
    }
    return test;
}