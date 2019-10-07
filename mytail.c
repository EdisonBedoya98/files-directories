#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>

#include <unistd.h>

int main(int argc, char *argv[])
{
    int n = atoi(argv[1]);
    printf("number: %d\n", n);

    char ch, file_name[15];
    FILE *fp;

    fp = fopen(argv[2], "r"); // read mode

    if (fp == NULL)
    {
        perror("Error while opening the file.\n");
        exit(EXIT_FAILURE);
    }

    int contador = 0;
    int contador2 = 0;

    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    // while para contar el número de lineas que tiene el archivo
    while ((read = getline(&line, &len, fp)) != -1)
    {
        contador++;
    }

    // le restamos al contador el número de lineas al final que se quieren imprimir para saber donde iniciar
    int inicio = contador + n;

    // reiniciamos el apuntador que abre el archivo
    fp = fopen(argv[2], "r");

    //while para imprimir las lineas solicitadas
    while ((read = getline(&line, &len, fp)) != -1)
    {
        contador2++;
        if (contador2 > inicio)
        {
            printf("%s", line);
        }
    }

    //cerramos el archivo
    fclose(fp);
    return 0;
}