x = int(input())
k = x

for y in range(x+1):
  if(y!=0):
    print("+",end='')

  if(x>=1):
    print('x',end='')
    if(x>=2):
      print('^'+x,end='')
  
  if(y>=1):
    print('y',end='')
    if(y>=2):
      print('^'+y,end='')