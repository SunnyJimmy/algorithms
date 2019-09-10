#! /usr/bin/python
'''
merge two list into one
'''
def merge(left, right):
    left_len=len(left)
    right_len=len(right)
    sorted_list=[]
    i = 0
    j = 0
    while i<left_len and j<right_len:
        if left[i] <= right[j]:
            sorted_list.append(left[i])
            i=i+1
        else:
            sorted_list.append(right[j])
            j=j+1

    if i == left_len:
        for k in range(j, right_len):
            sorted_list.append(right[k])
    else:
        for k in range(i, left_len):
            sorted_list.append(left[k])

    return sorted_list

'''
this is a groups style docs.
  
Parameters:
    list needed to sort 
Returns:
    sorted list
  
Raises:
  KeyError - raises an exception
'''

def mergy_sort(need_sorted_list):
#    print need_sorted_list
    list_len = len(need_sorted_list)
    if list_len == 1 or list_len == 0:
        return need_sorted_list

    left=need_sorted_list[0:len(need_sorted_list)/2]
    right=need_sorted_list[len(need_sorted_list)/2:]
    left=mergy_sort(left)
    right=mergy_sort(right)

    return merge(left, right)



unsorted_list = [1, 5, 2, 100, 45, 23, 23, 67, 90, 123, 53]

if  __name__ == '__main__':
    sorted=mergy_sort(unsorted_list)
    print sorted
