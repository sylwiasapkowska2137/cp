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

const int MAX = 1e4+7;
vi graf[MAX], color;

struct node{
	int upleft = -1, left = -1, downleft = -1, down = -1;
};

struct p{
	int st, nd, ind;
};
vector<node>dir;
vector<p> points;

bool cmp(p a, p b) {
	if (a.st == b.st) return a.nd < b.nd;
	return a.st < b.st;
}

int COLOR(int i){
	int ans = -1;
	int freq[] = {0,0,0,0};
	if (dir[i].upleft != -1) freq[color[dir[i].upleft]]++;
	if (dir[i].left != -1) freq[color[dir[i].left]]++;
	if (dir[i].downleft != -1) freq[color[dir[i].downleft]]++;
	if (dir[i].down != -1) freq[color[dir[i].down]]++;
	rep(j, 0, 4) {
		if (freq[j] == 0) {
			ans = j;
			break;
		}
	}
	return ans;
}

void bfs(int v, int colora, int colorb){
	queue<int>q;
	q.push(v);
	color[v] = colorb;
	while (!q.empty()){
		int v = q.front();q.pop();
		
		for (auto x: graf[v]){
			if (color[x] == color[v]){
				if (color[v] == colora) color[x] = colorb;
				else color[x] = colora;
				q.push(x);
			}
		}
	}
}

void solve(){
	int n, m; cin >> n >> m;
	
	points.resize(n);
	dir.resize(n);
	color.assign(n, -1);
	rep(i, 0, n) {
		cin >> points[i].st >> points[i].nd;
		points[i].ind = i;
	}
	sort(all(points), cmp);
	vi scaler(n);
	rep(i, 0, n) scaler[points[i].ind] = i;
	rep(i, 0, m){
		int a, b; cin >> a >> b;a--;b--;
		graf[scaler[a]].pb(scaler[b]);
		graf[scaler[b]].pb(scaler[a]);
	}

	rep(i, 0, n){
		for (auto koniec: graf[i]){
			//debug(koniec);
			if (dir[i].upleft == -1 && points[koniec].st - points[i].st == points[i].nd - points[koniec].nd && points[i].st - points[koniec].st > 0) dir[i].upleft = koniec;
			if (dir[i].left == -1 && points[koniec].nd == points[i].nd && points[koniec].st < points[i].st) dir[i].left = koniec;
			if (dir[i].downleft == -1 && points[i].nd - points[koniec].nd == points[i].st - points[koniec].st && points[i].st - points[koniec].st > 0) dir[i].downleft = koniec;
			if (dir[i].down == -1 && points[koniec].st == points[i].st && points[koniec].nd < points[i].nd) dir[i].down = koniec;
		}
		//cerr << "\n";
		
		/*
		debug(points[i].st);
		debug(points[i].nd);
		debug(dir[i].upleft);
		debug(dir[i].left);
		debug(dir[i].downleft);
		debug(dir[i].down);
		cerr << "\n";
		*/
	}
	
	rep(i, 0, n){
		color[i] = COLOR(i);
		if (color[i] == -1){
			//tu jest problem
			bfs(dir[i].upleft, color[dir[i].upleft], color[dir[i].downleft]);
			color[i] = COLOR(i);
			if (color[i] == -1){
				bfs(dir[i].left, color[dir[i].left], color[dir[i].down]);
				color[i] = COLOR(i);
				if (color[i] == -1){
					bfs(dir[i].down, color[dir[i].down], color[dir[i].left]);
					color[i] = COLOR(i);
				}
			}
			
		}
	}
	vi ans(n);
	rep(i, 0, n) ans[points[i].ind] = color[i]+1;
	rep(i, 0, n) cout << ans[i] << "\n"; 
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int t = 1;
	//cin >> t;
	while (t--) solve();
	
	return 0;
}
