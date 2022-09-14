#include <iostream>
#include <string>
#include <set>
using namespace std;
set <int> nie; //na tych pozycjach nie ma sumy równej 9

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, t, poz, res;
    string zew, wew;
    char znak, val;
    cin >> n >> t >> wew >> zew;
    wew = "0"+wew;
    zew = "0"+zew;
    for (int i = 0; i<n; i++){
        if (wew[i]+zew[i]!=105) nie.insert(i); 
    }
    while (t--){
        // cout << wew << " " << zew << "\n";
        cin >> znak;
        if (znak=='W'){
            cin >> poz >> val;
            poz = n-poz;
            wew[poz] = val;
            auto it = nie.find(poz);
            if (it != nie.end()){ // na pozycji poz nie ma sumy równej 9 
                if (wew[poz]+zew[poz]==105) nie.erase(it);
            } else {
                if (wew[poz]+zew[poz]!=105) nie.insert(poz);
            }
        } else if (znak=='Z'){
            cin >> poz >> val;
            poz = n-poz;
            zew[poz] = val;
            auto it = nie.find(poz); 
            if (it != nie.end()){ // na pozycji poz nie ma sumy równej 9 
                if (wew[poz]+zew[poz]==105) nie.erase(it);
            } else {
                if (wew[poz]+zew[poz]!=105) nie.insert(poz);
            }
        } else {
            cin >> poz;
            poz = n-poz;
            res = wew[poz]+zew[poz]-2*'0';
            auto it = nie.upper_bound(poz); 
            if (it != nie.end()) if (wew[*it]+zew[*it]-2*'0'>=10) res++;
            cout << res%10 << "\n";
        }
    }
}
