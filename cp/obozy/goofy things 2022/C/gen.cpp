#include <bits/stdc++.h>
using namespace std;;

const long long MOD = 1e9+7;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
int p(int a, int b){
    return rng()%(b-a+1)+a;
}

void solve(){
    int n = p(1, 5);
    cout << n << "\n";
    set<pair<int, int>>s;
    while (n){
        int a = p(1, 5);
        int b = p(1, 5);
        if (s.find({a, b}) == s.end()){
            s.insert({a, b});
            cout << a << " " << b << "\n";
            n--;
        }
    }
}

void solve2(){
    int n = p(1, 2137);
    cout << n << "\n";
    for (int i = 0; i<n; i++){
        int j = p(1, 20);
        for (int k =0; k<j; k++){
            cout << (char)('a'+p(0, 10));
        }
        cout << "\n";
    }
}

int main(){
    solve2();
}