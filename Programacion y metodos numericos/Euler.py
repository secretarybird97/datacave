import math
VR = float(input("Ingresar número real: "))
Z = int(input("¿Cuántos números significativos requiere? "))
c = 0.005*10**(2-Z)
i = 1
y = 0
n = 0
while i>=c:
    if y<1:
        x = (1**n)/(math.factorial(n))
        y = y+x
        EA = (VR-x)/VR
        z = y
    else:
        x = (1**n)/(math.factorial(n))
        z = y
        y = y+x
        i=(y-z)/y
        EA = (VR-y)/VR
    n=n+1
print("")
print("Número de iteraciones:", n, "\n")
print("Valor aproximado: ", y)
print(f"Error absoluto: {EA*100}%")
print(f"Error aproximado porcentual: {i*100}%")