#include <bits/stdc++.h>
using namespace std;


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    vector<int>a(n);//[0...n-1]
    for (int i = 0; i<n; i++) cin >> a[i];
    // sort(a.begin(), a.end()); 
    vector<pair<int, int>>b; 
    // pair<int, int>x = {21, 37}; //para, mozna tez sie spotkac z zapisem: 
    // pair<int, int>x = make_pair(21, 37);
    // cout << x.first << " " << x.second; //pierwszy i drugi element pary
    for (int i = 1; i<n-1; i++){
        b.push_back({a[i], i}); //vector par (wartosc, indeks)
    }
    // cout << a.size() << "\n"; //a.size() podaje rozmiar vectora
    // inne rzeczy ktore mozna zrobic z vectorami:
    // a.assign(n+1, 3); --> rozszerza vector do rozmiaru n+1 (indeksy od 0 do n), ustawia je wszystkie na 3
    // a.clear(); ---> czysci vector, od tego momentu jest pusty, posiada 0 elementow
    // reverse(a.begin(), a.end()); --> odwraca caly vector, e.g. {1, 2, 3} --> po reverse -->  {3, 2, 1};
    // 0  1  2  3  4  5
    //[1, 2, 3, 2, 4, 5]
    //{2, 1}, {2, 3}, {3, 2}, {4, 4}, {5, 5};
    //n = 5
    //{a[1], 1}, {a[2], 2}, {a[3], 3}
    sort(b.begin(), b.end()); //sortuje, sort par: najpierw po pierwszej wartosci, potem po drugiej
    int ile = min(4, (int)b.size()); //ilosc minimalnych elementow, ktore chcemy sprawdzic pod kątem kandydata na odpowiedz
    // int ile = 4;
    int ans = 2e9+7; // ans≤2*10^9
    for (int i = 0; i<ile; i++){ //i = 2
        for (int j = i+1; j<ile; j++){ //j = 3
            if (abs(b[i].second-b[j].second) != 1){ //sprawdzam czy elementy spod indeksow (i, j) są niesasiednie
                ans = min(ans, b[i].first + b[j].first); //biore minimum 
            }
        }
    }
    cout << ans << "\n";

    return 0;
}