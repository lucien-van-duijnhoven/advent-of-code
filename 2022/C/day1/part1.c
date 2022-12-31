#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

size_t getline(char **lineptr, size_t *n, FILE *stream)
{
    char *bufptr = NULL;
    char *p = bufptr;
    size_t size;
    int c;

    if (lineptr == NULL)
    {
        return -1;
    }
    if (stream == NULL)
    {
        return -1;
    }
    if (n == NULL)
    {
        return -1;
    }
    bufptr = *lineptr;
    size = *n;

    c = fgetc(stream);
    if (c == EOF)
    {
        return -1;
    }
    if (bufptr == NULL)
    {
        bufptr = malloc(128);
        if (bufptr == NULL)
        {
            return -1;
        }
        size = 128;
    }
    p = bufptr;
    while (c != EOF)
    {
        if ((p - bufptr) > (size - 1))
        {
            size = size + 128;
            bufptr = realloc(bufptr, size);
            if (bufptr == NULL)
            {
                return -1;
            }
        }
        *p++ = c;
        if (c == '\n')
        {
            break;
        }
        c = fgetc(stream);
    }

    *p++ = '\0';
    *lineptr = bufptr;
    *n = size;

    return p - bufptr - 1;
}

enum SEARCH_MODES
{
    ADDING,
    FINDING
};

int main(int argc, char **args)
{
    char *line = NULL;  /*malloc(10);*/
    size_t bufSize = 0; /*10;*/
    size_t read;
    FILE *f;
    int search = FINDING;

    f = fopen("../../inputs/day1/full.txt", "r");
    if (f == NULL)
    {
        exit(EXIT_FAILURE);
    }
    int highest = 0;
    int total = 0;
    while ((read = getline(&line, &bufSize, f)) != -1)
    {
        printf("%i characters read. \n", read);
        if (isdigit(line[0]))
        {
            total += atoi(line);
            printf("After atoi: %i\n", atoi(line));
        }
        else
        {
            total = 0;
        }

        if (total > highest)
        {
            highest = total;
        }
        printf("Line: %s\n", line);
        printf("Total: %i\n", total);
    }
    printf("Highest: %i\n", highest);
    fclose(f);
    if (line)
    {
        free(line);
    }
    return EXIT_SUCCESS;
}
