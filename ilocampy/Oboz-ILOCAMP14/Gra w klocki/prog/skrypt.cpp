#include <set>
#include <map>
#include <cmath>
#include <queue>
#include <stack>
#include <string>
#include <cstdio>
#include <vector>
#include <utility>
#include <sstream>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <sys/time.h>
#include <sstream>
#include <fstream>
#include <dirent.h>

#define ST first
#define ND second
#define MP make_pair
#define PB push_back
#define QI queue <int>
#define VI vector <int>
#define PII pair <int,int>
#define SZ(x) (int)(x).size()
#define ALL(x) x.begin(),x.end()
#define SYNC ios_base::sync_with_stdio(0)

typedef long long LL;
typedef long double LD;
typedef unsigned long long ULL;

using namespace std;

string t[100];
void Gen(int,int,int);

int main()
{
  t[1] = "1"; t[2] = "2"; t[3] = "3"; t[4] = "4"; t[5] = "5";
  t[6] = "6"; t[7] = "7"; t[8] = "8"; t[9] = "9"; t[10] = "10";
  t[11] = "11"; t[12] = "12"; t[13] = "13"; t[14] = "14"; t[15] = "15";
	timeval czas;
	gettimeofday(&czas, 0);
	srand(czas.tv_sec*1000+czas.tv_usec/1000);
  for(int i = 1; i <= 5; i++)
  {
    for(int j = 1; j <= 3; j++)
    {
      cout << "TEST #" << i << j << endl;
      string test = "a" + t[j] + "-" + t[i] + "p20";
      if(i == 1)
        Gen(10, 10, 10);
      if(i == 2)
        Gen(100, 1000, 1000);
      if(i == 3)
        Gen(1000, 10000, 1000000);
      if(i == 4)
        Gen(10000, 100000, 1000000000);
      if(i == 5)
        Gen(300000, 1000000, 1000000000);
      string sa = "./gen <temp.in >" + test + ".in";
      string sb = "./wzor <" + test + ".in >" + test + ".out";
      string sc = "./wzor <" + test + ".in";
      system( sa.c_str() );
      system( sb.c_str() );
      system( sc.c_str() );
    }
  }
}

void Gen(int n, int x, int r)
{
  ofstream plik;
  plik.open("temp.in");
  plik.clear();
  plik << n << " " << " " << x << " " << r;
  plik.close();
}
