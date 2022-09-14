#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int MAXN = 3e5+1;
const int L = 30;

int n, a[MAXN];
bool used[MAXN];

int findPairs(int s) {
   int res=0;
   map<int, vector<int>> cnt;
   for (int i=1; i<=n; ++i) {
      if (used[i]) continue;
      if (cnt.find(s-a[i]) == cnt.end()) {
         cnt[a[i]].push_back(i);
      } else {
         if (cnt[s-a[i]].empty()) cnt[a[i]].push_back(i);
         else {
            used[i]=used[cnt[s-a[i]].back()]=true;
            cnt[s-a[i]].pop_back();
            ++res;
         }
      }
   }
   return res;
}

int main() {
   ios_base::sync_with_stdio(0);
   cin.tie(NULL);
   cout.tie(NULL);
   cin>>n;
   for (int i=1; i<=n; ++i) cin>>a[i];

   int ans=0;
   for (int i=L; i>=1; --i) {
      int p=(1<<i);
      int x=findPairs(p);
      ans += x;
   }
   cout<<ans<<"\n";
}
