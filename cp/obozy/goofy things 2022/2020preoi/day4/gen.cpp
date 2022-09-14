#include <bits/stdc++.h>
using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int p(int a, int b){
    return a+rng()%(b-a+1);
}

vector<int>kmp(string &s){
	int n = (int)s.size();
	vector<int>pi(n);
	for (int i = 1; i<n; i++){
		int j = pi[i-1];
		while (j && s[i]!=s[j]) j = pi[j-1];
		if (s[i] == s[j]) j++;
		pi[i] = j;
	}
	return pi;
}


void solve(){
    int t = p(1, 10);
    cout << t << "\n";
    while (t--){
        int n = p(1, 20);
        cout << n << "\n";
        string s;
        for (int i = 0; i<n; i++){
            int x = p(0, 1);
            s += (char)(x+'a');
        }
        vector<int>pi = kmp(s);
        for (int i = 0; i<n; i++){
            int x = p(1, 100);
            if (!x){
                pi[i] = p(0, max(0, i-1));
            }
        }
        for (auto x: pi) cout << x << " ";
        cout << "\n";
    }
}

void solve2(){
    int n = p(1, 20);
    cout << n << "\n";
    for (int i = 2; i<=n; i++){
        cout << i << " " << p(1, i-1) << "\n";
    }
    for (int i = 1; i<=n; i++) cout << p(1, 10) << " ";
    cout << "\n";
    int q = p(1, 5);
    cout << q << "\n";
    while (q--){
        int t = p(0, 1);
        if (t == 1){
            cout << "Q " << p(1, n) << " " << p(1, n) << "\n";
        } else {
            cout << "C " << p(1, n) << " " << p(1, n) << " " << p(1, 10) << "\n";
        }
    }
}

int main(){
    solve2();
}