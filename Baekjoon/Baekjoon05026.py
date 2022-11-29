# BOJ_05026.py
for _ in range(int(input())):
	prob = input()
	skip = True
	for i in prob:
		if (i == '+'):
			skip = False
			break

	if not skip:
		a, b = map(int, prob.split('+'))
		print(a + b)
	else:
		print('skipped')