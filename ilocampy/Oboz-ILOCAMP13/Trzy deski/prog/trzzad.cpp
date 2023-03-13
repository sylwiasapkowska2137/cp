#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
#define LL long long
#define PB push_back
#define MP make_pair
#define ff first
#define ss second
#define DEBUG(x) cerr<<#x<<" "<<(x)<<endl;
#define INF 1000000000
using namespace std;
pair<int,int>tab[200005];
pair<int,int> S[200005];
int size;
int wynik,n;
pair<int,int> V[200005];
int sizer;
int lol(int w)
{
  int ret=0;
//   if(ile==4){if(size==0)return 1;else return 0;}
  int minx=INF+1;
  int miny=INF+1;
  int maxy=-INF-1,maxx=-INF-1;
  for(int i=size;i>=1;i--)
  {
    minx=min(S[i].ff,minx);
    maxx=max(S[i].ff,maxx);
    miny=min(S[i].ss,miny);
    maxy=max(S[i].ss,maxy);
  }
  
    //PRAWY DOLNY
    for(int i=size;i>=1;i--)
  {
    if(S[i].ff>=maxx-w&&S[i].ss<=miny+w)
    {
      V[++sizer]=S[i];
      swap(S[i],S[size]);
      size--;
      
    }      
  }
      int minx2=INF+1;
      int miny2=INF+1;
      int maxy2=-INF-1,maxx2=-INF-1;
      for(int i=size;i>=1;i--)
      {
	minx2=min(S[i].ff,minx2);
	maxx2=max(S[i].ff,maxx2);
	miny2=min(S[i].ss,miny2);
	maxy2=max(S[i].ss,maxy2);
      }
    
    
      int fuk=sizer;
  
    //prawy dolny+lewy gorny
        for(int i=size;i>=1;i--)
	{
	  if(S[i].ff>=maxx2-w&&S[i].ss<=miny2+w)
	  {
	    V[++sizer]=S[i];
	    swap(S[i],S[size]);
	    size--;
	    
	  }      
	}
	
	  for(int i=size;i>=1;i--)
	  {
	    if(S[i].ff<=minx2+w&&S[i].ss>=maxy2-w)
	    {
	//       V.PB(S[i]);
	      V[++sizer]=S[i];
	      swap(S[i],S[size]);
	      size--;
	      
	    }      
	  }
	
      
    
    if(size==0)ret=1;
    
       for(int i=fuk+1;i<=sizer;i++)
    {
      S[++size]=V[i];
    }
    sizer=fuk;
    if(ret==1)
	  {
	    
	    for(int i=1;i<=sizer;i++)
	      S[++size]=V[i];
	    sizer=0;
	    
	    return 1;
	  }
    
    //lewy dolny + prawy gorny
    
		  for(int i=size;i>=1;i--)
  {
    if(S[i].ff<=minx2+w&&S[i].ss<=miny2+w)
    {
      V[++sizer]=S[i];
      swap(S[i],S[size]);
      size--;
      
    }      
  }
	      
   for(int i=size;i>=1;i--)
  {
    if(S[i].ff>=maxx2-w&&S[i].ss>=maxy2-w)
    {
//       V.PB(S[i]);
      V[++sizer]=S[i];
      swap(S[i],S[size]);
      size--;
      
    }      
  }

	      
	    
	  
	  if(size==0)ret=1;
	  
	    for(int i=fuk+1;i<=sizer;i++)
	  {
	    S[++size]=V[i];
	  }
	  sizer=fuk;
	  if(ret==1)
	  {
	    
	    for(int i=1;i<=sizer;i++)
	      S[++size]=V[i];
	    sizer=0;
	    
	    return 1;
	  }
     for(int i=1;i<=sizer;i++)
	      S[++size]=V[i];
	    sizer=0;
    
    
  
    //PRAWY GORNY
   for(int i=size;i>=1;i--)
  {
    if(S[i].ff>=maxx-w&&S[i].ss>=maxy-w)
    {
//       V.PB(S[i]);
      V[++sizer]=S[i];
      swap(S[i],S[size]);
      size--;
      
    }      
  }

           minx2=INF+1;
       miny2=INF+1;
       maxy2=-INF-1,maxx2=-INF-1;
      for(int i=size;i>=1;i--)
      {
	minx2=min(S[i].ff,minx2);
	maxx2=max(S[i].ff,maxx2);
	miny2=min(S[i].ss,miny2);
	maxy2=max(S[i].ss,maxy2);
      }
    
    
       fuk=sizer;
  
    //prawy dolny+lewy gorny
        for(int i=size;i>=1;i--)
	{
	  if(S[i].ff>=maxx2-w&&S[i].ss<=miny2+w)
	  {
	    V[++sizer]=S[i];
	    swap(S[i],S[size]);
	    size--;
	    
	  }      
	}
	
	  for(int i=size;i>=1;i--)
	  {
	    if(S[i].ff<=minx2+w&&S[i].ss>=maxy2-w)
	    {
	//       V.PB(S[i]);
	      V[++sizer]=S[i];
	      swap(S[i],S[size]);
	      size--;
	      
	    }      
	  }
	
      
    
    if(size==0)ret=1;
    
       for(int i=fuk+1;i<=sizer;i++)
    {
      S[++size]=V[i];
    }
    sizer=fuk;
      if(ret==1)
	  {
	    
	    for(int i=1;i<=sizer;i++)
	      S[++size]=V[i];
	    sizer=0;
	    
	    return 1;
	  }
    
    //lewy dolny + prawy gorny
    
		  for(int i=size;i>=1;i--)
  {
    if(S[i].ff<=minx2+w&&S[i].ss<=miny2+w)
    {
      V[++sizer]=S[i];
      swap(S[i],S[size]);
      size--;
      
    }      
  }
	      
   for(int i=size;i>=1;i--)
  {
    if(S[i].ff>=maxx2-w&&S[i].ss>=maxy2-w)
    {
//       V.PB(S[i]);
      V[++sizer]=S[i];
      swap(S[i],S[size]);
      size--;
      
    }      
  }

	        
	    
	  
	  if(size==0)ret=1;
	  
	    for(int i=fuk+1;i<=sizer;i++)
	  {
	    S[++size]=V[i];
	  }
	  sizer=fuk;
	    if(ret==1)
	  {
	    
	    for(int i=1;i<=sizer;i++)
	      S[++size]=V[i];
	    sizer=0;
	    
	    return 1;
	  }
    
    
    

    
    
       for(int i=1;i<=sizer;i++)
	      S[++size]=V[i];
	    sizer=0;
  //LEWY GORNY
  for(int i=size;i>=1;i--)
  {
    if(S[i].ff<=minx+w&&S[i].ss>=maxy-w)
    {
//       V.PB(S[i]);
      V[++sizer]=S[i];
      swap(S[i],S[size]);
      size--;
      
    }      
  }

       minx2=INF+1;
       miny2=INF+1;
       maxy2=-INF-1,maxx2=-INF-1;
      for(int i=size;i>=1;i--)
      {
	minx2=min(S[i].ff,minx2);
	maxx2=max(S[i].ff,maxx2);
	miny2=min(S[i].ss,miny2);
	maxy2=max(S[i].ss,maxy2);
      }
    
    
       fuk=sizer;
  
       //prawy dolny+lewy gorny
        for(int i=size;i>=1;i--)
	{
	  if(S[i].ff>=maxx2-w&&S[i].ss<=miny2+w)
	  {
	    V[++sizer]=S[i];
	    swap(S[i],S[size]);
	    size--;
	    
	  }      
	}
	
	  for(int i=size;i>=1;i--)
	  {
	    if(S[i].ff<=minx2+w&&S[i].ss>=maxy2-w)
	    {
	//       V.PB(S[i]);
	      V[++sizer]=S[i];
	      swap(S[i],S[size]);
	      size--;
	      
	    }      
	  }
	
	
      
    
    if(size==0)ret=1;
    
       for(int i=fuk+1;i<=sizer;i++)
    {
      S[++size]=V[i];
    }
    sizer=fuk;
     if(ret==1)
	  {
	    
	    for(int i=1;i<=sizer;i++)
	      S[++size]=V[i];
	    sizer=0;
	    
	    return 1;
	  }
    //lewy dolny + prawy gorny
    
		  for(int i=size;i>=1;i--)
  {
    if(S[i].ff<=minx2+w&&S[i].ss<=miny2+w)
    {
      V[++sizer]=S[i];
      swap(S[i],S[size]);
      size--;
      
    }      
  }
	      
   for(int i=size;i>=1;i--)
  {
    if(S[i].ff>=maxx2-w&&S[i].ss>=maxy2-w)
    {
//       V.PB(S[i]);
      V[++sizer]=S[i];
      swap(S[i],S[size]);
      size--;
      
    }      
  }


	   
	      
	    
	  
	  if(size==0)ret=1;
	  
	    for(int i=fuk+1;i<=sizer;i++)
	  {
	    S[++size]=V[i];
	  }
	  sizer=fuk;
	  if(ret==1)
	  {
	    
	    for(int i=1;i<=sizer;i++)
	      S[++size]=V[i];
	    sizer=0;
	    
	    return 1;
	  }
    
    
  
     for(int i=1;i<=sizer;i++)
	      S[++size]=V[i];
	    sizer=0;
  //LEWY DOLNY
  for(int i=size;i>=1;i--)
  {
    if(S[i].ff<=minx+w&&S[i].ss<=miny+w)
    {
      V[++sizer]=S[i];
      swap(S[i],S[size]);
      size--;
      
    }      
  }

       minx2=INF+1;
       miny2=INF+1;
       maxy2=-INF-1,maxx2=-INF-1;
      for(int i=size;i>=1;i--)
      {
	minx2=min(S[i].ff,minx2);
	maxx2=max(S[i].ff,maxx2);
	miny2=min(S[i].ss,miny2);
	maxy2=max(S[i].ss,maxy2);
      }
    
    
       fuk=sizer;
  
     //prawy dolny+lewy gorny
        for(int i=size;i>=1;i--)
	{
	  if(S[i].ff>=maxx2-w&&S[i].ss<=miny2+w)
	  {
	    V[++sizer]=S[i];
	    swap(S[i],S[size]);
	    size--;
	    
	  }      
	}
	
	  for(int i=size;i>=1;i--)
	  {
	    if(S[i].ff<=minx2+w&&S[i].ss>=maxy2-w)
	    {
	//       V.PB(S[i]);
	      V[++sizer]=S[i];
	      swap(S[i],S[size]);
	      size--;
	      
	    }      
	  }
	
	
      
    
    if(size==0)ret=1;
    
       for(int i=fuk+1;i<=sizer;i++)
    {
      S[++size]=V[i];
    }
    sizer=fuk;
      if(ret==1)
	  {
	    
	    for(int i=1;i<=sizer;i++)
	      S[++size]=V[i];
	    sizer=0;
	    
	    return 1;
	  }
    
    //lewy gorny + prawy dolny
  //lewy dolny + prawy gorny
    
		  for(int i=size;i>=1;i--)
  {
    if(S[i].ff<=minx2+w&&S[i].ss<=miny2+w)
    {
      V[++sizer]=S[i];
      swap(S[i],S[size]);
      size--;
      
    }      
  }
	      
   for(int i=size;i>=1;i--)
  {
    if(S[i].ff>=maxx2-w&&S[i].ss>=maxy2-w)
    {
//       V.PB(S[i]);
      V[++sizer]=S[i];
      swap(S[i],S[size]);
      size--;
      
    }      
  }


	   
	  
	  if(size==0)ret=1;
	  
	    for(int i=fuk+1;i<=sizer;i++)
	  {
	    S[++size]=V[i];
	  }
	  sizer=fuk;
	    if(ret==1)
	  {
	    
	    for(int i=1;i<=sizer;i++)
	      S[++size]=V[i];
	    sizer=0;
	    
	    return 1;
	  }
    
    
 for(int i=1;i<=sizer;i++)
	      S[++size]=V[i];
	    sizer=0;
  

  
  
  return 0;
  
  
  
}

int main()
{
  scanf("%d",&n);
  int mnx=INF+1;
  int mny=INF+1;
  int mxy=-INF-1;
  int mxx=-INF+1;
  for(int i=1;i<=n;i++)
  {
    scanf("%d%d",&tab[i].ff,&tab[i].ss);
    mxx=max(mxx,tab[i].ff);
    mnx=min(mnx,tab[i].ff);
    mxy=max(mxy,tab[i].ss);
    mny=min(mny,tab[i].ss);
  }
  LL poc=1;
  LL kon=max(mxx-mnx,mxy-mny);
  for(int i=1;i<=n;i++)
  {
    S[++size]=MP(tab[i].ff,tab[i].ss);
  }
//   sort(S+1,S+1+size);
  while(poc<=kon)
  {
    LL sr=(LL)(poc+kon)/(LL)2;
//     cout<<sr<<endl;
//     cout<<size<<endl;
//     DEBUG(sr);
//     if(lol(sr)==1)
//     {
//       printf("%d",sr);
//       return 0;
//     }
    if(lol(sr)==1)
    {
      wynik=sr;
      kon=sr-1;
    }
    else
      poc=sr+1;
    
    
  }
  printf("%d",wynik);
  return 0;
}
