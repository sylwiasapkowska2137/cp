#include "generator.h"

#include <memory>
#include <set>
#include <cstdlib>

template <class F, class S>
std::ostream &operator<<(std::ostream &os, const std::pair<F, S> &pair) {
    os << pair.first << " " << pair.second;
    return os;
}

using museumItems = std::vector<int>;

Test exampleTest();

Test cornerSmall();
Test cornerNegative();
Test cornerRedundant();
Test cornerSame();
Test cornerDifferentLength();

Test positiveNoRedundant(int count1, int count2, int maxVal);
Test positiveRedundant(int count1, int count2, int maxVal, int redundaceLevel);
Test positiveRepetitions(int count1, int count2, int maxVal);
Test negative(int count1, int count2, int maxVal);
Test negativeRepetitions(int count1, int count2, int maxVal);

Test smallResultFromBigNums(int count1, int count2, int maxVal);

Test fullRandom(int count1, int count2, int maxVal);

int main() {
    Generator gen("muz");

    gen.beginGroup();
    gen.addTest(exampleTest());
    gen.endGroup();

    
    // 1
    gen.beginGroup();
    {
        gen.addTest(cornerSmall());
        Generator::setSeed(42131);
        gen.addTest(positiveNoRedundant(5, 5, 10));
    }
    gen.endGroup();

    // 2
    gen.beginGroup();
    {
        gen.addTest(cornerRedundant());
        Generator::setSeed(534223);
        gen.addTest(negative(10, 15, 50));
    }
    gen.endGroup();

    // 3
    gen.beginGroup();
    {
        gen.addTest(cornerNegative());
        Generator::setSeed(555511);
        gen.addTest(positiveRedundant(60, 50, 1000, 5));
    }
    gen.endGroup();

    // 4
    gen.beginGroup();
    {
        gen.addTest(cornerSame());
        Generator::setSeed(2232323);
        gen.addTest(negativeRepetitions(80, 100, 1000));
    }
    gen.endGroup();

    // 5
    gen.beginGroup();
    {
        gen.addTest(cornerDifferentLength());
        Generator::setSeed(989123);
        gen.addTest(fullRandom(2000, 2000, 2000));
    }
    gen.endGroup();

    // 6
    gen.beginGroup();
    {
        Generator::setSeed(123854);
        gen.addTest(positiveRepetitions(10 * 1000, 10 * 1000, 50 * 1000));
        Generator::setSeed(11122223);
        gen.addTest(negative(15 * 1000, 15 * 1000, 30 * 1000));
    }
    gen.endGroup();

    // 7
    gen.beginGroup();
    {
        Generator::setSeed(149329);
        gen.addTest(positiveNoRedundant(150 * 1000, 100 * 1000, 300 * 1000));
        Generator::setSeed(18123);
        gen.addTest(negativeRepetitions(100 * 1000, 95 * 1000, 300 * 1000));
    }
    gen.endGroup();

    // 8
    gen.beginGroup();
    {
        Generator::setSeed(7686512);
        gen.addTest(smallResultFromBigNums(140 * 1000, 180 * 1000, 255 * 1000));
        Generator::setSeed(665544);
        gen.addTest(fullRandom(180 * 1000, 210 * 1000, 250 * 1000 + 123));
    }
    gen.endGroup();
    
    // 9
    gen.beginGroup();
    {
        Generator::setSeed(4213501);
        gen.addTest(negative(200 * 1000, 5 * 1000, 300 * 1000));
        Generator::setSeed(98212111);
        gen.addTest(positiveRedundant(290 * 1000, 290 * 1000, 300 * 1000, 2));
    }
    gen.endGroup();

    // 10
    gen.beginGroup();
    {
        Generator::setSeed(456621);
        gen.addTest(smallResultFromBigNums(300 * 1000, 300 * 1000, 300 * 1000));
        Generator::setSeed(521112);
        gen.addTest(positiveNoRedundant(300 * 1000, 300 * 1000, 230 * 1000 + 321));
    }
    gen.endGroup();

    gen.generate();
}

Test generateTestFrom(museumItems &firstMuseum, museumItems &secondMuseum);
museumItems generateWithRepetitions(museumItems &baseToRepeat, int finalSize);
int randomIntMod(int mod);

Test exampleTest() {
    Test test;
    test.addLine(4, 5);
    test.addLine(2, 2, 4, 6);
    test.addLine(3, 7, 3, 4, 5);
    return test;
}

Test cornerSmall() {
    Test test;
    test.addLine(1, 1);
    test.addLine(1);
    test.addLine(1);
    return test;
}

Test cornerNegative() {
    Test test;
    test.addLine(1, 1);
    test.addLine(1);
    test.addLine(2);
    return test;
}

Test cornerRedundant() {
    Test test;
    test.addLine(4, 4);
    test.addLine(2, 4, 6, 8);
    test.addLine(1, 3, 5, 8);
    return test;
}

Test cornerSame() {
    Test test;
    test.addLine(3, 3);
    test.addLine(1, 1, 1);
    test.addLine(1, 1, 1);
    return test;
}

Test cornerDifferentLength() {
    Test test;
    test.addLine(1, 10);
    test.addLine(5);
    test.addLine(1, 2, 3, 4, 5, 6, 7, 8, 9, 10);
    return test;
}

Test positiveNoRedundant(int count1, int count2, int maxVal) {
    museumItems muzeum1, muzeum2;
    museumItems baseItems;
    int valuesCount = std::min(count1, count2) - (std::min(count1 / 3, count2 / 3));

    for (int i = 0; i < valuesCount; i++) {
        baseItems.push_back(Generator::random() % maxVal + 1);
    }

    for (int i = 0; i < valuesCount; i++) {
        muzeum1.push_back(baseItems[i]);
    }
    while (muzeum1.size() < count1) {
        muzeum1.push_back(baseItems[Generator::random() % baseItems.size()]);
    }
    std::shuffle(muzeum1.begin(), muzeum1.end(), Generator::getGen());

    for (int i = 0; i < valuesCount; i++) {
        muzeum2.push_back(baseItems[i]);
    }
    while (muzeum2.size() < count2) {
        muzeum2.push_back(baseItems[Generator::random() % baseItems.size()]);
    }
    std::shuffle(muzeum2.begin(), muzeum2.end(), Generator::getGen());

    return generateTestFrom(muzeum1, muzeum2);
}

// redundance level: 1 - 10 (1 is almost all redundant, 10 is almost no redundance)
Test positiveRedundant(int count1, int count2, int maxVal, int redundanceLevel) {
    museumItems muzeum1, muzeum2;
    museumItems baseItems1, baseItems2;

    int noRedundantCount = (redundanceLevel - 1) * (std::min(count1, count2) / 10) + (Generator::random() % (std::min(count1, count2) / 10) + 1) + 1;
    museumItems noRedundantItems;
    std::set<int> noRedundantUnique;

    int current;
    while (noRedundantItems.size() < noRedundantCount) {
        current = Generator::random() % maxVal + 1;
        if ((noRedundantUnique.insert(current)).second == true) {
            noRedundantItems.push_back(current);
        }
    }

    int base1 = Generator::random() % (count1 - noRedundantCount) + 1;
    int base2 = Generator::random() % (count2 - noRedundantCount) + 1;

    std::set<int> unique1;
    while (baseItems1.size() < base1) {
        current = Generator::random() % maxVal + 1;
        if (noRedundantUnique.find(current) == noRedundantUnique.end()) {
            baseItems1.push_back(current);
            unique1.insert(baseItems1.back());
        }
    }
    muzeum1 = generateWithRepetitions(baseItems1, count1 - noRedundantCount);
    for (int item : noRedundantItems) {
        muzeum1.push_back(item);
    }
    std::shuffle(muzeum1.begin(), muzeum1.end(), Generator::getGen());

    while (baseItems2.size() < base2) {
        current = Generator::random() % maxVal + 1;
        if (unique1.find(current) == unique1.end() && noRedundantUnique.find(current) == noRedundantUnique.end()) {
            baseItems2.push_back(current);
        }
    }
    muzeum2 = generateWithRepetitions(baseItems2, count2 - noRedundantCount);
    for (int item : noRedundantItems) {
        muzeum2.push_back(item);
    }
    std::shuffle(muzeum2.begin(), muzeum2.end(), Generator::getGen());

    return generateTestFrom(muzeum1, muzeum2);
}

Test positiveRepetitions(int count1, int count2, int maxVal) {
    museumItems muzeum1, muzeum2;
    museumItems baseVals;
    int differentVals = Generator::random() % (std::min(count1 / 10, count2 / 10) + 1);
    for (int i = 0; i < differentVals; i++) {
        baseVals.push_back(Generator::random() % maxVal + 1);
    }

    for (int i = 0; i < count1; i++) {
        muzeum1.push_back(baseVals[Generator::random() % baseVals.size()]);
    }
    for (int i = 0; i < count2; i++) {
        muzeum2.push_back(baseVals[Generator::random() % baseVals.size()]);
    }

    return generateTestFrom(muzeum1, muzeum2);
}

Test negative(int count1, int count2, int maxVal) {
    museumItems muzeum1, muzeum2;
    std::set<int> unique1;
    for (int i = 0; i < count1; i++) {
        muzeum1.push_back(Generator::random() % maxVal + 1);
        unique1.insert(muzeum1.back());
    }

    int current;
    while(muzeum2.size() < count2) {
        current = Generator::random() % maxVal + 1;
        if (unique1.find(current) == unique1.end()) {
            muzeum2.push_back(current);
        }
    }

    return generateTestFrom(muzeum1, muzeum2);
}

Test negativeRepetitions(int count1, int count2, int maxVal) {
    int base1 = Generator::random() % (count1 / 2) + 5;
    int base2 = Generator::random() % (count2 / 2) + 5;

    museumItems muzeum1, muzeum2;
    museumItems baseItems1, baseItems2;
    std::set<int> unique1;
    for (int i = 0; i < base1; i++) {
        baseItems1.push_back(Generator::random() % maxVal + 1);
        unique1.insert(baseItems1.back());
    }
    muzeum1 = generateWithRepetitions(baseItems1, count1);

    int current;
    while (baseItems2.size() < base2) {
        current = Generator::random() % maxVal + 1;
        if (unique1.find(current) == unique1.end()) {
            baseItems2.push_back(current);
        }
    }
    muzeum2 = generateWithRepetitions(baseItems2, count2);

    return generateTestFrom(muzeum1, muzeum2);
}

Test smallResultFromBigNums(int count1, int count2, int maxVal) {
    museumItems muzeum1, muzeum2;
    museumItems baseItems1, baseItems2;

    int noRedundantCount = std::min(count1, count2) / 10 + 1;
    museumItems noRedundantItems;
    std::set<int> noRedundantUnique;

    int current;
    while (noRedundantItems.size() < noRedundantCount) {
        current = Generator::random() % (maxVal / 5) + 1;
        if ((noRedundantUnique.insert(current)).second == true) {
            noRedundantItems.push_back(current);
        }
    }

    int base1 = Generator::random() % (count1 - noRedundantCount) + 1;
    int base2 = Generator::random() % (count2 - noRedundantCount) + 1;

    std::set<int> unique1;
    while (baseItems1.size() < base1) {
        current = Generator::random() % maxVal + 1;
        if (noRedundantUnique.find(current) == noRedundantUnique.end()) {
            baseItems1.push_back(current);
            unique1.insert(baseItems1.back());
        }
    }
    muzeum1 = generateWithRepetitions(baseItems1, count1 - noRedundantCount);
    for (int item : noRedundantItems) {
        muzeum1.push_back(item);
    }
    std::shuffle(muzeum1.begin(), muzeum1.end(), Generator::getGen());

    while (baseItems2.size() < base2) {
        current = Generator::random() % maxVal + 1;
        if (unique1.find(current) == unique1.end() && noRedundantUnique.find(current) == noRedundantUnique.end()) {
            baseItems2.push_back(current);
        }
    }
    muzeum2 = generateWithRepetitions(baseItems2, count2 - noRedundantCount);
    for (int item : noRedundantItems) {
        muzeum2.push_back(item);
    }
    std::shuffle(muzeum2.begin(), muzeum2.end(), Generator::getGen());

    return generateTestFrom(muzeum1, muzeum2);
}

Test fullRandom(int count1, int count2, int maxVal) {
    museumItems muzeum1, muzeum2;
    for (int i = 0; i < count1; i++) {
        muzeum1.push_back(Generator::random() % maxVal + 1);
    }

    for (int i = 0; i < count2; i++) {
        muzeum2.push_back(Generator::random() % maxVal + 1);
    }

    return generateTestFrom(muzeum1, muzeum2);
}

Test generateTestFrom(museumItems &firstMuseum, museumItems &secondMuseum) {
    Test test;
    test.addLine(firstMuseum.size(), secondMuseum.size());
    test.addLine(firstMuseum);
    test.addLine(secondMuseum);
    return test;
}

museumItems generateWithRepetitions(museumItems &baseToRepeat, int finalSize) {
    museumItems result;

    while (result.size() < finalSize) {
        result.push_back(baseToRepeat[Generator::random() % baseToRepeat.size()]);
    }

    return result;
}

int randomIntMod(int mod) {
    return Generator::random() % mod;
}
