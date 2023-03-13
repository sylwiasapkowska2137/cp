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

const int d=10;
int pier[2007];

void init()
{
	for (int i=0; i<(1<<d); i++)
	{
		pier[i]=-1;
		int v=(-i&i);
		while(v)
		{
			v>>=1;
			pier[i]++;
		}
	}
}

struct mac
{
	int tab[d];
	mac()
	{
		for (int i=0; i<d; i++)
			tab[i]=0;
	}
	void dodaj(int v)
	{
		for (int i=0; i<d; i++)
			if (v&(1<<i))
				v^=tab[i];
		if (!v)
			return;
		for (int i=0; i<d; i++)
			if (tab[i]&(1<<pier[v]) || i==pier[v])
				tab[i]^=v;
	}
	int czy_zaw(int v)
	{
		for (int i=0; i<d; i++)
			if (v&(1<<i))
				v^=tab[i];
		return (!v);
	}
	int rzad()
	{
		int ret=0;
		for (int i=0; i<d; i++)
			ret+=(tab[i]>0);
		return ret;
	}
	int los_nie()
	{
		assert(rzad()!=d);
		while(1)
		{
			int ret=random(0, (1<<d)-1);
			if (!czy_zaw(ret))
				return ret;
		}
	}
	int los_tak()
	{
		while(1)
		{
			int ret=random(0, (1<<d)-1);
			if (czy_zaw(ret))
				return ret;
		}
	}
	void wypisz()
	{
		for (int i=0; i<d; i++)
		{
			for (int j=0; j<d; j++)
				printf("%d", (tab[i]&(1<<j))>0);
			printf("\n");
		}
		printf("\n");
	}
};

mac merge(mac a, mac b)
{
	mac ret=a;
	for (int i=0; i<d; i++)
		if (b.tab[i])
			ret.dodaj(b.tab[i]);
	return ret;
}
    
Test example()
{
    Test test;
    test.addLine(4, 12);
    test.addLine(1, 1, 2, 0);
    test.addLine(1, 2, 4, 1);
    test.addLine(1, 3, 4, 2);
    test.addLine(1, 2, 3, 3);
    test.addLine(3, 1, 3, 3);
    test.addLine(1, 3, 1, 2);
    test.addLine(3, 3, 1, 3);
    test.addLine(2, 2, 1);
    test.addLine(3, 1, 3, 3);
    test.addLine(2, 2, 3);
    test.addLine(1, 2, 3, 2);
    test.addLine(3, 1, 1, 1);
    
    return test;
}
    
Test sciezka1(int n, int q, int dod, int lim)
{
    Test test;
    test.addLine(n, q);
    
    vector < pair <int,int> > wek1, wek2;
    vector <int> per;
    
    for (int i=0; i<=n; i++)
		per.push_back(i);
	for (int i=1; i<=n; i++)
		swap(per[i], per[random(1, i)]);
	
	map < pair <int,int> , int> zab;
	for (int i=1; i<n; i++)
	{
		wek1.push_back({per[i], per[i+1]});
		zab[{per[i], per[i+1]}]=1;
		zab[{per[i+1], per[i]}]=1;
	}
	
	bitset <1000007> juz;
	
	while(dod)
	{
		int p1=random(1, n);
		int p2=random(1, n);
		if (p1==p2 || zab[{p1, p2}])
			continue;
		wek1.push_back({p1, p2});
		zab[{p1, p2}]=1;
		zab[{p2, p1}]=1;
		dod--;
	}
	int jusz=0;
	for (int i=1; i<=q; i++)
	{
		if (wek1.empty())
			jusz=1;
		if (!random(0, 3) && i>=n)
		{
			test.addLine(3, random(1, n), random(1, n), random(0, (1<<lim)-1));
			continue;
		}
		if ((random(0, 4)>jusz && !wek1.empty()) || wek2.empty())
		{
			int x=random(0, (int)wek1.size()-1);
			test.addLine(1, wek1[x].first, wek1[x].second, random(0, (1<<lim)-1));
			wek2.push_back(wek1[x]);
			swap(wek1[x], wek1.back());
			wek1.pop_back();
		}
		else
		{
			int x=random(0, (int)wek2.size()-1);
			test.addLine(2, wek2[x].first, wek2[x].second);
			wek1.push_back(wek2[x]);
			swap(wek2[x], wek2.back());
			wek2.pop_back();
		}
	}
    return test;
}

Test drzewo1(int n, int q, int dod, int lim)
{
    Test test;
    test.addLine(n, q);
    
    vector < pair <int,int> > wek1, wek2;
    vector <int> per;
    
    for (int i=0; i<=n; i++)
		per.push_back(i);
	for (int i=1; i<=n; i++)
		swap(per[i], per[random(1, i)]);
	
	map < pair <int,int> , int> zab;
	for (int i=1; i<n; i++)
	{
		int x=random(i+1, n);
		wek1.push_back({per[i], per[x]});
		zab[{per[i], per[x]}]=1;
		zab[{per[x], per[i]}]=1;
	}
	
	bitset <1000007> juz;
	
	while(dod)
	{
		int p1=random(1, n);
		int p2=random(1, n);
		if (p1==p2 || zab[{p1, p2}])
			continue;
		wek1.push_back({p1, p2});
		zab[{p1, p2}]=1;
		zab[{p2, p1}]=1;
		dod--;
	}
	int jusz=0;
	for (int i=1; i<=q; i++)
	{
		if (wek1.empty())
			jusz=1;
		if (!random(0, 3) && i>=n)
		{
			test.addLine(3, random(1, n), random(1, n), random(0, (1<<lim)-1));
			continue;
		}
		if ((random(0, 4)>jusz && !wek1.empty()) || wek2.empty())
		{
			int x=random(0, (int)wek1.size()-1);
			test.addLine(1, wek1[x].first, wek1[x].second, random(0, (1<<lim)-1));
			wek2.push_back(wek1[x]);
			swap(wek1[x], wek1.back());
			wek1.pop_back();
		}
		else
		{
			int x=random(0, (int)wek2.size()-1);
			test.addLine(2, wek2[x].first, wek2[x].second);
			wek1.push_back(wek2[x]);
			swap(wek2[x], wek2.back());
			wek2.pop_back();
		}
	}
    return test;
}

Test drzewo2(int n, int q, int dod, int lim)
{
    Test test;
    test.addLine(n, q);
    
    vector < pair <int,int> > wek1, wek2;
    vector <int> per;
    
    for (int i=0; i<=n; i++)
		per.push_back(i);
	for (int i=1; i<=n; i++)
		swap(per[i], per[random(1, i)]);
	
	map < pair <int,int> , int> zab;
	for (int i=1; i<n; i++)
	{
		int x=random(i+1, min(n, i+2));
		wek1.push_back({per[i], per[x]});
		zab[{per[i], per[x]}]=1;
		zab[{per[x], per[i]}]=1;
	}
	
	bitset <1000007> juz;
	
	while(dod)
	{
		int p1=random(1, n);
		int p2=random(1, n);
		if (p1==p2 || zab[{p1, p2}])
			continue;
		wek1.push_back({p1, p2});
		zab[{p1, p2}]=1;
		zab[{p2, p1}]=1;
		dod--;
	}
	int jusz=0;
	for (int i=1; i<=q; i++)
	{
		if (wek1.empty())
			jusz=1;
		if (!random(0, 3) && i>=n)
		{
			test.addLine(3, random(1, n), random(1, n), random(0, (1<<lim)-1));
			continue;
		}
		if ((random(0, 4)>jusz && !wek1.empty()) || wek2.empty())
		{
			int x=random(0, (int)wek1.size()-1);
			test.addLine(1, wek1[x].first, wek1[x].second, random(0, (1<<lim)-1));
			wek2.push_back(wek1[x]);
			swap(wek1[x], wek1.back());
			wek1.pop_back();
		}
		else
		{
			int x=random(0, (int)wek2.size()-1);
			test.addLine(2, wek2[x].first, wek2[x].second);
			wek1.push_back(wek2[x]);
			swap(wek2[x], wek2.back());
			wek2.pop_back();
		}
	}
    return test;
}

Test pusty(int n, int q)
{
    Test test;
    test.addLine(n, q);
    
    for (int i=1; i<=q; i++)
		test.addLine(3, random(1, n), random(1, n), 0);
    
    return test;
}

Test scie(int n, int lim)
{
    Test test;
    
    test.addLine(n, n);
    
    vector <int> per;
    
    for (int i=0; i<=n; i++)
		per.push_back(i);
	for (int i=1; i<=n; i++)
		swap(per[i], per[random(1, i)]);
    
    int x=0;
    for (int i=1; i<n; i++)
    {
		int y=random(0, (1<<lim)-1);
		int raz=i;
		int dwa=i+1;
		if (random(0, 1))
			swap(raz, dwa);
		test.addLine(1, per[raz], per[dwa], y);
		x^=y;
	}
	test.addLine(3, per[1], per[n], x);
    
    return test;
}

Test scie2(int n, int lim)
{
    Test test;
    
    test.addLine(n, n*2-2);
    
    vector <int> wek;
    
    vector <int> per;
    
    for (int i=0; i<=n; i++)
		per.push_back(i);
	for (int i=1; i<=n; i++)
		swap(per[i], per[random(1, i)]);
    
    int x=0;
    for (int i=1; i<n; i++)
    {
		int y=random(0, (1<<lim)-1);
		wek.push_back(y);
		int raz=i;
		int dwa=i+1;
		if (random(0, 1))
			swap(raz, dwa);
		test.addLine(1, per[raz], per[dwa], y);
		x^=y;
	}
	reverse(wek.begin(), wek.end());
    for (int i=1; i<n; i++)
    {
		int raz=i;
		int dwa=n;
		if (random(0, 1))
			swap(raz, dwa);
		test.addLine(3, per[raz], per[dwa], x);
		x^=wek.back();
		wek.pop_back();
	}
    
    return test;
}

Test kwadrat(int n)
{
    Test test;
    
    test.addLine(n*(n-1), n*(n-1));
    
    vector < pair <int,int> > wek;
    
    for (int i=2; i<=n; i++)
    {
		test.addLine(1, 1, i, 0);
		test.addLine(3, 1, i, 1);
	}
    for (int i=2; i<=n; i++)
    {
		for (int j=i+1; j<=n; j++)
		{
			wek.push_back({i, j});
			if (random(0, 1))
				swap(wek.back().first, wek.back().second);
			swap(wek.back(), wek[random(0, (int)wek.size()-1)]);
		}
	}
	mac trz=mac();
	for (int i=0; i<wek.size(); i++)
	{
		if (i+1==(int)wek.size())
		{
			int daj;
			daj=trz.los_nie();
			test.addLine(1, wek[i].first, wek[i].second, daj);
			daj=trz.los_tak();
			int gdz=random(1, n);
			test.addLine(3, gdz, gdz, daj);
		}
		else
		{
			int daj;
			if (trz.rzad()+1<d)
				daj=random(0, (1<<d)-1);
			else
				daj=trz.los_tak();
			test.addLine(1, wek[i].first, wek[i].second, daj);
			daj=trz.los_nie();
			int gdz=random(1, n);
			test.addLine(3, gdz, gdz, daj);
		}
	}
    
    return test;
}

int main() {
	Generator gen("zaz");
	init();
	
    gen.beginGroup();
    {
		gen.addTest(example());
	}
    gen.endGroup();

    gen.beginGroup();
    {
		gen.setSeed(1);
		gen.addTest(sciezka1(50, 500, 4, 3));
		gen.setSeed(2);
		gen.addTest(sciezka1(50, 500, 5, 3));
		gen.setSeed(3);
		gen.addTest(sciezka1(50, 500, 6, 3));
		gen.setSeed(4);
		gen.addTest(drzewo1(50, 500, 4, 3));
		gen.setSeed(5);
		gen.addTest(drzewo1(50, 500, 5, 3));
		gen.setSeed(6);
		gen.addTest(drzewo1(50, 500, 6, 3));
		gen.setSeed(7);
		gen.addTest(drzewo2(50, 500, 4, 3));
		gen.setSeed(8);
		gen.addTest(drzewo2(50, 500, 5, 3));
		gen.setSeed(9);
		gen.addTest(drzewo2(50, 500, 6, 3));
		gen.setSeed(10);
		gen.addTest(pusty(500, 500));
		gen.setSeed(11);
		gen.addTest(scie(500, 3));
		gen.setSeed(12);
		gen.addTest(scie2(250, 3));
	}
    gen.endGroup();

    gen.beginGroup();
    {
		gen.setSeed(101);
		gen.addTest(sciezka1(10000, 200000, 5, 0));
		gen.setSeed(102);
		gen.addTest(sciezka1(10000, 200000, 8, 0));
		gen.setSeed(103);
		gen.addTest(sciezka1(10000, 200000, 11, 0));
		gen.setSeed(104);
		gen.addTest(drzewo1(10000, 200000, 2, 0));
		gen.setSeed(105);
		gen.addTest(drzewo1(10000, 200000, 3, 0));
		gen.setSeed(106);
		gen.addTest(drzewo1(10000, 200000, 4, 0));
		gen.setSeed(107);
		gen.addTest(drzewo2(10000, 200000, 2, 0));
		gen.setSeed(108);
		gen.addTest(drzewo2(10000, 200000, 3, 0));
		gen.setSeed(109);
		gen.addTest(drzewo2(10000, 200000, 4, 0));
		gen.setSeed(110);
		gen.addTest(pusty(10000, 10000));
		gen.setSeed(111);
		gen.addTest(scie(200000, 0));
		gen.setSeed(112);
		gen.addTest(scie2(100000, 0));
	}
    gen.endGroup();

    gen.beginGroup();
    {
		gen.setSeed(201);
		gen.addTest(sciezka1(10000, 200000, 5, 10));
		gen.setSeed(202);
		gen.addTest(sciezka1(10000, 200000, 8, 10));
		gen.setSeed(203);
		gen.addTest(sciezka1(10000, 200000, 11, 10));
		gen.setSeed(204);
		gen.addTest(drzewo1(10000, 200000, 5, 10));
		gen.setSeed(205);
		gen.addTest(drzewo1(10000, 200000, 8, 10));
		gen.setSeed(206);
		gen.addTest(drzewo1(10000, 200000, 11, 10));
		gen.setSeed(207);
		gen.addTest(drzewo2(10000, 200000, 5, 10));
		gen.setSeed(208);
		gen.addTest(drzewo2(10000, 200000, 8, 10));
		gen.setSeed(209);
		gen.addTest(drzewo2(10000, 200000, 11, 10));
		gen.setSeed(210);
		gen.addTest(pusty(200000, 200000));
		gen.setSeed(211);
		gen.addTest(scie(200000, 10));
		gen.setSeed(212);
		gen.addTest(kwadrat(200));
		gen.setSeed(213);
		gen.addTest(scie2(100000, 10));
	}
    gen.endGroup();

    gen.beginGroup();
    {
		gen.setSeed(301);
		gen.addTest(sciezka1(30000, 200000, 5, 10));
		gen.setSeed(302);
		gen.addTest(sciezka1(30000, 200000, 8, 10));
		gen.setSeed(303);
		gen.addTest(sciezka1(30000, 200000, 11, 10));
		gen.setSeed(304);
		gen.addTest(drzewo1(30000, 200000, 5, 10));
		gen.setSeed(305);
		gen.addTest(drzewo1(30000, 200000, 8, 10));
		gen.setSeed(306);
		gen.addTest(drzewo1(30000, 200000, 11, 10));
		gen.setSeed(307);
		gen.addTest(drzewo2(30000, 200000, 5, 10));
		gen.setSeed(308);
		gen.addTest(drzewo2(30000, 200000, 8, 10));
		gen.setSeed(309);
		gen.addTest(drzewo2(30000, 200000, 11, 10));
		gen.setSeed(310);
		gen.addTest(pusty(200000, 200000));
		gen.setSeed(311);
		gen.addTest(scie(200000, 10));
		gen.setSeed(312);
		gen.addTest(kwadrat(300));
		gen.setSeed(313);
		gen.addTest(scie2(100000, 10));
	}
    gen.endGroup();

    gen.beginGroup();
    {
		gen.setSeed(401);
		gen.addTest(sciezka1(100000, 200000, 5, 10));
		gen.setSeed(402);
		gen.addTest(sciezka1(100000, 200000, 8, 10));
		gen.setSeed(403);
		gen.addTest(sciezka1(100000, 200000, 11, 10));
		gen.setSeed(404);
		gen.addTest(drzewo1(100000, 200000, 5, 10));
		gen.setSeed(405);
		gen.addTest(drzewo1(100000, 200000, 8, 10));
		gen.setSeed(406);
		gen.addTest(drzewo1(100000, 200000, 11, 10));
		gen.setSeed(407);
		gen.addTest(drzewo2(100000, 200000, 5, 10));
		gen.setSeed(408);
		gen.addTest(drzewo2(100000, 200000, 8, 10));
		gen.setSeed(409);
		gen.addTest(drzewo2(100000, 200000, 11, 10));
		gen.setSeed(410);
		gen.addTest(pusty(200000, 200000));
		gen.setSeed(411);
		gen.addTest(scie(200000, 10));
		gen.setSeed(412);
		gen.addTest(kwadrat(430));
		gen.setSeed(413);
		gen.addTest(scie2(100000, 10));
	}
    gen.endGroup();
    
    gen.generate();
    return 0;
}
