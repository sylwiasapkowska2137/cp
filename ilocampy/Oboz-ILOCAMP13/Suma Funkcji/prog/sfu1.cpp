//rozwiąznie pierwiastek
//pierwszy komentarz https://discuss.codechef.com/questions/55571/fncs-editorial
#ifdef _WIN32
#  define LL "%I64d"
#else
#  define LL "%Ld"
#endif
 
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <ctime>
#include <vector>
#include <deque>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <bitset>
#include <string>
#include <algorithm>
#include <complex>
#include <utility>
#include <cassert>
using namespace std;
#define null NULL
#define mp make_pair
#define pb(a) push_back(a)
#define sz(a) ((int)(a).size())
#define all(a) a.begin() , a.end()
#define fi first
#define se second
#define relaxMin(a , b) (a) = min((a),(b))
#define relaxMax(a , b) (a) = max((a),(b))
#define SQR(a) ((a)*(a))
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef long long ll;
typedef unsigned long long ull;
#define UNSIGNED "%llu"
#define MAXN 100010
// Array with addition
#define ABLOCK 320
int arr[MAXN] , abid[MAXN];
int abadd[MAXN / ABLOCK + 10];
void prepare(){
  for(int i=0,cnt=0;i<MAXN;i += ABLOCK , ++cnt)
   for(int j=i , up = min(MAXN , i+ABLOCK);
       j < up;++j)
    abid[j] = cnt;
}
#define GET(i) (arr[i] + abadd[abid[i]])
void update(int lo , int hi){
  int blo = abid[lo] , bhi = abid[hi];
  if(blo == bhi){
   for(int i=lo;i<=hi;++i)
    ++arr[i];
                }
  else{
   for(int i=blo+1;i<bhi;++i)
    ++abadd[i];
   int lup = min(MAXN , (blo+1) * ABLOCK);
   int rlo = bhi * ABLOCK;
   for(int i=lo;i<lup;++i)
    ++arr[i];
   for(int i=rlo;i<=hi;++i)
    ++arr[i];
      }
}
// Solution
int N , Q;
int A[MAXN] , L[MAXN] , R[MAXN];
int QT[MAXN] , QX[MAXN] , QY[MAXN];
ull ANS[MAXN] , ADD[MAXN] , REM[MAXN];
void read(){
  scanf("%d" , &N);
  for(int i=0;i<N;++i)
   scanf("%d" , &A[i]);
  for(int i=0;i<N;++i)
   scanf("%d%d" , &L[i] , &R[i]),
   --L[i] , --R[i];
  scanf("%d" , &Q);
  for(int i=0;i<Q;++i){
   scanf("%d%d%d" , &QT[i] , &QX[i] , &QY[i]);
   if(QT[i] == 1) --QX[i];
   else --QX[i] , --QY[i];
                      }
}
// Offline sol
ull sum[MAXN] , seg_sum[MAXN];
ull interval(ull* of , int f , int t){
  if(f == 0) return of[t];
  return of[t] - of[f-1];
}
void init_offline(){
  sum[0] = A[0];
  for(int i=1;i<N;++i)
   sum[i] = sum[i-1] + A[i];
  seg_sum[0] = interval(sum , L[0] , R[0]);
  for(int i=1;i<N;++i)
   seg_sum[i] = seg_sum[i-1] +
                interval(sum , L[i] , R[i]);
}
// main_sol
int nval[MAXN];
vector<pii> sft[MAXN / ABLOCK + 10];
int id[MAXN] , id_used[MAXN] , id_ust = 0;
int name[MAXN];
vector< pair<int , bool> > odr[MAXN];
void additional(){
  for(int i=0;i<N;++i){
   update(L[i] , R[i]);
   vector< pair<int , bool> >& todo = odr[i];
   for(int j=0;j<sz(todo);++j){
    int q = todo[j].fi;
    ull& val = (todo[j].se) ? ADD[q] : REM[q];
    int BL = q / ABLOCK;
    int BBEG = BL * ABLOCK;
    int C = sz(sft[BL]);
    for(int p=0;p<C;++p)
     nval[p] = sft[BL][p].se;
    for(int p=BBEG;p<q;++p)
     if(QT[p] == 1)
      nval[name[p]] = QY[p];
    for(int p=0;p<C;++p){
     ull tmp = GET(sft[BL][p].fi);
     tmp *= nval[p];
     val += tmp;
                        }
                              }
                      }
}
void doit(){
  int cnt;
  int BLOCK = -1;
  for(int ilo = 0;ilo < Q;ilo += ABLOCK){
   ++BLOCK;
   ++id_ust , cnt = 0;
   int ihi = min(Q-1 , ilo + ABLOCK - 1);
   // Removing changed nums
   vector<pii>& CB = sft[BLOCK];
   for(int i=ilo;i<=ihi;++i)
    if(QT[i] == 1){
     int x = QX[i];
     if(id_used[x] != id_ust)
      id_used[x] = id_ust,
      id[x] = cnt++,
      CB.pb(mp(x , A[x])),
      A[x] = 0;
     name[i] = id[x];
                  }
    else{
     odr[QY[i]].pb(mp(i , true));
     if(QX[i] > 0)
      odr[QX[i] - 1].pb(mp(i , false));
        }
   // Offline answers
   init_offline();
   for(int i=ilo;i<=ihi;++i)
    if(QT[i] == 2)
     ANS[i] = interval(seg_sum , QX[i] , QY[i]);
   // Restoring
   for(int i=ilo;i<=ihi;++i)
    if(QT[i] == 1)
     A[QX[i]] = QY[i];
                                        }
  additional();
}
int main(){
  prepare();
  read();
  doit();
  for(int i=0;i<Q;++i){
   if(QT[i] == 1) continue;
   ull out = ANS[i];
   out += ADD[i];
   out -= REM[i];
   printf(UNSIGNED "\n" , out);
                      }
  return 0;
}
