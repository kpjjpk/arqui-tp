#include "../include/shell.h"

char buffer[SHELL_BUFFER_SIZE]={NULL_CHAR};

ShellCommand commands[SHELL_COMMAND_COUNT]={
												{"echo",echo},
											};

void shell(){
	int promptLength;
	 promptLength=__draw_prompt();
	 __load_shell_buffer(promptLength);
	 __parse_shell_command();
	 __clear_shell_buffer();
}

void __load_shell_buffer(int promptLength){//FIXME weird behaviour here every now and then. Maybe it's bochs?
	char curr;
	int i=0,printed=promptLength;

	do{
		curr=readChar();

		if(curr=='\n'){
			printf("\n");
			return;
		}

		if(curr=='\b'){
			if(printed==promptLength){
				break;
			}else{
				//IMPORTANT: this is necessary because below 1 is being added below
				//FIXME doesn't delete chars from the buffer!
				printed-=2;
			}
		}//FIXME: it takes \bs and puts them on the buffer: WRONG!
		//FIXME: apparently there are \ns in the buffer!
		buffer[i]=curr;
		printed+=iputc(buffer[i],STD_OUT);

		if(printed==LINE_WIDTH){
			printf("\n");
			printed=0;
		}

		i++;
	} while(i<SHELL_BUFFER_SIZE);
	// printf("salgo %d\n",i);
}

void __parse_shell_command(){
	char * args[MAX_SHELL_ARGS+1]={"\0"};
	int i=0,argc=0;

	char c;
	bool expectingParam=true;
	while(buffer[i]!='\0' && argc < MAX_SHELL_ARGS+1){
		c=buffer[i];
		switch(c){
			default:
				if(expectingParam==true){
					args[argc]=buffer+i;
					argc++;
					expectingParam=false;
				}
				break;
			case '\t':
			case ' ':
				buffer[i]='\0';
				expectingParam=true;
				break;
		}
		i++;
	}
	__invoke_shell_command(argc,args);
}

void __invoke_shell_command(int argc, char ** args){
	int i;
	char * name=args[0];

	for(i=0;i<SHELL_COMMAND_COUNT;i++){
		if(strcmp(name,commands[i].name)==0){
			(*(commands[i].cmd))(argc-1,args+1);
			return;
		}
	}
	echo(argc,args);
	return;
}

int __draw_prompt(){
	return printf("%s@%s:~%s",USER_NAME,PC_NAME,SHELL_PROMPT_END);
}

void __clear_shell_buffer(){
	int toClear;
	for(toClear=SHELL_BUFFER_SIZE;toClear>=0;toClear--){
		buffer[toClear]=NULL_CHAR;
	}
}