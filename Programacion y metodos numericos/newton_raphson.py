import math
X0=float(input("Valor inicial: "))
n=int(input("¿Cuántas cifras significativas requiere? "))
r=int(input("Decimales a desplegar: "))
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
    FXi=func(X0,0)
    FXip=func(X0,1)
    Xi=X0-(FXi/FXip)
    i=abs((Vact-Vant)/Vact)*100
    v=X0
    X0=Xi
    it=it+1
    print("")
    print(f"Iteración #{it}")
    print(f"X actual: {round(v, r)}")
    print(f"f(Xi) = {round(FXi, r)} | f'(Xi) = {round(FXip, r)}")
    print("Valor de la raíz aproximada: ", round(Xi, r))
    if it!=1:
        print("Error aproximado porcentual:", round(i,2), "%")