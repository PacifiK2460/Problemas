def f(n,i):
    #print(f"f({n}) = ",end='')
    if n%2:
        n = 3*n+1
    else:
        n = n/2
    
    #print(f"{n} | {i}")
    if n != 1:
        return f(n,i+1)
    return i+1
n = int(input())
print(f(n,1)-1)