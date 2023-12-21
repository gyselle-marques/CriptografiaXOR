#include <stdio.h>

int main (int args, char *argv[]){
FILE *file1, *file2; //ponteiros para os arquivos 1 e 2
char *chave; //chave recebida por argumento
int c; //indexação da chave

chave = argv[1]; //chave como primeiro argumento
if (*chave != '\0'){ //verificação do ponteiro da chave
    file1 = fopen(argv[2], "rb"); //abre o arquivo 1 (original) no modo de leitura binária
    if (file1 != NULL) { //verificação do arquivo 1
        file2 = fopen(argv[3], "wb"); //abre o arquivo 2 (cria um novo) no modo de gravação binária
        if (file2 != NULL){ //verificação do arquivo 2
            while((c = getc(file1)) != EOF){ //leitura dos caracteres até o final do arquivo
                if(!*chave) chave = argv[1]; //ponteiro da chave utilizando o primeiro argumento
                c ^= *(chave++); //operação XOR nos caracteres do arquivo 1 com iteração da chave
                putc(c, file2); //incluindo os caracteres criptografos no arquivo 2
            }
            fclose(file2); //fecha arquivo 2
        }
        fclose(file1); //fecha arquivo 1
    }
}
return 1; //retorno verdadeiro
}
