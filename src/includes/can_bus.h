#ifndef CAN_TECH_CAN_BUS_H
#define CAN_TECH_CAN_BUS_H

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <pthread.h>

#include "message.h"

void can_bus_create();
void *can_bus(void *arg);
void bus_sender(CAN_Data_Frame* frame);
void bus_receiver(CAN_Data_Frame* frame);

#endif // CAN_TECH_CAN_BUS_H