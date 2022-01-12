 = int(input())
e2 = input()

num_e = e2.count('e')
num_2 = e2.count('2')
if num_e > num_2:
    print('e')
elif num_e < num_2:
    print('2')
else:
    print('yee')
