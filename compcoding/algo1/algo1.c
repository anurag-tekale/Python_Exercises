// Day of the Programmer - hackerrank

#include <assert.h>
#include <ctype.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *readline();
char *ltrim(char *);
char *rtrim(char *);
void tostring(char str[], int num)
{
    int i, rem, len = 0, n;

    n = num;
    while (n != 0)
    {
        len++;
        n /= 10;
    }
    for (i = 0; i < len; i++)
    {
        rem = num % 10;
        num = num / 10;
        str[len - (i + 1)] = rem + '0';
    }
    str[len] = '\0';
}

// Complete the dayOfProgrammer function below.

/*
 * To return the string from the function, you should either do static allocation or dynamic allocation
 *
 * For example,
 * char* return_string_using_static_allocation() {
 *     static char s[] = "static allocation of string";
 *
 *     return s;
 * }
 *
 * char* return_string_using_dynamic_allocation() {
 *     char* s = malloc(100 * sizeof(char));
 *
 *     s = "dynamic allocation of string";
 *
 *     return s;
 * }
 *
 */
char *dayOfProgrammer(int year)
{

    char *s = malloc(100 * sizeof(char));
    char str[5];
    tostring(str, year);
    if (year <= 1917 && year >= 1700)
    {
        if (year % 4 == 0)
        {
            s = "12.09.";
            //strcat(s,str);
        }
        else
        {
            s = "13.09.";
            //strcat(s,str);
        }
    }

    else if (year == 1918)
    {

        s = "26.09.";
        //strcat(s,str);
        //
    }
    if (year > 1918 && year <= 2700)
    {
        if (year%400==0 ||(year % 4 == 0 && year % 100 != 0))
        {
            s = "12.09.";
            // strcat(s,str);
        }
        else
        {
            s = "13.09.";
            //strcat(s,str);
        }
    }

    return s;
}

int main()
{
    FILE *fptr = fopen(getenv("OUTPUT_PATH"), "w");

    char *year_endptr;
    char *year_str = ltrim(rtrim(readline()));
    int year = strtol(year_str, &year_endptr, 10);

    if (year_endptr == year_str || *year_endptr != '\0')
    {
        exit(EXIT_FAILURE);
    }

    char *result = dayOfProgrammer(year);

    fprintf(fptr, "%s", result);
    fprintf(fptr, "%d\n", year);

    fclose(fptr);

    return 0;
}

char *readline()
{
    size_t alloc_length = 1024;
    size_t data_length = 0;
    char *data = malloc(alloc_length);

    while (true)
    {
        char *cursor = data + data_length;
        char *line = fgets(cursor, alloc_length - data_length, stdin);

        if (!line)
        {
            break;
        }

        data_length += strlen(cursor);

        if (data_length < alloc_length - 1 || data[data_length - 1] == '\n')
        {
            break;
        }

        alloc_length <<= 1;

        data = realloc(data, alloc_length);

        if (!data)
        {
            data = '\0';

            break;
        }
    }

    if (data[data_length - 1] == '\n')
    {
        data[data_length - 1] = '\0';

        data = realloc(data, data_length);

        if (!data)
        {
            data = '\0';
        }
    }
    else
    {
        data = realloc(data, data_length + 1);

        if (!data)
        {
            data = '\0';
        }
        else
        {
            data[data_length] = '\0';
        }
    }

    return data;
}

char *ltrim(char *str)
{
    if (!str)
    {
        return '\0';
    }

    if (!*str)
    {
        return str;
    }

    while (*str != '\0' && isspace(*str))
    {
        str++;
    }

    return str;
}

char *rtrim(char *str)
{
    if (!str)
    {
        return '\0';
    }

    if (!*str)
    {
        return str;
    }

    char *end = str + strlen(str) - 1;

    while (end >= str && isspace(*end))
    {
        end--;
    }

    *(end + 1) = '\0';

    return str;
}
