import math
Xi=float(input("Límite inferior: "))
Xs=float(input("Límite superior: "))
n=int(input("¿Cuántas cifras significativas requiere? "))
Es=0.5*10**(2-n)
v=0
i=100
it=0

def func(x): #Función a evaluar
    y = (math.exp(-x))-x
    return y

while i>Es:
    Xr=(Xi+Xs)/2
    FXi=func(Xi)
    FXr=func(Xr)
    i=abs((Xr-v)/Xr)*100
    v=Xr
    it=it+1
    print("")
    print(f"Iteración #{it}")
    print(f"Límite inferior: {round(Xi, 6)} | Límite superior: {round(Xs, 6)}")
    print(f"f(Xi) = {round(FXi, 6)} | f(Xr) = {round(FXr, 6)} \n")
    print("Valor de la raíz aproximada:", round(Xr, 6))
    if it!=1:
        print("Error aproximado porcentual:", round(i,2), "%")
    if (FXi*FXr)>0:
        Xi=Xr
        Xs=Xs
    else:
        Xi=Xi
        Xs=Xr