def c(s):
    p = []
    true = []
    for c in range(len(s)):
        #checa por vocales
        if c != len(s)-1:
            p.append( f"{s[c]}{s[c+1]}"):

    return all(true)

r = input("arch")
if r == "y":
    f = open("input.txt","r")
    s = f.readlines()
    f.close()
    t = 0
    for i in s:
        if c(i):
            t+=1
    print(t)

else:
    s = str(input())
    print(c(s))
