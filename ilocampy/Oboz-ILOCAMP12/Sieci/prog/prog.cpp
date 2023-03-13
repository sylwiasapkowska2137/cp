#include <iostream>
#include <vector>
#include <queue>
#include <cassert>
#include <cstdio>
#include <algorithm>

#define PB push_back

using namespace std;

const int MAXN = 100010;
const int INF = 1000000100;

struct edge {
  int b, index, time, cost;
  edge(int b, int index, int time, int cost) : b(b), index(index), time(time), cost(cost) {
  }
};

vector<edge> graf[MAXN];
bool sol[MAXN], lisc[MAXN];
int odl[MAXN], f[MAXN], fodl[MAXN], dp[MAXN];
int n, a, b, c, d;

int bfs1(int start) {
  for (int i=1; i<=n; i++) {
    sol[i] = false;
    f[i] = 0;
  }
  odl[start] = 0;
  sol[start] = true;
  queue<int> q;
  q.push(start);
  while (q.size() > 0) {
    int v = q.front();
    q.pop();
    for (int i=0; i<graf[v].size(); i++) {
      if (!sol[graf[v][i].b]) {
	sol[graf[v][i].b] = true;
	odl[graf[v][i].b] = odl[v] + graf[v][i].time;
	f[graf[v][i].b] = v;
	fodl[graf[v][i].b] = graf[v][i].time;
	q.push(graf[v][i].b);
      }
    }
  }
  int maxdist = 0, res = -1;
  for (int i=1; i<=n; i++) {
    if (maxdist < odl[i]) {
      maxdist = odl[i];
      res = i;
    }
  }
  return res;
}

vector<pair<int, int> > get_path(int v1, int v2) {
  bfs1(v1);
  vector<pair<int, int> > res;
  int ak = v2;
  while (ak != v1) {
    res.push_back(make_pair(ak, fodl[ak]));
    ak = f[ak];
  }
  res.push_back(make_pair(ak, 0));
  return res;
}

void dfs(int v) {
  sol[v] = true;
  odl[v] = 0;
  for (int i=0; i<graf[v].size(); i++) {
    if (!sol[graf[v][i].b]) {
      f[graf[v][i].b] = v;
      fodl[graf[v][i].b] = graf[v][i].time;
      dfs(graf[v][i].b);
      odl[v] = max(odl[v], odl[graf[v][i].b] + graf[v][i].time);
    }
  }
}

bool is_in_tree(int v) {
  if (f[v] == -1) {
    return false;
  }
  if (f[f[v]] == -1) {
    return true;
  }
  if (odl[f[v]] == odl[v] + fodl[v]) {
    return true;
  }
  return false;
}

vector<int> wynik1[MAXN], wynik2[MAXN];

void dfs2(int v) {
  sol[v] = true;
  dp[v] = 0;
  lisc[v] = true;
  for (int i=0; i<graf[v].size(); i++) {
    if (!sol[graf[v][i].b] && is_in_tree(graf[v][i].b)) {
      dfs2(graf[v][i].b);
      lisc[v] = false;
      if (lisc[graf[v][i].b]) {
	wynik1[v].PB(graf[v][i].index);
	dp[v] += graf[v][i].cost;
	fprintf(stderr, "jestem w %d i biore cost  %d %d\n", v, graf[v][i].b, graf[v][i].cost);
      } else {
	if (dp[graf[v][i].b] < graf[v][i].cost) {
	  dp[v] += dp[graf[v][i].b];
	  wynik2[v].PB(graf[v][i].b);
	  fprintf(stderr, "jestem w %d i biore dp\n", v);
	} else {
	  dp[v] += graf[v][i].cost;
	  wynik1[v].PB(graf[v][i].index);
	  fprintf(stderr, "jestem w %d i biore cost  %d %d\n", v, graf[v][i].b, graf[v][i].cost);
	}
      }
    }
  }
  fprintf(stderr, "dp[%d] = %d\n", v, dp[v]);
}

vector<int> odt_tmp;

void dfs_odt(int v) {
  sol[v] = true;
  for (int i=0; i<wynik1[v].size(); i++) {
    odt_tmp.PB(wynik1[v][i]);
  }
  for (int i=0; i<wynik2[v].size(); i++) {
    dfs_odt(wynik2[v][i]);
  }
}

vector<int> odtworz(int v) {
  odt_tmp.clear();
  dfs_odt(v);
  return odt_tmp;
}

void dodaj_vec(vector<int> &v1, const vector<int> &v2) {
  for (int i=0; i<v2.size(); i++)
    v1.PB(v2[i]);
}

bool wyw[MAXN];

void odejmij_vec(vector<int> &v1, const vector<int> &v2) {
  for (int i=0; i<v2.size(); i++) {
    wyw[v2[i]] = true;
  }
  for (int i=0; i<v1.size();) {
    if (wyw[v1[i]]) {
      swap(v1[i], v1.back());
      v1.pop_back();
    } else {
      i++;
    }
  }
  for (int i=0; i<v2.size(); i++) {
    wyw[v2[i]] = false;
  }
}

int main () {
  scanf("%d", &n);
  for (int i=1; i<n; i++) {
    scanf("%d %d %d %d", &a, &b, &c, &d);
    graf[a].PB(edge(b, i, c, d));
    graf[b].PB(edge(a, i, c, d));
  }
  if (n == 2) {
    printf("%d\n%d\n%d\n", graf[1][0].cost, 1, 1);
    return 0;
  }
  int v1 = bfs1(1);
  int v2 = bfs1(v1);
  vector<pair<int, int> > path = get_path(v1, v2);
  int sum = 0;
  for (int i=0; i<path.size(); i++) {
    sum += path[i].second;
  }
  int mam = 0;
  int korzen = -1;
  int ii;
  for (int i=0; i<path.size(); i++) {
    if ((mam + path[i].second == sum / 2) && sum % 2 == 0) {
      assert(i+1 < path.size());
      ii = i+1;
      break;
    } else if (mam + path[i].second < (sum+1) / 2) {
      mam += path[i].second;
    } else {
      ii = i;
      break;
    }
  }
  if (ii == 0) {
    ii ++;
  } else if (ii == path.size()-1) {
    ii --;
  }
  korzen = path[ii].first;
  fprintf(stderr, "korzen to %d\n", korzen);
  for (int i=0; i<path.size(); i++) {
    fprintf(stderr, "%d %d\n", path[i].first, path[i].second);
  }
  fprintf(stderr, "\n\n");
  assert(korzen != -1);
  for (int i=1; i<=n; i++) {
    sol[i] = false;
  }
  f[korzen] = -1;
  dfs(korzen);
  for (int i=1; i<=n; i++) {
    fprintf(stderr, "odl[%d] =  %d\n", i, odl[i]);
  }
  for (int i=1; i<=n; i++) {
    sol[i] = false;
  }
  vector<pair<int, int> > dists;
  for (int i=0; i<graf[korzen].size(); i++) {
    dists.push_back(make_pair(odl[graf[korzen][i].b] + graf[korzen][i].time, i));
  }
  sort(dists.begin(), dists.end());
  reverse(dists.begin(), dists.end());
  while (dists.back().first < dists[1].first) {
    dists.pop_back();
  }
  fprintf(stderr, "\n\n");
  for (int i=0; i<dists.size(); i++) {
    fprintf(stderr, "%d %d\n", dists[i].first, dists[i].second);
    dfs2(graf[korzen][dists[i].second].b);
    if (lisc[graf[korzen][dists[i].second].b]) {
      dp[graf[korzen][dists[i].second].b] = INF;
    }
  }
  int result;
  vector<int> result_vec;
  if (dists[0].first == dists[1].first) {
    int sum = 0, maxi = 0;
    vector<int> sum_vec, maxi_vec;
    for (int i=0; i<dists.size(); i++) {
      if (dp[graf[korzen][dists[i].second].b] < graf[korzen][dists[i].second].cost) {
	sum += dp[graf[korzen][dists[i].second].b];
	vector<int> odt_vec = odtworz(graf[korzen][dists[i].second].b);
	dodaj_vec(sum_vec, odt_vec);
	if (maxi < dp[graf[korzen][dists[i].second].b]) {
	  maxi = dp[graf[korzen][dists[i].second].b];
	  maxi_vec = odt_vec;
	}
      } else {
	sum += graf[korzen][dists[i].second].cost;
	vector<int> odt_vec; odt_vec.push_back(graf[korzen][dists[i].second].index);
	dodaj_vec(sum_vec, odt_vec);
	if (maxi < graf[korzen][dists[i].second].cost) {
	  maxi = graf[korzen][dists[i].second].cost;
	  maxi_vec = odt_vec;
	}
      }
    }
    result = sum - maxi;
    result_vec = sum_vec;
    odejmij_vec(result_vec, maxi_vec);
  } else {
    int sum = 0;
    vector<int> sum_vec;
    for (int i=1; i<dists.size(); i++) {
      fprintf(stderr, "    %d %d\n",
        dp[graf[korzen][dists[i].second].b], graf[korzen][dists[i].second].cost);
      if (dp[graf[korzen][dists[i].second].b] < graf[korzen][dists[i].second].cost) {
	sum += dp[graf[korzen][dists[i].second].b];
	vector<int> dod_vec = odtworz(graf[korzen][dists[i].second].b);
	dodaj_vec(sum_vec, dod_vec);
      } else {
	sum += graf[korzen][dists[i].second].cost;
	vector<int> dod_vec; dod_vec.push_back(graf[korzen][dists[i].second].index);
	dodaj_vec(sum_vec, dod_vec);
      }
    }
    int moz;
    vector<int> moz_vec;
    if (dp[graf[korzen][dists[0].second].b] < graf[korzen][dists[0].second].cost) {
      moz = dp[graf[korzen][dists[0].second].b];
      fprintf(stderr, "jestem 1   %d   %d\n", moz, graf[korzen][dists[0].second].cost);
      moz_vec = odtworz(graf[korzen][dists[0].second].b);
    } else {
      moz = graf[korzen][dists[0].second].cost;
      fprintf(stderr, "jestem 2  %d    %d\n", moz, dp[graf[korzen][dists[0].second].b]);
      moz_vec.PB(graf[korzen][dists[0].second].index);
    }
    
    if (sum < moz) {
      result = sum;
      result_vec = sum_vec;
    } else {
      result = moz;
      result_vec = moz_vec;
    }
    fprintf(stderr, "%d %d\n", sum, moz);
  }
  printf("%d\n%d\n", result, (int)result_vec.size());
  for (int i=0; i<result_vec.size(); i++) {
    printf("%d ", result_vec[i]);
  }
  printf("\n");
}

