"""
A simple background 'deamon' program that alerts the user if long time has
passed since the last commit.
"""

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

//Return 1 if string pre is a prefix of string str. 0 otherwise
int prefix(const char *pre, const char *str)
{
    return strncmp(pre, str, strlen(pre)) == 0;
}

//Return time in second since last commit
double time_since_last_commit(){
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

  /* Read the output a line at a time */
  while (fgets(output, sizeof(output)-1, fp) != NULL) {
    // printf("%s", output);
    if (prefix("Date", output)){
      if (strptime(output, "Date:   %a %b %d %H:%M:%S %Y", &tm) != NULL){
        commit_time = mktime(&tm);
        time(&current_time);
        return difftime(current_time, commit_time);
      } else {
        printf("%s", "something went wrong during time extraction");
        return -1;
      }
    }
  }

  /* close */
  pclose(fp);
}

int main(){
  while(1){
    double last_commit_time_diff = time_since_last_commit();
    printf("seconds since last commit: %f\n", last_commit_time_diff);
    if (last_commit_time_diff > 600.0){
      printf("You have not commited your work in while. Commit your work!\n");
    }
    sleep(60);
  }
  return 0;
}
