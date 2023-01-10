#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define TAM 80
#define TAMF 80
#define TAMP 40


char inverteFrase(char frase[]);
int contaPrimeiroChar(char frase[]);
int contaPrimeiroWord(char txt[]);
void injetar_palavra(char frase[], char word[], int pos);
void troca_ultimaPalavra(char frase[], char pal[], int tamF, int tamP);
void exercicio8F07(char str[], int tam, char c, int x);
//E09
void maior_string_com3C();
int conta_char(char frs[], int x, char c);
//E10
void operacoes_comVetores(char c);
void print_array(float array[], int tam);


int main() {
    printf("\n\tPROJETO DE FICHA 07!\n\n");

    int cont=0;
    char vet[] = "Ola Sr. Silva Baia, meu amigo";
    char aux[]="Agnelo";
    char st[TAMF]="Hello friend, good nigth!";
    char nova[TAMP]= "morning!";
    char oparation;


    printf("Introd a oprecao: ");
    scanf("%c", &operation);

    operacoes_comVetores(operation);


    //duplica_char(vet, TAMF, 'a');
    //injetar_palavra(vet, aux, 7);
    //troca_ultimaPalavra(st, nova, TAMF, TAMP);
    //exercicio8F07(aux, 10, 'H', 5);
    //maior_string_com3C();

    return 0;
}

//F07 - E01
char inverteFrase(char frase[]){
    int size = strlen(frase);
    char aux;

    for(int i=0; i<size/2; i++){
         aux = frase[i];
        frase[i] = frase[size - i -1]; //get de last elem
        frase[size - i - 1] = aux;
    }

    printf("Frase invertida: %s\n", frase);
}


//F07 - E02
int contaPrimeiroChar(char frase[]){
    int chInicial=0, size, i=0;
    char aux, frase2[TAM];

    size = strlen(frase);

    for(i=0; i<size; i++)
        if (frase[i] == ' '){
            frase[i] = frase[i+1];
            aux = frase[i];
        }
    printf("Sem espacos:%s\n", frase);
    printf("Aux: %c\n", aux);

    for(i=0; i<size; i++)
        if(toupper(aux) == toupper(frase[i])){
            chInicial++;
        }

    return chInicial;
}
int versaoProfE2(char txt[]){
    char first;
    int ocorre=0, i;

    while((first == txt[i++]) == ' ');
    do{
        if(toupper(txt[i]) == toupper(first))
            ocorre++;
    }while(txt[++i] != '\0');

    return ocorre;
}


//F07 - E03
/*char separarPalavras(char txt[]){
    char aux;
    int i=0;

    while((aux == txt[i++]) == ' ');


    do{
        eBranco = 0;
        while((c = getchar()) == ' ')//absorver eBrancos
            eBranco = 1;
        if(i && eBranco && c != '\n')
            txt[i] = '\n';
    }while(c != '\n');


}
*/

//07 - E04
int contaPrimeiroWord(char frase[]){
    char aux[TAM];
    int i, size, ocorre;

    size = strlen(frase);

    while((aux[i] == frase[i++]) == ' ');
    do{
        int j = strcasecmp(aux, frase);
        if(i == 0)
            ocorre++;
    }while(frase[++i] != '\0');

    printf("Sem espacos:%s\n", frase);
    printf("Aux: %s\n", aux);

    return ocorre;
}

//07 - E05
//inserir uma palavra numa frase
void injetar_palavra(char frase[], char word[], int pos){
    for(int i=0; frase[i]!='\0'; i++){
        printf("%c", frase[i]);
        if(i == pos)
            printf("%s ", word);
    }
    putchar('\n');
}

//07 - E06
//input: frase e um char; output: duplica este char cada vez
//que ele aparecer na frase.
void duplica_char(char frase[], int tam, char c){
    int i, j, lenF, lenAux;
    char aux[TAMF];

    lenF = strlen(frase); //calc tamanho da frase

    j=0;
    for(i=0; i < lenF; i++){
        aux[j] = frase[i];
        j++;
        //se encontrar a char procurada
        if(frase[i] == c){
            aux[j] = c; //adiciona este char ao novo string
            j++;  //avança
        }
    }

    lenAux = strlen(aux);
    aux[lenAux]='\0';
    printf("String com <%c> duplicado: %s\n", c, aux);
}

//07 - E07
//substituir a ultima palavra para nova (passada por arg)
//VOU USAR 'STRRCHR' -> ele obtem a última ocorência de um char.
// EX: strrchr(str, 'e'); -> procura a ultima ocorrência de char 'e' na string str.
void troca_ultimaPalavra(char frase[], char pal[], int tamF, int tamP){
    int len;

    //strrchr -> obtem e aponta para the last espace ' '
    char *aux = strrchr(frase, ' ');

    //se a frase só tem uma palavra (sem espaços)
    if(aux == NULL){
        aux = frase;
    }
    else{
        //avança para the first letter of last word
        aux++;
    }

    //ver se a frase vai ser modificada.
    if(strcmp(aux, pal) == 0)
        printf("A frase NAO foi modificada\n"); //return 0
    else
        printf("A frase FOI modificada\n"); //return 1

    len = strlen(pal); //obtem tamanho da palavra.

    //copia a palavra para o último espaço encontrado.
    strcpy(aux, pal);

    //finaliza o string.
    aux[len]='\0';

    printf("AUX: %s\n", aux);
    printf("NOVO: %s\n", frase);
}

int conta_palavras(char str[]){//não urilizado.
    int contP=1;
    for(int i=0; str[i]!='\0'; i++){
        if(str[i] == ' ')
            contP++;
    }
    return contP;
}


//07 - E08
//Duplica char (c) x vezes, no final da string (tudo <= 10)
void exercicio8F07(char str[], int tam, char c, int x){
    int i, len;
    char aux[tam];

    len = strlen(str);

    for(i=0; i < x; i++){
        //percorrer todas as chars e guardar em aux
        aux[i] = c;
    }

    //se o novo tamanho da str ñ for maior q string original
    if(x+len <= tam){
        //adicionara aux ao string original
        strcat(str, aux);
    }
    printf("New string: %s\n", str);
}


//07 - E09
//
int conta_char(char frs[], int x, char c){
    int i, nvzs, flag;

    for(i=0; i < strlen(frs) && flag==0; i++){
        if(frs[i] == c){
            //cada vez que o char aparecer consecutiva/te
            nvzs++;
        }
        else{
            nvzs=0;
        }

        if(nvzs == x){
            //se o char aparecer x vezes consecutivas
            flag=1;
        }
    }
    return flag;
}

//Obtem maior string onde char (c) apareceu x vezes consecutivas
void maior_string_com3C() {
    char str[TAMF], c;
    char maiorStr[TAMF] = "";
    int lenM=0, lenSt=0;

    //printf("Introd um caracter: ");
    //scanf(" %c", &c);

    fflush(stdin);

    do {
        printf("Introd uma frase: ");
        gets(str);

        lenSt = strlen(str); //calc tamanho da string
        lenM = strlen(maiorStr);  //calc tamanho do maior string

        if (conta_char(str, 3, 'a') && lenSt > lenM )
            strcpy(maiorStr, str);

        //termina o ciclo quando encontrar 'fim' (comp leixográficamente).
    } while (stricmp(str, "fim") != 0);

    printf("Maior string com 3 <%c>: %s\n", 'a', maiorStr);
}


//07 - E10
//Realizar operações entre dois vetores

//Imprimir vetor
void print_array(float array[], int tam){
    for(int i=0; i < tam; i++){
        printf(" %2.1f ", array[i]);
    }
    printf("\n");
}

//funciona - mas tenho q consultar bem
void operacoes_comVetores(char c){
    int i, tam=3;
    float vet1[tam], vet2[tam], res[]={0}; //estariam nos parâmetros

    printf("<<<<Vector 1>>>>\n");
    for(i=0; i < tam; i++){
        printf("valor %d: ", i+1); scanf("%f", &vet1[i]);
    }

    printf("\n<<<<Vector 2>>>>\n");
    for(i=0; i < tam; i++){
        printf("valor %d:", i+1); scanf("%f", &vet2[i]);
    }

    switch(c){
        case '+':
            for(i=0; i < tam; i++){
                res[i] = vet1[i] + vet2[i];
            } break;
        case '-':
            for(i=0; i < tam; i++){
                res[i] = vet1[i] - vet2[i];
            } break;
        case '*':
        case 'x':
        case 'X':
            for(i=0; i < tam; i++){
                res[i] = vet1[i] * vet2[i];
            } break;
        case '/':
        case ':':
            for(i=0; i < tam; i++){
                if(vet2[i]){
                    res[i] = vet1[i] / vet2[i];
                }
                else{
                    printf("Não pode dividir por ZERO!");
                    break;
                }
            } break;
        default:
            printf("Operacao Invalida!!\n");
    }

    putchar('\n');
    print_array(vet1, tam);
    print_array(vet2, tam);
    printf("-------------\n");
    print_array(res, tam);
}


