import sys
for lineas in sys.stdin:  
  _ = input().split()
  arreglo = [int(x) for x in _]
  distancias = {}

  for first in arreglo:
    for second in arreglo:
      dif = abs(first - second)
      if dif in distancias:
        distancias[dif] = distancias[dif] + 1
      else:
        distancias[dif] = 1
  distancias.pop(0)
  print(max(distancias,key=distancias.get))