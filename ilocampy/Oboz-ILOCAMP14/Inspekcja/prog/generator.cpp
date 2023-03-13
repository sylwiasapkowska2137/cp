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

int los(int k)
{
	int w=(1<<(random(0, k)));
	return min(1000000000, random(0, w));
}
    
Test example()
{
    Test test;
    test.addLine(4);
    test.addLine(1, 2, 2);
    test.addLine(2, 3, 2);
    test.addLine(2, 4, 1);
    test.addLine(2);
    test.addLine(2, 4, 2);
    test.addLine(2, 1, 100);
    return test;
}

Test r1(int n, int q)
{
	if (n>10 &&  q>10)
	{
		n-=random(0, 3);
		q-=random(0, 3);
	}
    Test test;
    
    vector <int> per;
    for (int i=0; i<=n; i++)
		per.push_back(i);
    for (int i=1; i<=n; i++)
		swap(per[i], per[random(1, i)]);
	
	vector < pair <int,int> > kra;
	
	for (int i=2; i<=n; i++)
		kra.push_back({per[i], per[random(1, i-1)]});
		
	test.addLine(n);
	for (int i=0; i<n-1; i++)
	{
		if (random(0, 1))
			swap(kra[i].first, kra[i].second);
		test.addLine(kra[i].first, kra[i].second, los(30));
	}
	test.addLine(q);
	for (int i=0; i<q; i++)
	{
		int x=random(0, (int)kra.size()-1);
		if (random(0, 1))
			swap(kra[x].first, kra[x].second);
		test.addLine(kra[x].first, kra[x].second, los(30));
	}
    
    return test;
}

Test r2(int n, int q, int d)
{
	if (n>10 &&  q>10)
	{
		n-=random(0, 3);
		q-=random(0, 3);
	}
    Test test;
    
    vector <int> per;
    for (int i=0; i<=n; i++)
		per.push_back(i);
    for (int i=1; i<=n; i++)
		swap(per[i], per[random(1, i)]);
	
	vector < pair <int,int> > kra;
	
	for (int i=2; i<=n; i++)
		kra.push_back({per[i], per[random(max(1, i-d), i-1)]});
		
	test.addLine(n);
	for (int i=0; i<n-1; i++)
	{
		if (random(0, 1))
			swap(kra[i].first, kra[i].second);
		test.addLine(kra[i].first, kra[i].second, los(30));
	}
	test.addLine(q);
	for (int i=0; i<q; i++)
	{
		int x=random(0, (int)kra.size()-1);
		if (random(0, 1))
			swap(kra[x].first, kra[x].second);
		test.addLine(kra[x].first, kra[x].second, los(30));
	}
    
    return test;
}

Test r3(int n, int q, int d)
{
	if (n>10 &&  q>10)
	{
		n-=random(0, 3);
		q-=random(0, 3);
	}
    Test test;
    
    vector <int> per;
    for (int i=0; i<=n; i++)
		per.push_back(i);
    for (int i=1; i<=n; i++)
		swap(per[i], per[random(1, i)]);
	
	vector < pair <int,int> > kra;
	
	for (int i=2; i<=n; i++)
		kra.push_back({per[i], per[random(1, min(d, i-1))]});
		
	test.addLine(n);
	for (int i=0; i<n-1; i++)
	{
		if (random(0, 1))
			swap(kra[i].first, kra[i].second);
		test.addLine(kra[i].first, kra[i].second, los(10));
	}
	test.addLine(q);
	for (int i=0; i<q; i++)
	{
		int x=random(0, d);
		if (random(0, 1))
			swap(kra[x].first, kra[x].second);
		test.addLine(kra[x].first, kra[x].second, los(30));
	}
    
    return test;
}

Test r4(int n, int q)
{
	if (n>10 &&  q>10)
	{
		n-=random(0, 3);
		q-=random(0, 3);
	}
    Test test;
    
    vector <int> per;
    for (int i=0; i<=n; i++)
		per.push_back(i);
    for (int i=1; i<=n; i++)
		swap(per[i], per[random(1, i)]);
	
	vector < pair <int,int> > kra;
	
	kra.push_back({per[1], per[2]});
	for (int i=3; i<=n; i++)
		kra.push_back({per[random(1, 2)], per[i]});
		
	test.addLine(n);
	for (int i=0; i<n-1; i++)
	{
		if (random(0, 1))
			swap(kra[i].first, kra[i].second);
		test.addLine(kra[i].first, kra[i].second, los(10));
	}
	test.addLine(q);
	for (int i=0; i<q; i++)
	{
		if (random(0, 1))
			swap(kra[0].first, kra[0].second);
		test.addLine(kra[0].first, kra[0].second, los(30));
	}
    
    return test;
}

int main() {
	Generator gen("ins");
	
    gen.beginGroup();
    {
		gen.addTest(example());
	}
    gen.endGroup();

    gen.beginGroup();
    {
		gen.setSeed(1);
		gen.addTest(r1(50, 50));
		gen.setSeed(2);
		gen.addTest(r1(50, 50));
		gen.setSeed(3);
		gen.addTest(r1(50, 50));
		gen.setSeed(4);
		gen.addTest(r2(50, 50, 4));
		gen.setSeed(5);
		gen.addTest(r2(50, 50, 4));
		gen.setSeed(6);
		gen.addTest(r2(50, 50, 4));
		gen.setSeed(7);
		gen.addTest(r3(50, 50, 5));
		gen.setSeed(8);
		gen.addTest(r3(50, 50, 5));
		gen.setSeed(9);
		gen.addTest(r3(50, 50, 5));
		gen.setSeed(10);
		gen.addTest(r4(50, 50));
		gen.setSeed(11);
		gen.addTest(r4(50, 50));
		gen.setSeed(12);
		gen.addTest(r4(50, 50));
		gen.setSeed(13);
		gen.addTest(r4(2, 5));
	}
    gen.endGroup();

    gen.beginGroup();
    {
		gen.setSeed(101);
		gen.addTest(r1(2000, 5000));
		gen.setSeed(102);
		gen.addTest(r1(2000, 5000));
		gen.setSeed(103);
		gen.addTest(r1(2000, 5000));
		gen.setSeed(104);
		gen.addTest(r2(2000, 5000, 10));
		gen.setSeed(105);
		gen.addTest(r2(2000, 5000, 10));
		gen.setSeed(106);
		gen.addTest(r2(2000, 5000, 10));
		gen.setSeed(107);
		gen.addTest(r3(2000, 5000, 20));
		gen.setSeed(108);
		gen.addTest(r3(2000, 5000, 20));
		gen.setSeed(109);
		gen.addTest(r3(2000, 5000, 20));
		gen.setSeed(110);
		gen.addTest(r4(2000, 5000));
		gen.setSeed(111);
		gen.addTest(r4(2000, 5000));
		gen.setSeed(112);
		gen.addTest(r4(2000, 5000));
	}
    gen.endGroup();

    gen.beginGroup();
    {
		gen.setSeed(201);
		gen.addTest(r1(30000, 100000));
		gen.setSeed(202);
		gen.addTest(r1(30000, 100000));
		gen.setSeed(203);
		gen.addTest(r1(30000, 100000));
		gen.setSeed(204);
		gen.addTest(r2(30000, 100000, 10));
		gen.setSeed(205);
		gen.addTest(r2(30000, 100000, 10));
		gen.setSeed(206);
		gen.addTest(r2(30000, 100000, 10));
		gen.setSeed(207);
		gen.addTest(r3(30000, 100000, 100));
		gen.setSeed(208);
		gen.addTest(r3(30000, 100000, 100));
		gen.setSeed(209);
		gen.addTest(r3(30000, 100000, 100));
		gen.setSeed(210);
		gen.addTest(r4(30000, 100000));
		gen.setSeed(211);
		gen.addTest(r4(30000, 100000));
		gen.setSeed(212);
		gen.addTest(r4(30000, 100000));
	}
    gen.endGroup();

    gen.beginGroup();
    {
		gen.setSeed(301);
		gen.addTest(r1(100000, 500000));
		gen.setSeed(302);
		gen.addTest(r1(100000, 500000));
		gen.setSeed(303);
		gen.addTest(r1(100000, 500000));
		gen.setSeed(304);
		gen.addTest(r2(100000, 500000, 10));
		gen.setSeed(305);
		gen.addTest(r2(100000, 500000, 10));
		gen.setSeed(306);
		gen.addTest(r2(100000, 500000, 10));
		gen.setSeed(307);
		gen.addTest(r3(100000, 500000, 300));
		gen.setSeed(308);
		gen.addTest(r3(100000, 500000, 300));
		gen.setSeed(309);
		gen.addTest(r3(100000, 500000, 300));
		gen.setSeed(310);
		gen.addTest(r4(100000, 500000));
		gen.setSeed(311);
		gen.addTest(r4(100000, 500000));
		gen.setSeed(312);
		gen.addTest(r4(100000, 500000));
	}
    gen.endGroup();

    gen.beginGroup();
    {
		gen.setSeed(401);
		gen.addTest(r1(500000, 500000));
		gen.setSeed(402);
		gen.addTest(r1(500000, 500000));
		gen.setSeed(403);
		gen.addTest(r1(500000, 500000));
		gen.setSeed(404);
		gen.addTest(r2(500000, 500000, 20));
		gen.setSeed(405);
		gen.addTest(r2(500000, 500000, 20));
		gen.setSeed(406);
		gen.addTest(r2(500000, 500000, 20));
		gen.setSeed(407);
		gen.addTest(r3(500000, 500000, 1000));
		gen.setSeed(408);
		gen.addTest(r3(500000, 500000, 1000));
		gen.setSeed(409);
		gen.addTest(r3(500000, 500000, 1000));
		gen.setSeed(410);
		gen.addTest(r4(500000, 500000));
		gen.setSeed(411);
		gen.addTest(r4(500000, 500000));
		gen.setSeed(412);
		gen.addTest(r4(500000, 500000));
	}
    gen.endGroup();
    
    gen.generate();
    return 0;
}
