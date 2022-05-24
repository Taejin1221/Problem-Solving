w, h = map(int, input().split())
print(f'{(w + h) - (w * w + h * h) ** .5 : .6f}')
