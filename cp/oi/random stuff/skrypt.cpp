#include <bits/stdc++.h>
using namespace std;

int main(){
	system("g++ -std=c++17 -O3 wzor.cpp -o wzor");
	//Kompilacja programu, który zwraca zawsze poprawne wartości
	system("g++ -std=c++17 -O3 brut.cpp -o brut");
	//Kompilacja generatorki
	system("g++ -std=c++17 -O3 generatorka.cpp -o generatorka");
	for(int i = 1; i <= 1000; i++){
	    //Przygotowanie polecenia do wywołania generatorki
		char buff[100];
		sprintf(buff,"./generatorka %d > test.in",i);
		printf(buff);
        //Wywołanie przygotowanego polecenia
		system(buff);
		//Uruchomienie sprawdzanego programu z wylosowanym testem
		system("./wzor < test.in > wzor.out");
		//Uruchomienie brutalnego rozwiązania z wylosowanym testem
		system("./brut < test.in > brut.out");
		//Porównanie dwóch odpowiedzi
		bool ok = system("diff -B wzor.out brut.out");
		if(!ok){
            //Akcja, gdy odpowiedzi są identyczne
             cout<<i<<" OK ";
             cout<<endl;
        }else{
		    //Akcja gdy odpowiedzi się różnią
			cout<<i<<" BLAD"<<endl;
			break;
		}
	}
}

