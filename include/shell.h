#ifndef SHELL_H
#define SHELL_H

#include "../include/defs.h"
#include "../include/stdio.h"
#include "../include/commands.h"
#include "../include/string.h"

//TODO these are just for constants
#include "../include/keyboard.h"
#include "../include/video.h"

#define USER_NAME			"user"
#define PC_NAME				"PC"
#define SHELL_PROMPT_END	"$ "

#define WELCOME_MSG			"Welcome to changOS!"

#define SHELL_BUFFER_SIZE	SIZE_BUFFER //TODO: not the nicest name
#define LINE_WIDTH			WIDTH //WIDTH

#define SHELL_COMMAND_COUNT 7
#define MAX_SHELL_ARGS		10


typedef struct {
    char * name;
    void (*cmd)(int,char**);
} ShellCommand;

void shell();

void __print_welcome_message();
void __load_shell_buffer(int promptLength);
void __parse_shell_command();
void __invoke_shell_command(int argc, char ** args);
int __draw_prompt();
void __clear_shell_buffer();


#endif