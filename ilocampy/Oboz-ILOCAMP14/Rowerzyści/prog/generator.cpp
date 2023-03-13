#include <bits/stdc++.h>
#include "generator.h"
using namespace std;

template <class F, class S>
std::ostream &operator<<(std::ostream &os, const std::pair<F, S> &pair) {
    os << pair.first << " " << pair.second;
    return os;
}

int random(int a, int b)
{
    return Generator::random() % (b - a + 1) + a;
}

int mod=1000000007;
    
Test randomTest(int n)
{
    Test test;
    test.addLine(n);
    for (int h=1; h<=2; h++)
    {
		vector<int> v;
		for (int i = 1; i <= n; i++)
			v.push_back(random(0, mod-1));
		test.addLine(v);
	}
    return test;
}

int main() {
    Generator gen("row");

    gen.beginGroup();//1 test
    {
		gen.setSeed(1);
		gen.addTest(randomTest(10));
	}
    gen.endGroup();
    
    gen.beginGroup();//20 testów
    {
		for (int i=1; i<=10; i++)
		{
			gen.setSeed(10+i);
			gen.addTest(randomTest(i));
			gen.setSeed(30+i);
			gen.addTest(randomTest(i));
		}
    }
    gen.endGroup();
    
    gen.beginGroup();//26 testów
    {
		for (int i=1; i<=4; i++)
		{
			gen.setSeed(100+i);
			gen.addTest(randomTest(12));
		}
		for (int i=1; i<=17; i++)
		{
			gen.setSeed(150+i);
			gen.addTest(randomTest(13));
		}
		gen.setSeed(50000009);
		gen.addTest(randomTest(13));
		for (int i=1; i<=4; i++)
		{
			gen.setSeed(200+i);
			gen.addTest(randomTest(14));
		}
    }
    gen.endGroup();
    
    gen.beginGroup();//26 testów
    {
		for (int i=1; i<=4; i++)
		{
			gen.setSeed(1000+i);
			gen.addTest(randomTest(12));
		}
		for (int i=1; i<=18; i++)
		{
			gen.setSeed(1500+i);
			gen.addTest(randomTest(13));
		}
		for (int i=1; i<=4; i++)
		{
			gen.setSeed(2000+i);
			gen.addTest(randomTest(14));
		}
    }
    gen.endGroup();
    
    gen.beginGroup();//25 testów
    {
		for (int i=1; i<=5; i++)
		{
			for (int j=15; j<=19; j++)
			{
				gen.setSeed(3000*i+j);
				gen.addTest(randomTest(j));
			}
		}
    }
    gen.endGroup();
    
    gen.beginGroup();//10 testów
    {
		gen.setSeed(100000);
		gen.addTest(randomTest(30));
		gen.setSeed(100001);
		gen.addTest(randomTest(100));
		gen.setSeed(100002);
		gen.addTest(randomTest(300));
		gen.setSeed(100003);
		gen.addTest(randomTest(1000));
		gen.setSeed(100004);
		gen.addTest(randomTest(3000));
		gen.setSeed(100005);
		gen.addTest(randomTest(10000));
		gen.setSeed(100006);
		gen.addTest(randomTest(30000));
		gen.setSeed(100007);
		gen.addTest(randomTest(100000));
		gen.setSeed(100008);
		gen.addTest(randomTest(100000));
		gen.setSeed(100009);
		gen.addTest(randomTest(100000));
    }
    gen.endGroup();
    
    gen.beginGroup();//10 testów
    {
		gen.setSeed(1000000);
		gen.addTest(randomTest(10));
		gen.setSeed(1000001);
		gen.addTest(randomTest(13));
		gen.setSeed(1000002);
		gen.addTest(randomTest(13));
		gen.setSeed(1000003);
		gen.addTest(randomTest(14));
		gen.setSeed(1000004);
		gen.addTest(randomTest(18));
		gen.setSeed(1000005);
		gen.addTest(randomTest(30));
		gen.setSeed(1000006);
		gen.addTest(randomTest(100));
		gen.setSeed(1000007);
		gen.addTest(randomTest(1000));
		gen.setSeed(1000008);
		gen.addTest(randomTest(10000));
		gen.setSeed(1000009);
		gen.addTest(randomTest(100000));
    }
    gen.endGroup();
    
    gen.beginGroup();//10 testów
    {
		gen.setSeed(10000000);
		gen.addTest(randomTest(13));
		gen.setSeed(10000001);
		gen.addTest(randomTest(13));
		gen.setSeed(10000002);
		gen.addTest(randomTest(13));
		gen.setSeed(10000003);
		gen.addTest(randomTest(13));
		gen.setSeed(10000004);
		gen.addTest(randomTest(13));
		gen.setSeed(10000005);
		gen.addTest(randomTest(13));
		gen.setSeed(10000006);
		gen.addTest(randomTest(13));
		gen.setSeed(10000007);
		gen.addTest(randomTest(18));
		gen.setSeed(10000008);
		gen.addTest(randomTest(10));
		gen.setSeed(10000009);
		gen.addTest(randomTest(100000));
    }
    gen.endGroup();
    
    gen.generate();
    return 0;
}
