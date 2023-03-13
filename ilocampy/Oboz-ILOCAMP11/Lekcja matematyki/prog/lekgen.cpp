#include<iostream>
using namespace std;

int k[1000001], z, n;

int main() {
    int n, MOD;
    srand(time(NULL));
    cin >> z >> n;

    for (int i = 1; i <= z; i++) 
        k[i] = rand() % n + 1;
    for (int i = 1; i <= z; i++)
        cout << k[i];
    cout << endl;

    return 0;   
}
