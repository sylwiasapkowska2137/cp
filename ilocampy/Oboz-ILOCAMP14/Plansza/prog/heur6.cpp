#include<iostream>
#include<cstdio>
using namespace std;
long long a,b,m;
int main()
{
    scanf("%d%d%d",&a,&b,&m);
    if(a<0)a=a*(-1);
    if(b<0)b=b*(-1);
    if((m-a-b)%2==0)printf("TAK");
    else printf("NIE");
}
