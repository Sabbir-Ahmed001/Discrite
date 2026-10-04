#include <stdio.h>

int main()
{
    FILE *input, *output;

    int A[100], B[100];
    int n, m;

    // input.txt open
    input = fopen("input.txt", "r");

    // output.txt open
    output = fopen("output.txt", "w");

    // A এর size নেওয়া
    fscanf(input, "%d", &n);

    // A এর elements নেওয়া
    for (int i = 0; i < n; i++)
    {
        fscanf(input, "%d", &A[i]);
    }

    // B এর size নেওয়া
    fscanf(input, "%d", &m);

    // B এর elements নেওয়া
    for (int i = 0; i < m; i++)
    {
        fscanf(input, "%d", &B[i]);
    }

    fprintf(output, "A x B = {");

    // Cartesian Product
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            fprintf(output, "(%d, %d)", A[i], B[j]);

            if (i != n - 1 || j != m - 1)
            {
                fprintf(output, ", ");
            }
        }
    }

    fprintf(output, "}\n");

    fclose(input);
    fclose(output);

    return 0;
}
