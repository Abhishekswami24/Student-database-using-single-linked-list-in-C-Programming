#include"header.h"
int main()
{
	SLL *headptr=0;
	int op,c;
	while(1){
		printf("\033[32m My dear! Enter your choice\n");
		printf("1)add_begin 2)add_end 3)add_middle  4)print_node 5)count_node 6)save_file 7)read_file 8)reverse_print 9)print_rec 10)reverse_rec 11)delete_all 12)delete_node 13)search_node 14)sort_data 15)reverse_links 16)exit\033[31m\n");
		scanf("%d",&op);
		switch(op){
			case 1: add_begin(&headptr); break;
			case 2: add_end(&headptr);break;
			case 3: add_middle(&headptr);break;
			case 4: print_node(headptr);break;
			case 5: c=count_node(headptr);
				printf("Total count:%d\n",c);break;
			case 6: save_file(headptr);break;
			case 7: read_file(&headptr);break;
			case 8: reverse_print(headptr);break;
			case 9:  print_rec(headptr);break;
			case 10: reverse_rec(headptr);break;
			case 11: delete_all(&headptr);break;
			case 12: delete_node(&headptr);break;
			case 13: search_node(headptr);break;
			case 14: sort_data(headptr);break;
			case 15: reverse_links(&headptr);break;
			case 16: exit(0);
			default: printf("\033[31;4;1;5m My dear! Unknown choice\033[0m\n");
		}
	}    
}


void reverse_links(SLL **ptr){

  if(*ptr==0){
   printf("No records found\n");
   return ;
  }
  int i=0,c=count_node(*ptr); // finding node count
  if(c>1){
  SLL **a=malloc(sizeof(SLL *)*c); //memory allocated
  SLL *t=*ptr; // started from first node
  
  /////////storing all the node address safely in array
  while(t){
   a[i++]=t;
    t=t->next;
  }
 //////////// reverse the links (change the position)
  for(i=c-1;i>0;i--)
  a[i]->next=a[i-1];
  a[0]->next=0;
  *ptr=a[c-1];
 }

}


void delete_node(SLL **ptr)
{
  if(*ptr==0){
   printf("No records found\n");
   return ;
  }
  char name[20];
  printf("enter name  to delete\n");
  scanf("%s",name);
   SLL *del=*ptr,*prev; // started from first node
  while(del){
     if(strcmp(name,del->name)==0){ // if name found then
        if(del == *ptr) //  check is it first node 
           *ptr=del->next; // then update headptr
        else // if middle/last node 
           prev->next=del->next; //then update previous node next
        
        free(del); // delete a node 
        return;
     }
     prev=del; // follow del one step back
     del=del->next; // visit next node
   }
   printf("Name not found\n");
}


void sort_data(SLL *ptr)
{ 
	if(ptr==0){
		printf("No records found\n");
		return ;
	}
	int c=count_node(ptr); //finding node count
	SLL *p1=ptr ,*p2,t;
	int i,j;
	for(i=0;i<c-1;i++){
		p2=p1->next;
		for(j=0;j<c-1-i;j++){
			if(p1->rollno > p2->rollno){
				t.rollno=p1->rollno;
				strcpy(t.name,p1->name);
				t.marks=p1->marks;

				p1->rollno = p2->rollno;
				strcpy(p1->name,p2->name);
				p1->marks=p2->marks;

				p2->rollno=t.rollno;
				strcpy(p2->name,t.name);
				p2->marks=t.marks;

			}
			p2=p2->next; // visit next node 
		}
		p1=p1->next;
	}
}


void search_node(SLL *ptr)
{
	if(ptr==0){
		printf("No records found\n");
		return;
	}

	int num;
	printf("Enter rollno to search\n");
	scanf("%d",&num); //scan data from user
	while(ptr){ //till last node 
		if(ptr->rollno==num){ //checking is it available
			printf("%d %s %f\n",ptr->rollno,ptr->name,ptr->marks);
			return;
		}
		ptr=ptr->next; //visit next node 
	}
	printf("Rollno not found\n");

}


void delete_all(SLL **ptr)
{
	if(*ptr==0){
		printf("No records found\n");
		return ;
	}

	int c=1;
	SLL *del=*ptr; //started from first node 
	while(del){
		*ptr=del->next; // update headpointer
		sleep(1); // generate delay 1 sec
		printf("Node deleted:%d\n",c++);
		free(del); //node deleted
		del=*ptr;
	}
	printf("all the nodes deleted\n");
}


void print_rec(SLL *ptr){
	if(ptr){
		printf("%d %s %f\n",ptr->rollno,ptr->name,ptr->marks);
		if(ptr->next!=0)
			print_rec(ptr->next);
	}
	else
		printf("No records found\n");
} 
void reverse_rec(SLL *ptr){
	if(ptr){

		if(ptr->next!=0)
			reverse_rec(ptr->next);
		printf("%d %s %f\n",ptr->rollno,ptr->name,ptr->marks);
	}
	else
		printf("No records found\n");
}

void  reverse_print(SLL *ptr)
{
	if(ptr==0){
		printf("No records found\n");
		return ;
	}
	int i,j;
	SLL *t;
	int c=count_node(ptr); // finding node count
	for(i=0;i<c;i++){
		t=ptr; // always starts from first node
		for(j=0;j<c-i-1;j++)
			t=t->next; // shift pointer to desired position
		printf("%d %s %f\n",t->rollno,t->name,t->marks);  
	}
} 

void add_middle(SLL **ptr)
{
  
	SLL *new,*last;
	new=malloc(sizeof(SLL)); // created a node 
	printf("My Dear! Enter Rollno name and marks\n");
	scanf("%d%s%f",&new->rollno,new->name,&new->marks);

	if((*ptr==0) || (new->rollno < (*ptr)->rollno))
	{ // adding at first position
		new->next=*ptr; // update new next addr
		*ptr=new; // update headptr
	}
	else // if middle /last position
	{
		last= *ptr; // started from first node 
		while((last->next!=0) && (new->rollno > last->next->rollno )) // finding exact position to add
			last=last->next; // visit next node 

		new->next= last->next; // update new next as previous node 
		last->next=new; // update exact node next postion   

	} 
}

void add_end(SLL **ptr)
{
	SLL *new,*last;
	new=malloc(sizeof(SLL)); // created a node 
	printf("My Dear! Enter Rollno name and marks\n");
	scanf("%d%s%f",&new->rollno,new->name,&new->marks);

	new->next=0; //always new next is zero
	if(*ptr==0)  // if no records present then
		*ptr=new;  // update headpointer
	else  // if records present 
	{
		last=*ptr; // s	tarted from first node 
		while(last->next) // find the last node 
			last=last->next; // visit next node 

		last->next=new; // update last node next addr as new

	} 

}
void read_file(SLL **ptr)
{
	SLL *new,*last;
	FILE *fp;
	fp=fopen("std.txt","r");
	if(fp==0)
	{
		printf("File not present\n");
		return ;
	}
	while(1){
		new=malloc(sizeof(SLL)); // created a node 
		if(fscanf(fp,"%d%s%f",&new->rollno,new->name,&new->marks)==-1){ // read data from file till reached last
			free(new);
			break;
		}
		new->next=0; //always new next is zero
		if(*ptr==0)  // if no records present then
			*ptr=new;  // update headpointer
		else  // if records present 
		{
			last=*ptr; // started from first node 
			while(last->next) // find the last node 
				last=last->next; // visit next node 

			last->next=new; // update last node next addr as new
		} 
	}
}


void add_begin(SLL **ptr)
{
	SLL *new;
	new=malloc(sizeof(SLL)); // created a node 
	printf("My Dear! Enter Rollno name and marks\n");
	scanf("%d%s%f",&new->rollno,new->name,&new->marks);

	new->next=*ptr; // update newly create node next addr
	*ptr=new; // update headptr 
}

void print_node(SLL *ptr){
	printf("\033[34m******************\n");
	if(ptr==0){
		printf("NO records found\n");
		return ;
	}
	while(ptr){  // till reached to last node
		printf("%d %s %f\n",ptr->rollno,ptr->name,ptr->marks);
		ptr=ptr->next; // visit next node 

	}
	printf("**************************\033[0m");
}


int count_node(SLL *ptr){
	int c=0;
	while(ptr){  // till reached to last node
		c++;
		ptr=ptr->next; // visit next node 
	}

	return c;
}


void save_file(SLL *ptr){
	printf("\033[34m******************\n");
	if(ptr==0){
		printf("NO records found\n");
		return ;
	}
	FILE *fp;
	fp=fopen("std.txt","w");
	while(ptr){  // till reached to last node
		fprintf(fp,"%d %s %f\n",ptr->rollno,ptr->name,ptr->marks);
		ptr=ptr->next; // visit next node 

	}
	printf("**************************\033[0m");
	fclose(fp);
}












