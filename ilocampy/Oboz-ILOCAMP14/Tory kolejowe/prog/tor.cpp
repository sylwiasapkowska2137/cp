#include <iostream>
#include <vector>
#include <algorithm>
#define FI first
#define SE second
#define PB push_back
using namespace std;
typedef long long lol;
const lol INF = 1000000000000000000LL;
typedef pair<lol,lol> pi;
int main() {
    ios_base::sync_with_stdio(0);
    int ile;
    cin >> ile;
    vector<pi> domki;
    while(ile--) {
        pi tmp;
        cin >> tmp.FI >> tmp.SE;
        domki.PB(tmp);
    }
    sort(domki.begin(), domki.end());
    lol mins = INF, lastd = 0, wynik = INF;
    for(int i=0; i<domki.size(); i++) {
        mins += (domki[i].FI - lastd);
        wynik = min(wynik, mins + domki[i].SE);
        mins = min(mins, domki[i].SE);
        lastd = domki[i].FI;
    }
    cout << wynik << endl;
    return 0;
}