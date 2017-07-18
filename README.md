<p align="center">
<img src="https://s-media-cache-ak0.pinimg.com/736x/80/73/8e/80738e33b4644eef4a72af90d511adfa--seashell-art-seashell-crafts.jpg" alt="Shell Seahorse"/>
</p>

# Title #
0x15. C - Simple Shell

* [Table of Contents](#table-of-contents) 
	* [Authors](#Author)	
	* [Description](#description)
	* [Objectives](#objectives)
	* [Output](#output)
	* [Allowed Functions](#allowed-functions)
	* [Installation](#installation)
	* [Compilation](#compilation)
	* [Requirements](#requirements)
	* [Tasks](#tasks)
	  * [Mandatory 0](#mandatory-0)
	  * [Mandatory 1](#mandatory-1)
	  * [Mandatory 2](#mandatory-2)
	  * [Mandatory 3](#mandatory-3)
	  * [Mandatory 4](#mandatory-4)
	  * [Mandatory 5](#mandatory-5)
	  * [Mandatory 6](#mandatory-6)
	  * [Mandatory 7](#mandatory-7)

### Authors ###
* Jeffrey Kanemitsu
	* https://github.com/jeffreykanemitsu
	* https://twitter.com/canofmisosoup
* Tanya Kryukova
	* https://github.com/tanyastropheus
	* https://twitter.com/tyastropheus

### Description ###
Write a simple UNIX command interpreter.

### Objectives ###
* Understand the following concepts:
	* How does a shell work
	* What is a pid and a ppid
	* How to manipulate the environment of the current process
	* What is the difference between a function and a system call
	* How to create processes
	* What are the three prototypes of <code>main</code>
	* How does the shell use the <code>PATH</code> to find the programs
	* How to execute another program with the <code>execve</code> system call
	* How to suspend the execution of a process until one of its children terminates
	* What is <code>EOF</code>
### Output ###
<li>Unless specified otherwise, your program <strong>must have the exact same output</strong> as <code>sh</code> (<code>/bin/sh</code>) as well as the exact same error output.</li>
<li>The only difference is when you print an error, the name of the program must be equivalent to your <code>argv[0]</code> (See below)</li>
</ul>

<p>Example of error with <code>sh</code>:</p>

<pre><code>$ echo &quot;qwerty&quot; | /bin/sh
/bin/sh: 1: qwerty: not found
$ echo &quot;qwerty&quot; | /bin/../bin/sh
/bin/../bin/sh: 1: qwerty: not found
$
</code></pre>

<p>Same error with your program <code>hsh</code>:</p>

<pre><code>$ echo &quot;qwerty&quot; | ./hsh
./hsh: 1: qwerty: not found
$ echo &quot;qwerty&quot; | ./././hsh
./././hsh: 1: qwerty: not found
$

</code></pre>

### Allowed functions ###
* `access (man 2 access)`
* `chdir (man 2 chdir)</li>`
* `close (man 2 close)`
* `closedir (man 3 closedir)`
* `execve (man 2 execve)`
* `exit (man 3 exit)`
* `fork (man 2 fork)`
* `free (man 3 free)`
* `stat (__xstat) that(man 2 stat)`
* `lstat (__lxstat) (man 2 lstat)`
* `fstat (__fxstat) (man 2 fstat)`
* `getcwd (man 3 getcwd)`
* `getline (man 3 getline)`
* `kill (man 2 kill)`
* `malloc (man 3 malloc)`
* `open (man 2 open)`
* `opendir (man 3 opendir)`
* `perror (man 3 perror)`
* `read (man 2 read)`
* `readdir (man 3 readdir)`
* `signal (man 2 signal)`
* `strtok (man 3 strtok)`
* `wait (man 2 wait)`
* `waitpid (man 2 waitpid)`
* `wait3 (man 2 wait3)`
* `wait4 (man 2 wait4)`
* `write (man 2 write)`
* `_exit (man 2 _exit)`
* `isatty (man 3 isatty)`
* `fflush (man 3 fflush)`


### Installation ###
* Be in the desired directory that you want this function to be in.
* Go to https://github.com/tanyastropheus/simple_shell
* Clone the repository

![](http://imgur.com/I4YLqYM.gif)

* Clone the repository into your terminal

![](http://imgur.com/BD2F4jM.gif)

### Compilation ###
Your shell will be compiled this way:
`gcc -Wall -Werror -Wextra -pedantic *.c -o hsh`

### Requirements ###
	* Allowed editors: `vi`, `vim`, `emacs`
	* All your files should be compiled on Ubuntu 14.04 LTS
	* Your C programs and functions should be compiled with `gcc 4.8.4` using the flags `-Wall` `-Werror` `-Wextra` and `-pedantic`
	* All your files should end with a new line
	* A `README.md` file, at the root of the folder of the project is mandatory
	* Your code should use the `Betty` style. It will be checked using <a href="https://github.com/holbertonschool/Betty/blob/master/betty-style.pl">betty-style.pl</a> and <a href="https://github.com/holbertonschool/Betty/blob/master/betty-doc.pl">betty-doc.pl</a>
	* No more than 5 functions per file
	* All your header files should be include guarded
### Tasks ###
#### Mandatory 0 ####
0. **README, man, AUTHORS**
	* [ ] Write a `README`
	* [ ] Write a `man` for your shell
	* [ ] You should have an `AUTHORS` file at the root of your repository, listing all individuals having contributed content to the repository. Format, see <a href="https://github.com/docker/docker/blob/master/AUTHORS">Docker</a>
#### Mandatory 1 ####
1. **Betty would be proud**
	* [ ] Write a beautiful code that passes the Betty checks
#### Mandatory 2 ####
2. **Simple shell 0.1**
* Write a UNIX command line interpreter.
	* [ ] Usage: `simple_shell`
* Your Shell should:
	* [ ] Display a prompt and wait for the user to type a command. A command line always ends with a new line.
	* [ ] The prompt is displayed again each time a command has been executed.
	* [ ] The command lines are simple, no semi-columns, no pipes, no redirections or any other advanced features
	* [ ] The command lines are made only of one word. No arguments will be passed to programs.
	* [ ] If an executable cannot be found, print an error message and display the prompt again.
	* [ ] Handle errors.
	* [ ] You have to handle the "end of file" condition (`Ctrl+D`). Exit with code 0
* You don't have to:
	* Use the `PATH`
	* Implement built-ins
	* Handle the special characters: `"`, `'`, `` ` ``, `` \ ``, `*`, `&`, `#`
	* Be able to move the cursor
	* Handle commands with arguments
#### Mandatory 3 ####
3. **Simple shell 0.2**
* Simple shell 0.1 +
	* [ ] Handle command lines with arguments
#### Mandatory 4 ####
4. **Simple shell 0.3**
* Simple shell 0.2 +
	* [ ] Handle the `PATH`
#### Mandatory 5 ####
5. **Simple shell 0.4**
* Simple shell 0.3 +
	* [ ] Implement the `exit` built-in, that exits the shell
	* [ ] Usage: `exit`
	* [ ] You don't have to handle any argument to the built-in `exit`
#### Mandatory 6 ####
6. **Simple shell 1.0**
* Simple shell 0.4 +
	* [ ] Implement the `env` *built-in*, that prints the current environment
#### Mandatory 7 ####
7. **What happens when you type ls -l in the shell**
* Write a blog post describing step by step what happens when you type `ls -l` and hit Enter in a shell. Try to explain every step you know of, going in as much details as you can, give examples and draw diagrams when needed. You should merge your previous knowledge of the shell with the specifics of how it works under the hoods (including syscalls).
	* [ ] Have at least one picture, at the top of the blog post
	* [ ] Public your blog post on Medium or LinkedIn
	* [ ] Share your blog post at least on Twitter and LinkedIni
