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


unsigned int _strlen(char *s);
char **comd_to_av(char *s);
char *_strdup(char *str);
int _strcmp(char *s1, char *s2);
char *_getenv(const char *name);
int print_dir(void);
dir_t **link_dir(dir_t **head);
dir_t *add_nodedir_end(dir_t **head, char *s);
dir_t *traverse_end(dir_t *h);
char *_strcat(char *dest, char *src);
char *_strcpy(char *dest, char *src);
/* environment variables */
extern char **environ;

#endif /* SHELL_H */
