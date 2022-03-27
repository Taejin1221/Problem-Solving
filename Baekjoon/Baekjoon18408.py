nums = list(map(int, input().split()))
num1, num2 = nums.count(1), nums.count(2)
print(1 if num1 > num2 else 2)
