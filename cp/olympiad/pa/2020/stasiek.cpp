#include <bits/stdc++.h>
using namespace std;
int n, a, poc=1, kon=1, ismin, l, p, min1, min2, sum;
bool pom;
int pref[n+1], pref1[n+1];
bool is[n];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    pref[0]=0;
    for(int i=1;i<=n;i++){
        cin>>a;
        pref[i]=pref[i-1]+a;
    }
    pref1[0]=0;
    for(int i=1;i<=n;i++)  pref1[i]=pref[n]-pref[n-i];
    if(pref[n]<0){
        cout<<-1;
        return 0;
    }
    while(kon<n){
        pom=0;
        while(pref[poc]==pref[poc-1]&&kon<n){
            kon++;
            poc=kon;
        }
        ismin=0;
        while((pref[kon]-pref[poc-1]<0||ismin==0||pref[n]-pref[kon]<0)&&kon<n){
            if(pref[kon]<pref[kon-1]){
                    ismin++;
                    if(pref[kon]-pref[poc-1]>=0&&pref[n]-pref[kon]>=0)break;
                }
            kon++;
        }
        while(pref[kon]-pref[poc-1]>0&&poc<kon){
            pom=1;
           if(pref[poc]<pref[poc-1]){
               poc++;
               break;
           } poc++;
        }
        if(pom==1)poc--;
        for(int i=poc;i<=kon;i++)   is[i-1]=1;
        //cout<<poc<<' '<<kon<<endl;
        kon++;
        poc=kon;
    }
    poc=1;
    kon=1;
    while(kon<n)
    {
        pom=0;
        while(pref1[poc]==pref1[poc-1]&&kon<n)
        {
            //cout<<poc<<endl;
            kon++;
            poc=kon;
        }
        ismin=0;
        while((pref1[kon]-pref1[poc-1]<0||ismin==0||pref1[n]-pref1[kon]<0)&&kon<n)
        {
            if(pref1[kon]<pref1[kon-1])
                {
                    ismin++;
                    if(pref1[kon]-pref1[poc-1]>=0&&pref1[n]-pref1[kon]>=0)break;
                }
            kon++;
        }
        while(pref1[kon]-pref1[poc-1]>0&&poc<kon)
        {
            pom=1;
           if(pref1[poc]<pref1[poc-1])
           {
               poc++;
               break;
           }
           poc++;
        }
        if(pom==1)poc--;
        for(int i=poc;i<=kon;i++)
        {
            is[n-i]=1;
        }
        //cout<<poc<<' '<<kon<<endl;
        kon++;
        poc=kon;
    }
    for(int i=0;i<n;i++)
    {
        if(is[i]==1)
        {
            l=i+1;
            while(is[i]==1&&is[i+1]==1)
            {
                i++;
            }
            p=i+1;
            min1=0;
            min2=0;
            poc=l;
            kon=l;

            while(kon<p)
        {
            pom=0;
            while(pref[poc]==pref[poc-1]&&kon<p)
            {
                //cout<<poc<<endl;
                kon++;
                poc=kon;
            }
            ismin=0;
            while((pref[kon]-pref[poc-1]<0||ismin==0||pref[p]-pref[kon]<0)&&kon<p)
            {
                if(pref[kon]<pref[kon-1])
                {
                    ismin++;
                    if(pref[kon]-pref[poc-1]>=0&&pref[p]-pref[kon]>=0)break;
                }
                kon++;
            }
            while(pref[kon]-pref[poc-1]>0&&poc<kon)
            {
                pom=1;
                if(pref[poc]<pref[poc-1])
            {
                poc++;
                break;
            }
            poc++;
            }
            if(pom==1)poc--;
            if(ismin!=0)
            {
                min1+=(kon-poc);
            //cout<<min1<<endl;
               // cout<<poc<<' '<<kon<<endl;
            }
        kon++;
        poc=kon;
    }
    //cout<<min1;
    l=n-l+1;
    p=n-p+1;
    poc=p;
    kon=p;
    while(kon<l){
        pom=0;
        while(pref1[poc]==pref1[poc-1]&&kon<l){
            //cout<<poc<<endl;
            kon++;
            poc=kon;
        }
        ismin=0;
        while((pref1[kon]-pref1[poc-1]<0||ismin==0||pref1[l]-pref1[kon]<0)&&kon<l) {
            if(pref1[kon]<pref1[kon-1]){
                    ismin++;
                    if(pref1[kon]-pref1[poc-1]>=0&&pref1[l]-pref1[kon]>=0)break;
                }
            kon++;
        }
        while(pref1[kon]-pref1[poc-1]>0&&poc<kon) {
            pom=1;
           if(pref1[poc]<pref1[poc-1]){
               poc++;
               break;
           }
           poc++;
        }
        if(pom==1)poc--;
        if(ismin!=0)
        min2+=(kon-poc);
        kon++;
        poc=kon;
    }
        sum+=min(min1, min2);
        }
    }
    cout<<sum;
    return 0;
}
