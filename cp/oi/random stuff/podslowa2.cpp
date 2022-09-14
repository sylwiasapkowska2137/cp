#include <bits/stdc++.h>
using namespace std;

const int MAKS_DLUGOSC_SLOWA = 1e3+7; //1007
const int MAKS_PDOSLOW = MAKS_DLUGOSC_SLOWA*MAKS_DLUGOSC_SLOWA; //tyle pods³ow bêdzie maksymalnie gdy litery siê nie potwórz¹
long long int potegi1[MAKS_DLUGOSC_SLOWA]; //kolejne potêgi 59
long long int potegi2[MAKS_DLUGOSC_SLOWA]; //kolejne potêgi 313
long long int hash1_slowo[MAKS_DLUGOSC_SLOWA]; //hashe s³owa w systemie o podstawie 59
long long int hash2_slowo[MAKS_DLUGOSC_SLOWA];  //hashe s³owa w systemie o podstawie 313
pair < long long int, long long int> hashe_podslow[MAKS_PDOSLOW]; //pary hashów do sprawdzenia by unikn¹c powtorzenia reszt => paradoks dnia urodzin
const long long int MODULO1 = 1e9+7; //1000000007
const long long int MODULO2 = 1e9+9; //1000000009
const long long int g1 = 41;
const long long int g2 = 313;
string slowo; // slowo, ktore rozpatrujemy

int main(){
 int liczba_roznych_podslow, ile_hashy_podslow;
 long long int wartosc_hasha, zmiana, hash1_podslowa, hash2_podslowa;
 int indeks_potega_wyrownujaca;
 int poczatek, koniec;
 int i,j;
 cin >> slowo;
 slowo = "#" + slowo; //by unikn¹c zamieszania z indeksami
 potegi1[0] = 1; // generujey kolejne potêgi 59
 for (i=1; i<slowo.length(); ++i) {
    potegi1[i] = potegi1[i-1]*g1;
    potegi1[i] %= MODULO1;
 }
 potegi2[0] = 1; // oraz 313
 for (i=1; i<slowo.length(); ++i) {
    potegi2[i] = potegi2[i-1]*g2;
    potegi2[i] %= MODULO2;
 }
 hash1_slowo[0] = (long long int)slowo[0]; //   hash pierwszej litery - tzn. #
 for (i=1; i<slowo.length(); ++i) {
 	hash1_slowo[i] = hash1_slowo[i-1]; //sumy prefiksowe
 	zmiana = (long long int)slowo[i] * potegi1[i]; //59
 	zmiana %= MODULO1; // modulo
 	hash1_slowo[i] += zmiana; // na wszelki wypadek gdyby zmiana wysz³a ujemna:
 	hash1_slowo[i] %= MODULO1; // powtarzamy modulo
 	cerr << hash1_slowo[i] << " ";
 }
 hash2_slowo[0] = (long long int)slowo[0]; // analogicznie
 for (i=1; i<slowo.length(); ++i) {
 	hash2_slowo[i] = hash2_slowo[i-1];
 	zmiana = (long long int)slowo[i] * potegi2[i];
 	zmiana %= MODULO2;
 	hash2_slowo[i] += zmiana;
 	hash2_slowo[i] %= MODULO2;
 }
 ile_hashy_podslow = 0; // na pooczatku 0
 for (poczatek=1; poczatek<slowo.length(); ++poczatek) {
    for (koniec=poczatek; koniec<slowo.length(); ++koniec) {
       indeks_potega_wyrownujaca = slowo.length() - 1 - koniec; //okreslamy przesuniecie dwoch hashy w indeksach - 1 odejmujemy by indeksy sie zgadzaly z dlugoscia slowa
       hash1_podslowa = hash1_slowo[koniec] - hash1_slowo[poczatek-1]; //oraz w wartosciach
       hash1_podslowa += MODULO1;
       hash1_podslowa %= MODULO1; //modulujemy
       hash1_podslowa *= potegi1[indeks_potega_wyrownujaca]; // mnozymy o 59 do potegi przesuniecie
	   hash1_podslowa %= MODULO1; // znowu modulujemy by nie wychodziæ poza inta
       hash2_podslowa = hash2_slowo[koniec] - hash2_slowo[poczatek-1]; // analogicznie z 313
       hash2_podslowa += MODULO2;
       hash2_podslowa %= MODULO2;
       hash2_podslowa *= potegi2[indeks_potega_wyrownujaca];
	   hash2_podslowa %= MODULO2;
	   hashe_podslow[ile_hashy_podslow] = make_pair(hash1_podslowa,hash2_podslowa); // otrzymane hashe laczymy w pary
	   ++ile_hashy_podslow; // i podbijamy liczbe hashy
    }
 }
 sort (hashe_podslow, hashe_podslow+ile_hashy_podslow); // sortujemy hashe
 liczba_roznych_podslow = 1;
 for (i=1; i<ile_hashy_podslow; ++i) {
 	if (hashe_podslow[i-1] != hashe_podslow[i]) //sprawdzamy czy w dwa sposoby otzrymalismy te same hashe
 	   ++liczba_roznych_podslow; //podbijamy wartosc
 }
 cout << liczba_roznych_podslow << "\n";  // wynik
 return 0;
}

