#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include "command.h"

static char* greet[6] = {"Hello","Hi","Hey","Welcome back","Hey","Yo"};
static char* write_command[4] = {"set","note","mark","make"};
static char* read_command[4] = {"show","open","tell","saved"};

int main()
{
    srand(time(NULL));
    Search input;

    FILE *rptr;
    rptr = fopen("reminders.txt","w+");
    
    if(rptr == NULL)
    {
        printf("\n<-_-> ERROR : Could not access reminders.txt file...\n");
        exit(0);
    }

    printf("\n<=_=> %s %s ! What can I do for you?\n",greet[rand() % 6],NAME);
    do
    {
        input.type = UNKNOWN;
        printf("\n<-_-> ");
        scanf(" %[^\n]",input.command);
        command_type(&input);
        switch(input.type)
        {
            case GREETING :
                printf("\n<=_=> %s %s ! What can I do for you?\n",greet[rand() % 6],NAME);
                input.greet_count+=1;
                break;

            case REMINDER :
                if( strcasestr(input.command,write_command[0]) != NULL ||
                    strcasestr(input.command,write_command[1]) != NULL ||
                    strcasestr(input.command,write_command[2]) != NULL ||
                    strcasestr(input.command,write_command[3]) != NULL )
                {
                    set_reminder(&input,rptr);
                }
                else if( strcasestr(input.command,read_command[0]) != NULL ||
                         strcasestr(input.command,read_command[1]) != NULL ||
                         strcasestr(input.command,read_command[2]) != NULL ||
                         strcasestr(input.command,read_command[3]) != NULL)
                {
                    show_reminder(&input,rptr);
                }
                break;

            case CAMERA :
                printf("\n<=_=> Ok %s, Opening Camera....\n",NAME);
                sleep(3);
                system("cmd.exe /c start microsoft.windows.camera:");
                break;

            case TIME : 
                print_time();
                break;

            case MUSIC :
                printf("\n<=_=> Ok %s, Playing music....\n",NAME);
                printf("\n<=_=> Use [ctrl + c] to stop music\n");
                sleep(3);
                system("mpg123 \"/mnt/d/New folder (3)/New folder/Sia_-_Cheap_Thrills_(Performance_Edit).mp3\"");
                break;
                
            default :
                printf("\n<=_=> OOPS! I dont't get it %s....\n",NAME);
        }
        getchar();

    }while(1);
}