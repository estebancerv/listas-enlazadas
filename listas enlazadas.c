#include<stdio.h>

struct node {
	int val;
	struct node *next;
};

struct node crearlista(int n, struct node *cabeza){
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
	fin->next= '\0';
}

/*struct node crearlista(struct node *cabeza){
	struct node *medio, *final;
	medio=malloc(sizeof(struct node));
	final=malloc(sizeof(struct node));
	cabeza->val=1;
	medio->val=2;
	final->val=3;
	cabeza->next=medio;
	medio->next=final;
	final->next= '\0';
	return *cabeza;
}*/

void printlista(struct node *cabeza){
	struct node *t;
	t=malloc(sizeof(struct node));
	t=cabeza;
	while (t!='\0'){
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

main() {
	struct node *a;
	a=malloc(sizeof(struct node));
	crearlista(4,a);
	printlista(a);
	borrar(3,a);
	printlista(a);
	return 0;
}
