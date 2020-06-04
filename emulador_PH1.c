/*
             OPCODE
     BINÁRIO       HEXADECIMAL     INSTRUÇÃO
    0000 0000   =     0x00      =   NOP
    0001 0000   =     0x10      =   LDR  
    0010 0000   =     0x20      =   STR 
    0011 0000   =     0x30      =   ADD
    0100 0000   =     0x40      =   SUB
    0101 0000   =     0x50      =   MUL
    0110 0000   =     0x60      =   DIV
    0101 0000   =     0x70      =   NOT
    1000 0000   =     0x80      =   AND
    1001 0000   =     0x90      =   OR
    1010 0000   =     0xA0;     =   XOR
    1011 0000   =     0xB0      =   JMP
    1100 0000   =     0xC0      =   JEQ
    1101 0000   =     0xD0      =   JG
    1110 0000   =     0xE0      =   JL
    1111 0000   =     0xF0      =   HLT

*/

#include <stdio.h>
#include <stdlib.h>

int main (void){
    int mem [256]; 
    int pc = 0; //program counter
    int ac; //acumulador
    int ri; //registrador de instrucoes
    int rem; // reg. de endr. de memoria
    int rim; //reg. de dados de memoris
    int cont; // contador de instrucoes executadas
    
    FILE *file;
    
    //Abrindo o arquivo de TEXTO para LEITURA
   file = fopen("entrada01.txt", "r"); //Nao aponta em um end de memoria (o arq nao existe)
    if (file == NULL){ //Se houver erro na abertura
       printf("Arquivo nao pode ser aberto \n");
       getchar();
       exit (1);   
        }
    printf("Input file: entrada01.txt \n \n");
    
    while (!feof(file)){ //Le o arquivo enquanto ainda ha conteudo
        fscanf(file ,"%x %x", &endr, &info); // %x para hexadecimal
		mem[endr] = info;   
    }
    // Testes
        //Instrucoes que utilizam 1 Byte
            /*if(opcode = '0' || '7' || 'F' ){
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
                
            }*/
        


}


