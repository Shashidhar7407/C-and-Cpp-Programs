#include<iostream>
using namespace std;
struct llist {
	int data;
	struct llist *link;
};
void addi(struct llist *l1, struct llist *l2, struct llist **l3) {
	struct llist *t1=l1, *t2=l2, *temp=NULL;
	int carry=0;
	while(t1 != NULL and t2 != NULL) {
		int digi=(t1->data+t2->data+carry);
		carry=digi/10;
		digi%=10;
		cout<<digi<<" ";
		temp=new llist;
		if((*l3) == NULL) {
			temp->data=digi;
			temp->link=NULL;
			(*l3)=temp;
		} else {
			temp->data=digi;
			temp->link=(*l3);
			(*l3)=temp;
		}
		t1=t1->link; t2=t2->link;
	}
	if(t1 != NULL) {
		int digi=(t1->data+carry);
		carry=digi/10;
		digi%=10;
		cout<<digi<<" ";
		temp=new llist;
		temp->data=digi;
		temp->link=(*l3);
		(*l3)=temp;
	}
	if(t2 != NULL) {
		int digi=(t2->data+carry);
		carry=digi/10;
		digi%=10;
		cout<<digi<<" ";
		temp=new llist;
		temp->data=digi;
		temp->link=(*l3);
		(*l3)=temp;
	}
	if(carry) {
		temp=new llist;
		temp->data=carry;
		temp->link=(*l3);
		(*l3)=temp;
	}
}
void llist_reverse(llist **l) {
	llist *temp1=NULL, *temp2=(*l), *temp3=(*l), *temp4=(*l);
	while(temp4) cout<<temp4->data, temp4=temp4->link; cout<<endl;
	while(temp3) temp3=temp3->link,	temp2->link=temp1, temp1=temp2, temp2=temp3;
	(*l)=temp1; while(temp1) cout<<temp1->data, temp1=temp1->link; cout<<endl;
}
void llist_rev_rec(llist **l) {
	llist *temp=(*l)->link;
	if(!(*l)) return; if(!temp) return;
	llist_rev_rec(&temp); (*l)->link->link=(*l); (*l)->link=NULL; (*l)=temp;
}
struct dlist {
	int data; struct dlist *left, *right;
};
void dlist_reverse(dlist **d) {
	dlist *temp1=NULL, *temp2=(*d), *temp3=(*d), *temp4=(*d);
	while(temp4) cout<<temp4->data, temp4=temp4->right; cout<<endl;
	while(temp3) temp3=temp3->right, temp2->right=temp1, temp2->left=temp3, temp1=temp2, temp2=temp3;
	(*d)=temp1; while(temp1) cout<<temp1->data, temp1=temp1->right; cout<<endl;
}
void dlist_rev_rec(dlist **d) {
}
void mid_llist(llist *l) {
	llist *temp1=l, *temp2=l->link;
	while(temp2) { temp1=temp1->link; temp2=temp2->link; if(temp2) temp2=temp2->link; }
	cout<<temp1->data<<" ";
}
void merge2lists_alternate_nodes(llist *p, llist **q) {
	llist *p_curr=p, *q_curr=*q;
	llist *p_next, *q_next;
	while(p_curr and q_curr) {
		p_next=p_curr->link;
		q_next=q_curr->link;
		q_curr->link=p_next;
		p_curr->link=q_curr;
		p_curr=p_next;
		q_curr=q_next;
	}
	*q=q_curr;
}
void strlength(char *s) {
	int i=0; while(*s++ != '\0') i++; cout<<i<<" ";
}
int strcompare(char *p, char *q) {
	char *c=p, *d=q; while(*c && *d) if(*c != *d) return (*c-*d); else c++, d++; return 0;
}
int main() {
	struct llist *l1=NULL, *l2=NULL, *temp, *l3=NULL;
	temp=new llist; temp->data=1; temp->link=NULL; l1=temp; temp=new llist; temp->data=2; temp->link=l1; l1=temp;
	temp=new llist; temp->data=3; temp->link=l1; l1=temp; temp=new llist; temp->data=4; temp->link=l1; l1=temp;
	temp=new llist; temp->data=5; temp->link=l1; l1=temp; temp=new llist; temp->data=6; temp->link=l1; l1=temp;
//	temp=new llist; temp->data=7; temp->link=l1; l1=temp; mid_llist(l1); strlength(p); llist_reverse(&l1);
//	char *q="hellohai"; void (*p)(int, int); void (*k)(char *); k=&strlength; k(q); p=&add2; p(2,3);
//	temp=new llist; temp->data=7; temp->link=NULL; l2=temp; temp=new llist; temp->data=3; temp->link=l2; l2=temp;
//	temp=new llist; temp->data=2; temp->link=l2; l2=temp; temp=new llist; temp->data=4; temp->link=l2; l2=temp;
//	addi(l1,l2,&l3); temp=l3; while(temp != NULL) { cout<<temp->data; temp=temp->link; }
//	dlist *d1=NULL, *temp; temp=new dlist; temp->left=NULL; temp->right=NULL; temp->data=1; d1=temp;
//	temp=new dlist; temp->left=NULL; temp->right=d1; temp->data=2; d1->left=temp; d1=temp;
//	temp=new dlist; temp->left=NULL; temp->right=d1; temp->data=3; d1->left=temp; d1=temp;
//	temp=new dlist; temp->left=NULL; temp->right=d1; temp->data=4; d1->left=temp; d1=temp; dlist_reverse(&d1);
	return 0;
}
