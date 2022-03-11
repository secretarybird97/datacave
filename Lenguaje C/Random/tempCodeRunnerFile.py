def actor_max(actores, relacion): #actores=dict(), relacion=dict()
    nombre=''
    n = 0
    for i in actores:
        if((numero_peliculas(actores[i]['nombre'], relacion))>n):
            n = numero_peliculas(actores[i]['nombre'], relacion)
            nombre = actores[i]['nombre']
    return nombre