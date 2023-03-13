#include <iostream>
#include <cstdio>
using namespace std;

int n, m, startx, starty;
int tab[1005][1005];

void rysuj(){
    int x = startx;
    int y = starty;
    
    for(int i=x; i<x+n; i++) tab[y][i] = 1;
    x += n-1;
    
    for(int i=y; i<y+m; i++) tab[i][x] = 1;
    y += m-1;
        
    for(int i=x; i<x+m; i++) tab[y][i] = 1;
    x += m-1;
    
    for(int i=y; i<y+n; i++) tab[i][x] = 1;
    y += n-1;
    
    
    for(int i=x; i>x-m; i--) tab[y][i] = 1;
    x -= m-1;
    
    for(int i=y; i<y+m; i++) tab[i][x] = 1;
    y += m-1;
        
    for(int i=x; i>x-n; i--) tab[y][i] = 1;
    x -= n-1;
    
    for(int i=y; i>y-m; i--) tab[i][x] = 1;
    y -= m-1;
    
    
    for(int i=x; i>x-m; i--) tab[y][i] = 1;
    x -= m-1;
     
    for(int i=y; i>y-n; i--) tab[i][x] = 1;
    y -= n-1;
       
    for(int i=x; i<x+m; i++) tab[y][i] = 1;
    x +=  m-1;
    
    for(int i=y; i>y-m; i--) tab[i][x] = 1;
    y -= m-1;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin >> n;
    m = n;
    
    startx = n-1;
    starty = 0;

    while(n >= 1){
        rysuj();    
        startx += 2;
        starty += 2;
        n -= 4;
    }
    
    for(int i=0; i<m*3; i++){
        for(int j=0; j<m*3; j++){
            if(tab[i][j] == 1)
                cout << "#";
            else
                cout << " ";
        }
        cout << endl;        
    }
    
    return 0;    
}
