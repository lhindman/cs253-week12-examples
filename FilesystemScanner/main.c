#define _DEFAULT_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <errno.h>

#define UNUSED(x) (void)x

static int one (const struct dirent *current) {
    UNUSED(current);
    return 1;
}


int main (int argc, char * argv[]) {
    struct dirent **eps;
    int n;

    errno = 0;

    /* check if user specified a directory on the command line */
    if (argc == 2) {
        n = scandir (argv[1], &eps, one, alphasort);
    } else {
        /* start in the current directory */
        n = scandir ("./", &eps, one, alphasort);
    }

    /* validate directory was opened successfully */
    if (n < 0) {
        perror("scandir: ");
        exit(1);
    }

    int cnt;
    for (cnt = 0; cnt < n; ++cnt) {
        fprintf(stderr,"%s\n", eps[cnt]->d_name);
    }

    free (eps);

    return 0;
}
