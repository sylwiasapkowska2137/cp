#include <bits/stdc++.h>

using namespace std;
#define pb push_back

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;
        vector <int> a(n+1);
        for(int i = 1; i <= n; i++){
            cin >> a[i];
        }
        vector <int> v;
        a[0] = 0;
        for(int i = 1; i <= n; i++){
            if(a[i] != a[i-1]) v.pb(a[i]);
        }
        int ans = n+1;
        vector <int> lic;
        lic.assign(n+1, 1);
        for(int i = 0; i < (int)v.size(); i++){
            lic[v[i]]++;
        }
        for(int i = 1; i <= n; i++){
            if(lic[i] > 1) {
                if(i == v[n-1]) lic[i]--;
                if(i == v[0]) lic[i]--;
                ans = min(ans, lic[i]);
            }
        }
        if(v.size() == 1) ans = 0;
        cout << ans << "\n";
    }

    return 0;
}