#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <string>

using namespace std;


int main(){
    FILE *arq = fopen("alunos.txt", "r");
    FILE *arq2 = fopen("conceitos.txt", "w");
    char *strTmp = new char[100];
    
    if(arq && strTmp && arq2){
        fgets(strTmp, sizeof(char)*100, arq);
        fwrite(&strTmp[1], sizeof(char),4,arq2);

        fgets(strTmp, sizeof(char)*100, arq);
        fwrite(&strTmp[6], sizeof(char), 36 - 6, arq2);

        fgets(strTmp, sizeof(char)*100, arq);
        
    }


}