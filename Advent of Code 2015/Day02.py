import math
r = str(input())
if len(r) == 1:
    arch = open("input.txt","r")
    s = arch.readlines()
    arch.close()
else:
    s = r

t = 0
r = 0

for _ in s:
    li = _.split('x')
    m = [ float(i) for i in li ]
    l = m[0]
    w = m[1]
    h = m[2]
    e = min(l*w,w*h,h*l)
    b = min(2*l + 2*w,2*l + 2*h,2*w + 2*h)
    r += (w*h*l) + b
    t+= (2*l*w) + (2*w*h) + (2*h*l) + e 

print(t)
print(r)
