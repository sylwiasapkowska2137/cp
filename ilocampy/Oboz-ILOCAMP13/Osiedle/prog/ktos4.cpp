#include <bits/stdc++.h>
#define LL long long
#define LFF long double
using namespace std;

struct point{
    int x,y;
};
point make_point(int x,int y){point temp; temp.x=x;temp.y=y;return temp;}
point A,B;
int N;
vector<pair <point,point> > blocked;
point point_id[3000];
vector <int> pol[3000];
bool czy_polaczone[3000][3000];
LFF cost[3000];
LFF f_odl(point a,point b){
    LFF x=(long long)(a.x-b.x)*(a.x-b.x)+(long long)(a.y-b.y)*(a.y-b.y);
    return sqrtl(x);
}
void bfs(){
    priority_queue <pair <LFF,int> > quelele;
    quelele.push(make_pair(0,N*4));
    cost[N*4]=0;
    while (!quelele.empty()){
        int ak=quelele.top().second;
        quelele.pop();
        for (int i=0; i<pol[ak].size();i++){
            LFF odl=f_odl(point_id[pol[ak][i]],point_id[ak]);
            if (cost[pol[ak][i]]>cost[ak]+odl){
                cost[pol[ak][i]]=cost[ak]+odl;
                quelele.push(make_pair(-cost[pol[ak][i]],pol[ak][i]));
            }
        }

    }


}
long long ilo_wek(point a,point b,point c){
    return ((LL)a.x*(LL)b.y)+((LL)b.x*(LL)c.y)+((LL)c.x*(LL)a.y)-((LL)a.y*(LL)b.x)-((LL)b.y*(LL)c.x)-((LL)c.y*(LL)a.x);
}
int main(){
    scanf ("%d %d %d %d %d ", &N, &A.x, &A.y, &B.x, &B.y);
    point ta,tb;
    int pointN=N*4+2;
    point_id[N*4]=A;
    point_id[N*4+1]=B;
    for (int i=0;i<N;i++){
        scanf ("%d %d %d %d", &ta.x,&ta.y,&tb.x,&tb.y);
        point_id[i*4]  =ta;
        point_id[i*4+1]=make_point(ta.x,tb.y);
        point_id[i*4+3]=make_point(tb.x,ta.y);
        point_id[i*4+2]=tb;
        blocked.push_back(make_pair(ta,make_point(ta.x,tb.y)));
        blocked.push_back(make_pair(ta,make_point(tb.x,ta.y)));
        blocked.push_back(make_pair(make_point   (ta.x,tb.y),tb));
        blocked.push_back(make_pair(make_point   (tb.x,ta.y),tb));
        blocked.push_back(make_pair(make_point   (tb.x,ta.y),make_point   (ta.x,tb.y)));
        blocked.push_back(make_pair(ta,tb));
    /*    czy_polaczone[i*4]  [i*4+1]=1;///SPRAWDZ
        czy_polaczone[i*4+1][i*4+2]=1;
        czy_polaczone[i*4+2][i*4+3]=1;
        czy_polaczone[i*4+3][i*4]=1;
        czy_polaczone[i*4]  [i*4+3]=1;///SPRAWDZ
        czy_polaczone[i*4+1][i*4]=1;
        czy_polaczone[i*4+2][i*4+1]=1;
        czy_polaczone[i*4+3][i*4+2]=1;
        pol[i*4].push_back(i*4+1);
        pol[i*4].push_back(i*4+3);
        pol[i*4+1].push_back(i*4);
        pol[i*4+1].push_back(i*4+2);
        pol[i*4+2].push_back(i*4+1);
        pol[i*4+2].push_back(i*4+3);
        pol[i*4+3].push_back(i*4);
        pol[i*4+3].push_back(i*4+2);*/
    }

    for (int i=0; i<pointN;i++){
        point ak=point_id[i];
        for (int q=0;q<pointN;q++){
            if (i!=q and czy_polaczone[i][q]==0){
                ///czy da sie polaczyc?
                bool ok=1;
                for (int ibn=0; ibn<blocked.size();ibn++){
                    point k=ak,l=point_id[q],m=blocked[ibn].first,n=blocked[ibn].second;

                    if ((LFF)ilo_wek(k,l,m)*ilo_wek(k,l,n)<0LL and (LFF)ilo_wek(m,n,k)*ilo_wek(m,n,l)<0LL){
                        ///przecina sie
                        ok=0;
                        break;
                    }

                }
                if (ok and czy_polaczone[i][q]==0 and czy_polaczone[q][i]==0){
                        ///tworz droge
                        czy_polaczone[i][q]=1;
                        czy_polaczone[q][i]=1;
                        pol[i].push_back(q);
                        pol[q].push_back(i);
                        }


            }
        }
    }
///BFS
    fill (cost,cost+2900,((LL)1<<30)*((LL)1<<30));
    bfs();
    cerr << fixed << setprecision(9) << cost[pointN - 1] << endl;
    printf ("%.9Lf\n", cost[pointN-1]);
    return 0;
}
