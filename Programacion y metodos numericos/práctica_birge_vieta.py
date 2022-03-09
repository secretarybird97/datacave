import math
import numpy as np
k=int(input("Grado del polinomio: "))
pol1=np.zeros(k+1)
w=k
for j in range(k+1):
    pol1[j]=float(input(f"Coeficiente de x^{w}: "))
    w=w-1
X0=float(input("Valor inicial: "))
n=int(input("¿Cuántas cifras significativas requiere? "))
r=int(input("Decimales a desplegar: "))
Es=0.5*10**(2-n)
i=100
it=1
XA=0

while i>Es:
    Res=np.zeros(k+1)
    polC1=np.zeros(k+1)
    for j in range(k+1):
        if j==0:
            polC1[j]=pol1[j]+Res[j]
        else:
            Res[j]=polC1[j-1]*X0
            polC1[j]=pol1[j]+Res[j]
    pol2=polC1
    pol2=np.delete(pol2,[k])
    Res=np.zeros(k)
    polC2=np.zeros(k)
    for j in range(k):
        if j==0:
            polC2[j]=pol2[j]+Res[j]
        else:
            Res[j]=polC2[j-1]*X0
            polC2[j]=pol2[j]+Res[j]
    Xi=X0-(polC1[k]/polC2[k-1])
    i=abs((X0-XA)/X0)*100
    print("")
    print(f"Iteración #{it}")
    print(f"X actual: {round(X0, r)}")
    print(f"Residuo de f(x) = {round(polC1[k], r)} | Residuo de f'(x) = {round(polC2[k-1], r)}")
    print("X siguiente ", round(Xi, r))
    if it!=1:
        print("Error aproximado porcentual:", round(i,2), "%")
    XA=X0
    X0=Xi
    it=it+1