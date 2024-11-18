#ifndef CAN_TECH_CAN_NODE_H
#define CAN_TECH_CAN_NODE_H

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#include "message.h"

void nodes_create(int nodes);
void *can_node(void *arg);
void node_sender(CAN_Data_Frame* frame);
void node_receiver(CAN_Data_Frame* frame);

#endif // CAN_TECH_CAN_NODE_H