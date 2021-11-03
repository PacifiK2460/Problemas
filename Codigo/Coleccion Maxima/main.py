def c(i):
    print(coleccion[-1])
def i(i):
    coleccion[-1] = coleccion[-1] + i
    #print(coleccion[-1])
def d(i):
    coleccion[-1] = coleccion[-1] - i
    print(coleccion[-1])

coleccion = []
acciones = {'G':coleccion.append,'C':c,'E':coleccion.pop,'I':i,'D':d,'T':exit}
while True:
    i = input().split()
    c = i[0]

    try:
        k = int(i[1])
    except:
        k = 0

    try:
        acciones[c](k)
    except Exception:
        print("ERROR")
    coleccion.sort()