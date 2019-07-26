#include <ncurses.h>
#include <stdlib.h>
#include <time.h>
#include "snake.h"

void test_this_thing(Node* head){
  refresh();
  printw("%d %d\n", head->y, head->x);
  getch();
  printw("%d %d\n", my,mx);
  getch();
}

int main(){
  initscr();
  cbreak();
  noecho();
  curs_set(0);
  nodelay(stdscr,true);
  getmaxyx(stdscr, my, mx);
  Node* head=NULL;
  push(&head,(int)(mx/2),(int)(my/2));
  //test_this_thing(head);
  rand_coor();
  struct timespec cycle;
  cycle.tv_sec=0;
  cycle.tv_nsec=1000000000/10;
  while(true){
    nanosleep(&cycle, NULL);
    get_dir(head, getch());
    refresh();
    int x=next_x(head);
    if(x<0||x>mx){
      break;
    }

    int y=next_y(head);
    if(y<0||y>my){
      break;
    }
    
    push(&head, x, y);
    if(x==rand_x&&y==rand_y){
      rand_coor();
      continue;
    }
    remove_last(head);
    refresh_win(head);
  }
  endwin();
  free_ll(head);
  return 0;
}
