'''Miguel Cuevas #1279713'''

def numero_peliculas(actor, relacion): #actor=string, relacion=dict()
    n = 0
    for i in relacion:
        if(relacion[i]['actor']['nombre']==actor):
            n+=1
    return n

def n_actores_en(pelicula, relacion): #pelicula=string, relacion=dict()
    n=0 
    for i in relacion:
        if(relacion[i]['pelicula']['nombre']==pelicula):
            for j in relacion[i]['pelicula']:
                n+=1
    return n

def peliculas_con(actor, relacion): #actor=string, relacion=dict()
    peliculas=list()
    for i in relacion:
        if(relacion[i]['actor']['nombre']==actor):
            peliculas.append(relacion[i]['pelicula']['nombre'])
    return peliculas

def actores_en(pelicula, relacion): #pelicula=string, relacion=dict()
    actores=list()
    for i in relacion:
        if(relacion[i]['pelicula']['nombre']==pelicula):
            actores.append(relacion[i]['actor']['nombre'])
    return actores

def actor_max(actores, relacion): #actores=dict(), relacion=dict()
    nombre=''
    n = 0
    for i in actores:
        if((numero_peliculas(actores[i]['nombre'], relacion))>n):
            n = numero_peliculas(actores[i]['nombre'], relacion)
            nombre = actores[i]['nombre']
    return nombre

actores = dict()
actores['cb01'] = {'nombre':'Christian Bale'}
actores['hl01'] = {'nombre':'Heath Ledger'}
actores['ae01'] = {'nombre':'Aarib Eckhart'}
actores['mc01'] = {'nombre':'Michael Caine'}
actores['go01'] = {'nombre':'Gary Oldman'}
actores['ldc'] = {'nombre':'Leonardo DiCaprio'}
actores['jgl'] = {'nombre':'Joseph Gordon-Levitt'}
actores['th01'] = {'nombre':'Tom Hardy'}
actores['ep01'] = {'nombre':'Elliot Page'}
actores['cm01'] = {'nombre':'Cillian Murphy'}
actores['jl01'] = {'nombre':'Jared Leto'}
actores['wd01'] = {'nombre':'William Dafoe'}
actores['sb01'] = {'nombre':'Stephen Bogart'}
actores['rw01'] = {'nombre':'Reese Witherspoon'}
actores['hj01'] = {'nombre':'Hugh Jackman'}
actores['jg01'] = {'nombre':'Jack Gyllenghaal'}
actores['th01'] = {'nombre':'Terrence Howard'}
actores['pd01'] = {'nombre':'Paul Dano'}
actores['dd01'] = {'nombre':'David Dastmalchian'}
actores['ml01'] = {'nombre':'Melissa Leo'}
actores['rdj'] = {'nombre':'Robert Downey Jr.'}
actores['mr01'] = {'nombre':'Mark Ruffalo'}
actores['jcl01'] = {'nombre':'John Carroll Lynch'}
actores['ae02'] = {'nombre':'Anthony Edwards'}
actores['bs01'] = {'nombre':'Ben Stiller'}
actores['jb01'] = {'nombre':'Jack Black'}
actores['tc01'] = {'nombre':'Tom Cruise'}
actores['mc02'] = {'nombre':'Matthew McConaughey'}
actores['jc01'] = {'nombre':'Jim Carrey'}
actores['kw01'] = {'nombre':'Kate Winslet'}
actores['ew01'] = {'nombre':'Elijah Wood'}
actores['tw01'] = {'nombre':'Tom Wilkinson'}
actores['th02'] = {'nombre':'Tom Hanks'}
actores['cw01'] = {'nombre':'Christopher Walken'}
actores['aa01'] = {'nombre':'Amy Adams'}
actores['nb01'] = {'nombre':'Nathalie Baye'}
actores['bk01'] = {'nombre':'Ben Kingsley'}
actores['mw01'] = {'nombre':'Michelle Williams'}
actores['ah01'] = {'nombre':'Anne Hathaway'}
actores['tc02'] = {'nombre':'Timothée Chalamet'}
actores['jc02'] = {'nombre':'Jessica Chastain'}


peliculas = dict()
peliculas['btdk'] = {'nombre':'The Dark Knight'}
peliculas['time'] = {'nombre':'Inception'}
peliculas['ap01'] = {'nombre':'American Psycho'}
peliculas['prsns'] = {'nombre':'Prisoners'}
peliculas['zc'] = {'nombre':'Zodiac'}
peliculas['tropic'] = {'nombre':'Tropic Thunder'}
peliculas['essm'] = {'nombre':'Eternal Sunshine of the Spotless Mind'}
peliculas['ciyc'] = {'nombre':'Catch Me If You Can'}
peliculas['shut'] = {'nombre':'Shutter Island'}
peliculas['int'] = {'nombre':'Interstellar'}

relacion = dict()
relacion[1]={'actor':actores['cb01'],'pelicula':peliculas['btdk']} #The Dark Knight
relacion[2]={'actor':actores['hl01'],'pelicula':peliculas['btdk']}
relacion[3]={'actor':actores['ae01'],'pelicula':peliculas['btdk']}
relacion[4]={'actor':actores['mc01'],'pelicula':peliculas['btdk']}
relacion[5]={'actor':actores['go01'],'pelicula':peliculas['btdk']}
relacion[6]={'actor':actores['ldc'],'pelicula':peliculas['time']} #Inception
relacion[7]={'actor':actores['jgl'],'pelicula':peliculas['time']}
relacion[8]={'actor':actores['th01'],'pelicula':peliculas['time']}
relacion[9]={'actor':actores['ep01'],'pelicula':peliculas['time']}
relacion[10]={'actor':actores['cm01'],'pelicula':peliculas['time']}
relacion[11]={'actor':actores['mc01'],'pelicula':peliculas['time']}
relacion[12]={'actor':actores['cb01'],'pelicula':peliculas['ap01']} #American Psycho
relacion[13]={'actor':actores['jl01'],'pelicula':peliculas['ap01']}
relacion[14]={'actor':actores['wd01'],'pelicula':peliculas['ap01']}
relacion[15]={'actor':actores['sb01'],'pelicula':peliculas['ap01']}
relacion[16]={'actor':actores['rw01'],'pelicula':peliculas['ap01']}
relacion[17]={'actor':actores['hj01'],'pelicula':peliculas['prsns']} #Prisoners
relacion[18]={'actor':actores['jg01'],'pelicula':peliculas['prsns']}
relacion[19]={'actor':actores['th01'],'pelicula':peliculas['prsns']}
relacion[20]={'actor':actores['pd01'],'pelicula':peliculas['prsns']}
relacion[21]={'actor':actores['dd01'],'pelicula':peliculas['prsns']}
relacion[22]={'actor':actores['ml01'],'pelicula':peliculas['prsns']}
relacion[23]={'actor':actores['rdj'],'pelicula':peliculas['zc']} #Zodiac
relacion[24]={'actor':actores['mr01'],'pelicula':peliculas['zc']}
relacion[25]={'actor':actores['jg01'],'pelicula':peliculas['zc']}
relacion[26]={'actor':actores['jcl01'],'pelicula':peliculas['zc']}
relacion[27]={'actor':actores['ae02'],'pelicula':peliculas['zc']}
relacion[28]={'actor':actores['rdj'],'pelicula':peliculas['tropic']} #Tropic Thunder
relacion[29]={'actor':actores['mc02'],'pelicula':peliculas['tropic']}
relacion[30]={'actor':actores['bs01'],'pelicula':peliculas['tropic']}
relacion[31]={'actor':actores['jb01'],'pelicula':peliculas['tropic']}
relacion[32]={'actor':actores['tc01'],'pelicula':peliculas['tropic']}
relacion[33]={'actor':actores['mr01'],'pelicula':peliculas['essm']} #Eternsal Sunshine of the Spotless Mind
relacion[34]={'actor':actores['jc01'],'pelicula':peliculas['essm']}
relacion[35]={'actor':actores['kw01'],'pelicula':peliculas['essm']}
relacion[36]={'actor':actores['tw01'],'pelicula':peliculas['essm']}
relacion[37]={'actor':actores['ew01'],'pelicula':peliculas['essm']}
relacion[38]={'actor':actores['ldc'],'pelicula':peliculas['ciyc']} #Catch me if You Can
relacion[39]={'actor':actores['th02'],'pelicula':peliculas['ciyc']}
relacion[40]={'actor':actores['cw01'],'pelicula':peliculas['ciyc']}
relacion[41]={'actor':actores['aa01'],'pelicula':peliculas['ciyc']}
relacion[42]={'actor':actores['nb01'],'pelicula':peliculas['ciyc']}
relacion[43]={'actor':actores['ldc'],'pelicula':peliculas['shut']}
relacion[44]={'actor':actores['mr01'],'pelicula':peliculas['shut']}
relacion[45]={'actor':actores['jcl01'],'pelicula':peliculas['shut']} #Shutter Island
relacion[46]={'actor':actores['bk01'],'pelicula':peliculas['shut']}
relacion[47]={'actor':actores['mw01'],'pelicula':peliculas['shut']}
relacion[48]={'actor':actores['mc02'],'pelicula':peliculas['int']} #Interstellar
relacion[49]={'actor':actores['mc01'],'pelicula':peliculas['int']}
relacion[50]={'actor':actores['ah01'],'pelicula':peliculas['int']}
relacion[51]={'actor':actores['tc01'],'pelicula':peliculas['int']}
relacion[52]={'actor':actores['jc02'],'pelicula':peliculas['int']}

'''for i in range(1, 53):
    print(relacion[i])'''

x='Leonardo DiCaprio'
print("\n\n")
print(f"Numero de peliculas en las que aparece {x}:", numero_peliculas(x, relacion))
print("Numero de actores en Tropic Thunder:", n_actores_en('Tropic Thunder', relacion))
print(f"Peliculas con {x}:", peliculas_con(x, relacion))
print("Actores en Zodiac:", actores_en('Zodiac', relacion))
print("Actor con mas peliculas:", actor_max(actores, relacion))