#include<bits/stdc++.h>
using namespace std;
struct tree {
	int data;
	tree *left;
	tree *right;
};
struct llist {
	int data;
	llist *next;
};
void iter_in(tree *t) {
	if(t == NULL) return;
	tree *p[100];
	int top=0;
	while(t!=NULL) {
		while(t!=NULL) {
			if(t->right) p[top++]=t->right;
			p[top++]=t;
			t=t->left;
		}
		t=p[--top];
		while(top and t->right==NULL) {
			cout<<t->data<<" ";
			t=p[--top];
		}
		cout<<t->data<<" ";
		t=(top)?p[--top]:NULL;
	}
}
void iter_post(tree *t) {
	if(t == NULL) return;
	int top=0;
	struct {
		tree *myn;
		unsigned vleft:1;
		unsigned vright:1;
	}p[100];
	p[top++].myn=t;
	while(top) {
		if(t->left and !p[top].vleft) {
			p[top].vleft=1;
			p[top++].myn=t;
			t=t->left;
			continue;
		}
		if(t->right and !p[top].vright) {
			p[top].vright=1;
			p[top++].myn=t;
			t=t->right;
			continue;
		}
		cout<<t->data<<" ";
		p[top].vleft=p[top].vright=0;
		t=p[--top].myn;
	}
}
/*
int lcs(char a[], char b[]) {
	int m=strlen(a), n=strlen(b);
	int dp[m+1][n+1];
	rep(i,0,m+1) rep(j,0,n+1) {
		if(i==0 or j==0) dp[i][j]=0;
		else if(a[i-1]==b[j-1]) dp[i][j]=dp[i-1][j-1]+1;
		else dp[i][j]=max(dp[i-1][j], dp[i][j-1]);
	}
	return dp[m][n];
}
int editDist(char a[], char b[]) {
	int m=strlen(a), n=strlen(b);
	int dp[m+1][n+1];
	rep(i,0,m+1) dp[i][0]=i;
	rep(i,0,n+1) dp[0][i]=i;
	rep(i,1,m+1) rep(j,1,n+1) {
		if(a[i-1]==b[j-1]) dp[i][j]=dp[i-1][j-1];
		else dp[i][j]=min(dp[i-1][j], min(dp[i-1][j-1],dp[i][j-1]))+1;
	}
	return dp[m][n];
}
*/
int findLevel(tree *t, int k, int lvl) {
	if(t==NULL) return -1;
	if(t->data==k) return lvl;
	int l=findLevel(t->left,k,lvl+1);
	return (l==-1)?(findLevel(t->right,k,lvl+1):l;
}
tree* findDistUtil(tree *t,int n1, int n2, int &d1, int &d2, int lvl) {
	if(!t) return NULL;
	if(t->data==n1) {
		d1=lvl;
		return t;
	}	
	if(t->data==n2) {
		d2=lvl;
		return t;
	}
	tree* lcal=findUtilDist(t->left,n1,n2,d1,d2,lvl+1);
	tree* lcar=findUtilDist(t->right,n1,n2,d1,d2,lvl+1);
	if(lcal and lcar) {
		dist=d1+d2-2*lvl;
		return t;
	}
	if(lcal)?lcal:lcar;
}
void maxPathSum_any2leavesUtil(tree *t, int &res) {	//tree may contain negetive value nodes...
	if(!t) return 0;
	int lsum=maxPathSum_any2leavesUtil(t->left,res);
	int rsum=maxPathSum_any2leavesUtil(t->right,res);
	int cur_sum=max((lsum+rsum+t->data),max(lsum,rsum));
	if(cur_sum > res) res=cur_sum;
	return max(lsum,rsum)+t->data;
}
int maxPathSum_any2leaves(tree *t) {
	int res=0;
	maxPathSum_any2leavesUtil(t, res);
	return res;
}
int findDist(tree *t, int n1, int n2) {
	int d1=-1, d2=-1, dist;
	tree *lca=findDistUtil(t,n1,n2,d1,d2,dist,1);
	if(d1 != -1 and d2 != -1) return dist;
	if(d1 != -1) { dist=findLevel(lca,n2,0); return dist; }
	if(d2 != -1) { dist=findLevel(lca,n1,0); return dist; }
	return -1;
}
int height(tree *t) {
	if(!t) return 0;
	return max(height(t->left),height(t->right))+1;
}
int bfact(tree *t) {
	return (height(t->left)-height(t->right));
}
tree *leftRotate(tree *x) {
	tree *y = x->right;
    	tree *t2 = y->left;
	y->left = x;
	x->right = t2;
	return y;
}
tree *rightRotate(tree *y) {
	tree *x=y->left;
	tree *t2=x->right;
	x->right=y;
	y->left=t2;
	return x;
}
tree *add_avl(tree *t, int data) {
	if(!t) { tree *temp=new tree; temp->left=temp->right=NULL; temp->data=data; t=temp; return t; }
	if(t->data > data) t->left=add_avl(t->left,data);
	else t->right=add_avl(t->right,data);
	int bal=bfact(t);
	if(bal > 1 and data < t->left->data) return rightRotate(t);		//left left case
	if(bal < -1 and data > t->right->data) return leftRotate(t);		//right right case
	if(bal > 1 and data > t->left->data) {					//left right case
		t->left=leftRotate(t->left);
		return rightRotate(t);
	}
	if(bal < -1 and data < t->right->data) {				//right left case
		t->left=rightRotate(t->right);
		return leftRotate(t);
	}
	return t;
}
tree* tree2llUtil(tree *t) {
	if(!t) return NULL;
	tree *left, *right;
	if(t->left) {
		left=tree2llUtil(t->left);
		for(;left->right!=NULL;left=left->right);
		left->right=t;
		t->left=left;
	}
	if(t->right) {
		right=tree2llUtil(t->right);
		for(;right->left!=NULL;right=right->left);
		right->left=t;
		t->right=right;
	}
	return(t);
}
void tree2ll(tree *t) {
	if(!t) return;
	t=tree2llUtil(t);
	while(t->left) t=t->left;
	while(t!=NULL) cout<<t->data<<" ", t=t->right;
}

/* Recursively construct the right subtree and link it with root 
   The number of nodes in right subtree  is total nodes - nodes in 
   left subtree - 1 (for root) which is n-n/2-1*/
tree* sortedListToBST(llist **l, int n) {	//n number of nodes in linkedlist
	if(n<=0) return NULL;
	tree *left=sortedListToBST(l, n/2);
	tree *root=new tree; root->data=(*l)->data;
	root->left=left;
	*l=(*l)->next;
	root->right=sortedListToBST(l,n-n/2-1);
	return(root);
}
void treeLView(tree *t) {
	if(t==NULL) return;
	cout<<t->data<<" ";
	if(t->left) treeLView(t->left);
	else if(t->right) treeLView(t->right);
}
void treeRView(tree *t) {
	if(t==NULL) return;
	cout<<t->data<<" ";
	if(t->right) treeRView(t->right);
	else if(t->left) treeRView(t->left);
}
int main() {
	tree *t=new tree; tree *temp=new tree; temp->data=8; temp->left=temp->right=NULL; t=temp; temp=new tree; temp->data=5; temp->left=temp->right=NULL; t->left=temp; temp=new tree; temp->data=6; temp->left=temp->right=NULL; t->left->right=temp; temp=new tree; temp->data=2; temp->left=temp->right=NULL; t->left->left=temp; temp=new tree; temp->data=9; temp->left=temp->right=NULL; t->right=temp; iter_post(t);
//	t=add_avl(t,5); t=add_avl(t,11); t=add_avl(t,12); t=add_avl(t,2); t=add_avl(t,15); t=add_avl(t,4); t=add_avl(t,1); t=add_avl(t,13);	t=add_avl(t,14); t=add_avl(t,9); t=add_avl(t,8); t=add_avl(t,7); t=add_avl(t,17); t=add_avl(t,35); t=add_avl(t,25); t=add_avl(t,22);	iter_in(t);
}
