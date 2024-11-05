#ifndef CAN_TECH_MESSAGE_H
#define CAN_TECH_MESSAGE_H

#include <stdint.h>

#define MAX_DATA_LENGTH 8

typedef struct CAN_Data_Frame{
  uint8_t sof : 1;                     // Start of Frame, 1bit
  uint16_t identifier : 11;            // 메시지 ID, 11bit
  uint8_t rtr : 1;                     // Remote Transmission Request, 1bit
  uint8_t control : 6;                 // Control Field (6bit, DLC 포함)
  uint8_t dlc : 4;                     // Data Length Code (0 ~ 8)
  uint8_t data[MAX_DATA_LENGTH];       // Data Field (최대 8byte)
  uint16_t crc : 15;                   // CRC 오류 검출 코드, 15bit
  uint8_t ack : 2;                     // ACK, 2bit
  uint8_t eof : 7;                     // End of Frame, 7bit
} CAN_Data_Frame;

/*
  TODO:: Type of frame to be added later.
 
  Remote Frame
  Error Frame
  Overload Frame
  InterFrame Space
*/

#endif // CAN_TECH_MESSAGE_H