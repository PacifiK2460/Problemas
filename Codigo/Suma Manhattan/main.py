n = int(input())
data = []
total = 0
for _ in range(n):
  __ = input().split()
  data.append([int(i) for i in __])
del __
del _ 

for i in range(n-1):
  for j in range(i,n):
    if i != j:
      total = total + abs(data[i][0] - data[j][0]) + abs(data[i][1] - data[j][1])

del i,j,data
print(total)