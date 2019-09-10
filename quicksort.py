def quicksort(array):
    if len(array)<2:
        return array
    else:
        pivot = array[0]
        less = [ i for i in array[1:] if i<= pivot]
        greater = [i for i in array[1:] if i>pivot]
        less_ret = quicksort(less)
        greater_ret = quicksort(greater)
        '''
        print less_ret
        print [pivot]
        print greater_ret
        print '----------'
        '''
        return less_ret +[pivot]+greater_ret

if __name__ == '__main__':
    print quicksort([10, 2, 5, 8, 3, 9])
    
