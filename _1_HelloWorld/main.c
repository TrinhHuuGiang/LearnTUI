#include <stdio.h>

int main(int argc, char** argv)
{
    if (argc == 1)
    {
        printf("Argument [ 0] - [%s]\n", argv[0]);  // Thêm dòng mới
        printf("No additional arguments provided (argc < 2)\n");  // Thêm dòng thông báo rõ ràng hơn
        return -1;
    }

    for (int i = 0; i < argc; i++)
    {
        printf("Argument [%2d] - [%s]\n", i, argv[i]);  // Thêm dòng mới sau khi in
    }

    return 0;
}
