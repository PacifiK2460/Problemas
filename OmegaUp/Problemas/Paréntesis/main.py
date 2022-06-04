txt = input()
if txt.count('(') != txt.count(')') or (txt[0] == ')' or txt[-1] =='(' ):
  print("NO")
else:
  print("SI")