#include "generator.h"

#include <memory>
#include <set>
#include <utility>
#include <vector>
#include <queue>
#include <sys/time.h>
#include <cstdlib>

template <class F, class S>
std::ostream &operator<<(std::ostream &os, const std::pair<F, S> &pair) {
    os << pair.first << " " << pair.second;
    return os;
}

using graph_t = std::vector<std::pair<int, int>>;
using namespace std;

int random(int a, int b) 
{
    return Generator::random() % (b - a + 1) + a;
}

Test generateTest(int a, int b)
{
  Test test;
  test.addLine(random(a,b));
  return test;
}

Test exampleTest() 
{
    Test test;
    test.addLine(2);
    return test;
}

int main() 
{
    Generator gen("tel");
    int seed = 32508423;
    
    gen.beginGroup();
    gen.addTest(exampleTest());
    gen.endGroup();

    for(int i = 0; i <= 30; i++)
    {
      gen.beginGroup();
      gen.addTest(generateTest(i,i));
      gen.endGroup();
    }
    
    for(int i = 1; i <= 4; i++)
    {
      Generator::setSeed(seed * i);
      gen.beginGroup();
      gen.addTest(generateTest(100, 1000));
      gen.endGroup();
    }
    
    gen.generate();
}



