#include <stdio.h>

int main()
{
    FILE *input, *output;

    int A[100];
    int n;

    // input.txt open
    input = fopen("input.txt", "r");

    // output.txt open
    output = fopen("output.txt", "w");

    // File থেকে n এবং elements নেওয়া
    fscanf(input, "%d", &n);

    for (int i = 0; i < n; i++)
    {
        fscanf(input, "%d", &A[i]);
    }

    // মোট subset = 2^n
    int total = 1;

    for (int i = 0; i < n; i++)
    {
        total = total * 2;
    }

    fprintf(output, "Subsets of A = ");

    // সব subset বের করা
    for (int i = 0; i < total; i++)
    {
        fprintf(output, "{");

        for (int j = 0; j < n; j++)
        {
            if (i & (1 << j))
            {
                fprintf(output, "%d", A[j]);
            }
        }

        fprintf(output, "}");

        if (i < total - 1)
        {
            fprintf(output, ", ");
        }
    }

    fprintf(output, "\nP(A) = %d\n", total);

    fclose(input);
    fclose(output);

    return 0;
}
