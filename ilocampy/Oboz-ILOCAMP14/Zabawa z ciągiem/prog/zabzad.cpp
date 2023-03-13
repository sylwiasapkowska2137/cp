#include <iostream>
#include <fstream>
#include <stdio.h>
#include <algorithm>
#include <set>
#include <vector>
#include <map>
#include <queue>
#include <list>
#include <math.h>
#include <string>
#include <stdlib.h>

#define gcd(a,b) __gcd((a),(b))
#define sqr(a) ((a)*(a))
#define odd(a) ((a)&1)
#define foru(i,n) for (int i=0;i<(n);i++)
#define ford(i,n) for (int i=(n)-1;i>=0;i--)
#define forab(i,l,r) for (int i=(l);i<=(r);i++)
#define forabd(i,r,l) for (int i=(r);i>=(l);i--)
#define fillchar(a,b) memset((a),(b),sizeof((a)))
#define pb push_back
#define F first
#define S second
#define all(x) x.begin,x.end
#define pw2(x) (1ull<<(x))
#define mp make_pair

const long double eps=1e-20;
const long double pi=acos(-1.0);
// const long long inf=1000*1000*1000*1000*1000*1000;
const long long base=1000*1000*1000+7;

using namespace std;

int x,mi=1001,n,k;
long long sum;

int main(){
        cin>>n;
        foru(i,n+n-1){
                cin>>x;
                sum+=abs(x);
                if (x<0) k++;
                mi=min(mi,abs(x));
        }
        if (n%2) cout<<sum; else
        if ((k+1)%2) cout<<sum; else cout<<sum-mi-mi;
        return 0;
}