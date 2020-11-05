
#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

int main (int argc, char * argv[]) {
  DIR *dp;
  struct dirent *ep;

  errno = 0;

  /* check if user specified a directory on the command line */
  if (argc == 2) {
    dp = opendir(argv[1]);
  } else {
    /* start in the current directory */
    dp = opendir ("./");
  }

  /* validate directory was opened successfully */
  if (dp == NULL) {
    perror("opendir: ");
    exit(1);
  }

  /* Read each directory entry struct from the directory stream
   *   and print it to stdout. */
  while ( (ep = readdir (dp)) != NULL ) {
    fprintf(stdout,"%s\n", ep->d_name);
  }
    
  closedir (dp);


  return 0;
}
