#include "../include/sysio.h"


size_t __sys_write(int fd, const void* buffer, size_t count){
	switch(fd){
		case STD_ERR:
		case STD_OUT:
			__print(STD_DISPLAY,buffer,count);break;
		case REG_OUT:
			__print(REG_DISPLAY,buffer,count);break;
		default:
			return -1;
	}
}

size_t __sys_read(int fd, void* buffer, size_t count){
	size_t nread;

	switch(fd){
		case STD_IN: {
			nread=__read_from_stdin(fd, buffer,count);break;
		}
		default: nread=-1; break;
	}
	return nread;
}

size_t __read_from_stdin(int fd, void* buffer, size_t count){
	_Sti();

	size_t i;
	char ch;
	char* aux;
	if(fd==STD_IN){
		for(i=0;i<count;i++){
			ch='\0';
			while(ch=='\0'){
				ch=getKBChar();	
			}
			aux=(char*)buffer;
			*(aux+i)=ch;
		}
	}
	return i;
}