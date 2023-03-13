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
    
Test example()
{
    Test test;
    test.addLine(2);
    test.addLine(6);
    test.addLine(1, 1, 1, 2, 2, 2);
    test.addLine(6);
    test.addLine(2, 2, 2, 1, 1, 1);
    return test;
}
    
Test randomTest(int n, int m, int k)
{
    Test test;
    test.addLine(k);
    
	vector<int> v;
	test.addLine(n);
	for (int i=1; i<=n; i++)
		v.push_back(random(1, k));
	test.addLine(v);
	
	v.clear();
	test.addLine(m);
	for (int i=1; i<=m; i++)
		v.push_back(random(1, k));
	test.addLine(v);
	
    return test;
}
    
Test r1(int n, int r)//Takie same permutacje podwojonych elementów
{
    Test test;
    test.addLine(n/r);
    
	vector <int> w, v;
	for (int i=1; i<=n/r; i++)
		w.push_back(i);
	for (int i=0; i<n/r; i++)
		swap(w[i], w[random(0, i)]);
	for (int i=0; i<n/r; i++)
		for (int j=1; j<=r; j++)
			v.push_back(w[i]);
	test.addLine(n);
	test.addLine(v);
	test.addLine(n);
	test.addLine(v);
	
    return test;
}
    
Test r2(int n, int r)//Odwrócone permutacje podwojonych elementów
{
    Test test;
    test.addLine(n/r);
    
	vector <int> w, v;
	for (int i=1; i<=n/r; i++)
		w.push_back(i);
	for (int i=0; i<n/r; i++)
		swap(w[i], w[random(0, i)]);
	for (int i=0; i<n/r; i++)
		for (int j=1; j<=r; j++)
			v.push_back(w[i]);
	test.addLine(n);
	test.addLine(v);
	test.addLine(n);
	reverse(v.begin(), v.end());
	test.addLine(v);
	
    return test;
}

Test r3(int n, int r)//Losowe permutacje mające po tyle samo każdego elementu
{
    Test test;
    test.addLine(n/r);
    
	vector <int> v;
	for (int i=1; i<=n; i++)
		v.push_back((i+r-1)/r);
	for (int i=0; i<n; i++)
		swap(v[i], v[random(0, i)]);
	test.addLine(n);
	test.addLine(v);
	for (int i=0; i<n; i++)
		swap(v[i], v[random(0, i)]);
	test.addLine(n);
	test.addLine(v);
	
    return test;
}

Test s1()
{
    Test test;
    
    test.addLine(1);
	test.addLine(3);
	test.addLine(1, 1, 1);
	test.addLine(4);
	test.addLine(1, 1, 1, 1);
	
    return test;
}

Test s2()
{
    Test test;
    
    test.addLine(1);
	test.addLine(4);
	test.addLine(1, 1, 1, 1);
	test.addLine(3);
	test.addLine(1, 1, 1);
	
    return test;
}

Test s3()
{
    Test test;
    
    test.addLine(2);
	test.addLine(5);
	test.addLine(1, 2, 1, 2, 1);
	test.addLine(5);
	test.addLine(2, 1, 2, 1, 2);
	
    return test;
}

Test s4()
{
    Test test;
    
    test.addLine(2);
	test.addLine(1);
	test.addLine(1);
	test.addLine(1);
	test.addLine(1);
	
    return test;
}

Test s5()
{
    Test test;
    
    test.addLine(2);
	test.addLine(1);
	test.addLine(1);
	test.addLine(1);
	test.addLine(2);
	
    return test;
}

Test s6()
{
    Test test;
    
    test.addLine(3);
	test.addLine(3);
	test.addLine(1, 2, 3);
	test.addLine(3);
	test.addLine(3, 2, 1);
	
    return test;
}

Test s7()
{
    Test test;
    
    test.addLine(2);
	test.addLine(6);
	test.addLine(1, 2, 1, 2, 1, 2);
	test.addLine(6);
	test.addLine(1, 1, 1, 2, 2, 2);
	
    return test;
}

Test s8()
{
    Test test;
    
	test.addLine(2);
	
    vector <int> v;
	test.addLine(1000);
	for (int i=1; i<=1000; i++)
		v.push_back((i&1)+1);
	test.addLine(v);
    
    v.clear();
	test.addLine(501);
	for (int i=1; i<=501; i++)
		v.push_back(1);
	test.addLine(v);
	
    return test;
}

Test s9()
{
    Test test;
    
	test.addLine(3);
	
    vector <int> v;
	test.addLine(1000);
	for (int i=1; i<=1000; i++)
		v.push_back((i&1)+1);
	test.addLine(v);
    
    v.clear();
	test.addLine(1000);
	for (int i=1; i<=1000; i++)
		v.push_back(3);
	test.addLine(v);
	
    return test;
}

Test s10()
{
    Test test;
    
	test.addLine(2);
	
    vector <int> v;
	test.addLine(1000);
	for (int i=1; i<=500; i++)
		v.push_back(1);
	for (int i=1; i<=500; i++)
		v.push_back(2);
	test.addLine(v);
	
	v.clear();
	test.addLine(1000);
	for (int i=1; i<=500; i++)
		v.push_back(1);
	for (int i=1; i<=500; i++)
		v.push_back(2);
	test.addLine(v);
	
    return test;
}

Test s11()
{
    Test test;
    
	test.addLine(10);
	
    vector <int> v;
    int l=0;
    for (int i=0; (int)v.size()<1000; i=(i+1)%10)
    {
		v.push_back(i+1);
		l++;
		if (l==11)
		{
			l=0;
			v.pop_back();
		}
	}
	
	test.addLine(1000);
	test.addLine(v);
	
	test.addLine(1000);
	test.addLine(v);
	
    return test;
}

vector <Test> ujebujonce[10];

int main() {
    Generator gen("pod");
    
    ujebujonce[1].push_back(s1());
    ujebujonce[1].push_back(s2());
    ujebujonce[1].push_back(s3());
    ujebujonce[1].push_back(s4());
    ujebujonce[1].push_back(s5());
    ujebujonce[1].push_back(s6());
    ujebujonce[1].push_back(s7());
    
    gen.setSeed(187);
    ujebujonce[2].push_back(randomTest(20, 20, 4));
    gen.setSeed(190);
    ujebujonce[2].push_back(randomTest(20, 20, 4));
    gen.setSeed(280);
    ujebujonce[2].push_back(randomTest(20, 20, 4));
    gen.setSeed(1223);
    ujebujonce[2].push_back(randomTest(20, 20, 4));
    
    ujebujonce[3].push_back(s8());
    ujebujonce[3].push_back(s11());
    ujebujonce[4].push_back(s9());
    ujebujonce[5].push_back(s10());

    gen.beginGroup();
    {
		gen.addTest(example());
	}
    gen.endGroup();

    gen.beginGroup();
    {
		gen.setSeed(1);
		gen.addTest(randomTest(1, 1, 1));
		gen.setSeed(2);
		gen.addTest(randomTest(7, 8, 3));
		gen.setSeed(3);
		gen.addTest(randomTest(7, 8, 2));
		gen.setSeed(4);
		gen.addTest(randomTest(8, 8, 1));
		gen.setSeed(5);
		gen.addTest(randomTest(9, 10, 4));
		gen.setSeed(6);
		gen.addTest(randomTest(10, 9, 3));
		gen.setSeed(7);
		gen.addTest(r1(10, 2));
		gen.setSeed(8);
		gen.addTest(r2(10, 2));
		gen.setSeed(9);
		gen.addTest(r3(10, 2));
		gen.setSeed(10);
		gen.addTest(r3(9, 3));
		gen.setSeed(11);
		gen.addTest(r3(10, 5));
		gen.setSeed(12);
		gen.addTest(r3(10, 5));
		
		for (int h=1; h; h--)
			for (int i=0; i<ujebujonce[h].size() && (int)gen.tests.back().size()<26; i++)
				gen.addTest(ujebujonce[h][i]);
	}
    gen.endGroup();

    gen.beginGroup();
    {
		gen.setSeed(101);
		gen.addTest(randomTest(200, 200, 2));
		gen.setSeed(102);
		gen.addTest(randomTest(200, 200, 3));
		gen.setSeed(103);
		gen.addTest(randomTest(200, 200, 5));
		gen.setSeed(104);
		gen.addTest(randomTest(200, 200, 8));
		gen.setSeed(105);
		gen.addTest(randomTest(200, 200, 10));
		gen.setSeed(106);
		gen.addTest(randomTest(200, 200, 10));
		gen.setSeed(107);
		gen.addTest(randomTest(200, 200, 10));
		gen.setSeed(108);
		gen.addTest(randomTest(200, 200, 15));
		gen.setSeed(109);
		gen.addTest(randomTest(200, 200, 20));
		gen.setSeed(110);
		gen.addTest(randomTest(200, 200, 25));
		gen.setSeed(111);
		gen.addTest(r1(200, 2));
		gen.setSeed(112);
		gen.addTest(r2(200, 2));
		gen.setSeed(113);
		gen.addTest(r2(200, 5));
		gen.setSeed(114);
		gen.addTest(r3(200, 4));
		gen.setSeed(115);
		gen.addTest(r3(200, 8));
		gen.setSeed(116);
		gen.addTest(r3(200, 20));
		gen.setSeed(117);
		gen.addTest(r3(200, 40));
		
		for (int h=2; h; h--)
			for (int i=0; i<ujebujonce[h].size() && (int)gen.tests.back().size()<26; i++)
				gen.addTest(ujebujonce[h][i]);
	}
    gen.endGroup();

    gen.beginGroup();//20 testów
    {
		gen.setSeed(201);
		gen.addTest(randomTest(1000, 1000, 2));
		gen.setSeed(202);
		gen.addTest(randomTest(1000, 1000, 3));
		gen.setSeed(203);
		gen.addTest(randomTest(1000, 1000, 5));
		gen.setSeed(204);
		gen.addTest(randomTest(1000, 1000, 8));
		gen.setSeed(205);
		gen.addTest(randomTest(1000, 1000, 10));
		gen.setSeed(206);
		gen.addTest(randomTest(1000, 1000, 10));
		gen.setSeed(207);
		gen.addTest(randomTest(1000, 1000, 10));
		gen.setSeed(208);
		gen.addTest(randomTest(1000, 1000, 15));
		gen.setSeed(209);
		gen.addTest(randomTest(1000, 1000, 20));
		gen.setSeed(210);
		gen.addTest(randomTest(1000, 1000, 25));
		gen.setSeed(211);
		gen.addTest(randomTest(1000, 1000, 50));
		gen.setSeed(212);
		gen.addTest(randomTest(1000, 1000, 70));
		gen.setSeed(213);
		gen.addTest(randomTest(1000, 1000, 100));
		gen.setSeed(214);
		gen.addTest(r1(1000, 2));
		gen.setSeed(215);
		gen.addTest(r2(1000, 2));
		gen.setSeed(216);
		gen.addTest(r2(1000, 10));
		gen.setSeed(217);
		gen.addTest(r3(1000, 20));
		gen.setSeed(218);
		gen.addTest(r3(1000, 50));
		gen.setSeed(219);
		gen.addTest(r3(1000, 200));
		gen.setSeed(220);
		gen.addTest(r3(1000, 500));
		
		for (int h=3; h; h--)
			for (int i=0; i<ujebujonce[h].size() && (int)gen.tests.back().size()<26; i++)
				gen.addTest(ujebujonce[h][i]);
	}
    gen.endGroup();

    gen.beginGroup();
    {
		gen.setSeed(301);
		gen.addTest(randomTest(2000, 2000, 2));
		gen.setSeed(302);
		gen.addTest(randomTest(2000, 2000, 3));
		gen.setSeed(303);
		gen.addTest(randomTest(2000, 2000, 5));
		gen.setSeed(304);
		gen.addTest(randomTest(2000, 2000, 8));
		gen.setSeed(305);
		gen.addTest(randomTest(2000, 2000, 10));
		gen.setSeed(306);
		gen.addTest(randomTest(2000, 2000, 10));
		gen.setSeed(307);
		gen.addTest(randomTest(2000, 2000, 10));
		gen.setSeed(308);
		gen.addTest(randomTest(2000, 2000, 15));
		gen.setSeed(309);
		gen.addTest(randomTest(2000, 2000, 20));
		gen.setSeed(310);
		gen.addTest(randomTest(2000, 2000, 25));
		gen.setSeed(311);
		gen.addTest(randomTest(2000, 2000, 50));
		gen.setSeed(312);
		gen.addTest(randomTest(2000, 2000, 70));
		gen.setSeed(313);
		gen.addTest(randomTest(2000, 2000, 100));
		gen.setSeed(314);
		gen.addTest(r1(2000, 2));
		gen.setSeed(315);
		gen.addTest(r2(2000, 2));
		gen.setSeed(316);
		gen.addTest(randomTest(1, 1, 2000));
		gen.setSeed(317);
		gen.addTest(r2(2000, 50));
		gen.setSeed(318);
		gen.addTest(r3(2000, 40));
		gen.setSeed(319);
		gen.addTest(r3(2000, 100));
		gen.setSeed(320);
		gen.addTest(r3(2000, 200));
		
		for (int h=4; h; h--)
			for (int i=0; i<ujebujonce[h].size() && (int)gen.tests.back().size()<26; i++)
				gen.addTest(ujebujonce[h][i]);
	}
    gen.endGroup();

    gen.beginGroup();
    {
		gen.setSeed(401);
		gen.addTest(randomTest(2000, 2000, 2));
		gen.setSeed(402);
		gen.addTest(randomTest(2000, 2000, 3));
		gen.setSeed(403);
		gen.addTest(randomTest(2000, 2000, 5));
		gen.setSeed(404);
		gen.addTest(randomTest(2000, 2000, 8));
		gen.setSeed(405);
		gen.addTest(randomTest(2000, 2000, 10));
		gen.setSeed(406);
		gen.addTest(randomTest(2000, 2000, 10));
		gen.setSeed(407);
		gen.addTest(randomTest(2000, 2000, 10));
		gen.setSeed(408);
		gen.addTest(randomTest(2000, 2000, 15));
		gen.setSeed(409);
		gen.addTest(randomTest(2000, 2000, 20));
		gen.setSeed(410);
		gen.addTest(randomTest(2000, 2000, 25));
		gen.setSeed(411);
		gen.addTest(randomTest(2000, 2000, 50));
		gen.setSeed(412);
		gen.addTest(randomTest(2000, 2000, 70));
		gen.setSeed(413);
		gen.addTest(randomTest(2000, 2000, 100));
		gen.setSeed(414);
		gen.addTest(randomTest(2000, 2000, 500));
		gen.setSeed(415);
		gen.addTest(randomTest(2000, 2000, 1000));
		gen.setSeed(416);
		gen.addTest(randomTest(2000, 1, 1));
		gen.setSeed(417);
		gen.addTest(randomTest(1, 2000, 1));
		gen.setSeed(418);
		gen.addTest(r3(2000, 2000));
		gen.setSeed(419);
		gen.addTest(r3(2000, 4));
		gen.setSeed(420);
		gen.addTest(r3(2000, 5));
		
		for (int h=5; h; h--)
			for (int i=0; i<ujebujonce[h].size() && (int)gen.tests.back().size()<26; i++)
				gen.addTest(ujebujonce[h][i]);
	}
    gen.endGroup();
    
    gen.generate();
    return 0;
}
