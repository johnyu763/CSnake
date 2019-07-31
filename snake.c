#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "snake.h"

int mx=0,my=0,rand_x=0,rand_y=0,x_dir=0,y_dir=-1;

void free_ll(Node* head){
  Node* temp;
  while(head!=NULL){
    temp=head;
    head=head->next;
    free(temp);
  }
}
void refresh_win(Node* head){
  erase();
  mvaddch(rand_y,rand_x,ACS_DIAMOND);
  Node* temp=head;
  while(temp!=NULL){
    mvaddch(temp->y,temp->x,ACS_CKBOARD);
    temp=temp->next;
  }
}
int next_x(Node* head){
  return head->x+x_dir;
}
int next_y(Node* head){
  return head->y+y_dir;
}
void push(Node** head, int x,int y){
  Node* new_node=(Node*)malloc(sizeof(Node));
  new_node->x=x;
  new_node->y=y;
  if(*head!=NULL){
    new_node->next=*head;
  }
  *head=new_node;
}
void get_dir(char dir){
  switch(dir){
    case 'w':
      if(x_dir){
        y_dir=-1;
        x_dir=0;
      }
      break;
    case 'a':
      if(y_dir){
        x_dir=-1;
        y_dir=0;
      }
      break;
    case 's':
      if(x_dir){
        y_dir=1;
        x_dir=0;
      }
      break;
    case 'd':
      if(y_dir){
        x_dir=1;
        y_dir=0;
      }
      break;
    default:
      x_dir=x_dir;
      y_dir=y_dir;
      break;
  }
}
void rand_coor(){
  srand(time(0));
  rand_x=rand()%mx;
  rand_y=rand()%my;
}
void remove_last(Node* head){
  if(head==NULL){
    return;
  }
  if(head->next==NULL){
    free(head);
    return;
  }
  
  Node* temp=head;
  while(temp->next->next!=NULL){
    temp=temp->next;
  }
  free(temp->next);
  temp->next=NULL;
}
bool check_collide(Node* head, int length,int x, int y){
  if(length<4){
    return false;
  }

  Node* temp=head->next->next->next;
  while(temp!=NULL){
    if(x==temp->x&&y==temp->y){
      return true;
    }
    temp=temp->next;
  }

  return false;
}
