import codecs
r = str(input())
if r == "read":
    filename = open("input.txt","r")
    archivo = filename.readlines()
    filename.close()
else:
    archivo = []
    archivo.append(r)
    archivo.append("")
t1 = 0
t2 = 0
for x in archivo:
    print(x, " ",len(x)-1 + x[1:-2].count("\\") + x[1:-2].count('"')+4)
    t1 += len(x)-1 + x[1:-2].count("\\") + x[1:-2].count('"')+4
    t2 += len(x)-1

print(t1," - ",t2)
print(t1-t2)