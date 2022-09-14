//Sylwia Sapkowska
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
 
void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "falnd");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.strst); cerr << ", "; __print(x.ndcond); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? ", " : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif
 
template<class T> using pq = priority_queue<T>;
template<class T> using pqg = priority_queue<T, vector<T>, greater<T>>;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
#define rep(i, a, b) for (int i=a; i<(b); i++)
#define repd(i,a,b) for (int i = (a); i >= b; i--)
#define sz(x) (int)(x).size()
#define pb push_back
#define st first
#define nd second
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()
#define memo(x, val) memndt(x, val, sizeof(x))
#define PI 3.14159265359

int p(int a, int b){
	return a+rng()%(b-a+1);
}

LL n,m,nn,mm,a[1010][1010],b[1010][1010],c[1010][1010],sum[1010][1010],sum2[1010][1010];
deque <LL> q;
vector <pair <LL,pii> > v,ans;
bool vis[1010][1010];


void solve(){
	cin>>n>>m>>nn>>mm; 
	rep(i, 0, n)
	{
		rep(j,0, m)cin >> a[i][j];
		q.clear();
		rep(j,0, m)
		{
			while(!q.empty()&&a[i][q.back()]>=a[i][j]) q.pop_back();
			q.pb(j);
			if(j-mm+1>=0)
			{
				b[i][j-mm+1]=a[i][q.front()];
				if(q.front()==j-mm+1) q.pop_front();
			}
		}
	}
	rep(i,0, m-mm+1)
	{
		q.clear();
		rep(j,0, n)
		{
			while(!q.empty()&&b[q.back()][i]>=b[j][i]) q.pop_back();
			q.pb(j);
			if(j-nn+1>=0)
			{
				c[j-nn+1][i]=b[q.front()][i];
				if(q.front()==j-nn+1) q.pop_front();
			}
		}
	}
	rep(i,1, n) rep(j,0, m) sum[i+1][j+1]=sum[i+1][j]+a[i][j];
	rep(i,1, n+1) rep(j,0, m+1) sum2[i][j]=sum2[i-1][j]+sum[i][j];
	rep(i,0, n-nn+1) rep(j,0, m-mm+1)
	v.pb({sum2[i+nn][j+mm]-sum2[i][j+mm]-sum2[i+nn][j]+sum2[i][j]-nn*mm*c[i][j],{i,j}});
	sort(v.begin(),v.end());
	rep(i,0, v.size())
	{
		if(vis[v[i].nd.st][v[i].nd.nd]) continue;
		ans.pb({v[i].st,{v[i].nd.st+1,v[i].nd.nd+1}});
		for(LL j=max(v[i].nd.st-nn+1,0LL);j<v[i].nd.st+nn;j++)
		for(LL k=max(v[i].nd.nd-mm+1,0LL);k<v[i].nd.nd+mm;k++) vis[j][k]=true;
	}
	cout<<ans.size()<<endl;
	rep(i,0, ans.size()) {
		cout << ans[i].nd.st << " " << ans[i].nd.nd << " " << ans[i].st << "\n";
	}
}




int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--) solve();
	
	return 0;
}
