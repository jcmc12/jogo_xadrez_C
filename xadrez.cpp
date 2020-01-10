#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<windows.h>
#include<time.h>
#include<locale.h>
#include<string.h>

int jog=0,troc1=0,troc2=0;

void tabuleiro_apresentacao();
void par_impar(int op, int a,char nome_jogador1[],char nome_jogador2[]);
void adicionar_pecas_tabuleiro(char tabuleiro_jogar[][8]);
void posicao_pecas_tabuleiro(char tabuleiro_jogar[][8],char nome_jogador1[],char nome_jogador2[]);
void peao(int jogador1_linha_atual,int jogador1_coluna_atual,int jogador1_linha_mover,int jogador1_coluna_mover,
		  int aa,int bb,char tabuleiro_jogar[][8],int *continuar,char peca,int cc,int dd,int ee,int ff,int gg,
		  char nome_jogador1[],char nome_jogador2[]);
void torre(int jogador1_linha_atual,int jogador1_coluna_atual,int jogador1_linha_mover,int jogador1_coluna_mover,
		   int tt,int ttt,char tabuleiro_jogar[][8],int *continuar,int contador_torre,int z,char nome_jogador1[],char nome_jogador2[]);
void cavalo(int jogador1_linha_atual,int jogador1_coluna_atual,int jogador1_linha_mover,int jogador1_coluna_mover,
	        int tt,int ttt,char tabuleiro_jogar[][8],int *continuar,char nome_jogador1[],char nome_jogador2[]);
void bispo1(int jogador1_linha_atual,int jogador1_coluna_atual,int jogador1_linha_mover,int jogador1_coluna_mover,
			int tt,int ttt,char tabuleiro_jogar[][8],int *continuar,char nome_jogador1[],char nome_jogador2[],int z,int contador_torre);
void bispo2(int jogador1_linha_atual,int jogador1_coluna_atual,int jogador1_linha_mover,int jogador1_coluna_mover,
			int tt,int ttt,char tabuleiro_jogar[][8],int *continuar,char nome_jogador1[],char nome_jogador2[],int z,int contador_torre);
void rainha(int jogador1_linha_atual,int jogador1_coluna_atual,int jogador1_linha_mover,int jogador1_coluna_mover,
		    int tt,int ttt,char tabuleiro_jogar[][8],int *continuar,int contador_torre,int z,char nome_jogador1[],char nome_jogador2[]);
void rei(int jogador1_linha_atual,int jogador1_coluna_atual,int jogador1_linha_mover,int jogador1_coluna_mover,
		 char tabuleiro_jogar[][8],int *continuar,int tt,int ttt,char nome_jogador1[],char nome_jogador2[]);
int resultado1(char tabuleiro_jogar[][8]);
int resultado2(char tabuleiro_jogar[][8]);

void peao2(int jogador1_linha_atual,int jogador1_coluna_atual,int jogador1_linha_mover,int jogador1_coluna_mover,
		  int aa,int bb,char tabuleiro_jogar[][8],int *continuar,char peca,int cc,int dd,int ee,int ff,int gg,
		  char nome_jogador1[],char nome_jogador2[]);
bool verifica(char tabuleiro_jogar[][8],char peca);

int main(void)
{
	char apresentacao[33]="Seja Bem-vindo ao jogo de Xadrez",nome_jogador1[30],nome_jogador2[30];
	int i=0,op=0,j=0;
	int resultado_jogador1=0;
	
//-----------------------------------------------------------------------------------------------//
	
	                    //1) Tela de apresentação do jogo de Xadrez

//-----------------------------------------------------------------------------------------------//	
	
	system("Color 0E");
	
	printf("\t\t ");
	
	for(i=0;i<33;i++)
	{
		Sleep(90);
		printf("%c",apresentacao[i]);
	}
	
	printf("\n\n");
	tabuleiro_apresentacao();
	printf("\n\n\t\t  Pressione ENTER para iniciar");
	
	getch();
	system("cls");
	
//-----------------------------------------------------------------------------------------------//
	
	                //2) Entrada com os nomes dos jogadores e Sorteio

//-----------------------------------------------------------------------------------------------//	
	
	setlocale(LC_ALL,"Portuguese");
	
	printf("Nome do jogador: ");
	gets(nome_jogador1);
	printf("Nome do jogador: ");
	gets(nome_jogador2);
	
	printf("\n\n\t Escolha uma das opções para decidir quem irá começar\n\n");
	printf("\t        [1] %s - PAR   e %s - ÍMPAR\n",nome_jogador1,nome_jogador2);
	printf("\t        [2] %s - ÍMPAR e %s - PAR\n\n",nome_jogador1,nome_jogador2);
	
	printf("Opção: ");
	scanf("%d",&op);
	
	srand(time(NULL));
	int a=0;
	a=rand()%100;
	
	par_impar(op,a,nome_jogador1,nome_jogador2);
	getch();
	
	system("cls");
	
//-----------------------------------------------------------------------------------------------//
	
	                //3) Tela onde irá ocorrer o jogo de Xadrez

//-----------------------------------------------------------------------------------------------//	
	
	// declaração de variáveis que farão parte dessa tela
	char tabuleiro_jogar[8][8],peca; 
	int inicio=1,jogador1=1,jogador2=2,continuar=1,contador_torre=0,tt=0,ttt=0;
	int jogador1_linha_atual=0,jogador1_coluna_atual=0,jogador1_linha_mover=0,jogador1_coluna_mover=0;
	int aa=0,bb=0,cc=0,dd=0,ee=0,ff=0,gg=0,z=0,d=0,quebrar=1,resp1=0,resp2=0;
	
	//função que adiciona as peças no tabuleiro antes de começar o jogo no laço principal 
	adicionar_pecas_tabuleiro(tabuleiro_jogar);
		
	while(inicio==1)//Laço maior que irá controlar o jogo (principal)
	{
		system("cls");//limpa tela
		posicao_pecas_tabuleiro(tabuleiro_jogar,nome_jogador1,nome_jogador2);//exibe as peças no tabuleiro junto com os nomes
		quebrar=1;
		
		if(jogador1==1) //condicional para o primeiro jogador jogar
		{
						
			do //laço do menu
			{
				system("cls");
				posicao_pecas_tabuleiro(tabuleiro_jogar,nome_jogador1,nome_jogador2);
				fflush(stdin);
				printf("\n\n\t       %s, sua vez de jogar\n",nome_jogador1);
				printf("\n\t        [P]-Peão");
				printf("\n\t        [T]-Torre"); //menu referente as peças do primeiro jogador
				printf("\n\t        [C]-Cavalo"); 
				printf("\n\t        [B]-Bispo casa Preta");
				printf("\n\t        [b]-Bispo casa Branca");
				printf("\n\t        [R]-Rainha"); 
				printf("\n\t        [W]-Rei\n\n");
			
				printf("\n\t        Peça: ");
				fflush(stdin);
				scanf("%c",&peca);
			
				switch(peca) //com base na escolha da peça um movimento irá ocorrer
				{
					case 'P':
					continuar=1;
					bb=0;cc=1;dd=1;ee=1;ff=-1;gg=0;
					troc1=0;
														
					do //Esse laço serve para controlar se as coordenadas atuais das peças foram entre 0 - 7
					{
						jog=1;
						system("cls");
						posicao_pecas_tabuleiro(tabuleiro_jogar,nome_jogador1,nome_jogador2);
						printf("\n\n\t\tEntre com as coordenadas atuais da peça\n\n");
						printf("\t\tLinha: ");
						scanf("%d",&jogador1_linha_atual);
						printf("\t\tColuna: ");
						scanf("%d",&jogador1_coluna_atual);
						
						if((jogador1_linha_atual<0)||(jogador1_linha_atual>7)||(jogador1_coluna_atual<0)||(jogador1_coluna_atual>7))
						{
							printf("\n\t\t A linha e coluna devem estar entre 0 e 7!\n");
							getch();
						}
						
					}while((jogador1_linha_atual<0)||(jogador1_linha_atual>7)||(jogador1_coluna_atual<0)||(jogador1_coluna_atual>7));
					
					//Esse teste condicional é para garantir que não selecione outra peça diferente da sua
					if(tabuleiro_jogar[jogador1_linha_atual][jogador1_coluna_atual]=='P') 
					{
						do// laço que controla a jogada
						{
							aa=1;bb=0;cc=1;dd=1;ee=1;ff=-1;gg=0;
							system("cls");
							posicao_pecas_tabuleiro(tabuleiro_jogar,nome_jogador1,nome_jogador2);
							
							printf("\n\n\t\tEntre com as coordenadas para mover a peça escolhida\n");
							printf("\t           A linha e coluna devem estar entre 0 e 7!\n\n");
							printf("\t\tLinha: ");
							scanf("%d",&jogador1_linha_mover);
							printf("\t\tColuna: ");
							scanf("%d",&jogador1_coluna_mover);
							
							if((jogador1_linha_atual-jogador1_linha_mover==2)&&(jogador1_linha_atual==6))
							{
								aa=2;
							}
							else
							{
								aa=1;
							}
														
							peao(jogador1_linha_atual,jogador1_coluna_atual,jogador1_linha_mover,jogador1_coluna_mover,
					         aa,bb,tabuleiro_jogar,&continuar,peca,cc,dd,ee,ff,gg,nome_jogador1,nome_jogador2);
							
						}while(continuar==1);
						
					}
					else //caso  coordenada da sua peça não seja o seu peão irá aparecer essa mensagem
					{
						printf("\n\n\t\tEssa coordenada não corresponde ao seu Peão");
						printf("\n\t\t  Pressione ENTER para retornar ao menu");
						getch();
					}
					break;
				
					case 'T':
						continuar=1;
						contador_torre=0;
						z=0;
					
						do
						{
							jog=1;
							system("cls");
							posicao_pecas_tabuleiro(tabuleiro_jogar,nome_jogador1,nome_jogador2);
							printf("\n\n\t\tEntre com as coordenadas atuais da peça\n\n");
							printf("\t\tLinha: ");
							scanf("%d",&jogador1_linha_atual);
							printf("\t\tColuna: ");
							scanf("%d",&jogador1_coluna_atual);
						
							if((jogador1_linha_atual<0)||(jogador1_linha_atual>7)||(jogador1_coluna_atual<0)||(jogador1_coluna_atual>7))
							{
								printf("\n\t\t A linha e coluna devem estar entre 0 e 7!\n");
								getch();
							}
						
						}while((jogador1_linha_atual<0)||(jogador1_linha_atual>7)||(jogador1_coluna_atual<0)||(jogador1_coluna_atual>7));
				
						if(tabuleiro_jogar[jogador1_linha_atual][jogador1_coluna_atual]=='T')
						{
							do
							{
								contador_torre=0;
								z=0;
								continuar=1;
								system("cls");
								posicao_pecas_tabuleiro(tabuleiro_jogar,nome_jogador1,nome_jogador2);
								
								printf("\n\n\t\tEntre com as coordenadas para mover a peça escolhida\n");
								printf("\t           A linha e coluna devem estar entre 0 e 7!\n\n");
								printf("\t\tLinha: ");
								scanf("%d",&jogador1_linha_mover);
								printf("\t\tColuna: ");
								scanf("%d",&jogador1_coluna_mover);
						
								torre(jogador1_linha_atual,jogador1_coluna_atual,jogador1_linha_mover,jogador1_coluna_mover,
					          	      tt,ttt,tabuleiro_jogar,&continuar,contador_torre,z,nome_jogador1,nome_jogador2);
							
							}while(continuar==1);
						}
						else
						{
							printf("\n\n\t\tEssa coordenada não corresponde a sua Torre");
							printf("\n\t\t  Pressione ENTER para retornar ao menu");
							getch();
						}
						break;
				
					case 'C':
					
						continuar=1;
					
						do
						{
							jog=1;
							system("cls");
							posicao_pecas_tabuleiro(tabuleiro_jogar,nome_jogador1,nome_jogador2);
							printf("\n\n\t\tEntre com as coordenadas atuais da peça\n\n");
							printf("\t\tLinha: ");
							scanf("%d",&jogador1_linha_atual);
							printf("\t\tColuna: ");
							scanf("%d",&jogador1_coluna_atual);
						
							if((jogador1_linha_atual<0)||(jogador1_linha_atual>7)||(jogador1_coluna_atual<0)||(jogador1_coluna_atual>7))
							{
								printf("\n\t\t A linha e coluna devem estar entre 0 e 7!\n");
								getch();
							}
						
						}while((jogador1_linha_atual<0)||(jogador1_linha_atual>7)||(jogador1_coluna_atual<0)||(jogador1_coluna_atual>7));
					
					
						if(tabuleiro_jogar[jogador1_linha_atual][jogador1_coluna_atual]=='C')
						{
							do
							{
								continuar=1;
								tt=0;ttt=0;
								system("cls");
								posicao_pecas_tabuleiro(tabuleiro_jogar,nome_jogador1,nome_jogador2);
								
								printf("\n\n\t\tEntre com as coordenadas para mover a peça escolhida\n");
								printf("\t           A linha e coluna devem estar entre 0 e 7!\n\n");
								printf("\t\tLinha: ");
								scanf("%d",&jogador1_linha_mover);
								printf("\t\tColuna: ");
								scanf("%d",&jogador1_coluna_mover);
						
								cavalo(jogador1_linha_atual,jogador1_coluna_atual,jogador1_linha_mover,jogador1_coluna_mover,
					                   tt,ttt,tabuleiro_jogar,&continuar,nome_jogador1,nome_jogador2);
					           
							}while(continuar==1);
						}
						else
						{
							printf("\n\n\t\tEssa coordenada não corresponde ao seu Cavalo");
							printf("\n\t\t  Pressione ENTER para retornar ao menu");
							getch();
						}
						break;
				
					case 'B':
					
						continuar=1;
						contador_torre=0;
						z=1;tt=0;ttt=0;
					
						do
						{
						
							jog=1;
							system("cls");
							posicao_pecas_tabuleiro(tabuleiro_jogar,nome_jogador1,nome_jogador2);
							printf("\n\n\t\tEntre com as coordenadas atuais da peça\n\n");
							printf("\t\tLinha: ");
							scanf("%d",&jogador1_linha_atual);
							printf("\t\tColuna: ");
							scanf("%d",&jogador1_coluna_atual);
						
												
							if((jogador1_linha_atual<0)||(jogador1_linha_atual>7)||(jogador1_coluna_atual<0)||(jogador1_coluna_atual>7))
							{
								printf("\n\t\t A linha e coluna devem estar entre 0 e 7!\n");
								getch();
							}
						
						}while((jogador1_linha_atual<0)||(jogador1_linha_atual>7)||(jogador1_coluna_atual<0)||(jogador1_coluna_atual>7));
					
						if(tabuleiro_jogar[jogador1_linha_atual][jogador1_coluna_atual]=='B')
						{
							do
							{
								system("cls");
								posicao_pecas_tabuleiro(tabuleiro_jogar,nome_jogador1,nome_jogador2);
								continuar=1;
								contador_torre=0;
								z=1;tt=0;ttt=0;
								
								printf("\n\n\t\tEntre com as coordenadas para mover a peça escolhida\n");
								printf("\t           A linha e coluna devem estar entre 0 e 7!\n\n");
								printf("\t\tLinha: ");
								scanf("%d",&jogador1_linha_mover);
								printf("\t\tColuna: ");
								scanf("%d",&jogador1_coluna_mover);
						
								bispo1(jogador1_linha_atual,jogador1_coluna_atual,jogador1_linha_mover,jogador1_coluna_mover,
					               	   tt,ttt,tabuleiro_jogar,&continuar,nome_jogador1,nome_jogador2,z,contador_torre);
																		
							}while(continuar==1);
						}
						else
						{
							printf("\n\n\t\tEssa coordenada não corresponde ao seu Bispo");
							printf("\n\t\t   Pressione ENTER para retornar ao menu");
							getch();
						}
						break;
				
					case 'b':
					
						continuar=1;
						contador_torre=0;
						z=1;tt=0;ttt=0;
					
						do
						{
					
							jog=1;
							system("cls");
							posicao_pecas_tabuleiro(tabuleiro_jogar,nome_jogador1,nome_jogador2);
							printf("\n\n\t\tEntre com as coordenadas atuais da peça\n\n");
							printf("\t\tLinha: ");
							scanf("%d",&jogador1_linha_atual);
							printf("\t\tColuna: ");
							scanf("%d",&jogador1_coluna_atual);
																	
							if((jogador1_linha_atual<0)||(jogador1_linha_atual>7)||(jogador1_coluna_atual<0)||(jogador1_coluna_atual>7))
							{
								printf("\n\t\t A linha e coluna devem estar entre 0 e 7!\n");
								getch();
							}
						
						}while((jogador1_linha_atual<0)||(jogador1_linha_atual>7)||(jogador1_coluna_atual<0)||(jogador1_coluna_atual>7));
					
						if(tabuleiro_jogar[jogador1_linha_atual][jogador1_coluna_atual]=='b')
						{
							do
							{
								system("cls");
								posicao_pecas_tabuleiro(tabuleiro_jogar,nome_jogador1,nome_jogador2);
								continuar=1;
								contador_torre=0;
								z=1;tt=0;ttt=0;
								
								printf("\n\n\t\tEntre com as coordenadas para mover a peça escolhida\n");
								printf("\t           A linha e coluna devem estar entre 0 e 7!\n\n");
								printf("\t\tLinha: ");
								scanf("%d",&jogador1_linha_mover);
								printf("\t\tColuna: ");
								scanf("%d",&jogador1_coluna_mover);
														
								bispo2(jogador1_linha_atual,jogador1_coluna_atual,jogador1_linha_mover,jogador1_coluna_mover,
					           	       tt,ttt,tabuleiro_jogar,&continuar,nome_jogador1,nome_jogador2,z,contador_torre);
						
							}while(continuar==1);	
						}
						else
						{
							printf("\n\n\t\tEssa coordenada não corresponde ao seu Bispo");
							printf("\n\t\t  Pressione ENTER para retornar ao menu");
							getch();
						}
						break;
				
					case 'R':
						continuar=1;
						contador_torre=0;
						z=0;tt=0;ttt=0;
					
						do
						{
							jog=1;
							system("cls");
							posicao_pecas_tabuleiro(tabuleiro_jogar,nome_jogador1,nome_jogador2);
							printf("\n\n\t\tEntre com as coordenadas atuais da peça\n\n");
							printf("\t\tLinha: ");
							scanf("%d",&jogador1_linha_atual);
							printf("\t\tColuna: ");
							scanf("%d",&jogador1_coluna_atual);
																	
							if((jogador1_linha_atual<0)||(jogador1_linha_atual>7)||(jogador1_coluna_atual<0)||(jogador1_coluna_atual>7))
							{
								printf("\n\t\t A linha e coluna devem estar entre 0 e 7!\n");
								getch();
							}
						
						}while((jogador1_linha_atual<0)||(jogador1_linha_atual>7)||(jogador1_coluna_atual<0)||(jogador1_coluna_atual>7));
					
					
						if(tabuleiro_jogar[jogador1_linha_atual][jogador1_coluna_atual]=='R')
						{
							do
							{
						
								system("cls");
								posicao_pecas_tabuleiro(tabuleiro_jogar,nome_jogador1,nome_jogador2);
								continuar=1;
								contador_torre=0;
								z=0;tt=0;ttt=0;
								
								printf("\n\n\t\tEntre com as coordenadas para mover a peça escolhida\n");
								printf("\t           A linha e coluna devem estar entre 0 e 7!\n\n");
								printf("\t\tLinha: ");
								scanf("%d",&jogador1_linha_mover);
								printf("\t\tColuna: ");
								scanf("%d",&jogador1_coluna_mover);
						
								rainha(jogador1_linha_atual,jogador1_coluna_atual,jogador1_linha_mover,jogador1_coluna_mover,
		    				           tt,ttt,tabuleiro_jogar,&continuar,contador_torre,z,nome_jogador1,nome_jogador2);
																	
							}while(continuar==1);
						}
						else
						{
							printf("\n\n\t\tEssa coordenada não corresponde a sua Rainha");
							printf("\n\t\t  Pressione ENTER para retornar ao menu");
							getch();
						}
						break;
					
					case 'W':
					
						continuar=1;
						contador_torre=0;
						z=0;tt=0;ttt=0;
					
						do
						{
							jog=1;
							system("cls");
							posicao_pecas_tabuleiro(tabuleiro_jogar,nome_jogador1,nome_jogador2);
							printf("\n\n\t\tEntre com as coordenadas atuais da peça\n\n");
							printf("\t\tLinha: ");
							scanf("%d",&jogador1_linha_atual);
							printf("\t\tColuna: ");
							scanf("%d",&jogador1_coluna_atual);
																	
							if((jogador1_linha_atual<0)||(jogador1_linha_atual>7)||(jogador1_coluna_atual<0)||(jogador1_coluna_atual>7))
							{
								printf("\n\t\t A linha e coluna devem estar entre 0 e 7!\n");
								getch();
							}
						
						}while((jogador1_linha_atual<0)||(jogador1_linha_atual>7)||(jogador1_coluna_atual<0)||(jogador1_coluna_atual>7));
					
						if(tabuleiro_jogar[jogador1_linha_atual][jogador1_coluna_atual]=='W')
						{
							do
							{
								system("cls");
								posicao_pecas_tabuleiro(tabuleiro_jogar,nome_jogador1,nome_jogador2);
								continuar=1;
								tt=0;ttt=0;
								
								printf("\n\n\t\tEntre com as coordenadas para mover a peça escolhida\n");
								printf("\t           A linha e coluna devem estar entre 0 e 7!\n\n");
								printf("\t\tLinha: ");
								scanf("%d",&jogador1_linha_mover);
								printf("\t\tColuna: ");
								scanf("%d",&jogador1_coluna_mover);
							
								rei(jogador1_linha_atual,jogador1_coluna_atual,jogador1_linha_mover,jogador1_coluna_mover,
							    	tabuleiro_jogar,&continuar,tt,ttt,nome_jogador1,nome_jogador2);
							
							}while(continuar==1);
						}
						else
						{
							printf("\n\n\t\tEssa coordenada não corresponde ao seu Rei");
							printf("\n\t\t  Pressione ENTER para retornar ao menu");
							getch();
						}
						break;
				
					default:
						printf("\n\n\t\t       Opção inválida\n");
						printf("\n\n\t\tPressione ENTER para fazer a jogada");
						getch();
					
				}
				
				//esse teste condicional verifica que a peça ocupa o local que foi informado. Caso isso aconteca, o laço do menu se quebra								
				if(tabuleiro_jogar[jogador1_linha_mover][jogador1_coluna_mover]==peca)
				{
					quebrar=0;
				}
				else
				{
					quebrar=1;
				}
				
			}while(quebrar==1&&troc1==0);
		}
						
		resp1=resultado1(tabuleiro_jogar);//chamada da função para verificar se o jogador derrubou o rei do jogador 2
						
		if(resp1==1)
		{
			inicio=1;
		}
		else //caso o rei tenha sido derrubado, o jogador é anunciado como vencedor e o laço principal se quebra
		{
			system("cls");
			posicao_pecas_tabuleiro(tabuleiro_jogar,nome_jogador1,nome_jogador2);
			printf("\n\n\t\t\t%s, você ganhou o duelo!",nome_jogador1);
			jogador2=0;
			break;
		}
		
		quebrar=1;
		
		if(jogador2==2)//os comentários do jogador equivalem para o jogador 2
		{
						
			do
			{
				system("cls");
				posicao_pecas_tabuleiro(tabuleiro_jogar,nome_jogador1,nome_jogador2);
				fflush(stdin);
				printf("\n\n\t       %s, sua vez de jogar\n",nome_jogador2);
				printf("\n\t        [A]-Peão");
				printf("\n\t        [J]-Torre"); 
				printf("\n\t        [K]-Cavalo"); 
				printf("\n\t        [L]-Bispo casa Preta");
				printf("\n\t        [l]-Bispo casa Branca");
				printf("\n\t        [M]-Rainha"); 
				printf("\n\t        [N]-Rei\n\n");
			
				printf("\n\t        Peça: ");
				fflush(stdin);
				scanf("%c",&peca);
			
				switch(peca)
				{
					case 'A':
					continuar=1;
					bb=0;cc=-1;dd=1;ee=-1;ff=-1;gg=7;
					troc2==0;
														
					do
					{
						jog=2;
						system("cls");
						posicao_pecas_tabuleiro(tabuleiro_jogar,nome_jogador1,nome_jogador2);
						printf("\n\n\t\tEntre com as coordenadas atuais da peça\n\n");
						printf("\t\tLinha: ");
						scanf("%d",&jogador1_linha_atual);
						printf("\t\tColuna: ");
						scanf("%d",&jogador1_coluna_atual);
						
						if((jogador1_linha_atual<0)||(jogador1_linha_atual>7)||(jogador1_coluna_atual<0)||(jogador1_coluna_atual>7))
						{
							printf("\n\t\t A linha e coluna devem estar entre 0 e 7!\n");
							getch();
						}
						
					}while((jogador1_linha_atual<0)||(jogador1_linha_atual>7)||(jogador1_coluna_atual<0)||(jogador1_coluna_atual>7));
					
					if(tabuleiro_jogar[jogador1_linha_atual][jogador1_coluna_atual]=='A')
					{
						do
						{
							aa=-1;bb=0;cc=-1;dd=1;ee=-1;ff=-1;gg=7;
							system("cls");
							posicao_pecas_tabuleiro(tabuleiro_jogar,nome_jogador1,nome_jogador2);
							
							printf("\n\n\t\tEntre com as coordenadas para mover a peça escolhida\n");
							printf("\t           A linha e coluna devem estar entre 0 e 7!\n\n");
							printf("\t\tLinha: ");
							scanf("%d",&jogador1_linha_mover);
							printf("\t\tColuna: ");
							scanf("%d",&jogador1_coluna_mover);
							
							if((jogador1_linha_atual-jogador1_linha_mover==-2)&&(jogador1_linha_atual==1))
							{
								aa=-2;
							}
							else
							{
								aa=-1;
							}
													
							peao2(jogador1_linha_atual,jogador1_coluna_atual,jogador1_linha_mover,jogador1_coluna_mover,
					         aa,bb,tabuleiro_jogar,&continuar,peca,cc,dd,ee,ff,gg,nome_jogador1,nome_jogador2);
							
						}while(continuar==1);
						
					}
					else
					{
						printf("\n\n\t\tEssa coordenada não corresponde ao seu Peão");
						printf("\n\t\t  Pressione ENTER para retornar ao menu");
						getch();
					}
					break;
				
					case 'J':
						continuar=1;
						contador_torre=0;
						z=0;
					
						do
						{
							jog=2;
							system("cls");
							posicao_pecas_tabuleiro(tabuleiro_jogar,nome_jogador1,nome_jogador2);
							printf("\n\n\t\tEntre com as coordenadas atuais da peça\n\n");
							printf("\t\tLinha: ");
							scanf("%d",&jogador1_linha_atual);
							printf("\t\tColuna: ");
							scanf("%d",&jogador1_coluna_atual);
						
							if((jogador1_linha_atual<0)||(jogador1_linha_atual>7)||(jogador1_coluna_atual<0)||(jogador1_coluna_atual>7))
							{
								printf("\n\t\t A linha e coluna devem estar entre 0 e 7!\n");
								getch();
							}
						
						}while((jogador1_linha_atual<0)||(jogador1_linha_atual>7)||(jogador1_coluna_atual<0)||(jogador1_coluna_atual>7));
				
						if(tabuleiro_jogar[jogador1_linha_atual][jogador1_coluna_atual]=='J')
						{
							do
							{
								contador_torre=0;
								z=0;
								continuar=1;
								system("cls");
								posicao_pecas_tabuleiro(tabuleiro_jogar,nome_jogador1,nome_jogador2);
								
								printf("\n\n\t\tEntre com as coordenadas para mover a peça escolhida\n");
								printf("\t           A linha e coluna devem estar entre 0 e 7!\n\n");
								printf("\t\tLinha: ");
								scanf("%d",&jogador1_linha_mover);
								printf("\t\tColuna: ");
								scanf("%d",&jogador1_coluna_mover);
						
								torre(jogador1_linha_atual,jogador1_coluna_atual,jogador1_linha_mover,jogador1_coluna_mover,
					          	      tt,ttt,tabuleiro_jogar,&continuar,contador_torre,z,nome_jogador1,nome_jogador2);
							
							}while(continuar==1);
						}
						else
						{
							printf("\n\n\t\tEssa coordenada não corresponde a sua Torre");
							printf("\n\t\t  Pressione ENTER para retornar ao menu");
							getch();
						}
						break;
				
					case 'K':
					
						continuar=1;
					
						do
						{
							jog=2;
							system("cls");
							posicao_pecas_tabuleiro(tabuleiro_jogar,nome_jogador1,nome_jogador2);
							printf("\n\n\t\tEntre com as coordenadas atuais da peça\n\n");
							printf("\t\tLinha: ");
							scanf("%d",&jogador1_linha_atual);
							printf("\t\tColuna: ");
							scanf("%d",&jogador1_coluna_atual);
						
							if((jogador1_linha_atual<0)||(jogador1_linha_atual>7)||(jogador1_coluna_atual<0)||(jogador1_coluna_atual>7))
							{
								printf("\n\t\t A linha e coluna devem estar entre 0 e 7!\n");
								getch();
							}
						
						}while((jogador1_linha_atual<0)||(jogador1_linha_atual>7)||(jogador1_coluna_atual<0)||(jogador1_coluna_atual>7));
					
					
						if(tabuleiro_jogar[jogador1_linha_atual][jogador1_coluna_atual]=='K')
						{
							do
							{
								continuar=1;
								tt=0;ttt=0;
								system("cls");
								posicao_pecas_tabuleiro(tabuleiro_jogar,nome_jogador1,nome_jogador2);
								
								printf("\n\n\t\tEntre com as coordenadas para mover a peça escolhida\n");
								printf("\t           A linha e coluna devem estar entre 0 e 7!\n\n");
								printf("\t\tLinha: ");
								scanf("%d",&jogador1_linha_mover);
								printf("\t\tColuna: ");
								scanf("%d",&jogador1_coluna_mover);
						
								cavalo(jogador1_linha_atual,jogador1_coluna_atual,jogador1_linha_mover,jogador1_coluna_mover,
					                   tt,ttt,tabuleiro_jogar,&continuar,nome_jogador1,nome_jogador2);
					           
							}while(continuar==1);
						}
						else
						{
							printf("\n\n\t\tEssa coordenada não corresponde ao seu Cavalo");
							printf("\n\t\t  Pressione ENTER para retornar ao menu");
							getch();
						}
						break;
				
					case 'L':
					
						continuar=1;
						contador_torre=0;
						z=1;tt=0;ttt=0;
					
						do
						{
						
							jog=2;
							system("cls");
							posicao_pecas_tabuleiro(tabuleiro_jogar,nome_jogador1,nome_jogador2);
							printf("\n\n\t\tEntre com as coordenadas atuais da peça\n\n");
							printf("\t\tLinha: ");
							scanf("%d",&jogador1_linha_atual);
							printf("\t\tColuna: ");
							scanf("%d",&jogador1_coluna_atual);
						
												
							if((jogador1_linha_atual<0)||(jogador1_linha_atual>7)||(jogador1_coluna_atual<0)||(jogador1_coluna_atual>7))
							{
								printf("\n\t\t A linha e coluna devem estar entre 0 e 7!\n");
								getch();
							}
						
						}while((jogador1_linha_atual<0)||(jogador1_linha_atual>7)||(jogador1_coluna_atual<0)||(jogador1_coluna_atual>7));
					
						if(tabuleiro_jogar[jogador1_linha_atual][jogador1_coluna_atual]=='L')
						{
							do
							{
								system("cls");
								posicao_pecas_tabuleiro(tabuleiro_jogar,nome_jogador1,nome_jogador2);
								continuar=1;
								contador_torre=0;
								z=1;tt=0;ttt=0;
								
								printf("\n\n\t\tEntre com as coordenadas para mover a peça escolhida\n");
								printf("\t           A linha e coluna devem estar entre 0 e 7!\n\n");
								printf("\t\tLinha: ");
								scanf("%d",&jogador1_linha_mover);
								printf("\t\tColuna: ");
								scanf("%d",&jogador1_coluna_mover);
						
								bispo1(jogador1_linha_atual,jogador1_coluna_atual,jogador1_linha_mover,jogador1_coluna_mover,
					               	   tt,ttt,tabuleiro_jogar,&continuar,nome_jogador1,nome_jogador2,z,contador_torre);
																		
							}while(continuar==1);
						}
						else
						{
							printf("\n\n\t\tEssa coordenada não corresponde ao seu Bispo");
							printf("\n\t\t   Pressione ENTER para retornar ao menu");
							getch();
						}
						break;
				
					case 'l':
					
						continuar=1;
						contador_torre=0;
						z=1;tt=0;ttt=0;
					
						do
						{
					
							jog=2;
							system("cls");
							posicao_pecas_tabuleiro(tabuleiro_jogar,nome_jogador1,nome_jogador2);
							printf("\n\n\t\tEntre com as coordenadas atuais da peça\n\n");
							printf("\t\tLinha: ");
							scanf("%d",&jogador1_linha_atual);
							printf("\t\tColuna: ");
							scanf("%d",&jogador1_coluna_atual);
																	
							if((jogador1_linha_atual<0)||(jogador1_linha_atual>7)||(jogador1_coluna_atual<0)||(jogador1_coluna_atual>7))
							{
								printf("\n\t\t A linha e coluna devem estar entre 0 e 7!\n");
								getch();
							}
						
						}while((jogador1_linha_atual<0)||(jogador1_linha_atual>7)||(jogador1_coluna_atual<0)||(jogador1_coluna_atual>7));
					
						if(tabuleiro_jogar[jogador1_linha_atual][jogador1_coluna_atual]=='l')
						{
							do
							{
								system("cls");
								posicao_pecas_tabuleiro(tabuleiro_jogar,nome_jogador1,nome_jogador2);
								continuar=1;
								contador_torre=0;
								z=1;tt=0;ttt=0;
								
								printf("\n\n\t\tEntre com as coordenadas para mover a peça escolhida\n");
								printf("\t           A linha e coluna devem estar entre 0 e 7!\n\n");
								printf("\t\tLinha: ");
								scanf("%d",&jogador1_linha_mover);
								printf("\t\tColuna: ");
								scanf("%d",&jogador1_coluna_mover);
														
								bispo2(jogador1_linha_atual,jogador1_coluna_atual,jogador1_linha_mover,jogador1_coluna_mover,
					           	       tt,ttt,tabuleiro_jogar,&continuar,nome_jogador1,nome_jogador2,z,contador_torre);
						
							}while(continuar==1);	
						}
						else
						{
							printf("\n\n\t\tEssa coordenada não corresponde ao seu Bispo");
							printf("\n\t\t  Pressione ENTER para retornar ao menu");
							getch();
						}
						break;
				
					case 'M':
						continuar=1;
						contador_torre=0;
						z=0;tt=0;ttt=0;
					
						do
						{
							jog=2;
							system("cls");
							posicao_pecas_tabuleiro(tabuleiro_jogar,nome_jogador1,nome_jogador2);
							printf("\n\n\t\tEntre com as coordenadas atuais da peça\n\n");
							printf("\t\tLinha: ");
							scanf("%d",&jogador1_linha_atual);
							printf("\t\tColuna: ");
							scanf("%d",&jogador1_coluna_atual);
																	
							if((jogador1_linha_atual<0)||(jogador1_linha_atual>7)||(jogador1_coluna_atual<0)||(jogador1_coluna_atual>7))
							{
								printf("\n\t\t A linha e coluna devem estar entre 0 e 7!\n");
								getch();
							}
						
						}while((jogador1_linha_atual<0)||(jogador1_linha_atual>7)||(jogador1_coluna_atual<0)||(jogador1_coluna_atual>7));
					
					
						if(tabuleiro_jogar[jogador1_linha_atual][jogador1_coluna_atual]=='M')
						{
							do
							{
						
								system("cls");
								posicao_pecas_tabuleiro(tabuleiro_jogar,nome_jogador1,nome_jogador2);
								continuar=1;
								contador_torre=0;
								z=0;tt=0;ttt=0;
								
								printf("\n\n\t\tEntre com as coordenadas para mover a peça escolhida\n");
								printf("\t           A linha e coluna devem estar entre 0 e 7!\n\n");
								printf("\t\tLinha: ");
								scanf("%d",&jogador1_linha_mover);
								printf("\t\tColuna: ");
								scanf("%d",&jogador1_coluna_mover);
						
								rainha(jogador1_linha_atual,jogador1_coluna_atual,jogador1_linha_mover,jogador1_coluna_mover,
		    				           tt,ttt,tabuleiro_jogar,&continuar,contador_torre,z,nome_jogador1,nome_jogador2);
																	
							}while(continuar==1);
						}
						else
						{
							printf("\n\n\t\tEssa coordenada não corresponde a sua Rainha");
							printf("\n\t\t  Pressione ENTER para retornar ao menu");
							getch();
						}
						break;
					
					case 'N':
					
						continuar=1;
						contador_torre=0;
						z=0;tt=0;ttt=0;
					
						do
						{
							jog=2;
							system("cls");
							posicao_pecas_tabuleiro(tabuleiro_jogar,nome_jogador1,nome_jogador2);
							printf("\n\n\t\tEntre com as coordenadas atuais da peça\n\n");
							printf("\t\tLinha: ");
							scanf("%d",&jogador1_linha_atual);
							printf("\t\tColuna: ");
							scanf("%d",&jogador1_coluna_atual);
																	
							if((jogador1_linha_atual<0)||(jogador1_linha_atual>7)||(jogador1_coluna_atual<0)||(jogador1_coluna_atual>7))
							{
								printf("\n\t\t A linha e coluna devem estar entre 0 e 7!\n");
								getch();
							}
						
						}while((jogador1_linha_atual<0)||(jogador1_linha_atual>7)||(jogador1_coluna_atual<0)||(jogador1_coluna_atual>7));
					
						if(tabuleiro_jogar[jogador1_linha_atual][jogador1_coluna_atual]=='W')
						{
							do
							{
								system("cls");
								posicao_pecas_tabuleiro(tabuleiro_jogar,nome_jogador1,nome_jogador2);
								continuar=1;
								tt=0;ttt=0;
								
								printf("\n\n\t\tEntre com as coordenadas para mover a peça escolhida\n");
								printf("\t           A linha e coluna devem estar entre 0 e 7!\n\n");
								printf("\t\tLinha: ");
								scanf("%d",&jogador1_linha_mover);
								printf("\t\tColuna: ");
								scanf("%d",&jogador1_coluna_mover);
							
								rei(jogador1_linha_atual,jogador1_coluna_atual,jogador1_linha_mover,jogador1_coluna_mover,
							    	tabuleiro_jogar,&continuar,tt,ttt,nome_jogador1,nome_jogador2);
							
							}while(continuar==1);
						}
						else
						{
							printf("\n\n\t\tEssa coordenada não corresponde ao seu Rei");
							printf("\n\t\t  Pressione ENTER para retornar ao menu");
							getch();
						}
						break;
				
					default:
						printf("\n\n\t\t       Opção inválida\n");
						printf("\n\n\t\tPressione ENTER para fazer a jogada");
						getch();
					
				}
							
				if(tabuleiro_jogar[jogador1_linha_mover][jogador1_coluna_mover]==peca)
				{
					quebrar=0;
				}
				else
				{
					quebrar=1;
				}
				
			}while(quebrar==1&&troc2==0);
		}
		
		resp2=resultado2(tabuleiro_jogar);
						
		if(resp2==1)
		{
			inicio=1;
		}
		else
		{
			system("cls");
			posicao_pecas_tabuleiro(tabuleiro_jogar,nome_jogador1,nome_jogador2);
			printf("\n\n\t\t\t%s, você ganhou o duelo!",nome_jogador2);
			jogador1=0;
			break;
		}
		
							
	//	getch();		
	}
			
	printf("\n\n\n");
	system("pause");
	return (0);
}



void tabuleiro_apresentacao(void){

	int x,y;
	
	for(y=1;y<9;y++)
	{
		printf("\t\t        ");
		
		for(x=1;x<9;x++)
		{
			if((x+y)%2==0)
			{
				Sleep(90);
				printf("\xDB\xDB");
				
			}
			else
			{
				Sleep(90);
				printf("  ");
			}
		}
		printf("\n");
	}	
	
}

void par_impar(int op, int a,char nome_jogador1[],char nome_jogador2[]){
	
	char aux[30];
	
	if(op==1)
	{
		
		if(a%2==0)
		{
			printf("\n\tNÚMERO SORTEADO: %d\n\n",a);
			printf("\n\t%s, você será o primeiro a jogar",nome_jogador1);
			printf("\n\tSuas peças estão posicionadas na linha 6 e 7 do tabuleiro");
			
			printf("\n\n\t%s, você será o segundo a jogar",nome_jogador2);
			printf("\n\tSuas peças estão posicionadas na linha 0 e 1 do tabuleiro");
		
		}
		else
		{
			strcpy(aux, nome_jogador1);
			strcpy(nome_jogador1,nome_jogador2);
			strcpy(nome_jogador2,aux);
			
			printf("\n\tNÚMERO SORTEADO: %d\n\n",a);
			printf("\n\t%s, você será o primeiro a jogar",nome_jogador1);
			printf("\n\tSuas peças estão posicionadas na linha 6 e 7 do tabuleiro");
			
			printf("\n\n\t%s, você será o segundo a jogar",nome_jogador2);
			printf("\n\tSuas peças estão posicionadas na linha 0 e 1 do tabuleiro");
		
		}
		
	}
	
	if(op==2)
	{
		
		if(a%2==0)
		{
			strcpy(aux, nome_jogador1);
			strcpy(nome_jogador1,nome_jogador2);
			strcpy(nome_jogador2,aux);
			
			printf("\n\tNÚMERO SORTEADO: %d\n\n",a);
			printf("\n\t%s, você será o primeiro a jogar",nome_jogador1);
			printf("\n\tSuas peças estão posicionadas na linha 6 e 7 do tabuleiro");
			
			printf("\n\n\t%s, você será o segundo a jogar",nome_jogador2);
			printf("\n\tSuas peças estão posicionadas na linha 0 e 1 do tabuleiro");
			
		}
		else
		{
			printf("\n\tNÚMERO SORTEADO: %d\n\n",a);
			printf("\n\t%s, você será o primeiro a jogar",nome_jogador1);
			printf("\n\tSuas peças estão posicionadas na linha 6 e 7 do tabuleiro");
			
			printf("\n\n\t%s, você será o segundo a jogar",nome_jogador2);
			printf("\n\tSuas peças estão posicionadas na linha 0 e 1 do tabuleiro");
		}
		
	}
}

void adicionar_pecas_tabuleiro(char tabuleiro_jogar[][8]){
	
	int i=0,j=0;
	
	for(i=0;i<8;i++)
	{
		tabuleiro_jogar[1][i]='A';
		tabuleiro_jogar[6][i]='P';
	}
	
	tabuleiro_jogar[7][0]='T'; tabuleiro_jogar[7][7]='T';
	
	tabuleiro_jogar[7][1]='C'; tabuleiro_jogar[7][6]='C';
	
	tabuleiro_jogar[7][2]='B'; tabuleiro_jogar[7][5]='b';
	
	tabuleiro_jogar[7][3]='R'; tabuleiro_jogar[7][4]='W';
	
	tabuleiro_jogar[0][0]='J'; tabuleiro_jogar[0][7]='J';
	
	tabuleiro_jogar[0][1]='K'; tabuleiro_jogar[0][6]='K';
	
	tabuleiro_jogar[0][2]='l'; tabuleiro_jogar[0][5]='L';
	
	tabuleiro_jogar[0][3]='M'; tabuleiro_jogar[0][4]='N';
	
	
	for(i=2;i<=5;i++)
	{
		for(j=0;j<8;j++)
		{
			tabuleiro_jogar[i][j]=' ';
		}
	}
	
	//tabuleiro_jogar[1][3]='A';
	//tabuleiro_jogar[6][3]='P';
	
}

void posicao_pecas_tabuleiro(char tabuleiro_jogar[][8],char nome_jogador1[],char nome_jogador2[]){
	
	int i=0,j=0;
	
	printf("\n\n\t                     %s x %s",nome_jogador1,nome_jogador2);
	
	printf("\n\n\n\t       L\\C");
	
	for(i=0;i<8;i++)
	{
		printf("  %d  ",i);
	}
	
	printf("\n\n");
		
	for(i=0;i<8;i++)
    {
    	printf("\t        %d ",i);
    	
		for(j=0;j<8;j++)
    	{
    		printf(" |%c| ",tabuleiro_jogar[i][j]);
    		
		}
		
		printf("\n\t       -------------------------------------------",tabuleiro_jogar[i][j]);
		printf("\n");
	}
	
	//printf("\n\n\t%s, [P]-Peão [T]-Torre [C]-Cavalo [B]-Bispo [R]-Rainha [W]-Rei",nome_jogador1);
	//printf("\n\n\t%s, [A]-Peão [J]-Torre [K]-Cavalo [L]-Bispo [M]-Rainha [N]-Rei\n",nome_jogador2);
}

void peao(int jogador1_linha_atual,int jogador1_coluna_atual,int jogador1_linha_mover,int jogador1_coluna_mover,
		  int aa,int bb,char tabuleiro_jogar[][8],int *continuar,char peca,int cc,int dd,int ee,int ff,int gg,
		  char nome_jogador1[],char nome_jogador2[]){

	
	int i=0,j=0,s=0,controle=1;

						
	if((jogador1_linha_atual-jogador1_linha_mover==aa)&&(jogador1_coluna_atual-jogador1_coluna_mover==bb))
	{
		for(i=0;i<8;i++)
		{
			if(jogador1_linha_mover==i)
			{
				for(j=0;j<8;j++)
				{
					if(jogador1_coluna_mover==j)
					{
						if(tabuleiro_jogar[i][j]==' ')
						{
							tabuleiro_jogar[i][j]='P';
							tabuleiro_jogar[i+aa][j]=' ';
							*continuar=0;
																		
							if(jogador1_linha_mover==gg)
							{
								
								do
								{
								
									printf("\n\n\t\tTroca de peça\n\n");
									printf("\t\t[T]Torre [C]Cavalo [B]Bispo [b]Bispo [R]Rainha [N]Não troca\n\n");
									printf("\n\t        Peça: ");
									fflush(stdin);
									scanf("%c",&peca);
													
									switch(peca)
									{
										case 'T':
											
											if(verifica(tabuleiro_jogar,peca))
											{
												tabuleiro_jogar[i][j]='T';
												*continuar=0;
												troc1=1;
												controle=0;
											}
											else
											{
												printf("\n\n\t\tNão se pode escolher essa peça");
												getch();
											}
											break;
										
										case 'C':
											
											if(verifica(tabuleiro_jogar,peca))
											{
												tabuleiro_jogar[i][j]='C';
												*continuar=0;
												troc1=1;
												controle=0;
											}
											else
											{
												printf("\n\n\t\tNão se pode escolher essa peça");
												getch();
											}
											break;
										
										case 'B':
											
											if(verifica(tabuleiro_jogar,peca))
											{
												tabuleiro_jogar[i][j]='B';
												*continuar=0;
												troc1=1;
												controle=0;
											}
											else
											{
												printf("\n\n\t\tNão se pode escolher essa peça");
												getch();
											}
											break;
										
										case 'b':
											
											if(verifica(tabuleiro_jogar,peca))
											{
												tabuleiro_jogar[i][j]='b';
												*continuar=0;
												troc1=1;
												controle=0;
											}
											else
											{
												printf("\n\n\t\tNão se pode escolher essa peça");
												getch();
											}
											break;
										
										case 'R':
											
											if(verifica(tabuleiro_jogar,peca))
											{
												tabuleiro_jogar[i][j]='R';
												*continuar=0;
												troc1=1;
												controle=0;
											}
											else
											{
												printf("\n\n\t\tNão se pode escolher essa peça");
												getch();
											}
											break;
										
										case 'N':
																							
											tabuleiro_jogar[i][j]='P';
											troc1=1;
											controle=0;
											break;
									
										default:
											printf("\n\n\t\topção inválida");
											getch();
									}
								}while(controle==1);
							}
												
						}
						else
						{
							printf("\n\n\t\t  Essa jogada não é permitida");
							getch();
							*continuar=0;
						}
					}
				}
			}
		}
	}
	else
	{
		if(((jogador1_linha_atual-jogador1_linha_mover==cc)&&(jogador1_coluna_atual-jogador1_coluna_mover==dd))||
		   ((jogador1_linha_atual-jogador1_linha_mover==ee)&&(jogador1_coluna_atual-jogador1_coluna_mover==ff)))
		{	
			for(i=0;i<8;i++)
			{
				if(jogador1_linha_mover==i)
				{
					for(j=0;j<8;j++)
					{
						if(jogador1_coluna_mover==j)
						{	
							if(tabuleiro_jogar[i][j]=='A'||tabuleiro_jogar[i][j]=='J'||tabuleiro_jogar[i][j]=='K'||
							   tabuleiro_jogar[i][j]=='L'||tabuleiro_jogar[i][j]=='M'||tabuleiro_jogar[i][j]=='N'||
							   tabuleiro_jogar[i][j]=='l')
							{
								if(ee==jogador1_linha_atual-jogador1_linha_mover && ff==jogador1_coluna_atual-jogador1_coluna_mover)
								{
									if(tabuleiro_jogar[i][j]=='N')
									{
										s++;
									}
									
									tabuleiro_jogar[i][j]='P';
									tabuleiro_jogar[i+1][j-1]=' ';
									*continuar=0;
																		
								}
								if(cc==jogador1_linha_atual-jogador1_linha_mover && dd==jogador1_coluna_atual-jogador1_coluna_mover)
								{
									if(tabuleiro_jogar[i][j]=='N')
									{
										s++;
									}
																		
									tabuleiro_jogar[i][j]='P';
									tabuleiro_jogar[i+1][j+1]=' ';
									*continuar=0;
								}
																					
								if(jogador1_linha_mover==gg && s==0)
								{
									do
									{
																													
										printf("\n\n\t\tTroca de peça\n\n");
										printf("\t\t[T]Torre [C]Cavalo [B]Bispo [b]Bispo [R]Rainha [N]Não troca\n\n");
										printf("\n\t        Peça: ");
										fflush(stdin);
										scanf("%c",&peca);
																																				
										switch(peca)
										{
																						
											case 'T':
												
												if(verifica(tabuleiro_jogar,peca))
												{
													tabuleiro_jogar[i][j]='T';
													*continuar=0;
													troc1=1;
													controle=0;
												}
												else
												{
													printf("\n\n\t\tNão se pode escolher essa peça");
													getch();
												}
												break;
										
											case 'C':
												
												if(verifica(tabuleiro_jogar,peca))
												{
													tabuleiro_jogar[i][j]='C';
													*continuar=0;
													troc1=1;
													controle=0;
												}
												else
												{
													printf("\n\n\t\tNão se pode escolher essa peça");
													getch();
												}
												break;
											
											case 'B':
												
												if(verifica(tabuleiro_jogar,peca))
												{
													tabuleiro_jogar[i][j]='B';
													*continuar=0;
													troc1=1;
													controle=0;
												}
												else
												{
													printf("\n\n\t\tNão se pode escolher essa peça");
													getch();
												}
												break;
											
											case 'b':
											
											if(verifica(tabuleiro_jogar,peca))
											{
												tabuleiro_jogar[i][j]='b';
												*continuar=0;
												troc1=1;
												controle=0;
											}
											else
											{
												printf("\n\n\t\tNão se pode escolher essa peça");
												getch();
											}
											break;
										
											case 'R':
												
												if(verifica(tabuleiro_jogar,peca))
												{
													tabuleiro_jogar[i][j]='R';
													*continuar=0;
													troc1=1;
													controle=0;
												}
												else
												{
													printf("\n\n\t\tNão se pode escolher essa peça");
													getch();
												}
												break;
											
											case 'N':
																							
												tabuleiro_jogar[i][j]='P';
												troc1=1;
												controle=0;
												break;
										
											default:
												printf("\n\n\t\topção inválida");
												getch();
										}
									}while(controle==1);
								}
													
							}
							else
							{
								printf("\n\n\t\t  Essa jogada não é permitida");
								getch();
								*continuar=0;
							}
						}
					}
				}	
			}
		}
		else
		{
			printf("\n\n\t     Não se pode utilizar essa coordenada para mover essa peça");
			getch();
			*continuar=0;
		}
	}							  	
}

void torre(int jogador1_linha_atual,int jogador1_coluna_atual,int jogador1_linha_mover,int jogador1_coluna_mover,
int tt,int ttt,char tabuleiro_jogar[][8],int *continuar,int contador_torre,int z,char nome_jogador1[],char nome_jogador2[]){

	int i=0,j=0;
	
							
	if(((jogador1_linha_atual-jogador1_linha_mover>=1)&&(jogador1_linha_atual-jogador1_linha_mover<=7)) &&
	   ((jogador1_coluna_atual-jogador1_coluna_mover==0)))
    {
																
		for(i=jogador1_linha_mover+1;i<=jogador1_linha_atual-1;i++)
		{
						
			if(tabuleiro_jogar[i][jogador1_coluna_mover]==' ')
			{
				contador_torre++;//movimento para cima
			}
			z++;
		}
							
		tt=jogador1_linha_mover;
		ttt=jogador1_coluna_mover;
							
		if(z==contador_torre)
		{
			if((tabuleiro_jogar[tt][ttt]=='A'||tabuleiro_jogar[tt][ttt]=='J'||tabuleiro_jogar[tt][ttt]=='K'||
			   tabuleiro_jogar[tt][ttt]=='L'||tabuleiro_jogar[tt][ttt]=='M'||tabuleiro_jogar[tt][ttt]=='N'||
			   tabuleiro_jogar[tt][ttt]==' '||tabuleiro_jogar[tt][ttt]=='l')&&(jog==1))
			{
				tabuleiro_jogar[tt][ttt]='T';
				tabuleiro_jogar[jogador1_linha_atual][jogador1_coluna_atual]=' ';
				*continuar=0;	
			}
			else
			{
				if((tabuleiro_jogar[tt][ttt]=='P'||tabuleiro_jogar[tt][ttt]=='T'||tabuleiro_jogar[tt][ttt]=='C'||
				   tabuleiro_jogar[tt][ttt]=='B'||tabuleiro_jogar[tt][ttt]=='R'||tabuleiro_jogar[tt][ttt]=='W'||
				   tabuleiro_jogar[tt][ttt]==' '||tabuleiro_jogar[tt][ttt]=='b')&&(jog==2))
				{
					tabuleiro_jogar[tt][ttt]='J';
					tabuleiro_jogar[jogador1_linha_atual][jogador1_coluna_atual]=' ';
					*continuar=0;	
				}
				else
				{
					printf("\n\n\t\tNão pode atacar as sua próprias peças");
					*continuar=0;
					getch();
				}
			
			}
		}
		else
		{
			printf("\n\n\t\tNão se pode fazer jogada porque não há espaço para locomover");
			getch();
			*continuar=0;
		}
	}
	else
	{
		if(((jogador1_linha_atual-jogador1_linha_mover<=-1)&&(jogador1_linha_atual-jogador1_linha_mover>=-7)) &&
		   ((jogador1_coluna_atual-jogador1_coluna_mover==0)))
		{
			for(i=jogador1_linha_mover-1;i<=jogador1_linha_atual+1;i--)
			{
				if(tabuleiro_jogar[i][jogador1_coluna_mover]==' ')
				{
					contador_torre++; //movimento para baixo
				}
				z++;
			}
								
			tt=jogador1_linha_mover;
			ttt=jogador1_coluna_mover;
								
			if(z==contador_torre)
			{
				if((tabuleiro_jogar[tt][ttt]=='A'||tabuleiro_jogar[tt][ttt]=='J'||tabuleiro_jogar[tt][ttt]=='K'||
				   tabuleiro_jogar[tt][ttt]=='L'||tabuleiro_jogar[tt][ttt]=='M'||tabuleiro_jogar[tt][ttt]=='N'||
				   tabuleiro_jogar[tt][ttt]==' '||tabuleiro_jogar[tt][ttt]=='l')&&(jog==1))
				{
					tabuleiro_jogar[tt][ttt]='T';
					tabuleiro_jogar[jogador1_linha_atual][jogador1_coluna_atual]=' ';
					*continuar=0;	
				}
				else
				{
					if((tabuleiro_jogar[tt][ttt]=='P'||tabuleiro_jogar[tt][ttt]=='T'||tabuleiro_jogar[tt][ttt]=='C'||
					   tabuleiro_jogar[tt][ttt]=='B'||tabuleiro_jogar[tt][ttt]=='R'||tabuleiro_jogar[tt][ttt]=='W'||
					   tabuleiro_jogar[tt][ttt]==' '||tabuleiro_jogar[tt][ttt]=='b')&&(jog==2))
					{
						tabuleiro_jogar[tt][ttt]='J';
						tabuleiro_jogar[jogador1_linha_atual][jogador1_coluna_atual]=' ';
						*continuar=0;	
					}
					else
					{
						printf("\n\n\t\tNão pode atacar as sua próprias peças");
						*continuar=0;
						getch();
					}
				}
			}
			else
			{
				printf("\n\n\t\tNão se pode fazer jogada porque não há espaço para locomover");
				getch();
				*continuar=0;
			}
								
		}
		else
		{
			if(((jogador1_coluna_atual-jogador1_coluna_mover<=-1)&&(jogador1_coluna_atual-jogador1_coluna_mover>=-7)) &&
			   ((jogador1_linha_atual-jogador1_linha_mover==0)))
			{
			    for(i=jogador1_coluna_mover-1;i>=jogador1_coluna_atual+1;i--)
				{
					if(tabuleiro_jogar[jogador1_linha_mover][i]==' ')
					{
						contador_torre++; //movimento para direita
					}
					z++;
				}
									
				tt=jogador1_linha_mover;
				ttt=jogador1_coluna_mover;
									
				if(z==contador_torre)
				{
					if((tabuleiro_jogar[tt][ttt]=='A'||tabuleiro_jogar[tt][ttt]=='J'||tabuleiro_jogar[tt][ttt]=='K'||
					   tabuleiro_jogar[tt][ttt]=='L'||tabuleiro_jogar[tt][ttt]=='M'||tabuleiro_jogar[tt][ttt]=='N'||
					   tabuleiro_jogar[tt][ttt]==' '||tabuleiro_jogar[tt][ttt]=='l')&&(jog==1))
					{
						tabuleiro_jogar[tt][ttt]='T';
						tabuleiro_jogar[jogador1_linha_atual][jogador1_coluna_atual]=' ';
						*continuar=0;	
					}
					else
					{
						if((tabuleiro_jogar[tt][ttt]=='P'||tabuleiro_jogar[tt][ttt]=='T'||tabuleiro_jogar[tt][ttt]=='C'||
						   tabuleiro_jogar[tt][ttt]=='B'||tabuleiro_jogar[tt][ttt]=='R'||tabuleiro_jogar[tt][ttt]=='W'||
						   tabuleiro_jogar[tt][ttt]==' '||tabuleiro_jogar[tt][ttt]=='b')&&(jog==2))
						{
							tabuleiro_jogar[tt][ttt]='J';
							tabuleiro_jogar[jogador1_linha_atual][jogador1_coluna_atual]=' ';
							*continuar=0;	
						}
						else
						{
							printf("\n\n\t\tNão pode atacar as sua próprias peças");
							*continuar=0;
							getch();
						}
					
					}
				}
				else
				{
					printf("\n\n\t\tNão se pode fazer jogada porque não há espaço para locomover");
					getch();
					*continuar=0;
				}
									
			}
			else
			{
				if(((jogador1_coluna_atual-jogador1_coluna_mover>=1)&&(jogador1_coluna_atual-jogador1_coluna_mover<=7)) &&
			       ((jogador1_linha_atual-jogador1_linha_mover==0)))
			    {
			        for(i=jogador1_coluna_mover+1;i<=jogador1_coluna_atual-1;i++)
					{
						if(tabuleiro_jogar[jogador1_linha_mover][i]==' ')
						{
							contador_torre++; //movimento para esquerda
						}
						z++;
					}
											
					tt=jogador1_linha_mover;
					ttt=jogador1_coluna_mover;
											
					if(z==contador_torre)
					{
						if((tabuleiro_jogar[tt][ttt]=='A'||tabuleiro_jogar[tt][ttt]=='J'||tabuleiro_jogar[tt][ttt]=='K'||
						   tabuleiro_jogar[tt][ttt]=='L'||tabuleiro_jogar[tt][ttt]=='M'||tabuleiro_jogar[tt][ttt]=='N'||
						   tabuleiro_jogar[tt][ttt]==' '||tabuleiro_jogar[tt][ttt]=='l')&&(jog==1))
						{
							tabuleiro_jogar[tt][ttt]='T';
							tabuleiro_jogar[jogador1_linha_atual][jogador1_coluna_atual]=' ';
							*continuar=0;
						}
						else
						{
							if((tabuleiro_jogar[tt][ttt]=='P'||tabuleiro_jogar[tt][ttt]=='T'||tabuleiro_jogar[tt][ttt]=='C'||
							   tabuleiro_jogar[tt][ttt]=='B'||tabuleiro_jogar[tt][ttt]=='R'||tabuleiro_jogar[tt][ttt]=='W'||
							   tabuleiro_jogar[tt][ttt]==' '||tabuleiro_jogar[tt][ttt]=='b')&&(jog==2))
							{
								tabuleiro_jogar[tt][ttt]='J';
								tabuleiro_jogar[jogador1_linha_atual][jogador1_coluna_atual]=' ';
								*continuar=0;	
							}
							else
							{
								printf("\n\n\t\tNão pode atacar as sua próprias peças");
								*continuar=0;
								getch();
							}
							
						}
					}
					else
					{
						printf("\n\n\t\tNão se pode fazer jogada porque não há espaço para locomover");
						getch();
						*continuar=0;
					}
				}
				else
				{
					printf("\n\n\t\tNão se pode jogar com essas coordenadas");
					*continuar=0;
					getch();
				}
			}
		}
	}
}

void cavalo(int jogador1_linha_atual,int jogador1_coluna_atual,int jogador1_linha_mover,int jogador1_coluna_mover,
	        int tt,int ttt,char tabuleiro_jogar[][8],int *continuar,char nome_jogador1[],char nome_jogador2[]){

	int i=0,j=0;
	
						
	if((jogador1_linha_atual-jogador1_linha_mover==2)&&(jogador1_coluna_atual-jogador1_coluna_mover==1))
	{
		tt=jogador1_linha_mover;
		ttt=jogador1_coluna_mover;
							
		for(i=0;i<8;i++)
		{
			if(jogador1_linha_mover==i)
			{
				for(j=0;j<8;j++)
				{
					if(jogador1_coluna_mover==j)
					{
						if((tabuleiro_jogar[tt][ttt]=='A'||tabuleiro_jogar[tt][ttt]=='J'||tabuleiro_jogar[tt][ttt]=='K'||
			   			   tabuleiro_jogar[tt][ttt]=='L'||tabuleiro_jogar[tt][ttt]=='M'||tabuleiro_jogar[tt][ttt]=='N'||
			               tabuleiro_jogar[tt][ttt]==' '||tabuleiro_jogar[tt][ttt]=='l')&&(jog==1))
			            {
							tabuleiro_jogar[tt][ttt]='C';
							tabuleiro_jogar[jogador1_linha_atual][jogador1_coluna_atual]=' ';
							*continuar=0;	
						}
						else
						{
							if((tabuleiro_jogar[tt][ttt]=='P'||tabuleiro_jogar[tt][ttt]=='T'||tabuleiro_jogar[tt][ttt]=='C'||
				   			   tabuleiro_jogar[tt][ttt]=='B'||tabuleiro_jogar[tt][ttt]=='R'||tabuleiro_jogar[tt][ttt]=='W'||
				   			   tabuleiro_jogar[tt][ttt]==' '||tabuleiro_jogar[tt][ttt]=='b')&&(jog==2))
							{
								tabuleiro_jogar[tt][ttt]='K';
								tabuleiro_jogar[jogador1_linha_atual][jogador1_coluna_atual]=' ';
								*continuar=0;	
							}
							else
							{
								printf("\n\n\t\tNão pode atacar as sua próprias peças");
								*continuar=0;
								getch();
							}
						}
					}
				}
			}
		}
	}
	else
	{
		if((jogador1_linha_atual-jogador1_linha_mover==-2)&&(jogador1_coluna_atual-jogador1_coluna_mover==1))
		{
			tt=jogador1_linha_mover;
			ttt=jogador1_coluna_mover;
							
			for(i=0;i<8;i++)
			{
				if(jogador1_linha_mover==i)
				{
					for(j=0;j<8;j++)
					{	
						if(jogador1_coluna_mover==j)
						{
							if((tabuleiro_jogar[tt][ttt]=='A'||tabuleiro_jogar[tt][ttt]=='J'||tabuleiro_jogar[tt][ttt]=='K'||
			   				   tabuleiro_jogar[tt][ttt]=='L'||tabuleiro_jogar[tt][ttt]=='M'||tabuleiro_jogar[tt][ttt]=='N'||
			                   tabuleiro_jogar[tt][ttt]==' '||tabuleiro_jogar[tt][ttt]=='l')&&(jog==1))
			                {
								tabuleiro_jogar[tt][ttt]='C';
								tabuleiro_jogar[jogador1_linha_atual][jogador1_coluna_atual]=' ';
								*continuar=0;	
							}
							else
							{
								if((tabuleiro_jogar[tt][ttt]=='P'||tabuleiro_jogar[tt][ttt]=='T'||tabuleiro_jogar[tt][ttt]=='C'||
				   				   tabuleiro_jogar[tt][ttt]=='B'||tabuleiro_jogar[tt][ttt]=='R'||tabuleiro_jogar[tt][ttt]=='W'||
				   				   tabuleiro_jogar[tt][ttt]==' '||tabuleiro_jogar[tt][ttt]=='b')&&(jog==2))
								{
									tabuleiro_jogar[tt][ttt]='K';
									tabuleiro_jogar[jogador1_linha_atual][jogador1_coluna_atual]=' ';
									*continuar=0;	
								}
								else
								{
									printf("\n\n\t\tNão pode atacar sua próprias peças");
									*continuar=0;
									getch();
								}
							}
						}
					}
				}		
			}
		}
		else
		{
			if((jogador1_linha_atual-jogador1_linha_mover==2)&&(jogador1_coluna_atual-jogador1_coluna_mover==-1))
			{
				tt=jogador1_linha_mover;
				ttt=jogador1_coluna_mover;
							
				for(i=0;i<8;i++)
				{
					if(jogador1_linha_mover==i)
					{
						for(j=0;j<8;j++)
						{	
							if(jogador1_coluna_mover==j)
							{
								if((tabuleiro_jogar[tt][ttt]=='A'||tabuleiro_jogar[tt][ttt]=='J'||tabuleiro_jogar[tt][ttt]=='K'||
			   					   tabuleiro_jogar[tt][ttt]=='L'||tabuleiro_jogar[tt][ttt]=='M'||tabuleiro_jogar[tt][ttt]=='N'||
			                       tabuleiro_jogar[tt][ttt]==' '||tabuleiro_jogar[tt][ttt]=='l')&&(jog==1))
			                    {
									tabuleiro_jogar[tt][ttt]='C';
									tabuleiro_jogar[jogador1_linha_atual][jogador1_coluna_atual]=' ';
									*continuar=0;	
								}
								else
								{
									if((tabuleiro_jogar[tt][ttt]=='P'||tabuleiro_jogar[tt][ttt]=='T'||tabuleiro_jogar[tt][ttt]=='C'||
				   					   tabuleiro_jogar[tt][ttt]=='B'||tabuleiro_jogar[tt][ttt]=='R'||tabuleiro_jogar[tt][ttt]=='W'||
				   					   tabuleiro_jogar[tt][ttt]==' '||tabuleiro_jogar[tt][ttt]=='b')&&(jog==2))
									{
										tabuleiro_jogar[tt][ttt]='K';
										tabuleiro_jogar[jogador1_linha_atual][jogador1_coluna_atual]=' ';
										*continuar=0;	
									}
									else
									{
										printf("\n\n\t\tNão pode atacar suas próprias peças");
										*continuar=0;
										getch();
									}
								}
							}
						}
					}		
				}
			}
			else
			{
				if((jogador1_linha_atual-jogador1_linha_mover==-2)&&(jogador1_coluna_atual-jogador1_coluna_mover==-1))
				{
					tt=jogador1_linha_mover;
					ttt=jogador1_coluna_mover;
							
					for(i=0;i<8;i++)
					{
						if(jogador1_linha_mover==i)
						{
							for(j=0;j<8;j++)
							{	
								if(jogador1_coluna_mover==j)
								{
									if((tabuleiro_jogar[tt][ttt]=='A'||tabuleiro_jogar[tt][ttt]=='J'||tabuleiro_jogar[tt][ttt]=='K'||
			   						   tabuleiro_jogar[tt][ttt]=='L'||tabuleiro_jogar[tt][ttt]=='M'||tabuleiro_jogar[tt][ttt]=='N'||
			                           tabuleiro_jogar[tt][ttt]==' '||tabuleiro_jogar[tt][ttt]=='l')&&(jog==1))
			                        {
										tabuleiro_jogar[tt][ttt]='C';
										tabuleiro_jogar[jogador1_linha_atual][jogador1_coluna_atual]=' ';
										*continuar=0;	
									}
									else
									{
										if((tabuleiro_jogar[tt][ttt]=='P'||tabuleiro_jogar[tt][ttt]=='T'||tabuleiro_jogar[tt][ttt]=='C'||
				   						   tabuleiro_jogar[tt][ttt]=='B'||tabuleiro_jogar[tt][ttt]=='R'||tabuleiro_jogar[tt][ttt]=='W'||
				   						   tabuleiro_jogar[tt][ttt]==' '||tabuleiro_jogar[tt][ttt]=='b')&&(jog==2))
										{
											tabuleiro_jogar[tt][ttt]='K';
											tabuleiro_jogar[jogador1_linha_atual][jogador1_coluna_atual]=' ';
											*continuar=0;	
										}
										else
										{
											printf("\n\n\t\tNão pode atacar as suas próprias peças");
											*continuar=0;
											getch();
										}
									}
								}
													
							}
						}		
					}
				}
				else
				{
					if((jogador1_linha_atual-jogador1_linha_mover==1)&&(jogador1_coluna_atual-jogador1_coluna_mover==2))
					{
						tt=jogador1_linha_mover;
						ttt=jogador1_coluna_mover;
							
						for(i=0;i<8;i++)
						{
							if(jogador1_linha_mover==i)
							{
								for(j=0;j<8;j++)
								{	
									if(jogador1_coluna_mover==j)
									{
										if((tabuleiro_jogar[tt][ttt]=='A'||tabuleiro_jogar[tt][ttt]=='J'||tabuleiro_jogar[tt][ttt]=='K'||
			   							   tabuleiro_jogar[tt][ttt]=='L'||tabuleiro_jogar[tt][ttt]=='M'||tabuleiro_jogar[tt][ttt]=='N'||
			                               tabuleiro_jogar[tt][ttt]==' '||tabuleiro_jogar[tt][ttt]=='l')&&(jog==1))
			                            {
											tabuleiro_jogar[tt][ttt]='C';
											tabuleiro_jogar[jogador1_linha_atual][jogador1_coluna_atual]=' ';
											*continuar=0;	
										}
										else
										{
											if((tabuleiro_jogar[tt][ttt]=='P'||tabuleiro_jogar[tt][ttt]=='T'||tabuleiro_jogar[tt][ttt]=='C'||
				   							   tabuleiro_jogar[tt][ttt]=='B'||tabuleiro_jogar[tt][ttt]=='R'||tabuleiro_jogar[tt][ttt]=='W'||
				   							   tabuleiro_jogar[tt][ttt]==' '||tabuleiro_jogar[tt][ttt]=='b')&&(jog==2))
											{
												tabuleiro_jogar[tt][ttt]='K';
												tabuleiro_jogar[jogador1_linha_atual][jogador1_coluna_atual]=' ';
												*continuar=0;	
											}
											else
											{
												printf("\n\n\t\tNão pode atacar suas próprias peças");
												*continuar=0;
												getch();
											}
										}
									}
								}
							}		
						}
					}
					else
					{
						if((jogador1_linha_atual-jogador1_linha_mover==1)&&(jogador1_coluna_atual-jogador1_coluna_mover==-2))
						{
							tt=jogador1_linha_mover;
							ttt=jogador1_coluna_mover;
							
							for(i=0;i<8;i++)
							{
								if(jogador1_linha_mover==i)
								{
									for(j=0;j<8;j++)
									{	
										if(jogador1_coluna_mover==j)
										{
											if((tabuleiro_jogar[tt][ttt]=='A'||tabuleiro_jogar[tt][ttt]=='J'||tabuleiro_jogar[tt][ttt]=='K'||
			   								   tabuleiro_jogar[tt][ttt]=='L'||tabuleiro_jogar[tt][ttt]=='M'||tabuleiro_jogar[tt][ttt]=='N'||
			                                   tabuleiro_jogar[tt][ttt]==' '||tabuleiro_jogar[tt][ttt]=='l')&&(jog==1))
			                                {
												tabuleiro_jogar[tt][ttt]='C';
												tabuleiro_jogar[jogador1_linha_atual][jogador1_coluna_atual]=' ';
												*continuar=0;	
											}
											else
											{
												if((tabuleiro_jogar[tt][ttt]=='P'||tabuleiro_jogar[tt][ttt]=='T'||tabuleiro_jogar[tt][ttt]=='C'||
				   								   tabuleiro_jogar[tt][ttt]=='B'||tabuleiro_jogar[tt][ttt]=='R'||tabuleiro_jogar[tt][ttt]=='W'||
				   								   tabuleiro_jogar[tt][ttt]==' '||tabuleiro_jogar[tt][ttt]=='b')&&(jog==2))
												{
													tabuleiro_jogar[tt][ttt]='K';
													tabuleiro_jogar[jogador1_linha_atual][jogador1_coluna_atual]=' ';
													*continuar=0;	
												}
												else
												{
													printf("\n\n\t\tNão pode atacar suas próprias peças");
													*continuar=0;
													getch();
												}
											}
										}
									}
								}		
							}
						}
						else
						{
							if((jogador1_linha_atual-jogador1_linha_mover==-1)&&(jogador1_coluna_atual-jogador1_coluna_mover==-2))
							{
								tt=jogador1_linha_mover;
								ttt=jogador1_coluna_mover;
							
								for(i=0;i<8;i++)
								{
									if(jogador1_linha_mover==i)
									{
										for(j=0;j<8;j++)
										{	
											if(jogador1_coluna_mover==j)
											{
												if((tabuleiro_jogar[tt][ttt]=='A'||tabuleiro_jogar[tt][ttt]=='J'||tabuleiro_jogar[tt][ttt]=='K'||
			   								       tabuleiro_jogar[tt][ttt]=='L'||tabuleiro_jogar[tt][ttt]=='M'||tabuleiro_jogar[tt][ttt]=='N'||
			                                       tabuleiro_jogar[tt][ttt]==' '||tabuleiro_jogar[tt][ttt]=='l')&&(jog==1))
			                                	{
													tabuleiro_jogar[tt][ttt]='C';
													tabuleiro_jogar[jogador1_linha_atual][jogador1_coluna_atual]=' ';
													*continuar=0;	
												}
												else
												{
													if((tabuleiro_jogar[tt][ttt]=='P'||tabuleiro_jogar[tt][ttt]=='T'||tabuleiro_jogar[tt][ttt]=='C'||
				   								       tabuleiro_jogar[tt][ttt]=='B'||tabuleiro_jogar[tt][ttt]=='R'||tabuleiro_jogar[tt][ttt]=='W'||
				   								       tabuleiro_jogar[tt][ttt]==' '||tabuleiro_jogar[tt][ttt]=='b')&&(jog==2))
													{
														tabuleiro_jogar[tt][ttt]='K';
														tabuleiro_jogar[jogador1_linha_atual][jogador1_coluna_atual]=' ';
														*continuar=0;	
													}
													else
													{
														printf("\n\n\t\tNão pode atacar suas próprias peças");
														*continuar=0;
														getch();
													}
												}
											}
										}
									}		
								}
							}
							else
							{
								if((jogador1_linha_atual-jogador1_linha_mover==-1)&&(jogador1_coluna_atual-jogador1_coluna_mover==2))
								{
									tt=jogador1_linha_mover;
									ttt=jogador1_coluna_mover;
							
									for(i=0;i<8;i++)
									{
										if(jogador1_linha_mover==i)
										{
											for(j=0;j<8;j++)
											{	
												if(jogador1_coluna_mover==j)
												{
													if((tabuleiro_jogar[tt][ttt]=='A'||tabuleiro_jogar[tt][ttt]=='J'||tabuleiro_jogar[tt][ttt]=='K'||
			   								       	   tabuleiro_jogar[tt][ttt]=='L'||tabuleiro_jogar[tt][ttt]=='M'||tabuleiro_jogar[tt][ttt]=='N'||
			                                           tabuleiro_jogar[tt][ttt]==' '||tabuleiro_jogar[tt][ttt]=='l')&&(jog==1))
			                                		{
														tabuleiro_jogar[tt][ttt]='C';
														tabuleiro_jogar[jogador1_linha_atual][jogador1_coluna_atual]=' ';
														*continuar=0;	
													}
													else
													{
														if((tabuleiro_jogar[tt][ttt]=='P'||tabuleiro_jogar[tt][ttt]=='T'||tabuleiro_jogar[tt][ttt]=='C'||
				   								       	   tabuleiro_jogar[tt][ttt]=='B'||tabuleiro_jogar[tt][ttt]=='R'||tabuleiro_jogar[tt][ttt]=='W'||
				   								           tabuleiro_jogar[tt][ttt]==' '||tabuleiro_jogar[tt][ttt]=='b')&&(jog==2))
														{
															tabuleiro_jogar[tt][ttt]='K';
															tabuleiro_jogar[jogador1_linha_atual][jogador1_coluna_atual]=' ';
															*continuar=0;	
														}
														else
														{
															printf("\n\n\t\tNão pode atacar suas próprias peças");
															*continuar=0;
															getch();
														}
													}
												}
											}
										}		
									}
								}
								else
								{
									printf("\n\n\t\tNão se pode jogar com essas coordenadas");
									*continuar=0;
									getch();
								}
							}
						}
					}
				}
			}
		}
	}

}

void bispo1(int jogador1_linha_atual,int jogador1_coluna_atual,int jogador1_linha_mover,int jogador1_coluna_mover,
			int tt,int ttt,char tabuleiro_jogar[][8],int *continuar,char nome_jogador1[],char nome_jogador2[],int z,int contador_torre){
			
	int i=0,kkk=0;
	
	kkk=0;
	

if ((jogador1_linha_mover==0 && jogador1_coluna_mover==1)||(jogador1_linha_mover==0 && jogador1_coluna_mover==3)|| (jogador1_linha_mover==0 && jogador1_coluna_mover==5)|| (jogador1_linha_mover==0 && jogador1_coluna_mover==7)||
   (jogador1_linha_mover==1 && jogador1_coluna_mover==0)||(jogador1_linha_mover==1 && jogador1_coluna_mover==2)|| (jogador1_linha_mover==1 && jogador1_coluna_mover==4)|| (jogador1_linha_mover==1 && jogador1_coluna_mover==6)||
   (jogador1_linha_mover==2 && jogador1_coluna_mover==1)||(jogador1_linha_mover==2 && jogador1_coluna_mover==3)|| (jogador1_linha_mover==2 && jogador1_coluna_mover==5)|| (jogador1_linha_mover==2 && jogador1_coluna_mover==7)||
   (jogador1_linha_mover==3 && jogador1_coluna_mover==0)||(jogador1_linha_mover==3 && jogador1_coluna_mover==2)|| (jogador1_linha_mover==3 && jogador1_coluna_mover==4)|| (jogador1_linha_mover==3 && jogador1_coluna_mover==6)||
   (jogador1_linha_mover==4 && jogador1_coluna_mover==1)||(jogador1_linha_mover==4 && jogador1_coluna_mover==3)|| (jogador1_linha_mover==4 && jogador1_coluna_mover==5)|| (jogador1_linha_mover==4 && jogador1_coluna_mover==7)||
   (jogador1_linha_mover==5 && jogador1_coluna_mover==0)||(jogador1_linha_mover==5 && jogador1_coluna_mover==2)|| (jogador1_linha_mover==5 && jogador1_coluna_mover==4)|| (jogador1_linha_mover==5 && jogador1_coluna_mover==6)||
   (jogador1_linha_mover==6 && jogador1_coluna_mover==1)||(jogador1_linha_mover==6 && jogador1_coluna_mover==3)|| (jogador1_linha_mover==6 && jogador1_coluna_mover==5)|| (jogador1_linha_mover==6 && jogador1_coluna_mover==7)||
   (jogador1_linha_mover==7 && jogador1_coluna_mover==0)||(jogador1_linha_mover==7 && jogador1_coluna_mover==2)|| (jogador1_linha_mover==7 && jogador1_coluna_mover==4)|| (jogador1_linha_mover==7 && jogador1_coluna_mover==6))	
{
												
	if(((jogador1_linha_atual-jogador1_linha_mover>=1)&&(jogador1_linha_atual-jogador1_linha_mover<=7))&&
	   ((jogador1_coluna_atual-jogador1_coluna_mover<=-1)&&(jogador1_linha_atual-jogador1_linha_mover>=-7)))	
		{
			kkk=0;
			
			for(i=jogador1_linha_mover+1;i<=jogador1_linha_atual-1;i++)
			{
				kkk++;
				if(tabuleiro_jogar[i][jogador1_coluna_mover-z]==' ')
				{
					contador_torre++;
				}
				z++;
			}
												
			tt=jogador1_linha_mover;
			ttt=jogador1_coluna_mover;
							
			if(kkk==contador_torre)
			{
				if((tabuleiro_jogar[tt][ttt]=='A'||tabuleiro_jogar[tt][ttt]=='J'||tabuleiro_jogar[tt][ttt]=='K'||
			   	   tabuleiro_jogar[tt][ttt]=='L'||tabuleiro_jogar[tt][ttt]=='M'||tabuleiro_jogar[tt][ttt]=='N'||
			   	   tabuleiro_jogar[tt][ttt]==' '||tabuleiro_jogar[tt][ttt]=='l')&&(jog==1))
				{
					tabuleiro_jogar[tt][ttt]='B';
					tabuleiro_jogar[jogador1_linha_atual][jogador1_coluna_atual]=' ';
					*continuar=0;	
				}
				else
				{
					if((tabuleiro_jogar[tt][ttt]=='P'||tabuleiro_jogar[tt][ttt]=='T'||tabuleiro_jogar[tt][ttt]=='C'||
				   	   tabuleiro_jogar[tt][ttt]=='B'||tabuleiro_jogar[tt][ttt]=='R'||tabuleiro_jogar[tt][ttt]=='W'||
				   	   tabuleiro_jogar[tt][ttt]==' '||tabuleiro_jogar[tt][ttt]=='b')&&(jog==2))
					{
						tabuleiro_jogar[tt][ttt]='L';
						tabuleiro_jogar[jogador1_linha_atual][jogador1_coluna_atual]=' ';
						*continuar=0;	
					}
					else
					{
						printf("\n\n\t\tNão pode atacar as sua próprias peças");
						*continuar=0;
						getch();
					}
									
				}
			}
			else
			{
				printf("\n\n\t\tNão se pode fazer a jogada devido a passagem não estar livre");
				getch();
				*continuar=0;
			}
		}
		else
		{
			if(((jogador1_linha_atual-jogador1_linha_mover<=-1)&&(jogador1_linha_atual-jogador1_linha_mover>=-7))&&
			   ((jogador1_coluna_atual-jogador1_coluna_mover>=1)&&(jogador1_linha_atual-jogador1_linha_mover<=7)))	
			{
				
				kkk=0;
				for(i=jogador1_linha_mover-1;i>=jogador1_linha_atual+1;i--)
				{
					
					kkk++;
					if(tabuleiro_jogar[i][jogador1_coluna_mover+z]==' ')
					{
						contador_torre++;
					}
					z++;
									
				}
												
				tt=jogador1_linha_mover;
				ttt=jogador1_coluna_mover;
							
				if(kkk==contador_torre)
				{
					if((tabuleiro_jogar[tt][ttt]=='A'||tabuleiro_jogar[tt][ttt]=='J'||tabuleiro_jogar[tt][ttt]=='K'||
			   		   tabuleiro_jogar[tt][ttt]=='L'||tabuleiro_jogar[tt][ttt]=='M'||tabuleiro_jogar[tt][ttt]=='N'||
			   		   tabuleiro_jogar[tt][ttt]==' '||tabuleiro_jogar[tt][ttt]=='l')&&(jog==1))
					{
						tabuleiro_jogar[tt][ttt]='B';
						tabuleiro_jogar[jogador1_linha_atual][jogador1_coluna_atual]=' ';
						*continuar=0;	
					}
					else
					{
						if((tabuleiro_jogar[tt][ttt]=='P'||tabuleiro_jogar[tt][ttt]=='T'||tabuleiro_jogar[tt][ttt]=='C'||
				   		   tabuleiro_jogar[tt][ttt]=='B'||tabuleiro_jogar[tt][ttt]=='R'||tabuleiro_jogar[tt][ttt]=='W'||
				   		   tabuleiro_jogar[tt][ttt]==' '||tabuleiro_jogar[tt][ttt]=='b')&&(jog==2))
						{
							tabuleiro_jogar[tt][ttt]='L';
							tabuleiro_jogar[jogador1_linha_atual][jogador1_coluna_atual]=' ';
							*continuar=0;	
						}
						else
						{
							printf("\n\n\t\tNão pode atacar as sua próprias peças");
							*continuar=0;
							getch();
						}
									
					}
				}
				else
				{
					printf("\n\n\t\tNão se pode fazer a jogada devido a passagem não estar livre");
					getch();
					*continuar=0;
				}
			}
			else
			{
				if(((jogador1_linha_atual-jogador1_linha_mover>=1)&&(jogador1_linha_atual-jogador1_linha_mover<=6))&&
				   ((jogador1_coluna_atual-jogador1_coluna_mover>=1)&&(jogador1_linha_atual-jogador1_linha_mover<=6)))
				{
					kkk=0;
						  	   	   	
					for(i=jogador1_linha_mover+1;i<=jogador1_linha_atual-1;i++)
					{
						kkk++;
						
						if(tabuleiro_jogar[i][jogador1_coluna_mover+z]==' ')
						{
							contador_torre++;
						}
						z++;
										
					}
												
					tt=jogador1_linha_mover;
					ttt=jogador1_coluna_mover;
									
					if(kkk==contador_torre)
					{
						if((tabuleiro_jogar[tt][ttt]=='A'||tabuleiro_jogar[tt][ttt]=='J'||tabuleiro_jogar[tt][ttt]=='K'||
			   			   tabuleiro_jogar[tt][ttt]=='L'||tabuleiro_jogar[tt][ttt]=='M'||tabuleiro_jogar[tt][ttt]=='N'||
			   			   tabuleiro_jogar[tt][ttt]==' '||tabuleiro_jogar[tt][ttt]=='l')&&(jog==1))
						{
							tabuleiro_jogar[tt][ttt]='B';
							tabuleiro_jogar[jogador1_linha_atual][jogador1_coluna_atual]=' ';
							*continuar=0;	
						}
						else
						{
							if((tabuleiro_jogar[tt][ttt]=='P'||tabuleiro_jogar[tt][ttt]=='T'||tabuleiro_jogar[tt][ttt]=='C'||
				   			   tabuleiro_jogar[tt][ttt]=='B'||tabuleiro_jogar[tt][ttt]=='R'||tabuleiro_jogar[tt][ttt]=='W'||
				   			   tabuleiro_jogar[tt][ttt]==' '||tabuleiro_jogar[tt][ttt]=='b')&&(jog==2))
							{
								tabuleiro_jogar[tt][ttt]='L';
								tabuleiro_jogar[jogador1_linha_atual][jogador1_coluna_atual]=' ';
								*continuar=0;	
							}
							else
							{
								printf("\n\n\t\tNão pode atacar as sua próprias peças");
								*continuar=0;
								getch();
							}
									
						}
					}
					else
					{
						printf("\n\n\t\tNão se pode fazer a jogada devido a passagem não estar livre");
						getch();
						*continuar=0;
					}
				}
				else
				{
				   	if(((jogador1_linha_atual-jogador1_linha_mover<=-1)&&(jogador1_linha_atual-jogador1_linha_mover>=-6))&&
					   ((jogador1_coluna_atual-jogador1_coluna_mover<=-1)&&(jogador1_linha_atual-jogador1_linha_mover>=-6)))
					{
						kkk=0;
						
						for(i=jogador1_linha_mover-1;i>=jogador1_linha_atual+1;i--)
						{
							kkk++;
							
							if(tabuleiro_jogar[i][jogador1_coluna_mover-z]==' ')
							{
								contador_torre++;
							}
							z++;
											
						}
												
						tt=jogador1_linha_mover;
						ttt=jogador1_coluna_mover;
										
						if(kkk==contador_torre)
						{
							if((tabuleiro_jogar[tt][ttt]=='A'||tabuleiro_jogar[tt][ttt]=='J'||tabuleiro_jogar[tt][ttt]=='K'||
			   				   tabuleiro_jogar[tt][ttt]=='L'||tabuleiro_jogar[tt][ttt]=='M'||tabuleiro_jogar[tt][ttt]=='N'||
			   				   tabuleiro_jogar[tt][ttt]==' '||tabuleiro_jogar[tt][ttt]=='l')&&(jog==1))
							{
								tabuleiro_jogar[tt][ttt]='B';
								tabuleiro_jogar[jogador1_linha_atual][jogador1_coluna_atual]=' ';
								*continuar=0;	
							}
							else
							{
								if((tabuleiro_jogar[tt][ttt]=='P'||tabuleiro_jogar[tt][ttt]=='T'||tabuleiro_jogar[tt][ttt]=='C'||
				   				   tabuleiro_jogar[tt][ttt]=='B'||tabuleiro_jogar[tt][ttt]=='R'||tabuleiro_jogar[tt][ttt]=='W'||
				   				   tabuleiro_jogar[tt][ttt]==' '||tabuleiro_jogar[tt][ttt]=='b')&&(jog==2))
								{
									tabuleiro_jogar[tt][ttt]='L';
									tabuleiro_jogar[jogador1_linha_atual][jogador1_coluna_atual]=' ';
									*continuar=0;	
								}
								else
								{
									printf("\n\n\t\tNão pode atacar as sua próprias peças");
									*continuar=0;
									getch();
								}
									
							}
						}
						else
						{
							printf("\n\n\t\tNão se pode fazer a jogada devido a passagem não estar livre");
							getch();
							*continuar=0;
						}
					
					}
				}
			}
		}
}
else
{
	printf("\n\n\t\tNão se pode mover com essa coordenada");
	*continuar=0;
	getch();
}

}

void bispo2(int jogador1_linha_atual,int jogador1_coluna_atual,int jogador1_linha_mover,int jogador1_coluna_mover,
			int tt,int ttt,char tabuleiro_jogar[][8],int *continuar,char nome_jogador1[],char nome_jogador2[],int z,int contador_torre){
			
	int i=0,kkk=0;
	
	kkk=0;

if ((jogador1_linha_mover==0 && jogador1_coluna_mover==0)||(jogador1_linha_mover==0 && jogador1_coluna_mover==2)|| (jogador1_linha_mover==0 && jogador1_coluna_mover==4)|| (jogador1_linha_mover==0 && jogador1_coluna_mover==6)||
   (jogador1_linha_mover==1 && jogador1_coluna_mover==1)||(jogador1_linha_mover==1 && jogador1_coluna_mover==3) || (jogador1_linha_mover==1 && jogador1_coluna_mover==5)|| (jogador1_linha_mover==1 && jogador1_coluna_mover==7)||
   (jogador1_linha_mover==2 && jogador1_coluna_mover==0)||(jogador1_linha_mover==2 && jogador1_coluna_mover==2) || (jogador1_linha_mover==2 && jogador1_coluna_mover==4)|| (jogador1_linha_mover==2 && jogador1_coluna_mover==6)||
   (jogador1_linha_mover==3 && jogador1_coluna_mover==1)||(jogador1_linha_mover==3 && jogador1_coluna_mover==3) || (jogador1_linha_mover==3 && jogador1_coluna_mover==5)|| (jogador1_linha_mover==3 && jogador1_coluna_mover==7)||
   (jogador1_linha_mover==4 && jogador1_coluna_mover==0)||(jogador1_linha_mover==4 && jogador1_coluna_mover==2) || (jogador1_linha_mover==4 && jogador1_coluna_mover==4)|| (jogador1_linha_mover==4 && jogador1_coluna_mover==6)||
   (jogador1_linha_mover==5 && jogador1_coluna_mover==1)||(jogador1_linha_mover==5 && jogador1_coluna_mover==3) || (jogador1_linha_mover==5 && jogador1_coluna_mover==5)|| (jogador1_linha_mover==5 && jogador1_coluna_mover==7)||
   (jogador1_linha_mover==6 && jogador1_coluna_mover==0)||(jogador1_linha_mover==6 && jogador1_coluna_mover==2) || (jogador1_linha_mover==6 && jogador1_coluna_mover==4)|| (jogador1_linha_mover==6 && jogador1_coluna_mover==6)||
   (jogador1_linha_mover==7 && jogador1_coluna_mover==1)||(jogador1_linha_mover==7 && jogador1_coluna_mover==3) || (jogador1_linha_mover==7 && jogador1_coluna_mover==5)|| (jogador1_linha_mover==7 && jogador1_coluna_mover==7))	
{
												
	if(((jogador1_linha_atual-jogador1_linha_mover>=1)&&(jogador1_linha_atual-jogador1_linha_mover<=7))&&
	   ((jogador1_coluna_atual-jogador1_coluna_mover>=1)&&(jogador1_linha_atual-jogador1_linha_mover<=7)))	
		{
			kkk=0;
			
			for(i=jogador1_linha_mover+1;i<=jogador1_linha_atual-1;i++)
			{
				kkk++;
				if(tabuleiro_jogar[i][jogador1_coluna_mover+z]==' ')
				{
					contador_torre++;
				}
				z++;
			}
												
			tt=jogador1_linha_mover;
			ttt=jogador1_coluna_mover;
							
			if(kkk==contador_torre)
			{
				if((tabuleiro_jogar[tt][ttt]=='A'||tabuleiro_jogar[tt][ttt]=='J'||tabuleiro_jogar[tt][ttt]=='K'||
			   	   tabuleiro_jogar[tt][ttt]=='L'||tabuleiro_jogar[tt][ttt]=='M'||tabuleiro_jogar[tt][ttt]=='N'||
			   	   tabuleiro_jogar[tt][ttt]==' '||tabuleiro_jogar[tt][ttt]=='l')&&(jog==1))
				{
					tabuleiro_jogar[tt][ttt]='b';
					tabuleiro_jogar[jogador1_linha_atual][jogador1_coluna_atual]=' ';
					*continuar=0;	
				}
				else
				{
					if((tabuleiro_jogar[tt][ttt]=='P'||tabuleiro_jogar[tt][ttt]=='T'||tabuleiro_jogar[tt][ttt]=='C'||
				   	   tabuleiro_jogar[tt][ttt]=='B'||tabuleiro_jogar[tt][ttt]=='R'||tabuleiro_jogar[tt][ttt]=='W'||
				   	   tabuleiro_jogar[tt][ttt]==' '||tabuleiro_jogar[tt][ttt]=='b')&&(jog==2))
					{
						tabuleiro_jogar[tt][ttt]='l';
						tabuleiro_jogar[jogador1_linha_atual][jogador1_coluna_atual]=' ';
						*continuar=0;	
					}
					else
					{
						printf("\n\n\t\tNão pode atacar as sua próprias peças");
						*continuar=0;
						getch();
					}
									
				}
			}
			else
			{
				printf("\n\n\t\tNão se pode fazer a jogada devido a passagem não estar livre");
				getch();
				*continuar=0;
			}
		}
		else
		{
			if(((jogador1_linha_atual-jogador1_linha_mover<=-1)&&(jogador1_linha_atual-jogador1_linha_mover>=-7))&&
			   ((jogador1_coluna_atual-jogador1_coluna_mover<=-1)&&(jogador1_linha_atual-jogador1_linha_mover>=-7)))	
			{
				
				kkk=0;
				for(i=jogador1_linha_mover-1;i>=jogador1_linha_atual+1;i--)
				{
					
					kkk++;
					if(tabuleiro_jogar[i][jogador1_coluna_mover-z]==' ')
					{
						contador_torre++;
					}
					z++;
									
				}
												
				tt=jogador1_linha_mover;
				ttt=jogador1_coluna_mover;
							
				if(kkk==contador_torre)
				{
					if((tabuleiro_jogar[tt][ttt]=='A'||tabuleiro_jogar[tt][ttt]=='J'||tabuleiro_jogar[tt][ttt]=='K'||
			   		   tabuleiro_jogar[tt][ttt]=='L'||tabuleiro_jogar[tt][ttt]=='M'||tabuleiro_jogar[tt][ttt]=='N'||
			   		   tabuleiro_jogar[tt][ttt]==' '||tabuleiro_jogar[tt][ttt]=='l')&&(jog==1))
					{
						tabuleiro_jogar[tt][ttt]='b';
						tabuleiro_jogar[jogador1_linha_atual][jogador1_coluna_atual]=' ';
						*continuar=0;	
					}
					else
					{
						if((tabuleiro_jogar[tt][ttt]=='P'||tabuleiro_jogar[tt][ttt]=='T'||tabuleiro_jogar[tt][ttt]=='C'||
				   		   tabuleiro_jogar[tt][ttt]=='B'||tabuleiro_jogar[tt][ttt]=='R'||tabuleiro_jogar[tt][ttt]=='W'||
				   		   tabuleiro_jogar[tt][ttt]==' '||tabuleiro_jogar[tt][ttt]=='b')&&(jog==2))
						{
							tabuleiro_jogar[tt][ttt]='l';
							tabuleiro_jogar[jogador1_linha_atual][jogador1_coluna_atual]=' ';
							*continuar=0;	
						}
						else
						{
							printf("\n\n\t\tNão pode atacar as sua próprias peças");
							*continuar=0;
							getch();
						}
									
					}
				}
				else
				{
					printf("\n\n\t\tNão se pode fazer a jogada devido a passagem não estar livre");
					getch();
					*continuar=0;
				}
			}
			else
			{
				if(((jogador1_linha_atual-jogador1_linha_mover>=1)&&(jogador1_linha_atual-jogador1_linha_mover<=6))&&
				   ((jogador1_coluna_atual-jogador1_coluna_mover<=-1)&&(jogador1_linha_atual-jogador1_linha_mover>=-6)))
				{
					kkk=0;
						  	   	   	
					for(i=jogador1_linha_mover+1;i<=jogador1_linha_atual-1;i++)
					{
						kkk++;
						
						if(tabuleiro_jogar[i][jogador1_coluna_mover-z]==' ')
						{
							contador_torre++;
						}
						z++;
										
					}
												
					tt=jogador1_linha_mover;
					ttt=jogador1_coluna_mover;
									
					if(kkk==contador_torre)
					{
						if((tabuleiro_jogar[tt][ttt]=='A'||tabuleiro_jogar[tt][ttt]=='J'||tabuleiro_jogar[tt][ttt]=='K'||
			   			   tabuleiro_jogar[tt][ttt]=='L'||tabuleiro_jogar[tt][ttt]=='M'||tabuleiro_jogar[tt][ttt]=='N'||
			   			   tabuleiro_jogar[tt][ttt]==' '||tabuleiro_jogar[tt][ttt]=='l')&&(jog==1))
						{
							tabuleiro_jogar[tt][ttt]='b';
							tabuleiro_jogar[jogador1_linha_atual][jogador1_coluna_atual]=' ';
							*continuar=0;	
						}
						else
						{
							if((tabuleiro_jogar[tt][ttt]=='P'||tabuleiro_jogar[tt][ttt]=='T'||tabuleiro_jogar[tt][ttt]=='C'||
				   			   tabuleiro_jogar[tt][ttt]=='B'||tabuleiro_jogar[tt][ttt]=='R'||tabuleiro_jogar[tt][ttt]=='W'||
				   			   tabuleiro_jogar[tt][ttt]==' '||tabuleiro_jogar[tt][ttt]=='b')&&(jog==2))
							{
								tabuleiro_jogar[tt][ttt]='l';
								tabuleiro_jogar[jogador1_linha_atual][jogador1_coluna_atual]=' ';
								*continuar=0;	
							}
							else
							{
								printf("\n\n\t\tNão pode atacar as sua próprias peças");
								*continuar=0;
								getch();
							}
									
						}
					}
					else
					{
						printf("\n\n\t\tNão se pode fazer a jogada devido a passagem não estar livre");
						getch();
						*continuar=0;
					}
				}
				else
				{
				   	if(((jogador1_linha_atual-jogador1_linha_mover<=-1)&&(jogador1_linha_atual-jogador1_linha_mover>=-6))&&
					   ((jogador1_coluna_atual-jogador1_coluna_mover>=1)&&(jogador1_linha_atual-jogador1_linha_mover<=6)))
					{
						kkk=0;
						
						for(i=jogador1_linha_mover-1;i>=jogador1_linha_atual+1;i--)
						{
							kkk++;
							
							if(tabuleiro_jogar[i][jogador1_coluna_mover+z]==' ')
							{
								contador_torre++;
							}
							z++;
											
						}
												
						tt=jogador1_linha_mover;
						ttt=jogador1_coluna_mover;
										
						if(kkk==contador_torre)
						{
							if((tabuleiro_jogar[tt][ttt]=='A'||tabuleiro_jogar[tt][ttt]=='J'||tabuleiro_jogar[tt][ttt]=='K'||
			   				   tabuleiro_jogar[tt][ttt]=='L'||tabuleiro_jogar[tt][ttt]=='M'||tabuleiro_jogar[tt][ttt]=='N'||
			   				   tabuleiro_jogar[tt][ttt]==' '||tabuleiro_jogar[tt][ttt]=='l')&&(jog==1))
							{
								tabuleiro_jogar[tt][ttt]='b';
								tabuleiro_jogar[jogador1_linha_atual][jogador1_coluna_atual]=' ';
								*continuar=0;	
							}
							else
							{
								if((tabuleiro_jogar[tt][ttt]=='P'||tabuleiro_jogar[tt][ttt]=='T'||tabuleiro_jogar[tt][ttt]=='C'||
				   				   tabuleiro_jogar[tt][ttt]=='B'||tabuleiro_jogar[tt][ttt]=='R'||tabuleiro_jogar[tt][ttt]=='W'||
				   				   tabuleiro_jogar[tt][ttt]==' '||tabuleiro_jogar[tt][ttt]=='b')&&(jog==2))
								{
									tabuleiro_jogar[tt][ttt]='l';
									tabuleiro_jogar[jogador1_linha_atual][jogador1_coluna_atual]=' ';
									*continuar=0;	
								}
								else
								{
									printf("\n\n\t\tNão pode atacar as sua próprias peças");
									*continuar=0;
									getch();
								}
									
							}
						}
						else
						{
							printf("\n\n\t\tNão se pode fazer a jogada devido a passagem não estar livre");
							getch();
							*continuar=0;
						}
					
					}
				}
			}
		}
}
else
{
	printf("\n\n\t\tNão se pode mover com essa coordenada");
	*continuar=0;
	getch();
}
}

void rainha(int jogador1_linha_atual,int jogador1_coluna_atual,int jogador1_linha_mover,int jogador1_coluna_mover,
int tt,int ttt,char tabuleiro_jogar[][8],int *continuar,int contador_torre,int z,char nome_jogador1[],char nome_jogador2[])
{
	int i=0,j=0,kkk=0,zz=1;
	
							
	if(((jogador1_linha_atual-jogador1_linha_mover>=1)&&(jogador1_linha_atual-jogador1_linha_mover<=7)) &&
	   ((jogador1_coluna_atual-jogador1_coluna_mover==0)))
    {
																
		for(i=jogador1_linha_mover+1;i<=jogador1_linha_atual-1;i++)
		{
						
			if(tabuleiro_jogar[i][jogador1_coluna_mover]==' ')
			{
				contador_torre++;//movimento para cima
			}
			z++;
		}
							
		tt=jogador1_linha_mover;
		ttt=jogador1_coluna_mover;
							
		if(z==contador_torre)
		{
			if((tabuleiro_jogar[tt][ttt]=='A'||tabuleiro_jogar[tt][ttt]=='J'||tabuleiro_jogar[tt][ttt]=='K'||
			   tabuleiro_jogar[tt][ttt]=='L'||tabuleiro_jogar[tt][ttt]=='M'||tabuleiro_jogar[tt][ttt]=='N'||
			   tabuleiro_jogar[tt][ttt]==' '||tabuleiro_jogar[tt][ttt]=='l')&&(jog==1))
			{
				tabuleiro_jogar[tt][ttt]='R';
				tabuleiro_jogar[jogador1_linha_atual][jogador1_coluna_atual]=' ';
				*continuar=0;	
			}
			else
			{
				if((tabuleiro_jogar[tt][ttt]=='P'||tabuleiro_jogar[tt][ttt]=='T'||tabuleiro_jogar[tt][ttt]=='C'||
				   tabuleiro_jogar[tt][ttt]=='B'||tabuleiro_jogar[tt][ttt]=='R'||tabuleiro_jogar[tt][ttt]=='W'||
				   tabuleiro_jogar[tt][ttt]==' '||tabuleiro_jogar[tt][ttt]=='b')&&(jog==2))
				{
					tabuleiro_jogar[tt][ttt]='M';
					tabuleiro_jogar[jogador1_linha_atual][jogador1_coluna_atual]=' ';
					*continuar=0;	
				}
				else
				{
					printf("\n\n\t\tNão pode atacar as sua próprias peças");
					*continuar=0;
					getch();
				}
			
			}
		}
		else
		{
			printf("\n\n\t\tNão se pode fazer jogada porque não há espaço para locomover");
			getch();
			*continuar=0;
		}
	}
	else
	{
		if(((jogador1_linha_atual-jogador1_linha_mover<=-1)&&(jogador1_linha_atual-jogador1_linha_mover>=-7)) &&
		   ((jogador1_coluna_atual-jogador1_coluna_mover==0)))
		{
			for(i=jogador1_linha_mover-1;i<=jogador1_linha_atual+1;i--)
			{
				if(tabuleiro_jogar[i][jogador1_coluna_mover]==' ')
				{
					contador_torre++; //movimento para baixo
				}
				z++;
			}
								
			tt=jogador1_linha_mover;
			ttt=jogador1_coluna_mover;
								
			if(z==contador_torre)
			{
				if((tabuleiro_jogar[tt][ttt]=='A'||tabuleiro_jogar[tt][ttt]=='J'||tabuleiro_jogar[tt][ttt]=='K'||
				   tabuleiro_jogar[tt][ttt]=='L'||tabuleiro_jogar[tt][ttt]=='M'||tabuleiro_jogar[tt][ttt]=='N'||
				   tabuleiro_jogar[tt][ttt]==' '||tabuleiro_jogar[tt][ttt]=='l')&&(jog==1))
				{
					tabuleiro_jogar[tt][ttt]='R';
					tabuleiro_jogar[jogador1_linha_atual][jogador1_coluna_atual]=' ';
					*continuar=0;	
				}
				else
				{
					if((tabuleiro_jogar[tt][ttt]=='P'||tabuleiro_jogar[tt][ttt]=='T'||tabuleiro_jogar[tt][ttt]=='C'||
					   tabuleiro_jogar[tt][ttt]=='B'||tabuleiro_jogar[tt][ttt]=='R'||tabuleiro_jogar[tt][ttt]=='W'||
					   tabuleiro_jogar[tt][ttt]==' '||tabuleiro_jogar[tt][ttt]=='b')&&(jog==2))
					{
						tabuleiro_jogar[tt][ttt]='M';
						tabuleiro_jogar[jogador1_linha_atual][jogador1_coluna_atual]=' ';
						*continuar=0;	
					}
					else
					{
						printf("\n\n\t\tNão pode atacar as sua próprias peças");
						*continuar=0;
						getch();
					}
				
				}
			}
			else
			{
				printf("\n\n\t\tNão se pode fazer jogada porque não há espaço para locomover");
				getch();
				*continuar=0;
			}
								
		}
		else
		{
			if(((jogador1_coluna_atual-jogador1_coluna_mover<=-1)&&(jogador1_coluna_atual-jogador1_coluna_mover>=-7)) &&
			   ((jogador1_linha_atual-jogador1_linha_mover==0)))
			{
			    for(i=jogador1_coluna_mover-1;i>=jogador1_coluna_atual+1;i--)
				{
					if(tabuleiro_jogar[jogador1_linha_mover][i]==' ')
					{
						contador_torre++; //movimento para direita
					}
					z++;
				}
									
				tt=jogador1_linha_mover;
				ttt=jogador1_coluna_mover;
									
				if(z==contador_torre)
				{
					if((tabuleiro_jogar[tt][ttt]=='A'||tabuleiro_jogar[tt][ttt]=='J'||tabuleiro_jogar[tt][ttt]=='K'||
					   tabuleiro_jogar[tt][ttt]=='L'||tabuleiro_jogar[tt][ttt]=='M'||tabuleiro_jogar[tt][ttt]=='N'||
					   tabuleiro_jogar[tt][ttt]==' '||tabuleiro_jogar[tt][ttt]=='l')&&(jog==1))
					{
						tabuleiro_jogar[tt][ttt]='R';
						tabuleiro_jogar[jogador1_linha_atual][jogador1_coluna_atual]=' ';
						*continuar=0;	
					}
					else
					{
						if((tabuleiro_jogar[tt][ttt]=='P'||tabuleiro_jogar[tt][ttt]=='T'||tabuleiro_jogar[tt][ttt]=='C'||
						   tabuleiro_jogar[tt][ttt]=='B'||tabuleiro_jogar[tt][ttt]=='R'||tabuleiro_jogar[tt][ttt]=='W'||
						   tabuleiro_jogar[tt][ttt]==' '||tabuleiro_jogar[tt][ttt]=='b')&&(jog==2))
						{
							tabuleiro_jogar[tt][ttt]='M';
							tabuleiro_jogar[jogador1_linha_atual][jogador1_coluna_atual]=' ';
							*continuar=0;	
						}
						else
						{
							printf("\n\n\t\tNão pode atacar as sua próprias peças");
							*continuar=0;
							getch();
						}
					
					}
				}
				else
				{
					printf("\n\n\t\tNão se pode fazer jogada porque não há espaço para locomover");
					getch();
					*continuar=0;
				}
									
			}
			else
			{
				if(((jogador1_coluna_atual-jogador1_coluna_mover>=1)&&(jogador1_coluna_atual-jogador1_coluna_mover<=7)) &&
			       ((jogador1_linha_atual-jogador1_linha_mover==0)))
			    {
			        for(i=jogador1_coluna_mover+1;i<=jogador1_coluna_atual-1;i++)
					{
						if(tabuleiro_jogar[jogador1_linha_mover][i]==' ')
						{
							contador_torre++; //movimento para esquerda
						}
						z++;
					}
											
					tt=jogador1_linha_mover;
					ttt=jogador1_coluna_mover;
											
					if(z==contador_torre)
					{
						if((tabuleiro_jogar[tt][ttt]=='A'||tabuleiro_jogar[tt][ttt]=='J'||tabuleiro_jogar[tt][ttt]=='K'||
						   tabuleiro_jogar[tt][ttt]=='L'||tabuleiro_jogar[tt][ttt]=='M'||tabuleiro_jogar[tt][ttt]=='N'||
						   tabuleiro_jogar[tt][ttt]==' '||tabuleiro_jogar[tt][ttt]=='l')&&(jog==1))
						{
							tabuleiro_jogar[tt][ttt]='R';
							tabuleiro_jogar[jogador1_linha_atual][jogador1_coluna_atual]=' ';
							*continuar=0;
						}
						else
						{
							if((tabuleiro_jogar[tt][ttt]=='P'||tabuleiro_jogar[tt][ttt]=='T'||tabuleiro_jogar[tt][ttt]=='C'||
							   tabuleiro_jogar[tt][ttt]=='B'||tabuleiro_jogar[tt][ttt]=='R'||tabuleiro_jogar[tt][ttt]=='W'||
							   tabuleiro_jogar[tt][ttt]==' '||tabuleiro_jogar[tt][ttt]=='b')&&(jog==2))
							{
								tabuleiro_jogar[tt][ttt]='M';
								tabuleiro_jogar[jogador1_linha_atual][jogador1_coluna_atual]=' ';
								*continuar=0;	
							}
							else
							{
								printf("\n\n\t\tNão pode atacar as sua próprias peças");
								*continuar=0;
								getch();
							}
							
						}
					}
					else
					{
						printf("\n\n\t\tNão se pode fazer jogada porque não há espaço para locomover");
						getch();
						*continuar=0;
					}
				}
				else
				{
					if(((jogador1_linha_atual-jogador1_linha_mover>=1)&&(jogador1_linha_atual-jogador1_linha_mover<=7))&&
	   				   ((jogador1_coluna_atual-jogador1_coluna_mover<=-1)&&(jogador1_linha_atual-jogador1_linha_mover>=-7)))	
					{
						kkk=0; zz=1;
			
						for(i=jogador1_linha_mover+1;i<=jogador1_linha_atual-1;i++)
						{
							kkk++;
							if(tabuleiro_jogar[i][jogador1_coluna_mover-zz]==' ')
							{
								contador_torre++;
							}
							zz++;
						}
												
						tt=jogador1_linha_mover;
						ttt=jogador1_coluna_mover;
							
						if(kkk==contador_torre)
						{
							if((tabuleiro_jogar[tt][ttt]=='A'||tabuleiro_jogar[tt][ttt]=='J'||tabuleiro_jogar[tt][ttt]=='K'||
			   	   			   tabuleiro_jogar[tt][ttt]=='L'||tabuleiro_jogar[tt][ttt]=='M'||tabuleiro_jogar[tt][ttt]=='N'||
			   	   			   tabuleiro_jogar[tt][ttt]==' '||tabuleiro_jogar[tt][ttt]=='l')&&(jog==1))
							{
								tabuleiro_jogar[tt][ttt]='R';
								tabuleiro_jogar[jogador1_linha_atual][jogador1_coluna_atual]=' ';
								*continuar=0;	
							}
							else
							{
								if((tabuleiro_jogar[tt][ttt]=='P'||tabuleiro_jogar[tt][ttt]=='T'||tabuleiro_jogar[tt][ttt]=='C'||
				   	   			   tabuleiro_jogar[tt][ttt]=='B'||tabuleiro_jogar[tt][ttt]=='R'||tabuleiro_jogar[tt][ttt]=='W'||
				   	   			   tabuleiro_jogar[tt][ttt]==' '||tabuleiro_jogar[tt][ttt]=='b')&&(jog==2))
								{
									tabuleiro_jogar[tt][ttt]='M';
									tabuleiro_jogar[jogador1_linha_atual][jogador1_coluna_atual]=' ';
									*continuar=0;	
								}
								else
								{
									printf("\n\n\t\tNão pode atacar as sua próprias peças");
									*continuar=0;
									getch();
								}
							}
						}
						else
						{
							printf("\n\n\t\tNão se pode fazer a jogada devido a passagem não estar livre");
							getch();
							*continuar=0;
						}
					}
					else
					{
						if(((jogador1_linha_atual-jogador1_linha_mover<=-1)&&(jogador1_linha_atual-jogador1_linha_mover>=-7))&&
			   			   ((jogador1_coluna_atual-jogador1_coluna_mover>=1)&&(jogador1_linha_atual-jogador1_linha_mover<=7)))	
						{
				
							kkk=0; zz=1;
							for(i=jogador1_linha_mover-1;i>=jogador1_linha_atual+1;i--)
							{
					
								kkk++;
								if(tabuleiro_jogar[i][jogador1_coluna_mover+zz]==' ')
								{
									contador_torre++;
								}
								zz++;
							}
												
							tt=jogador1_linha_mover;
							ttt=jogador1_coluna_mover;
							
							if(kkk==contador_torre)
							{
								if((tabuleiro_jogar[tt][ttt]=='A'||tabuleiro_jogar[tt][ttt]=='J'||tabuleiro_jogar[tt][ttt]=='K'||
			   		   			   tabuleiro_jogar[tt][ttt]=='L'||tabuleiro_jogar[tt][ttt]=='M'||tabuleiro_jogar[tt][ttt]=='N'||
			   		               tabuleiro_jogar[tt][ttt]==' '||tabuleiro_jogar[tt][ttt]=='l')&&(jog==1))
								{
									tabuleiro_jogar[tt][ttt]='R';
									tabuleiro_jogar[jogador1_linha_atual][jogador1_coluna_atual]=' ';
									*continuar=0;	
								}
								else
								{
									if((tabuleiro_jogar[tt][ttt]=='P'||tabuleiro_jogar[tt][ttt]=='T'||tabuleiro_jogar[tt][ttt]=='C'||
				   		   		   	   tabuleiro_jogar[tt][ttt]=='B'||tabuleiro_jogar[tt][ttt]=='R'||tabuleiro_jogar[tt][ttt]=='W'||
				   		   		       tabuleiro_jogar[tt][ttt]==' '||tabuleiro_jogar[tt][ttt]=='b')&&(jog==2))
									{
										tabuleiro_jogar[tt][ttt]='M';
										tabuleiro_jogar[jogador1_linha_atual][jogador1_coluna_atual]=' ';
										*continuar=0;	
									}
									else
									{
										printf("\n\n\t\tNão pode atacar as sua próprias peças");
										*continuar=0;
										getch();
									}
								}
							}
							else
							{
								printf("\n\n\t\tNão se pode fazer a jogada devido a passagem não estar livre");
								getch();
								*continuar=0;
							}
						}
						else
						{
							if(((jogador1_linha_atual-jogador1_linha_mover>=1)&&(jogador1_linha_atual-jogador1_linha_mover<=6))&&
				   			   ((jogador1_coluna_atual-jogador1_coluna_mover>=1)&&(jogador1_linha_atual-jogador1_linha_mover<=6)))
							{
								kkk=0; zz=1;
						  	   	   	
								for(i=jogador1_linha_mover+1;i<=jogador1_linha_atual-1;i++)
								{
									kkk++;
						
									if(tabuleiro_jogar[i][jogador1_coluna_mover+zz]==' ')
									{
										contador_torre++;
									}
									zz++;
								}
												
								tt=jogador1_linha_mover;
								ttt=jogador1_coluna_mover;
									
								if(kkk==contador_torre)
								{
									if((tabuleiro_jogar[tt][ttt]=='A'||tabuleiro_jogar[tt][ttt]=='J'||tabuleiro_jogar[tt][ttt]=='K'||
			   			   			   tabuleiro_jogar[tt][ttt]=='L'||tabuleiro_jogar[tt][ttt]=='M'||tabuleiro_jogar[tt][ttt]=='N'||
			   			   			   tabuleiro_jogar[tt][ttt]==' '||tabuleiro_jogar[tt][ttt]=='l')&&(jog==1))
									{
										tabuleiro_jogar[tt][ttt]='R';
										tabuleiro_jogar[jogador1_linha_atual][jogador1_coluna_atual]=' ';
										*continuar=0;	
									}
									else
									{
										if((tabuleiro_jogar[tt][ttt]=='P'||tabuleiro_jogar[tt][ttt]=='T'||tabuleiro_jogar[tt][ttt]=='C'||
				   			   			   tabuleiro_jogar[tt][ttt]=='B'||tabuleiro_jogar[tt][ttt]=='R'||tabuleiro_jogar[tt][ttt]=='W'||
				   			   			   tabuleiro_jogar[tt][ttt]==' '||tabuleiro_jogar[tt][ttt]=='b')&&(jog==2))
										{
											tabuleiro_jogar[tt][ttt]='M';
											tabuleiro_jogar[jogador1_linha_atual][jogador1_coluna_atual]=' ';
											*continuar=0;	
										}
										else
										{
											printf("\n\n\t\tNão pode atacar as sua próprias peças");
											*continuar=0;
											getch();
										}
									}
								}
								else
								{
									printf("\n\n\t\tNão se pode fazer a jogada devido a passagem não estar livre");
									getch();
									*continuar=0;
								}
							}
							else
							{
								if(((jogador1_linha_atual-jogador1_linha_mover<=-1)&&(jogador1_linha_atual-jogador1_linha_mover>=-6))&&
					   			   ((jogador1_coluna_atual-jogador1_coluna_mover<=-1)&&(jogador1_linha_atual-jogador1_linha_mover>=-6)))
								{
									kkk=0;
						
									for(i=jogador1_linha_mover-1;i>=jogador1_linha_atual+1;i--)
									{
										kkk++; zz=1;
							
										if(tabuleiro_jogar[i][jogador1_coluna_mover-zz]==' ')
										{
											contador_torre++;
										}
										zz++;
									}
												
									tt=jogador1_linha_mover;
									ttt=jogador1_coluna_mover;
										
									if(kkk==contador_torre)
									{
										if((tabuleiro_jogar[tt][ttt]=='A'||tabuleiro_jogar[tt][ttt]=='J'||tabuleiro_jogar[tt][ttt]=='K'||
			   				   			   tabuleiro_jogar[tt][ttt]=='L'||tabuleiro_jogar[tt][ttt]=='M'||tabuleiro_jogar[tt][ttt]=='N'||
			   				   			   tabuleiro_jogar[tt][ttt]==' '||tabuleiro_jogar[tt][ttt]=='l')&&(jog==1))
										{
											tabuleiro_jogar[tt][ttt]='R';
											tabuleiro_jogar[jogador1_linha_atual][jogador1_coluna_atual]=' ';
											*continuar=0;	
										}
										else
										{
											if((tabuleiro_jogar[tt][ttt]=='P'||tabuleiro_jogar[tt][ttt]=='T'||tabuleiro_jogar[tt][ttt]=='C'||
				   				   			   tabuleiro_jogar[tt][ttt]=='B'||tabuleiro_jogar[tt][ttt]=='R'||tabuleiro_jogar[tt][ttt]=='W'||
				   				   			   tabuleiro_jogar[tt][ttt]==' '||tabuleiro_jogar[tt][ttt]=='b')&&(jog==2))
											{
												tabuleiro_jogar[tt][ttt]='M';
												tabuleiro_jogar[jogador1_linha_atual][jogador1_coluna_atual]=' ';
												*continuar=0;	
											}
											else
											{
												printf("\n\n\t\tNão pode atacar as sua próprias peças");
												*continuar=0;
												getch();
											}
										}
									}
									else
									{
										printf("\n\n\t\tNão se pode fazer a jogada devido a passagem não estar livre");
										getch();
										*continuar=0;
									}
								}
								else
								{
									if(((jogador1_linha_atual-jogador1_linha_mover>=1)&&(jogador1_linha_atual-jogador1_linha_mover<=7))&&
	   								   ((jogador1_coluna_atual-jogador1_coluna_mover>=1)&&(jogador1_linha_atual-jogador1_linha_mover<=7)))	
									{
										kkk=0;zz=1;
			
										for(i=jogador1_linha_mover+1;i<=jogador1_linha_atual-1;i++)
										{
											kkk++;
											if(tabuleiro_jogar[i][jogador1_coluna_mover+zz]==' ')
											{
												contador_torre++;
											}
											zz++;
										}
												
										tt=jogador1_linha_mover;
										ttt=jogador1_coluna_mover;
							
										if(kkk==contador_torre)
										{
											if((tabuleiro_jogar[tt][ttt]=='A'||tabuleiro_jogar[tt][ttt]=='J'||tabuleiro_jogar[tt][ttt]=='K'||
			   	   							   tabuleiro_jogar[tt][ttt]=='L'||tabuleiro_jogar[tt][ttt]=='M'||tabuleiro_jogar[tt][ttt]=='N'||
			   	   							   tabuleiro_jogar[tt][ttt]==' '||tabuleiro_jogar[tt][ttt]=='l')&&(jog==1))
											{
												tabuleiro_jogar[tt][ttt]='R';
												tabuleiro_jogar[jogador1_linha_atual][jogador1_coluna_atual]=' ';
												*continuar=0;	
											}
											else
											{
												if((tabuleiro_jogar[tt][ttt]=='P'||tabuleiro_jogar[tt][ttt]=='T'||tabuleiro_jogar[tt][ttt]=='C'||
				   	   						   	   tabuleiro_jogar[tt][ttt]=='B'||tabuleiro_jogar[tt][ttt]=='R'||tabuleiro_jogar[tt][ttt]=='W'||
				   	   				               tabuleiro_jogar[tt][ttt]==' '||tabuleiro_jogar[tt][ttt]=='b')&&(jog==2))
												{
													tabuleiro_jogar[tt][ttt]='M';
													tabuleiro_jogar[jogador1_linha_atual][jogador1_coluna_atual]=' ';
													*continuar=0;	
												}
												else
												{
													printf("\n\n\t\tNão pode atacar as sua próprias peças");
													*continuar=0;
													getch();
												}
											}
										}
										else
										{
											printf("\n\n\t\tNão se pode fazer a jogada devido a passagem não estar livre");
											getch();
											*continuar=0;
										}
									}
									else
									{
										if(((jogador1_linha_atual-jogador1_linha_mover<=-1)&&(jogador1_linha_atual-jogador1_linha_mover>=-7))&&
			   							   ((jogador1_coluna_atual-jogador1_coluna_mover<=-1)&&(jogador1_linha_atual-jogador1_linha_mover>=-7)))	
			   							{
				
											kkk=0;zz=1;
											
											for(i=jogador1_linha_mover-1;i>=jogador1_linha_atual+1;i--)
											{
					
												kkk++; 
												
												if(tabuleiro_jogar[i][jogador1_coluna_mover-zz]==' ')
												{			
													contador_torre++;
												}
												zz++;
											}
												
											tt=jogador1_linha_mover;
											ttt=jogador1_coluna_mover;
							
											if(kkk==contador_torre)
											{
												if((tabuleiro_jogar[tt][ttt]=='A'||tabuleiro_jogar[tt][ttt]=='J'||tabuleiro_jogar[tt][ttt]=='K'||
			   		   							   tabuleiro_jogar[tt][ttt]=='L'||tabuleiro_jogar[tt][ttt]=='M'||tabuleiro_jogar[tt][ttt]=='N'||
			   		   							   tabuleiro_jogar[tt][ttt]==' '||tabuleiro_jogar[tt][ttt]=='l')&&(jog==1))
												{
													tabuleiro_jogar[tt][ttt]='R';
													tabuleiro_jogar[jogador1_linha_atual][jogador1_coluna_atual]=' ';
													*continuar=0;	
												}
												else
												{
													if((tabuleiro_jogar[tt][ttt]=='P'||tabuleiro_jogar[tt][ttt]=='T'||tabuleiro_jogar[tt][ttt]=='C'||
				   		   							   tabuleiro_jogar[tt][ttt]=='B'||tabuleiro_jogar[tt][ttt]=='R'||tabuleiro_jogar[tt][ttt]=='W'||
				   		   							   tabuleiro_jogar[tt][ttt]==' '||tabuleiro_jogar[tt][ttt]=='b')&&(jog==2))
													{
														tabuleiro_jogar[tt][ttt]='M';
														tabuleiro_jogar[jogador1_linha_atual][jogador1_coluna_atual]=' ';
														*continuar=0;	
													}
													else
													{
														printf("\n\n\t\tNão pode atacar as sua próprias peças");
														*continuar=0;
														getch();
													}
												}
											}
											else
											{
												printf("\n\n\t\tNão se pode fazer a jogada devido a passagem não estar livre");
												getch();
												*continuar=0;
											}
										}
										else
										{
											if(((jogador1_linha_atual-jogador1_linha_mover>=1)&&(jogador1_linha_atual-jogador1_linha_mover<=6))&&
				   							   ((jogador1_coluna_atual-jogador1_coluna_mover<=-1)&&(jogador1_linha_atual-jogador1_linha_mover>=-6)))
											{
												kkk=0; zz=1;
						  	   	   	
												for(i=jogador1_linha_mover+1;i<=jogador1_linha_atual-1;i++)
												{
													kkk++;
						
													if(tabuleiro_jogar[i][jogador1_coluna_mover-zz]==' ')
													{
														contador_torre++;
													}
													zz++;
												}
												
												tt=jogador1_linha_mover;
												ttt=jogador1_coluna_mover;
									
												if(kkk==contador_torre)
												{
													if((tabuleiro_jogar[tt][ttt]=='A'||tabuleiro_jogar[tt][ttt]=='J'||tabuleiro_jogar[tt][ttt]=='K'||
			   			   							   tabuleiro_jogar[tt][ttt]=='L'||tabuleiro_jogar[tt][ttt]=='M'||tabuleiro_jogar[tt][ttt]=='N'||
			   			   							   tabuleiro_jogar[tt][ttt]==' '||tabuleiro_jogar[tt][ttt]=='l')&&(jog==1))
													{
														tabuleiro_jogar[tt][ttt]='R';
														tabuleiro_jogar[jogador1_linha_atual][jogador1_coluna_atual]=' ';
														*continuar=0;	
													}
													else
													{
														if((tabuleiro_jogar[tt][ttt]=='P'||tabuleiro_jogar[tt][ttt]=='T'||tabuleiro_jogar[tt][ttt]=='C'||
				   			   							   tabuleiro_jogar[tt][ttt]=='B'||tabuleiro_jogar[tt][ttt]=='R'||tabuleiro_jogar[tt][ttt]=='W'||
				   			   							   tabuleiro_jogar[tt][ttt]==' '||tabuleiro_jogar[tt][ttt]=='b')&&(jog==2))
														{
															tabuleiro_jogar[tt][ttt]='M';
															tabuleiro_jogar[jogador1_linha_atual][jogador1_coluna_atual]=' ';
															*continuar=0;	
														}
														else
														{
															printf("\n\n\t\tNão pode atacar as sua próprias peças");
															*continuar=0;
															getch();
														}
													}
												}		
												else
												{
													printf("\n\n\t\tNão se pode fazer a jogada devido a passagem não estar livre");
													getch();
													*continuar=0;
												}
											}
											else
											{
												if(((jogador1_linha_atual-jogador1_linha_mover<=-1)&&(jogador1_linha_atual-jogador1_linha_mover>=-6))&&
					   							   ((jogador1_coluna_atual-jogador1_coluna_mover>=1)&&(jogador1_linha_atual-jogador1_linha_mover<=6)))
												{
													kkk=0; zz=1;
						
													for(i=jogador1_linha_mover-1;i>=jogador1_linha_atual+1;i--)
													{		
														kkk++;
							
														if(tabuleiro_jogar[i][jogador1_coluna_mover+zz]==' ')
														{
															contador_torre++;
														}
														zz++;
													}
												
													tt=jogador1_linha_mover;
													ttt=jogador1_coluna_mover;
										
													if(kkk==contador_torre)
													{
														if((tabuleiro_jogar[tt][ttt]=='A'||tabuleiro_jogar[tt][ttt]=='J'||tabuleiro_jogar[tt][ttt]=='K'||
			   				   							   tabuleiro_jogar[tt][ttt]=='L'||tabuleiro_jogar[tt][ttt]=='M'||tabuleiro_jogar[tt][ttt]=='N'||
			   				   							   tabuleiro_jogar[tt][ttt]==' '||tabuleiro_jogar[tt][ttt]=='l')&&(jog==1))
														{
															tabuleiro_jogar[tt][ttt]='R';
															tabuleiro_jogar[jogador1_linha_atual][jogador1_coluna_atual]=' ';
															*continuar=0;	
														}
														else
														{
															if((tabuleiro_jogar[tt][ttt]=='P'||tabuleiro_jogar[tt][ttt]=='T'||tabuleiro_jogar[tt][ttt]=='C'||
				   				   							   tabuleiro_jogar[tt][ttt]=='B'||tabuleiro_jogar[tt][ttt]=='R'||tabuleiro_jogar[tt][ttt]=='W'||
				   				   							   tabuleiro_jogar[tt][ttt]==' '||tabuleiro_jogar[tt][ttt]=='b')&&(jog==2))
															{
																tabuleiro_jogar[tt][ttt]='M';
																tabuleiro_jogar[jogador1_linha_atual][jogador1_coluna_atual]=' ';
																*continuar=0;	
															}
															else
															{
																printf("\n\n\t\tNão pode atacar as sua próprias peças");
																*continuar=0;
																getch();
															}
														}
													}
													else
													{
														printf("\n\n\t\tNão se pode fazer a jogada devido a passagem não estar livre");
														getch();
														*continuar=0;
													}
												}
												else
												{
													printf("\n\n\t\tNão se pode mover com essa coordenada");
													*continuar=0;
													getch();
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
}		

void rei(int jogador1_linha_atual,int jogador1_coluna_atual,int jogador1_linha_mover,int jogador1_coluna_mover,
		 char tabuleiro_jogar[][8],int *continuar,int tt,int ttt,char nome_jogador1[],char nome_jogador2[]){

								
	if(((jogador1_linha_atual-jogador1_linha_mover>=-1)&&(jogador1_linha_atual-jogador1_linha_mover<=1))&&
	  ((jogador1_coluna_atual-jogador1_coluna_mover>=-1)&&(jogador1_coluna_atual-jogador1_coluna_mover<=1)))
	{
		tt=jogador1_linha_mover;
		ttt=jogador1_coluna_mover;
		
		if((tabuleiro_jogar[tt][ttt]=='A'||tabuleiro_jogar[tt][ttt]=='J'||tabuleiro_jogar[tt][ttt]=='K'||
		   tabuleiro_jogar[tt][ttt]=='L'||tabuleiro_jogar[tt][ttt]=='M'||tabuleiro_jogar[tt][ttt]=='N'||
		   tabuleiro_jogar[tt][ttt]==' '||tabuleiro_jogar[tt][ttt]=='l')&&(jog==1))
		{
			tabuleiro_jogar[tt][ttt]='W';
			tabuleiro_jogar[jogador1_linha_atual][jogador1_coluna_atual]=' ';
			*continuar=0;	
		}
		else
		{
			if((tabuleiro_jogar[tt][ttt]=='P'||tabuleiro_jogar[tt][ttt]=='T'||tabuleiro_jogar[tt][ttt]=='C'||
			   tabuleiro_jogar[tt][ttt]=='B'||tabuleiro_jogar[tt][ttt]=='R'||tabuleiro_jogar[tt][ttt]=='W'||
			   tabuleiro_jogar[tt][ttt]==' '||tabuleiro_jogar[tt][ttt]=='b')&&(jog==2))
			{
				tabuleiro_jogar[tt][ttt]='N';
				tabuleiro_jogar[jogador1_linha_atual][jogador1_coluna_atual]=' ';
				*continuar=0;	
			}
			else
			{
				printf("\n\n\t\tNão pode atacar as sua próprias peças");
				*continuar=0;
				getch();	
			}
		}
	}
	else
	{
		printf("\n\n\t\tNão se pode mover com essa coordenada");
		*continuar=0;
		getch();
	}
}

int resultado1(char tabuleiro_jogar[][8]){
	
	int i=0,j=0,resultado_jogador1=0;
	
	for(i=0;i<8;i++)
		{
			for(j=0;j<8;j++)
			{
				if(tabuleiro_jogar[i][j]=='N')
				{
					resultado_jogador1++;
				}
			}
		}
		
		if(resultado_jogador1>0)
		{
			return(1);
		}
		else
		{
			return(0);
		}
	
}

int resultado2(char tabuleiro_jogar[][8]){
	
	int i=0,j=0,resultado_jogador2=0;
	
	for(i=0;i<8;i++)
		{
			for(j=0;j<8;j++)
			{
				if(tabuleiro_jogar[i][j]=='W')
				{
					resultado_jogador2++;
				}
			}
		}
		
		if(resultado_jogador2>0)
		{
			return(1);
		}
		else
		{
			return(0);
		}
	
}

void peao2(int jogador1_linha_atual,int jogador1_coluna_atual,int jogador1_linha_mover,int jogador1_coluna_mover,
		  int aa,int bb,char tabuleiro_jogar[][8],int *continuar,char peca,int cc,int dd,int ee,int ff,int gg,
		  char nome_jogador1[],char nome_jogador2[]){

	
	int i=0,j=0,s=0,controle=1;

						
	if((jogador1_linha_atual-jogador1_linha_mover==aa)&&(jogador1_coluna_atual-jogador1_coluna_mover==bb))
	{
		for(i=0;i<8;i++)
		{
			if(jogador1_linha_mover==i)
			{
				for(j=0;j<8;j++)
				{
					if(jogador1_coluna_mover==j)
					{
						if(tabuleiro_jogar[i][j]==' ')
						{
							tabuleiro_jogar[i][j]='A';
							tabuleiro_jogar[i+aa][j]=' ';
							*continuar=0;
																		
							if(jogador1_linha_mover==gg)
							{
								do
								{
								
								
									printf("\n\n\t\tTroca de peça\n\n");
									printf("\t\t[J]Torre [K]Cavalo [L]Bispo [l]Bispo [M]Rainha [N]Não troca\n\n");
									printf("\n\t        Peça: ");
									fflush(stdin);
									scanf("%c",&peca);
													
									switch(peca)
									{
										case 'J':
											
											if(verifica(tabuleiro_jogar,peca))
											{
												tabuleiro_jogar[i][j]='J';
												troc2=1;
												controle=0;
											}
											else
											{
												printf("\n\n\t\tNão se pode escolher essa peça");
												getch();
											}
											break;
										
										case 'K':
											
											if(verifica(tabuleiro_jogar,peca))
											{
												tabuleiro_jogar[i][j]='K';
												troc2=1;
											}
											else
											{
												printf("\n\n\t\tNão se pode escolher essa peça");
												getch();
											}
											break;
									
										case 'L':
											
											if(verifica(tabuleiro_jogar,peca))
											{
												tabuleiro_jogar[i][j]='L';
												troc2=1;	
											}
											else
											{
												printf("\n\n\t\tNão se pode escolher essa peça");
												getch();
											}
											break;
										
										case 'l':
											
											if(verifica(tabuleiro_jogar,peca))
											{
												tabuleiro_jogar[i][j]='l';
												troc2=1;	
											}
											else
											{
												printf("\n\n\t\tNão se pode escolher essa peça");
												getch();
											}
											break;
									
										case 'M':
											
											if(verifica(tabuleiro_jogar,peca))
											{
												tabuleiro_jogar[i][j]='M';
												troc2=1;	
											}
											else
											{
												printf("\n\n\t\tNão se pode escolher essa peça");
												getch();
											}
											break;
									
										case 'N':
																							
											tabuleiro_jogar[i][j]='A';
											troc2=1;
											controle=0;
											break;
											
										default:
											printf("\n\n\t\topção inválida");
											getch();
									}
								}while(controle==1);
							}
												
						}
						else
						{
							printf("\n\n\t\t  Essa jogada não é permitida");
							getch();
							*continuar=0;
						}
					}
				}
			}
		}
	}
	else
	{
		if(((jogador1_linha_atual-jogador1_linha_mover==cc)&&(jogador1_coluna_atual-jogador1_coluna_mover==dd))||
		   ((jogador1_linha_atual-jogador1_linha_mover==ee)&&(jogador1_coluna_atual-jogador1_coluna_mover==ff)))
		{	
			for(i=0;i<8;i++)
			{
				if(jogador1_linha_mover==i)
				{
					for(j=0;j<8;j++)
					{
						if(jogador1_coluna_mover==j)
						{	
							if(tabuleiro_jogar[i][j]=='P'||tabuleiro_jogar[i][j]=='T'||tabuleiro_jogar[i][j]=='C'||
							   tabuleiro_jogar[i][j]=='B'||tabuleiro_jogar[i][j]=='R'||tabuleiro_jogar[i][j]=='W'||
							   tabuleiro_jogar[i][j]=='b')
							{
								if(ee==jogador1_linha_atual-jogador1_linha_mover && ff==jogador1_coluna_atual-jogador1_coluna_mover)
								{
									
									if(tabuleiro_jogar[i][j]=='W')
									{
										s++;
									}
									
									tabuleiro_jogar[i][j]='A';
									tabuleiro_jogar[i-1][j-1]=' ';
									*continuar=0;
								}
								if(cc==jogador1_linha_atual-jogador1_linha_mover && dd==jogador1_coluna_atual-jogador1_coluna_mover)
								{
									tabuleiro_jogar[i][j]='A';
									tabuleiro_jogar[i-1][j+1]=' ';
									*continuar=0;
								}
																					
								if(jogador1_linha_mover==gg && s==0)
								{
									
									do
									{
									
										printf("\n\n\t\tTroca de peça\n\n");
										printf("\t\t[J]Torre [K]Cavalo [L]Bispo [l]Bispo [M]Rainha [N]Não troca\n\n");
										printf("\n\t        Peça: ");
										fflush(stdin);
										scanf("%c",&peca);
																																				
										switch(peca)
										{
											case 'J':
											
												if(verifica(tabuleiro_jogar,peca))
												{
													tabuleiro_jogar[i][j]='J';
													troc2=1;
													controle=0;
												}
												else
												{
													printf("\n\n\t\tNão se pode escolher essa peça");
													getch();
												}
												break;
												
											case 'K':
												
												if(verifica(tabuleiro_jogar,peca))
												{
													tabuleiro_jogar[i][j]='K';
													troc2=1;
													controle=0;
												}
												else
												{
													printf("\n\n\t\tNão se pode escolher essa peça");
													getch();
												}
												break;
												
											case 'L':
												
												if(verifica(tabuleiro_jogar,peca))
												{
													tabuleiro_jogar[i][j]='L';
													troc2=1;
													controle=0;
												}
												else
												{
													printf("\n\n\t\tNão se pode escolher essa peça");
													getch();
												}
												break;
											
											case 'l':
											
												if(verifica(tabuleiro_jogar,peca))
												{
													tabuleiro_jogar[i][j]='l';
													troc2=1;	
												}
												else
												{
													printf("\n\n\t\tNão se pode escolher essa peça");
													getch();
												}
												break;
												
											case 'M':
												
												if(verifica(tabuleiro_jogar,peca))
												{
													tabuleiro_jogar[i][j]='M';
													troc2=1;
													controle=0;
												}
												else
												{
													printf("\n\n\t\tNão se pode escolher essa peça");
													getch();
												}
												break;
												
											case 'N':
																								
												tabuleiro_jogar[i][j]='A';
												troc2=1;
												controle=0;
												break;
											
											default:
												printf("\n\n\t\topção inválida");
												getch();
										}
									}while(controle==1);		
								}
													
							}
							else
							{
								printf("\n\n\t\t  Essa jogada não é permitida");
								getch();
								*continuar=0;
							}
						}
					}
				}	
			}
		}
		else
		{
			printf("\n\n\t     Não se pode utilizar essa coordenada para mover essa peça");
			getch();
			*continuar=0;
		}
	}							  	
}

bool verifica(char tabuleiro_jogar[][8],char peca){
	
	int i=0,j=0,verificar=0;
	
	for(i=0;i<8;i++)
	{
		for(j=0;j<8;j++)
		{
			if(tabuleiro_jogar[i][j]==peca)
			{
				verificar++;
			}
		}
	}
	
	if(peca=='B'||peca=='b'||peca=='R'||peca=='L'||peca=='l'||peca=='M')
	{
		if(verificar>0)
		{
			return(0);
		}
		else
		{
			return(1);
		}
	}
	else
	{
		if(peca=='T'||peca=='C'||peca=='J'||peca=='K')
		{
			if(verificar==2)
			{
				return(0);
			}
			else
			{
				return(1);
			}
		}
	}
	
		
	
	
}

