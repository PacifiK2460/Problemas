import hashlib
p = str(input())
n = 0
while(1):
    s = p+str(n)
    r = hashlib.md5(s.encode())
    r1 = r.hexdigest()
    if r1[0:6] == "000000":
        print(n)
        break
    else:
        n+=1
