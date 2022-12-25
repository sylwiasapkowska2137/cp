#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
#define PB push_back
#define MP make_pair
#define ALL(v) (v).begin(),(v).end()
#define SZ(v) (int)v.size()
namespace library{
    using u32=unsigned int;
    using u64=unsigned long long;
    template<typename T> bool chmin(T &a,const T &b){ if(a>b){ a=b; return 1;} return 0;}
    template<typename T> bool chmax(T &a,const T &b){ if(a<b){ a=b; return 1;} return 0;}
    template<typename T> T gcd(T a,T b){ return b?library::gcd(b,a%b):a;}
    template<typename T> T lcm(T a,T b){ return a/library::gcd(a,b)*b;}
    template<typename T,typename U> T pow(T a,U n){ return n?(n&1?a:1)*library::pow(a*a,n>>1):1;}
    u64 sqrt(u64 n){ u64 l=0,r=4294967296; while(r-l>1) (((l+r)/2)*((l+r)/2)<=n?l:r)=(l+r)/2; return l;}
    u32 rand(){ static std::mt19937 mt(std::chrono::steady_clock::now().time_since_epoch().count()); return mt();}
    u32 rand(u32 upper){ return library::rand()%upper;}
    u64 randll(){ static std::mt19937_64 mt(std::chrono::steady_clock::now().time_since_epoch().count()); return mt();}
    u64 randll(u64 upper){ return library::randll()%upper;}
    void iosetup(){ std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout<<std::fixed<<std::setprecision(15);}
    const int mod9=998244353,mod10=1000000007;
    const int inf=std::numeric_limits<int>::max();
    const int64_t infll=std::numeric_limits<int64_t>::max();
    template<typename T> int find(const std::vector<T> &v,const T &x,const std::string &ieq,int l,int r){
        int idx=-1;
        if(ieq=="<"||ieq==">=") idx=upper_bound(v.begin()+l,v.begin()+r,x)-v.begin()-(ieq=="<"?0:1);
        if(ieq==">"||ieq=="<=") idx=lower_bound(v.begin()+l,v.begin()+r,x)-v.begin()-(ieq==">"?1:0);
        return idx;
    }
    template<typename T> int find(const std::vector<T> &v,const T &x,const std::string &ieq){ return find(v,x,ieq,0,(int)v.size());}
    template<typename T> T get(const std::vector<T> &v,const T &x,const std::string &ieq,int l,int r){
        int idx=find(v,x,ieq,l,r);
        return idx==l-1?numeric_limits<T>::min():(idx==r?numeric_limits<T>::max():v[idx]);
    }
    template<typename T> T get(const std::vector<T> &v,const T &x,const std::string &ieq){ return get(v,x,ieq,0,(int)v.size());}
    template<typename T> int count(const std::vector<T> &v,const T &x,const std::string &ieq,int l,int r){
        if(ieq=="<") return r-(upper_bound(v.begin()+l,v.begin()+r,x)-v.begin());
        if(ieq=="<=") return r-(lower_bound(v.begin()+l,v.begin()+r,x)-v.begin());
        if(ieq==">") return lower_bound(v.begin()+l,v.begin()+r,x)-v.begin()-l;
        if(ieq==">=") return upper_bound(v.begin()+l,v.begin()+r,x)-v.begin()-l;
        return upper_bound(v.begin()+l,v.begin()+r,x)-lower_bound(v.begin()+l,v.begin()+r,x);
    }
    template<typename T>
    int count(const std::vector<T> &v,const T &x,const std::string &ieq){ return count(v,x,ieq,0,(int)v.size());}
    template<typename T> int find_nearest(const std::vector<T> &v,const T &x,int l,int r){
        int idxr=lower_bound(v.begin()+l,v.begin()+r,x)-v.begin(),idxl=idxr-1;
        return (idxl==l-1?idxr:(idxr==r?idxl:(v[idxr]-x>x-v[idxl]?idxl:idxr)));
    }
    template<typename T> int find_nearest(const std::vector<T> &v,const T &x){ return find_nearest(v,x,0,(int)v.size());}
    template<typename T> int get_nearest(const std::vector<T> &v,const T &x,int l,int r){ return v[find_nearest(v,x,l,r)];}
    template<typename T> int get_nearest(const std::vector<T> &v,const T &x){ return get_nearest(v,x,0,(int)v.size());}
}
#define li library
template<typename T,typename U> ostream& operator<<(ostream &os,const pair<T,U> &p){ return os<<p.first<<" "<<p.second;}
/*--------------------------------------------------------------------------------------------------------------------*/

template<typename T=std::string,int type=26,int base='a'>
struct suffix_array{

    public:
    T s;
    const std::vector<int> SA;

    suffix_array(const T &s_):s(s_),SA(build_suffix_array<T,type,base>(s)){}

    template<typename T_=std::string,int type_=26,int base_='a'>
    static std::vector<int> build_rotate_array(const T_ &v){
        int N=(int)v.size(),S=0;
        std::vector<int> p(N),c(N),cnt(type_,0),tmp(type_);
        for(int i=0;i<N;i++) cnt[v[i]-base_]++;
        for(int i=1;i<type_;i++) cnt[i]+=cnt[i-1];
        for(int i=0;i<N;i++){
            if(v[i]-base_) p[cnt[v[i]-base_-1]+tmp[v[i]-base_]++]=i;
            else p[tmp[v[i]-base_]++]=i;
        }
        c[p[0]]=0;
        for(int i=1;i<N;i++){
            if(v[p[i]]!=v[p[i-1]]) S++;
            c[p[i]]=S;
        }
        S++;

        std::vector<int> np(N),nc(N);
        for(int k=0;(1<<k)<N;k++){
            cnt.assign(S,0),tmp.assign(S,0);
            for(int i=0;i<N;i++){
                p[i]-=(1<<k);
                if(p[i]<0) p[i]+=N;
            }
            for(int i=0;i<N;i++) cnt[c[p[i]]]++;
            for(int i=1;i<S;i++) cnt[i]+=cnt[i-1];
            for(int i=0;i<N;i++){
                if(c[p[i]]) np[cnt[c[p[i]]-1]+tmp[c[p[i]]]++]=p[i];
                else np[tmp[c[p[i]]]++]=p[i];
            }

            S=0;
            nc[np[0]]=S;
            for(int i=1;i<N;i++){
                int bef=np[i-1]+(1<<k),aft=np[i]+(1<<k);
                if(bef>=N) bef-=N;
                if(aft>=N) aft-=N;
                if(c[np[i-1]]!=c[np[i]]||c[bef]!=c[aft]) S++;
                nc[np[i]]=S;
            }
            S++;
            swap(p,np),swap(c,nc);
        }
        return p;
    }

    template<typename T_=std::string,int type_=26,int base_='a'>
    static std::vector<int> build_suffix_array(T_ &v){
        v.resize(v.size()+1);
        v[v.size()-1]=base_-1;
        auto res=build_rotate_array<T_,type_+1,base_-1>(v);
        v.resize(v.size()-1);
        res.erase(res.begin());
        return res;
    }

    template<typename T_=std::string>
    int lower_bound(const T_ &t) const {
        int left=0,right=(int)s.size();
        std::function<bool(int)> comp=[&](const int idx){
            int ls=(int)s.size(),lt=(int)t.size(),l=std::min(ls-idx,lt);
            for(int i=0;i<l;i++){ if(s[idx+i]<t[i]) return false; if(s[idx+i]>t[i]) return true;}
            return l==lt;
        };
        if(comp(SA[0])) return left;
        if(!comp(SA[right-1])) return right;
        while(right-left>1){
            int mid=(left+right)/2;
            if(comp(SA[mid])) right=mid;
            else left=mid;
        }
        return right;
    }

    template<typename T_=std::string>
    int upper_bound(const T_ &t) const {
        int left=0,right=(int)s.size();
        std::function<bool(int)> comp=[&](const int idx){
            int ls=(int)s.size(),lt=(int)t.size(),l=std::min(ls-idx,lt);
            for(int i=0;i<l;i++){ if(s[idx+i]<t[i]) return false; if(s[idx+i]>t[i]) return true;}
            return false;
        };
        if(comp(SA[0])) return left;
        if(!comp(SA[right-1])) return right;
        while(right-left>1){
            int mid=(left+right)/2;
            if(comp(SA[mid])) right=mid;
            else left=mid;
        }
        return right;
    }

    template<typename T_=std::string>
    std::vector<int> find(const T_ &t) const {
        int left=lower_bound(t),right=upper_bound(t);
        std::vector<int> res(right-left);
        for(int i=left;i<right;i++) res[i-left]=SA[i];
        sort(res.begin(),res.end());
        return res;
    }

    template<typename T_=std::string>
    int count(const T_ &t) const {
        return upper_bound(t)-lower_bound(t);
    }

    template<typename T_=std::string>
    bool contain(const T_ &t) const {
        return (bool)(upper_bound(t)-lower_bound(t));
    }

    void print() const {
        for(int i=0;i<(int)s.size();i++){
            std::cout<<i<<" : "<<s.substr(SA[i])<<" ("<<SA[i]<<") "<<std::endl;
        }
    }
};

int main(){
    int N; cin>>N;
    string S,T; cin>>S>>T;
    string U;
    U+=S;
    U+=S;
    U+=('a'-1);
    U+=T;
    U+=T;
    U+=('z'+1);
    suffix_array<string,28,(int)'a'-1> sa(U);
    const auto &SA=sa.SA;
    ll ans=0;
    int cnt=N;
    for(int i=0;i<4*N+2;i++){
        if(0<=SA[i]&&SA[i]<N){
            ans+=cnt;
        }else if(2*N+1<=SA[i]&&SA[i]<3*N+1){
            cnt--;
        }
    }
    cout<<ans<<endl;
    return 0;
}