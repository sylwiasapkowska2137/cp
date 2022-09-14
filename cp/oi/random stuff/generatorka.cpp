#include <bits/stdc++.h>
using namespace std;

//Losowanie wartości z przedziału <a, b>
long long R(long long a, long long b){
	return rand()%(b-a+1) + a;
}

//Uruchomienie programu z podanymi parametrami
//argv - liczba parametrów
//argc - tablica z parametrami (zapisanymi jako stringi)
int main(int argv, char **argc){
	
	int nr = atoi(argc[1]);
	srand(nr*time(0));
	
    int n = R(1, 300) ;
    int m = R(1, n);
    cout << n << " " << m << endl;
    for(int i = 1; i<=m; i++){
        int x = R(1, n);
        cout << x << " ";
    }
    cout << endl;
    set <int> s;
    while (s.size() < m){
		int x = R(1, n);
        s.insert(x);
	}
    for (auto it = s.begin(); it!=s.end(); it++){
		cout << *it << " ";
	}
    cout << endl;
    for (int i = 1; i<=n; i++){
		int x = R(1, n);
		cout << x << " ";
	}
    cout << endl;
}
