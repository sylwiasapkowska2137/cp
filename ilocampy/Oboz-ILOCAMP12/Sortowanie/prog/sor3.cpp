#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <fstream>
#include <numeric>
#include <iomanip>
#include <bitset>
#include <list>
#include <stdexcept>
#include <functional>
#include <utility>
#include <ctime>

using namespace std;

int a[110000],rank[110000],n,T;

const bool cmp(const int x,const int y)
{
    return a[x]<a[y] || a[x]==a[y] && x < y;
}

int main()
{
    scanf("%d",&T);
    for (int casenum=0;casenum<T;casenum++)
    {
        scanf("%d",&n);
        for (int i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
            rank[i]=i;
        }
        sort(rank,rank+n,cmp);
        int ans=0,last=n;
        for (int i=0;i<n;)
        {
            int r=i;
            while (r+1 < n && a[rank[r+1]]==a[rank[i]]) r++;
            if (rank[i]<last) ans++;
            int j=rank[i]; i=r+1;
            if (j<last)
                while (rank[r]>last) r--;
            last=rank[r];
        }
        int p=0;
        while ((1 << p) < ans) p++;
        cout << p << endl;
    }
}
