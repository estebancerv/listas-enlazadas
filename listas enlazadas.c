struct node {
	int val;
	struct node *next;
};

struct node crearlista(struct node *cabeza){
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
}

void printlista(struct node *cabeza){
	struct node *t;
	t=malloc(sizeof(struct node));
	t=cabeza;
	while (t!='\0'){
		printf("%d ", t->val);
		t=t->next;
	}
}

/*struct node borrar(int ele, struct node *cabeza){
	int cont=0;
	struct node *t;
	t=malloc(sizeof(struct node));
	t=cabeza;
	while (t!='\0'){
		if (cont=ele){
			t->next=t->next->next;
		}
		t=t->next;
		cont++;
	}
	return *cabeza;
}*/

main() {
	struct node *a;
	a=malloc(sizeof(struct node));
	crearlista(a);
	printlista(a);
	/*borrar(1,a);*/
	printlista(a);
	return 0;
}
