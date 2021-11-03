n = int(input())

for _ in range(n):
    parrafo = input().split()
    for palabra in parrafo:
        palabra = palabra.upper()
        if(palabra[0] == 'P' and palabra[-1] == 'R') or (palabra[0] == 'H' and 'O' in palabra):
            print("#"*len(palabra),end=' ')
        else:
            print(palabra,end=' ')
    print("\n")