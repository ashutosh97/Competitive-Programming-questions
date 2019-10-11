#define TAM 5 
#define TAMSENHA 6 
#define VAR 2 
 
int main(){ 
	int banco[TAM][VAR], N, i, j, t, convert, teste = 1;
	int senha[TAMSENHA][VAR];
	char letra;
 
	scanf("%i", &N);
	
	while (N > 0) {
		for (i=0; i < TAMSENHA; i++) {
			for (j=0; j < VAR; j++) {
				senha[i][j] = 0;
			}
		}
 
		for (i=0; i < N; i++) {
			for (j=0; j < TAM; j++) {
				for (t=0; t < VAR; t++) {
					scanf("%i", &banco[j][t]);
				}
			}
 
 
			for (j=0; j < TAMSENHA; j++) {
				letra = getchar(); //para descartar o espaço em branco
				letra = getchar();
				convert = letra - 'A';
				//printf("\n------- %i %i ------", letra, convert);
				
				if (i == 0) {
					senha[j][0] = banco[convert][0];
					senha[j][1] = banco[convert][1];
				} else {
					if (senha[j][0] != banco[convert][0] && senha[j][0] != banco[convert][1]) {
						if (senha[j][1] == banco[convert][0] || senha[j][1] == banco[convert][1]) {
							senha[j][0] = senha[j][1];
						} else {
							senha[j][0] = banco[convert][0];
						}
					}
					if (senha[j][1] != banco[convert][0] && senha[j][1] != banco[convert][1]) {
						if (senha[j][0] == banco[convert][0] || senha[j][1] == banco[convert][1]) {
							senha[j][1] = senha[j][0];
						} else {
							senha[j][1] = banco[convert][1];
						}
					}
				}
			}
		}
		printf("Teste %i\n", teste);
		teste++;
 
		for (i=0; i < TAMSENHA; i++) {
			printf("%i ", senha[i][0]);
		}
 
		printf("\n\n");
		
		scanf("%i", &N);
	}
	
	return 0;
}   