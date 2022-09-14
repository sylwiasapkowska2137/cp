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
#define sz(x) (int)(x).size()

template<typename T>
void make_u(vector<T>& x) {
    sort(all(x));
    x.erase(unique(all(x)),x.end());
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, m;
    cin>>n>>m;
    vt<pii> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i].first>>a[i].second;
    }
    vt<pii> pts;
    int one = 0, two = 0;
    pts.pb(one,two);
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        one+=a;
        two+=b;
        pts.pb(one,two);
    }
    make_u(a);
    make_u(pts);
    debug()<<imie(a) imie(pts);
    if(sz(a)!=sz(pts)){
        cout<<"NO WAY"<<endl;
        exit(0);
    }
    int dx=a[0].first-pts[0].first;
    int dy=a[0].second-pts[0].second;
    for(int i=0;i<sz(pts);i++){
        pts[i].first += dx;
        pts[i].second += dy;
    }
    make_u(a);
    make_u(pts);
    debug()<<imie(a) imie(pts);
    if(a==pts){
        cout << "MAYBE"<<endl;
    }
    else{
        cout<<"NO WAY";
    }
}
