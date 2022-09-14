// Michał Burzyński
#include <bits/stdc++.h>

using namespace std;

#define pii pair<int, int>

const int MAXN = 201;
const int INF = 1e9;
const int di[] = {-1, 0, 1, 0};
const int dj[] = {0, 1, 0, -1};
const int S = 4;

char b[MAXN][MAXN], tmp[MAXN][MAXN];

bool vis[MAXN][MAXN];
int n, d[MAXN][MAXN];
pii par[MAXN][MAXN];

vector<pii> v;

// https://cp-algorithms.com/graph/breadth-first-search.html

void explode(int i, int j) {
   for (int x=j; x>=1; --x) {
      if (b[i][x] == 'X') break;
      tmp[i][x]='.';
   }
   for (int x=j; x<=n; ++x) {
      if (b[i][x] == 'X') break;
      tmp[i][x]='.';
   }

   for (int x=i; x>=1; --x) {
      if (b[x][j] == 'X') break;
      tmp[x][j]='.';
   }
   for (int x=i; x<=n; ++x) {
      if (b[x][j] == 'X') break;
      tmp[x][j]='.';
   }
}

void clearField() {
   for (int i=1; i<=n; ++i) {
      for (int j=1; j<=n; ++j) {
         tmp[i][j]=b[i][j];
         vis[i][j]=false;
         d[i][j]=INF;
         par[i][j]={-1, -1};
      }
   }
}

bool valid(int i, int j) {
   return (1 <= i && i <= n) && (1 <= j && j <= n);
}

void bfs(pii s) {
   queue<pii> q;
   q.push(s);
   vis[s.first][s.second]=true;
   d[s.first][s.second]=0;

   while (!q.empty()) {
      pii v=q.front();
      q.pop();

      int i=v.first, j=v.second;
      for (int x=0; x<S; ++x) {
         int ni=i+di[x], nj=j+dj[x];
         if (valid(ni, nj) && d[ni][nj] == INF && tmp[ni][nj] == '.') {
            d[ni][nj]=d[i][j]+1;
            par[ni][nj]={i, j};
            q.push({ni, nj});
         }
      }
   }
}

string mv;
int t=INF, bi, bj;

string getMoves(pii c) {
   pii x;

   string res;
   while (par[c.first][c.second].first != -1) {
      x=par[c.first][c.second];

      if (x.first == c.first) {
         if (x.second > c.second) res += 'L';
         else res += 'P';
      } else {
         if (x.first > c.first) res += 'G';
         else res += 'D';
      }
      c=x;
   }

   reverse(res.begin(), res.end());
   return res;
}

void solve(pii s, pii e) {
   for (int i=1; i<=n; ++i) {
      for (int j=1; j<=n; ++j) {
         if (tmp[i][j] == 'X') continue;
         explode(i, j);
         bfs(s);

         if (d[e.first][e.second] == INF) {
            clearField();
            continue;
         }

         if (d[e.first][e.second] < t) {
            t=d[e.first][e.second];
            bi=i, bj=j;
            mv=getMoves(e);
         }
         clearField();
      }
   }
}

int main() {
   ios_base::sync_with_stdio(0);
   cin.tie(NULL);
   cout.tie(NULL);
   cin>>n;

   pii s, e;
   for (int i=1; i<=n; ++i) {
      for (int j=1; j<=n; ++j) {
         cin>>b[i][j];
         d[i][j]=INF;

         if (b[i][j] == 'P') s={i, j}, b[i][j]='.';
         else if (b[i][j] == 'K') e={i, j}, b[i][j]='.';
         if (b[i][j] == '#') v.push_back({i, j});
         tmp[i][j]=b[i][j];
         par[i][j]={-1, -1};
      }
   }
   clearField();

   solve(s, e);
   if (t == INF) {
      cout<<"NIE\n";
      return 0;
   }
   cout<<t<<"\n";
   //cout<<bi<<" "<<bj<<"\n";
   //cout<<mv<<"\n";
}
