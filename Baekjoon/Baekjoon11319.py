vowels = "AEIOUaeiou"
for _ in range(int(input())):
    sentence = input()
    con, vow = 0, 0
    for s in sentence:
        if s in vowels:
            vow += 1
        elif s == ' ':
            continue
        else:
            con += 1
    print(con, vow)
