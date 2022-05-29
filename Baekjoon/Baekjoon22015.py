nums = list(map(int, input().split()))
print(sum([(max(nums) - n) for n in nums]))
