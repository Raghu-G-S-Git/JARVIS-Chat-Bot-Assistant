#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "command.h"

static Command type = UNKNOWN;

static char *greeting[MAX_GREET] = {"Hello","Hi","Hey","Hye","Welcome back","Yo","Jarvis",NAME}; 

static char *reminders[3] = {"reminder","set","note"}; 

static char *camera[3] = {"camera","vedio","picture"}; 

static char *istime[2] = {"time","date"}; 

static char *music[4] = {"music","song","audio","play"}; 

void command_type(Search *input)
{
    input->greet_count = 0;
    if(is_greet(input->command) == 1)
    {
        input->type = GREETING;
    }
    else if(is_reminder(input->command) ==  1)
    {
        input->type = REMINDER;
    }
    else if(is_camera(input->command) == 1)
    {
        input->type = CAMERA;
    }
    else if(is_time(input->command) == 1)
    {
        input->type = TIME;
    }
    else if(is_music(input->command) == 1)
    {
        input->type = MUSIC;
    }
    return;  
}

int is_greet(char *command)
{
    int i=0;
    
    while(i < MAX_GREET)
    {
        if(strcasestr(command,greeting[i]) != NULL)
            return 1;
        i++;
    }
    return 0;
}

int is_reminder(char *command)
{
    int i=0;
    
    while(i < 3)
    {
        if(strcasestr(command,reminders[i]) != NULL)
            return 1;
        i++;
    }
    return 0;
}

void set_reminder(Search *input, FILE *rptr)
{
    char *msg_start = NULL;
    
    // Try to find any of the reminder keywords
    for(int i = 0; i < 3; i++)
    {
        msg_start = strcasestr(input->command, reminders[i]);
        if(msg_start != NULL)
        {
            msg_start += strlen(reminders[i]); // skip the keyword
            while(*msg_start == ' ' || *msg_start == ':' || *msg_start == '-')
                msg_start++; // skip extra characters
            break;
        }
    }

    if (msg_start != NULL && *msg_start != '\0')
    {
        fwrite(msg_start, strlen(msg_start), 1, rptr);
        fwrite("\n", 1, 1, rptr); // new line for better file formatting
        fflush(rptr); // ensure it's written to file
        printf("\n<=_=> Reminder is set for %s\n", msg_start);
    }
    else
    {
        printf("\n<=_=> Couldn't extract reminder message.\n");
    }
}

void show_reminder(Search *input,FILE *rptr)
{
    char ch;
    int reminder_no = 1;

    fseek(rptr, 0, SEEK_END);
    if (ftell(rptr) == 0)
    {
        printf("\n<=_=> No Reminders set!\n");
        return;
    }
    rewind(rptr);

    printf("\n<=_=> Here are your saved reminders:\n");

    printf("\tReminder %d : ", reminder_no);
    while ((ch = fgetc(rptr)) != EOF)
    {
        if (ch == '\n')
        {
            printf("\n");
            reminder_no++;
            if ((!feof(rptr)) && ((ch=fgetc(rptr)) != EOF))
                printf("\tReminder %d : %c", reminder_no,ch);
        }
        else
        {
            printf("%c", ch);
        }
        
    }
    return;
}

int is_camera(char *command)
{
    int i=0;
    
    while(i < 3)
    {
        if(strcasestr(command,camera[i]) != NULL)
            return 1;
        i++;
    }
    return 0;
}

int is_time(char *command)
{
    int i=0;
    
    while(i < 2)
    {
        if(strcasestr(command,istime[i]) != NULL)
            return 1;
        i++;
    }
    return 0;
}

void print_time(void)
{
    time_t now = time(NULL);
    struct tm *t = localtime(&now);

    char buf[100];
    strftime(buf, sizeof(buf), "[%Y-%m-%d] [%I:%M:%S %p]", t);
    printf("\n<=_=> It is: %s\n", buf);

    return;
}

int is_music(char *command)
{
    int i=0;
    
    while(i < 4)
    {
        if(strcasestr(command,music[i]) != NULL)
            return 1;
        i++;
    }
    return 0;
}