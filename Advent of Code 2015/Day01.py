import os
r = str(input())
if len(r) == 1:
    arch = open("input.txt","r")
    s = str(arch.readlines())
    arch.close()
else:
    s = r
c = 0
i = 0
for char in s:
    if char == '(':
        c += 1
        i += 1
    elif char == ')':
        c -= 1
        i += 1

    print(i," ",c)
    if c == -1:
        break

print(len(s))
