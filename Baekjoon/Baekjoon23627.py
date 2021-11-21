# Baekjoon23627.py
# https://www.acmicpc.net/problem/23627
string = input()
if len(string) < len("driip") or string[-5:] != "driip":
    print("not cute")
else:
    print("cute")
