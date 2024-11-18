#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "can_bus.h"
#include "can_tech_ui.h"

int main() {
  // Create a can bus ui.
  can_bus_display();

  // Get node count from user.
  int nodes = get_node_count();

  // Create bus thread.
  can_bus_create();

  getch();
  endwin();

  printf("Program terminated.\n");
  return EXIT_SUCCESS;
}
