#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <ctime>
#define LL long long
#define PB push_back
#define MP make_pair
#define ff first
#define ss second
using namespace std;
int size;


int main(int argc, char *argv[])
{
  srand(time(0)*atoi(argv[1]));
  int n=rand()%100+1;
  long long x=rand()%1000+1;
  printf("%d %lld\n",n,x);
  //cout<<rand()%1000+1<<" ";
  for(int i=1;i<=n;i++)
  {
    printf("%d ",rand()%100000+1);
  }
  
  
}