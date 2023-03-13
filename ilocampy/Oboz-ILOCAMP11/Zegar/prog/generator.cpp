#include "generator.h"

#include <memory>
#include <cstdio>
#include <string>

template <class F, class S>
std::ostream &operator<<(std::ostream &os, const std::pair<F, S> &pair) {
    os << pair.first << " " << pair.second;
    return os;
}

const int fullDay = 24 * 60;
using timePair = std::pair<int, int>;

Test exampleTest();

Test simpleRandom();
Test underHourRandom();
Test shortRandom();
Test averageRandom();
Test longRandom();
Test equalRandom();
Test maximumRandom();
Test throughMidnightRandom();
Test throughMidnightShort();
Test throughMidnightAverage();
Test throughMidnightLong();
Test throughMidnightMaximum();


int main() {
    Generator gen("zeg");

    gen.beginGroup();
    gen.addTest(exampleTest());
    gen.endGroup();

    // 1
    gen.beginGroup();
    {
        Generator::setSeed(12345);
        gen.addTest(underHourRandom());
        Generator::setSeed(23456);
        gen.addTest(underHourRandom());
        Generator::setSeed(34567);
        gen.addTest(shortRandom());
    }
    gen.endGroup();

    // 2
    gen.beginGroup();
    {
        Generator::setSeed(45434);
        gen.addTest(shortRandom());
        Generator::setSeed(555124);
        gen.addTest(averageRandom());
        Generator::setSeed(63242);
        gen.addTest(averageRandom());
    }
    gen.endGroup();

    // 3
    gen.beginGroup();
    {
        Generator::setSeed(66434);
        gen.addTest(averageRandom());
        Generator::setSeed(5551123);
        gen.addTest(longRandom());
        Generator::setSeed(232131);
        gen.addTest(longRandom());
    }
    gen.endGroup();

    // 4
    gen.beginGroup();
    {
        Generator::setSeed(79281);
        gen.addTest(longRandom());
        Generator::setSeed(311231);
        gen.addTest(maximumRandom());
        Generator::setSeed(5524123);
        gen.addTest(equalRandom());
    }
    gen.endGroup();

    // 5
    gen.beginGroup();
    {
        Generator::setSeed(98918123);
        gen.addTest(maximumRandom());
        Generator::setSeed(878123);
        gen.addTest(maximumRandom());
        Generator::setSeed(9889891);
        gen.addTest(maximumRandom());
    }
    gen.endGroup();

    // 6
    gen.beginGroup();
    {
        Generator::setSeed(123854);
        gen.addTest(simpleRandom());
        Generator::setSeed(99912221);
        gen.addTest(throughMidnightShort());
        Generator::setSeed(88787771);
        gen.addTest(throughMidnightShort());
    }
    gen.endGroup();

    // 7
    gen.beginGroup();
    {
        Generator::setSeed(149329);
        gen.addTest(longRandom());
        Generator::setSeed(777127);
        gen.addTest(throughMidnightAverage());
        Generator::setSeed(341241);
        gen.addTest(throughMidnightLong());
    }
    gen.endGroup();

    // 8
    gen.beginGroup();
    {
        Generator::setSeed(7686512);
        gen.addTest(throughMidnightLong());
        Generator::setSeed(3334441);
        gen.addTest(throughMidnightMaximum());
        Generator::setSeed(888123);
        gen.addTest(maximumRandom());
    }
    gen.endGroup();

    gen.generate();
}

std::string writeTime(int minutes);
std::string writeTime(int hours, int minutes);
timePair generatePair(bool throughMidnight, int minDiff, int maxDiff);

Test exampleTest() {
    Test test;
    test.addLine("09:30");
    test.addLine("12:15");
    return test;
}

Test simpleRandom() {
    Test test;
    timePair input = generatePair(false, 1, fullDay - 1);
    test.addLine(writeTime(input.first));
    test.addLine(writeTime(input.second));
    return test;
}

Test underHourRandom() {
    Test test;
    timePair input = generatePair(false, 1, 59);
    test.addLine(writeTime(input.first));
    test.addLine(writeTime(input.second));
    return test;
}

Test shortRandom() {
    Test test;
    timePair input = generatePair(false, 30, 179);
    test.addLine(writeTime(input.first));
    test.addLine(writeTime(input.second));
    return test;
}

Test averageRandom() {
    Test test;
    timePair input = generatePair(false, fullDay / 4, 3 * fullDay / 4);
    test.addLine(writeTime(input.first));
    test.addLine(writeTime(input.second));
    return test;
}

Test longRandom() {
    Test test;
    timePair input = generatePair(false, fullDay / 2, fullDay - 1);
    test.addLine(writeTime(input.first));
    test.addLine(writeTime(input.second));
    return test;
}

Test equalRandom() {
    Test test;
    int bothTimes = Generator::random() % fullDay;
    test.addLine(writeTime(bothTimes));
    test.addLine(writeTime(bothTimes));
    return test;
}

Test maximumRandom() {
    Test test;
    timePair input = generatePair(false, fullDay - 5, fullDay - 1);
    test.addLine(writeTime(input.first));
    test.addLine(writeTime(input.second));
    return test;
}

Test throughMidnightRandom() {
    Test test;
    timePair input = generatePair(true, 1, fullDay - 1);
    test.addLine(writeTime(input.first));
    test.addLine(writeTime(input.second));
    return test;
}

Test throughMidnightShort() {
    Test test;
    timePair input = generatePair(true, 1, 179);
    test.addLine(writeTime(input.first));
    test.addLine(writeTime(input.second));
    return test;
}

Test throughMidnightAverage() {
    Test test;
    timePair input = generatePair(false, fullDay / 4, 3 * fullDay / 4);
    test.addLine(writeTime(input.first));
    test.addLine(writeTime(input.second));
    return test;
}

Test throughMidnightLong() {
    Test test;
    timePair input = generatePair(true, fullDay / 2 , fullDay - 1);
    test.addLine(writeTime(input.first));
    test.addLine(writeTime(input.second));
    return test;
}

Test throughMidnightMaximum() {
    Test test;
    timePair input = generatePair(true, fullDay - 5, fullDay - 1);
    test.addLine(writeTime(input.first));
    test.addLine(writeTime(input.second));
    return test;
}

std::string writeTime(int minutes) {
    char result[16];
    sprintf(result, "%02d:%02d", minutes / 60, minutes % 60);

    return std::string(result);
}

std::string writeTime(int hours, int minutes) {
    return writeTime(hours * 60 + minutes);
}

timePair generatePair(bool throughMidnight, int minDiff, int maxDiff) {
    std::pair<int, int> result;

    int length = minDiff + (Generator::random() %  (maxDiff - minDiff));
    
    int begin, end;
    if (!throughMidnight) {
        begin = Generator::random() % (fullDay - length);
        end = begin + length;
    } else {
        begin = (fullDay - length + 1) + (Generator::random() % length);
        end = begin + length - fullDay;
    }
    result.first = begin;
    result.second = end;

    return result;
}




