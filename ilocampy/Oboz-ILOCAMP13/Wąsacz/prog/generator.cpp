#include "generator.h"

#include <memory>

template <class F, class S>
std::ostream &operator<<(std::ostream &os, const std::pair<F, S> &pair) {
    os << pair.first << " " << pair.second;
    return os;
}

using namespace std;
using graph_t = std::vector<std::pair<int, int>>;

const int MIN_N = 1;
const int MAX_N = 300 * 1000;
const int MAX_Q = 500 * 1000;
const int MAX_C = 1000 * 1000;

Test exampleTest();

int main() 
{
    Generator gen("was");

    gen.beginGroup();
    gen.addTest(exampleTest());
    gen.endGroup();
    
    gen.generate();
}

Test exampleTest()
{
    Test test;
    test.addLine(5, 10, 5);
    test.addLine(3, 10);
    test.addLine(8, 5);
    test.addLine(4, 18);
    test.addLine(2, 20);
    test.addLine(7, 11);
    return test;
}