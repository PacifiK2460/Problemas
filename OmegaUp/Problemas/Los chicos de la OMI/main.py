n = int(input())
m = {}
for _ in range(n):
    name = input()
    cal = int(input())

    m[name] = cal

m = sorted(m,key=m.get)
print(m[-1],m[0])