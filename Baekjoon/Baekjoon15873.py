nums = input()
if len(nums) == 4:
    print(20)
elif len(nums) == 3:
    if nums[1] == '0':
        print(10 + int(nums[2]))
    else:
        print(int(nums[0]) + 10)
else:
    print(int(nums[0]) + int(nums[1]))
