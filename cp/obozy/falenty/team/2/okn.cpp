#include <bits/stdc++.h>

using namespace std;

#define pii pair<int, int>
#define ll long long
#define ld long double

const int N = 2e3+1;
const int S = 3e6+100;
const int K = 11;
const int INF = 1e9+1;

int dp[S], d[K], c[K], n, k;
int x[N], y[N], mn[S];

ll dst(int i, int j) {
    ll xd=x[i]-x[j], yd=y[i]-y[j];
    return ceill((ld)sqrtl(xd*xd+yd*yd));
}

int main() {
    cin>>n;
    for (int i=1; i<=n; ++i) cin>>x[i]>>y[i];
    cin>>k;
    for (int i=1; i<=k; ++i) cin>>d[i]>>c[i];
    for (int i=1; i<S; ++i) dp[i]=INF;

    for (int i=1; i<=k; ++i) {
        for (int j=0; j<S; ++j) {
            if (j+d[i] < S) dp[j+d[i]]=min(dp[j+d[i]], dp[j]+c[i]);
        }
    }

    mn[S-1]=dp[S-1];
    for (int i=S-2; i>=0; --i) mn[i]=min(mn[i+1], dp[i]);

    ll ans=0;
    for (int i=1; i<n; ++i) {
        ll len=dst(i, i+1);
        assert(len < S);
        ans+=mn[len];
    }
    ans+=mn[dst(n, 1)];

    cout<<ans<<"\n";
}