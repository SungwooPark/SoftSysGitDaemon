#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

//Return 1 if string pre is a prefix of string str. 0 otherwise
int prefix(const char *pre, const char *str)
{
    return strncmp(pre, str, strlen(pre)) == 0;
}

int main(){
  FILE *fp;
  char output[1035];
  struct tm tm;
  time_t commit_time;
  time_t current_time;

  /* Open the command for reading. */
  fp = popen("git log", "r");
  if (fp == NULL) {
    printf("Failed to run command\n" );
    exit(1);
  }

  /* Read the output a line at a time - output it. */
  while (fgets(output, sizeof(output)-1, fp) != NULL) {
    // printf("%s", output);
    if (prefix("Date", output)){
      printf("%s", output);
      if (strptime(output, "Date:   %a %b %d %H:%M:%S %Y", &tm) != NULL){
        commit_time = mktime(&tm);
        time(&current_time);
        printf("commit diff time: %f\n", difftime(current_time, commit_time));
      } else {
        printf("%s", "something went wrong during time extraction");
      }
    }
  }

  /* close */
  pclose(fp);

  return 0;
}
