#include <bits/stdc++.h>
using namespace std;

#define LL long long
#define pb push_back
#define pii pair<int, int>
#define st first
#define nd second
#define debug(x) cerr << x << " "

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    LL m, d, ptr = 0, tmp;
    int n, ans = 1;
    cin >> m >> d >> n;
    vector<LL>a(n);
    for (int i = 0; i<n; i++) cin >> a[i];

    sort(a.begin(), a.end());
    //for (auto x: a) debug(x);
    //cerr << "\n";
    int last = lower_bound(a.begin(), a.end(), m-d)-a.begin();
    if (last >= n) {
		cout << "0\n";
		return 0;
	}
	//debug(last);
	LL end = (m+d-a[last]+1)/2;
    for (int i = n-1; i>=0; i--){
		if (ptr>=end) break;
        if (i == last) continue;
        tmp = a[i]-d+ptr;
        //if (tmp <= 0){
            //cout << "0\n";
            //return 0;
        //}
        ptr+=tmp;
        ans++;
    }
    //debug(ptr);
    if (ptr < end) cout << "0\n";
    else cout << ans << "\n";
    return 0;
}
