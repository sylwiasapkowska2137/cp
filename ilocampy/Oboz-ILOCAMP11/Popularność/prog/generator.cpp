#include "generator.h"

#include <memory>
#include <set>
#include <cstdlib>

template <class F, class S>
std::ostream &operator<<(std::ostream &os, const std::pair<F, S> &pair) {
    os << pair.first << " " << pair.second;
    return os;
}

using intVec = std::vector<int>;
using intVecVec = std::vector<intVec>;
using intPair = std::pair<int, int>;
using intPairVec = std::vector<intPair>;

Test exampleTest();

Test cornerSmall();
Test cornerMinimal();
Test cornerAllFollowing();
Test cornerNoFollowing();

Test closeToNoFollowers(int n, int m, int maxQueriesSum);
Test manyFollowers(int n, int m, int maxQueriesSum);
Test random(int n, int m, int maxQueriesSum);
Test manySmallConnections(int n, int m, int maxQueriesSum);
Test coupleBigConnections(int n, int m, int maxQueriesSum);
Test maximumConnection(int n, int m, int maxQueriesSum);
Test zeroConnections(int n, int m, int maxQueriesSum);

int main() {
    Generator gen("pop");

    gen.beginGroup();
    gen.addTest(exampleTest());
    gen.endGroup();
    
    // 1
    gen.beginGroup();
    {
        gen.addTest(cornerSmall());
        Generator::setSeed(812938);
        gen.addTest(closeToNoFollowers(20, 20, 200));
    }
    gen.endGroup();

    // 2
    gen.beginGroup();
    {
        gen.addTest(cornerNoFollowing());
        Generator::setSeed(333772);
        gen.addTest(manyFollowers(20, 20, 200));
    }
    gen.endGroup();

    // 3
    gen.beginGroup();
    {
        gen.addTest(cornerAllFollowing());
        Generator::setSeed(55234);
        gen.addTest(random(20, 20, 400));
    }
    gen.endGroup();

    // 4
    gen.beginGroup();
    {
        gen.addTest(cornerMinimal());
        Generator::setSeed(5636421);
        gen.addTest(manySmallConnections(90, 90, 3000));
    }
    gen.endGroup();

    // 5
    gen.beginGroup();
    {
        Generator::setSeed(989123);
        gen.addTest(manyFollowers(2000, 5 * 1000, 700 * 1000));

        Generator::setSeed(9123964);
        gen.addTest(closeToNoFollowers(1900, 4 * 1000, 800 * 1000));

        Generator::setSeed(1234412);
        gen.addTest(maximumConnection(1800, 2000, 1000 * 1000));
    }
    gen.endGroup();

    // 6
    gen.beginGroup();
    {
        Generator::setSeed(123854);
        gen.addTest(zeroConnections(650, 10 * 1000, 500 * 1000));

        Generator::setSeed(669129);
        gen.addTest(manyFollowers(2000, 3 * 1000, 990 * 1000));

        Generator::setSeed(3555234);
        gen.addTest(maximumConnection(2000, 2 * 1000, 1000 * 1000));
    }
    gen.endGroup();

    // 7
    gen.beginGroup();
    {
        Generator::setSeed(949192);
        gen.addTest(coupleBigConnections(2000, 4 * 1000, 1000 * 1000));

        Generator::setSeed(24514);
        gen.addTest(random(2000, 5000, 1000 * 1000));

        Generator::setSeed(1234);
        gen.addTest(maximumConnection(2000, 2 * 1000, 1000 * 1000));
    }
    gen.endGroup();

    // 8
    gen.beginGroup();
    {
        Generator::setSeed(86512);
        gen.addTest(zeroConnections(1900, 900 * 1000, 1000 * 1000));

        Generator::setSeed(914);
        gen.addTest(closeToNoFollowers(1900, 4 * 1000, 800 * 1000));

        Generator::setSeed(4472341);
        gen.addTest(maximumConnection(2000, 1000, 1000 * 1000));
    }
    gen.endGroup();

    gen.generate();
}

intPairVec createRandomPairs(int n, int count);
intVecVec createRandomTable(int n, int pairs);
intVecVec createTableFromPairs(int n, intPairVec vec);

intVecVec createRandomQueriesForTable(intVecVec &table, int m, int maxSumOfQueries, int type);
intVecVec createUltraSmallRandomQueriesForTable(intVecVec &table, int m, int maxSumOfQueries);

void incrementQueriesElements(intVecVec &toIncrement);
intVecVec createProperQueriesOutput(intVecVec toOoutput);

Test exampleTest() {
    Test test;
    test.addLine("6");
    test.addLine("0 0 1 0 1 1");
    test.addLine("0 0 1 0 0 1");
    test.addLine("0 0 0 0 1 1");
    test.addLine("1 0 0 0 0 1");
    test.addLine("0 0 0 0 0 1");
    test.addLine("0 0 0 0 0 0");
    test.addLine("4");
    test.addLine("3 1 2 3");
    test.addLine("3 1 5 3");
    test.addLine("4 1 2 6 4");
    test.addLine("4 1 2 4 5");
    return test;
}

Test cornerSmall() {
    Test test;
    test.addLine("2");
    test.addLine("0 1");
    test.addLine("0 0");
    test.addLine("3");
    test.addLine("2 1 2");
    test.addLine("1 1");
    test.addLine("1 2");
    return test;
}

Test cornerMinimal() {
    Test test;
    test.addLine("1");
    test.addLine("0");
    test.addLine("1");
    test.addLine("1 1");
    return test;
}
Test cornerAllFollowing() {
    Test test;
    test.addLine("4");
    test.addLine("0 1 1 1");
    test.addLine("1 0 1 1");
    test.addLine("1 1 0 1");
    test.addLine("1 1 1 0");
    test.addLine("4");
    test.addLine("3 1 2 3");
    test.addLine("2 1 2");
    test.addLine("1 1");
    test.addLine("4 1 2 3 4");
    return test;
}

Test cornerNoFollowing() {
    Test test;
    test.addLine("4");
    test.addLine("0 0 0 0");
    test.addLine("0 0 0 0");
    test.addLine("0 0 0 0");
    test.addLine("0 0 0 0");
    test.addLine("4");
    test.addLine("3 1 2 3");
    test.addLine("2 1 2");
    test.addLine("1 1");
    test.addLine("4 1 2 3 4");
    return test;
}

Test closeToNoFollowers(int n, int m, int maxQueriesSum) {
    Test test;

    int pairsCount = n / 2 + (Generator::random() % n);
    intVecVec table = createTableFromPairs(n, createRandomPairs(n, pairsCount));
    intVecVec queriesForTable = createRandomQueriesForTable(table, m, maxQueriesSum, 0); 

    test.addLine(table.size());
    for (int i = 0; i < table.size(); i++) {
        test.addLine(table[i]);
    }
    test.addLine(queriesForTable.size());
    incrementQueriesElements(queriesForTable);
    intVecVec finalQueries = createProperQueriesOutput(queriesForTable);
    for (int i = 0; i < finalQueries.size(); i++) {
        test.addLine(finalQueries[i]);
    }

    return test;
}

Test manyFollowers(int n, int m, int maxQueriesSum) {
    Test test;

    int pairsCount = n * n / 3 + (Generator::random() % n);
    intVecVec table = createTableFromPairs(n, createRandomPairs(n, pairsCount));
    intVecVec queriesForTable = createRandomQueriesForTable(table, m, maxQueriesSum, 0); 

    test.addLine(table.size());
    for (int i = 0; i < table.size(); i++) {
        test.addLine(table[i]);
    }
    test.addLine(queriesForTable.size());
    incrementQueriesElements(queriesForTable);
    intVecVec finalQueries = createProperQueriesOutput(queriesForTable);
    for (int i = 0; i < finalQueries.size(); i++) {
        test.addLine(finalQueries[i]);
    }

    return test;
}

Test random(int n, int m, int maxQueriesSum) {
    Test test;

    int pairsCount = Generator::random() % (n * n - n - 2) + 1;
    intVecVec table = createTableFromPairs(n, createRandomPairs(n, pairsCount));
    intVecVec queriesForTable = createRandomQueriesForTable(table, m, maxQueriesSum, 2); 

    test.addLine(table.size());
    for (int i = 0; i < table.size(); i++) {
        test.addLine(table[i]);
    }
    test.addLine(queriesForTable.size());
    incrementQueriesElements(queriesForTable);
    intVecVec finalQueries = createProperQueriesOutput(queriesForTable);
    for (int i = 0; i < finalQueries.size(); i++) {
        test.addLine(finalQueries[i]);
    }

    return test;
}


Test manySmallConnections(int n, int m, int maxQueriesSum) {
    Test test;

    // creating sth in a diagonal shape
    intPairVec pairsVec;
    for (int i = 0; i < n - 1; i++) {
        intPair current;
        current.first = i;
        current.second = i + 1;
        pairsVec.push_back(current);
    }

    intVecVec table = createTableFromPairs(n, pairsVec);
    intVecVec queriesForTable = createRandomQueriesForTable(table, m, maxQueriesSum, 0); 

    test.addLine(table.size());
    for (int i = 0; i < table.size(); i++) {
        test.addLine(table[i]);
    }
    test.addLine(queriesForTable.size());
    incrementQueriesElements(queriesForTable);
    intVecVec finalQueries = createProperQueriesOutput(queriesForTable);
    for (int i = 0; i < finalQueries.size(); i++) {
        test.addLine(finalQueries[i]);
    }

    return test;
}

Test coupleBigConnections(int n, int m, int maxQueriesSum) {
    Test test;

    intVec all;
    for (int i = 0; i < n; i++) {
        all.push_back(i);
    }
    std::shuffle(all.begin(), all.end(), Generator::getGen());

    // creating connections:
    intPairVec pairsVec;
    int connectionsCount = 3 + Generator::random() % 5;
    for (int i = 0; i < connectionsCount; i++) {
        int connectionSize = n / connectionsCount;
        int currentFirst = all.back();
        all.pop_back();
        int currentSecond;
        for (int j = 1; j < connectionSize; j++) {
            currentSecond = all.back();
            all.pop_back();
            pairsVec.push_back(std::make_pair(currentSecond, currentFirst));
        }
    }

    intVecVec table = createTableFromPairs(n, pairsVec);
    intVecVec queriesForTable = createRandomQueriesForTable(table, m, maxQueriesSum, 1); 

    test.addLine(table.size());
    for (int i = 0; i < table.size(); i++) {
        test.addLine(table[i]);
    }
    test.addLine(queriesForTable.size());
    incrementQueriesElements(queriesForTable);
    intVecVec finalQueries = createProperQueriesOutput(queriesForTable);
    for (int i = 0; i < finalQueries.size(); i++) {
        test.addLine(finalQueries[i]);
    }

    return test;
}

Test maximumConnection(int n, int m, int maxQueriesSum) {
    Test test;

    // creating connection:
    intPairVec pairsVec;
    
    int currentFirst = Generator::random() % n;
    for (int j = 0; j < n; j++) {
        if (currentFirst == j) {
            continue;
        }
        pairsVec.push_back(std::make_pair(j, currentFirst));
    }

    intVecVec table = createTableFromPairs(n, pairsVec);
    intVecVec queriesForTable = createRandomQueriesForTable(table, m, maxQueriesSum, 1); 

    test.addLine(table.size());
    for (int i = 0; i < table.size(); i++) {
        test.addLine(table[i]);
    }
    test.addLine(queriesForTable.size());
    incrementQueriesElements(queriesForTable);
    intVecVec finalQueries = createProperQueriesOutput(queriesForTable);
    for (int i = 0; i < finalQueries.size(); i++) {
        test.addLine(finalQueries[i]);
    }

    return test;
}

Test zeroConnections(int n, int m, int maxQueriesSum) {
    Test test;

    // empty connection pairs vec:
    intPairVec pairsVec;

    intVecVec table = createTableFromPairs(n, pairsVec);
    intVecVec queriesForTable = createUltraSmallRandomQueriesForTable(table, m, maxQueriesSum);

    test.addLine(table.size());
    for (int i = 0; i < table.size(); i++) {
        test.addLine(table[i]);
    }
    test.addLine(queriesForTable.size());
    incrementQueriesElements(queriesForTable);
    intVecVec finalQueries = createProperQueriesOutput(queriesForTable);
    for (int i = 0; i < finalQueries.size(); i++) {
        test.addLine(finalQueries[i]);
    }

    return test;
}

intPairVec createRandomPairs(int n, int count) {
    intPairVec pairs;
    for (int i = 0; i < count; i++) {
        int first = Generator::random() % (n - 2) + 1;
        int secondDirection = Generator::random() % 2;
        int second;
        if (secondDirection == 0) {
            second = Generator::random() % first;
        } else {
            second = first + Generator::random() % (n - first - 1) + 1;
        }
        pairs.push_back(std::make_pair(first, second));
    }

    return pairs;
}

intVecVec createRandomTable(int n, int pairs) {
    intPairVec pairsVec;
    for (int i = 0; i < pairs; i++) {
        int first = Generator::random() % n;
        int second = Generator::random() % n;
        pairsVec.push_back(std::make_pair(first, second));
        if (pairsVec.back().first == pairsVec.back().second) {
            pairsVec.pop_back();
            i--;
        }
    }

    return createTableFromPairs(n, pairsVec);
}

intVecVec createTableFromPairs(int n, intPairVec pairsVec) {
    intVecVec res;
    for (int i = 0; i < n; i++) {
        intVec l;
        for (int j = 0; j < n; j++) {
            l.push_back(0);
        }
        res.push_back(l);
    }

    for (int i = 0; i < pairsVec.size(); i++) {
        res[pairsVec[i].first][pairsVec[i].second] = 1;
    }

    return res;
}

intVecVec createRandomQueriesForTable(intVecVec &table, int m, int maxSumOfQueries, int type) {

    //find candidates for each one to be popular between:
    intVec *candidatesForAll = new intVec[table.size() + 5];
    for (int i = 0; i < table.size(); i++) {
        for (int j = 0; j < table.size(); j++) {
            if (table[j][i] == 1) {
                candidatesForAll[i].push_back(j);
            }
        }
    }

    for (int i = 0; i < table.size(); i++) {
        for (int j = 0; j < candidatesForAll[i].size(); j++) {
            if (table[i][candidatesForAll[i][j]] == 1) {
                std::swap(candidatesForAll[i][j], candidatesForAll[i][candidatesForAll[i].size() - 1]);
                candidatesForAll[i].pop_back();
                j--;
            }
        }
    }

    intVecVec queries;
    int positiveQueries = 7 * m / 10;

    if (type == 2) {
        positiveQueries = m / 10;
    }

    while (queries.size() < positiveQueries && maxSumOfQueries > 0) {
        int popularId = Generator::random() % table.size();
        intVec followers;
        followers.push_back(popularId);
        int followersCount;
        if (type == 1) {
            if (candidatesForAll[popularId].size() > 1) {
                followersCount = candidatesForAll[popularId].size() - (Generator::random() % ((candidatesForAll[popularId].size() - 1) / 10 + 1));
            } else {
                continue;
            }
        } else {
            if (candidatesForAll[popularId].size() > 0) {
                followersCount = candidatesForAll[popularId].size() - (Generator::random() % ((candidatesForAll[popularId].size() - 1) / 10 + 1));
            } else {
                followersCount = 0;
            }
        }

        if (followersCount == 1 && Generator::random() % 1000 != 0) {
            continue;
        }

        std::shuffle(candidatesForAll[popularId].begin(), candidatesForAll[popularId].end(), Generator::getGen());
        for (int i = 0; i < followersCount; i++) {
            followers.push_back(candidatesForAll[popularId][i]);
        }
        std::shuffle(followers.begin(), followers.end(), Generator::getGen());
        if (followers.size() <= maxSumOfQueries) {
            queries.push_back(followers);
        }
        maxSumOfQueries -= followers.size();
    }

    while (queries.size() < m && maxSumOfQueries > 10) {
        int currentQuerySize = 9 * table.size() / 10 + Generator::random() % (std::max(table.size() / 10, (unsigned long) 1));
        if (currentQuerySize < maxSumOfQueries) {
            break;
        }
        intVec currentQuery;
        std::set<int> currentQuerySet;
        int x;
        while (currentQuerySet.size() < currentQuerySize) {
            x = Generator::random() % table.size();
            if (currentQuerySet.find(x) == currentQuerySet.end()) {
                currentQuerySet.insert(x);
                currentQuery.push_back(x);
            }
        }

        maxSumOfQueries -= currentQuerySize;
        queries.push_back(currentQuery);
    }

    delete[] candidatesForAll;
    return queries;
}

intVecVec createUltraSmallRandomQueriesForTable(intVecVec &table, int m, int maxSumOfQueries) {
    intVecVec queries;
    int moreThanSingleQueries = maxSumOfQueries - m;
    int currentSize;
    for (int i = 0; i < m; i++) {
        intVec currentQuery;
        if (Generator::random() % 2 == 0 && moreThanSingleQueries > 0) {
            currentSize = 1 + Generator::random() % 3;
            if (currentSize > moreThanSingleQueries + 1) {
                continue;
            }
            std::set<int> toCheck;
            while(currentQuery.size() < currentSize) {
                int current = Generator::random() % table.size();
                if (toCheck.find(current) == toCheck.end()) {
                    toCheck.insert(current);
                    currentQuery.push_back(current);
                }
            }
            std::shuffle(currentQuery.begin(), currentQuery.end(), Generator::getGen());
        } else {
            currentQuery.push_back(Generator::random() % table.size());
        }
        queries.push_back(currentQuery);
        moreThanSingleQueries -= currentQuery.size() - 1;
    }

    return queries;
}

void incrementQueriesElements(intVecVec &toIncrement) {
    for (int i = 0; i < toIncrement.size(); i++) {
        for (int j = 0; j < toIncrement[i].size(); j++) {
            toIncrement[i][j]++;
        }
    }
}

intVecVec createProperQueriesOutput(intVecVec toOutput) {
    intVecVec result;
    for (int i = 0; i < toOutput.size(); i++) {
        intVec current;
        current.push_back(toOutput[i].size());
        for (int j = 0; j < toOutput[i].size(); j++) {
            current.push_back(toOutput[i][j]);
        }
        result.push_back(current);
    }

    std::shuffle(result.begin(), result.end(), Generator::getGen());
    return result;
}
