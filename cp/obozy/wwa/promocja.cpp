#include <bits/stdc++.h>
using namespace std;

#define LL unsigned long long
#define pb push_back
#define pii pair<int, int>
#define st first
#define nd second
#define debug(x) cerr << x << " "

bool cmp(pii a, pii b){
	return a.nd < b.nd;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	
	int n;
	cin >> n;
	vector<pii>a(n);
	for (int i = 0; i<n; i++) {
		cin >> a[i].st;
		a[i].nd = i;
	}
	sort(a.begin(), a.end());
	LL ans = 0LL;
	int x = n/2;
	int granica = a[x-1].st;
	//debug(granica);
	for (int i = 0; i<x; i++)ans+=(LL)a[i].st;
	cout << ans << "\n";
	stack<int>s1, s2;
	sort(a.begin(), a.end(), cmp);
	for (int i = 0; i<n; i++) s1.push(a[i].st);
	while(!s1.empty()){
		while(1){
			if(s2.empty()) break;
			else if(s2.top()>granica && s1.top()>granica) break;
			else if(s2.top()<=granica && s1.top()<=granica) break;
			else {
				cout << s1.top() << " " << s2.top() << "\n";
				s1.pop();
				s2.pop();
			}
		}
		if (!s1.empty()){
			s2.push(s1.top());
			s1.pop();
		}
	}
	return 0;
}
