#ifndef _TABLE_H_
#define _TABLE_H_

#include "mytypes.h"

typedef enum FIELDTYPE
  {
    ONEBYTE=0,
    TWOBYTE=1,
    FOURBYTE=2,
    RESERVER=3   //ONLY ONE BYTE
  }field_type_t;

typedef enum{
  CAT_ONE=0,
  CAT_TWO=1,
  CAT_THREE=2
}category_t;

typedef struct MEM2REG_DATA
{
  uint16_t wordoffset;
  uint16_t byteoffset;
  field_type_t field_type;
  uint16_t field_type_num;
  uint8_t attrID;
}mem2reg_data;
#endif
