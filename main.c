#include <stdio.h>

int main(int ac, char **av, char **ep)
{
    int i;

    if (ac == 1)
    {
        i = 0;
        while (ep[i])
        {
            printf("%s\n", ep[i]);
            i++;
        }
    }
    return (0);
}