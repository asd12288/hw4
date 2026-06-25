#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* func(char* str, int step, int times)
{
    int size1, i, j, t;
    char* res;

    size1 = strlen(str);

    // Reminder: one char = one byte
    res = (char*)malloc(1);

    if (res == NULL)
        return NULL;

    for (i = 0, j = 0, t = 0; t < times; j += step, i++)
    {
        if (j >= size1)
        {
            j = j - size1;
            t = t + 1;
        }

        if (t < times)
        {
            // Reminder: one char = one byte
            res = (char*)realloc(res, i + 2);
            res[i] = str[j];
        }
    }

    res[i - 1] = '\0';

    return res;
}

int main()
{
    char str[] = "1234567890ABCDEFG";
    char* res;

    res = func(str, 1, 2);
    res[strlen(res)-1] = 'p';
    printf("%s\n", res);
    free(res);

    res = func(str, 17, 5);
    printf("%s\n", res);
    free(res);

    res = func(str, 2, 2);
    printf("%s\n", res);
    free(res);

    return 0;
}