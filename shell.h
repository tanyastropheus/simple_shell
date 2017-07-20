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

/**
 * struct dir_s - struct for elements in the singly linked list of directories
 * @dir: pointer to the directory in PATH
 * @next: pointer to the next node
 */

typedef struct dir_s
{
	char *dir;
	struct dir_s *next;
} dir_t;

/**
 * struct mem_s - struct for pointers to malloced memory in the program
 * @s: pointer to the string read and allocated in heap by getline()
 * @strcp: pointer to the copy of string s which strtok() is called on to count
 * the number of tokens
 * @argv: double pointer to the array of pointers to the tokenized string strcp
 * @env_cpy: pointer to the string that is a  copy of the environment variable
 * @h: pointer to the head node of the singly linked list
 * @buf: pointer to the string that is the absolute path of the command
 */

typedef struct mem_s
{
	char *s;
	char *strcp;
	char **argv;
	char *env_cpy;
	dir_t *h;
	char *buf;
} mem_t;

char *prompt_readline(mem_t *mem);
char *readline(mem_t *mem);
char *_strdup(char *str);
char **comd_to_av(char *s, mem_t *mem);
char *_getenv(const char *name, char *envp[], mem_t *mem);
dir_t **link_dir(dir_t **head, char *envp[], mem_t *mem);
dir_t *add_nodedir_end(dir_t **head, char *s);
int _strcmp(char *s1, char *s2);
unsigned int _strlen(char *s);
char *_strcat(char *dest, char *src);
/*int print_dir(void); /* how do we use this function? */
char *_strcpy(char *dest, char *src);
dir_t *traverse_end(dir_t *h);
char *search_PATH(char *file, char *envp[], mem_t *mem);
int fork_exec(char *file, char *av[], char *envp[]);
void free_all(mem_t *mem);


#endif /* SHELL_H */
