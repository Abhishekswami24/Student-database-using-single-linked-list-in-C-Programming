#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
typedef struct Student
{
  int rollno;
  char name[20];
  float marks;
  struct Student *next;
}SLL;

void add_begin(SLL **);
void print_node(SLL*);
int count_node(SLL*);
void save_file(SLL*);
void reverse_print(SLL*);
void print_rec(SLL*);
void reverse_rec(SLL*);
void add_end(SLL **);
void read_file(SLL**);
void delete_all(SLL**);
void search_node(SLL*);
void add_middle(SLL**);
void sort_data(SLL*);
void delete_node(SLL**);
void reverse_links(SLL**);

