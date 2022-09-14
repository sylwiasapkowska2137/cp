#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pii pair<int, ll>

const int MAXM = 1e6+1;

struct S {
   int a, s;
   ll p;
};

ll n, m, t, leadp=0;
vector<S> q;
vector<int> pps;

map<int, ll> pt;
map<int, vector<pii>> sb;
vector<pii> v;

bool cmp(S a, S b) {
   return a.s < b.s;
}

void constructMap() {
   assert(!q.empty());
   for (int i=0; i<(int)q.size(); ++i) {
      pt[q[i].a] += q[i].p;

      if (pt[q[i].a] > leadp && !v.empty() && v.back().first == q[i].s) v.pop_back();
      if (pt[q[i].a] > leadp) {
         leadp=pt[q[i].a];
         v.push_back({q[i].s, leadp});
      }
   }
   assert(!v.empty());
   v.push_back({t+1, v.back().second});
}

int leadingTime(int x) {
   ll sc=0, leadtm=0;
   sort(sb[x].begin(), sb[x].end());
   for (auto u : sb[x]) {
      sc += u.second;
      int up=(upper_bound(v.begin(), v.end(), make_pair(u.first, LLONG_MAX))-v.begin()), lf=up-1;
      if (lf < 0) continue;
      if (v[lf].second == sc) leadtm+=v[up].first-u.first;
   }
   return leadtm;
}

int main() {
   ios_base::sync_with_stdio(0);
   cin.tie(NULL);
   cout.tie(NULL);
   cin>>n>>m>>t;

   bool allZeros=true;
   for (int i=1; i<=m; ++i) {
      int a, s, p;
      cin>>a>>s>>p;
      if (p == 0) continue;
      q.push_back(S{a, s, p});
      sb[a].push_back({s, p});
      pps.push_back(a);
      allZeros=false;
   }

   sort(q.begin(), q.end(), cmp), sort(pps.begin(), pps.end());
   pps.erase(unique(pps.begin(), pps.end()), pps.end());

   if (allZeros == true) {
      cout<<1<<"\n";
      return 0;
   }

   constructMap();

   int ans=1, leadtm=0;
   for (auto u : pps) {
      int x=leadingTime(u);
      if (x > leadtm) {
         leadtm=x;
         ans=u;
      }
   }
   cout<<ans<<"\n";
}
