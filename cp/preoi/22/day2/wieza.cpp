#include <bits/stdc++.h>

using namespace std;

#define ll long long

ll n;
string s;

struct Frac {
   ll p, q;
};

bool cmpFrac(Frac a, Frac b) {
   return a.p*b.q > b.p*a.q;
}

bool cmpStrict(Frac a, Frac b) {
   return a.p*b.q >= b.p*a.q;
}

int main() {
   ios_base::sync_with_stdio(0);
   cin.tie(NULL);
   cout.tie(NULL);
   cin>>n>>s;
   ll cnt=0, i=1, ans=0;
   for (auto u : s) {
      if (u == 'D') --ans;
      else ++ans;
   }

   Frac x=Frac{ans, n};
   for (auto u : s) {
      if (u == 'D') --cnt;
      else ++cnt;

      if (i == n) continue;
      
      Frac t=Frac{cnt, i};
      while (!cmpFrac(x, t)) ++x.p;
      ++i;
   }
   while (!cmpStrict(x, Frac{cnt, n})) ++x.p;

   cout<<x.p-ans<<"\n";
}
