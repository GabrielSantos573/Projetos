//Nome completo:Gabriel Oliveira Santos. Matr�cula:UC21100452.  Curso: Ci�ncia da computa��o.
 
#include<stdio.h>//biblioteca para printf e scanf
#include<stdlib.h> //biblioteca para limpar a tela 
#include<math.h>  //biblioteca para opera��es matem�ticas
#include<locale.h>//biblioteca para pra aceitar caracter especial:setlocale(LC_ALL, "Portuguese");
#include<string.h>//biblioteca para strlen e strcmp: http://linguagemc.com.br/a-biblioteca-string-h/
#include<ctype.h> //biblioteca para o uso do toupper e tolower
#include <windows.h>

static int BACKGROUND = 1;BLACK;//pode ser o numero ou o nome da cor/
static int FOREGROUND = 7;LIGHTGRAY;

void textcolor (int letras, int fundo){//para mudar a cor de fundo mude o background*/

    FOREGROUND = letras;
    BACKGROUND = fundo;	//�nico jeito do textcolor funcionar pra mim.
    
    SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE),
    letras + (BACKGROUND << 4));
}


/*             0     1    2     3   4      5      6      7         8  /
typedef enum{BLACK,BLUE,GREEN,CYAN,RED,MAGENTA,BROWN,LIGHTGRAY,DARKGRAY,   / nome das cores /
LIGHTBLUE,LIGHTGREEN,LIGHTCYAN,LIGHTRED,LIGHTMAGENTA,YELLOW,WHITE} COLORS;
/  9         10         11        12        13         14    15 /
*/


int main(){
	setlocale(LC_ALL, "Portuguese");//para pra aceitar caracter especial em portugues
	
	char destino[25], ocupacao[200], nome[25];
	int qntAssentos, fileira = 0, idade,opcao, reserva,confirmado, id = 0, i = 0;
	int qntReserva = 0, qntConfi = 0, qntDisp = 0, responsavel;
	float preco, novoPreco;
	
	//Intera��o com a empressa.

	do{
		printf("\nDestino do voo:");
		fgets(destino,25,stdin);
		
		
		if(strlen(destino) <= 2)
			printf("O destino n�o pode ser nulo!");
		else ("Destino aceito");
	}while(strlen(destino) <= 2);
	
	do{
		printf("Qual � o pre�o da passagem?R$");
		scanf("%f", &preco);
		if(preco <= 0)
			printf("Pre�o inv�lido");
	}while(preco <= 0);
	
	fflush(stdin);

	do{
		printf("Qual � a quantidade de assentos?");
		scanf("%d", &qntAssentos);
		if(qntAssentos < 90 || qntAssentos > 200)
			printf("N�o temos aeronaves com essa capacidade");
		else printf("Dados aceitos\n");
	}while(qntAssentos < 90 || qntAssentos > 200);
	
	getch("");//Pra n�o limpor a tela direto(precisa que aperte alguma tecla)
	system("cls");
	
	//Intera��o com o usu�rio.
	
	
	for(int i = 0; i < qntAssentos; i++){//cria��o do mapa dos assentos do avi�o 
		ocupacao[i] = 'D';
	}

	printf("Ol�, seja bem vinda(o) � SALUMAR LINHAS AEREAS.\n");
	
	do{
		printf("\n1- Verificar a ocupa��o do voo;\n");
		printf("2- Efetuar reserva;\n");
		printf("3- Ver n�mero de indentifica��o;\n");
		printf("4- Cancelar reserva;\n");
		printf("5- Confirmar reserva;\n");
		printf("0- sair\n");
		scanf("%d", &opcao);
		
		fflush(stdin);
		
		switch(opcao){
			case 1:
				for(int i = 0; i < qntAssentos; i++){
					printf("[%c] ", ocupacao[i]);
					
					if(ocupacao[i + 1] == 'D'){
						textcolor(2,0);//comando pra mudar a cor do assento de acordo com a letra. 
					}
					else if(ocupacao[i + 1] == 'R'){
						textcolor(4,0);
					}else 
						textcolor(1,0);	
					fileira++;
					if(fileira == 4){//Pra dividir em fileiras de 4. 
						printf("\n");
						fileira = 0;
					}
				}
				
				getch("");
				system("cls");
				textcolor(15,0);
				break;	
			case 2: 
			
				do{
					printf("\nQual � o seu nome?");
					fgets(nome, 25, stdin);
					
					fflush(stdin);
					
					printf("\nQual � a sua idade?");
					scanf("%d", &idade);
					if(idade > 120 || idade <= 0)
						printf("Idade n�o aceita!");
					else if(idade <= 14){
						printf("Na SALUMAR LINHAS AEREAS n�o permitimos que crian�as(<16) reservem vo�s");
						printf("\nCaso esteja acompanhado informe a idade do Respons�vel primeiro: ");
						scanf("%d", &responsavel);
						printf("\n(A idade do acompanhate e da crian�a ser� verificada no aeroporto)\n");
					}
				}while(idade > 120 || idade <= 0);
				if(idade <= 5)
					preco = (preco/2);
			
				printf("\nDigite o numero do assento desejado:");
				scanf("%d", &reserva);
				qntReserva++;
				
				
				
				for(int i = 0; i < qntAssentos; i++){
					if((i + 1) == reserva){
						ocupacao[i] = 'R';
					}	
				}
					
				id = reserva;
				printf("O seu n�mero de indentifica��o �: %d", id);
				printf("\nO pre�o a pagar �: %.2f", preco);
				
				getch("");
				system("cls");
				
				break;
			case 3: 
				printf("==============================================");
				printf("\n%s", nome);
				printf("O seu n�mero de indentifica��o �: %d\n", id);
				printf("==============================================");
				
				getch("");
				system("cls");
				
				break;
			case 4:
				printf("\nQual � o seu n�mero de indentifica��o?");
				scanf("%d", &id);
				for(int i = 0; i < qntAssentos; i++){
					if((i + 1) == id)
						ocupacao[i] = 'D';
				}
				
				system("cls");
				
				break;
			case 5:
				
				printf("\nQual � o seu n�mero de indentifica��o?");printf("(Para confima��o uma reserva � necess�rio que haja uma reserva.)");
				scanf("%d", &id);
				qntConfi++;
				
				for(int i = 0; i < qntAssentos; i++){
					if((i + 1) == id && ocupacao[i] == 'R')
						ocupacao[i] = 'C';	
				}
						
				getch("");
				system("cls");
				break;
				
			case 0:
				printf("Agradecemos por escolher SALUMAR LINHAS AEREAS, volte sempre!");
				break;	
		}
		
	}while(opcao != 0);
	
	//Intera��o com a empressa.
	
	getch("");
	system("cls");
	
	printf("QUANTIDADE DE ASSENTOS COM RESERVAS: %d", qntReserva);
	printf("\nQUANTIDADE DE VENDAS CONFIRMADAS: %d", qntConfi);
	
	qntDisp = qntAssentos - (qntReserva + qntConfi);
	
	printf("\nQUANTIDADE DE ASSENTOS DISP�NIVEIS: %d", qntDisp);
		

	return 0;
	
}
