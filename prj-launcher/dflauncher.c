#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <unistd.h>

int main(int argc, char **argv) {
  char absExePath[PATH_MAX];
  char *p;

  /* i) Get the absolute path to this executable directory */
  if (!(p = strrchr(argv[0], '/'))) {
    getcwd(absExePath, sizeof(absExePath));
  } else {
    *p = '\0';

    char currentWorkingDirectory[PATH_MAX];
    getcwd(currentWorkingDirectory, sizeof(currentWorkingDirectory));
    chdir(argv[0]);
    getcwd(absExePath, sizeof(absExePath));
    chdir(currentWorkingDirectory);
  }

  /* ii) Info only when not in production */
  if (argc > 1) {
    printf("DEBUG: Absolute path to executable is: %s\n", absExePath);
  }

  /* iii) Generate the absolute path to the script */
  uint64_t length = strlen(absExePath);
  char absScriptPath[length+4];
  strncpy(absScriptPath, absExePath, length);
  absScriptPath[length] = '/';
  absScriptPath[length+1] = 'd';
  absScriptPath[length+2] = 'f';
  absScriptPath[length+3] = '\0';

  /* iv) Info only when not in production, otherwise run script */
  if (argc > 1) {
    printf("DEBUG: Absolute path to script is: %s\n", absScriptPath);
  } else {
    system(absScriptPath);
  }

  return 0;
}
