#include "can_bus_ui.h"

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
