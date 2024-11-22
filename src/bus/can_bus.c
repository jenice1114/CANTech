#include "can_bus.h"

#define MAX_RETRIES 3

pthread_mutex_t bus_ready_lock = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t bus_ready_cond = PTHREAD_COND_INITIALIZER;
bool bus_ready = false;

bool can_bus_create() {
  pthread_t can_bus_id;
  int retries = 0;

  while (retries < MAX_RETRIES) {
    if (pthread_create(&can_bus_id, NULL, can_bus, NULL) == 0) {
      pthread_mutex_lock(&bus_ready_lock);
      while (!bus_ready) {
        pthread_cond_wait(&bus_ready_cond, &bus_ready_lock);
      }
      pthread_mutex_unlock(&bus_ready_lock);
      return true;
    }

    retries++;
    perror("Failed to create CAN Bus thread. Retrying...");
    sleep(2); // 재시도 간격
  }

  printf("Failed to create CAN Bus after %d retries.\n", MAX_RETRIES);
  return false;
}

void *can_bus(void *arg) {
  pthread_mutex_lock(&bus_ready_lock);
  bus_ready = true;
  pthread_cond_signal(&bus_ready_cond);
  pthread_mutex_unlock(&bus_ready_lock);

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
