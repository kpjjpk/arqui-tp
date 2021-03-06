#include "../include/kasm.h"
#include "../include/defs.h"
#include "../include/inthandlers.h"
#include "../include/video.h"
#include "../include/keyboard.h"
#include "../include/shell.h"

/********************************** 
*
*  Kernel
*
***********************************/

#ifndef _kernel_
#define _kernel_

#define OS_PID	0


typedef enum eINT_80 {WRITE=0, READ} tINT_80;
typedef enum eUSER {U_KERNEL=0, U_NORMAL} tUSERS;

/* __write
*
* Recibe como parametros:
* - File Descriptor
* - Buffer del source
* - Cantidad
*
**/
size_t __write(int fd, const void* buffer, size_t count);

/* __read
*
* Recibe como parametros:
* - File Descriptor
* - Buffer a donde escribir
* - Cantidad
*
**/
size_t __read(int fd, void* buffer, size_t count);

#endif