#include <stdio.h>

///@file This demo is demostrate how to split a rectangle into squares with max lenght


void get_max_square(unsigned int h, unsigned int w, unsigned int *square_hw)
{
    int left_h = 0;
    int left_w = 0;
    int square_number = 0;
    if(h < w)
    {
        square_number = w/h;
        left_h = h;
        left_w = w - h * square_number;
    }
    else
    {
        square_number = h/w;
        left_h = h - w * square_number;
        left_w = w;
    }

    if (left_h%left_w ==0 || left_w%left_h == 0)
    {
        if(left_h%left_w == 0)
            *square_hw = left_w;
        else
            *square_hw = left_h;
        return;
    }
    else
    {
        get_max_square(left_h, left_w, square_hw);
    }
}





void main()
{
    unsigned int square_hw = 0;
    get_max_square(140, 660, &square_hw);
    printf("square's lenght is %u\n", square_hw);
}
