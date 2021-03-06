/*********************************************
kasm.h

************************************************/

#include "defs.h"


unsigned int _read_msw();

void        _lidt(IDTR *idtr);

void		_mascaraPIC1(byte mascara);  /* Escribe mascara de PIC1 */
void		_mascaraPIC2(byte mascara);  /* Escribe mascara de PIC2 */

void		_Cli(void);				/* Deshabilita interrupciones  */
void		_Sti(void);				/* Habilita interrupciones  */

void		_int_08_hand();			/* Timer tick */
void		_int_09_hand();
void		_int_80_hand();			/**/

size_t		_Sys_Call();			/**/

void 		_ejectCD();

void		_debug(void);

void 		_closeCD();

void		_infoCD();

void 		_ejectCD();

void		_registerschange();
