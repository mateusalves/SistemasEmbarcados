#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

//*********************************/
//CASO ALTERE A QUANTIDADE DE SLOTS .... ALTERAR AQUI

int	qtd_slots=24;

//*********************************/



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
int	checar_horario;



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

//*****************************************************************************/
//VARIAVEIS PARA LER AS HORAS DO SISTEMA
char	horario_sistema[9];
char	hora_sistema[1];
char	minuto_sistema[1];
char	minuto_anterior[1];	//fara a verificacao a cada minuto
int	hora_check=0;
int	minuto_check=0;

//*****************************************************************************/

char	leitura[10][400];
char	*result;

int 	qtdp=0;
int 	r_qtdp=-1;
int 	i=0;
int	j=0;
int	a=0;
int	selecao=0;
int	inicializacao=0;


int sistema();
int checar_dados();

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
		inicializacao=1;
	};

	fclose(pont_arq);


	while	(selecao!=5){
	
		sistema();
		
		if (checar_horario==1){
			strcpy(minuto_anterior,minuto_sistema);
			checar_dados();
		};

	};
	



	fclose(pont_arq);
	printf("\nARQUIVO FECHADO\n");	
	getchar();

	return (0);
}



int checar_dados(){

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
					char chamada2[50];
					char chamada3[50];

			

			//****************************
			//Checar horarios dos remédios
			if(hora_check==hora[qtdp-1][quantidade_remedio[qtdp][0]][0] && minuto_check==minuto[qtdp-1][quantidade_remedio[qtdp][0]][0] && slot[qtdp-1][quantidade_remedio[qtdp][0]][0]!=0){

					printf("\nO usuario %s deve tomar o remedio %s localizado no slot %d\n",usuario[qtdp-1],remedio[qtdp-1][quantidade_remedio[qtdp][0]], slot[qtdp-1][quantidade_remedio[qtdp][0]][0]);
					//INSERIR AQUI O COMANDO PARA A RASPBERRY =)))

					strcpy(chamada2,"./movNEMA ");
					strcat(chamada2,"12");
				
					system(chamada2);

					strcpy(chamada3,"./buz ");
					strcat(chamada3, usuario[qtdp-1]);
					strcat(chamada3," aa ");
					system(chamada3);

			};
			if(hora_check==hora[qtdp-1][quantidade_remedio[qtdp][0]][1] && minuto_check==minuto[qtdp-1][quantidade_remedio[qtdp][0]][1] && slot[qtdp-1][quantidade_remedio[qtdp][0]][0]!=0){

					printf("\nO usuario %s deve tomar o remedio %s localizado no slot %d\n",usuario[qtdp-1],remedio[qtdp-1][quantidade_remedio[qtdp][0]], slot[qtdp-1][quantidade_remedio[qtdp][0]][0]);
					//INSERIR AQUI O COMANDO PARA A RASPBERRY =)))
	strcpy(chamada2,"./movNEMA ");
					strcat(chamada2,"12");
				
					system(chamada2);

					strcpy(chamada3,"./buz ");
					strcat(chamada3, usuario[qtdp-1]);
					strcat(chamada3," aa ");
					system(chamada3);



			};
			if(hora_check==hora[qtdp-1][quantidade_remedio[qtdp][0]][2] && minuto_check==minuto[qtdp-1][quantidade_remedio[qtdp][0]][2] && slot[qtdp-1][quantidade_remedio[qtdp][0]][0]!=0){
				
					printf("\nO usuario %s deve tomar o remedio %s localizado no slot %d\n",usuario[qtdp-1],remedio[qtdp-1][quantidade_remedio[qtdp][0]], slot[qtdp-1][quantidade_remedio[qtdp][0]][0]);
					//INSERIR AQUI O COMANDO PARA A RASPBERRY =)))
	strcpy(chamada2,"./movNEMA ");
					strcat(chamada2,"12");
				
					system(chamada2);

					strcpy(chamada3,"./buz ");
					strcat(chamada3, usuario[qtdp-1]);
					strcat(chamada3," aa ");
					system(chamada3);


			};


				
			//****************************

			laco++;
			r_qtdp++;

  }

	inicializacao=1;
	fclose(pont_arq);
	return (0);


};



int sistema(){

	//_strtime(horario_sistema);

	char TimeString[128];
	time_t timer;
	struct tm *localtime(const time_t *timer);

	strftime(TimeString, 80, "%Y-%m-%d %H:%M:%S", localtime(&timer));



	hora_sistema[0]=horario_sistema[0];
	hora_sistema[1]=horario_sistema[1];
	hora_sistema[2]='\0';
	hora_check=atoi(hora_sistema);
	minuto_sistema[0]=horario_sistema[3];
	minuto_sistema[1]=horario_sistema[4];
	minuto_sistema[2]='\0';
	minuto_check=atoi(minuto_sistema);


	if(atoi(minuto_anterior)!=atoi(minuto_sistema)){
		checar_horario=1;	
	}else{
		checar_horario=0;
	};

	return(0);
};
