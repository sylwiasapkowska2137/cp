#include <bits/stdc++.h>
 
using namespace std;
 
#define ll long long
 
const int INF = 1e9+42069; // 2137
const int MAXN = 1e6;
 
int z[MAXN+69], ans[MAXN+69], n, k;
 
string s;
 
// funkcja Z = najlepszy algorytm tekstowy
 
int main() {
   ios_base::sync_with_stdio(0);
   cin.tie(NULL);
   cin>>n>>k;
   cin>>s;
 
   for (int i=1, l=0, r=0; i<n; ++i) {
      if (i <= r) z[i]=min(r-i+1, z[i-l]);
      while (i+z[i] < n && s[z[i]] == s[i+z[i]]) ++z[i];
      if (i+z[i]-1 > r) l=i, r=i+z[i]-1;
   }
   z[0]=INF;
 
   for (int i=1; i<=n; ++i) {
      int c=0;
      for (int j=i-1; j<n; j+=i) {
         if (z[j-i+1] < i) break;
         ++c;
         if (c >= k) ++ans[j], --ans[j+min(z[j+1], i)+1];
      }
   }
 
   int x=0;
   for (int i=0; i<n; ++i) {
      x+=ans[i];
      if (x > 0) cout<<1;
      else cout<<0;
   }
   cout<<"\n";
}
