//Daniel Rizzo - RA: 582700
//Gustavo Freitas - RA: 582360
//Marcos Felipe - RA: 580562

#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>


struct login {
    char nome[9], senha[9];
} cadastro[5];

char *verificar(int tipo){
	char verify[9];
	int i;
	for (i = 0; i < 8;) {
            verify[i] = getche();

            if (isalpha(verify[i]) || isdigit(verify[i])) {
            	if (tipo == 2){
            		printf("\b*");
				}
                i++;
            }
            else 
				if (verify[i] == 8)
				{
					printf(" \b");
				}
			else {
                printf("\b \b");
            }
        }
    verify[i] = '\0';
    return verify;
}
char *registro()
{
    int j;
    for (j = 0; j < 5; j++) {
        printf("Cadastre o %dº usuario -> ", (j + 1));
        strcpy(cadastro[j].nome, verificar(1));
        printf("\nCadastre a senha do %dº usuario -> ", (j + 1));
        strcpy(cadastro[j].senha, verificar(2));
        system("cls");
        }
}

char *entrada()
{ 
char user[9], senha[9];
int i,nm[5],se[5],logado;
	printf("Login\nDigite seu nome de usuário: ");
	strcpy(user,verificar(1));
	printf("\nDigite sua senha: ");
	strcpy(senha,verificar(2));
	system("cls");
	
	for(i=0;i<5;i++)
	{
		nm[i] = strcmp(cadastro[i].nome,user);
		se[i] = strcmp(cadastro[i].senha,senha);
		
		if ((nm[i] == 0) && (se[i] == 0)){
			logado=1;
		} 
		else {
			logado=0;
		}
	}
	if (logado == 1){
		printf("OK");
	} else {
		printf("Acesso Negado");
	}
}
main()
{
	setlocale(LC_ALL, "Portuguese");
    registro();
    entrada();
}

