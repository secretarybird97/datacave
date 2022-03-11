# -*- coding: utf-8 -*-
"""
Created on Wed Oct  6 11:18:28 2021

@author: jesus
"""
def peliculasdeactor(nombre,relacion):
    pelis = 0
    for key in relacion:
        if (relacion[key]['actor']['nombre']==nombre):
            pelis+=1
    return pelis
def cantidadactores(nombre,relacion):
    actores=0
    for key in relacion :
        if (relacion[key]['pelicula']['nombre']==nombre):
            for cont in relacion[key]['pelicula']:
                 actores +=1   
    return actores
def nombrepeliculasdeactor(nombre,relacion):
    pelis = list()
    for key in relacion:
        if (relacion[key]['actor']['nombre']==nombre):
            pelis.append(relacion[key]['pelicula']['nombre'])
    return pelis
def nombrecantidadactores(nombre,relacion):
    actores= list()
    for key in relacion :
        if (relacion[key]['pelicula']['nombre']==nombre):
            for cont in relacion[key]['pelicula']:
                 actores.append(relacion[cont]['actor']['nombre'])
    return actores
def actormaspelis(actores,relacion):
    participaciones=list()
    indice=0
    maxp=1000
    for key in actores:
        participaciones.append(peliculasdeactor(actores[key]['nombre'], relacion))
    for con in participaciones:
        if maxp<participaciones[con]:
            maxp=participaciones[con]
            indice=con
    return actores[indice]['nombre']
actores = dict()
actores['jc01']={'nombre':'Joaquin Cosio'}
actores['vf01']={'nombre':'Veronica Falcon'}
actores['mm01']={'nombre':'Melissa McCarthy'}
actores['kw01']={'nombre':'Kate Winslet'}
actores['at01']={'nombre':'Anya Taylor-Joy'}
actores['jf01']={'nombre':'Johnny Flynn'}
actores['mg01']={'nombre':'Mia Goth'}
actores['ai01']={'nombre':'Angus Imrie'}
actores['lt01']={'nombre':'Letty Thomas'}
actores['gw01']={'nombre':'Gemma Whelan'}
actores['bn01']={'nombre':'Bill Nighy'}
actores['jm01']={'nombre':'James McAvoy'}
actores['hl01']={'nombre':'Haley Lu Richardson'}
actores['js01']={'nombre':'Jessica Sula'}
actores['bb01']={'nombre':'Betty Buckley'}
actores['ic01']={'nombre':'Izzie Coffey'}
actores['bw01']={'nombre':'Brad William Henke'}
actores['rp01']={'nombre':'Rosamund Pike'}
actores['yf01']={'nombre':'Yvette Feuer'}
actores['mn01']={'nombre':'Mirjam Novak'}
actores['rb01']={'nombre':'Ralph Berkin'}
actores['sr01']={'nombre':'Sam Riley'}
actores['cf01']={'nombre':'Claire Foy'}
actores['tc01']={'nombre':'Tom Cullen'}
actores['gl01']={'nombre':'Gary Lewis'}
actores['rj01']={'nombre':'Robert Jack'}
actores['ow01']={'nombre':'Owen Whitelaw'}
actores['mf01']={'nombre':'Michael Fassbender'}
actores['jl01']={'nombre':'Jennifer Lawrence'}
actores['nh01']={'nombre':'Nicholas Hoult'}
actores['st01']={'nombre':'Sophie Turner'}
actores['ts01']={'nombre':'Tye Sheridan'}
actores['jj01']={'nombre':'Javon Johnson'}
actores['sb01']={'nombre':'Sophi Bairley'}
actores['bw02']={'nombre':'Bokeem Woodbine'}
actores['cg01']={'nombre':'Chloë Grace Moretz'}
actores['ct01']={'nombre':'Casey Tutton'}
actores['jh01']={'nombre':'Josh Hutcherson'}
actores['lh01']={'nombre':'Liam Hemsworth'}
actores['st02']={'nombre':'Stanley Tucci'}
actores['wb01']={'nombre':'Wes Bentley'}
actores['ws01']={'nombre':'Willow Shields'}
actores['jg01']={'nombre':'Jeff Goldblum'}
actores['bp01']={'nombre':'Bill Pullman'}
actores['mm02']={'nombre':'Maika Monroe'}
actores['wf01']={'nombre':'William Fichtner'}
actores['jh02']={'nombre':'Judd Hirsch'}
actores['ch01']={'nombre':'Chris Hemsworth'}
actores['th01']={'nombre':'Tom Hiddleston'}
actores['cb01']={'nombre':'Cate Blanchett'}
actores['mr01']={'nombre':'Mark Ruffalo'}
actores['ie01']={'nombre':'Idris Elba'}
actores['tt01']={'nombre':'Tessa Thompson'}
actores['mw01']={'nombre':'Mia Wasikowska'}
actores['jc02']={'nombre':'Jessica Chastain'}
actores['ch02']={'nombre':'Charlie Hunnam'}
actores['jb01']={'nombre':'Jim Beaver'}
actores['lh02']={'nombre':'Leslie Hope'}
actores['rd01']={'nombre':'Robert Downey Jr.'}
actores['ce01']={'nombre':'Chris Evans'}
actores['sj01']={'nombre':'Scarlett Johansson'}
actores['bc01']={'nombre':'Benedict Cumberbatch'}
actores['th02']={'nombre':'Tom Holland'}

peliculas = dict()
peliculas['sp01']={'nombre':'Saving Private Perez'}
peliculas['ts01']={'nombre':'The Starling'}
peliculas['tl01']={'nombre':'The life of David Gale'}
peliculas['em01']={'nombre':'Emma'}
peliculas['sp02']={'nombre':'Split'}
peliculas['ra01']={'nombre':'Radioactive'}
peliculas['ms01']={'nombre':'My son'}
peliculas['xm01']={'nombre':'X-Men: Dark Phoenix'}
peliculas['tp01']={'nombre':'The poker house'}
peliculas['th01']={'nombre':'The hunger games'}
peliculas['id01']={'nombre':'Independence day'}
peliculas['tr01']={'nombre':'Thor: ragnarok'}
peliculas['cp01']={'nombre':'Avengers: endgame'}
peliculas['ae01']={'nombre':'Avengers: endgame'}

relacion = dict()
relacion[1] ={'actor':actores['jc01'],'pelicula':peliculas['sp01']}
relacion[2] ={'actor':actores['vf01'],'pelicula':peliculas['sp01']}
relacion[3] ={'actor':actores['vf01'],'pelicula':peliculas['ts01']}
relacion[4] ={'actor':actores['mm01'],'pelicula':peliculas['ts01']}
relacion[5] ={'actor':actores['mm01'],'pelicula':peliculas['tl01']}
relacion[6] ={'actor':actores['kw01'],'pelicula':peliculas['tl01']}
#Cast emma
relacion[6] ={'actor':actores['at01'],'pelicula':peliculas['em01']}
relacion[7] ={'actor':actores['jf01'],'pelicula':peliculas['em01']}
relacion[8] ={'actor':actores['mg01'],'pelicula':peliculas['em01']}
relacion[9] ={'actor':actores['ai01'],'pelicula':peliculas['em01']}
relacion[10] ={'actor':actores['lt01'],'pelicula':peliculas['em01']}
relacion[11] ={'actor':actores['gw01'],'pelicula':peliculas['em01']}
relacion[12] ={'actor':actores['bn01'],'pelicula':peliculas['em01']}
#Cast split
relacion[13] ={'actor':actores['at01'],'pelicula':peliculas['sp02']}
relacion[14] ={'actor':actores['jm01'],'pelicula':peliculas['sp02']}
relacion[15] ={'actor':actores['hl01'],'pelicula':peliculas['sp02']}
relacion[16] ={'actor':actores['js01'],'pelicula':peliculas['sp02']}
relacion[17] ={'actor':actores['bb01'],'pelicula':peliculas['sp02']}
relacion[18] ={'actor':actores['ic01'],'pelicula':peliculas['sp02']}
relacion[19] ={'actor':actores['bw01'],'pelicula':peliculas['sp02']}
#Cast Radioactive
relacion[20] ={'actor':actores['rp01'],'pelicula':peliculas['ra01']}
relacion[21] ={'actor':actores['yf01'],'pelicula':peliculas['ra01']}
relacion[22] ={'actor':actores['mn01'],'pelicula':peliculas['ra01']}
relacion[23] ={'actor':actores['rb01'],'pelicula':peliculas['ra01']}
relacion[24] ={'actor':actores['sr01'],'pelicula':peliculas['ra01']}
relacion[25] ={'actor':actores['at01'],'pelicula':peliculas['ra01']}
#Cast My son
relacion[26] ={'actor':actores['jm01'],'pelicula':peliculas['ms01']}
relacion[28] ={'actor':actores['cf01'],'pelicula':peliculas['ms01']}
relacion[29] ={'actor':actores['tc01'],'pelicula':peliculas['ms01']}
relacion[30] ={'actor':actores['gl01'],'pelicula':peliculas['ms01']}
relacion[31] ={'actor':actores['rj01'],'pelicula':peliculas['ms01']}
relacion[32] ={'actor':actores['ow01'],'pelicula':peliculas['ms01']}
#Cast X-Men: Dark Phoenix
relacion[33] ={'actor':actores['jm01'],'pelicula':peliculas['xm01']}
relacion[34] ={'actor':actores['mf01'],'pelicula':peliculas['xm01']}
relacion[35] ={'actor':actores['jl01'],'pelicula':peliculas['xm01']}
relacion[36] ={'actor':actores['nh01'],'pelicula':peliculas['xm01']}
relacion[37] ={'actor':actores['st01'],'pelicula':peliculas['xm01']}
relacion[38] ={'actor':actores['ts01'],'pelicula':peliculas['xm01']}
#Cast The poker house
relacion[39] ={'actor':actores['jl01'],'pelicula':peliculas['tp01']}
relacion[40] ={'actor':actores['jj01'],'pelicula':peliculas['tp01']}
relacion[41] ={'actor':actores['sb01'],'pelicula':peliculas['tp01']}
relacion[42] ={'actor':actores['bw02'],'pelicula':peliculas['tp01']}
relacion[43] ={'actor':actores['cg01'],'pelicula':peliculas['tp01']}
relacion[44] ={'actor':actores['ct01'],'pelicula':peliculas['tp01']}
#Cast The hunger games
relacion[45] ={'actor':actores['jl01'],'pelicula':peliculas['th01']}
relacion[46] ={'actor':actores['lh01'],'pelicula':peliculas['th01']}
relacion[47] ={'actor':actores['st02'],'pelicula':peliculas['th01']}
relacion[48] ={'actor':actores['wb01'],'pelicula':peliculas['th01']}
relacion[49] ={'actor':actores['ws01'],'pelicula':peliculas['th01']}
relacion[50] ={'actor':actores['jh01'],'pelicula':peliculas['th01']}
#Cast Independence day
relacion[51] ={'actor':actores['lh01'],'pelicula':peliculas['id01']}
relacion[52] ={'actor':actores['jg01'],'pelicula':peliculas['id01']}
relacion[53] ={'actor':actores['bp01'],'pelicula':peliculas['id01']}
relacion[54] ={'actor':actores['mm02'],'pelicula':peliculas['id01']}
relacion[55] ={'actor':actores['wf01'],'pelicula':peliculas['id01']}
relacion[56] ={'actor':actores['jh02'],'pelicula':peliculas['id01']}
#Cast Thor: ragnarok
relacion[57] ={'actor':actores['jg01'],'pelicula':peliculas['tr01']}
relacion[58] ={'actor':actores['ch01'],'pelicula':peliculas['tr01']}
relacion[59] ={'actor':actores['th01'],'pelicula':peliculas['tr01']}
relacion[60] ={'actor':actores['cb01'],'pelicula':peliculas['tr01']}
relacion[61] ={'actor':actores['mr01'],'pelicula':peliculas['tr01']}
relacion[62] ={'actor':actores['ie01'],'pelicula':peliculas['tr01']}
relacion[63] ={'actor':actores['tt01'],'pelicula':peliculas['tr01']}
#Cast Crimson peak
relacion[64] ={'actor':actores['th01'],'pelicula':peliculas['cp01']}
relacion[65] ={'actor':actores['mw01'],'pelicula':peliculas['cp01']}
relacion[66] ={'actor':actores['ch02'],'pelicula':peliculas['cp01']}
relacion[67] ={'actor':actores['jb01'],'pelicula':peliculas['cp01']}
relacion[68] ={'actor':actores['jc02'],'pelicula':peliculas['cp01']}
relacion[69] ={'actor':actores['lh02'],'pelicula':peliculas['cp01']}
#Cast Avengers:Endgame
relacion[70] ={'actor':actores['mr01'],'pelicula':peliculas['ae01']}
relacion[71] ={'actor':actores['ch01'],'pelicula':peliculas['ae01']}
relacion[72] ={'actor':actores['rd01'],'pelicula':peliculas['ae01']}
relacion[73] ={'actor':actores['ce01'],'pelicula':peliculas['ae01']}
relacion[74] ={'actor':actores['sj01'],'pelicula':peliculas['ae01']}
relacion[75] ={'actor':actores['bc01'],'pelicula':peliculas['ae01']}
relacion[76] ={'actor':actores['th02'],'pelicula':peliculas['ae01']}
#nombre = input("Ingrese el nombre del actor/actriz que desea: ")
#print(f'{nombre} ha participado en ',peliculasdeactor(nombre, relacion),' peliculas')
#nombre = input("Ingrese el nombre dela pelicula que desea: ")
print(cantidadactores(nombre,relacion))
#print("El actor con mas participaciones es: ",actormaspelis(actores, relacion))