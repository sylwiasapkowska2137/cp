#include <bits/stdc++.h>
using namespace std;
 
#define LL long long
#define debug(x) cerr << x << " "
#define st first
#define nd second
 
void radix_sort(vector <pair<pair<int, int>, int>> &a){
	int n = a.size();
	vector <int> cnt(n), pos(n);
	for (auto x: a) cnt[x.st.nd]++;
	vector <pair<pair<int, int>, int>> a2(n);
	pos[0] = 0;
	for (int i = 1; i<n; i++) pos[i] = pos[i-1]+cnt[i-1];
	for (auto x: a){
		a2[pos[x.st.nd]] = x;
		pos[x.st.nd]++;
	}
	a = a2;
	
	vector <int> cnt(n), pos(n);
	for (auto x: a) cnt[x.st.st]++;
	vector <pair<pair<int, int>, int>> a2(n);
	pos[0] = 0;
	for (int i = 1; i<n; i++) pos[i] = pos[i-1]+cnt[i-1];
	for (auto x: a){
		a2[pos[x.st.st]] = x;
		pos[x.st.st]++;
	}
	a = a2;
}
 
int main(){ //n log^2 n
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	string s;
	cin >> s;
	s+="$";
	int n = s.size();
	vector <int>p(n), c(n);//p - porzadek sufiksow, c - ich klasy
		vector <pair<char, int>> a(n);
		for (int i = 0; i<n; i++) a[i] = {s[i], i};
		sort(a.begin(), a.end());
		for (int i = 0; i<n; i++) p[i] = a[i].nd;
		c[p[0]] = 0;
		for (int i = 1; i<n; i++){
			if(a[i].st == a[i-1].st) c[p[i]] = c[p[i-1]];
			else c[p[i]] = c[p[i-1]]+1;
		}
	int k = 0;
	while ((1<<k) < n){
		vector <pair<pair<int, int>, int>>a(n);
		for (int i = 0; i<n; i++){
			a[i] = {{c[i], c[(i+(1<<k))%n]}, i};
		}
		radix_sort(a);
		for (int i = 0; i<n; i++) p[i] = a[i].nd;
		c[p[0]] = 0;
		for (int i = 1; i<n; i++){
			if(a[i].st == a[i-1].st) c[p[i]] = c[p[i-1]];
			else c[p[i]] = c[p[i-1]]+1;
		}
		k++;
	}
	for (int i = 0; i<n; i++)cout << p[i] << " ";
	return 0;
}
