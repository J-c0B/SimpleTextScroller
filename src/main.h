/*
*   
*   SimpleTextScroller
*   
*   author : J-c0B
*   github : https://github.com/J-c0B
*   email : gjak2700@gmail.com 
*
*
*/

#include <stdio.h>
#include <errno.h>

void Install();
void Uninstall();
char * Arguments(int argc, char *argv[]);
void eexit(int code);
void Arg_Err()
{

perror("No valid argument has been provided!");
eexit(1);

}