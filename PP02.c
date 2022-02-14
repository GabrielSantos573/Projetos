//Nome completo:Gabriel Oliveira Santos. Matrícula:UC21100452.  Curso: Ciência da computação.
 
#include<stdio.h>//biblioteca para printf e scanf
#include<stdlib.h> //biblioteca para limpar a tela 
#include<math.h>  //biblioteca para operações matemáticas
#include<locale.h>//biblioteca para pra aceitar caracter especial:setlocale(LC_ALL, "Portuguese");
#include<string.h>//biblioteca para strlen e strcmp: http://linguagemc.com.br/a-biblioteca-string-h/
#include<ctype.h> //biblioteca para o uso do toupper e tolower
#include <windows.h>

static int BACKGROUND = 1;BLACK;//pode ser o numero ou o nome da cor/
static int FOREGROUND = 7;LIGHTGRAY;

void textcolor (int letras, int fundo){//para mudar a cor de fundo mude o background*/

    FOREGROUND = letras;
    BACKGROUND = fundo;	//único jeito do textcolor funcionar pra mim.
    
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
	
	//Interação com a empressa.

	do{
		printf("\nDestino do voo:");
		fgets(destino,25,stdin);
		
		
		if(strlen(destino) <= 2)
			printf("O destino não pode ser nulo!");
		else ("Destino aceito");
	}while(strlen(destino) <= 2);
	
	do{
		printf("Qual é o preço da passagem?R$");
		scanf("%f", &preco);
		if(preco <= 0)
			printf("Preço inválido");
	}while(preco <= 0);
	
	fflush(stdin);

	do{
		printf("Qual é a quantidade de assentos?");
		scanf("%d", &qntAssentos);
		if(qntAssentos < 90 || qntAssentos > 200)
			printf("Não temos aeronaves com essa capacidade");
		else printf("Dados aceitos\n");
	}while(qntAssentos < 90 || qntAssentos > 200);
	
	getch("");//Pra não limpor a tela direto(precisa que aperte alguma tecla)
	system("cls");
	
	//Interação com o usuário.
	
	
	for(int i = 0; i < qntAssentos; i++){//criação do mapa dos assentos do avião 
		ocupacao[i] = 'D';
	}

	printf("Olá, seja bem vinda(o) à SALUMAR LINHAS AEREAS.\n");
	
	do{
		printf("\n1- Verificar a ocupação do voo;\n");
		printf("2- Efetuar reserva;\n");
		printf("3- Ver número de indentificação;\n");
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
					printf("\nQual é o seu nome?");
					fgets(nome, 25, stdin);
					
					fflush(stdin);
					
					printf("\nQual é a sua idade?");
					scanf("%d", &idade);
					if(idade > 120 || idade <= 0)
						printf("Idade não aceita!");
					else if(idade <= 14){
						printf("Na SALUMAR LINHAS AEREAS não permitimos que crianças(<16) reservem voôs");
						printf("\nCaso esteja acompanhado informe a idade do Responsável primeiro: ");
						scanf("%d", &responsavel);
						printf("\n(A idade do acompanhate e da criança será verificada no aeroporto)\n");
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
				printf("O seu número de indentificação é: %d", id);
				printf("\nO preço a pagar é: %.2f", preco);
				
				getch("");
				system("cls");
				
				break;
			case 3: 
				printf("==============================================");
				printf("\n%s", nome);
				printf("O seu número de indentificação é: %d\n", id);
				printf("==============================================");
				
				getch("");
				system("cls");
				
				break;
			case 4:
				printf("\nQual é o seu número de indentificação?");
				scanf("%d", &id);
				for(int i = 0; i < qntAssentos; i++){
					if((i + 1) == id)
						ocupacao[i] = 'D';
				}
				
				system("cls");
				
				break;
			case 5:
				
				printf("\nQual é o seu número de indentificação?");printf("(Para confimação uma reserva é necessário que haja uma reserva.)");
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
	
	//Interação com a empressa.
	
	getch("");
	system("cls");
	
	printf("QUANTIDADE DE ASSENTOS COM RESERVAS: %d", qntReserva);
	printf("\nQUANTIDADE DE VENDAS CONFIRMADAS: %d", qntConfi);
	
	qntDisp = qntAssentos - (qntReserva + qntConfi);
	
	printf("\nQUANTIDADE DE ASSENTOS DISPÓNIVEIS: %d", qntDisp);
		

	return 0;
	
}
