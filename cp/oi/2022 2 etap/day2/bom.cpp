#include <bits/stdc++.h>
//#pragma GCC optimize("Ofast")
//#pragma GCC optimize ("unroll-loops")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

//Jakub Misiaszek
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

const int nod = 1e9 + 6969;

void solve(){
	int n; cin >> n;
	vector<vector<char>> pol(n+2,vector<char>(n+2,'X'));
	pii p, k;
	rep(i,1,n+1){
		rep(j,1,n+1){
			cin >> pol[i][j];
			if(pol[i][j]=='P') p={i,j};
			else if(pol[i][j]=='K') k={i,j};
		}
	}
	
	vector<vector<vi>> vis(n+2,vector<vi>(n+2,vi(5,nod)));
	
	//odleglosci od konca
	vector<vi> odk(n+2, vi(n+2,nod));
	odk[k.st][k.nd]=0;
	vi z1={1,-1,0,0}, z2={0,0,1,-1}; // pierwsze dwa to ruch w pionie, potem w poziomie
	rep(i,0,4){
		if(pol[k.st+z1[i]][k.nd+z2[i]]=='#') odk[k.st+z1[i]][k.nd+z2[i]]=1;
	}
	
	
	queue<pii>Q;
	Q.push(k);
	while(!Q.empty()){
		int x = Q.front().st, y = Q.front().nd;
		Q.pop();
		
		rep(i,0,4){
			if(odk[x+z1[i]][y+z2[i]]==nod){
				if(pol[x+z1[i]][y+z2[i]]!='X' && pol[x+z1[i]][y+z2[i]]!='#'){
					if(odk[x+z1[i]][y+z2[i]] > odk[x][y]+1){
						odk[x+z1[i]][y+z2[i]] = odk[x][y]+1;
						Q.push({x+z1[i], y+z2[i]});
					}
				}
			}
		}
	}
	
	//odleglosci od poczatku
	//vis ma 5 stanow, 0-nic, 1-pionowo bez zakretu, 2-poz bez zakretu, 3-pion z zakretem, 4-poz z zakretem
	int ans = nod;
	Q.push(p);
	vis[p.st][p.nd][0]=0;
	while(!Q.empty()){
		int x = Q.front().st, y = Q.front().nd;
		Q.pop();
		
		//stan 0
		rep(i,0,4){
			int nx = x+z1[i], ny = y+z2[i];
			if(pol[nx][ny]=='.'){
				if(vis[nx][ny][0]==nod){
					if(vis[nx][ny][0] > vis[x][y][0]+1){
						vis[nx][ny][0] = vis[x][y][0]+1;
						Q.push({nx,ny});
					}
				}
			}
			else if(pol[nx][ny]=='#'){
				bool dod=0;
				if(vis[nx][ny][1]==nod){
					if(vis[nx][ny][1] > vis[x][y][0]+1){
						vis[nx][ny][1] = vis[x][y][0]+1;
						dod=1;
					}
				}
				if(vis[nx][ny][2]==nod){
					if(vis[nx][ny][2] > vis[x][y][0]+1){
						vis[nx][ny][2] = vis[x][y][0]+1;
						dod=1;
					}
				}
				if(dod) Q.push({nx,ny});
			}
		}
		
		//stan 1, pion
		rep(i,0,2){
			int nx = x+z1[i], ny = y+z2[i];
			if(pol[nx][ny]!='X'){
				if(vis[nx][ny][1]==nod){
					if(vis[nx][ny][1] > vis[x][y][1]+1){
						vis[nx][ny][1] = vis[x][y][1]+1;
						Q.push({nx,ny});
					}
				}
			}
		}
		rep(i,2,4){
			int nx = x+z1[i], ny = y+z2[i];
			if(pol[nx][ny]!='X'){
				if(vis[nx][ny][4]==nod){
					if(vis[nx][ny][4] > vis[x][y][1]+1){
						vis[nx][ny][4] = vis[x][y][1]+1;
						Q.push({nx,ny});
					}
				}
			}
		}
		
		//stan 2, poziom
		rep(i,0,2){
			int nx = x+z1[i], ny = y+z2[i];
			if(pol[nx][ny]!='X'){
				if(vis[nx][ny][3]==nod){
					if(vis[nx][ny][3] > vis[x][y][2]+1){
						vis[nx][ny][3] = vis[x][y][2]+1;
						Q.push({nx,ny});
					}
				}
			}
		}
		rep(i,2,4){
			int nx = x+z1[i], ny = y+z2[i];
			if(pol[nx][ny]!='X'){
				if(vis[nx][ny][2]==nod){
					if(vis[nx][ny][2] > vis[x][y][2]+1){
						vis[nx][ny][2] = vis[x][y][2]+1;
						Q.push({nx,ny});
					}
				}
			}
		}
		
		//stan 3, pion
		rep(i,0,2){
			int nx = x+z1[i], ny = y+z2[i];
			if(pol[nx][ny]!='X'){
				if(vis[nx][ny][3]==nod){
					if(vis[nx][ny][3] > vis[x][y][3]+1){
						vis[nx][ny][3] = vis[x][y][3]+1;
						Q.push({nx,ny});
					}
				}
			}
		}
		
		//stan 4, poziom
		rep(i,2,4){
			int nx = x+z1[i], ny = y+z2[i];
			if(pol[nx][ny]!='X'){
				if(vis[nx][ny][4]==nod){
					if(vis[nx][ny][4] > vis[x][y][4]+1){
						vis[nx][ny][4] = vis[x][y][4]+1;
						Q.push({nx,ny});
					}
				}
			}
		}
	}
	
	rep(i,1,n+1){
		rep(j,1,n+1){
			//cout << odk[i][j] << " ";
			int val = nod;
			rep(l,0,5) val = min(val,vis[i][j][l]);
			ans = min(ans, val+odk[i][j]);
		}
		//cout << "\n";
	}
	
	if(ans == nod){
		cout << "NIE\n";
		return;
	}
	else cout << ans << "\n";
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int t = 1;
	//cin >> t;
	while (t--) solve();
	
	return 0;
}
