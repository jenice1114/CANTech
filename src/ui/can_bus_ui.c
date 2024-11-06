#include "can_bus_ui.h"

void can_bus_display() {
  initscr();
  noecho();
  curs_set(FALSE);

  int row, col;
  getmaxyx(stdscr, row, col);
  mvprintw(row / 2 - 1, (col - 20) / 2, "----------------------");
  mvprintw(row / 2, (col - 20) / 2, "       CAN Bus       ");
  mvprintw(row / 2 + 1, (col - 20) / 2, "----------------------");
  refresh();
}
