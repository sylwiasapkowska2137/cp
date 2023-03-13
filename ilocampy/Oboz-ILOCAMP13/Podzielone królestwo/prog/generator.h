#ifndef ILOCAMP_GENERATOR__H
#define ILOCAMP_GENERATOR__H

#include <iostream>
#include <iomanip>
#include <random>
#include <cassert>
#include <cstdint>
#include <sstream>
#include <fstream>
#include <algorithm>
#include <iterator>

class Test {
public:
    Test();
    Test(const Test &);
    Test(Test &&) = default;
    Test &operator=(const Test &);
    Test &operator=(Test &&) = default;

    void setSeparator(const std::string &separator = " ");

    template <class T, class... Targs>
    void addLine(const T &arg, Targs &&... args);

    template <class T, class... Targs>
    void addLine(const std::vector<T> &arg, Targs &&... args);

    template <class T>
    void addLine(const T &t);

    template <class T>
    void addLine(const std::initializer_list<T> &elements);

    template <class T>
    void addLine(const std::vector<T> &elements);

    std::string str() const;
    std::ostringstream &raw();

private:
    std::string separator;
    std::ostringstream buffer;
};

class Generator {
public:
    static std::mt19937_64 &getGen();
    static void setSeed(unsigned seed);
    static std::uint32_t random();
    static std::uint64_t random64();
    static double randomDouble();  // [0.0; 1.0]

    Generator(const std::string &taskID);

    void beginGroup();
    void endGroup();
    void addTest(const Test &test);
    void generate() const;

    std::string inputPath;       // ../test
    std::string outputPath;      // ../test
    std::string exampleInPath;   // ../in
    std::string exampleOutPath;  // ../out

private:
    std::string taskID;
    bool insideGroup;
    std::vector<std::vector<Test>> tests;

    void execute(const std::string &input, const std::string &output) const;
    void createTestFile(const std::string &filename, const Test &test) const;

    std::string getInFilename(std::size_t groupIdx, std::size_t testIdx) const;
    std::string getOutFilename(std::size_t groupIdx, std::size_t testIdx) const;
    std::string getFilename(std::size_t groupIdx, std::size_t testIdx) const;
};

inline Test::Test() : separator(" ") {
}

inline void Test::setSeparator(const std::string &separator) {
    this->separator = separator;
}

inline Test::Test(const Test &that) {
    *this = that;
}

inline Test &Test::operator=(const Test &that) {
    separator = that.separator;
    buffer.str(that.str());
    return *this;
}

template <class T, class... Targs>
void Test::addLine(const T &arg, Targs &&... args) {
    buffer << arg << separator;
    addLine(std::forward<Targs>(args)...);
}

template <class T, class... Targs>
void Test::addLine(const std::vector<T> &arg, Targs &&... args) {
    std::copy(arg.begin(), arg.end(), std::ostream_iterator<T>(buffer, separator.c_str()));
    addLine(std::forward<Targs>(args)...);
}

template <class T>
void Test::addLine(const std::initializer_list<T> &elements) {
    addLine(std::vector<T>(elements));
}

template <class T>
void Test::addLine(const std::vector<T> &elements) {
    for (auto it = elements.begin(); it != elements.end();) {
        buffer << *it;
        if (++it != elements.end()) {
            buffer << separator;
        }
    }
    buffer << std::endl;
}

inline std::string Test::str() const {
    return buffer.str();
}

inline std::ostringstream &Test::raw() {
    return buffer;
}

template <class T>
void Test::addLine(const T &t) {
    buffer << t << std::endl;
}

inline Generator::Generator(const std::string &taskID) : taskID(taskID), insideGroup(false) {
    inputPath = "../test";
    outputPath = "../test";
    exampleInPath = "../in";
    exampleOutPath = "../out";
}

inline void Generator::beginGroup() {
    assert(insideGroup == false && "zagniezdzone grupy");

    insideGroup = true;
    tests.emplace_back();
}

inline void Generator::endGroup() {
    assert(insideGroup == true && "brak otwartej grupy");
    assert(!tests.back().empty() && "brak testow w grupie");

    insideGroup = false;
}

inline void Generator::addTest(const Test &test) {
    if (!insideGroup) {
        tests.emplace_back();
    }
    tests.back().push_back(test);
}

inline void Generator::generate() const {
    assert(insideGroup == false && "ostatnia grupa nie zostala zamknieta");

    std::cout << "example input : " << exampleInPath << std::endl;
    std::cout << "example output: " << exampleOutPath << std::endl;
    std::cout << "tests input   : " << inputPath << std::endl;
    std::cout << "tests output  : " << outputPath << std::endl;
    std::cout << std::endl;

    for (std::size_t groupIdx = 0; groupIdx < tests.size(); groupIdx++) {
        for (std::size_t testIdx = 0; testIdx < tests[groupIdx].size(); testIdx++) {
            std::string inFilename = getInFilename(groupIdx, testIdx);
            std::string outFilename = getOutFilename(groupIdx, testIdx);
            std::string filename = getFilename(groupIdx, testIdx);

            std::cout << filename;
            createTestFile(inFilename, tests[groupIdx][testIdx]);
            execute(inFilename, outFilename);
            std::cout << std::setw((int)(20 - filename.size())) << "Done" << std::endl;
        }
    }
}

inline std::string Generator::getInFilename(std::size_t groupIdx, std::size_t testIdx) const {
    std::string prefix = inputPath;
    if (groupIdx == 0) {
        prefix = exampleInPath;
    }
    return prefix + "/" + getFilename(groupIdx, testIdx) + ".in";
}

inline std::string Generator::getOutFilename(std::size_t groupIdx, std::size_t testIdx) const {
    std::string prefix = outputPath;
    if (groupIdx == 0) {
        prefix = exampleOutPath;
    }
    return prefix + "/" + getFilename(groupIdx, testIdx) + ".out";
}

inline std::string Generator::getFilename(std::size_t groupIdx, std::size_t testIdx) const {
    std::string filename = taskID;

    if (tests.size() > 9 && groupIdx < 10 && groupIdx != 0) {
        filename += "0";
    }
    filename += std::to_string(groupIdx);

    if (tests[groupIdx].size() > 1) {
        filename += 'a' + testIdx;
    }

    return filename;
}

inline void Generator::execute(const std::string &input, const std::string &output) const {
    std::string binName = taskID + "zad";

    char buf[256];
    sprintf(buf, "./%s < %s > %s", binName.c_str(), input.c_str(), output.c_str());
    fprintf(stderr, "%s\n", buf);
    if (system(buf)) {
        assert(false);
    }
}

inline void Generator::createTestFile(const std::string &filename, const Test &test) const {
    std::ofstream ofstream(filename);
    ofstream << test.str();
    ofstream.close();
}

inline void Generator::setSeed(unsigned seed) {
    getGen().seed(seed);
}

inline std::uint32_t Generator::random() {
    return getGen()() % UINT32_MAX;
}

inline std::uint64_t Generator::random64() {
    return getGen()();
}

inline double Generator::randomDouble() {
    return getGen()() / (double)UINT64_MAX;
}

inline std::mt19937_64 &Generator::getGen() {
    static std::mt19937_64 *gen = nullptr;
    if (!gen) {
        gen = new std::mt19937_64;
    }
    return *gen;
}

#endif
