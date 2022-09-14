#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>

using namespace std;

vector < pair <int, int> > a, b, c;
vector <int> maxi;
long long suma[3], sum;

bool byfirst(pair <int, int> elem1, pair <int, int> elem2){
    return elem1.first < elem2.first;
}

bool bysec(pair <int, int> elem1, pair <int, int> elem2){
    return elem1.second < elem2.second;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, x, y, z, mini = 1e9+7, mina, minb, minc;
    cin >> n;
    for (int i = 0; i<n; i++){
        cin >> x >> y >> z;
        suma[0]+=(long long)x;
        suma[1]+=(long long)y;
        suma[2]+=(long long)z;
        maxi.push_back(max(x, max(y, z)));
        a.push_back(make_pair(maxi[i]-x, i));
        b.push_back(make_pair(maxi[i]-y, i));
        c.push_back(make_pair(maxi[i]-z, i));
    }
    sort(a.begin(), a.end(), byfirst);  
    // for (int i = 0; i<n; i++) cout << a[i].first << " " << a[i].second << "\n";
    sort(b.begin(), b.end(), byfirst);  
    // for (int i = 0; i<n; i++) cout << b[i].first << " " << b[i].second << "\n";
    sort(c.begin(), c.end(), byfirst);  
    // for (int i = 0; i<n; i++) cout << c[i].first << " " << c[i].second << "\n";
    if (suma[0]>0 and suma[1]>0 and suma[2]>0){
        for (int i = 0; i<3; i++){
            for (int j = 0; j<3; j++){
                for (int k = 0; k<3; k++){
                    if (a[i].second != b[j].second and a[i].second != c[k].second and b[j].second != c[k].second){
                        if (a[i].first + b[j].first + c[k].first<mini){
                            mina = a[i].second; minb = b[j].second; minc = c[k].second;
                            mini = a[i].first + b[j].first + c[k].first;
                        }
                    }
                }
            }
        }
        // cout << mina << minb << minc;
        sort(a.begin(), a.end(), bysec);
        sort(b.begin(), b.end(), bysec);
        sort(c.begin(), c.end(), bysec);
        sum = suma[0]+suma[1]+suma[2];
        for (int i = 0; i<n; i++){
            a[i].first = maxi[i] - a[i].first;
            b[i].first = maxi[i] - b[i].first;
            c[i].first = maxi[i] - c[i].first;
            if (mina == i) sum -= (long long)a[i].first;
            else if (minb == i) sum -= (long long)b[i].first;
            else if (minc == i) sum -= (long long)c[i].first;
            else sum -= (long long)maxi[i];
            // cout << sum << "\n";
        }
    }

    if (suma[0] == 0 or suma[1]==0 or suma[2]==0){

        sum = suma[0]+suma[1]+suma[2];
        if (sum == suma[0] or sum == suma[1] or sum == suma[2]) {
            cout << 0;
            return 0;
        }
        
        if (suma[0]==0){
            int mina = 1e9+7, minb = 1e9+7, mini = 1e9+7;
            for (int i = 0; i<3; i++){
                for (int j = 0; j<3; j++){
                    if (b[i].second != c[j].second){
                        if (b[i].first + c[j].first<mini){
                            mina = b[i].second; minb = c[j].second;
                            mini = b[i].first + c[j].first;
                        }
                    }
                }
            }
            sort(b.begin(), b.end(), bysec);
            sort(c.begin(), c.end(), bysec);
            for (int i = 0; i<n; i++){
                b[i].first = maxi[i] - b[i].first;
                c[i].first = maxi[i] - c[i].first;
                if (mina == i) sum -= (long long)b[i].first;
                else if (minb == i) sum -= (long long)c[i].first;
                else sum -= (long long)maxi[i];
            }
        }
        else if (suma[1]==0) {
            int mina = 1e9+7, minb = 1e9+7, mini = 1e9+7;
            for (int i = 0; i<3; i++){
                for (int j = 0; j<3; j++){
                    if (a[i].second != c[j].second){
                        if (a[i].first + c[j].first<mini){
                            mina = a[i].second; minb = c[j].second;
                            mini = a[i].first + c[j].first;
                        }
                    }
                }
            }
            sort(a.begin(), a.end(), bysec);
            sort(c.begin(), c.end(), bysec);
            for (int i = 0; i<n; i++){
                a[i].first = maxi[i] - a[i].first;
                c[i].first = maxi[i] - c[i].first;
                if (mina == i) sum -= (long long)a[i].first;
                else if (minb == i) sum -= (long long)c[i].first;
                else sum -= (long long)maxi[i];
            }


        }  else {
            int mina = 1e9+7, minb = 1e9+7, mini = 1e9+7;
            for (int i = 0; i<3; i++){
                for (int j = 0; j<3; j++){
                    if (b[i].second != a[j].second){
                        if (b[i].first + a[j].first<mini){
                            mina = b[i].second; minb = a[j].second;
                            mini = b[i].first + a[j].first;
                        }
                    }
                }
            }
            sort(b.begin(), b.end(), bysec);
            sort(a.begin(), a.end(), bysec);
            for (int i = 0; i<n; i++){
                b[i].first = maxi[i] - b[i].first;
                a[i].first = maxi[i] - a[i].first;
                if (mina == i) sum -= (long long)b[i].first;
                else if (minb == i) sum -= (long long)a[i].first;
                else sum -= (long long)maxi[i];
            }
        }
    }
    cout << sum;
    return 0;
}