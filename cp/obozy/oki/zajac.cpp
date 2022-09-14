#include <bits/stdc++.h>
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

const int MAX = 1002, INF = 1e9+7;
int n, m;
int graf[MAX][MAX];
int dist[MAX][MAX];
int x[] = {1, 1, -1, -1, 2, 2, -2, -2};
int y[] = {2, -2, 2, -2, 1, -1, 1, -1};

void fastscan(int &number)
{
    //variable to indicate sign of input number
    bool negative = false;
    register int c;
  
    number = 0;
  
    // extract current character from buffer
    c = getchar();
    if (c=='-')
    {
        // number is negative
        negative = true;
  
        // extract the next character from the buffer
        c = getchar();
    }
  
    // Keep on extracting characters if they are integers
    // i.e ASCII Value lies from '0'(48) to '9' (57)
    for (; (c>47 && c<58); c=getchar())
        number = number *10 + c - 48;
  
    // if scanned input has a negative sign, negate the
    // value of the input number
    if (negative)
        number *= -1;
}

void bfs(pii s){
	queue<pii>q;
	dist[s.st][s.nd] = 0;
	q.push(s);
	while (!q.empty()){
		pii v = q.front();q.pop();
		rep(i, 0, 8){
			s = {v.st+x[i], v.nd+y[i]};
			if (s.st >= 1 && s.nd >= 1 && s.st <= n && s.nd <= m){
				if (dist[s.st][s.nd] == INF && graf[s.st][s.nd]!=(int)'x'){
					dist[s.st][s.nd] = dist[v.st][v.nd]+1;
					q.push(s);
				}
			}
		}
	}
}

void solve(){
	fastscan(n);
	fastscan(m);
	pii start, koniec;
	string s = "ncx.z";
	rep(i, 1, n+1){
		rep(j, 1, m+1){
			char c = getchar();
			while (c!='n' && c!='x' && c!='.' && c!='z') c = getchar();
			graf[i][j] = c;
			dist[i][j] = INF;
			if (graf[i][j] == (int)'z') start = {i, j};
			if (graf[i][j] == (int)'n') koniec = {i, j};
		}
	}
	bfs(start);
	if (dist[koniec.st][koniec.nd] == INF) cout << "NIE\n";
	else cout << dist[koniec.st][koniec.nd] << "\n";
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	solve();
	
	return 0;
}
