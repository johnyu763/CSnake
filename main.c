#include <ncurses.h>
#include <stdlib.h>
#include <time.h>
#include "snake.h"

int main(){
  initscr();
  cbreak();
  noecho();
  curs_set(0);
  nodelay(stdscr,true);
  getmaxyx(stdscr, my, mx);
  Node* head=NULL;
  push(&head,(int)(mx/2),(int)(my/2));
  int length=1;
  rand_coor();
  struct timespec cycle;
  cycle.tv_sec=0;
  cycle.tv_nsec=1000000000/10;
  while(true){
    nanosleep(&cycle, NULL);
    get_dir(getch());
    refresh();
    int x=next_x(head);
    if(x<0||x>mx){
      break;
    }

    int y=next_y(head);
    if(y<0||y>my){
      break;
    }
    
    if(check_collide(head, length, x, y)){
      break;
    }
    
    push(&head, x, y);
    if(x==rand_x&&y==rand_y){
      rand_coor();
      length++;
      continue;
    }
    remove_last(head);
    refresh_win(head);
  }
  endwin();
  free_ll(head);
  return 0;
}

