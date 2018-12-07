#include <stdio.h>
#include <stdlib.h>
#include <string.h>


char	usuario[10][40];
int	idade[10];
int 	quantidade_remedio[10][1];
char	remedio[10][10][20];
int 	quantidade_dose[10][10][1];
int 	quantidade_horario[10][10][1];
int 	hora[10][10][3];
int 	minuto[10][10][3];
int	slot[10][40][1];
int	id[10][1];
int	id_slot=0;



char 	hora_lida1[1];
char 	minuto_lida1[1];
char 	hora_lida2[1];
char 	minuto_lida2[1];
char 	hora_lida4[1];
char 	minuto_lida4[1];
char	idade_lida[3];
char 	remedio_lida[3];
char 	dose_lida[3];
char	slot_lida[10];
char	id_lida[10];


char	leitura[10][400];
char	*result;

int 	qtdp=0;
int 	r_qtdp=-1;
int 	i=0;
int	j=0;
int	a=0;
int	selecao=0;
int	inicializacao=0;

int escrever_dados();
int ler_dados();
int mostar_dados();
int limpar_dados();
int chamar_codigo(int selecao);

//Criar ponteiro de arquivo
FILE *pont_arq;

int main(){



	//abre arquivo
	pont_arq=fopen("teste10.txt","r");

	if (pont_arq == NULL ){
		printf("\n****  arquivo nao existe ****\n");
		pont_arq=fopen("teste10.txt","w");

		//cabeçalho
		fprintf(pont_arq, "%s", "usuario");
		fprintf(pont_arq, "\t");
		fprintf(pont_arq, "%s", "ID");
		fprintf(pont_arq, "\t");
		fprintf(pont_arq, "%s", "idade");
		fprintf(pont_arq, "\t");
		fprintf(pont_arq, "%s", "Quantidade de remedios");
		fprintf(pont_arq, "\t");
		fprintf(pont_arq, "%s", "nome dos remedios");
		fprintf(pont_arq, "\t");
		fprintf(pont_arq, "%s", "Slot dos remedios");
		fprintf(pont_arq, "\t");
		fprintf(pont_arq, "%s", "Quantidade de dose");
		fprintf(pont_arq, "\t");
		fprintf(pont_arq, "%s", "horario 01");
		fprintf(pont_arq, "\t");
		fprintf(pont_arq, "%s", "horario 02");
		fprintf(pont_arq, "\t");
		fprintf(pont_arq, "%s", "horario 03");
		fprintf(pont_arq, "\n");
	
	}else{
		printf("\n****  arquivo aberto com sucesso ****\n");
		ler_dados();
		inicializacao=1;
	};

	fclose(pont_arq);


	while	(selecao!=5){
		while (selecao<1 || selecao>5){
			printf("\n****  Qual modo de operacao deseja ****\n");	
			printf("\n****  Ler banco de dados : 1 ****\n");
			printf("\n****  cadastrar dados : 2 ****\n");
			printf("\n****  Mostrar dados : 3 ****\n");
			printf("\n****  Limpar banco de dados : 4 ****\n");
			printf("\n****  Fechar programa : 5 ****\n");
			scanf("%d", &selecao);
		};

		printf("\nModo selecionado : %d\n", selecao);

		chamar_codigo(selecao);

		fclose(pont_arq);		

		if (selecao<5 && selecao!=0){
			selecao=0;
		};


	};
	



	fclose(pont_arq);
	printf("\nARQUIVO FECHADO\n");	
	getchar();

	return (0);
}

int escrever_dados(){

int qtd=0;
int mem;

pont_arq=fopen("teste10.txt","w");

//******************************************************************************************************************************
//prepara cabecalho do banco de dados
		fprintf(pont_arq, "%s", "usuario");
		fprintf(pont_arq, "\t");
		fprintf(pont_arq, "%s", "ID");
		fprintf(pont_arq, "\t");
		fprintf(pont_arq, "%s", "idade");
		fprintf(pont_arq, "\t");
		fprintf(pont_arq, "%s", "Quantidade de remedios");
		fprintf(pont_arq, "\t");
		fprintf(pont_arq, "%s", "nome dos remedios");
		fprintf(pont_arq, "\t");
		fprintf(pont_arq, "%s", "Slot dos remedios");
		fprintf(pont_arq, "\t");
		fprintf(pont_arq, "%s", "Quantidade de dose");
		fprintf(pont_arq, "\t");
		fprintf(pont_arq, "%s", "horario 01");
		fprintf(pont_arq, "\t");
		fprintf(pont_arq, "%s", "horario 02");
		fprintf(pont_arq, "\t");
		fprintf(pont_arq, "%s", "horario 03");
		fprintf(pont_arq, "\n");

//******************************************************************************************************************************



//******************************************************************************************************************************
//Inicio do cadastro de pacientes

	printf("\nEntre com a quantidade de pacientes: ");
	scanf("%d", &qtd);
	getchar();		

	mem=qtdp;
	qtdp=qtd+qtdp;	
		


	for (i=0;i<qtdp;i++){ //i = numero do paciente
		
		//***********************************************************
		//ZERAR VARIAVEIS TIPO CONTADORES DAS LOGICAS DE CADA USUARIO
		j=0;
		a=0;
		//***********************************************************

		//Nome do usuario
		if(i>=mem || inicializacao<1){	//garante a nao escrita sobre o dado anterior
			printf("\nEntre com o nome do usuario %d: ", (i+1));
			gets(usuario[i]);
		};
		fprintf(pont_arq, "%s", usuario[i]);
		fprintf(pont_arq, "\t");

		//ID do usuario
		if(i>=mem || inicializacao<1){	//garante a nao escrita sobre o dado anterior
			printf("\nUsuario de ID numero : %d", (i+1));
			id[i][0]=i+1;
			getchar();
		};
		fprintf(pont_arq, "%d", id[i][0]);
		fprintf(pont_arq, "\t");


		//Idade do usuario
		if(i>=mem || inicializacao<1){	//garante a nao escrita sobre o dado anterior
			printf("\nEntre com a idade do usuario %d: ", (i+1));
			scanf("%d", &idade[i]);getchar();
		};
		fprintf(pont_arq, "%d", idade[i]);
		fprintf(pont_arq, "\t");

		//Quantidade de remedio
		if(i>=mem || inicializacao<1){	//garante a nao escrita sobre o dado anterior
			printf("\nEntre com a quantidade de remedios do usuario %d: ", (i+1));
			scanf("%d", &quantidade_remedio[i][0]);getchar();
		};
		fprintf(pont_arq, "%d", quantidade_remedio[i][0]);
		fprintf(pont_arq, "\t");


		for(j=0;j<quantidade_remedio[i][0];j++){ //laço do remedio
		
			//Nome do remedio
			if(i>=mem || inicializacao<1){	//garante a nao escrita sobre o dado anterior
				printf("\nEntre com o nome do remedio %d do usuario %d: ", (j+1), (i+1));
				gets(remedio[i][j]);
			};
			fprintf(pont_arq, "%s", remedio[i][j]);
			fprintf(pont_arq, "\t");

			//Slot do remedio
			if(i>=mem || inicializacao<1){	//garante a nao escrita sobre o dado anterior
				id_slot++;
				slot[i][j][0]=id_slot;	
				printf("\nO slot do remedio %d do usuario %d: %d", (j+1), (i+1), slot[i][j][0]);
				getchar();
			};
			fprintf(pont_arq, "%d", slot[i][j][0]);
			fprintf(pont_arq, "\t");
			
			//Quantidade de dose do remedio
			if(i>=mem || inicializacao<1){	//garante a nao escrita sobre o dado anterior
				printf("\nEntre com a quantidade de dose do remedio %d do usuario %d: ", (j+1), (i+1));
				scanf("%d", &quantidade_dose[i][j][0]);getchar();
			};
			fprintf(pont_arq, "%d", quantidade_dose[i][j][0]);
			fprintf(pont_arq, "\t");

			//Quantidade de horarios do remedio
			if(i>=mem || inicializacao<1){	//garante a nao escrita sobre o dado anterior
				printf("\nEntre com a quantidade de horarios do remedio %d do usuario %d: ", (j+1), (i+1));
				scanf("%d", &quantidade_horario[i][j][0]);getchar();
			};

			for(a=0;a<quantidade_horario[i][j][0];a++){
				//Hora do remedio
				if(i>=mem || inicializacao<1){	//garante a nao escrita sobre o dado anterior
					printf("\nEntre com a hora %d do remedio %d do usuario %d: ", (a+1), (j+1), (i+1));
					scanf("%d", &hora[i][j][a]);getchar();
				};

				//Minuto do remedio
				if(i>=mem || inicializacao<1){	//garante a nao escrita sobre o dado anterior
					printf("\nEntre com o minuto %d do remedio %d do usuario %d: ", (a+1), (j+1), (i+1));
					scanf("%d", &minuto[i][j][a]);getchar();
				};
				fprintf(pont_arq, "%d:%d", hora[i][j][a], minuto[i][j][a]);
				fprintf(pont_arq, "\t");
			
			};

			if(j!=(quantidade_remedio[i][0]-1)){
				fprintf(pont_arq, "\n");
				fprintf(pont_arq, "\t\t\t\t");
			};

		};
		fprintf(pont_arq, "\n");
	};

//Fim do cadastro de pacientes		
//******************************************************************************************************************************

	inicializacao=1;
	fclose(pont_arq);

	return (0);
};

int ler_dados(){

//garantir variaveis zeradas
 	qtdp=0;
 	r_qtdp=-1;
 	i=0;
	j=0;
	a=0;
	id_slot=0;



int	cont=0;
int	copia=0;
int	mem[8];
int	horario=0;
int	laco=0;

pont_arq=fopen("teste10.txt","r");

  while (!feof(pont_arq))
  {
	// Lê uma linha (inclusive com o '\n')
	result = fgets(leitura[r_qtdp], 400, pont_arq);  // o 'fgets' lê até 400 caracteres ou até o '\n'
	if(strlen(leitura[r_qtdp])<10 && inicializacao==1){	//se o arquivo resetou o db ele resete inicializacao tbm
		inicializacao=0;
	};

	if (result){  // Se foi possível ler

	
		if(leitura[r_qtdp][0]!='\t' && laco>0){
			qtdp++;
			copia=0;	
			cont=0;
			mem[copia]=cont;

		};
		if(leitura[r_qtdp][0]=='\t' && leitura[r_qtdp][1]=='\t'){
			copia=3;	
			cont=3;
			mem[copia]=cont;
			quantidade_remedio[qtdp][0]=quantidade_remedio[qtdp][0]+1;
			strcpy(hora_lida1,"0");
			strcpy(minuto_lida1,"0");
			strcpy(hora_lida2,"0");
			strcpy(minuto_lida2,"0");
			strcpy(hora_lida4,"0");
			strcpy(minuto_lida4,"0");
			
		};


		while(leitura[r_qtdp][cont]!='\n' && r_qtdp!=-1 && strlen(leitura[r_qtdp])>10){
			

			if(leitura[r_qtdp][cont]!='\t'){
				switch (copia){
					case 0:
						usuario[qtdp-1][cont]=leitura[r_qtdp][cont];
		
					break;

					case 1:
						id_lida[cont-mem[copia]]=leitura[r_qtdp][cont];	//cont - mem elimina a posicao do \t e copia os caracteres
	
					break;


					case 2:
						if(atoi(id_lida)!=0){
							id[qtdp-1][0]=atoi(id_lida);	//grava a variavel
							strcpy(id_lida,"0");		//limpa a variavel
						};

						idade_lida[cont-mem[copia]]=leitura[r_qtdp][cont];	//cont - mem elimina a posicao do \t e copia os caracteres
	
					break;

					case 3:
						if(atoi(idade_lida)!=0){
							idade[qtdp-1]=atoi(idade_lida);	//grava a variavel
							strcpy(idade_lida,"0");		//limpa a variavel
						};

						remedio_lida[cont-mem[copia]]=leitura[r_qtdp][cont];

					break;

					case 4:
						if(atoi(remedio_lida)!=0){
							quantidade_remedio[qtdp-1][0]=atoi(remedio_lida);
							strcpy(remedio_lida,"0");
						};
						

						remedio[qtdp-1][quantidade_remedio[qtdp][0]][cont-mem[copia]]=leitura[r_qtdp][cont];
	
					break;

					case 5:
						slot_lida[cont-mem[copia]]=leitura[r_qtdp][cont];
	
					break;

					case 6:
						if(atoi(slot_lida)!=0){
							slot[qtdp-1][quantidade_remedio[qtdp][0]][0]=atoi(slot_lida);
							strcpy(slot_lida,"0");
							id_slot++;		//incrementa o id dos slots ocupados
						};

						dose_lida[cont-mem[copia]]=leitura[r_qtdp][cont];
	
					break;

					case 7:
						if(atoi(dose_lida)!=0){
							quantidade_dose[qtdp-1][quantidade_remedio[qtdp][0]][0]=atoi(dose_lida);
							strcpy(dose_lida,"0");
						};
						
						if(leitura[r_qtdp][cont]!=':'){
							if(horario==0){
								hora_lida1[cont-mem[copia]]=leitura[r_qtdp][cont];

							}else{
								minuto_lida1[cont-mem[copia]-3]=leitura[r_qtdp][cont];

							}
						}else{
							horario=1;
						};
						quantidade_horario[qtdp-1][quantidade_remedio[qtdp][0]][0]=1;	
					break;

					case 8:
						if(leitura[r_qtdp][cont]!=':'){
							if(horario==0){
								hora_lida2[cont-mem[copia]]=leitura[r_qtdp][cont];

							}else{
								minuto_lida2[cont-mem[copia]-3]=leitura[r_qtdp][cont];

							}
						}else{
							horario=1;
						};	
						quantidade_horario[qtdp-1][quantidade_remedio[qtdp][0]][0]=2;
					break;

					case 9:
						if(leitura[r_qtdp][cont]!=':'){
							if(horario==0){
								hora_lida4[cont-mem[copia]]=leitura[r_qtdp][cont];

							}else{
								minuto_lida4[cont-mem[copia]-3]=leitura[r_qtdp][cont];

							}
						}else{
							horario=1;
						};	
						quantidade_horario[qtdp-1][quantidade_remedio[qtdp][0]][0]=3;
					break;


				}
			}else{
				copia++;
				mem[copia]=cont+1;
				horario=0;
			}
			
			cont++;
			
		}
	}
	

			//****************************
			//conversao das horas para int
			hora[qtdp-1][quantidade_remedio[qtdp][0]][0]=atoi(hora_lida1);
			minuto[qtdp-1][quantidade_remedio[qtdp][0]][0]=atoi(minuto_lida1);
			hora[qtdp-1][quantidade_remedio[qtdp][0]][1]=atoi(hora_lida2);
			minuto[qtdp-1][quantidade_remedio[qtdp][0]][1]=atoi(minuto_lida2);
			hora[qtdp-1][quantidade_remedio[qtdp][0]][2]=atoi(hora_lida4);
			minuto[qtdp-1][quantidade_remedio[qtdp][0]][2]=atoi(minuto_lida4);				
			//****************************

			laco++;
			r_qtdp++;

  }

	inicializacao=1;
	fclose(pont_arq);
	return (0);


};

int mostar_dados(){

printf("\n\nLeitura dos dados\n\n");
getchar();
int i=0;


//******************************************************************************************************************************
//Inicio do leitura do cadastro de pacientes		

	for (i=0;i<qtdp;i++){ //i = numero do paciente
		
		//***********************************************************
		//ZERAR VARIAVEIS TIPO CONTADORES DAS LOGICAS DE CADA USUARIO
		j=0;
		a=0;
		//***********************************************************

		//Nome do usuario
		printf("\nO nome do usuario %d e: %s", (i+1), usuario[i]);
		getchar();

		//ID do usuario
		printf("\nO usuario %d e: %d", (i+1), id[i][0]);
		getchar();

		//Idade do usuario
		printf("\nA idade do usuario %d e: %d anos", (i+1), idade[i]);
		getchar();

		//Quantidade de remedio
		printf("\nA quantidade de remedios do usuario %d e: %d ", (i+1), quantidade_remedio[i][0]);
		getchar();

		for(j=0;j<quantidade_remedio[i][0];j++){ //laço do remedio
		
			//Nome do remedio
			printf("\nO nome do remedio %d do usuario %d e: %s", (j+1), (i+1), remedio[i][j]);
			getchar();

			//Slot do remedio
			printf("\nO slot do remedio %d do usuario %d e: %d", (j+1), (i+1), slot[i][j][0]);
			getchar();
			
			//Quantidade de dose do remedio
			printf("\nA quantidade de dose do remedio %d do usuario %d e: %d", (j+1), (i+1), quantidade_dose[i][j][0]);
			getchar();

			//Quantidade de horarios do remedio
			printf("\nA quantidade de horarios do remedio %d do usuario %d e: %d", (j+1), (i+1), quantidade_horario[i][j][0]);
			getchar();

			for(a=0;a<quantidade_horario[i][j][0];a++){
				//Hora do remedio
				printf("\nO horario %d do remedio %d do usuario %d e: %d : %d", (a+1), (j+1), (i+1), hora[i][j][a], minuto[i][j][a]);
				getchar();
			
			};



		};
		


	};

//Fim da leitura do cadastro de pacientes		
//******************************************************************************************************************************


	return (0);
};

int limpar_dados(){
pont_arq=fopen("teste10.txt","w");

//******************************************************************************************************************************
//prepara cabecalho do banco de dados
		fprintf(pont_arq, "%s", "usuario");
		fprintf(pont_arq, "\t");
		fprintf(pont_arq, "%s", "idade");
		fprintf(pont_arq, "\t");
		fprintf(pont_arq, "%s", "Quantidade de remedios");
		fprintf(pont_arq, "\t");
		fprintf(pont_arq, "%s", "nome dos remedios");
		fprintf(pont_arq, "\t");
		fprintf(pont_arq, "%s", "Quantidade de dose");
		fprintf(pont_arq, "\t");
		fprintf(pont_arq, "%s", "horario 01");
		fprintf(pont_arq, "\t");
		fprintf(pont_arq, "%s", "horario 02");
		fprintf(pont_arq, "\t");
		fprintf(pont_arq, "%s", "horario 03");
		fprintf(pont_arq, "\n");
//******************************************************************************************************************************

	fclose(pont_arq);
	return (0);
};


int chamar_codigo(int selecao){


	switch (selecao){
		case 1:
			ler_dados();
		break;
		case 2:
			escrever_dados();
		break;
		case 3:
			mostar_dados();
		break;
		case 4:
			limpar_dados();
		break;
	};

	return (0);
};
