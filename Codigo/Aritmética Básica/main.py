a = int(input())
x = str(input())
b = int(input())
r = {'+':a+b, '-':a-b, '*':a*b, '/':a/b, '%':a%b}[x]
print( ('%f' % r).rstrip('0').rstrip('.') )