#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>

#include "can_bus.h"
#include "can_bus_ui.h"

int main() {
  // Create a can bus ui.
  can_bus_display();

  // Get node count from user.
  int nodes = get_node_count();

  pthread_t can_bus_id;

  if (pthread_create(&can_bus_id, NULL, can_bus, NULL) != 0) {
    perror("Failed to create CAN Bus thread.");
    return EXIT_FAILURE;
  }

  pthread_join(can_bus_id, NULL);

  getch();
  endwin();

  printf("Program terminated.\n");
  return EXIT_SUCCESS;
}
