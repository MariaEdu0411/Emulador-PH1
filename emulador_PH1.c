/*
                 OPCODE
	     
     BINÁRIO       HEXADECIMAL     INSTRUÇÃO
    0000 0000   =     0x00      =    NOP
    0001 0000   =     0x10      =    LDR  
    0010 0000   =     0x20      =    STR 
    0011 0000   =     0x30      =    ADD
    0100 0000   =     0x40      =    SUB
    0101 0000   =     0x50      =    MUL
    0110 0000   =     0x60      =    DIV
    0101 0000   =     0x70      =    NOT
    1000 0000   =     0x80      =    AND
    1001 0000   =     0x90      =    OR
    1010 0000   =     0xA0;     =    XOR
    1011 0000   =     0xB0      =    JMP
    1100 0000   =     0xC0      =    JEQ
    1101 0000   =     0xD0      =    JG
    1110 0000   =     0xE0      =    JL
    1111 0000   =     0xF0      =    HLT

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
    printf("Input file: entrada01.txt \n");
    printf("\n");
    
    while (!feof(file)){ //Le o arquivo enquanto ainda ha conteudo
        fscanf(file ,"%x %x", &endr, &info); // %x para hexadecimal
	mem[endr] = info; // guradando todas os dados contidos no arquivo no vetor mem com indice endr   
    }
    do{//Percorrendo todo o vetor até um break
        // Passando as informaçoes para os registradores     
        rem = pc;
        rdm = mem[rem];
        ri = rdm;
        
        //Testando no conj. de instruçoes do PH1
        //NOP
        if(ri == 0x00){ 
            pc = pc+1; //Regra sem exceçao, utiliza 1 Byte
	    printf("NOP;\n");
	    execut++;
	    continue;
	}
        //LDR
        if(ri == 0x10){
            pc = pc+2; //Utiliza 2 Bytes 
            printf("LDR %x; ", rdm);
            printf("AC <- MEM[%x]\n", rdm);
            rem = rdm;
            rdm = mem[rem];
            ac = rdm; // dado contido na no end de mem vai pro ac
            execut++;
	    continue;
            
        }
        //STR
        if(ri == 0x20){
            pc=pc+2;
            printf("STR %x; ", rdm);
            printf("MEM[%x] <- AC\n", rdm);
            rem = rdm;
            rdm = ac; //reg. de mem recebe o valor contido no ac
            mem[rem] = rdm;
            execut++;
	    continue;
        }
	    //ADD
        if(ri == 0x30){
            pc = pc + 2;
            printf("ADD %x; ", rdm);
            printf("AC <- AC + MEM[%x]", rdm);
            rem = rdm;
            rdm = mem[rem];
            ac= ac + rdm;
            execut++;
            continue;
        }
        //SUB
        if(ri == 0x40){
            pc = pc + 2;
            printf("SUB %x; ", rdm);
            printf("AC <- AC - MEM[%x]", rdm);
            rem = rdm;
            rdm = mem[rem];
            ac= ac - rdm;
            execut++;
            continue;
        }
        //MUL
        if(ri == 0x50){
            pc = pc + 2;
            printf("MUL %x; ", rdm);
            printf("AC <- AC * MEM[%x]", rdm);
            rem = rdm;
            rdm = mem[rem];
            ac= ac * rdm;
            execut++;
            continue;
        }
        //DIV
        if(ri == 0x60){
            pc = pc + 2;
            printf("ADD %x; ", rdm);
            printf("AC <- AC / MEM[%x]", rdm);
            rem = rdm;
            rdm = mem[rem];
            ac= ac / rdm;
            execut++;
            continue;
        }
        
    }while(1) //loop infinito

    printf("\n");
    printf("% instructions executed\n",  execut);
    printf("\n");
    printf("Registers:\n");
    printf("AC &x\n", ac);
    printf("PC %x\n", pc);
    printf("\n");
    printf("Memory:\n");
    
    int i; 
    for(i = 128; i < 131; i++){ // 80 = 128
        printf("%x %x\n", i, mem[i]);
    }
    return 0;
}

