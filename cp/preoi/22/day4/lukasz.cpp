#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define loop(i,a,b) for(int i = a; i <= b; i++)
#define rep(a,b) for(int a = 0; a < b; a++)
#define rev(a,b) for(int a = b-1; a >= 0; a--)
#define st first
#define nd second
#define pb push_back
#define para pair<ll,ll>
#define all(a) a.begin(), a.end()
#define lg(a) (31-__builtin_clz(a))

const ll MOD = 1e9+7;
const ll MAX = 2e5+9;

int n;
int odl[MAX];

int rep[MAX];
int roz[MAX];

bool odw[MAX];

pair<int,int> jump[MAX][18];

stack<int> small_graph;

vector<pair<int,int>> graph[MAX];

void clear(int v){
	 odw[v]=0;
	 for(int i=0;i<graph[v].size();i++){
		  if(odw[graph[v][i].st])
				clear(graph[v][i].st);
	 }
}

void deep(int v){
	 small_graph.push(v);
	 for(int i=0;i<graph[v].size();i++){
		  if(!odw[graph[v][i].st]){
				odl[graph[v][i].st]=odl[v]+1;
				jump[graph[v][i].st][0]={v,graph[v][i].nd};
				deep(graph[v][i].st);
		  }
	 }
}
void build_jump(){
	 while(!small_graph.empty()){
		  int v = small_graph.top();
		  small_graph.pop();

		  for(int k=1;k<=lg(odl[v]);k++){
				jump[v][k].st = jump[jump[v][k-1].st][k-1].st;
				jump[v][k].nd = jump[v][k-1].nd + jump[jump[v][k-1].st][k-1].nd;
		  }
	 }
}
int Find(int a){
	 if(rep[a]==a)
		  return a;
	 int fa = Find(rep[a]);
	 rep[a] = fa;
	 return fa;
}
void Union(int a,int b,int m){
	 int fa = Find(a);
	 int fb = Find(b);


	 if(roz[fa]<roz[fb]){
		  swap(fa,fb);
		  swap(a,b);
	 }

	 //b->a
	 clear(b);
	 odl[b] = odl[a]+1;
	 jump[b][0]={a,m};
	 deep(b);
	 build_jump();

	 roz[fa]+=roz[fb];
	 rep[fb]=fa;
}
void init(int N,int S){
	 n = N;

	 for(int i=1;i<=n;i++){
		  rep[i]=i;
		  roz[i]=1;
		  odw[i]=0;
	 }
}
void build(int x,int y,int m){
	 Union(x,y,m);
	 graph[x].pb({y,m});
	 graph[y].pb({x,m});
}
int path(int x,int y){
	 int s = 0;
	 if(odl[x]<odl[y])
		  swap(x,y);
	 if(odl[x]!=odl[y]){
		  for(int j=lg(odl[x]-odl[y]);j>=0;j--)
				if(odl[jump[x][j].st]>=odl[y]){
					 s += jump[x][j].nd;
					 x = jump[x][j].st;
				}
	 }
	 if(x == y) return s;
	 for(int j=lg(odl[x]);j>=0;j--){
		  if(jump[x][j].st!=jump[y][j].st){
				s += jump[x][j].nd + jump[y][j].nd;
				x = jump[x][j].st;
				y = jump[y][j].st;
		  }
	 }
	 return s+jump[y][0].nd+jump[x][0].nd;
}
/*int q;
char c;
int a,b,m;
void solve(){
	 cin>>c;
	 if(c=='B'){
		  cin>>a>>b>>m;
		  build(a,b,m);
	 } else{
		  cin>>a>>b;
		  cout<<path(a,b)<<"\n";
	 }
}
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	 cin>>n>>q;
	 init(n,0);
	 while(q--)
		  solve();
    return 0;
}*/
