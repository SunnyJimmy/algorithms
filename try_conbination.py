'''
C 5 4
'''
import copy

words=['1', '2', '3', '4', '5']

def generate_conbination(condidate, result, n):
    if len(result) == n:
        print result
    else:
        for i in range(len(condidate)):
            new_result = copy.copy(result)
            new_result += condidate[i]
            generate_conbination(condidate[i+1:], new_result, 4)

if __name__ == '__main__':
    generate_conbination(words, [], 4)
