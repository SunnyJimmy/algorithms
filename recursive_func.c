#include <stdio.h>


void recursive_func(int i)
{
    if (i == 0)
        return;
    else
    {
        recursive_func(i - 1);//递归条件
        printf("%d\n", i);
    }
}




int main()
{
    recursive_func(10);

    return 0;
}
