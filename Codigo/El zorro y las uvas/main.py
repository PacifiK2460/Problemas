n = input()
uvas = input().split()
m = input()
saltos = input().split()
for salto in saltos:
    c = 0
    for uva in uvas:
        if salto >= uva:
            c = c + 1
    print(c,end=' ')
    c = 0