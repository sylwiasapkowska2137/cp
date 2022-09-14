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

void test_case() {
	int n,m;
	cin>>n>>m;
	vt<vt<int>> N(n+1,vt<int>(m+1));
	vt<vt<int>> E(n+1,vt<int>(m+1));
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>N[i][j];
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>E[i][j];
		}
	}
    int gans=0;
    for(int i=0;i<(1LL<<(n*m));i++){
        vt<vt<int>> dir(n+1,vt<int>(m+1));
        for(int j=0;j<n*m;j++){
            if(i & (1LL<<j)) {
                dir[j / m + 1][(j % m) + 1] = 1;
            }
        }
        int ans=0;
        for(int j=1;j<=n;j++){
            for(int k=1;k<=m;k++){
                int czyjed = 1;
                for(int l=k;l<=m;l++){
                    if(dir[j][l]==0){
                        czyjed=0;
                    }
                }
                if(czyjed) {
                    ans += E[j][k];
                }
            }
        }
        for(int j=1;j<=n;j++){
            for(int k=1;k<=m;k++){
                int czyzer = 1;
                for(int l=1;l<=j;l++){
                    if(dir[l][k]==1){
                        czyzer=0;
                    }
                }
                if(czyzer) {
                    ans += N[j][k];
                }
            }
        }
        gans=max(gans,ans);
    }
    cout<<gans<<endl;
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
	int t;
	cin >> t;
	while(t--) {
		test_case();
	}
}
