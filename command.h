#ifndef COMMAND_H
#define COMMAND_H

#define MAX_GREET 8
#define NAME "BOSS"

typedef enum
{
    GREETING,
    DOCUMENT,
    MUSIC,
    TIME,
    CAMERA,
    REMINDER,
    UNKNOWN
}Command;

typedef struct 
{
    int greet_count;
    char command[100];
    Command type;
}Search;

void command_type(Search *input);
int is_greet(char *command);
int is_reminder(char *command);
void set_reminder(Search *input, FILE *rptr);
void show_reminder(Search *input,FILE *rptr);
int is_camera(char *command);
int is_time(char *command);
void print_time(void);
int is_music(char *command);

#endif