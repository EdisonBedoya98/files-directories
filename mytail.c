#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>

#include <unistd.h>

int main(int argc, char *argv[])
{
    int n = atoi(argv[1]);

    printf("number: %d\n", n);
    char cwd[256];
    if (getcwd(cwd, sizeof(cwd)) != NULL)
    {
        const size_t len1 = strlen(cwd);
        const size_t len2 = strlen(argv[2]);
        char *result = malloc(len1 + len2 + 1);

        memcpy(result, cwd, len1);
        memcpy(result + len1, argv[2], len2 + 1);

        printf("Current worjing directory is: %s\n", result);
        FILE *fptr;
        fopen(result, "r");

        fclose(fptr);

        return 0;
    }
}