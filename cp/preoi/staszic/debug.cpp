#include <bits/stdc++.h>
using namespace std; 

int randomize() { return (rand() % 1000); } 

int main () { 
	srand(time(NULL)); 
	vector<int> vect(10); 
	generate(vect.begin(), vect.end(), randomize); 
	for (int i=0; i<vect.size(); i++) cout << vect[i] << " " ; 
	return 0; 
} 

