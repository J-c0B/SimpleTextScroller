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
#include <termios.h>
#include <unistd.h>
#include <sys/ioctl.h>

#include "shellinfo.h"

static struct termios t_settings,c_settings;

void Getshellsize(struct shellsize * size)
{
struct winsize shell_size;
ioctl(0, TIOCGWINSZ, &shell_size);
size->x = shell_size.ws_col;
size->y = shell_size.ws_row;
}

void Shellconfig()
{

printf("\x1b[?25l");

tcgetattr(1,&c_settings);
c_settings.c_lflag = ~ECHO;
c_settings.c_lflag &= ~ICANON;
tcsetattr(0,0,&c_settings);

}

void Saveshellconfig()
{
tcgetattr(1,&t_settings);
}

void Restoreshellconfig(bool command_h)
{
    
printf("\x1b[?25h");
if(command_h)  
{
    printf("\x1b[2J");
    printf("\x1b[H");
}
tcsetattr(0,0,&t_settings);
}

bool Resizecheck(struct shellsize size)
{
    
struct shellsize c_size;
Getshellsize(&c_size);
return ((size.x == c_size.x && size.y == c_size.y) ? false : true);

}

bool Quit()
{
char Key = 0;
int pressed;
ioctl(0, FIONREAD,&pressed);
    if(pressed)
read(0, &Key, 1);

return ((Key == 'Q' || Key == 'q') ? true : false);
 
}