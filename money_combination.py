'''
1 2 5 10---> 10
'''

total_select=[1, 2, 5, 10]

def combinate(needed_money, combination):
    if needed_money == 0:
        print combination 
        return
    elif needed_money < 0:
        return
    else:
        for i in total_select:
            new_combination=combination[:]
            new_combination.append(i)
            combinate(needed_money - i, new_combination) 

if  __name__ == '__main__':
    combinate(10, [])  
