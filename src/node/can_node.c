#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

#include "can_node.h"
#include "can_bus.h"
#include "can_tech_ui.h"

void nodes_create(int nodes) {
  pthread_t* node_threads = malloc(nodes * sizeof(pthread_t));
  int* node_ids = malloc(nodes * sizeof(int));

  if (node_threads == NULL || node_ids == NULL) {
    perror("Failed to allocate memory for nodes.");
    exit(EXIT_FAILURE);
  }

  for (int i = 0; i < nodes; i++) {
    node_ids[i] = i + 1;
    if (pthread_create(&node_threads[i], NULL, can_node, &node_ids[i]) != 0) {
      perror("Failed to create CAN Node thread.");
      free(node_threads);
      free(node_ids);
      exit(EXIT_FAILURE);
    }
  }
  update_node_count(nodes);

  for (int i = 0; i < nodes; i++) {
    pthread_join(node_threads[i], NULL);
    printf("Node %d thread joined.\n", i + 1);
  }

  free(node_threads);
  free(node_ids);
}

void* can_node(void* arg) {
  int node_id = *(int*)arg;
  CAN_Data_Frame frame;

  frame.identifier = node_id;
  frame.dlc = 8;
  // TODO:: 식별 데이터 받아오는 로직
  for (int i = 0; i < frame.dlc; i++) {
    frame.data[i] = i + node_id;
  }

  while (1) {
    node_sender(&frame);
    sleep(1);
  }

  return NULL;
}

void node_sender(CAN_Data_Frame* frame) {
  // TODO:: 버스로 메시지 송신
  bus_receiver(frame);
}

void node_receiver(CAN_Data_Frame* frame) {
  printf("Node %d received message from Node %d\n", frame->identifier, frame->identifier);
  // TODO:: ACK 수신 -> UI 갱신 -> 수신한 데이터에 따른 처리
}
