#include <cstdio>
#include <iostream>
using namespace std;

int n, m, a, b, c, wynik = 1000000000;
int tab[1000][1000];

int main(){
  scanf("%d %d", &n, &m);
  
  for(int i=1; i<=n; i++)
     for(int j=1; j<=n; j++)
	  tab[i][j] = 10000;
  
  while(m--){
      scanf("%d %d %d", &a, &b, &c);
      tab[a][b] = c;
      tab[b][a] = c;
  }
  
  for(int i=1; i<=n; i++)
    for(int j=1; j<=n; j++)
      for(int k=1; k<=n; k++){
	if(i == j || i == k || j == k) continue;
	wynik = min(wynik, (tab[i][j] + tab[i][k]) * 2);
	wynik = min(wynik, tab[i][j] + tab[i][k] + tab[j][k]);
      }

  printf("%d", wynik);
      
  return 0;
}