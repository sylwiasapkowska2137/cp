#include <bits/stdc++.h>
//#pragma GCC optimize("Ofast")
//#pragma GCC optimize ("unroll-loops")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

//szablon czesciowo skopiowany z profilu https://codeforces.com/profile/Geothermal
using namespace std;
 
typedef long long LL;
typedef long double LD;
 
typedef pair<int, int> pii;
typedef pair<LL,LL> pll;
typedef pair<LD,LD> pdd;
 
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<LD> vld;
typedef vector<LL> vll;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
 
template<class T> using pq = priority_queue<T>;
template<class T> using pqg = priority_queue<T, vector<T>, greater<T>>;
 
#define rep(i, a, b) for (int i=a; i<(b); i++)
#define repd(i,a,b) for (int i = (a); i >= b; i--)
#define sz(x) (int)(x).size()
#define pb push_back
#define st first
#define nd second
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()
#define memo(x) memset(x, 0, sizeof(x))
#define debug(x) cerr << x << " "
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
LL losuj(LL a, LL b){ return a+rng()%(b-a+1);}

void solve(){
	int n, m, k; cin >> n >> m >> k;
	vector<vi> vis(n+1,vi(m+1,0));
	map<pair<pii,pii>,int>mapa;
	queue<pii>Q;
	int visited=0;
	vi t1={1,0,-1,0}, t2={0,-1,0,1};
	
	
	rep(q,1,k+1){
		pii f,s;
		cin >> f.st >> f.nd >> s.st >> s.nd;
		mapa[{f,s}]=1;
		mapa[{s,f}]=1;
		
		
		visited=1;
		vis[1][1]=q;
		Q.push({1,1});
		while(!Q.empty()){
			int x=Q.front().st, y=Q.front().nd;
			//cout << x << " " << y << "\n";
			Q.pop();
			rep(i,0,4){
				x+=t1[i]; y+=t2[i];
				if(x>0 && x<=n && y>0 && y<=m){
					if(!mapa.count({{x-t1[i],y-t2[i]},{x,y}})){
						if(vis[x][y]!=q){
							vis[x][y]=q;
							visited++;
							Q.push({x,y});
						}
					}
				}
				x-=t1[i]; y-=t2[i];
			}
		}
		if(visited==n*m) cout << "TAK\n";
		else{
			cout << "NIE\n";
			mapa.erase({f,s});
			mapa.erase({s,f});
		}
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int t = 1;
	//cin >> t;
	while (t--) solve();
	
	return 0;
}
