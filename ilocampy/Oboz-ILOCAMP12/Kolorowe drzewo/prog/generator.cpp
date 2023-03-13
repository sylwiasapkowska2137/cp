//g++ -std=gnu++11 generator.cpp -o generator && ./generator
#include<bits/stdc++.h>
#include "generator.h"
#include "medTest.h"
#define PII pair<int,int>
#define f first
#define s second
#define VI vector<int>
#define VVI vector< VI >
#define LL long long
#define MP make_pair
#define LD long double
#define PB push_back
#define ALL(V) V.begin(),V.end()
#define abs(x) max((x),-(x))
#define PDD pair<LD,LD> 
#define VPII vector< PII > 
#define siz(V) ((int)V.size())
#define FOR(x, b, e)  for(int x=b;x<=(e);x++)
#define FORD(x, b, e) for(int x=b;x>=(e);x--)
#define REP(x, n)     for(int x=0;x<(n);x++)
#define mini(a,b) a=min(a,b)
#define maxi(a,b) a=max(a,b)
using namespace std;
int a, b;
 
int R(int a, int b) {
    return Generator::random() % (b - a + 1) + a;
}

Test exampleTest() {
    Test test;
    test.addLine(6);
    test.addLine(2, 3);
    test.addLine(3, 4);
    test.addLine(3, 1);
    test.addLine(4, 5);
    test.addLine(4, 6);
    test.addLine(1, 1, 3, 2, 1, 1);
    return test;
}
  
VPII generatetree1(int n)
{
VPII ret;
FOR(i,2,n)
  {
  ret.PB(MP(i,R(1,i-1)));
  }
return ret;
}
VPII generatetree2(int n)
{
VPII ret;
FOR(i,2,n)
  {
  if(R(1,100)>=3)ret.PB(MP(i,R(max(1,i-7),i-1)));
  else ret.PB(MP(i,R(1,i-1)));
  }
return ret;
}
struct FI
  {
  int *t;
  FI(int n)
    {
    n++;
    t=new int[n+1];
    FOR(i,1,n)t[i]=i;
    }
  int find(int a)
    {
    return a==t[a]?a:t[a]=find(t[a]);
    }
  void unio(int a,int b)
    {
    t[find(a)]=find(b);
    }
  };
VPII generatetree3(int n)
{
FI X(n);
VPII ret;
while(ret.size()!=n-1)
  {
  a=R(1,n);
  b=R(1,n);
  if(X.find(a)!=X.find(b))
    {
    ret.PB(MP(a,b));
    X.unio(a,b);
    }
  }
return ret;
}
VPII generatetree4(int n,int T=0)//duże stopnie
  {
  if(T==0)T=R(3,10);
  VPII ret;
  FOR(i,2,n)
    {
    if(R(1,300)>=5)ret.PB(MP(i,R(1,min(i-1,T))));
    else ret.PB(MP(i,R(1,i-1)));
    }
  return ret;  
  }
VPII generatetree5(int n,int T=0)//bardzo duże stopnie
  {
  if(T==0)T=R(1,4);
  VPII ret;
  FOR(i,2,n)
    {
    if(R(1,300)>=2)ret.PB(MP(i,R(1,min(i-1,T))));
    else ret.PB(MP(i,R(1,i-1)));
    }
  return ret;  
  }
VPII generatetree6(int n)
  {
  VPII ret;
  FOR(i,2,n)
    {
    if(R(1,3000)>=2)ret.PB(MP(i,R(max(1,i-2),i-1)));
    else ret.PB(MP(i,R(1,i-1)));
    }
  return ret;
  }
void permutuj(VPII &V)
  {
  int n=V.size()+1;
  int t[n+1];
  FOR(i,1,n)t[i]=i;
  random_shuffle(t+2,t+n+1);
  REP(i,V.size())
    {
    V[i].f=t[V[i].f];
    V[i].s=t[V[i].s];
    if(R(1,3)==1)swap(V[i].f,V[i].s);
    }
  random_shuffle(ALL(V));
  }
  
  
  

  

  
bool checktree(VPII V) {
// {a
int n=V.size()+1;
FI X(n);
REP(i,V.size())
  {
  a=V[i].f;
  b=V[i].s;
  if(a>n||b>n)return 0;
  if(a<1||b<1)return 0;
  if(X.find(a)==X.find(b))return 0;
  X.unio(a,b);
  }
return 1;
}

const int MXN = 1e6+6;
VI V[MXN];
int odl[MXN];
void dfs(int x,int pp)
  {
  for(auto it:V[x])
    {
    if(it == pp)continue;
    odl[it] = odl[x] + 1;
    dfs(it, x);
    }
  }
int srednica(VPII X)
  {
  int n = X.size() + 1;
  FOR(i,1,n)
    {
    V[i].clear();
    odl[i]=0;
    }
  for(auto it:X)
    {
    V[it.f].PB(it.s);
    V[it.s].PB(it.f);
    }
  odl[1]=0;
  dfs(1, 0);
  int mx=0;
  FOR(i,1,n)
    {
    if(odl[mx] < odl[i])
      {
      mx = i;
      }
    }
  odl[mx]=0;
  dfs(mx, 0);
  int r = 0;
  FOR(i,1,n)
    {
    maxi(r, odl[i]);
    }
  return r;
  }


void przygotujzapytania(VPII inn)
  {
  int n = inn.size() + 1;
  FOR(i,1,n)V[i].clear();
  REP(i,n)
    {
    V[inn[i].f].PB(inn[i].s);
    V[inn[i].s].PB(inn[i].f);
    }
  odl[1]=0;
  dfs(1, 0);
  
  }

  
  
  
  
  VPII generatetree(int n,int x, int minS)
  {
  VPII V1;
    switch (x)
    {
    case 1:
      {
      V1=generatetree1(n);
      break;
      }
    case 2:
      {
      V1=generatetree2(n);
      break;
      }
    case 3:
      {
      V1=generatetree3(n);
      break;
      }
    case 4:
      {
      V1=generatetree4(n);
      break;
      }
    case 5:
      {
      V1=generatetree5(n);
      break;
      }
    case 6:
      {
      V1=generatetree6(n);
      
      
      cout << n << " " << srednica(V1) << endl;
      
      while (srednica(V1) < minS)
          V1 = generatetree6(n);
      
      break;
      }
    }
  permutuj(V1);
  return V1;
  }
  
  
  
  
Test losoweKolory(int n, int x, int minS, int maxColor) {
    Test test;
    
    VPII v = generatetree(n, x, minS);
    
    test.addLine(n);
    
    for (int i=0; i<v.size(); i++)
        test.addLine(v[i].f, v[i].s);
    
    vector<int> colors;
    for (int i = 1; i <= n; i++) {
        colors.push_back(R(1, maxColor));
    }
    test.addLine(colors);
    
    return test;
}

// int odl[MXN];
int color[MXN];
int mm;
bool odw[MXN];
void DFS(int w, int wsp) {
    odw[w] = true;
    odl[w] = 1;
    for (int i = 0; i < V[w].size(); i++) {
        int u = V[w][i];
        if (!odw[u]) {
            DFS(u, wsp);
            odl[w] = max(odl[w], odl[u] + 1);
        }
    }
    if (R(1, odl[w]) <= wsp) {
        color[w] = 1;
    } else {
        color[w] = R(1, mm);
    }
}

Test nielosoweKolory(int n, int x, int minS, int maxColor, int wsp) {
    Test test;
    mm = x;
    VPII v = generatetree(n, x, minS);
    for (int i = 1; i <= n; i++) {
        odl[i] = 0;
        odw[i] = 0;
        color[i] = 0;
        V[i].clear();
    }
    test.addLine(n);
    
    for (int i=0; i<v.size(); i++) {
        test.addLine(v[i].f, v[i].s);
    
        V[v[i].f].push_back(v[i].s);
        V[v[i].s].push_back(v[i].f);
    }
    
    DFS(1, wsp);
    vector<int> kolory;
    for (int i = 1; i <= n; i++) kolory.push_back(color[i]);
    return test;
}
  
Test mediumTest1() {
    Test test;
    test.addLine(330);
    test.addLine(1, 2);
    test.addLine(2, 3);
    test.addLine(1, 4);
    test.addLine(4, 5);
    test.addLine(5, 6);
    test.addLine(2, 7);
    test.addLine(2, 8);
    test.addLine(4, 9);
    test.addLine(1, 10);
    test.addLine(2, 11);
    test.addLine(1, 12);
    test.addLine(12, 13);
    test.addLine(6, 14);
    test.addLine(5, 15);
    test.addLine(1, 16);
    test.addLine(4, 17);
    test.addLine(12, 18);
    test.addLine(1, 19);
    test.addLine(19, 20);
    test.addLine(18, 21);
    test.addLine(2, 22);
    test.addLine(19, 23);
    test.addLine(6, 24);
    test.addLine(4, 25);
    test.addLine(16, 26);
    test.addLine(11, 27);
    test.addLine(11, 28);
    test.addLine(27, 29);
    test.addLine(4, 30);
    test.addLine(14, 31);
    test.addLine(2, 32);
    test.addLine(12, 33);
    test.addLine(30, 34);
    test.addLine(16, 35);
    test.addLine(8, 36);
    test.addLine(17, 37);
    test.addLine(13, 38);
    test.addLine(22, 39);
    test.addLine(23, 40);
    test.addLine(9, 41);
    test.addLine(16, 42);
    test.addLine(12, 43);
    test.addLine(27, 44);
    test.addLine(7, 45);
    test.addLine(13, 46);
    test.addLine(6, 47);
    test.addLine(28, 48);
    test.addLine(41, 49);
    test.addLine(14, 50);
    test.addLine(32, 51);
    test.addLine(24, 52);
    test.addLine(37, 53);
    test.addLine(36, 54);
    test.addLine(22, 55);
    test.addLine(23, 56);
    test.addLine(43, 57);
    test.addLine(53, 58);
    test.addLine(17, 59);
    test.addLine(41, 60);
    test.addLine(2, 61);
    test.addLine(25, 62);
    test.addLine(32, 63);
    test.addLine(55, 64);
    test.addLine(41, 65);
    test.addLine(61, 66);
    test.addLine(7, 67);
    test.addLine(16, 68);
    test.addLine(25, 69);
    test.addLine(11, 70);
    test.addLine(49, 71);
    test.addLine(15, 72);
    test.addLine(8, 73);
    test.addLine(2, 74);
    test.addLine(71, 75);
    test.addLine(9, 76);
    test.addLine(34, 77);
    test.addLine(73, 78);
    test.addLine(55, 79);
    test.addLine(77, 80);
    test.addLine(20, 81);
    test.addLine(62, 82);
    test.addLine(26, 83);
    test.addLine(25, 84);
    test.addLine(17, 85);
    test.addLine(26, 86);
    test.addLine(67, 87);
    test.addLine(5, 88);
    test.addLine(31, 89);
    test.addLine(55, 90);
    test.addLine(13, 91);
    test.addLine(64, 92);
    test.addLine(90, 93);
    test.addLine(13, 94);
    test.addLine(42, 95);
    test.addLine(91, 96);
    test.addLine(50, 97);
    test.addLine(54, 98);
    test.addLine(97, 99);
    test.addLine(57, 100);
    test.addLine(53, 101);
    test.addLine(2, 102);
    test.addLine(63, 103);
    test.addLine(71, 104);
    test.addLine(48, 105);
    test.addLine(73, 106);
    test.addLine(16, 107);
    test.addLine(30, 108);
    test.addLine(53, 109);
    test.addLine(62, 110);
    test.addLine(5, 111);
    test.addLine(109, 112);
    test.addLine(77, 113);
    test.addLine(74, 114);
    test.addLine(65, 115);
    test.addLine(54, 116);
    test.addLine(71, 117);
    test.addLine(90, 118);
    test.addLine(5, 119);
    test.addLine(10, 120);
    test.addLine(57, 121);
    test.addLine(29, 122);
    test.addLine(74, 123);
    test.addLine(30, 124);
    test.addLine(58, 125);
    test.addLine(121, 126);
    test.addLine(107, 127);
    test.addLine(78, 128);
    test.addLine(48, 129);
    test.addLine(18, 130);
    test.addLine(23, 131);
    test.addLine(11, 132);
    test.addLine(99, 133);
    test.addLine(104, 134);
    test.addLine(127, 135);
    test.addLine(120, 136);
    test.addLine(46, 137);
    test.addLine(23, 138);
    test.addLine(101, 139);
    test.addLine(111, 140);
    test.addLine(102, 141);
    test.addLine(86, 142);
    test.addLine(140, 143);
    test.addLine(16, 144);
    test.addLine(127, 145);
    test.addLine(130, 146);
    test.addLine(109, 147);
    test.addLine(105, 148);
    test.addLine(114, 149);
    test.addLine(86, 150);
    test.addLine(133, 151);
    test.addLine(68, 152);
    test.addLine(26, 153);
    test.addLine(20, 154);
    test.addLine(27, 155);
    test.addLine(49, 156);
    test.addLine(86, 157);
    test.addLine(7, 158);
    test.addLine(22, 159);
    test.addLine(61, 160);
    test.addLine(98, 161);
    test.addLine(73, 162);
    test.addLine(64, 163);
    test.addLine(3, 164);
    test.addLine(109, 165);
    test.addLine(92, 166);
    test.addLine(24, 167);
    test.addLine(117, 168);
    test.addLine(166, 169);
    test.addLine(50, 170);
    test.addLine(4, 171);
    test.addLine(162, 172);
    test.addLine(145, 173);
    test.addLine(124, 174);
    test.addLine(52, 175);
    test.addLine(78, 176);
    test.addLine(130, 177);
    test.addLine(44, 178);
    test.addLine(119, 179);
    test.addLine(101, 180);
    test.addLine(45, 181);
    test.addLine(159, 182);
    test.addLine(174, 183);
    test.addLine(80, 184);
    test.addLine(90, 185);
    test.addLine(12, 186);
    test.addLine(100, 187);
    test.addLine(125, 188);
    test.addLine(110, 189);
    test.addLine(161, 190);
    test.addLine(147, 191);
    test.addLine(112, 192);
    test.addLine(185, 193);
    test.addLine(122, 194);
    test.addLine(187, 195);
    test.addLine(81, 196);
    test.addLine(32, 197);
    test.addLine(164, 198);
    test.addLine(12, 199);
    test.addLine(32, 200);
    test.addLine(152, 201);
    test.addLine(163, 202);
    test.addLine(148, 203);
    test.addLine(154, 204);
    test.addLine(39, 205);
    test.addLine(189, 206);
    test.addLine(19, 207);
    test.addLine(148, 208);
    test.addLine(21, 209);
    test.addLine(96, 210);
    test.addLine(92, 211);
    test.addLine(115, 212);
    test.addLine(84, 213);
    test.addLine(28, 214);
    test.addLine(157, 215);
    test.addLine(91, 216);
    test.addLine(182, 217);
    test.addLine(18, 218);
    test.addLine(116, 219);
    test.addLine(45, 220);
    test.addLine(167, 221);
    test.addLine(104, 222);
    test.addLine(218, 223);
    test.addLine(34, 224);
    test.addLine(132, 225);
    test.addLine(223, 226);
    test.addLine(225, 227);
    test.addLine(19, 228);
    test.addLine(191, 229);
    test.addLine(220, 230);
    test.addLine(148, 231);
    test.addLine(225, 232);
    test.addLine(149, 233);
    test.addLine(41, 234);
    test.addLine(225, 235);
    test.addLine(26, 236);
    test.addLine(64, 237);
    test.addLine(153, 238);
    test.addLine(206, 239);
    test.addLine(79, 240);
    test.addLine(158, 241);
    test.addLine(127, 242);
    test.addLine(194, 243);
    test.addLine(47, 244);
    test.addLine(51, 245);
    test.addLine(242, 246);
    test.addLine(181, 247);
    test.addLine(136, 248);
    test.addLine(22, 249);
    test.addLine(19, 250);
    test.addLine(15, 251);
    test.addLine(138, 252);
    test.addLine(80, 253);
    test.addLine(109, 254);
    test.addLine(150, 255);
    test.addLine(71, 256);
    test.addLine(219, 257);
    test.addLine(12, 258);
    test.addLine(32, 259);
    test.addLine(120, 260);
    test.addLine(8, 261);
    test.addLine(179, 262);
    test.addLine(219, 263);
    test.addLine(122, 264);
    test.addLine(8, 265);
    test.addLine(57, 266);
    test.addLine(45, 267);
    test.addLine(188, 268);
    test.addLine(198, 269);
    test.addLine(229, 270);
    test.addLine(76, 271);
    test.addLine(29, 272);
    test.addLine(75, 273);
    test.addLine(108, 274);
    test.addLine(90, 275);
    test.addLine(134, 276);
    test.addLine(167, 277);
    test.addLine(53, 278);
    test.addLine(241, 279);
    test.addLine(140, 280);
    test.addLine(180, 281);
    test.addLine(141, 282);
    test.addLine(110, 283);
    test.addLine(56, 284);
    test.addLine(10, 285);
    test.addLine(67, 286);
    test.addLine(28, 287);
    test.addLine(70, 288);
    test.addLine(265, 289);
    test.addLine(251, 290);
    test.addLine(34, 291);
    test.addLine(262, 292);
    test.addLine(84, 293);
    test.addLine(154, 294);
    test.addLine(236, 295);
    test.addLine(2, 296);
    test.addLine(83, 297);
    test.addLine(15, 298);
    test.addLine(217, 299);
    test.addLine(104, 300);
    test.addLine(245, 301);
    test.addLine(21, 302);
    test.addLine(263, 303);
    test.addLine(265, 304);
    test.addLine(119, 305);
    test.addLine(225, 306);
    test.addLine(186, 307);
    test.addLine(31, 308);
    test.addLine(120, 309);
    test.addLine(60, 310);
    test.addLine(41, 311);
    test.addLine(236, 312);
    test.addLine(134, 313);
    test.addLine(66, 314);
    test.addLine(5, 315);
    test.addLine(217, 316);
    test.addLine(106, 317);
    test.addLine(77, 318);
    test.addLine(76, 319);
    test.addLine(315, 320);
    test.addLine(182, 321);
    test.addLine(272, 322);
    test.addLine(142, 323);
    test.addLine(138, 324);
    test.addLine(295, 325);
    test.addLine(301, 326);
    test.addLine(118, 327);
    test.addLine(116, 328);
    test.addLine(30, 329);
    test.addLine(204, 330);
    test.addLine(3, 3, 1, 1, 1, 1, 1, 3, 3, 1, 3, 2, 2, 1, 2, 3, 1, 2, 3, 1, 3, 2, 3, 2, 1, 1, 3, 1, 2, 3, 3, 2, 1, 3, 3, 1, 1, 1, 3, 2, 1, 2, 3, 2, 3, 2, 1, 1, 3, 2, 1, 2, 3, 1, 1, 3, 2, 3, 3, 1, 1, 1, 1, 1, 1, 3, 2, 2, 1, 1, 3, 1, 3, 3, 3, 3, 1, 1, 3, 1, 3, 1, 3, 3, 1, 3, 3, 1, 1, 1, 1, 2, 1, 1, 3, 1, 1, 1, 3, 1, 2, 3, 2, 2, 2, 2, 1, 3, 1, 1, 3, 3, 1, 3, 3, 2, 3, 3, 2, 1, 3, 1, 3, 1, 2, 2, 2, 3, 3, 2, 1, 1, 1, 1, 3, 3, 3, 1, 3, 3, 1, 1, 3, 2, 3, 3, 1, 3, 2, 3, 1, 2, 1, 1, 3, 3, 3, 2, 3, 3, 3, 1, 1, 3, 1, 1, 3, 1, 2, 1, 1, 3, 1, 1, 2, 3, 1, 3, 3, 3, 3, 1, 3, 1, 2, 2, 1, 2, 3, 1, 1, 3, 1, 2, 3, 3, 3, 3, 1, 2, 3, 1, 1, 3, 2, 3, 3, 3, 2, 3, 2, 3, 1, 1, 1, 2, 3, 1, 3, 3, 2, 2, 3, 2, 3, 2, 1, 2, 2, 1, 1, 2, 3, 3, 2, 1, 2, 2, 3, 2, 2, 2, 1, 2, 3, 2, 1, 3, 3, 1, 2, 1, 2, 2, 2, 2, 3, 1, 1, 3, 2, 3, 1, 1, 2, 2, 2, 3, 1, 2, 2, 2, 1, 3, 1, 1, 1, 2, 1, 3, 3, 2, 3, 2, 1, 3, 1, 1, 1, 2, 1, 2, 1, 1, 1, 3, 1, 3, 3, 2, 2, 2, 1, 3, 2, 2, 1, 2, 1, 1, 2, 3, 3, 2, 2, 3, 2, 2, 2, 2, 2, 2, 1, 2, 1, 2, 3, 2, 1, 2);
    return test;
}

  
Test single1() {
    Test test;
    test.addLine(1);
    test.addLine(1);
    return test;
}
  
Test smallTest1() {
    Test test;
    test.addLine(13);
    test.addLine(1, 3);
    test.addLine(3, 2);
    test.addLine(2, 11);
    test.addLine(4, 3);
    test.addLine(4, 12);
    test.addLine(4, 13);
    test.addLine(3, 6);
    test.addLine(6, 5);
    test.addLine(5, 7);
    test.addLine(1, 9);
    test.addLine(9, 10);
    test.addLine(9, 8);
    test.addLine(1, 1, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1);
    return test;
}
  
Test smallTest2() {
    Test test;
    test.addLine(8);
    test.addLine(1, 2);
    test.addLine(1, 3);
    test.addLine(1, 4);
    test.addLine(3, 5);
    test.addLine(2, 6);
    test.addLine(2, 7);
    test.addLine(5, 8);
    test.addLine(2, 2, 1, 1, 3, 1, 3, 2);
    return test;
}

Test special1() {
    Test test;
    test.addLine(5);
    test.addLine(1, 2);
    test.addLine(2, 3);
    test.addLine(2, 4);
    test.addLine(3, 5);
    test.addLine(1, 1, 1, 1, 1);
    return test;
}

Test smallTest3() {
    Test test;
    test.addLine(6);
    test.addLine(1, 2);
    test.addLine(1, 3);
    test.addLine(1, 4);
    test.addLine(1, 5);
    test.addLine(3, 6);
    test.addLine(1, 1, 2, 1, 1, 1);
    return test;
}

Test smallTest4() {
    Test test;
    test.addLine(6);
    test.addLine(6, 2);
    test.addLine(6, 3);
    test.addLine(6, 4);
    test.addLine(6, 5);
    test.addLine(3, 1);
    test.addLine(1, 1, 2, 1, 1, 1);
    return test;    
}

Test smallTest5() {
    Test test;
    test.addLine(8);
    test.addLine(1, 2);
    test.addLine(2, 3);
    test.addLine(3, 4);
    test.addLine(4, 5);
    test.addLine(4, 6);
    test.addLine(5, 7);
    test.addLine(5, 8);
    test.addLine(3, 3, 3, 2, 3, 1, 1, 3);
    return test;
}

Test smallTest6() {
    Test test;
    test.addLine(6);
    test.addLine(1, 2);
    test.addLine(1, 3);
    test.addLine(2, 4);
    test.addLine(3, 5);
    test.addLine(3, 6);
    test.addLine(3, 2, 1, 2, 2, 2);
    return test;
}

Test smallTest7() {
    Test test;
    test.addLine(7);
    test.addLine(7, 2);
    test.addLine(7, 3);
    test.addLine(7, 4);
    test.addLine(2, 5);
    test.addLine(2, 6);
    test.addLine(3, 1);
    test.addLine(2, 1, 2, 2, 2, 2, 1);
    return test;
}

Test smallTest8() {
    Test test;
    test.addLine(7);
    test.addLine(1, 2);
    test.addLine(1, 3);
    test.addLine(1, 4);
    test.addLine(2, 5);
    test.addLine(2, 6);
    test.addLine(3, 7);
    test.addLine(1, 1, 2, 2, 2, 2, 2);
    return test;
}

Test smallTest9() {
    Test test;
    test.addLine(7);
    test.addLine(1, 2);
    test.addLine(1, 3);
    test.addLine(2, 4);
    test.addLine(4, 5);
    test.addLine(3, 6);
    test.addLine(4, 7);
    test.addLine(1, 3, 1, 3, 1, 3, 3);
    return test;
}

Test smallTest10() {
    Test test;
    test.addLine(7);
    test.addLine(1, 2);
    test.addLine(1, 3);
    test.addLine(1, 4);
    test.addLine(2, 5);
    test.addLine(4, 6);
    test.addLine(4, 7);
    test.addLine(1, 2, 2, 1, 2, 2, 2);
    return test;
}


int main(int argc, char *argv[]) 
  {
  Generator gen("kol");

  gen.beginGroup();
  gen.addTest(exampleTest());
  gen.endGroup();

  // 1
  gen.beginGroup();
  {
      Generator::setSeed(982751);
      
      gen.addTest(single1());
      gen.addTest(smallTest1());
      gen.addTest(smallTest2());
      gen.addTest(losoweKolory(10, 1, 4, 3));
      gen.addTest(losoweKolory(15, 1, 3, 5));
      gen.addTest(smallTest5());
      gen.addTest(smallTest6());
      gen.addTest(smallTest7());
      gen.addTest(smallTest8());
  }
  gen.endGroup();
  
  //2
  gen.beginGroup();
  {
      gen.addTest(special1());
      gen.addTest(smallTest3());
      gen.addTest(smallTest4());
      Generator::setSeed(191182751);
      gen.addTest(losoweKolory(3, 1, 0, 3));
      gen.addTest(losoweKolory(50, 2, 0, 2));
      gen.addTest(losoweKolory(50, 3, 0, 2));
      gen.addTest(losoweKolory(70, 4, 0, 2));
      gen.addTest(losoweKolory(200, 5, 1, 3));
      gen.addTest(losoweKolory(100, 6, 0, 2));
      gen.addTest(smallTest10());
  }
  gen.endGroup();

  //3
  gen.beginGroup();
  {
      Generator::setSeed(982755341);

      gen.addTest(losoweKolory(1000, 2, 0,3));
      gen.addTest(losoweKolory(1000, 3, 0, 2));
      gen.addTest(smallTest9());
      gen.addTest(losoweKolory(1000, 2, 0,3));
      gen.addTest(nielosoweKolory(1000, 2, 0,2, 6));
      gen.addTest(losoweKolory(1000, 2, 0,3));
  }
  gen.endGroup();
  
  // 4
  gen.beginGroup();
  {
      Generator::setSeed(1982755341);
      
      gen.addTest(nielosoweKolory(100000, 1, 100, 5, 5));
      gen.addTest(losoweKolory(100000, 2, 0, 3));
      gen.addTest(nielosoweKolory(100000, 3, 0, 3, 5));
      gen.addTest(mediumTest1());
      gen.addTest(losoweKolory(100000, 2, 0, 2));
      gen.addTest(losoweKolory(200000, 3, 10, 2));
      gen.addTest(nielosoweKolory(200000, 2, 0, 1, 10));
      gen.addTest(losoweKolory(500000, 2, 1, 5));
  }
  gen.endGroup();

  // 5
  gen.beginGroup();
  {
      Generator::setSeed(99755341);

      gen.addTest(nielosoweKolory(100000, 6, 0, 3, 10));
      gen.addTest(losoweKolory(100000, 6, 0, 3));
      gen.addTest(nielosoweKolory(600000, 6, 0, 3, 100));
      gen.addTest(losoweKolory(700000, 6, 0, 2));
      gen.addTest(nielosoweKolory(800000, 6, 0, 2, 1000));
      gen.addTest(losoweKolory(900000, 6, 0, 10));
      
      gen.addTest(losoweKolory(700000, 3, 1, 10));
      gen.addTest(nielosoweKolory(800000, 2, 0, 100, 20));
      gen.addTest(losoweKolory(600000, 4, 1, 2));
      gen.addTest(nielosoweKolory(800000, 2, 0, 2, 10));
      gen.addTest(losoweKolory(900000, 2, 1, 2));
      gen.addTest(losoweKolory(1000000, 5, 0, 2));
  }
  gen.endGroup(); 
  
  // 6
  gen.beginGroup();
  {
      Generator::setSeed(1982755341);
      
      gen.addTest(losoweKolory(100000, 3, 1, 10));
      gen.addTest(losoweKolory(1000000, 2, 1, 1000000000));
      gen.addTest(losoweKolory(100000, 5, 1, 100));
      gen.addTest(mediumTest2());
      gen.addTest(nielosoweKolory(100000, 6, 1, 4, 50));
      gen.addTest(losoweKolory(300000, 1, 0, 2));
      gen.addTest(nielosoweKolory(200000, 2, 20, 3, 10000));
      gen.addTest(nielosoweKolory(500000, 2, 10, 10, 10));
  }
  gen.endGroup();
  
  // 7
  gen.beginGroup();
  {
      Generator::setSeed(1982755341);
      
      gen.addTest(losoweKolory(1000000, 3, 1, 2));
      gen.addTest(losoweKolory(200000, 2, 1, 2));
      gen.addTest(nielosoweKolory(300000, 2, 1, 5, 10));
      gen.addTest(losoweKolory(100000, 6, 1, 3));
      
      gen.addTest(nielosoweKolory(200000, 2, 50, 2, 50));
      gen.addTest(losoweKolory(203110, 6, 30, 3));
      gen.addTest(losoweKolory(311341, 3, 5, 2));
  }
  gen.endGroup();


  gen.generate();
  }
