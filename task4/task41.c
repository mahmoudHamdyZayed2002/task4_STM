#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

char *str_in;
size_t n;
char *const_str="/usr/bin/";

int main (void)
{
  printf ("my pid =%d , my parent pid =%d \n", getpid (), getppid ());
  getchar ();

  while (1)
    {
    
      //free(&n);
      printf (" femto >>>>>>>> ");
      getline (&str_in, &n, stdin);
      int len = strlen (str_in);
      str_in[len - 1] = 0;
      if (strlen (str_in) == 0)
	{
	  continue;
	}
      else
	{
	}
      char *argu = str_in;
      char *command = strtok_r (argu, " ", &argu);
      if ((strlen (argu)) == 0)
	{
	 argu =NULL;
	}
      printf ("command =%s , arg = %s \n", command, argu);
      if ((!(strcmp ("exit", command))))
	{
	  printf ("you are wilcome\n");

	  break;
	}
        else if(!(strcmp(command ,"cd"))){
		      chdir (argu);
      
      }
      else
	{
      pid_t ret_pid = fork ();
      if (ret_pid < 0)
	{
	  printf ("error generation \n");
	}
      else if (ret_pid > 0)
	{

	  int status;
	  wait (&status);
	  printf ("the last command status =%d , exit status =%d\n", status,
		  WIFEXITED (status));
	}
      else if (ret_pid == 0)
	{

	
	  char *n_argv[] = { command, argu, NULL };
	  char *n_nvp[] = { NULL };

	  execvp (command, n_argv);
	  printf ("nter correct command\n");
	  return 99;
	}
	}
    }

  return 0;
}


