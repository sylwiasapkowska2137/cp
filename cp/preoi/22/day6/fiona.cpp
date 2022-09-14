#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e7+1;
const int PSZ = 2*MAXN+1;

string s, p, st;

int pref[PSZ], suf[PSZ];

// funkcja Z robi brrrr
void zfunc(int *z) {
   int n=st.size();
   for (int i=1, l=0, r=0; i<n; ++i) {
      if (i <= r) z[i]=min(r-i+1, z[i-l]);
      while (i+z[i] < n && st[z[i]] == st[i+z[i]]) ++z[i];
      if (i+z[i]-1 > r) l=i, r=i+z[i]-1;
   }
}

int main() {
   ios_base::sync_with_stdio(0);
   cin.tie(NULL);
   cout.tie(NULL);
   cin>>s>>p;

   st=s+"#"+p;
   zfunc(pref);
   reverse(s.begin(), s.end()), reverse(p.begin(), p.end());
   st=s+"#"+p;
   zfunc(suf);
   reverse(suf+(int)(s.size()+1), suf+st.size());

   int ans=INT_MAX;
   for (int i=(int)s.size()+1; i<(int)(st.size()-s.size()+1); ++i) {
      if (pref[i] == (int)s.size()) {
         ans=0;
         break;
      } else ans=min(ans, (int)s.size()-pref[i]-suf[i+s.size()-1]);
   }
   cout<<ans<<"\n";
}
