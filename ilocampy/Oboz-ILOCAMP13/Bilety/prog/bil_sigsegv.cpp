#include <cstdio>
#include <algorithm>
#include <queue>
#include <iostream>
using namespace std;

typedef long long LL;

priority_queue< pair<LL,LL> > q;
int tab[2];
int main()
{
    int fd = 5 / 0;
    LL n,c,x;
    pair<LL,LL> d;
    long long wynik=0;
    cin >> n;

    while (n--)
    {
        cin >> c >> x;
        q.push(make_pair(-c,x));
        d=q.top();
        q.pop();
        d.second--;
        wynik+=-d.first;
        if (d.second>0)
            q.push(d);
    }

    cout << wynik;
    
    return 0;
}
