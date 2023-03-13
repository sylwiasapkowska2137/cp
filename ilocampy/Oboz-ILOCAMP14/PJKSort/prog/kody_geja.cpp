// Generowanie wszystkich wyrazów kodu Graya
//         o zadanej liczbie bitów
//------------------------------------------
// (C)2005 mgr Jerzy Wałaszek
//                 I Liceum Ogólnokształcące
//                 im. K. Brodzińskiego
//                 w Tarnowie
//------------------------------------------

#include <iostream>
#include <string>

using namespace std;

// W tablicy WyrazyGraya tworzone będą kolejne
// wyrazy kodowe. Tablica ta musi posiadać tyle
// elementów, ile jest wszystkich wyrazów kodu.

unsigned WyrazyGraya[65536];

// Funkcja oblicza potęgę liczby 2
//--------------------------------
unsigned Pot2(unsigned n)
{
  unsigned p;

  p = 1;
  while(n-- > 0) p += p;
  return(p);
}

// Rekurencyjna procedura generacji wyrazów kodu Graya
//----------------------------------------------------
void Gray(unsigned n)
{
  unsigned i, p;

  if(n == 1)
  {
    WyrazyGraya[0] = 0;
    WyrazyGraya[1] = 1;
  }
  else
  {
    Gray(n - 1); // wyznaczamy poprzednie wyrazy
    p = Pot2(n - 1);
    for(i = p; i < p + p; i ++)
      WyrazyGraya[i] = p + WyrazyGraya[p + p - i - 1];
  };
}

// Procedura wyświetlająca zawartość tablicy WyrazyGraya
//------------------------------------------------------
void Pisz(unsigned n)
{
  unsigned i, j, kg, p;
  string s;

  p = Pot2(n);
  for(i = 0; i < p; i++)
  {
    s  = "";
    kg = WyrazyGraya[i];
    for(j = 1; j <= n; j++)
    {
      s  = (char)(48 + kg % 2) + s;
      kg /= 2;
    };
    cout << s << endl;
  };
}

main()
{
  unsigned n;
  char z[1];

  cout << "Generacja kodu Gray'a\n"
          "---------------------\n"
          "(C)2005 J.Walaszek\n"
          "      I LO w Tarnowie\n\n"
          "Ile bitow (1..16) ? ";
  cin >> n;
  cout << endl;
  if((n < 1) || (n > 16))
    cout << "Niepoprawna liczba bitow n!";
  else
  {
    Gray(n); Pisz(n);
  };
  cout << "\n\nNacisnij ENTER...\n";
  cin.getline(z,1);
  cin.getline(z,1);
}