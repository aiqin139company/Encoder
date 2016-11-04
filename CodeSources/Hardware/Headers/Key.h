#ifndef _KEY_H_
#define _KEY_H_

#ifdef __cplusplus
 extern "C" {
#endif

#include "BSP.h"

void Key_Init(void);
u8 Key_Scan(u8 mode);

#ifdef __cplusplus
}
#endif
#endif /* _KEY_H_ */

