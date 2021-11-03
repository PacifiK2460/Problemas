import sys
for line in sys.stdin:
  line = line.split()
  line = [int(x) for x in line]
  cantidad = len(line)
  suma = sum(line)
  print(cantidad, suma)