#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pii pair<int, int>
#define vi vector<int>

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int MAGIC_CONSTANT=1e9;

struct Q {
   int p, k, x;
};

ll rnd(ll a, ll b){
   return a+rng()%(b-a+1);
}

vector<Q> v;

int main() {
   srand(2137);
   int n=rnd(1, 2000);
   for (int i=0; i<n; ++i) {
	   //int tp = 1, tk = C, tx = 1;
      int tp=rnd(1, 5), tk=rnd(tp, 10), tx=rnd(1, 10);
      v.push_back(Q{tp, tk, tx});
      v.push_back(Q{tp, tk, tx});
   }
   int X = rnd(1, 1e9);
	v.push_back(Q{X, X, 1});
   //v.push_back(Q{C, C, C});
  // shuffle(v.begin(), v.end(), rng);
   cout<<v.size()<<"\n";
   for (int i=0; i<(int)v.size(); ++i) {
      cout<<v[i].p<<" "<<v[i].k<<" "<<v[i].x<<"\n";
   }
}
