import time
r = str(input())
if r == "read":
    filename = open("input.txt","r")
    archivo = filename.readlines()
    filename.close()
else:
    archivo = []
    archivo.append(r)
    archivo .append("")
del r
reserved = ["id","and","as","assert","break","class","continue","def","del","elif","else","except","False","True","finally","for","from","global","if","import","in","is","lamba","not","or","pass","raise","return","try","while","with","yeild"]

archivo.reverse()
for linea in archivo:
    while True:
        palabras = linea.split(" ")
        try:
            if len(palabras) == 3:
                if palabras[2].rstrip() in reserved:
                    palabras[2] = f"_{palabras[2]}"
                if palabras[0].rstrip() in reserved:
                    palabras[0] = f"_{palabras[0]}"

                print(f"{palabras[2].rstrip()} = {palabras[0]}")
                exec(f"{palabras[2].rstrip()} = {palabras[0]}")
            elif len(palabras) == 4:
                if palabras[3].rstrip() in reserved:
                    palabras[3] = f"_{palabras[3]}"
                if palabras[1].rstrip() in reserved:
                    palabras[1] = f"_{palabras[1]}"

                print(f"{palabras[3].rstrip()} = ~{palabras[1]}")
                exec(f"{palabras[3].rstrip()} = ~{palabras[1]}")
            else:
                if palabras[2].rstrip() in reserved:
                    palabras[2] = f"_{palabras[2]}"
                if palabras[0].rstrip() in reserved:
                    palabras[0] = f"_{palabras[0]}"
                if palabras[4].rstrip() in reserved:
                    palabras[4] = f"_{palabras[4]}"

                if palabras[1] == "AND":                        
                    print(f"{palabras[4].rstrip()} = {palabras[0]}&{palabras[2]}")
                    exec(f"{palabras[4].rstrip()} = {palabras[0]}&{palabras[2]}")
                elif palabras[1] == "OR":
                    print(f"{palabras[4].rstrip()} = {palabras[0]}|{palabras[2]}")
                    exec(f"{palabras[4].rstrip()} = {palabras[0]}|{palabras[2]}")
                elif palabras[1] == "LSHIFT":
                    print(f"{palabras[4].rstrip()} = {palabras[0]}<<{palabras[2]}")
                    exec(f"{palabras[4].rstrip()} = {palabras[0]}<<{palabras[2]}")
                elif palabras[1] == "RSHIFT":
                    print(f"{palabras[4].rstrip()} = {palabras[0]}>>{palabras[2]}")
                    exec(f"{palabras[4].rstrip()} = {palabras[0]}>>{palabras[2]}")
                else:
                    exec(f"raise Exception(\"Error\")")
            break
        except NameError as var:
            print(var)
            #time.sleep(0.1)
            var = str(var).split(' ')
            var = var[1].replace("\'",'')
            print("Declarando: ",var)
            exec(f"{var} = 0")
        except SyntaxError as var:
            print(f"! {var}")
        except Exception as error:
            print(error)
            time.sleep(5)
print(a)