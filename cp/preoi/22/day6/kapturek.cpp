#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int MAXN = 1e6+1;
const int INF = 1e9;

int n, p[MAXN], k[MAXN], x[MAXN];

ll pref(int m) {
   ll cnt=0;
   for (int i=1; i<=n; ++i) {
      if (p[i] > m) continue;
      cnt += (min(m, k[i])-p[i])/x[i]+1;
   }

   return cnt;
}

int cntVisits(int z) {
   int res=0;
   for (int i=1; i<=n; ++i) {
      if (z > k[i] || z < p[i]) continue;
      if ((z-p[i])%x[i] == 0) ++res;
   }
   return res;
}

int main() {
   ios_base::sync_with_stdio(0);
   cin.tie(NULL);
   cout.tie(NULL);
   cin>>n;

   for (int i=1; i<=n; ++i) {
      cin>>p[i]>>k[i]>>x[i];
   }

   ll l=1, r=INF, res=INF;
   while (l <= r) {
      ll mid=(l+r)/2, z=pref(mid);
      if (z&1) {
         res=mid, r=mid-1;
      } else l=mid+1;
   }

   if (res == INF) cout<<"NIE\n";
   else {
      cout<<res<<" "<<cntVisits(res)<<"\n";
   }
}
