nums = sorted(list(map(int, input().split())))
a = input()
for b in a:
    if b == 'A':
        print(nums[0], end = ' ')
    elif b == 'B':
        print(nums[1], end = ' ')
    else:
        print(nums[2], end = ' ')
