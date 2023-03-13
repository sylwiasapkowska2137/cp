#include "generator.h"

#include <memory>

template <class F, class S>
std::ostream &operator<<(std::ostream &os, const std::pair<F, S> &pair) {
    os << pair.first << " " << pair.second;
    return os;
}

using graph_t = std::vector<std::pair<int, int>>;

const int MINN = 2;
const int MAXN = 3 * 100 * 1000;
const int MAXABC = 1000 * 1000;

Test exampleTest();
Test uniqueCase(int,int);
Test specialCase1_1(int,int);
Test specialCase1_2(int,int);
Test specialCase2_1(int,int);
Test specialCase2_2(int,int);
Test randomCase(int,int);


int main() 
{
    Generator gen("tmg");

    //0
    gen.beginGroup();
    {
        gen.addTest(exampleTest());
    }
    gen.endGroup();
    
    //Unique numbers
    //1 
    gen.beginGroup();
    {
        Generator::setSeed(1980891);
        gen.addTest(uniqueCase(10, 40));
    }
    gen.endGroup();
    
    //Repeating numbers
    //2
    gen.beginGroup();
    {
        Generator::setSeed(2310132);
        gen.addTest(specialCase1_1(10,20));
        Generator::setSeed(2311132);
        gen.addTest(specialCase1_2(10,20));
        Generator::setSeed(2312132);
        gen.addTest(specialCase2_1(10,20));
        Generator::setSeed(2313132);
        gen.addTest(specialCase2_2(10,20));
        Generator::setSeed(2314132);
        gen.addTest(randomCase(10,20));
    }
    gen.endGroup();
    
    //Unique numbers    
    //2
    gen.beginGroup();
    {
        Generator::setSeed(3030303);
        gen.addTest(uniqueCase(1000, 4000));
    }
    gen.endGroup();
    
    //Repeating numbers
    //4
    gen.beginGroup();
    {
        Generator::setSeed(4040404);
        gen.addTest(specialCase1_1(1000,2000));
        Generator::setSeed(4041404);
        gen.addTest(specialCase1_2(1000,2000));
        Generator::setSeed(4042404);
        gen.addTest(specialCase2_1(1000,2000));
        Generator::setSeed(4043404);
        gen.addTest(specialCase2_2(1000,2000));
        Generator::setSeed(4044404);
        gen.addTest(randomCase(1000,2000));
    }
    gen.endGroup();
    
    //Complexity (n log n) or (n) passes
    
    //Unique numbers
    //5
    gen.beginGroup();
    {
        Generator::setSeed(5050505);
        gen.addTest(uniqueCase(MAXN, MAXABC));
    }
    gen.endGroup();
    
    //Unique numbers    
    //6
    gen.beginGroup();
    {
        Generator::setSeed(6606066);
        gen.addTest(uniqueCase(MAXN, MAXABC));
    }
    gen.endGroup();
    
    //Unique numbers    
    //7
    gen.beginGroup();
    {
        Generator::setSeed(7770777);
        gen.addTest(uniqueCase(MAXN, MAXABC));
    }
    gen.endGroup();
    
    //Repeating numbers
    //8
    gen.beginGroup();
    {
        Generator::setSeed(8080808);
        gen.addTest(specialCase1_1(MAXN, MAXABC));
        Generator::setSeed(8081808);
        gen.addTest(specialCase1_2(MAXN, MAXABC));
        Generator::setSeed(8082808);
        gen.addTest(specialCase2_1(MAXN, MAXABC));
        Generator::setSeed(8083808);
        gen.addTest(specialCase2_2(MAXN, MAXABC));
        Generator::setSeed(8084808);
        gen.addTest(randomCase(MAXN, MAXABC));
    }
    gen.endGroup();
    
    //Repeating numbers    
    //9
    gen.beginGroup();
    {
        Generator::setSeed(9990999);
        gen.addTest(specialCase1_1(MAXN, MAXABC));
        Generator::setSeed(9991999);
        gen.addTest(specialCase1_2(MAXN, MAXABC));
        Generator::setSeed(9992999);
        gen.addTest(specialCase2_1(MAXN, MAXABC));
        Generator::setSeed(9993999);
        gen.addTest(specialCase2_2(MAXN, MAXABC));
        Generator::setSeed(9994999);
        gen.addTest(randomCase(MAXN, MAXABC));
    }
    gen.endGroup();
    
    //Repeating numbers    
    //10
    gen.beginGroup();
    {
        Generator::setSeed(1010101);
        gen.addTest(specialCase1_1(MAXN, MAXABC));
        Generator::setSeed(1011101);
        gen.addTest(specialCase1_2(MAXN, MAXABC));
        Generator::setSeed(1012101);
        gen.addTest(specialCase2_1(MAXN, MAXABC));
        Generator::setSeed(1013201);
        gen.addTest(specialCase2_2(MAXN, MAXABC));
        Generator::setSeed(1014101);
        gen.addTest(randomCase(MAXN, MAXABC));
    }
    gen.endGroup();


    gen.generate();
}

using namespace std;

int random(int a, int b);

Test exampleTest() 
{
    Test test;
    test.addLine(6);
    test.addLine(5, 1 ,3);
    test.addLine(2, 3, 2);
    test.addLine(6, 4, 10);
    test.addLine(1, 7, 6);
    test.addLine(3, 5, 4);
    test.addLine(20, 3, 6);
    return test;
}

Test uniqueCase (int n, int maxABC)
{
    Test test;
    vector <int> V(maxABC);
    iota(V.begin(), V.end(), 1);
    random_shuffle(V.begin(), V.end());
    test.addLine(n);
    for(int i = 1; i <= n; i++)
    {
        int a = V.back();
        V.pop_back();
        int b = V.back();
        V.pop_back();
        int c = V.back();
        V.pop_back();
        
        test.addLine(a,b,c);
    }
    return test;
}

Test specialCase1_1(int n, int maxABC)
{
    Test test;
    test.addLine(n);
    test.addLine(maxABC, maxABC, maxABC);
    for(int i = 2; i <= n - 1; i++)
    {
        test.addLine( random(1, maxABC - 1), random(1, maxABC - 1), random(1, maxABC - 1) );
    }
    test.addLine(maxABC, maxABC - 1, maxABC);
    return test;
}

Test specialCase1_2(int n, int maxABC)
{
    Test test;
    test.addLine(n);
    test.addLine(maxABC, maxABC, maxABC);
    for(int i = 2; i <= n - 1; i++)
    {
        test.addLine( random(1, maxABC - 1), random(1, maxABC - 1), random(1, maxABC - 1) );
    }
    test.addLine(maxABC, maxABC, maxABC);
    return test;
}

Test specialCase2_1(int n, int maxABC)
{
    Test test;
    test.addLine(n);
    test.addLine(maxABC, maxABC - 3, maxABC - 3);
    for(int i = 2; i <= n - 1; i++)
    {
        test.addLine( random(1, maxABC - 3), random(1, maxABC - 3), random(1, maxABC - 3) );
    }
    test.addLine(maxABC - 2, maxABC - 3, maxABC - 3);
    return test;
}

Test specialCase2_2(int n, int maxABC)
{
    Test test;
    test.addLine(n);
    test.addLine(maxABC, maxABC - 3, maxABC - 3);
    for(int i = 2; i <= n - 1; i++)
    {
        test.addLine( random(1, maxABC - 3), random(1, maxABC - 3), random(1, maxABC - 3) );
    }
    test.addLine(maxABC, maxABC - 3, maxABC - 3);
    return test;
}

Test randomCase(int n, int maxABC)
{
    Test test;
    test.addLine(n);
    for(int i = 1; i <= n; i++)
    {
        test.addLine( random(1, maxABC), random(1, maxABC), random(1, maxABC) );
    }
    return test;
}


int random(int a, int b) 
{
    return Generator::random() % (b - a + 1) + a;
}
