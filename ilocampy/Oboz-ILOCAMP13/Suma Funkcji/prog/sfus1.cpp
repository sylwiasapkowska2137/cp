#include <bits/stdc++.h>
 
#define F first
#define S second
#define pb push_back
#define FOR(i,lb,ub) for(i=lb;i<=ub;i++)
#define RFOR(i,ub,lb) for(i=ub;i>=lb;i--)
#define FORS(it,v) for(it=v.begin();it!=v.end();it++)
#define int long long
#define show_time cout<<"\tTIME="<<(en-st)/CLOCKS_PER_SEC<<endl;
int gcd(int a, int b) { return b?gcd(b,a%b):a; }
using namespace std;
int tree[100005], l[100005], r[100005], MaxVal;
void update(int idx ,int val){
    while (idx <= MaxVal){
		tree[idx] += val;
		idx += (idx & -idx);
	}
}
int read(int idx){
    int sum = 0;
	while (idx > 0){
		sum += tree[idx];
		idx -= (idx & -idx);
	}
	return sum;
}
#undef int
int main()
{
#define int long long
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int i;
    int n;
    cin>>n;
    MaxVal = n;
    FOR(i,1,n)
    {
        int x;
        cin>>x;
        update(i,x);
    }
    FOR(i,1,n)
    {
        cin>>l[i]>>r[i];
    }
    int q;
    cin>>q;
    while (q--)
    {
        int c,x,y;
        cin>>c>>x>>y;
        if (c==1)
        {
            int z = read(x) - read(x-1);
            update(x,y-z);
        }
        else
        {
            int ans=0;
            FOR(i,x,y)
            {
                ans += read(r[i]) - read(l[i]-1);
            }
            cout<<ans<<endl;
        }
    }
    
    return 0;
} 
