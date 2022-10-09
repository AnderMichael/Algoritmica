from sys import stdin
def readInt(): return int(stdin.readline()[:-1])
def readIntGroup(): return map(int,stdin.readline()[:-1].split())

#stdin = open('Contest1\in.txt','r')

def mezcla(ini):
    #if ini == n-1: return
    global ingredientes,pizzas
    for i in range(ini,n):
        if i!=ini:
            ingredientes[i-1]=False
        if i in pares and any(ingredientes[p] for p in pares[i]):
            continue
        pizzas+=1
        ingredientes[i]=True
        mezcla(i+1)

# Lectura de datos
n,m=readIntGroup()
ingredientes=[False]*n
pares = {}

for i in range(m):
    a,b=readIntGroup()
    a-=1
    b-=1
    if a>b:
        if a in pares:
            pares[a].append(b)
        else:
            pares[a]=[b]
    else:
        if b in pares:
            pares[b].append(a)
        else:
            pares[b]=[a]

#Salida
pizzas=0
mezcla(0)
print(pizzas+1)