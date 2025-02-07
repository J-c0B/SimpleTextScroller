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

#include <stdbool.h>

struct shellsize
{
int x,y;
};
struct cursor_position 
{
int x,y;
};

void Saveshellconfig();
void Restoreshellconfig(bool command_h);
void Shellconfig();
void Error();
bool Resizecheck(struct shellsize size);
void Getshellsize(struct shellsize * size);
bool Quit();

void scroll(struct shellsize size,char line[],bool direction);
void Setcursor(struct cursor_position *c_pos, int x, int y);
void movecursor(struct cursor_position c_pos);
void wait(unsigned int milliseconds);
void print(char * line,struct shellsize size);
void Initialise(char * message,char line[],struct shellsize size);