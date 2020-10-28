matriz = []
soma_pares = soma_coluna = maior = 0

for i in range(0, 3):
    coluna = []
    for j in range(0, 3):
        valor = int(input(f'Digite um valor para [{i}, {j}]: '))
        coluna.append(valor)

        if valor % 2 == 0:
            soma_pares += valor
        if j == 2:
            soma_coluna += valor
        if i == 1:
            if j == 0:
                maior = valor
            else:
                if valor > maior:
                    maior = valor
    matriz.append(coluna)

print('='*15)
for i in range(0, 3):
    for j in range(0, 3):
            print(f'[{matriz[i][j] :^5}]', end='')
    print()

print('='*15)
print(f'A soma dos valores pares digitados é {soma_pares}')
print(f'A soma dos valores da terceira coluna é {soma_coluna}')
print(f'O maior valor da segunda linha é {maior}')
