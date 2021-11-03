inicio = input().split(':')
fin = input().split(':')

inicio = int(inicio[0])*60*60 + int(inicio[1])*60 + int(inicio[2])
fin = int(fin[0])*60*60 + int(fin[1])*60 + int(fin[2])

if fin >= inicio:
  print(fin-inicio)
else:
  print(86400-inicio+fin)