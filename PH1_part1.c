#include <stdio.h>
#include <stdlib.h>

int main (int argc, char **argv){
    FILE *arq, *dest;

    int mem[256];
    int opcode;
    int dadomem;
    int cont;
    int pc = 0;
    int ac = 0;

    //Abrindo o arquivo de TEXTO para LEITURA
    arq= fopen("/home/eduarda/Documentos/oi.txt", "rt");
    if (arq == NULL){ //Se houver erro na abertura
        fprintf(stderr,"Erro na abertura do arquivo de origem\n");
        exit (1);   
        }
    else{
    printf("Arquivo aberto\n");
    }
    while (!feof(arq)){ //Le o arquivo enquanto ainda ha conteudo
        fscanf(arq, "%x %x", &opcode, &dadomem);
        mem[opcode] = dadomem;//Armazena os dados lidos no vetor
        printf("%x %x\n", opcode, dadomem);// Print para ter certeza de que leu
    }
        // Testes
        //Instrucoes que utilizam 1 Byte
            if(opcode = '0' || '7' || 'F' ){
                if(opcode = '0'){ //NOP
                fprintf (dest, "\n");    
                }
                if(opcode = '7'){ //NOT
                ac = !ac;
                fprintf (dest, "AC <- !AC");    
                }
                if(opcode = 'F'){ //HLT
                fprintf (dest, "HLT");   
                exit(1); 
                }
            }
        //Instrucoes que utilizam 2 Bytes
            else{
                
            }


}


