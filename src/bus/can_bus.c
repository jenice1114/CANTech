#include "can_bus.h"

void can_bus_create() {
  pthread_t can_bus_id;

  if (pthread_create(&can_bus_id, NULL, can_bus, NULL) != 0) {
    perror("Failed to create CAN Bus thread.");
    return EXIT_FAILURE;
  }

  pthread_join(can_bus_id, NULL);
}

void *can_bus(void *arg) {
  while (1) {
    // TODO:: 버스 메시지 수신 감지
    sleep(1);
  }

  return NULL;
}

void bus_sender(CAN_Data_Frame* frame) {
  // TODO:: 우선순위로 정렬 -> 관련 Node로 ACK 전달
}


void bus_receiver(CAN_Data_Frame* frame) {
  // TODO:: 메시지 파싱 -> ACK(생성) -> bus_sender
}
