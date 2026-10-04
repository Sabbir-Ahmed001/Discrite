#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};


/* Create a new node */
struct Node* createNode(int value)
{
    struct Node *newNode;

    newNode = (struct Node*)malloc(sizeof(struct Node));

    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}


/* Create BST from sorted array */
struct Node* createBST(int arr[], int start, int end)
{
    int mid;
    struct Node *root;

    if (start > end)
    {
        return NULL;
    }

    /* Find middle element */
    mid = (start + end) / 2;

    /* Middle element becomes root */
    root = createNode(arr[mid]);

    /* Create left subtree */
    root->left = createBST(arr, start, mid - 1);

    /* Create right subtree */
    root->right = createBST(arr, mid + 1, end);

    return root;
}


/* Print the tree */
void printTree(FILE *outputFile, struct Node *root, int space)
{
    int i;

    if (root == NULL)
    {
        return;
    }

    space = space + 5;

    /* Print right subtree first */
    printTree(outputFile, root->right, space);

    fprintf(outputFile, "\n");

    for (i = 5; i < space; i++)
    {
        fprintf(outputFile, " ");
    }

    fprintf(outputFile, "%d\n", root->data);

    /* Print left subtree */
    printTree(outputFile, root->left, space);
}


int main()
{
    FILE *inputFile;
    FILE *outputFile;

    int arr[100];
    int n = 0;

    inputFile = fopen("input.txt", "r");
    outputFile = fopen("output.txt", "w");

    if (inputFile == NULL || outputFile == NULL)
    {
        printf("File cannot be opened.\n");
        return 1;
    }

    /* Read numbers from input.txt */
    while (fscanf(inputFile, "%d", &arr[n]) == 1)
    {
        n++;

        /* Read comma if present */
        fscanf(inputFile, ",");
    }

    /* Create BST */
    struct Node *root;

    root = createBST(arr, 0, n - 1);

    /* Write BST to output.txt */
    fprintf(outputFile, "Binary Search Tree:\n");

    printTree(outputFile, root, 0);

    fclose(inputFile);
    fclose(outputFile);

    return 0;
}
