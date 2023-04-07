#include<bits/stdc++.h>
using namespace std;
const int mod=1000000007;
int fnd(int x,int *f){if(x!=f[x])f[x]=fnd(f[x],f);return f[x];}
int fa[18][400003],n,pa[18][200003],f[200003];
int dep[200003],ans=1;
int l[200003],r[200003];

int mypow(int x,int times){
	int ret=1;
	while(times){
		if(times&1)
			ret=1ll*ret*x%mod;
		times>>=1;
		x=1ll*x*x%mod;
	}return ret;
}

int lca(int x,int y){
	if(dep[x]<dep[y])swap(x,y);
	for(int i=17;i>=0;i--)
		if(dep[x]-dep[y]&(1<<i))
			x=pa[i][x];
	if(x==y)return x;
	for(int i=17;i>=0;i--)
		if(pa[i][x]!=pa[i][y])
			x=pa[i][x],y=pa[i][y];
	return pa[0][x];
}

void merge(int x,int y){
	x=fnd(x,f);y=fnd(y,f);
	if(x==y)return;
	f[x]=y;
	ans=1ll*ans*mypow(r[x]-l[x]+1,mod-2)%mod;
	ans=1ll*ans*mypow(r[y]-l[y]+1,mod-2)%mod;
	l[y]=max(l[y],l[x]);r[y]=min(r[y],r[x]);
	ans=ans*max(0ll,r[y]-l[y]+1ll)%mod;
}

void merge2(int x,int y,int t){
	if(fnd(x,fa[t])==fnd(y+n,fa[t]))
		return;
	if(t==0){
		merge(x,y);
		return;
	}
	fa[t][fnd(x,fa[t])]=fnd(y+n,fa[t]);
	fa[t][fnd(x+n,fa[t])]=fnd(y,fa[t]);
	merge2(x,pa[t-1][y],t-1);
	merge2(pa[t-1][x],y,t-1);
}

void merge1(int x,int y,int t){
	if(fnd(x,fa[t])==fnd(y,fa[t]))
		return;
	if(t==0){
		merge(x,y);
		return;
	}
	fa[t][fa[t][x]]=fa[t][y];
	merge1(x,y,t-1);
	merge1(pa[t-1][x],pa[t-1][y],t-1);
}

vector<int>v[200003];
void dfs(int x){
	f[x]=x;
	for(int i=1;i<18;i++)
		if(pa[i-1][x]==-1)
			pa[i][x]=-1;
		else
			pa[i][x]=pa[i-1][pa[i-1][x]];
	for(int i=0;i<18;i++)
		fa[i][x]=x,fa[i][x+n]=x+n;
	for(auto y:v[x])
		dep[y]=dep[x]+1, 
		dfs(y);
}

int kthpa(int x,int t){
	for(int i=0;i<18;i++)
		if(t&(1<<i))
			x=pa[i][x];
	return x;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>n;
	for(int i=0;i<18;i++)
		fa[i][n]=n;
	pa[0][0]=-1;
	for(int i=1;i<n;i++)
		cin>>pa[0][i],pa[0][i]--,
		v[pa[0][i]].push_back(i);
	dfs(0);
	for(int i=0;i<n;i++)
	{
		cin>>l[i]>>r[i];
		ans=(r[i]-l[i]+1ll)*ans%mod;
	}
	int T;
	cin>>T;
	while(T--){
		int a,b,c,d,e,f,t;
		cin>>a>>b>>d>>e;
		a--;b--;d--;e--;
		c=lca(a,b);f=lca(d,e);
		t=min(dep[a]-dep[c],dep[d]-dep[f]);
		for(int i=17;i>=0;i--)
			if(t&(1<<i))
				merge1(a,d,i),
				a=pa[i][a],
				d=pa[i][d];
		t=min(dep[b]-dep[c],dep[e]-dep[f]);
		for(int i=17;i>=0;i--)
			if(t&(1<<i))
				merge1(b,e,i),
				b=pa[i][b],
				e=pa[i][e];
		if(a==c){
			t=dep[b]-dep[c]+1;
			for(int i=17;i>=0;i--)
				if(t&(1<<i))
					t=t^(1<<i), 
					merge2(b,kthpa(d,t),i),
					b=pa[i][b];
		}
		else{
			t=dep[a]-dep[c]+1;
			for(int i=17;i>=0;i--)
				if(t&(1<<i))
					t^=(1<<i),
					merge2(a,kthpa(e,t),i),
					a=pa[i][a];
		}
		cout<<ans<<'\n'; 
	}
}
