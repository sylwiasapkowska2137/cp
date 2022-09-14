#include<bits/stdc++.h>
using namespace std;
#define pkt pair<int, int>

//start - punkt, wzgledem ktorego bedziemy sortowac
pair <int, int> start;
stack<pkt> otoczka;

//sprawdzam, w ktorym kierunku skrecam
//jesli zwracany wynik jest ujemny, to w lewo, jesli dodatni to w prawo,
//jesli zero to ide prosto
int iloczyn_wektorowy(pkt X, pkt Y, pkt Z)
{
    int x1 = Z.first - X.first, y1 = Z.second - X.second,
        x2 = Y.first - X.first, y2 = Y.second - X.second;
    return x1*y2 - x2*y1;
}

//zwracam stos z wierzcholkami otoczki
stack<pkt > buduj_otoczke(vector <pkt > P)
{
    stack<pkt > stos;
    stos.push(P[0]);
    pkt X = P[0], Y = P[1];
    for(int i=2; i<P.size(); i++)
    {
        // dopóki skręcam w prawo lub ide prosto
        //usuwam niepotrzebne wierzcholki ze stosu
        while(iloczyn_wektorowy(X, Y, P[i])>=0)
        {
            Y = X;
            stos.pop();
            if(stos.empty())break;
            X = stos.top(); //X <- P[0]
        }
        stos.push(Y);
        X = Y;
        Y = P[i];
    }
    return stos;
}

bool porownaj(pkt A, pkt B)
{
	//ustawiam wierzcholek startowy na poczatku tablicy
    if(A==start)return 1;
    if(B==start)return 0;
    //-------------------------------------------------
    
    //jesli dla dwoch punkow kat jest taki sam, to najpierw
    //wez ten, ktory ma mniejsza wspolrzedna x
    if((A.second-start.second)*(B.first-start.first) ==
    (A.first-start.first)*(B.second-start.second))
        return A.first<B.first;
        
    return (A.second-start.second)*(B.first-start.first) <
    (A.first-start.first)*(B.second-start.second);
}



int main()
{
    int n;
    cin>>n;

    vector <pkt > P(n);

    for(int i=0; i<n; i++)
    {
        cin>>P[i].first>>P[i].second; //P(x, y) = (P.first, P.second)
        //szukam wieszcholka najnizej polozonego
        //a w przypadku remisu, najbardziej na lewo
        if(i==0)
            start = P[i];
        else
            if(P[i].second == start.second)
                start.first = min(P[i].first, start.first);
            else
                if(P[i].second < start.second)
                    start = P[i];
    	//------------------------------------------------
    }
    //sortowanie katowe wzgledem punktu polozonego
    //najbardziej na dole, a w przypadku remisu 
    //najbardziej na lewo
    sort(P.begin(), P.end(), porownaj);
    P.push_back(start);

    stack<pkt > stos = buduj_otoczke(P);

	//wypisanie wierzcholka startowego
	cout<<start.first<<' '<<start.second<<endl;
	
	//wypisanie kolejnych wierzcholkow otoczki wypuklej
    while(!stos.empty())
    {
        cout<<stos.top().first<<' '<<stos.top().second<<endl;
        stos.pop();
    }

    return 0;
}
