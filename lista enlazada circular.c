#include<stdio.h>

struct node {
	int val;
	struct node *next;
};

void crearlista(int n, struct node *cabeza){
	int i;
	struct node *med;
	struct node *fin;
	cabeza->val=1;
	fin=cabeza;
	for(i=2; i<=n; i++){
		med = malloc(sizeof(struct node));
		med->val=i;
		fin->next=med;
		fin=med;
	}
	fin->next= cabeza;
}

void printlista(struct node *cabeza){
	struct node *t;
	t=malloc(sizeof(struct node));
	t=cabeza;
	while (t->next!=cabeza){
		printf("%d ", t->val);
		t=t->next;
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
		while (fin->next!=cabeza){
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
	struct node *t;
	temp=malloc(sizeof(struct node));
	t=malloc(sizeof(struct node));
	t=cabeza;
	while(t->next!=cabeza){
		t=t->next;
	}
	temp->val=ele;
	temp->next=cabeza;
	cabeza=temp;
	t->next=cabeza;
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
