//https://goofy.ilo.pl/team/problem.php?id=1329
#include <bits/stdc++.h>

using namespace std;

const int MAX = 30;
int freq1[MAX], freq2[MAX];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int mini, suma = 0;
	string a, b;
	cin >> a >> b;
	for (int i = 0; i<(int)a.length(); i++) {
		freq1[a[i]-'a']++;
	}
	for (int i = 0; i<(int)b.length(); i++) {
		freq2[b[i]-'a']++;
	}
	for (int i = 0; i < 28; i++){
		mini = min(freq1[i], freq2[i]);
		freq1[i] = mini;
		freq2[i] = mini;
		suma += mini;
	}
	if (suma == 0) cout << "BRAK\n";
	else {
		cout << suma << "\n";
		for (int i = 0; i<(int)a.length(); i++){
			if (freq1[a[i]-'a']>0){
				cout << a[i];
				freq1[a[i]-'a']--;
			}
		}
		cout << "\n";
		cout << suma << "\n";
		for (int i = 0; i<(int)b.length(); i++){
			if (freq2[b[i]-'a']>0){
				cout << b[i];
				freq2[b[i]-'a']--;
			}
		}
		cout << "\n";
	}
	return 0;
} 
