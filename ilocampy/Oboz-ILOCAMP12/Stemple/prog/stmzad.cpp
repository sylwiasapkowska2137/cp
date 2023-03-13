/* Wzorcówka do zadania "Stemple" (Ilocamp Zima 2016)
 * Złożoność O(n*m)
 * Autor: Mateusz Chołołowicz
 */

#include <iostream>
#include <cstdio>
#include <map>
#include <vector>
using namespace std;

#define ff first
#define ss second

const int MX = 1005;
const int INF = 1000000000;

int n, m;
int a, b, id = 1, blok = 1, dlugosc, wynik;
int szablon[MX];
map <int, int> M;
vector <pair<int, int> > stemple[MX];
vector <pair<int, int> > bloki[MX];
vector <int> kolejnosc[MX];
pair<int, int> plecak[MX][MX];
int szerokoscStempli[MX];


void wczytajDaneIPrzygotujStruktury() {
    scanf("%d %d", &n, &m);
    
    for (int i=1; i<=n; i++) {
        scanf("%d", &szablon[i]);
        
        if (M[szablon[i]] == 0) {
            M[szablon[i]] = id;
            id++;
        }
    }
    
    for (int i=1; i<=n; i++) {
        dlugosc++;
        
        if (szablon[i] != szablon[i + 1]) {
            if (szablon[i] > 0) {
                bloki[M[szablon[i]]].push_back(make_pair(dlugosc, blok));
                blok++;
            }
            dlugosc = 0;
        }
    }
    
    for (int i=1; i<=m; i++) {
        scanf("%d %d", &a, &b);
        
        int nr = M[a];
        if (nr > 0) {
            stemple[nr].push_back(make_pair(b, i));
            szerokoscStempli[i] = b;
        }
    }
}

void policzPlecak() {
    for (int i=1; i<id; i++) {
        for (int w=1; w<=n; w++)
            plecak[i][w].ff = INF;
        
        for (int j=0; j<stemple[i].size(); j++) {
            int szerokosc = stemple[i][j].ff;
            
            for (int w=0; w<n; w++) {
                if (plecak[i][w].ff == INF)
                    continue;
                
                if (w + szerokosc <= n && plecak[i][w].ff + 1 < plecak[i][w + szerokosc].ff) {
                    plecak[i][w + szerokosc].ff = plecak[i][w].ff + 1;
                    plecak[i][w + szerokosc].ss = stemple[i][j].ss;
                }
            }
        }
    }
}

int policzWynik() {
    for (int i=1; i<id; i++) {
        for (int j=0; j<bloki[i].size(); j++) {
            int szerokosc = bloki[i][j].ff;
            int nrBloku = bloki[i][j].ss;
            
            if (plecak[i][szerokosc].ff == INF)
                return false;
            
            wynik += plecak[i][szerokosc].ff;
            
            while (szerokosc > 0) {
                kolejnosc[nrBloku].push_back(plecak[i][szerokosc].ss);
                szerokosc -= szerokoscStempli[plecak[i][szerokosc].ss];
            }
        }
    }
    
    return true;
}

int main() {
    wczytajDaneIPrzygotujStruktury();
    
    policzPlecak();
    
    bool git = policzWynik();
    
    if (git) {
        printf("%d\n", wynik);
        for (int i=1; i<blok; i++)
            for (int j=kolejnosc[i].size()-1; j>=0; j--)
                printf("%d ", kolejnosc[i][j]);
    }
    else {
        printf("NIE\n");
    }

    return 0;
}