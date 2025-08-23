#ifndef __BEEP_H
#define __BEEP_H
#include "sys.h"

#define BEEP PBout(8) //BEEP
void BEEP_init(void);
void BEEP_on(void);
void BEEP_off(void);

#endif
