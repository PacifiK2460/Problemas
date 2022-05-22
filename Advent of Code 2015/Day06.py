r = str(input())
if r == "read":
    f = open("input.txt","r")
    s = f.readlines()
    f.close()
else:
    s = [r,r]
matrix = [[False for x in range(1000)] for y in range(1000)] 
for line in s:
    words = line.split(' ')
    if len(words) == 4:
        cords_s, cords_e = words[1].split(','), words[3].split(',')
    else:
        cords_s, cords_e = words[2].split(','), words[4].split(',')
    cords_s = list(map(int, cords_s))
    cords_e = list(map(int, cords_e)) 
    for x in range(cords_s[0], cords_e[0]+1):
        for y in range(cords_s[1], cords_e[1]+1):
            if len(words) == 4:
                matrix[x][y] += 2 
            elif words[1] == "on":
                matrix[x][y] += 1
            elif words[1] == "off":
                matrix[x][y] -= 1
                if matrix[x][y] < 0:
                    matrix[x][y] = 0
            else:
                raise Exception("Error")
print(sum(sum(matrix,[])))