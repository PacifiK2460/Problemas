r = str(input())
if r == "read":
    #print("reading")
    f = open("input.txt","r")
    s = str(f.readlines())
    f.close()
else:
    s = r

cords = [["0,0"],["0,0"]]
i = 0
x1 = 0
y1 = 0
x2 = 0
y2 = 0

for _ in s:
    if _ == '^':
        if i:
            y1+=1
        else:
            y2+=1
    elif _ == 'v':
        if i:
            y1-=1
        else:
            y2-=1
    elif _ == '>':
        if i:
            x1+=1
        else:
            x2+=1
    elif _ == '<':
        if i:
            x1-=1
        else:
            x2-=1

    
    if _ == '^' or _ == 'v' or _ == '>' or _ == '<':
        if i:
            x = x1
            y = y1
        else:
            x = x2
            y = y2
        cords[i].append(f"{x},{y}")
        i = not i

cords = list(dict.fromkeys(cords[0])) + list(dict.fromkeys(cords[1]))
cords = list(dict.fromkeys(cords))
#print(cords)
print(len(cords))
