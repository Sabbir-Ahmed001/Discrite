#include <stdio.h>

int main()
{
    FILE *input, *output;

    int A[100], B[100], C[100];
    int nA, nB, nC;

    int result[100];
    int nResult = 0;

    int i, j, found;

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

    /* Read Set C */
    fscanf(input, "%d", &nC);

    for(i = 0; i < nC; i++)
    {
        fscanf(input, "%d", &C[i]);
    }

    /* Add elements of A */
    for(i = 0; i < nA; i++)
    {
        result[nResult] = A[i];
        nResult++;
    }

    /* Add elements of B if they are not already present */
    for(i = 0; i < nB; i++)
    {
        found = 0;

        for(j = 0; j < nResult; j++)
        {
            if(B[i] == result[j])
            {
                found = 1;
                break;
            }
        }

        if(found == 0)
        {
            result[nResult] = B[i];
            nResult++;
        }
    }

    /* Add elements of C if they are not already present */
    for(i = 0; i < nC; i++)
    {
        found = 0;

        for(j = 0; j < nResult; j++)
        {
            if(C[i] == result[j])
            {
                found = 1;
                break;
            }
        }

        if(found == 0)
        {
            result[nResult] = C[i];
            nResult++;
        }
    }

    /* Write result to output file */
    fprintf(output, "A U B U C = {");

    for(i = 0; i < nResult; i++)
    {
        fprintf(output, "%d", result[i]);

        if(i < nResult - 1)
        {
            fprintf(output, ", ");
        }
    }

    fprintf(output, "}");

    /* Close files */
    fclose(input);
    fclose(output);

    printf("Union operation completed successfully.\n");

    return 0;
}
