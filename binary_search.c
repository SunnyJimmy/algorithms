#include <stdio.h>

///@brief binary search 
///@param target 
///@param data  
///@param len
///@param return -1 not find
///              >=0 corresponded index 
///@detail 时间复杂度 O(log n),data是已经排过序的数据，并且是从小到大排列的
///算法复杂度表示的是最糟糕的情况下的运行速度
int binary_search(unsigned int target, unsigned int *data, unsigned int len)
{
    unsigned int low = 0;
    unsigned int high = len - 1;
    unsigned int mid = 0; 
    while(low <= high)
    {
        mid = (low + high)/2;
        if(data[mid] == target)
            return mid;
        else if(data[mid] < target)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    return -1;
};



int main()
{
    unsigned int data[10] = {1, 4, 7, 8, 9, 10, 15, 20, 26, 78};

    int index = binary_search(11, data, 10);
    if (index < 0)
    {
        printf("do not find\n");
    }
    else
    {
        printf("find at index %u \n", index);
    }

    return 0;
}
