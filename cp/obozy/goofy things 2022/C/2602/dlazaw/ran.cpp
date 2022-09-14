#include <bits/stdc++.h>
#include "ranlib.h"
#define glowna_funkcja_programu main
#define integer int
#define bez_zwracania_niczego void
using namespace std;
const int maksymalna_wartosc_n = 1007;
vector<integer> graf_z_biblioteczki[maksymalna_wartosc_n];
int glebokosc_z_wierzcholka_startowego_dfs[maksymalna_wartosc_n][maksymalna_wartosc_n];
bool dobrykierunek[maksymalna_wartosc_n];

bez_zwracania_niczego depth_first_search(integer vertex, integer parent, integer current_from)
{
	for (integer i = 0; i<(integer)graf_z_biblioteczki[vertex].size(); i++)
	{
		if (graf_z_biblioteczki[vertex][i] != parent)
		{
			glebokosc_z_wierzcholka_startowego_dfs[current_from][graf_z_biblioteczki[vertex][i]] = glebokosc_z_wierzcholka_startowego_dfs[current_from][vertex] + 1;
			depth_first_search(graf_z_biblioteczki[vertex][i], vertex, current_from);
		}
	}
}

integer liczba_wierzcholkow;

bool wyczysc(integer wierzcholek, integer parent, integer zapytanie, bool flag){
	bool flaga2 = flag;
	if (wierzcholek == zapytanie) 
	{
		flaga2 = true;
	}
	for (integer i = 0; i<(int)graf_z_biblioteczki[wierzcholek].size(); i++)
	{
		if (graf_z_biblioteczki[wierzcholek][i] == parent) 
		{
			continue;
		}
		flaga2 |= wyczysc(graf_z_biblioteczki[wierzcholek][i], wierzcholek, zapytanie, (wierzcholek == zapytanie) || flag);
	}
	if (!flaga2) 
	{
		dobrykierunek[wierzcholek] = true;
	}
	return flaga2;
}

integer znajdzpoprawnaodpowiedz()
{
	integer maksymalna = INT_MAX, wierzcholek = -1;
	for (integer i = 1; i<= liczba_wierzcholkow; i++){
		if (dobrykierunek[i] == true)
		{
			continue;
		}
		integer temporary = 0;
		for (integer j = 1; j <= liczba_wierzcholkow; j++)
		{
			if (dobrykierunek[j] == true)
			{
				continue;
			}
			temporary = max(temporary, glebokosc_z_wierzcholka_startowego_dfs[i][j]);
		}
		if (maksymalna >= temporary){
			maksymalna = temporary;
			wierzcholek = i;
		}
	}
	return wierzcholek;
}

bez_zwracania_niczego solve()
{
	liczba_wierzcholkow = dajN();
	vector<pair<integer, integer>> krawedzie_grafu = dajKraw();

	for (integer i = 0; i<(integer)krawedzie_grafu.size(); i++)
	{
		integer a = krawedzie_grafu[i].first;
		integer b = krawedzie_grafu[i].second;
		graf_z_biblioteczki[a].push_back(b);
		graf_z_biblioteczki[b].push_back(a);
	}
	for (integer i = 1; i<=liczba_wierzcholkow; i++)
	{
		depth_first_search(i, -1, i);
	}
	
	integer obecnykandydat = znajdzpoprawnaodpowiedz();
	while (true) 
	{
		integer zapytanie = pytaj(obecnykandydat);
		if (zapytanie == -1)
		{
			odpowiedz(obecnykandydat);
			exit(0);
		}
		wyczysc(obecnykandydat, obecnykandydat, zapytanie, false);
		dobrykierunek[obecnykandydat] = true;
		obecnykandydat = znajdzpoprawnaodpowiedz();
	}
}

integer glowna_funkcja_programu()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	solve();
	
	return 0;
}
