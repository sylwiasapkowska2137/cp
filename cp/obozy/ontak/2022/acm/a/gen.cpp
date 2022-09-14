#include <bits/stdc++.h>

using namespace std;

#define sim template < class c
#define ris return * this
#define dor > debug & operator <<
#define eni(x) sim > typename \
  enable_if<sizeof dud<c>(0) x 1, debug&>::type operator<<(c i) {
sim > struct rge { c b, e; };
sim > rge<c> range(c i, c j) { return {i, j}; }
sim > auto dud(c* x) -> decltype(cerr << *x, 0);
sim > char dud(...);
struct debug {
#ifdef XOX
~debug() { cerr << endl; }
eni(!=) cerr << boolalpha << i; ris; }
eni(==) ris << range(begin(i), end(i)); }
sim, class b dor(pair < b, c > d) {
  ris << "(" << d.first << ", " << d.second << ")";
}
sim dor(rge<c> d) {
  *this << "[";
  for (c it = d.b; it != d.e; ++it)
    *this << ", " + 2 * (it == d.b) << *it;
  ris << "]";
}
#else
sim dor(const c&) { ris; }
#endif
};
#define imie(x...) " [" #x ": " << (x) << "] "

#define int long long
#define pb emplace_back
#define all(x) (x).begin(), (x).end()
#define pii pair<int,int>
#define vt vector

int r(int a,int b){
    return a + rand()%(b-a+1);
}

int32_t main(int argc, char* argv[]) {
    cin.tie(0)->sync_with_stdio(0);
    srand(atoi(argv[1]));
    int n = r(1, 5), m = r(1, 5);
    cout << 1 << endl;
    cout << n << " " << m << endl;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cout << r(0,2137) << " ";
        }
        cout<<endl;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cout << r(0,2137) << " ";
        }
        cout<<endl;
    }
}
