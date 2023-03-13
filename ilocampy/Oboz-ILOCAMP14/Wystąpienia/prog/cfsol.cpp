#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;

#define rep(i, n) for (int i = 0, _##i = (n); i < _##i; ++i)
#define repi(i, a) for (__typeof((a).begin()) i = (a).begin(), _##i=(a).end(); i != _##i; ++i)

int arr[1000010];

int main() {
//  freopen("a.in","r",stdin); freopen("a.out","w",stdout);

    int n, m;
    cin >> n >> m;
    rep (i, n) cin >> arr[i];
    sort(arr, arr + n);
    int curp = -1;
    ll curneed = 0;
    int mxn = 0;
    int t = 0;
    rep (i, n) {
        while (curneed > m) {
            curp++;
            curneed -= arr[i] - arr[curp];
        }
        if (i - curp > mxn) {
            mxn = i - curp;
            t = arr[i];
        }
        if (i < n - 1) {
            curneed += (ll)(i - curp) * (arr[i + 1] - arr[i]);
        }
    }
    cout << mxn << ' ' << t << endl;
}