#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int N = (int)1e5+7;
int num[N];
int hasz[N],cnt[N];
int main(){
        int n,k;cin >> n>> k;
        for(int i = 0; i< n; i++)
                scanf("%d",&num[i]);
        sort(num,num+n);
        int tmp = 0,len = 0;
        for(int i = 0; i < n; i++){
                tmp++;
                if(num[i] != num[i+1] || i == n-1){
                        hasz[len] = num[i]; cnt[len] = tmp; tmp = 0;
                        len ++;
                }}
        int sum = cnt[0]; int ans = hasz[0];
        for(int i = 1; i < len; i++) {
                long long t = 0; int s = cnt[i];
                for(int j = i-1; j >=0; j--){
                        long long v = 1LL*(hasz[i] - hasz[j])*cnt[j];
                        if(t + v >= k) {
                                s += (k - t) / (hasz[i] - hasz[j]);
                                break;
                        }
                        t += v; s+= cnt[j];
                }
                if(s > sum) {
                        sum = s; ans = hasz[i];
                }
        }
        cout<< sum << " "<< ans<<endl;
}