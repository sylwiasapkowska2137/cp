#include <bits/stdc++.h>

using namespace std;

#define pii pair<char, int>

const int MAXQ = 5e3+1;
const int Q = 1e6+1;

int q, sz[3], anc[Q];
pii x[Q];

vector<int> v[MAXQ];

void addW(int i, int x) {
   v[i].push_back(x), v[x].push_back(i);
}

void addZ(int i, int x) {
   for (auto u : v[x]) {
      v[u].push_back(i), v[i].push_back(u);
   }
}

int main() {
   cin>>q;
   for (int i=1; i<=q; ++i) cin>>x[i].first>>x[i].second;

   v[1].push_back(2), v[2].push_back(1);
   int g=3;
   for (int i=1; i<=q; ++i) {
      char c=x[i].first;
      int a=x[i].second;

      if (c == '?') cout<<v[a].size()<<"\n";
      else if (c == 'Z') addZ(g++, a);
      else addW(g++, a);
   }
}
