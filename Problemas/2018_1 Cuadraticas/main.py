import math
a = int(input())
b = int(input())
c = int(input())

d = b**2-4*a*c
r = []

try:
  r.append(((-b + math.sqrt(d))/2))
except:
  r.append('NA')

try:
  r.append(((-b - math.sqrt(d))/2))
except:
  r.append('NA')

r.sort()

if d > 0:
  print(r[0],'\n',r[1])
else:
  print(r[0])