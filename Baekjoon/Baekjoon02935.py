a = input()
o = input()
b = input()

if (o == '+'):
    print(int(a) + int(b))
else:
    print('1' + '0' * (len(a) - 1 + len(b) - 1))
