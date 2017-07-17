#ifndef SHELL_H
#define SHELL_H
#include <unistd.h>
#include <sys/types.h>
#include <signal.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <sys/resource.h>
#include <errno.h>


/* struct for PATH directories */
typedef struct dir_s
{
	char *dir;
	struct dir_s *next;
} dir_t;

char *prompt_readline(void);
char *_strdup(char *str);
char **comd_to_av(char *s);
char *_getenv(const char *name, char *envp[]);
dir_t **link_dir(dir_t **head, char *envp[]);
dir_t *add_nodedir_end(dir_t **head, char *s);
int _strcmp(char *s1, char *s2);
unsigned int _strlen(char *s);
char *_strcat(char *dest, char *src);
int print_dir(void); /* how do we use this function? */
char *_strcpy(char *dest, char *src);
dir_t *traverse_end(dir_t *h);




#endif /* SHELL_H */
