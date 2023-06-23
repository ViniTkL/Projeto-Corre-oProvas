/*
==================================================================================

                               CALCULADOR DE NOTAS

==================================================================================
Empresa: Guizinho's LTDA.
Equipe de Programadores:
               VINÍCIUS SANTANA AZAMBUJA
               GABRIEL BARBOSA DE ARRUDA
               -------------------------
               -------------------------
Curso: TECNOLOGIA DE ANÁLISE E DESENVOLVIMENTO DE SISTEMAS
Data de início do projeto: 28/10/2022
----------------------------------------------------------------------------------
Descrição do Programa:
		Programa feito para ajudar professores com a organização e distribuição das
		notas dos alunos.
Versão do programa: 1.0
Melhorias da versão: primeira versão
Data de lançamento da versão: 14/11/2022
==================================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include  <string.h>

int main(void)
{
 //variaveis
  int  Aln, i;
  float notaf,qntdQ,qntd1, contacertos=0;
  int *alunos;
  float *notas;
  char *rep;
  char *gab;


   printf("=====================================================================================================\n======================================== CALCULADOR DE NOTAS ========================================\n=====================================================================================================\n ");
  //perguntado quantas questões a prova tem
  printf("\nDigite a quantidade de questoes da prova: ");
  scanf("%f", &qntd1);

  //caso o professo exagere nas questões(Enem tem no máximo 180)
  if(qntd1>200 || qntd1<=0 ){
    while(qntd1>200 || qntd1<=0){
        printf("Valor inserido de questoes muito grande, por favor tente novamente e insira um numero menor que 200\nDigite a quantidade de questoes da prova: ");
        scanf("%f", &qntd1);
    }
  }


  //qntd de elementos do vetor
  qntdQ=qntd1;
  rep=(malloc(qntdQ*sizeof(char)));
  gab=(malloc(qntdQ*sizeof(char)));
  alunos=(malloc(Aln*sizeof(int)));
  notas=(malloc(Aln*sizeof(int)));

  //vetores sem memória disponível
  if(rep == NULL){
      printf("Falha em alocar espaco para continuar a operacao\n");
      system("pause");
      exit(1);
  }
  if(gab == NULL){
      printf("Falha em alocar espaco para continuar a operacao\n");
      system("pause");
      exit(1);
  }
  if(alunos == NULL){
      printf("Falha em alocar espaco para continuar a operacao\n");
      system("pause");
      exit(1);
  }
  //pedindo o gabarito
  for(i=0;i<qntdQ;i++){
    printf("Digite o gabarito da questao %d: ",i+1);
    scanf("%s",&gab[i]);
    if(gab[i] != 'a'&& gab[i] != 'b' && gab[i] != 'c' && gab[i] != 'd' && gab[i] != 'e'&& gab[i] != 'A'&& gab[i] != 'B' && gab[i] != 'C' && gab[i] != 'D' && gab[i] != 'E'){
       while(gab[i] != 'a'&& gab[i] != 'b' && gab[i] != 'c' && gab[i] != 'd' && gab[i] != 'e'&& gab[i] != 'A'&& gab[i] != 'B' && gab[i] != 'C' && gab[i] != 'D' && gab[i] != 'E'){
        printf("Valor invalido, tente novamente inserindo respostas de A ate E\nDigite o gabarito da questao %d: ",i+1);
        scanf("%s",&gab[i]);
       }
    }
  }


  //Pedindo quantidade de alunos
  printf("\nDigite a quantidade de alunos que fizeram a prova: ");
  scanf("%d", &Aln);
  //numero mínimino aceitavel para a variavel Aln
  if(Aln<=0){
    while(Aln<=0){
            printf("Valor invalido, tente novamente\nDigite a quantidade de alunos que fizeram a prova: ");
            scanf("%d", &Aln);
    }
  }

  //pedindo o RA dos alunos
  for(i=0;i<Aln;i++){
    printf("\nDigite o RA do aluno [%d]: ",i+1);
    scanf("%d", &alunos[i]);
    //Caso o número de alunos digitado seja inválido Pt.1
    if(alunos[i]<=0){
        while(alunos[i]<=0){
            printf("Valor invalido, tente novamente\nDigite o RA do aluno [%d]: ",i+1);
            scanf("%d", &alunos[i]);
        }
    }
  }
      //Caso o número de alunos digitado seja inválido Pt.2
    for(i=0;i<Aln;i++){
        for(int j=i+1;j<Aln;j++){
            if(alunos[i]==alunos[j]){
                while(alunos[i]==alunos[j]){
                    printf("RA [%d] repetido, tente novamente\nDigite o RA do aluno [%d]: ",j+1,j+1);
                    scanf("%d", &alunos[j]);
                }
            }
        }
    }
  //Repetir essa parte do código por qntd de alunos que fizeram a prova :)
  for(int r=0;r<Aln;r++){
  //repostas
  for(i=0;i<qntdQ;i++){
    printf("\nDigite a resposta da questao %d do aluno [%d]: ",i+1,alunos[r]);
    scanf("%s",&rep[i]);

    //caso a reposta seja diferente de a b c d e
        if(rep[i] != 'a'&& rep[i] != 'b' && rep[i] != 'c' && rep[i] != 'd' && rep[i] != 'e'&& rep[i] != 'A'&& rep[i] != 'B' && rep[i] != 'C' && rep[i] != 'D' && rep[i] != 'E'){
            while(rep[i] != 'a'&& rep[i] != 'b' && rep[i] != 'c' && rep[i] != 'd' && rep[i] != 'e'&& rep[i] != 'A'&& rep[i] != 'B' && rep[i] != 'C' && rep[i] != 'D' && rep[i] != 'E'){
                printf("Valor invalido, tente novamente inserindo respostas de A ate E\nDigite o gabarito da questao %d: ",i+1);
                scanf("%s",&rep[i]);
                            }
                }
        //contar a quantidade de acertos
        if(rep[i] == gab[i]){
            contacertos=contacertos+1;
        }
        else{
            if(strcmp(rep,gab)== 0){
            contacertos=qntd1;
                }
            }
    }






    //notas dos alunos
    notaf=(contacertos/qntd1)*10;
    notas[r]=notaf;
    //resetando cont para cada aluno
    contacertos=0;
}
//estrutura para mostrar as notas
  printf("--------------------------- NOTAS ---------------------------");
  for(i=0;i<Aln;i++){
    printf("\nAluno[%d]: %.2f\n-------------------------------------------------------------",alunos[i], notas[i]);
    }
    return 0;
}
