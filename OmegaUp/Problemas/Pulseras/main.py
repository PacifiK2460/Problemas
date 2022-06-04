import math
x = int(input())
val = x - math.floor(1.5+0.5*x)

n = x+1

if(x%2):
    n=n+(x*val)
else:
    n=n+(x*(val-1)+2)

print(n%1000000007)