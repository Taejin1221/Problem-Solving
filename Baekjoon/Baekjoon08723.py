a, b, c = map(int, input().split())
if (a == b and b == c):
    print(2)
else:
    nums = sorted([a, b, c])
    if (nums[2] ** 2 == nums[0] ** 2 + nums[1] ** 2):
        print(1)
    else:
        print(0)
