
#include "AD5235.h"

#include <string.h>
#include "hal_functions.h"

#define DPOT_HEADER_RDAC 0xB0
//#define DPOT_HEADER_RDAC 0xB1

void DPOT_write(dev_id id, uint16_t val) {

  char tx[3] = { DPOT_HEADER_RDAC, 0x00, 0x00};
  char rx[3];

  tx[1] = (val >> 8);
  tx[2] = (val & 0x00FF);

  HAL_SPI_readWrite(id, &tx, 3, &rx);
  usleep(10);

  tx[0] = 0xB1;
  HAL_SPI_readWrite(id, &tx, 3, &rx);

}
