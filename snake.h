#ifndef SNAKE_H_
#define SNAKE_H_

extern int mx,my,rand_x,rand_y,x_dir,y_dir;

typedef struct Node{
  int x,y;
  struct Node* next;
}Node;

void free_ll(Node* head);
void push(Node** head, int x, int y);
void refresh_win(Node* head);
void append(Node** head,int x,int y);
int next_x(Node* head);
int next_y(Node* head);
void rand_coor();
void get_dir(Node* head, char dir);
void remove_last(Node* head);

#endif  
