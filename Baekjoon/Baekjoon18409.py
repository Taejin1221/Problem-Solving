n = int(input())
vowels = 'aeiou'
a = input()

ans = 0
for i in a:
    if i in vowels:
        ans += 1
        
print(ans)
