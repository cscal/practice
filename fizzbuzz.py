#! /usr/bin/python

# This is the python version of the classic fizzbuzz problem

# This was the first version, correct although it does repeat
#for i in range(1, 101):
#    if i%15 == 0:
#        print('FizzBuzz')
#    elif i%3 == 0:
#        print('Fizz')
#    elif i%5 == 0:
#        print('Buzz')
#    else:
#        print(i)

for i in range(1, 101):
    if i%3 == 0:
        print('Fizz', end='')
    if i%5 == 0:
        print('Buzz', end='')
    if i%3 != 0 and i%5 != 0:
        print(i, end='')
    print('\n', end='')
