#include<stdio.h>

struct node {
	int val;
	struct node *next;
	struct node *prev;
};

void crearlista(int n, struct node *cabeza){
	int i;
	struct node *med;
	struct node *p;
	cabeza->val=1;
	p=cabeza;
	for(i=2; i<=n; i++){
		med = malloc(sizeof(struct node));
		med->val=i;
		p->next=med;
		med->prev=p;
		p=med;
	}
	med=p;
	p->prev=med;
	p->next= '\0';
}

void printlista(struct node *cabeza){
	struct node *t;
	t=malloc(sizeof(struct node));
	t=cabeza;
	while (t!='\0'){
		printf("%d ", t->val);
		t=t->next;
	}
	printf("\n");
	while (t!=cabeza){
		printf("%d ", t->val);
		t=t->prev;
	}
}



struct node borrar(int ele, struct node *cabeza){
	struct node *fin;
	struct node *med;
	struct node *temp;
	if (cabeza->val==ele){
		temp=cabeza;
		cabeza=cabeza->next;
		free(temp);
	}
	else{
		med=cabeza;
		fin=cabeza->next;
		while (fin!='\0'){
			if (fin->val==ele){
				med->next=fin->next;
				free(fin);
				break;
			}
			med=fin;
			fin=fin->next;
		}
	}
	return *cabeza;
}

struct node *insertarp(int ele, struct node *cabeza){
	struct node *temp;
	temp=malloc(sizeof(struct node));
	temp->val=ele;
	cabeza->prev=temp;
	temp->next=cabeza;
	cabeza=temp;
	return cabeza;
}

main() {
	struct node *a;
	a=malloc(sizeof(struct node));
	crearlista(4,a);
	printlista(a);
	borrar(3,a);
	printf("\n");
	printlista(a);
	a = insertarp(5,a);
	printf("\n");
	printlista(a);
	return 0;
}
