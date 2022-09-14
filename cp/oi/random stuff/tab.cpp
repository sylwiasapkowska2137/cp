#include <iostream>
using namespace std;

const int MAX = 1007;
bool tab[MAX][MAX];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, m, t, res = 0, x1, y1, x2, y2, suma; 
    cin >> n >> m >> t;
    while (t--){
        cin >> x1 >> y1 >> x2 >> y2; //x na górze,y na górze, x na dole, y na dole
        if (x1 == 1 and y1 == 1){
            res -= 2*tab[x2+1][y2+1];
            res += 1;
        } else if (x1 == 1){ //1,5
            suma = tab[x2+1][y2+1] + tab[x2+1][y1];
            res -= 2*suma;
            res += 2;
        } else if (y1 == 1){
            suma = tab[x2+1][y2+1] + tab[x1][y2+1];
            res -= 2*suma;
            res += 2;
        }  else {
            suma = tab[x1][y1] + tab[x2+1][y1] + tab[x1][y2+1] + tab[x2+1][y2+1];
            res -= 2*suma;
            res += 4;
        }
        cout << res << "\n";
        tab[x1][y1] = !tab[x1][y1];
        tab[x2+1][y1] = !tab[x2+1][y1];
        tab[x1][y2+1] = !tab[x1][y2+1];
        tab[x2+1][y2+1] = !tab[x2+1][y2+1];
    }
    return 0;
}