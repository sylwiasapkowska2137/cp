#if 1
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <set>
#include <stdlib.h>
#include <string.h>
using namespace std;
 
char getinput()
{
	char in[] = "5 1 2 3 4 5 1 3 2 5 4 5 3 5 1 2 7 2 1 4 1 3 7 2 1 4 2 3 5 2 3 3 1 5 10 2 1 4";
	static int i = 0;
	return in[i++];
}
#define gchar getchar_unlocked()
//#define gchar getchar()
//#define gchar getinput()
 
void fastread(int* a)
{
	register char c = 0;
	while (c < 33)
		c = gchar;
	*a = 0;
	while (c > 33)
	{
		*a = *a * 10 + c - '0';
		c = gchar;
	}
}
 struct interval
{
	int s;
	int e;	
};
struct interval intervallist[100001];
struct compare_asc
{
	bool operator()(const int &a, const int &b) 
	{
		/*if(intervallist[a].s < intervallist[b].s)
		{
			return true;
		}
		else if(intervallist[a].s > intervallist[b].s)
		{
			return false;
		}
		return (intervallist[a].e < intervallist[b].e);*/		
 
		if(intervallist[a].s < intervallist[b].s)
		{
			return true;
		}
		return false;
	}   
}compare_asc_obj;
struct compare_desc
{
	bool operator()(const int &a, const int &b) 
	{		
		if(intervallist[a].e > intervallist[b].e)
		{
			return true;
		}
		return false;
	}   
}compare_desc_obj;
struct node
{
	int middle;
	vector<int> interval_asc;
	vector<int> interval_desc;
	struct node *leftchild;
	struct node *rightchild;
};
struct nodebank
{
	//struct node store[300000];
	int len;
 
	nodebank()
	{
		len = 0;
	}
	
	struct node *getnode()
	{
		//struct node *n = &(store[len]);
		//++len;
		//return n;
		return (new struct node);
	}
};
 
struct nodebank bank;
 
vector<vector <int> > rcache; 
vector<int> iarray;
struct interval line[100001];
void it_insert(vector<int> &v, struct node *n, int l, int r)
{	
	{
		memset(line, 0, sizeof(line));
 
		vector<int>::iterator it;
		for(it = v.begin(); it != v.end(); ++it)
		{
			line[intervallist[*it].s].s += 1;
			line[intervallist[*it].e].e += 1;
		}
 
		int count = 0;
		int temp, i;
		for(i = l; i <= r; ++i)
		{
			//e means left total
			temp = line[i].e;
			line[i].e = count;
			count += temp;
		}
		count = 0;
		for(i = r; i >= l; --i)
		{
			//s means right total
			temp = line[i].s;
			line[i].s = count;
			count += temp;
		}	
		for(i = r; i >= l; --i)
		{
			//s means diff of left and right total
			temp = line[i].s - line[i].e;
			if(temp < 0)
			{
				temp = -temp;
			}
			line[i].s = temp;
		}	
 
		vector<int> bal;
		int min = 99999999;
		
		for(i = l; i <= r; ++i)
		{
			if(line[i].s < min)
			{
				min = line[i].s;
			}
		}
		for(i = l; i <= r; ++i)
		{
			if(line[i].s == min)
			{
				bal.push_back(i);
			}
		}
		n->middle = bal[bal.size() >> 1];
	}
		int lle = 2000000000;
		int lre = -1;
		int rle = 2000000000;
		int rre = -1;
		vector<int> vecleft;
		vector<int> vecright;
		vector<int>::iterator it;
		for(it = v.begin(); it != v.end(); ++it)
		{
			if(intervallist[*it].e < n->middle)
			{
				vecleft.push_back(*it);
				if(intervallist[*it].s < lle)
				{
					lle = intervallist[*it].s;
				}
				if(intervallist[*it].e > lre)
				{
					lre = intervallist[*it].e;
				}
			}
			else if(intervallist[*it].s > n->middle)
			{
				vecright.push_back(*it);
				if(intervallist[*it].s < rle)
				{
					rle = intervallist[*it].s;
				}
				if(intervallist[*it].e > rre)
				{
					rre = intervallist[*it].e;
				}
			}
			else
			{				
				n->interval_asc.push_back(*it);
				n->interval_desc.push_back(*it);				
			}
		}
 
		sort(n->interval_asc.begin(), n->interval_asc.end(), compare_asc_obj);
		sort(n->interval_desc.begin(), n->interval_desc.end(), compare_desc_obj);
 
		n->leftchild = NULL;
		n->rightchild = NULL;
 
		if(vecleft.size())
		{
			n->leftchild = bank.getnode();			
			it_insert(vecleft, n->leftchild, lle, lre);
		}
		if(vecright.size())
		{
			n->rightchild = bank.getnode();			
			it_insert(vecright, n->rightchild, rle, rre);
		}
	
}
void it_find(vector<int> &result, struct node *n, int point)
{
	if(n == NULL)
	{
		return;
	}
 
	vector<int>::iterator it;	
 
	if(point < n->middle)
	{
		for(it = n->interval_asc.begin(); it != n->interval_asc.end(); ++it)
		{
			if(intervallist[*it].s <= point)
			{
				result.push_back(*it);				
			}
			else
			{
				break;
			}
		}
		it_find(result, n->leftchild, point);
	}
	else if(point > n->middle)
	{
		for(it = n->interval_desc.begin(); it != n->interval_desc.end(); ++it)
		{
			if(intervallist[*it].e >= point)
			{
				result.push_back(*it);				
			}
			else
			{
				break;
			}
		}
 
		it_find(result, n->rightchild, point);
	}
	else
	{
		for(it = n->interval_desc.begin(); it != n->interval_desc.end(); ++it)
		{			
				result.push_back(*it);
		}
	}
}
 
 
 
struct Fenwick_Tree_Sum
{
    vector<unsigned long long int> a;	
	vector<unsigned long long int> v;
 
    Fenwick_Tree_Sum()
	{
	}
 
    void init(const vector<unsigned long long int>& Arg)
	{
        a.resize(Arg.size());
 
        for(int i = 0 ; i < (int)a.size(); i++)
            increase(i, Arg[i]);
 
    }
 
    // Increases value of i-th element by ''delta''.
    void increase(int i, long long int delta)
    {
        for (; i < (int)a.size(); i |= i + 1)
            a[i] += delta;
    }
 
    // Returns sum of elements with indexes left..right, inclusive; (zero-based);
    unsigned long long int getsum(int left, int right)
    {
        return sum(right) - sum(left-1); //when left equals 0 the function hopefully returns 0
    }
 
    unsigned long long int sum(int ind)
    {
        unsigned long long int sum = 0;
        while (ind>=0)
        {
            sum += a[ind];
            ind &= ind + 1;
            ind--;
        }
        return sum;
    }
};
 
 
int main(int argc, char *argv[])
{
	int N;
	fastread(&N);	
 
	struct Fenwick_Tree_Sum bita;	
	bita.v.resize(N+1);
	struct Fenwick_Tree_Sum bitf;	
	bitf.v.resize(N+1);
 
	iarray.resize(N);	
	
	int i, ivalue;
	unsigned long long int lvalue;
 
	for(i = 1; i <= N; ++i)
	{
		fastread(&ivalue);
		lvalue = ivalue;
		bita.v[i] = lvalue;		
	}
	bita.init(bita.v);
	
	int le = 2000000000;
	int re = -1;	
	for(i = 1; i <= N; ++i)
	{
		fastread(&(intervallist[i].s));
		fastread(&(intervallist[i].e));
 
		if(intervallist[i].s < le)
		{
			le = intervallist[i].s;
		}
		if(intervallist[i].e > re)
		{
			re = intervallist[i].e;
		}		
 
		bitf.v[i] = bita.getsum(intervallist[i].s, intervallist[i].e);				
 
		iarray[i-1] = i;		
	}
 	bitf.init(bitf.v);
	
	struct node *root = bank.getnode();
 	it_insert(iarray, root, le, re);
	//return 0;
	
	//rcache.resize(N+1);
	int q;
	int qt, x, y, j;
	long long int delta;
	unsigned long long int res = 0;
	fastread(&q);
	while(q--)
	{
		fastread(&qt);
		fastread(&x);
		fastread(&y);
		
		if(qt == 1)
		{			
			if((long long)bita.v[x] > (long long)y)
			{
				delta = bita.v[x] - y;
				delta = -delta;
			}
			else
			{
				delta = y - bita.v[x];
			}
			bita.v[x] = y;
 
			/*
			if(rcache[x].size() == 0)
			{
				it_find(rcache[x], root, x);
			}
			for(j = 0; j < rcache[x].size(); ++j)
			{				
				bitf.increase(rcache[x][j], delta);				
			}
			*/
			iarray.clear();
			it_find(iarray, root, x);
			for(j = 0; j < (long long)iarray.size(); ++j)
			{				
				bitf.increase(iarray[j], delta);				
			}		
		}
		else
		{			
			res = bitf.getsum(x, y);
			printf("%llu\n", res);
		}		
	}	
}
#endif
  
