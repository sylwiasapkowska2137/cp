#include <bits/stdc++.h>
using namespace std;

#define LL long long
#define ULL unsigned LL
#define LD long double
#define pii pair<int, int>
#define st first
#define nd second
#define debug(x) cerr << x << " "
#define pb push_back

struct Node{
    LL l, r;
    Node *right, *left;
};


Node *getnode(){
	Node *temp = (Node*)malloc(sizeof(Node));
	temp->l = temp->r = 0;
	temp->right = temp->left = NULL;
	return temp;
}

Node* insert(Node *root, LL n, LL level){
    if(level == -1) return root;
    if(n & (1<<level)){
        root->r++;
        if(!root->right) root->right = getnode();
        root->right = insert(root->right, n, level-1);
    }else{
        root->l++;
        if(!root->left)root->left = getnode();
        root->left = insert(root->left, n, level-1);
    }
    return root;
}

int query(Node *root, LL n, LL level, LL k){
    if(!root || level == -1) return 0LL;
    bool p = (n&(1<<level));
    bool q = (k&(1<<level));
    if (q){
        if (!p) return root->l+query(root->right, n, level-1, k);
        else return root->r+query(root->left, n, level-1, k);
    }else {
        if (!p) return query(root->left, n, level-1, k);
        else return query(root->right, n, level-1, k);
    }
}


int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	LL n, k, ans = 0LL, x = 0LL;
	cin >> n >> k;
	k++;
	vector <int> a(n);
	Node *root = getnode();
	insert(root, 0, 20);
	for (LL i = 0; i<n; i++){
		cin >> a[i];
		x^=a[i];
		ans+=query(root, x, 20, k);
		insert(root, x, 20);
	}
	cout << ans << "\n";
	return 0;
}
