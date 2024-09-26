#include <stdio.h>

int main(int argc,const char** argv)
{
    if (argc == 1)
    {
        printf("Argument [ 0] - [%s]\n", argv[0]);  // Print default input
        printf("No additional arguments provided (argc < 2)\n");  // 
        return -1;
    }

    for (int i = 0; i < argc; i++)
    {
        printf("Argument [%2d] - [%s]\n", i, argv[i]);  // Print input argument
    }

    return 0;
}
