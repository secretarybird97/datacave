import math
X0=float(input("Valor anterior: "))
X1=float(input("Valor actual: "))
n=int(input("¿Cuántas cifras significativas requiere? "))
Es=0.5*10**(2-n)
v=0
i=100
it=0

def func(x,k): #Función a evaluar
    if k==0:
        y=(math.exp(-x))-x
        return y
    if k==1:
        y=(-math.exp(-x))-1
        return y
    
while i>Es:
    Vact=X0
    Vant=v
    FX1=func(X1,0)
    FX0=func(X0,0)
    Xi=X1-((FX1*(X0-X1))/(FX0-FX1))
    i=abs((X1-X0)/X1)*100
    it=it+1
    print("")
    print(f"Iteración #{it}")
    print(f"f(Xi) = {round(FX1, 7)} | f(Xi-1) = {round(FX0, 7)}")
    print("Valor de la raíz aproximada:", round(Xi, 7))
    print("Error aproximado porcentual:", round(i,5), "%")
    v=X1
    X1=Xi
    X0=v