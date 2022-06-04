txt = input()
up = False
for c in txt:
  if c != '*':
    if up:
      c = c.upper()
    
    print(c,end="")
  else:
    up = not up
