

const int INF=1000000000+5;
const int N=1e4+5;
//~ const int N=30+5;
const int M=30;
const ll oo=LLONG_MAX;
const int mod=998244353;

string s;
int m;
int needMask;
int pw[N];

void add_self(int& a,int b){
	a+=b;
	if(a>=mod) a-=mod;
}

int mul(int a,int b){
	return 1ll*a*b%mod;
}

int poww(int a,int b){
	int r=1;
	while(b){
		if(b&1) r=mul(r,a);
		a=mul(a,a);
		b>>=1;
	}
	return r;
}

int n;
pair<int,int> dp[N][2][2][1<<10];

pair<int,int> solve(int pos,int zero,int tight,int mask){
	if(pos==n){
		if((mask&needMask)==needMask&&!zero){
			return {1,0};
		}
		else{
			return {0,0};
		}
	}
	pair<int,int>& ret=dp[pos][zero][tight][mask];
	if(ret.first>=0) return ret;
	ret={0,0};
	int x=s[pos]-'0';
	for(int k=0;k<10;++k){
		if(tight&&k>x) break;
		int new_zero=zero&&k==0;
		int new_tight=tight&&k==x;
		int new_mask=mask;
		if(k>0||!zero) new_mask|=(1<<k);
		pair<int,int> next=solve(pos+1,new_zero,new_tight,new_mask);
		add_self(ret.first,next.first);
		add_self(ret.second,next.second);
		add_self(ret.second,mul(pw[n-1-pos],mul(next.first,k)));
	}
	return ret;
}



int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	cin>>s;
	n=(int)s.size();
	cin>>m;
	for(int i=0;i<m;++i){
		int x;
		cin>>x;
		needMask|=(1<<x);
	}
	pw[0]=1;
	for(int i=1;i<=n;++i) pw[i]=mul(pw[i-1],10);
	for(int i=0;i<n;++i){
		for(int zero=0;zero<2;++zero){
			for(int tight=0;tight<2;++tight){
				for(int mask=0;mask<(1<<10);++mask){
					dp[i][zero][tight][mask]={-1,-1};
				}
			}
		}
	}
	pair<int,int> ans=solve(0,1,1,0);
	cout<<ans.second<<endl;
	return 0;
}


