#include<bits/stdc++.h>
#define loop(i,j,s) for(int i=j;i<s;i++)
#define loopback(i,j,s) for(int i=j;i>=s;i--)
#define pln( x ) cout << x << "\n"
#define ps( x ) cout << x << " "
#define entr cout << "\n"
#define pcnt(i) __builtin_popcount(i)
#define ll long long
using namespace std;
const int INFTY=20000000;
const int MAX=500100;
const int MOD=10000000;
 
void coutTab(int* tab,int n){
        loop(i,0,n){
                cout<<tab[i]<<" ";
        }
        cout<<"\n";
}
//------------------------------------------
struct pnt{
        int x,y;
};
struct segment{
        pnt a, b;
};
pnt P,K;
int n;
vector<segment> sgmnts;
segment make_segment(pnt a, pnt b){
        segment s;
        s.a=a;
        s.b=b;
        return s;
}
ll coef[2][2];
ll getCoef(pnt A,pnt B,pnt C){
        coef[0][0]=B.x-A.x;
        coef[0][1]=B.y-A.y;
        coef[1][0]=C.x-A.x;
        coef[1][1]=C.y-A.y;
        return coef[0][0]*coef[1][1]-coef[0][1]*coef[1][0];
}
bool intersect(segment sa, segment sb){
        pnt A=sa.a;
        pnt B=sa.b;
        pnt C=sb.a;
        pnt D=sb.b;
        ll d1=getCoef(A,B,C);
        ll d2=getCoef(A,B,D);
        ll d3=getCoef(C,D,A);
        ll d4=getCoef(C,D,B);
        if(((d1>0&&d2<0)||(d1<0&&d2>0))&&((d3>0&&d4<0)||(d3<0&&d4>0)))
                return 1;
        return  0;                     
}
segment intersectedSegment(segment s){
        loop(i,0,sgmnts.size()){
                if(intersect(s,sgmnts[i]))
                        return sgmnts[i];
        }
        pnt s0;
        s0.x=0;
        s0.y=0;
        return make_segment(s0,s0);
}
double d(pnt A, pnt B){
        return sqrt((A.x-B.x)*(A.x-B.x)+(A.y-B.y)*(A.y-B.y));
}
double go(segment s){
        segment intrsct = intersectedSegment(s);
        if(intrsct.a.x==0&&intrsct.a.y==0&&intrsct.b.x==0&&intrsct.b.y==0){
                return d(s.a,s.b);
        }
        return min(go(make_segment(s.a,intrsct.a))+go(make_segment(intrsct.a,s.b)),go(make_segment(s.a,intrsct.b))+go(make_segment(intrsct.b,s.b)));
}
int main(){
        ios_base::sync_with_stdio(0);
        cin>>n;
        cin>>P.x>>P.y>>K.x>>K.y;
        pnt a,b,c,d;
        loop(i,0,n){
                cin>>a.x>>a.y>>c.x>>c.y;
                b.x=c.x;
                b.y=a.y;
                d.x=a.x;
                d.y=c.y;
                sgmnts.push_back(make_segment(a,b));
                sgmnts.push_back(make_segment(b,c));
                sgmnts.push_back(make_segment(c,d));
                sgmnts.push_back(make_segment(d,a));
        }
        loop(i,0,sgmnts.size()){
                cout<<sgmnts[i].a.x<<" "<<sgmnts[i].a.y<<" "<<sgmnts[i].b.x<<" "<<sgmnts[i].b.y<<"\n";
        }
        cout<<fixed<<setprecision(8)<<go(make_segment(P,K));
}
