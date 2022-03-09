print("Diccionarios") #Diccionarios
bolsa={'dinero' : 12, 'dulces' : 3, 'panuelos' : 75}
print(bolsa)
print( bolsa['dulces'])
bolsa['dulces']+=2
print(bolsa)

print("\nListas vs diccionarios") #Listas vs diccionarios
lst = [21, 183]
print(lst)
lst[0] = 23
print(lst)
print("")
datos = {'edad' : 21, 'curso' : 182}
print(datos)
datos['edad'] = 23
print(datos)

print("\nDiccionarios literales") #Diccionarios literales
d = {'carlos' : 1, 'alfredo' : 42, 'enero' : 100}
print(d)
otro = {}
print(otro)

print("\nMuchos contadores en un diccionario") #Muchos contadores en un diccionario
nombres = {'Carlos' : 1, 'Jorge' : 1}
print(nombres)
nombres['Jorge']+=1
print(nombres)

print("\nDiccionarios: tracebacks") #Diccionarios tracebacks
'Carlos' in nombres

 #Cuando vemos un nuevo nombre
contadores = {}
nombres = ['Jorge', 'Alberto', 'Jorge', 'Luis', 'Alberto']
for nombre in nombres:
    if nombre not in contadores:
        contadores[nombre] = 1
    else:
        contadores[nombre]+=1
print(contadores)

print("\nMetodoo get") #Metodo get
if nombre in contadores:
    x = contadores[nombre]
else:
    x = 0
x = contadores.get(nombre,0)

contadores={}
nombres = ['Jorge', 'Alberto', 'Jorge', 'Luis', 'Alberto']
for nombre in nombres:
    contadores[nombre] = contadores.get(nombre,0)+1
print(contadores)

print("\nPatron de conteo") #Patron de conteo
contadores={}
linea = input("Introduce una linea de texto: ")
palabras = linea.split()
print("Contando...")
for palabra in palabras:
    contadores[palabra] = contadores.get(palabra,0)+1
print('Contadores:', contadores)

print("\nDiccionarios y ciclos") #Diccionarios y ciclos definidos
contadores = {'Jorge' : 2, 'Alberto' : 2, 'Luis' : 1}
for i in contadores:
    print(i, contadores[i])

print("\nRecuperando listas de claves y valores") #Recuperando listas de claves y valores
contadores = {'Jorge' : 2, 'Alberto' : 2, 'Luis' : 1}
print(list(contadores))
print(contadores.keys())
print(contadores.values())
print(contadores.items())

print("\nIteracion con dos variables") #Recuperando listas de claves y valores
contadores = {'Jorge' : 2, 'Alberto' : 2, 'Luis' : 1}
for clave,valor in contadores.items():
    print(clave, valor)

print("")
nombre = input("Introduce el nombre del archivo: ")
archivo = open(nombre)
contadores={}
for linea in archivo:
    palabras=linea.split()
    for palabra in palabras:
        contadores[palabra] = contadores.get(palabra,0)+1
contador_mayor = None
palabra_mayor = None
for palabra,contador in contadores.items():
    if contador_mayor is None or contador > contador_mayor:
        palabra_mayor = palabra
        contador_mayor = contador
print(palabra_mayor, contador_mayor)