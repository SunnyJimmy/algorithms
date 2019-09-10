'''
try passwords from conbination of 'a ... z'
repeatable arrangement
'''
import copy

password='adec'
words=['a', 'b', 'c', 'd', 'e']


def generate_passwd(n, result=''):
    if n == 0:
        if result == password:
            print 'correct password ' + result
#        else:
#            print 'wrong password ' + result
    else:
        for i in words:
            new_result = copy.copy(result)
            new_result += i
            generate_passwd(n-1, new_result)

if __name__ == '__main__':
    generate_passwd(4)
