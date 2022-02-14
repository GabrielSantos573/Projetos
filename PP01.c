 //Nome completo:Gabriel Oliveira Santos. Matr�cula:UC21100452. Curso: Ci�ncia da computa��o.
 
#include<stdio.h>//biblioteca para printf e scanf
#include<stdlib.h> //biblioteca para limpar a tela 
#include<math.h>  //biblioteca para opera��es matem�ticas
#include<locale.h>//biblioteca para pra aceitar caracter especial:setlocale(LC_ALL, "Portuguese");
#include<string.h>//biblioteca para strlen e strcmp: http://linguagemc.com.br/a-biblioteca-string-h/
#include<ctype.h> //biblioteca para o uso do toupper e tolower: http://linguagemc.com.br/ctype-h-toupper-tolower-isalpha-isdigit-em-c/

int main(){
	setlocale(LC_ALL, "Portuguese");//para pra aceitar caracter especial:setlocale(LC_ALL, "Portuguese");
	
	char filme[60], sexo;//declara��o de variavers: string e char
	int idade, quantidade1,quantidade2, sessoes, sessao, i, maiorMasc, maiorFem, crianca = 0, adolescente = 0, adulto = 0, idoso = 0, crianca2 = 0, adolescente2 = 0, adulto2 = 0, idoso2 = 0, opcao, sexoM, sexoF;///declara��o de variavers que recebem numeros inteiros 
	
	do{//valida��o do nome do filme(n�o podendo ser vazio)
		printf("\nDiga o nome do filme: ");//comando de sa�da para o usu�rio digitar o nome do filme
		gets(filme);//comando de entrada para receber o nome do filme
		fflush(stdin);//comando pra limpar o buffer de memoria 
		if(strlen(filme) <=0)//condi��o n�o deixar o usu�rio deixar o campo vazio 
			printf("\nDigite um filme v�lido!");//mensagem de "erro" caso ele deixe vazio 
	}while(strlen(filme) <=0);//repetir enquanto ele n�o digitar o nome do filme 
	
	

	do{//valida��o do numero de sessoes
		printf("\nQuantas sess�es ouveram? R: ");//comando de sa�da para o usu�rio digitar o numero de sess�es
		scanf("%d", &sessoes);//comando para receber o numero de sess�es
		if(sessoes != 2)//comando para n�o deixar ser diferente de 2 as sess�es
			printf("\nNo nosso cinema fazemos 2 sess�es por filme ", filme);//mensagem de "erro" caso seja diferente de 2 
		else
			printf("Seus dados foram aceitos\n");//mensagem de sucesso
	}while(sessoes != 2);//repetir enquanto for diferente que 2 
	
	do{//valida��o da quantidade de pessoas por sess�o 
		printf("\nQuantas pessoas assistiram '%s' na primeira sess�o? R:", filme);//comando de sa�da para o usu�rio digitar a quanatidade de pessoas 
		scanf("%d", &quantidade1);//comando para receber a quanatidade de pessoas 
		if(quantidade1 < 10)//comando para n�o deixar ser menor que 10 a quanatidade de pessoas
		printf("Quantidade inv�lida, n�o fazemos sess�es com menos de 10 pessoas");//mensagem de "erro" caso seja menor que 10 
	}while(quantidade1 < 10);//repetir enquanto for menor que 10
	
	do{//valida��o da quantidade de pessoas por sess�o 
		printf("\nQuantas pessoas assistiram '%s' na segunda sess�o? R:", filme);//comando de sa�da para o usu�rio digitar a quanatidade de pessoas
		scanf("%d", &quantidade2);//comando para receber a quanatidade de pessoas 
		if(quantidade2 < 10)//comando para n�o deixar ser menor que 10 a quanatidade de pessoas
		printf("Quantidade inv�lida, n�o fazemos sess�es com menos de 10 pessoas ");//mensagem de "erro" caso seja menor que 10 
	}while(quantidade2 < 10);//repetir enquanto for menor que 10
	
//intera��o com o cliente

		printf("\nBem vindos ao Cineplace.");//intera��o com o usu�rio 
		printf("\n� com muito prazer que o recebemos na nossa primeira sess�o do filme '%s' e agradecemos por escolher o melhor do centroeste.\n", filme);
	
//SESS�O 1
		
	printf("\nEsperamos que tenha gostado do filme, agora precisamos que respondam a algumas perguntas.\n");//introdu��o a sess�o
	for(i=0; i < quantidade1; i++){//comando para repetir de acordo com a quantidades de pessoas(da primeira sess�o)
		do{
			printf("\nInfome o a sua idade:");
			fflush(stdin);
			scanf("%d", &idade);
			if(idade < 3 || idade > 100)
				printf("Idade n�o aceita!");
		}while(idade < 3 || idade > 100);
		
		do{
			printf("Infome o sexo: ");
			fflush(stdin);
			scanf("%c", &sexo);
			sexo = toupper(sexo);
			if(sexo != 'M' && sexo != 'm' && sexo != 'F' && sexo != 'f')
				printf("\nSexo inv�lido, Digite(M/F)\n");
		}while(sexo != 'M' && sexo != 'm' && sexo != 'F' && sexo != 'f');
		
		
		if(idade >= 3 && idade <= 13)//condi��o para incrementar o numero de crian�as cada vez que o usu�rio digite um valor entre 3 e 13(incluindo eles msms)
			crianca++;
		else if(idade >= 14 && idade <= 17)
		 	adolescente++;
		else if(idade >= 18 && idade <= 64)
			adulto++;
		else  if(idade >= 65 && idade <= 100)
			idoso++;
		
		if(sexo == 'M')//condi��o para incrementar o numero de pessoas pertencentes ao sexo masculino cada vez que o usu�rio digite M ou m 
			sexoM++;
		if(sexo == 'F')
			sexoF++;
			
		if(idade >= 18 && sexo == 'M')//condi��o para incrementar o numero de pessoas pertencentes ao sexo masculino cada vez que o usu�rio digite M ou m 
			maiorMasc++;              //e seja maior de idade.
		if(idade >= 18 && sexo == 'F')	
			maiorFem++;
				
	}
	
	fflush(stdin);
	
	printf("\nQuantidade de crian�as na primeira sess�o: %d", crianca);//comando de sa�da para mostras o numero de crian�as na primeira sess�o
	printf("\nQuantidade de adolescente na primeira sess�o: %d", adolescente);
	printf("\nQuantidade de adultos na primeira sess�o: %d", adulto);
	printf("\nQuantidade de idosos na primeira sess�o: %d\n", idoso);
	
//SESS�O 2

	printf("\nBem vindos ao Cineplace.");
	printf("\n� com muito prazer que o recebemos na nossa segunda sess�o do filme '%s' e agradecemos por escolher o melhor do centroeste.\n", filme);
	
	for(i=0; i < quantidade2; i++){
		do{
			printf("\nInfome o a sua idade:");
			scanf("%d", &idade);
			if(idade < 3 || idade > 100)
				printf("Idade n�o aceita!");
		}while(idade < 3 || idade > 100);
		
		do{
			printf("Infome o sexo: ");
			fflush(stdin);
			scanf("%c", &sexo);
			sexo = toupper(sexo);
			if(sexo != 'M' && sexo != 'm' && sexo != 'F' && sexo != 'f')
				printf("\nSexo inv�lido, Digite(M/F)\n");
		}while(sexo != 'M' && sexo != 'm' && sexo != 'F' && sexo != 'f');
		
		if(idade >= 3 && idade <= 13)
			crianca2++;
		else if(idade >= 14 && idade <= 17)
		 	adolescente2++;
		else if(idade >= 18 && idade <= 64)
			adulto2++;
		else  if(idade >= 65 && idade <= 100)
			idoso2++;
			
		if(sexo == 'M')
			sexoM++;
		if(sexo == 'F')
			sexoF++;
		if(idade >= 18 && sexo == 'M')
			maiorMasc++;
		if(idade >= 18 && sexo == 'F')	
			maiorFem++;		
	}	
	
	printf("Quantidade de crian�as na segunda sess�o: %d", crianca2);//comando de sa�da para mostras o numero de crian�as na primeira sess�o
	printf("\nQuantidade de adolescente na segunda sess�o: %d", adolescente2);
	printf("\nQuantidade de adultos na segunda sess�o: %d", adulto2);
	printf("\nQuantidade de idosos na segunda sess�o: %d\n", idoso2);
	
	
//Dados do dia(considerando as duas sess�es)
	
	getch("");//comando para s� limpar a tela quando der enter
	
	printf("\nDados considerando as duas sess�es:");
	
	system("cls");//comando para limpar a tela
	
	do{
	printf("\nDigite a op��o desejada: \n 1-Para saber o nome do filme, a quantidade de pessoas do sexo feminino e masculino que assistiram o filme;\n 2- Quatidade de pessoas separadas por faixa et�ria;\n 3- a quantidade de pessoas maiores de idade do sexo masculino e feminino que estiveram presentes; \n 4- Sair. \nR:");//comando de sa�da para o usu�rio escolher a op��p desejada
	scanf("%d", &opcao);
	switch(opcao){//comando de condi��o para criar 1 menu, de acordo com o que o usu�rio digite 
		case 1: printf("\nNome do filme: %s\n", filme);
				printf("\nQuantidade de pessoas do sexo feminino: %d", sexoF);
				printf("\nQuantidade de pessoas do sexo masculino: %d\n", sexoM);
				break;
				
		case 2: printf("\nQuantidade de crian�as: %d", (crianca2 + crianca));
				printf("\nQuantidade de adolescente: %d", (adolescente2 + adolescente));
				printf("\nQuantidade de adultos: %d", (adulto2 + adulto));
				printf("\nQuantidade de idosos: %d\n", (idoso2 + idoso));
				break;
				
		case 3: printf("\nQuantidade de adultos do sexo feminino: %d", maiorFem);
				printf("\nQuantidade de adultos do sexo masculino: %d\n", maiorMasc);
		
		case 4: printf("\nSair\n");
				
	}
	
	getch("");
	system("cls");
	
}while(opcao != 4);
	
	
	
	return 0;		
}
