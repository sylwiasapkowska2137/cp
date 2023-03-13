#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
#define ff first
#define ss second
 
const int M = 100005;
int n, m, a, b, c, p;
vector <pair<int, int> > G[M], G2[M], V[M];
long long odl[M];
pair<int, int> K[M];
long long waga[M];
long long wynik = 1000000000000LL;
 
int main(){
    scanf("%d %d", &n, &m);
    p = sqrt(m) + 1;
    
    for(int i=0; i<m; i++){
        scanf("%d %d %d", &a, &b, &c);   
        K[i].ff = a;
        K[i].ss = b;  
        waga[i] = c;   
        
        V[a].push_back(make_pair(b, c));
        V[b].push_back(make_pair(a, c));
    }
 
    for(int i=1; i<=n; i++){
        if(V[i].size() >= p)
            G[i] = V[i]; 
        else{
            for(int j=0; j<V[i].size(); j++)
                if(V[V[i][j].ff].size() < p)
                    G2[i].push_back(V[i][j]);    
        }
    }
    
    for(int i=1; i<=n; i++)
      if(V[i].size() > 1){
	  for(int j=0; j<V[i].size(); j++) 
	    swap(V[i][j].ff, V[i][j].ss);
	  sort(V[i].begin(), V[i].end());
	  wynik = min(wynik, 2*((long long)V[i][0].ff + (long long)V[i][1].ff));
      }
    
    // > sqrt(m)
    
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++)
            odl[j] = 0;
        if(G[i].size()){ 
            for(int j=0; j<G[i].size(); j++)
                odl[G[i][j].ff] = G[i][j].ss;  
                
            for(int j=0; j<m; j++){
                a = K[j].ff;
                b = K[j].ss;    
                
                if(odl[a] && odl[b]){  
		    wynik = min(wynik, 2*(odl[a] + waga[j]));
		    wynik = min(wynik, 2*(odl[b] + waga[j]));
		    wynik = min(wynik, odl[a] + odl[b] + waga[j]);  
                }
            }        
        } 
    }
    
    // < sqrt(m)
    
    for(int i=0; i<m; i++){
        if(G2[K[i].ff].size() && G2[K[i].ss].size()){
            for(int j=1; j<=n; j++)
                odl[j] = 0;
            
            for(int j=0; j<G2[K[i].ff].size(); j++)
                odl[G2[K[i].ff][j].ff] = G2[K[i].ff][j].ss;                 

            for(int j=0; j<G2[K[i].ss].size(); j++)
                if(odl[G2[K[i].ss][j].ff])
                    wynik = min(wynik, odl[G2[K[i].ss][j].ff] + waga[i] + G2[K[i].ss][j].ss); 
        }   
    }
    
    printf("%lld", wynik);
    
    return 0;    
}
 
