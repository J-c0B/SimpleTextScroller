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
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

#include "shellinfo.h"
#include "main.h"

#define MAX_SIZE 8192

int wtime = 50;

int main(int argc, char *argv[])
{
Saveshellconfig();
Shellconfig();
setbuf(stdout,NULL);

struct shellsize s_size;
struct cursor_position start_pos;
char * message = Arguments(argc,argv);
char line[MAX_SIZE];
char * p_message = &line[strlen(message)];
bool qsignal = false;



Getshellsize(&s_size);
Setcursor(&start_pos,0,s_size.y/2);
Initialise(message,line,s_size);

while (!qsignal)
{


for(int n = 0 ; n <= s_size.x ; n++)
{
    if(Quit() == true)
    {
    qsignal = true;
    break;
    }
    wait(wtime);
     if(Resizecheck(s_size))
    {
        Getshellsize(&s_size);
        Setcursor(&start_pos,0,s_size.y/2);
        Initialise(message,line,s_size);
        continue;
    }
    print(line,s_size);
    scroll(s_size,line);
    movecursor(start_pos);
    p_message++;
}

}

    eexit(0);
}



char * Arguments(int argc, char *argv[])
{

char * string;

if(argc > 1)
{


if(strcmp(argv[1],"-h") == 0 || strcmp(argv[1],"-help") == 0 || strcmp(argv[1],"--help") == 0)
{
printf("--help , -help , --h , -h \t prints available commands.\n --time , -time , -t \t sets the time between every message scroll.\n");
printf("--install , -install , -i \t Install the SimpleTextScroller.\n --uninstall , -uninstall , -u Uninstall the SimpleTextScroller.\n");   
eexit(0);
}
else if(strcmp(argv[1],"-i") == 0 || strcmp(argv[1],"-install") == 0 || strcmp(argv[1],"--install") == 0)
{
Install();
eexit(0);
}
else if(strcmp(argv[1],"-u") == 0 || strcmp(argv[1],"-uninstall") == 0 || strcmp(argv[1],"--uninstall") == 0)
{
Uninstall();   
eexit(0);
}
else
    for(int n = 1; n < argc ;n++)
{

if(strcmp(argv[n],"-time") == 0 || strcmp(argv[n],"--time") == 0 || strcmp(argv[n],"-t") == 0)
{

if(n+1 < argc)
{
    wtime = atoi(argv[n+1]);
    n++;
} 
else
    Arg_Err();

}
else if (string == NULL)
{
string = argv[n];
}

}

return string;
}
else
    Arg_Err();

}
void eexit(int code)
{
    if(code == -1)
    {
        Restoreshellconfig(true);
        code = 0;
    }
    else
        Restoreshellconfig(false);

exit(code);
}

void Install()
{
char cpath[256];
getcwd(cpath,sizeof(cpath));
chdir(cpath);
system("sudo ln sts /usr/bin/sts");
}

void Uninstall()
{
system("sudo rm /usr/bin/sts");
}