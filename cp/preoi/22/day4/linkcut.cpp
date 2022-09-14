/*
ID: USACO_template
LANG: C++
PROG: https://judge.yosupo.jp/problem/dynamic_tree_vertex_add_path_sum
*/
#include <iostream>  //cin , cout
#include <fstream>   //fin, fout
#include <stdio.h>   // scanf , pringf
#include <cstdio>
#include <algorithm> // sort , stuff
#include <stack>     // stacks
#include <queue>     // queues
#include <map>
#include <string>
#include <string.h>
#include <set>

using namespace std;

typedef pair<int, int>          pii;
typedef vector<int>             vi;     /// adjlist without weight
typedef vector<pii>             vii;    /// adjlist with weight
typedef vector<pair<int,pii>>   vpip;   /// edge with weight
typedef long long               ll;

#define mp  make_pair
#define ff  first
#define ss  second
#define pb  push_back
#define sz(x)   (int)(x).size()

const int MOD = 1e9+7;  // 998244353;
const int MX  = 2e5+5;   //
const ll  INF = 1e18;    //

#define MAXV 200007
#define MAXE 100007


bool debug;

int N, Q;

/// Link Cut Tree
/**
 * Description: Link-Cut Tree. Given a function 1 ..N
 	* evaluates  for any $a,b.$ \texttt{sz} is for path queries;
 	* \texttt{sub}, \texttt{vsub} are for subtree queries. \texttt{x->access()}
 	* brings \texttt{x} to the top and propagates it; its left subtree will be
 	* the path from \texttt{x} to the root and its right subtree will be empty.
 	* Then \texttt{sub} will be the number of nodes in the connected component
 	* of \texttt{x} and \texttt{vsub} will be the number of nodes under \texttt{x}.
 	* Use \texttt{makeRoot} for arbitrary path queries.
 * Time: O(\log N)
 * Usage: FOR(i,1,N+1)LCT[i]=new snode(i); link(LCT[1],LCT[2],1);
 * Source: Dhruv Rohatgi, Eric Zhang
	* https://sites.google.com/site/kc97ble/container/splay-tree/splaytree-cpp-3
	* https://codeforces.com/blog/entry/67637
	* https://codeforces.com/blog/entry/80383
 * Verification: (see README for links)
	* ekzhang Balanced Tokens
	* Dynamic Tree Test (Easy)
	* https://probgate.org/viewproblem.php?pid=578 (The Applicant)
 */

#include <assert.h>     /* assert */

typedef struct snode* sn;
struct snode {      //////// VARIABLES
	sn p, c[2];     // parent, children
	sn extra;       // extra cycle node for "The Applicant"
	bool flip = 0;  // subtree flipped or not
	int vtx;
	ll val, sz;    /// value in node, # nodes in current splay tree
	int sub, vsub = 0; /// # of nodes in connected tree including itself; vsub stores sum of virtual children
	/// where the "virtual subtrees" refers to the subtrees except the one in the Splay.
	/// https://codeforces.com/blog/entry/67637

	ll stsum;   /// sum of all val in the splay tree; IF call access(), then it is from original root to this node

	snode(int _vtx, int _val) : vtx(_vtx), val(_val) {
		p = c[0] = c[1] = extra = NULL; calc(); }

	friend int getSz(sn x) { return x?x->sz:0; }
	friend int getSub(sn x) { return x?x->sub:0; }
    friend ll  getStSum(sn x) { return x?x->stsum:0; }

	void prop() { // lazy prop
		if (!flip) return;
		swap(c[0],c[1]); flip = 0;
		for(int i=0; i<2; i++) if (c[i]) c[i]->flip ^= 1;
	}
	void calc() { // recalc vals
		for(int i=0; i<2; i++) if (c[i]) c[i]->prop();
		sz = 1+getSz(c[0])+getSz(c[1]);
		sub = 1+getSub(c[0])+getSub(c[1])+vsub;
		stsum = val + getStSum(c[0])+getStSum(c[1]);    // update sum of splay tree value; same approach as sz
	}
	//////// SPLAY TREE OPERATIONS
	int dir() {
		if (!p) return -2;
		for(int i=0; i<2; i++) if (p->c[i] == this) return i;
		return -1; // p is path-parent pointer
	} // -> not in current splay tree
	// test if root of current splay tree
	bool isRoot() { return dir() < 0; }
	friend void setLink(sn x, sn y, int d) {    /// x is parent in the original tree
		if (y) y->p = x;
		if (d >= 0) x->c[d] = y; }
	void rot() { // assume p and p->p propagated
		assert(!isRoot()); int x = dir(); sn pa = p;
		setLink(pa->p, this, pa->dir());
		setLink(pa, c[x^1], x); setLink(this, pa, x^1);
		pa->calc();
	}
	void splay() {  // bring this node to the root of splay tree
		while (!isRoot() && !p->isRoot()) {
			p->p->prop(), p->prop(), prop();
			dir() == p->dir() ? p->rot() : rot();
			rot();
		}
		if (!isRoot()) p->prop(), prop(), rot();
		prop(); calc();
	}
	sn fbo(int b) { // find by order
		prop(); int z = getSz(c[0]); // of splay tree
		if (b == z) { splay(); return this; }
		return b < z ? c[0]->fbo(b) : c[1] -> fbo(b-z-1);
	}

	//////// BASE OPERATIONS

	/// make this node the "access node", i.e. the path from original root to this node is one splay tree
	/// bring this to top of splay tree (not impacting the original representation tree)
	void access() {
		for (sn v = this, pre = NULL; v; v = v->p) {
			v->splay(); // now switch virtual children
			if (pre) v->vsub -= pre->sub;
			if (v->c[1]) v->vsub += v->c[1]->sub;
			v->c[1] = pre; v->calc(); pre = v;
		}
		splay(); assert(!c[1]); // right subtree is empty
	}
	void makeRoot() {   // of the splay tree
		access(); flip ^= 1; access(); assert(!c[0] && !c[1]); }

	//////// QUERIES
	friend sn lca(sn x, sn y) {
		if (x == y) return x;
		x->access(), y->access(); if (!x->p) return NULL;
		x->splay(); return x->p?:x; // y was below x in latter case
	} // access at y did not affect x -> not connected
	friend bool connected(sn x, sn y) { return lca(x,y); }

	// # nodes above; distance to root in original tree
	int distRoot() { access(); return getSz(c[0]); }
	sn getRoot() { /// get root of LCT component in the original tree
		access(); sn a = this;
		while (a->c[0]) a = a->c[0], a->prop();
		a->access(); return a;
	}
	sn getPar(int b) { // get b-th parent on path to root
		access(); b = getSz(c[0])-b; assert(b >= 0);
		return fbo(b);
	} // can also get min, max on path to root, etc

	//////// MODIFICATIONS
	void setVal(int v) { access(); val = v; calc(); }
	void addVal(int v) { access(); val += v; calc(); }
	friend void link(sn x, sn y, bool force = 1) {
		assert(!connected(x,y));
		if (force) y->makeRoot(); /// make x par of y; x -> y
		else { y->access(); assert(!y->c[0]); }
		x->access(); setLink(y,x,0); y->calc();
	}
	friend void cut(sn y) { // cut y from its parent
		y->access(); assert(y->c[0]);
		y->c[0]->p = NULL; y->c[0] = NULL; y->calc(); }
	friend void cut(sn x, sn y) { // if x, y adj in tree
		x->makeRoot(); y->access();
		assert(y->c[0] == x && !x->c[0] && !x->c[1]); cut(y); }
};
sn LCT[MAXV];

//////// THE APPLICANT SOLUTION
void setNex(sn a, sn b) { // set f[a] = b
	if (connected(a,b)) a->extra = b;
	else link(b,a); }
void delNex(sn a) { // set f[a] = NULL
	auto t = a->getRoot();
	if (t == a) { t->extra = NULL; return; }
	cut(a); assert(t->extra);
	if (!connected(t,t->extra))
		link(t->extra,t), t->extra = NULL;
}
sn getPar(sn a, int b) { // get f^b[a]
	int d = a->distRoot(); if (b <= d) return a->getPar(b);
	b -= d+1; auto r = a->getRoot()->extra; assert(r);
	d = r->distRoot()+1; return r->getPar(b%d);
}


int main() {
    debug = false;
    ios_base::sync_with_stdio(false); cin.tie(0);

    cin >> N >> Q;
    for(int i=1; i<=N; i++) {
        int x; cin >> x;
        LCT[i] = new snode(i, x);
    }
    for(int i=1; i<=N-1;i++) {
        int a, b; cin >> a >> b; a++; b++;
        link(LCT[a], LCT[b]);
        if(debug) {
            cout << LCT[a]->stsum << " " << LCT[b]->stsum << endl;
            LCT[b]->access();
            cout << LCT[a]->stsum << " " << LCT[b]->stsum << endl;
            LCT[a]->access();
            cout << LCT[a]->stsum << " " << LCT[b]->stsum << endl;
            LCT[b]->access();
            cout << LCT[a]->stsum << " " << LCT[b]->stsum << endl;

        }
    }

	while(Q--) {
		int cmd; cin >> cmd;
		int a, b, c, d;
		if(cmd == 0) {
            cin >> a >> b >> c >> d;
            a++; b++; c++; d++;
            cut(LCT[a], LCT[b]);
			link(LCT[c], LCT[d]);
		} else if(cmd == 1) {
			cin >> a >> b;
			a++;
			LCT[a]->addVal(b);
		} else if(cmd == 2) {
		    cin >> a >> b; a++; b++;
		    if(a == b) {
                cout << LCT[a]->val << endl;
		    } else {
                LCT[a]->access(); ll asum = getStSum(LCT[a]);
                LCT[b]->access(); ll bsum = getStSum(LCT[b]);
                LCT[a]->splay();
                sn mylca = LCT[a]->p?:LCT[a];
                mylca->access();  ll lsum = getStSum(mylca);
                cout << asum + bsum - 2LL * lsum + mylca->val << endl;
		    }
		}
	}


    if(debug) cout << endl << "EOL" << endl;

}
