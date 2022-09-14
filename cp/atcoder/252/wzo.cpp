#include<bits/stdc++.h>
#define ll long long
#define db double
#define pii pair<int,int>
#define mp make_pair
#define fi first
#define se second
using namespace std;
ll read(){
	ll sum=0,f=1;char st=getchar();
	while(st<'0'||st>'9'){
		if(st=='-')f=-1;
		st=getchar();
	}
	while('0'<=st&&st<='9'){
		sum=(sum<<3)+(sum<<1)+st-'0';
		st=getchar();
	}
	return sum*f;
}
const int maxn=80,mod=998244353;
int id[maxn];
vector<ll> a[maxn];
bool paix(int s1,int s2){
	return a[s1].size()>a[s2].size();
}
int n,m;
ll k;
vector<ll> f[2],b,c;
vector<pair<vector<ll>,vector<ll> > > g[2];
int main(){
//	freopen("1.in","r",stdin);
//	freopen("1.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;++i){
		int x=read();
		a[x].push_back(read());
	}
	for(int i=1;i<=m;++i)id[i]=i;
	sort(id+1,id+1+m,paix);
	int st=1;
	for(int i=1;i<=m;++i)
		if(st*a[id[i]].size()<=4e5)st*=a[id[i]].size(),id[i]=-id[i];
	int p=0;
	f[0].push_back(0);
	for(int i=1;i<=m;++i){
		if(id[i]<0)continue;
		p=p^1;
		f[p].clear();
		for(auto x:f[p^1])
			for(auto y:a[id[i]])
				f[p].push_back(x^y);
	}
	b=f[p];
	f[p].clear();
	f[p].push_back(0);
	for(int i=1;i<=m;++i){
		if(id[i]>0)continue;
		id[i]=-id[i],p=p^1;
		f[p].clear();
		for(auto x:f[p^1])
			for(auto y:a[id[i]])
				f[p].push_back(x^y);
	}
//	for(auto x:b)
//		cout<<x<<" ";
//	cout<<endl;
//	for(auto x:f[p])
//		cout<<x<<" ";
//	cout<<endl;
	g[0].push_back(mp(b,f[p])),p=0;
	ll ans=0;
	for(int i=59;i>=0;--i){
		p^=1,g[p].clear();
		ll an=0,st=1ll<<i;
		for(const pair<vector<ll>,vector<ll>> &x:g[p^1]){
//			for(auto y:x.fi)
//				cout<<y<<" ";
//			cout<<endl;
//			for(auto y:x.se)
//				cout<<y<<" ";
//			cout<<endl;
			int a[2]={0,0},b[2]={0,0};
			for(auto y:x.fi)++a[!!(y&st)];
			for(auto y:x.se)++b[!!(y&st)];
//			cout<<a[0]<<" "<<b[1]<<" "<<a[1]<<" "<<b[0]<<endl;
			an+=1ll*a[0]*b[1]+1ll*a[1]*b[0];
		}
//		cout<<"an="<<an<<" k="<<k<<endl;
		int bj=0;
		if(an>=k)ans|=st,bj=1;
		else k-=an;
		for(const pair<vector<ll>,vector<ll>> &x:g[p^1]){
			vector<ll> a[2],b[2];
			for(auto y:x.fi)a[!!(y&st)].push_back(y^(y&st));
			for(auto y:x.se)b[!!(y&st)].push_back(y^(y&st));
			if(a[0].size()&&b[bj].size())g[p].push_back(mp(a[0],b[bj]));
			if(a[1].size()&&b[bj^1].size())g[p].push_back(mp(a[1],b[bj^1]));
		}
	}
	cout<<ans<<endl;
	return 0;
}
