#include <stdio.h>

int main()
{
    FILE *input, *output;

    int A[100], B[100];
    int nA, nB;

    int i, j;

    /* Open files */
    input = fopen("input.txt", "r");
    output = fopen("output.txt", "w");

    /* Read Set A */
    fscanf(input, "%d", &nA);

    for(i = 0; i < nA; i++)
    {
        fscanf(input, "%d", &A[i]);
    }

    /* Read Set B */
    fscanf(input, "%d", &nB);

    for(i = 0; i < nB; i++)
    {
        fscanf(input, "%d", &B[i]);
    }

    /* Write intersection */
    fprintf(output, "A intersection B = {");

    for(i = 0; i < nA; i++)
    {
        for(j = 0; j < nB; j++)
        {
            if(A[i] == B[j])
            {
                fprintf(output, "%d ", A[i]);
            }
        }
    }

    fprintf(output, "}");

    /* Close files */
    fclose(input);
    fclose(output);

    printf("Intersection operation completed successfully.\n");

    return 0;
}
