#include "can_tech_ui.h"

#include <pthread.h>

#define MAX_NODES 5

static pthread_mutex_t ui_lock = PTHREAD_MUTEX_INITIALIZER;
static int current_node_count = 0;

void can_bus_display() {
  initscr();
  noecho();
  curs_set(FALSE);

  int row, col;
  getmaxyx(stdscr, row, col);

  char *can_bus_txt[] = {
      "  #####      ###    ##    ##        #####   ##     ##  ######   ",
      " ##   ##    ## ##   ###   ##        ##  ##  ##     ##  ##    ## ",
      "##         ##   ##  ####  ##        ##  ##  ##     ##  ##       ",
      "##        ##     ## ## ## ##        #####   ##     ##  ######   ",
      "##        ######### ##  ####        ##  ##  ##     ##        ## ",
      " ##   ##  ##     ## ##   ###        ##  ##  ##     ##  ##    ## ",
      "  #####   ##     ## ##    ##        #####    #######   ######   "
  };

  int txt_height = sizeof(can_bus_txt) / sizeof(can_bus_txt[0]);
  int txt_width = strlen(can_bus_txt[0]);

  int line_length = txt_width + 80;
  int line_x = (col - line_length) / 2;
  int line_above = (row - txt_height) / 2 - 2;
  int line_below = (row + txt_height) / 2 + 1;

  mvhline(line_above, line_x, '=', line_length);
  int txt_x = (col - txt_width) / 2;
  int txt_y = (row - txt_height) / 2;
  for (int i = 0; i < txt_height; i++) {
    mvprintw(txt_y + i, txt_x, "%s", can_bus_txt[i]);
  }
  mvhline(line_below, line_x, '=', line_length);

  refresh();
}

int get_node_count() {
  int node = 0;

  curs_set(TRUE);
  while (1) {
    move(LINES - 3, 2);
    clrtoeol();
    mvprintw(LINES - 3, 2, "Enter the number of nodes (max %d): ", MAX_NODES);
    refresh();

    echo();
    scanw("%d", &node);

    if (node >= 1 && node <= MAX_NODES) {
      break;
    } else {
      mvprintw(LINES - 2, 2, "Help:: Invalid input. (1 ~ %d)", MAX_NODES);
      refresh();
    }
  }

  move(LINES - 3, 2);
  clrtoeol();
  move(LINES - 2, 2);
  clrtoeol();
  refresh();

  return node;
}

void can_node_display() {
  int row, col;
  getmaxyx(stdscr, row, col);

  int bus_y = (row + 7) / 2;
  int node_y = bus_y + 3;
  int spacing = 20;
  int node_start_x = (col - (spacing * (current_node_count - 1))) / 2;

  for (int i = 0; i < current_node_count; i++) {
    mvprintw(node_y, node_start_x + (i * spacing), "Node %d", i + 1);
  }

  refresh(); // 화면 갱신
}

void update_node_count(int nodes) {
  pthread_mutex_lock(&ui_lock);
  current_node_count = nodes;
  can_node_display();
  pthread_mutex_unlock(&ui_lock);
}
