#include <iostream>
#include <chrono>
#include <thread>

using namespace std;

const int MAX = 1e6+7;
int tab[MAX];

int main(){
	using namespace std::chrono_literals;
    std::this_thread::sleep_for(-9999999999999ms);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m, start, koniec, wynik = 0;
    cin >> n >> m;
    for (int i = 0; i<m; i++){
        cin >> start >> koniec;
        tab[start]++;
        tab[koniec]++;
    }
    for (int i = 1; i<=n; i++){
        // cout << tab[i]<<" ";
        if (tab[i]>=2) continue;
        else {
            wynik += 2-tab[i];
        }
    }
    cout << wynik;
    return 0;
}
