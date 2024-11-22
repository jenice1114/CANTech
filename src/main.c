#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "can_bus.h"
#include "can_tech_ui.h"
#include "can_node.h"

int main() {
  // Create a can bus ui.
  can_bus_display();

  // Get node count from user.
  int nodes = get_node_count();

  // Create bus thread.
  while (1) {
    if (can_bus_create()) {
      break;
    }

    char choice;
    printf("Failed to create CAN Bus. Do you want to retry? (y/n): ");
    scanf(" %c", &choice);

    if (choice == 'n' || choice == 'N') {
      printf("Exiting program.\n");
      return EXIT_FAILURE;
    }
  }

  // Create nodes thread.
  nodes_create(nodes);

  getch();
  endwin();

  printf("Program terminated.\n");
  return EXIT_SUCCESS;
}
