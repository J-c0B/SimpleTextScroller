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
#include <time.h>
#include <string.h>

#include "shellinfo.h"

void wait(unsigned int milliseconds)
{
static struct timespec r_time;
struct timespec w_time;

w_time.tv_sec = 0;
r_time.tv_sec = 0; 

r_time.tv_nsec = 0;
w_time.tv_nsec = (milliseconds*1000000)+r_time.tv_nsec;

nanosleep(&w_time,&r_time);
}

void movecursor(struct cursor_position c_pos)
{
printf("\x1B[%i;%iH",c_pos.y,c_pos.x);
}

void scroll(struct shellsize size,char line[])
{
char l_char = ' ',n_char = ' ';

for (int n = 0 ; n < size.x ; n++)
{
l_char = n_char;
n_char = line[n];

if(n == size.x-1)
    line[0] = l_char;
else
    line[n] = l_char;

}

}

void print(char * line,struct shellsize size)
{
printf("\x1B[2J");
for(int n = 0 ; n < size.x;n++)
{
printf("%c",line[n]);
}
}

void Initialise(char * message,char * line,struct shellsize size)
{   

for(int n = 0 ; n < size.x ; n++)
    line[n] = ' ';


for(int n = 0 ; strlen(message) <= size.x && n < size.x ; n++)
{
line[n] = message[n];
if(n > strlen(message))
    line[n] = ' ';
}
}

void Setcursor(struct cursor_position *c_pos, int x,int y)
{
c_pos->x = x;
c_pos->y = y;
}