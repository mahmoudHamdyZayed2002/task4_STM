# task4_STM
#  my own femto shell
### system calls i used
***

wait(),fork(),execvp,getline,

***
### built in function heleped me to generate my code 
***

strlen : to get the length of the string
strcmp : for comparing two strings
strcpy : to copy string to a nothe (used in test1.c)
strcat : to connect two strings (used in test1.c)

***
### my code flow
***
first i take string from usser contain command and arguments
then i seperate command and arguments by using parsing with strtok_r()function,
i used call system FORK() to generate a new process and then use EXECVP call system to replace the generation process
(child) with the command which being passed by the userand main process (parent) will be holded till child process being ended and return status to parent
using call system wait.

***
### task4_dynamic.c 
***
is the last version of my code as i handelled it to be dynamic allocation not static
***
