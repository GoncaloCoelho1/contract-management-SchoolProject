#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include<conio.h>
#include <string.h>

struct Contrato{
    char nomeF[30];     //Nome do Funcionario
    char nomeE[40];     //Nome da Empresa
    char local[30];     //Localidade
    char descfuncao[50];    //Descricao da Funcao
    int dataI;      //Data de Inicio
    int tempC;      //Duracao do trabalho a termo
    int prazoAP;    //aviso Previo da cassasso do contrato
    double valorR;  //valor da remuneracao
    int num_cliente;  //numero de cliente
};
//declaracao dos nomes das funcoes
void cabecalho();
void mostrarcabecalho();
void mostrarContratos();
void atualizarContrato();
void input_contract();
int Menu();

//funcao principal
int main()
{
    int aux;
    do {//ciclo para mostrar o menu
	    system("cls");// limpa a tela

        aux = Menu();

        if(aux == 1){//se selecionar 1 vai deixar criar um contrato
            int i=1;
            while(i == 1){//ciclo while é executado se a condicao for verdadeira

                input_contract(); //seleciona 1 e o utilizador pode criar um contrato
                printf("\nAcrescentar Contrato: Sim->1 / Nao->0\n"); //pergunta ao utilizador se quer continuar a acrescentar contratos
                scanf("%d", &i);// obtem a resposta
            }
        }


        if(aux == 2)// se selecionar 2 vai mostrar todos os contratos existentes no ficheiro
        {
            mostrarContratos();//chama a funcao definida para ver todos os contratos feitos
            system("pause");// pausa o programa

        }
        else if(aux == 3)// se o utilizador escolher 3 vai atualizar o contrato
        {
            atualizarContrato();//chama a funcao definida para atualizar o contrato

        }

    }while(aux != 4);// seleciona 4 para sair do ciclo
    return 0;
}

void cabecalho()
{//funcao cabecalho, fica sempre no topo

    printf("##########################################################################################\n");
	printf("###################                    Gerir Contratos                 ###################\n");
	printf("##########################################################################################");

}

void input_contract()
{

    struct Contrato c1;

    printf("Informe o Funcionario(a): ");
    scanf("%s", c1.nomeF);
    printf("Informe o nome da empresa: ");
    scanf("%s", c1.nomeE);
    printf("Informe o local: ");
    scanf("%s", c1.local);
    printf("Descreva a sua funcao: ");
    scanf("%s", c1.descfuncao);
    printf("Designe o numero do cliente: ");
    scanf("%d", &c1.num_cliente);
    c1.dataI = 2022;
    c1.tempC = 2;
    c1.prazoAP = 5;
    c1.valorR = 645.0;


    FILE *fp = fopen("contrato.txt", "a");
    if (fp == NULL) {
           printf("ERRO! O arquivo não foi aberto!\n");
        // handle error
    }

    fprintf(fp,"%d,%s,%s,%s,%s,%d,%d,%d,%f\n", c1.num_cliente, c1.nomeE, c1.nomeF, c1.local, c1.descfuncao, c1.dataI, c1.tempC, c1.prazoAP, c1.valorR);

    fclose(fp);
}

 void mostrarContratos()// funcao definida para ver todos os contratos feitos
{
    mostrarcabecalho();// mostra o cabecalho do programa
    FILE* fp = fopen("contrato.txt", "r");//abre o ficheiro dos contratos


    char linha[500];//declaraçao da variavel linha para ler linha a linha

    while (fgets(linha, sizeof(linha), fp)) {//ciclo while para ler informacoes linha a linha ou seja lê uma linha, amazena a linha na variavel linha e faz isso para todas as linhas do ficheiro

        char virgula[] = ",";//da o valor "," à variavel virgula

        char *ptr = strtok(linha, virgula);//ponteiro que lerá a linha até a primeira vírgula que é o numero do cliente
        printf("%s", ptr);//mostra o numero do cliente
        printf("\t");
        ptr = strtok(NULL, virgula);//mete o apontador na posiçao da proxima virgula

        printf("%s", ptr);//mostra o nome da empresa
        printf("\t");
        ptr = strtok(NULL, virgula);

        printf("%s", ptr);//mostra o nome do empregado
        printf("\t");
        ptr = strtok(NULL, virgula);

        printf("%s", ptr);//mostra o local
        printf("\t");
        ptr = strtok(NULL, virgula);

        printf("%s", ptr);//mostra a descricao da funcao de trabalho
        printf("\t");
        ptr = strtok(NULL, virgula);

        printf("%s", ptr);//mostra a data de inicio
        printf("\t");
        ptr = strtok(NULL, virgula);

        printf("%s", ptr);//mostra a duraçao do trabalho
        printf("\t");
        ptr = strtok(NULL, virgula);

        printf("%s", ptr);//mostra o fim do contrato
        printf("\t");
        ptr = strtok(NULL, virgula);
        printf("%s", ptr);// mostra o valora de remuneraçao
        printf("\n");

    }
    fclose(fp);//fecha o ficheiro
    }

int Menu()//funcao menu, onde vai obter a opcao introduzida pelo utilizador
{
    int opcao;
    system("cls");
    cabecalho();//chama a funcao cabecalho que fica no topo

    printf("\n[1] Criar contrato");
    printf("\n[2] Ver todos os contratos criados");
    printf("\n[3] Atualizar um contrato");
    printf("\n[4] Sair");
    printf("\n");
    printf("\nEntre com a sua escolha:  ");
    scanf("%d",&opcao); //recebe a opcao introduzida pelo utilizador
    return opcao;
}

void mostrarcabecalho()//funcao para uma melhor organizacao dos dados
{
    system("cls");
    cabecalho();
    printf("\n");
    printf("\n");
    printf("Cli\tEmp\tNome\tLocal\tDesc\tDataI\tTempC\tFimC\tRem\t"); //modelo de apresentacao
    printf("\n");
    printf("\n");
}

void atualizarContrato()//funcao que serve para procurar um contrato no ficheiro(de acordo com o numero de cliente) e com base na decisao do usuario, decidir se o altera ou nao
{
    int verifica = 1;// variavel auxiliar que verifica a existencia do contrato com base no numero de cliente
    int Local;//variavel usada para encontrar o local da matriz onde o contrato esta, dependendo do numero de cliente foi guardado
    int NumCliente;
    int cont = 0;//variável para contar o número do contrato do arquivo
    system("cls");//limpa a tela
    cabecalho();//chama a funcao cabecalho

    printf("\n-> Introduza o numero de cliente\n");// pede o numero de cliente
    scanf("%d", &NumCliente);//guarda o numero de cliente

    FILE* fp = fopen("Contrato.txt", "r");//abre o ficheiro para contar o numero de contratos(pelas linhas existentes)
    char linha[500];
    if(fp != NULL)//o codigo so vai executar se a conficao for verdadeira
    {
        while (fgets(linha, sizeof(linha), fp)) //enquanto forem encontradas linhas continua a incrementar
        {
            cont++;//variavel incrementada
        }
        fclose(fp);


        struct Contrato c;//declaracao da variavel que representa a estrutura contrato
        struct Contrato *MatrizContrato;//declara a matriz de ponteiros para a estrutura contrato para armazenar o contrato dinamicamente
        MatrizContrato = (struct Contrato*)calloc(cont , sizeof(struct Contrato));//alocar a memoria especifica de acordo com o tamanho da matriz (variavel cont é o numero de linhas da matriz)


        if(MatrizContrato == NULL)//se a a alocacao falhar
        {
            printf("ERRO! Memoria nao alocada");
            exit(1);//programa fecha com erro de memoria nao alocala
        }

        FILE* file = fopen("Contrato.txt", "r");//abrir o ficheiro contrato em modo de leitura
        int i = 0;
        while (fgets(linha, sizeof(linha), file))//ciclo while para ler linha a linha a partir do ficheiro
        {

            char virgula[] = ",";
            char *ptr = strtok(linha, virgula);//ponteiro incializado com o endereço do primeiro parametro ate à virgula

            int num = atoi(ptr);//variavel que vai guardar o valor de ptr como inteiro
            c.num_cliente = num;//coloca o valor do numero encontrado no ficheiro, na estrutura do contrato

            if(NumCliente == c.num_cliente) //se o numero introduzido pelo utilizador for igual ao que foi colocado na estrutura ele executa a condicao
            {
                Local = i; //coloca o valor de i na variavel local que é a linha da matriz onde nos encontramos
                verifica = 2; //passa de 1 para 2 quando a condicao é verdadeira
            }
            ptr = strtok(NULL, virgula);// passar NULL como o primeiro argumento indica que a função deve continuar a partir da última posição em que foi chamada até à proxima virgula
            strcpy(c.nomeF, ptr);//funcao strcpy vai copiar o valor colocado anteriormente em ptr na nossa estrutura e neste caso no parametro nomeF

            ptr = strtok(NULL, virgula);
            strcpy(c.nomeE, ptr);

            ptr = strtok(NULL, virgula);
            strcpy(c.local, ptr);

            ptr = strtok(NULL, virgula);
            strcpy(c.descfuncao, ptr);

            ptr = strtok(NULL, virgula);
            c.dataI = atoi(ptr);//converter de alfanumerico para inteiro devido a tpr ser uma string e queremos o valor inteiro

            ptr = strtok(NULL, virgula);
            c.tempC = atoi(ptr);

            ptr = strtok(NULL, virgula);
            c.prazoAP = atoi(ptr);

            ptr = strtok(NULL, virgula);
            double num2 = atoi(ptr);//recebe o valor em inteiro e agora tem que passar a double
            c.valorR = (double)num2;//converter de inteiro para double fazendo CAST

            MatrizContrato[i] = c; //adiciona os valores da estrutura numa determinada linha da matriz que é a linha onde foi encontrado o numero de cliente
            i = i + 1;//incrementa a variavel para passar de linha

        }
        fclose(file);//fecha o ficheiro

        if(verifica != 1)//condicao que verifica se o contrato foi encontrado(valor 2) ou nao (valor 1) e se for encontrado executa
        {
            int opcao; //variavel para obter a opcao do utilizador
            mostrarcabecalho(); //funcao modelo
            //mostra os dados todos do contrato no ecra
            printf("%d", MatrizContrato[Local].num_cliente);printf("\t");
            printf("%s", MatrizContrato[Local].nomeF);printf("\t");
            printf("%s", MatrizContrato[Local].nomeE);printf("\t");
            printf("%s", MatrizContrato[Local].local);printf("\t");
            printf("%s", MatrizContrato[Local].descfuncao);printf("\t");
            printf("%d", MatrizContrato[Local].dataI);printf("\t");
            printf("%d", MatrizContrato[Local].tempC);printf("\t");
            printf("%d", MatrizContrato[Local].prazoAP);printf("\t");
            printf("%f", MatrizContrato[Local].valorR);printf("\t");
            //verifica se o utilizador quer realmente alterar o contrato
            printf("\n-> Quer alterar o contrato?\n->Pressione 1 para alterar ou qualquer outro valor para voltar ao menu principal");
            printf("\n->introduza a sua escolha: ");
            scanf("%d",&opcao);//obtem a variavel
            if(opcao == 1)//se a opcao introduzida for "1" o utilizador vai poder alterar o contrato
            {
                //declaracao de variaveis auxiliares iguais à estrutura contrato
                char nomeE[30];
                char nomeF[40];
                char local[30];
                char descfuncao[50];
                int dataI;
                int tempC;
                int prazoAP;
                double valorR;
//entrar com os novos dados do contrato
//atualiza os valores na linha da matriz anteriomente encontrada
                printf("\n->Atualizar nome da empresa: ");
                scanf("%s",&nomeE);//armazena o valor na variavel auxiliar
                strcpy(MatrizContrato[Local].nomeE, nomeE);//copiar o valor auxiliar para dentro do parametro nomeE da linha da matriz
                printf("\n->Atualizar nome do funcionario: ");
                scanf("%s",&nomeF);
                strcpy(MatrizContrato[Local].nomeF, nomeF);
                printf("\n->Atualizar local: ");
                scanf("%s",&local);
                strcpy(MatrizContrato[Local].local, local);
                printf("\n->Atualizar funcao: ");
                scanf("%s",&descfuncao);
                strcpy(MatrizContrato[Local].descfuncao, descfuncao);
                printf("\n->Atualizar data de inicio: ");
                scanf("%d",&dataI);
                MatrizContrato[Local].dataI = dataI;
                printf("\n->Atualizar Duracao do trabalho: ");
                scanf("%d",&tempC);
                MatrizContrato[Local].tempC = tempC;
                printf("\n->Atualizar fim do contrato: ");
                scanf("%d",&prazoAP);
                MatrizContrato[Local].prazoAP = prazoAP;
                printf("\n->Atualizar valor de remuneracao: ");
                scanf("%lf",&valorR);
                MatrizContrato[Local].valorR = valorR;
                printf("\n Contrato atualizado com sucesso!");

//neste momento todos os dados inseridos estao inseridos numa das linhas da matriz contrato

                FILE* fw = fopen("Contrato.txt", "w");//abrir o ficheiro para escrita desses dados
                int z = 0;
                if(fw != NULL) //se fw for diferente de NULL o ficheiro vai abrir
                {
                    while (z != cont) //enquanto z for diferente de cont ele imprime os valores de todos os parametros dessa linha da matriz
                    {
//coloca as informacoes atualizadas de volta no ficheiro sempre com os parametros separados por virgulas
                        fprintf(fw,"%d",MatrizContrato[z].num_cliente);fprintf(fw,"%s",",");
                        fprintf(fw,"%s",MatrizContrato[z].nomeF);fprintf(fw,"%s",",");
                        fprintf(fw,"%s",MatrizContrato[z].nomeE);fprintf(fw,"%s",",");
                        fprintf(fw,"%s",MatrizContrato[z].local);fprintf(fw,"%s",",");
                        fprintf(fw,"%s",MatrizContrato[z].descfuncao);fprintf(fw,"%s",",");
                        fprintf(fw,"%d",MatrizContrato[z].dataI);fprintf(fw,"%s",",");
                        fprintf(fw,"%d",MatrizContrato[z].tempC);fprintf(fw,"%s",",");
                        fprintf(fw,"%d",MatrizContrato[z].prazoAP);fprintf(fw,"%s",",");
                        fprintf(fw,"%f",MatrizContrato[z].valorR);fprintf(fw,"%s",",");
                        fprintf(fw,"%s","\n"); //enter
                        z = z + 1; //incrementa a variavel
                    }
                    fclose(fw);//fecha o ficheiro depois de introduzir os dados atualizados
                }
                else
                {
                    printf("!!Erro!! ficheiro nao encontrado");
                }
                system("pause");

            }


        }
        else//caso o contrato nao for encontrado mostra o seguinte na tela
        {
            printf("->Nenhnum contrato foi encontrado com este numero de cliente ");
            system("pause");
        }
        free(MatrizContrato);//libertar a memoria introduzida anteriomente
    }
    else //ficheiro nao encontrado
    {
        printf("!!Erro!! ficheiro nao encontrado");
        system("pause");
    }
}
