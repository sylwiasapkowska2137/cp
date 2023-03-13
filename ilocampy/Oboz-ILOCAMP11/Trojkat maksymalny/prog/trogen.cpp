#include<iostream>
using namespace std;

int main() {
    int n, g, mm;
    srand(time(NULL));
    cin >> n >> mm;
    cout << n << endl;
    while(n--) {
        g = (rand()*rand())%mm+1;
        cout << g << " ";
    }
    cout << endl;
    return 0;   
}
