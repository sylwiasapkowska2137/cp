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

Test exampleTest() 
{
    Test test;
    test.addLine(6, 6);
    test.addLine(4, 3, 9, 3, 7, 3);
    test.addLine(3, 6);
    test.addLine(5, 1);
    test.addLine(6, 4);
    test.addLine(4, 1);
    test.addLine(2, 4);
    test.addLine(1, 5, 1);
    test.addLine(1, 4, 6);
    test.addLine(1, 5, 4);
    test.addLine(2, 6, 2);
    test.addLine(3, 1);
    test.addLine(1, 5, 1);
    return test;
}

Test randomTest(int n, int q, int cNormal, int cQuery, bool allOperations = true, int chance1 = 5, int chance2 = 2, int chance3 = 3)
{
    Test test;
    test.addLine(n, q);
    vector <int> V(n, 0);
    
    for(int i = 0; i < n; i++)
    {
        V[i] = 1 + Generator::random() % cNormal;
    }
    test.addLine(V);
    
    iota(V.begin(), V.end(), 1);
    random_shuffle(V.begin(), V.end());
    vector <int> Temp(1, 1);
    
    while(!V.empty())
    {
        if(V.back() != 1)
        {
            test.addLine(V.back(), Temp[Generator::random() % Temp.size()]);
            Temp.push_back(V.back());
        }
        V.pop_back();
    }
    
    int cnt = 0;
    while(q--)
    {
        int chanceSum = chance1 + chance2 * allOperations + chance3 * (cnt != 0);
    
        int type1begin = 0, type1end = chance1 - 1;
        int type2begin = type1end + 1, type2end = type2begin + chance2 * allOperations - 1;
        int type3begin = type2end + 1, type3end = type3begin + chance3 * (cnt != 0) - 1;
        if(chance2 * allOperations == 0) type2begin = type2end = -1;
        if(chance3 * (cnt != 0) == 0) type3begin = type3end = -1;
        
        int rng = Generator::random() % chanceSum;
        if(type1begin <= rng && rng <= type1end) // 1
        {
            int x = 1 + Generator::random() % cQuery;
            int y = 1 + Generator::random() % n;
            cnt++;
            test.addLine(1, x, y);
        }
        if(type2begin <= rng && rng <= type2end) // 2
        {
            int x = 1 + Generator::random() % cNormal;
            int y = 1 + Generator::random() % n;
            n++;
            test.addLine(2, x, y);
        }
        if(type3begin <= rng && rng <= type3end) // 3
        {
            int x = 1 + Generator::random() % cnt;
            test.addLine(3, x);
        }
    }
    
    return test;
}

Test branchTest(int n, int q, int cSmall, int cBig, int cQuery, int branches, int layer, bool allOperations = true, int chance1 = 5, int chance2 = 2, int chance3 = 3)
{
    Test test;
    test.addLine(n, q);
    
    vector <int> V(n, 0);
    vector <int> Dis(n + q + 1000, 0);
    
    iota(V.begin(), V.end(), 1);
    random_shuffle(V.begin(), V.end());
    vector <int> Temp(0);
    
    for(int i = 1; i < branches; i++)
    {
        int cnt = n / branches;
        int act = 1;
        while(cnt != 0)
        {
            if(V.back() != 1)
            {
                Temp.push_back(act);
                Dis[V.back()] = Dis[act] + 1;
                act = V.back();
                Temp.push_back(act);
                cnt--;
            }
            V.pop_back();
        }
    }
    for(int i = branches; i <= branches; i++)
    {
        int act = 1;
        while(!V.empty())
        {
            if(V.back() != 1)
            {
                Temp.push_back(act);
                Dis[V.back()] = Dis[act] + 1;
                act = V.back();
                Temp.push_back(act);
            }
            V.pop_back();
        }
    }
    
    for(int i = 0; i < n; i++)
    {
        if(Dis[i + 1] >= (n / branches) - layer)
        {
            V.push_back(1 + Generator::random() % cBig);
        }
        else
        {
            V.push_back(1 + Generator::random() % cSmall);
        }
    }
    test.addLine(V);
    
    int duba = 0;
    while(!Temp.empty())
    {
        int a = Temp.back();
        Temp.pop_back();
        int b = Temp.back();
        Temp.pop_back();
        test.addLine(a, b);
        duba++;
        
    }
    
    int cnt = 0;
    while(q--)
    {
        int chanceSum = chance1 + chance2 * allOperations + chance3 * (cnt != 0);
        
        int type1begin = 0, type1end = chance1 - 1;
        int type2begin = type1end + 1, type2end = type2begin + chance2 * allOperations - 1;
        int type3begin = type2end + 1, type3end = type3begin + chance3 * (cnt != 0) - 1;
        if(chance2 * allOperations == 0) type2begin = type2end = -1;
        if(chance3 * (cnt != 0) == 0) type3begin = type3end = -1;
        
        int rng = Generator::random() % chanceSum;
        
        if(type1begin <= rng && rng <= type1end) // 1
        {
            int x = 1 + Generator::random() % cQuery;
            int y = 1 + Generator::random() % n;
            cnt++;
            test.addLine(1, x, y);
        }
        if(type2begin <= rng && rng <= type2end) // 2
        {
            int y = 1 + Generator::random() % n;
            int x = 1 + Generator::random() % ((Dis[y] + 1 >= (n / branches) - layer) ? cBig : cSmall);
            n++;
            test.addLine(2, x, y);
        }
        if(type3begin <= rng && rng <= type3end) // 3
        {
            int x = 1 + Generator::random() % cnt;
            test.addLine(3, x);
        }        
        
        
    }
    return test;
}

Test branchTest2(int n, int q, int cSmall, int cBig, int cQuery, int branches, int layer, int route, bool allOperations = true, int chance1 = 5, int chance2 = 2, int chance3 = 3)
{
    Test test;
    test.addLine(n, q);
    
    vector <int> V(n, 0);
    vector <int> Dis(n + q + 1000, 0);
    
    iota(V.begin(), V.end(), 1);
    random_shuffle(V.begin(), V.end());
    vector <int> Temp(0);
    
    int rootLike = 1;
    for(int i = 1; i < route; i++)
    {
        if(V.back() != 1)
        {
            Temp.push_back(rootLike);
            Dis[V.back()] = Dis[rootLike] + 1;
            rootLike = V.back();
            Temp.push_back(rootLike);
        }
        else i--;
        V.pop_back();
    }
    
    for(int i = 1; i < branches; i++)
    {
        int cnt = (n - route) / branches;
        int act = rootLike;
        while(cnt != 0)
        {
            if(V.back() != 1)
            {
                Temp.push_back(act);
                Dis[V.back()] = Dis[act] + 1;
                act = V.back();
                Temp.push_back(act);
                cnt--;
            }
            V.pop_back();
        }
    }
    for(int i = branches; i <= branches; i++)
    {
        int act = rootLike;
        while(!V.empty())
        {
            if(V.back() != 1)
            {
                Temp.push_back(act);
                Dis[V.back()] = Dis[act] + 1;
                act = V.back();
                Temp.push_back(act);
            }
            V.pop_back();
        }
    }
    
    for(int i = 0; i < n; i++)
    {
        if(Dis[i + 1] >= ((n - route) / branches) - layer)
        {
            V.push_back(1 + Generator::random() % cBig);
        }
        else
        {
            V.push_back(1 + Generator::random() % cSmall);
        }
    }
    test.addLine(V);
    
    while(!Temp.empty())
    {
        int a = Temp.back();
        Temp.pop_back();
        int b = Temp.back();
        Temp.pop_back();
        test.addLine(a, b);
    }
    
    int cnt = 0;
    while(q--)
    {
        int chanceSum = chance1 + chance2 * allOperations + chance3 * (cnt != 0);
        
        int type1begin = 0, type1end = chance1 - 1;
        int type2begin = type1end + 1, type2end = type2begin + chance2 * allOperations - 1;
        int type3begin = type2end + 1, type3end = type3begin + chance3 * (cnt != 0) - 1;
        if(chance2 * allOperations == 0) type2begin = type2end = -1;
        if(chance3 * (cnt != 0) == 0) type3begin = type3end = -1;
        
        int rng = Generator::random() % chanceSum;
        
        if(type1begin <= rng && rng <= type1end) // 1
        {
            int x = 1 + Generator::random() % cQuery;
            int y = 1 + Generator::random() % n;
            cnt++;
            test.addLine(1, x, 1);
        }
        if(type2begin <= rng && rng <= type2end) // 2
        {
            int y = 1 + Generator::random() % n;
            int x = 1 + Generator::random() % ((Dis[y] + 1 >= ((n - route) / branches) - layer) ? cBig : cSmall);
            n++;
            test.addLine(2, x, y);
        }
        if(type3begin <= rng && rng <= type3end) // 3
        {
            int x = 1 + Generator::random() % cnt;
            test.addLine(3, x);
        }        
        
        
    }
    return test;
}

int main() 
{
    Generator gen("srw");

    gen.beginGroup();
    gen.addTest(exampleTest());
    gen.endGroup();

    //1 - 50% group
    gen.beginGroup();
    {
        Generator::setSeed(1111111);
        gen.addTest(randomTest(5, 50, 20, 5, 0));
        Generator::setSeed(1112111);
        gen.addTest(randomTest(5, 50, 20, 5, 0));
    }
    gen.endGroup();

    //2
    gen.beginGroup();
    {
        Generator::setSeed(2221222);
        gen.addTest(randomTest(5, 50, 20, 5));
        Generator::setSeed(2222222);
        gen.addTest(randomTest(5, 50, 20, 5));
    }
    gen.endGroup();

    //3 - 50% group
    gen.beginGroup();
    {
        Generator::setSeed(3331333);
        gen.addTest(randomTest(100, 200, 100, 20, 0));
        Generator::setSeed(3332333);
        gen.addTest(randomTest(100, 200, 100, 20, 0));        
    }
    gen.endGroup();

    //4
    gen.beginGroup();
    {
        Generator::setSeed(4441444);
        gen.addTest(randomTest(100, 200, 100, 20));
        Generator::setSeed(4442444);
        gen.addTest(randomTest(100, 200, 100, 20));        
        
    }
    gen.endGroup();

    //5 - 50% group
    gen.beginGroup();
    {
        Generator::setSeed(5551555);
        gen.addTest(branchTest(10000, 20000, 10, 500, 500, 5, 10, 0, 9, 0, 2));
        Generator::setSeed(5552555);
        gen.addTest(branchTest2(10000, 20000, 10, 500, 500, 3, 10, 5000, 0, 9, 0, 2)); 
    }
    gen.endGroup();

    //6
    gen.beginGroup();
    {
        Generator::setSeed(6661666);
        gen.addTest(branchTest(10000, 20000, 10, 500, 500, 5, 10, 1, 9, 0, 2));
        Generator::setSeed(5552555);
        gen.addTest(branchTest2(10000, 20000, 10, 500, 500, 3, 10, 5000, 1, 9, 1, 2));        
    }
    gen.endGroup();


    //7 - 50% group
    gen.beginGroup();
    {
        Generator::setSeed(7771777);
        gen.addTest(branchTest(100000, 200000, 100, 500000, 500000, 10, 20, 0));
        Generator::setSeed(7772777);
        gen.addTest(branchTest2(100000, 200000, 100, 500000, 500000, 10, 20, 10000, 0));                
    }
    gen.endGroup();


    //8
    gen.beginGroup();
    {
        Generator::setSeed(8881888);
        gen.addTest(branchTest(100000, 200000, 100, 500000, 500000, 10, 20));
        Generator::setSeed(8882888);
        gen.addTest(branchTest2(100000, 200000, 100, 500000, 500000, 10, 10000, 20));     
    }
    gen.endGroup();

    //9 - 50% group
    gen.beginGroup();
    {
        Generator::setSeed(9991999);
        gen.addTest(branchTest(MAX_N, MAX_Q, 100, MAX_C, MAX_C, 5, 10, 0));
        Generator::setSeed(9992999);
        gen.addTest(branchTest(MAX_N, MAX_Q, 100, MAX_C, MAX_C, 5, 10, 0));
        Generator::setSeed(9993999);
        gen.addTest(branchTest2(MAX_N, MAX_Q, 100, MAX_C, MAX_C, 5, 10, 100000, 0));
    }
    gen.endGroup();

    //10
    gen.beginGroup();
    {
        Generator::setSeed(1001001);
        gen.addTest(branchTest(MAX_N, MAX_Q, 100, MAX_C, MAX_C, 5, 10));
        Generator::setSeed(1002001);
        gen.addTest(branchTest(MAX_N, MAX_Q, 100, MAX_C, MAX_C, 5, 10));
        Generator::setSeed(1003001);
        gen.addTest(branchTest2(MAX_N, MAX_Q, 100, MAX_C, MAX_C, 5, 10, 100000));
    }
    gen.endGroup();
   
    gen.generate();
}