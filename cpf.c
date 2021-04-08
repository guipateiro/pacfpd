#include <stdio.h>

#define DIGITO 0

/* CASO QUEIRA COLOCAR UM CPF DE REGIAO MUDE O DIGITO PARA O DIGITO DO ESTADO E MUDA A FUNCAO "incrementacpf" PARA "incrementacpfdefinido"
1.ª: DF, GO, MT, MS e TO;
2.ª: AC, AP, AM, PA, RO e RR;
3.ª: CE, MA e PI;
4.ª: AL, PB, PE e RN;
5.ª: BA e SE;
6.ª: MG;
7.ª: ES e RJ;
8.ª: SP;
9.ª: PR e SC;
10.ª: RS.*/

struct meucpf{
	int d1;
	int d2;
	int d3;
	int d4;
	int d5;
	int d6;
	int d7;
	int d8;
	int d9;
} typedef T_cpf;

void incrementacpf(T_cpf *ccc){
	if (++ccc->d9 == 10){
		ccc->d9 = 0;
		if (++ccc->d8 == 10){
			ccc->d8 =0;
			if (++ccc->d7 == 10){
				ccc->d7= 0;
				if (++ccc->d6 == 10){
					ccc->d6 = 0;
					if (++ccc->d5 == 10){
						ccc->d5 = 0;
						if (++ccc->d4 == 10){
							ccc->d4 = 0;
							if (++ccc->d3 == 10){
								ccc->d3 = 0;
								if (++ccc->d2 == 10){
									ccc->d2 = 0;
									if (++ccc->d1 == 10)
										return;
								}
							}
						}
					}
				}
			}
		}
	}
	return;																		
}

void incrementacpfdefinido(T_cpf *ccc){
	if (++ccc->d8 == 10){
		ccc->d8 =0;
		if (++ccc->d7 == 10){
			ccc->d7= 0;
			if (++ccc->d6 == 10){
				ccc->d6 = 0;
				if (++ccc->d5 == 10){
					ccc->d5 = 0;
					if (++ccc->d4 == 10){
						ccc->d4 = 0;
							if (++ccc->d3 == 10){
							ccc->d3 = 0;
							if (++ccc->d2 == 10){
								ccc->d2 = 0;
								if (++ccc->d1 < 10)
									return;
							}
						}
					}
				}
			}
		}
	}
	return;																		
}




int main(){
	int codigo;
	T_cpf cpf = {0,0,0,0,0,0,0,0,DIGITO};
	printf("insina os ultimos 2 digitos que deseja pesquisar: \n");
	scanf("%i", &codigo);
	int codigo1 = codigo % 10;
	int codigo2 =(codigo - codigo1)/10;
	int aux1 = 0;
	int aux2 = 0;
	int aux = 0;
	long aux3 = 0;
	FILE* arq = NULL;

	arq = fopen("resp.txt","w");

	//printf("%i || %i \n",codigo2, codigo1);
	printf("%i%i%i.%i%i%i.%i%i%i\n",cpf.d1,cpf.d2,cpf.d3,cpf.d4,cpf.d5,cpf.d6,cpf.d7,cpf.d8,cpf.d9 );
	while(cpf.d1<10){
		aux = codigo1+codigo2+cpf.d1+cpf.d2+cpf.d3+cpf.d4+cpf.d5+cpf.d6+cpf.d7+cpf.d8+cpf.d9;
		if (((aux % 11) == 0 || (aux % 11) == 10 || (aux % 11) == 1) && (aux <= 88)){ //logica da soma dos digitos de um cpf ser multiplo de 11 com vairacao de +/- 1
			aux1 = (cpf.d1*10)+(cpf.d2*9)+(cpf.d3*8)+(cpf.d4*7)+(cpf.d5*6)+(cpf.d6*5)+(cpf.d7*4)+(cpf.d8*3)+(cpf.d9*2);   //logica do primeiro digito verificador
			aux1 = aux1 % 11;
			if (aux1 == 0 || aux1 == 1){ 
				aux1 = 0;
			}
			else {
				aux1 = 11 - aux1;
			}
			aux2 = (cpf.d1*11)+(cpf.d2*10)+(cpf.d3*9)+(cpf.d4*8)+(cpf.d5*7)+(cpf.d6*6)+(cpf.d7*5)+(cpf.d8*4)+(cpf.d9*3)+(aux1*2); //logica do segundo digito verificador 
			aux2 = aux2 % 11;
			if(aux2 == 0 || aux2 == 1){
				aux2 = 0;			    
			}
			else {
				aux2 = 11 - aux2;
			}
			if(aux1 == codigo2 && aux2 == codigo1){		//comparacao dos digitos dos outros 9 numeros com o desejado
				fprintf(arq,"%i%i%i.%i%i%i.%i%i%i\n",cpf.d1,cpf.d2,cpf.d3,cpf.d4,cpf.d5,cpf.d6,cpf.d7,cpf.d8,cpf.d9 );
				aux3++;
			}
			incrementacpf(&cpf);
			//incrementacpfdefinido(&cpf);
		}
		else{
			incrementacpf(&cpf);
			//incrementacpfdefinido(&cpf);
		}
	}

printf("%li \n", aux3);




}