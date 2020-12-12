#include <stdio.h>
#include <string.h>
#include <stdlib.h> rand()
#include <time.h> time()
// chcp 65001

void sayHi()
{
    printf("hi");
}

void greet(char name[], int age)
{
    printf("Hello %s, your age is %d", name, age);
}

int maxNum(int num1, int num2, int num3)
{
    int result;
    if (num1 >= num2 && num1 >= num3)
    {
        result = num1;
    }
    else if (num2 >= num1 && num2 >= num3)
    {
        result = num2;
    }
    else
    {
        result = num3;
    }
    return result;
}

double elevaAoCubo(double num)
{
    double result = num * num * num;

    return result;
}

//struct
struct Estudante
{
    char nome[50];
    int idade;
    double media;
};

//função gera número randomico

int random_int(int min, int max)
    {
        return min + rand() % (max + 1 - min);
    }

int main()
{

    // //variáveis
    const char nome[] = "Renan";
    const char sobrenome[] = "Felice";
    int idade = 32;
    printf("Olá, meu nome é %s %s\n", nome, sobrenome);
    printf("Eu tenho %d anos\n", idade);
    idade++;
    printf("Agora eu tenho %d anos", idade);
    printf("\n");

    //ponteiros - armazenar endereço de memória
    int * pIdade = &idade;
    printf("endereço de memória da variável idade:  %p\n", &nome);

    //tipo de dados
    int numeroInteiro = 10;
    printf("%d\n", numeroInteiro);

    double numeroDecimal  = 3.15;
    printf("%.2f\n", numeroDecimal);

    char caracterUnico = 'A';
    printf("%c\n", caracterUnico);

    char frase [] = "quando queremos escrever mais de um caracter devemos usar um array de char";
    printf("%s\n", frase);

    //pegando input do usuário
    double altura;
    char sexo;
    char nomeFilha [50];
    printf("Digite a sua altura: ");
    scanf("%lf", &altura);
    printf("informe o seu Sexo (apenas 1 caractere) ");
    scanf(" %c", &sexo);

    //as duas linhas abaixo removem a quebra de linha inserida pelo scanf
    scanf("%*[^\n]");
    getchar();

    printf("qual o nome da sua filha? ");
    // não é necessário o ponteiro & para capturar strings no scanf, porém ele para quando encontra um espaço em branco
    // scanf("%s", nomeFilha);

    //fgets consegue capturar strings com espaços em branco
    fgets(nomeFilha, 50, stdin);
    printf("A sua altura é %.2f\n", altura);
    printf("o seu sexo é %c\n", sexo);
    printf("o nome da sua filha é %s\n", nomeFilha);

    //arrays
    int luckyNumbers [] = {4, 8, 15, 16, 23, 42};
    printf("luckyNumbers arr %d\n", luckyNumbers[0]);

    int otherNumbers[10];
    otherNumbers[0] = 100;
    printf("otherNumbers arr %d\n", otherNumbers[2]);

    //functions

    sayHi();
    printf("\n");
    greet("Renan", 33);

    printf("informe um número para elevar ao cubo: ");
    double numUsuario;
    scanf("%lf", &numUsuario);
    printf("o número %f elevado ao cubo é: %f", numUsuario, elevaAoCubo(numUsuario));

    //if

    printf("o número máximo é: %d\n", maxNum(6, 5, 4));

    //struct
    struct Estudante estudanteTeste;
    estudanteTeste.idade = 20;
    estudanteTeste.media = 8.5;
    strcpy(estudanteTeste.nome, "Renan");

    printf("O nome do estudante é %s, sua idade é %d e sua média é %.1f", estudanteTeste.nome, estudanteTeste.idade, estudanteTeste.media);

    //while
    int index = 0;
    while (index <= 5)
    {
        printf("while loop, o index é %d\n", index);
        index++;
    }

    for (int i = 10; i <= 20; i++)
    {
        printf("for loop, o index é: %d\n", i);
    }

    //matriz
    int matNum[3][2] = {{11, 12}, {25, 26}, {30, 35}};

    int k, j;
    for (k = 0; k < 3; k++)
    {
        for (j = 0; j < 2; j++)
        {
            printf("%d\n", matNum[k][j]);
        }
    }

    int *p = (int *)malloc(sizeof(int));

    if(p == NULL){
        printf("alocação de memória falhou");
    }

    *p = 1050;

    printf("o valor armazendo no ponteiro p eh: %d e seu endereco de memoria eh: %p", *p, p);

    printf("numero randomico: %d", random_int(500, 1000));
    

    return 0;
}
