#include <iostream>

#define REP(i, a, b) for (int i = (a), _end_ = (b); i != _end_; ++i)
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define mp make_pair
#define x first
#define y second

using namespace std;

typedef long long LL;

const int oo = 0x3f3f3f3f;

const int maxn = 1000000;

int n;
bool a[maxn + 5];

int main()
{
        scanf("%d", &n);
        REP(i, 0, n) scanf("%d", a + i);
        int ans = 0;
        int lst = -oo;
        REP(i, 0, n)
        {
                if (a[i])
                {
                        if (lst == -oo) lst = i - 1;
                        ans += min(2, i - lst);
                        lst = i;
                }
        }
        printf("%d\n", ans);
        return 0;
}