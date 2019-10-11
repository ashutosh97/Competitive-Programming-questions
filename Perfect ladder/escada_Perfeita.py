n = int(input())
termos = [int(x) for x in input().split()]
sn = 0
for i in termos:
  sn += i
""" 
an=a1+(n-1)*r
razão é 1 porque os bloquinhos aumentam 1 em 1
an = a1 + (n-1).r
como razão é 1 --> an = a1+(n-1) --> a1 = an -(n-1) --> 
*****a1 =  an - n +1 *****
soma SN= (a1+an).(n/2)
manipulando -->
2sn = (a1+an).n --> 
2sn/n = a1+an  --> 
---- an = 2sn/n - a1 ----
a1 = 2sn/n- an

"""
equacao = (2*sn) / n
an = (equacao + (n - 1)) // 2
a1 = an - n +1
sobras,alteracoes = 0,0
for i in range(n):
  sobras+=(termos[i] - (i + a1))
  if (termos[i]>i+a1):
    alteracoes+=(termos[i] - (i + a1))

if sobras == 0:
    print(int(alteracoes))
else:
    print(-1)
