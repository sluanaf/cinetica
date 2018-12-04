#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
float ordem0 (int N, float concentracao[], float tempo[]){

    double a=0; //coeficiente angular
    double b=0; //coeficiente linear
    int i=0;
    double soma1=0;
    double soma2=0;
    double soma3=0;
    double soma4=0;
    float soma_erro=0;
    float media_erro=0;
    double conta1[N];//conc*tempo
    double conta2[N];//conc
    double conta3[N];//tempo
    double conta4[N];//pow tempo
    int conta=0;
    float y [N];
    float erro[N];


    for(i=0;i<N;i++){
            conta1[i]=(concentracao[i]*tempo[i]);
            conta2[i]= concentracao[i];
            conta3[i]=tempo[i];
            conta4[i] = (pow(tempo[i],2));
    }

    for(i=0;i<N;i++){
            soma1=soma1 + conta1[i];
            soma2=soma2 + conta2[i];
            soma3=soma3 + conta3[i];
            soma4=soma4 + conta4[i];
    }

    //calculando coeficiente angular

    a=((N*soma1) - (soma3*soma2))/ ((N*soma4) - pow(soma3,2));

    //calculando coefiente linear

    b=((soma4*soma2) - (soma1*soma3))/ ((N*soma4)-pow(soma3,2));

    // equacao da reta

    for(i=0;i<N;i++){
         y[i] = (a*tempo[i]) + b;
         //calculo do erro
        erro[i]= (y[i]-concentracao[i])/y[i];
        if(erro[i]<0){
            erro[i]=erro[i]*(-1);
        }
        soma_erro=soma_erro+erro[i];
    }

    FILE *fd=NULL;

    char ARQUIVO[100]="C:\\Users\\luana\\linear0.txt";

    if((fd=fopen(ARQUIVO,"w+"))==NULL){
    printf("Erro.");
    exit(1);
    }

    for(i=0;i<N;i++){
        fprintf(fd,"%.2f %.2f\n",tempo[i], y[i]);
    }

    fclose(fd);

    media_erro=soma_erro/N;

    return media_erro;
}

float ordem1  (int N, float concentracao[], float tempo[]){

    double a=0; //coeficiente angular
    double b=0; //coeficiente linear
    int i=0;
    double soma1=0;
    double soma2=0;
    double soma3=0;
    double soma4=0;
    float soma_erro=0;
    float media_erro=0;
    double conta1[N];//conc*tempo
    double conta2[N];//conc
    double conta3[N];//tempo
    double conta4[N];//pow tempo
    float concentracao1[N];
    float y[N];
    float erro[N];


    for(i=0;i<N;i++){
            concentracao1[i]=log(concentracao[i]);
    }

    for(i=0;i<N;i++){
            conta1[i]=(concentracao1[i]*tempo[i]);
            conta2[i]= concentracao1[i];
            conta3[i]=tempo[i];
            conta4[i] = (pow(tempo[i],2));
    }

    for(i=0;i<N;i++){
            soma1=soma1 + conta1[i];
            soma2=soma2 + conta2[i];
            soma3=soma3 + conta3[i];
            soma4=soma4 + conta4[i];
    }

    a=((N*soma1) - (soma3*soma2))/ ((N*soma4) - pow(soma3,2));

    b=((soma4*soma2) - (soma1*soma3))/ ((N*soma4)-pow(soma3,2));

    for(i=0;i<N;i++){
         y[i] = (a*tempo[i]) + b;
         //calculo do erro
        erro[i]= (y[i]-concentracao1[i])/y[i];
        if(erro[i]<0){
            erro[i]=erro[i]*(-1);
        }
        soma_erro=soma_erro+erro[i];
    }

    FILE *fd=NULL;

    char ARQUIVO[100]="C:\\Users\\luana\\linear.txt";

    if((fd=fopen(ARQUIVO,"w+"))==NULL){
    printf("Erro.");
    exit(1);
    }

    for(i=0;i<N;i++){
        fprintf(fd,"%.2f %.2f\n",tempo[i], y[i]);
     }

     printf("\n");
     fprintf(fd,"\n");
     fclose(fd);

    media_erro=soma_erro/N;

    return media_erro;

}

float ordem2  (int N, float concentracao[], float tempo[]){
    double a=0; //coeficiente angular
    double b=0; //coeficiente linear
    int i=0;
    double soma1=0;
    double soma2=0;
    double soma3=0;
    double soma4=0;
    float soma_erro=0;
    float media_erro=0;
    double conta1[N];//conc*tempo
    double conta2[N];//conc
    double conta3[N];//tempo
    double conta4[N];//pow tempo
    float concentracao2[N];
    float erro[N];
    float y[N];


    for(i=0;i<N;i++){
            concentracao2[i]= (float)1/concentracao[i];
    }


    for(i=0;i<N;i++){
            conta1[i]=(concentracao2[i]*tempo[i]);
            conta2[i]= concentracao2[i];
            conta3[i]=tempo[i];
            conta4[i] = (pow(tempo[i],2));
    }


    for(i=0;i<N;i++){
            soma1=soma1 + conta1[i];
            soma2=soma2 + conta2[i];
            soma3=soma3 + conta3[i];
            soma4=soma4 + conta4[i];

    }

    a=((N*soma1) - (soma3*soma2))/ ((N*soma4) - pow(soma3,2));


    b=((soma4*soma2) - (soma1*soma3))/ ((N*soma4)-pow(soma3,2));




    for(i=0;i<N;i++){
         y[i] = (a*tempo[i]) + b;
         //calculo do erro
        erro[i]= (y[i]-concentracao2[i])/y[i];
        if(erro[i]<0){
            erro[i]=erro[i]*(-1);
        }
        soma_erro=soma_erro+erro[i];
    }

    FILE *fd=NULL;

    char ARQUIVO[100]="C:\\Users\\luana\\linear2.txt";

    if((fd=fopen(ARQUIVO,"w+"))==NULL){
    printf("Erro.");
    exit(1);
    }

    for(i=0;i<N;i++){
        fprintf(fd,"%.2f %.2f\n",tempo[i], y[i]);
    }

    printf("\n");
    fprintf(fd,"\n");
    fclose(fd);

    media_erro=soma_erro/N;

    return media_erro;
}
void grafico0(int N, float concentracao[], float tempo[]){
    int i=0;

    FILE *fd=NULL;

    char ARQUIVO[100]="C:\\Users\\luana\\arq.txt";

    if((fd=fopen(ARQUIVO,"w+"))==NULL){
    printf("Erro.");
    exit(1);
    }

    for(i=0;i<N;i++){
        fprintf(fd,"%.2f %.2f\n",tempo[i], concentracao[i]);
     }

     printf("\n");
     fprintf(fd,"\n");
     fclose(fd);

     char SCRIPT[100]="C:\\Users\\luana\\script.txt";

     fd=NULL;

     if((fd=fopen(SCRIPT,"w+"))==NULL){
     printf("Erro.");
     exit(1);
     }

     char conteudo[100]="plot 'C:\\Users\\luana\\arq.txt' with lines linetype 18 lw 2 title 'Reta com dados experimentais',";
     char conteudo2[100]="'C:\\Users\\luana\\linear0.txt'  title 'Reta ajustada linearmente' with lines linetype 15";
     strcat(conteudo,conteudo2);
     fprintf(fd,"%s", conteudo);
     fclose(fd);

    system("C:\\Users\\luana\\Downloads\\gnuplot\\gnuplot\\bin\\gnuplot  -p C:\\Users\\luana\\script.txt");

}
void  grafico1(int N, float concentracao[], float tempo[]){
    int i=0;
    float concentracao2[N];

    for(i=0;i<N;i++){
        concentracao2[i]=log(concentracao[i]);
    }

    FILE *fd=NULL;

    char ARQUIVO[100]="C:\\Users\\luana\\arq.txt";

    if((fd=fopen(ARQUIVO,"w+"))==NULL){
    printf("Erro.");
    exit(1);
    }

    for(i=0;i<N;i++){
        fprintf(fd,"%.2f %.2f\n",tempo[i], concentracao2[i]);
     }

     printf("\n");
     fprintf(fd,"\n");

     fclose(fd);

     char SCRIPT[100]="C:\\Users\\luana\\script.txt";

     if((fd=fopen(SCRIPT,"w+"))==NULL){
     printf("Erro.");
     exit(1);
     }

     char conteudo[100]="plot 'C:\\Users\\luana\\arq.txt' with lines linetype 18 lw 2 title 'Reta com dados experimentais',";
     char conteudo2[100]="'C:\\Users\\luana\\linear.txt' title 'Reta ajustada linearmente' with lines linetype 15";
     strcat(conteudo,conteudo2);
     fprintf(fd,"%s", conteudo);
     fclose(fd);

    system("C:\\Users\\luana\\Downloads\\gnuplot\\gnuplot\\bin\\gnuplot  -p C:\\Users\\luana\\script.txt");

}
void grafico2(int N, float concentracao[], float tempo[]){
    int i=0;
    float concentracao3[N];

    for(i=0;i<N;i++){
            concentracao3[i]= (float)1/concentracao[i];
    }

    FILE *fd=NULL;

    char ARQUIVO[100]="C:\\Users\\luana\\arq.txt";

    if((fd=fopen(ARQUIVO,"w+"))==NULL){
    printf("Erro.");
    exit(1);
    }

    for(i=0;i<N;i++){
        fprintf(fd,"%.2f %.2f\n",tempo[i], concentracao3[i]);
     }

     printf("\n");
     fprintf(fd,"\n");
     fclose(fd);

     char SCRIPT[100]="C:\\Users\\luana\\script.txt";

     fd=NULL;

     if((fd=fopen(SCRIPT,"w+"))==NULL){
     printf("Erro.");
     exit(1);
     }

     char conteudo[100]="plot 'C:\\Users\\luana\\arq.txt' with lines linetype 18 lw 2 title 'Reta com dados experimentais',";
     char conteudo2[100]="'C:\\Users\\luana\\linear2.txt'  title 'Reta ajustada linearmente' with lines linetype 15";
     strcat(conteudo,conteudo2);
     fprintf(fd,"%s", conteudo);
     fclose(fd);

    system("C:\\Users\\luana\\Downloads\\gnuplot\\gnuplot\\bin\\gnuplot  -p C:\\Users\\luana\\script.txt");

}
double constante(int N,float concentracao2[],float tempo[]){


    double a=0; //coeficiente angular
    int i=0;
    double soma1=0;
    double soma2=0;
    double soma3=0;
    double soma4=0;
    double conta1[N];//conc*tempo
    double conta2[N];//conc
    double conta3[N];//tempo
    double conta4[N];//pow tempo

     for(i=0;i<N;i++){
            conta1[i]=(concentracao2[i]*tempo[i]);
            conta2[i]= concentracao2[i];
            conta3[i]=tempo[i];
            conta4[i] = (pow(tempo[i],2));
    }


    for(i=0;i<N;i++){
            soma1=soma1 + conta1[i];
            soma2=soma2 + conta2[i];
            soma3=soma3 + conta3[i];
            soma4=soma4 + conta4[i];

    }

    a=((N*soma1) - (soma3*soma2))/ ((N*soma4) - pow(soma3,2));

    return a;

}

int main()
{

    int N=0; // numero de experimentos
    float *tempo ;
    float *concentracao;
    float *concentracao2;
    int i =0;
    float erro_ordem0=0;
    float erro_ordem1=0;
    float erro_ordem2=0;
    float menor=0;
    int opcao;
    double const_velocidade=0;

    printf("*****DETERMINACAO DA ORDEM E DA CONSTANTE DE VELOCIDADE ATRAVES DE DADOS EXPERIMENTAIS*****");
    printf("\n");
    printf("***Trabalho realizado por Luana Ferreira, Miriam Nadur e Bruna Leal***");
    printf("\n");
    printf("Para obter resultados satisfatorios, sera necessario definir a quantidade N de experimentos");
    printf(" para assim o usuario digitar N concentracoes com seus respectivos tempos. ");
    printf("O programa tem o intuito de aplicar os dados inseridos em calculos especificos da fisico-quimica e matematica, afim de encontrar");
    printf(" a constante de velocidade e a ordem de reacao. Esta ultima usou metodos de erro experimentais e plotagem");
    printf(" do grafico com dados experimentais e dados teoricos, afim de compara-los.");
    printf("\n");
    printf("Obrigado pela atencao!!");
    printf("\nDigite a quantidade de experimentos:");
    scanf("%i",&N);

    concentracao = malloc(sizeof(float) * N);
    concentracao2 = malloc(sizeof(float) * N);
    tempo = malloc(sizeof(float) * N);

    for(i=0;i<N;i++){

            printf("\nDigite a concentracao do experimento %i: ",i);
            scanf("%f", &concentracao[i]);
            setbuf(stdin,NULL);

            printf("\nDigite o tempo do experimento %i :",i);
            scanf("%f", &tempo[i]);
            setbuf(stdin,NULL);

    }

    erro_ordem0=ordem0(N,concentracao,tempo);

    erro_ordem1=ordem1(N,concentracao,tempo);

    erro_ordem2=ordem2(N,concentracao,tempo);

    menor=erro_ordem0;

    if(erro_ordem0>erro_ordem1){
            menor=erro_ordem1;
        if(erro_ordem1>erro_ordem2){
                menor=erro_ordem2;
        }
    }
    //aquele que possui o menor erro, é o mais proximo de uma reta, e portanto é a ordem certa
    //plotagem da ordem certa
    if(menor==erro_ordem0){
            printf("Com os dados inseridos descobriu-se que a reacao é de ordem 0!!");
            for(i=0;i<N;i++){
                    concentracao2[i]=concentracao[i];
            }
            const_velocidade=constante(N,concentracao2,tempo);
            printf("\nA constante de velocidade obtida pelos dados inseridos foi: %lf",const_velocidade);
            grafico0(N,concentracao,tempo);
    }
    if(menor==erro_ordem1){
            printf("Com os dados inseridos descobriu-se que a reacao é de ordem 1!!");
            for(i=0;i<N;i++){
                    concentracao2[i]=log(concentracao[i]);
            }
            const_velocidade=constante(N,concentracao2,tempo);
            printf("\nA constante de velocidade obtida pelos dados inseridos foi: %lf",const_velocidade);
            grafico1(N,concentracao,tempo);
    }
    if(menor==erro_ordem2){
            printf("Com os dados inseridos descobriu-se que a reacao é de ordem 2!!");
            for(i=0;i<N;i++){
                    concentracao2[i]= (float)1/concentracao[i];
            }
            const_velocidade=constante(N,concentracao2,tempo);
            printf("\nA constante de velocidade obtida pelos dados inseridos foi: %lf",const_velocidade);
            grafico2(N,concentracao,tempo);
    }



    return 0;
}
