#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int find_mini(unsigned int *data, unsigned char *used_index, unsigned int len)
{
    int mini_index = -1;
    int i = 0;
    for(i=0; i<len; i++)
    {
        if (used_index[i] == 0)
        {
            if (mini_index < 0)
                mini_index = i;

            if(data[i] < data[mini_index])
            {
                mini_index = i;
            }
        }
    }

    return mini_index;
}

///@brief 数组实现版
///@oaram 
///O(n^2)
void select_sort_with_array(unsigned int *data, unsigned int len)
{
    unsigned int *sorted_data = malloc(sizeof(unsigned int) * len); 
    unsigned char *selected_index  = calloc(sizeof(unsigned char), len);
    int i = 0;
    int index = 0;
    for(i=0; i<len; i++)
    {
        index = find_mini(data, selected_index, len);
        sorted_data[i] = data[index];
        selected_index[index] = 1;//标记为已经使用
    }

    memcpy(data, sorted_data, sizeof(unsigned int) * len);   
}


///@brief 双向链表实现版，要比数组版的时间复杂度低
void select_sort_with_arry()
{

}

int main()
{
    unsigned int data[10] = {1, 2, 20, 2, 7, 40, 23, 53, 22, 89}; 
    select_sort_with_array(data, 10);
    
    int i = 0;
    for(i=0; i<10; i++)
    {
        printf("%d\t", data[i]);
    }
    printf("\n");

    return 0;
}
