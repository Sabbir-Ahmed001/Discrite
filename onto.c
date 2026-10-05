#include <stdio.h>

int main()
{
    FILE *fp;

    int n, m, k;
    int domain[100];
    char codomain[100];
    char mapping[100];

    int i, j;
    int oneToOne = 1;
    int onto = 1;
    int found;

    fp = fopen("input.txt", "r");

    if (fp == NULL)
    {
        printf("File could not be opened.\n");
        return 1;
    }

    /* Read domain */
    fscanf(fp, "%d", &n);

    for (i = 0; i < n; i++)
    {
        fscanf(fp, "%d", &domain[i]);
    }

    /* Read codomain */
    fscanf(fp, "%d", &m);

    for (i = 0; i < m; i++)
    {
        fscanf(fp, " %c", &codomain[i]);
    }

    /* Read mapping */
    fscanf(fp, "%d", &k);

    for (i = 0; i < k; i++)
    {
        fscanf(fp, " %c", &mapping[i]);
    }

    /* Check One-to-One */

    for (i = 0; i < k; i++)
    {
        for (j = i + 1; j < k; j++)
        {
            if (mapping[i] == mapping[j])
            {
                oneToOne = 0;
                break;
            }
        }

        if (oneToOne == 0)
        {
            break;
        }
    }

    /* Check Onto */

    for (i = 0; i < m; i++)
    {
        found = 0;

        for (j = 0; j < k; j++)
        {
            if (codomain[i] == mapping[j])
            {
                found = 1;
                break;
            }
        }

        if (found == 0)
        {
            onto = 0;
            break;
        }
    }

    /* Display result */

    if (oneToOne == 1 && onto == 1)
    {
        printf("Function is Bijective (One-to-One and Onto)\n");
    }
    else if (oneToOne == 1)
    {
        printf("Function is One-to-One\n");
    }
    else if (onto == 1)
    {
        printf("Function is Onto\n");
    }
    else
    {
        printf("Function is Neither One-to-One nor Onto\n");
    }

    fclose(fp);

    return 0;
}
