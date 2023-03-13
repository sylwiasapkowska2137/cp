#include <bits/stdc++.h>
#define int long long
using namespace std;
 
string to_string(string s) { return s; }
template <typename T> string to_string(T v) {
  bool first = true;
  string res = "[";
  for (const auto &x : v) {
    if (!first)
      res += ", ";
    first = false;
    res += to_string(x);
  }
  res += "]";
  return res;
}
 
void dbg_out() { cout << endl; }
template <typename Head, typename... Tail> void dbg_out(Head H, Tail... T) {
  cout << ' ' << to_string(H);
  dbg_out(T...);
}
 
#ifdef DEBUG
#define dbg(...) cout << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif
 
int nbElem, nbVoulus;
struct Container {
  multiset<int> small, big;
  int sum = 0;
 
  Container() {}
 
  void fix() {
    while ((int)big.size() > nbVoulus - 2) {
      int toDel = *big.begin();
      sum -= toDel;
      big.erase(big.begin());
      small.insert(toDel);
    }
    while ((int)big.size() < nbVoulus - 2 and !small.empty()) {
      int toDel = *small.rbegin();
      small.erase(small.find(toDel));
      sum += toDel;
      big.insert(toDel);
    }
  }
 
  void add(int x) {
    if (small.empty())
      big.insert(x), sum += x;
    else if (big.empty())
      small.insert(x);
    else if (x < *small.rbegin())
      small.insert(x);
    else
      big.insert(x), sum += x;
    fix();
  }
 
  void erase(int x) {
    if (big.count(x))
      big.erase(big.find(x)), sum -= x;
    else
      small.erase(small.find(x));
    fix();
  }
};
 
const int INF = 1e18;
 
signed main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
 
  cin >> nbElem >> nbVoulus;
 
  vector<pair<int, int>> arr(nbElem);
  for (auto &[V, C] : arr)
    cin >> V >> C;
  sort(arr.begin(), arr.end(), [&](auto l, auto r) {
    return pair(l.second, l.first) < pair(r.second, r.first);
  });
 
  int curL = 0, curR = 0;
 
  Container container;
 
  auto calc = [&](int l, int r) {
    if (r - l < nbVoulus - 2)
      return -INF;
    while (curR < r)
      container.add(arr[curR++].first);
    while (curL < l)
      container.erase(arr[curL++].first);
    while (curL > l)
      container.add(arr[--curL].first);
    while (curR > r)
      container.erase(arr[--curR].first);
    return container.sum;
  };
 
  int sol = -INF;
 
  auto Solve = [&](auto solve, int deb, int fin, int optL, int optR) {
    if (deb == fin)
      return;
    int mid = (deb + fin) / 2;
    int opt = -1;
    int dp = -INF;
 
    for (int i = min(optR, mid) - 1; i >= optL; --i) {
      int v = arr[mid].first + arr[i].first -
              2 * (arr[mid].second - arr[i].second) + calc(i + 1, mid);
      if (v > dp)
        opt = i, dp = v;
    }
    sol = max(sol, dp);
    solve(solve, deb, mid, optL, opt + 1);
    solve(solve, mid + 1, fin, opt, optR);
  };
 
  Solve(Solve, nbVoulus - 1, nbElem, 0, nbElem);
  cout << sol << endl;
}