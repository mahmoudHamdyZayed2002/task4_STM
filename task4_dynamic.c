#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

char **parsing_string(char * user_string , int* arg_number){
	int str_len = strlen(user_string);
	char **array_parsed=NULL;
	int arr_index =0;
	*arg_number=1;
	while (arr_index < str_len) {
	if (user_string[arr_index] == ' ') {
	    (*arg_number)++;
	}
	arr_index++;
    }
	char *token = strtok(user_string," ");
	array_parsed = (char**)malloc(((*arg_number)+1) * sizeof(char*));
	int index =0;
for (arr_index = 0; arr_index < *arg_number; arr_index++) {
	int token_size = strlen(token);
	array_parsed[arr_index] = (char *) malloc(token_size * sizeof(char));
	strcpy(array_parsed[arr_index], token);
	token = strtok(NULL, " ");	//make token points to the next word
    }

    
	return array_parsed;
	
}


char *str_in;
size_t n;

int main (void)
{
  printf ("my pid =%d , my parent pid =%d \n", getpid (), getppid ());
  getchar ();

  while (1)
    {
    
      char **arguments=NULL;
      int arg_num=0;
      char path [30]={0};
      char * path2=getcwd(path,30);
      printf (" %s >>>>>>>> ",path);
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
        arguments = parsing_string(str_in,&arg_num);
	for(int i =0 ; i<arg_num;i++){
                printf("1111111111111111aguments[%d] = %s /n ",i,arguments[i]);

        }
	printf("number of parsing strings = %d\n",arg_num);
	
       if ((!(strcmp ("exit", arguments[0]))))
	{
	  printf ("you are wilcome\n");

	  break;
	}
        else if(!(strcmp(arguments[0] ,"cd"))){
		      chdir (arguments[1]);
      
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
	
	for(int i =0 ; i<arg_num;i++){
		printf("22222222arguments[%d] = %s \n ",i,arguments[i]);

	}	
	  execvp (arguments[0], arguments);
	  printf ("nter correct command\n");
	  return 99;
	}
	}
    }

  return 0;
}


