import math
n = int(input())
s = input()
cartas = [0,0]

for c in s:
  if c == 'B':
    cartas[0] = cartas[0] + 1
  else:
    cartas[1] = cartas[1] + 1

cartas.sort()
print(cartas[1] - math.ceil(n/2))