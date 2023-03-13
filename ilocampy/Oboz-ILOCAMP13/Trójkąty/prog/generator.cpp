#include "generator.h"

#include <memory>
#include <set>
#include <utility>
#include <vector>
#include <queue>
#include <algorithm>
#define ALL(x) (x).begin(),(x).end()

template <class F, class S>
std::ostream &operator<<(std::ostream &os, const std::pair<F, S> &pair) {
    os << pair.first << " " << pair.second;
    return os;
}

using graph_t = std::vector<std::pair<int, int>>;
using namespace std;

const int maxVal = 500;

vector <int> V(4);

Test exampleTest();

Test zeroAreaCase1();
Test zeroAreaCase2();
Test equalCase();
Test firstCase1();
Test firstCase2();
Test secondCase();
Test easyCase();
Test nopeCase();

int random(int a, int b) 
{
    return Generator::random() % (b - a + 1) + a;
}

int main() 
{
    Generator gen("trk");

    gen.beginGroup();
    gen.addTest(exampleTest());
    gen.endGroup();
    
    //1
    gen.beginGroup();
    {
        Generator::setSeed(1231321);
        gen.addTest( zeroAreaCase1() );
        Generator::setSeed(1123211);
        gen.addTest( firstCase1() );
        Generator::setSeed(1643321);
        gen.addTest( firstCase1() );
        
    }
    gen.endGroup();
    
    //2
    gen.beginGroup();
    {
        Generator::setSeed(2355213);
        gen.addTest( zeroAreaCase2() );
        Generator::setSeed(2234568);
        gen.addTest( firstCase2() );
        Generator::setSeed(2878964);
        gen.addTest( firstCase2() );
        
    }
    gen.endGroup();
    
    //3
    gen.beginGroup();
    {
        Generator::setSeed(3456787);
        gen.addTest( nopeCase() );
        Generator::setSeed(7843215);
        gen.addTest( secondCase() );
        Generator::setSeed(4632156);
        gen.addTest( secondCase() );
    }
    gen.endGroup();
    
    //4
    gen.beginGroup();
    {
        Generator::setSeed(5467312);
        gen.addTest( nopeCase() );
        Generator::setSeed(3187645);
        gen.addTest( easyCase() );
        Generator::setSeed(9463135);
        gen.addTest( easyCase() );
    }
    gen.endGroup();
    
    //5
    gen.beginGroup();
    {
        Generator::setSeed(8645312);
        gen.addTest( nopeCase() );
        Generator::setSeed(6572134);
        gen.addTest( equalCase() );
        Generator::setSeed(2345623);
        gen.addTest( equalCase() );
    }
    gen.endGroup();
    
    gen.generate();
}

using namespace std;

Test exampleTest() 
{
    Test test;
    test.addLine(8, 3, 5, 4);
    return test;
}

Test zeroAreaCase1()
{
    V[0] = 1 + Generator::random() % maxVal;
    V[1] = 1 + Generator::random() % maxVal;
    V[2] = V[0] + V[1];
    V[3] = V[2] + V[1] + Generator::random() % maxVal;
    
    random_shuffle(ALL(V));
    Test test;
    test.addLine(V);
    return test;
}


Test zeroAreaCase2()
{
    V[0] = 1 + Generator::random() % maxVal;
    V[1] = 1 + Generator::random() % maxVal;
    V[2] = V[0] + V[1];
    V[3] = 1 + Generator::random() % ( V[2] - V[0] - 4 );
    
    random_shuffle(ALL(V));
    Test test;
    test.addLine(V);
    return test;
}

Test firstCase1()
{
    V[0] = 4 + Generator::random() % maxVal;
    V[1] = V[0] + Generator::random() % 4;
    V[2] = V[1] + Generator::random() % 4;
    V[3] = 10 * V[2];
    
    random_shuffle(ALL(V));
    Test test;
    test.addLine(V);
    return test;
    
}

Test firstCase2()
{
    V[0] = 1 + Generator::random() % 5;
    V[1] = (5 + Generator::random() % 3) * V[0] + Generator::random() % 10;
    V[2] = V[1] + Generator::random() % 7;
    V[3] = V[2] + Generator::random() % 7;
    
    random_shuffle(ALL(V));
    Test test;
    test.addLine(V);
    return test;    
}

Test secondCase()
{
    V[0] = V[1] = 1 + Generator::random() % maxVal;
    V[2] = V[3] = V[0] * 10 + Generator::random() % maxVal;
    
    random_shuffle(ALL(V));
    Test test;
    test.addLine(V);
    return test;    
}

Test equalCase()
{
    V[0] = V[1] = V[2] = V[3] = 1 + Generator::random() % maxVal;
    
    Test test;
    test.addLine(V);
    return test;
}

Test easyCase()
{
    V[0] = 1 + Generator::random() % maxVal;
    V[1] = 1 + Generator::random() % maxVal;
    V[2] = random( abs(V[0] - V[1]) + 1, V[0] + V[1] - 1); 
    V[3] = 1 + Generator::random() % maxVal;
    
    random_shuffle(ALL(V));
    Test test;
    test.addLine(V);
    return test;
}

Test nopeCase()
{
    V[0] = 1 + Generator::random() % maxVal;
    V[1] = V[0] * (2 + Generator::random() % 3) + Generator::random() % maxVal;
    V[2] = V[1] * (2 + Generator::random() % 3) + Generator::random() % maxVal;
    V[3] = V[2] * (2 + Generator::random() % 3) + Generator::random() % maxVal;
    
    random_shuffle(ALL(V));
    Test test;
    test.addLine(V);
    return test;
}