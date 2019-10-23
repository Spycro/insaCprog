#include <stdio.h>
#define Question
void fillRewind();
void remplace(int pos,char ch,FILE* file);
int nbLigne(FILE* file);

int main(int argc, char const *argv[])
{
    #ifdef Question1
    FILE* fichier= fopen("texte","r");
    char c;
    while((c=fgetc(fichier))!=EOF){

        printf("%c",(char)c);
    }

    fclose(fichier);
    #endif

    #ifdef Question2
    FILE* fichier= fopen("texte","r");
    char c;
    while((c=fgetc(fichier))!=EOF){

       fputc(c,stdout);
    }

    fclose(fichier);
    #endif

    #ifdef Question3
    FILE* depart= fopen("texte","r");
    FILE* arrive= fopen("copie","w");
    char c;
    while((c=fgetc(depart))!=EOF){
       fputc(c,arrive);
    }
    fclose(depart);
    #endif

    #ifdef Question4
    FILE* depart= fopen("texte","r");
    FILE* arrive= fopen(argv[1],"w");
    char c;
    while((c=fgetc(depart))!=EOF){
       fputc(c,arrive);
    }
    fclose(depart);
    #endif

    #ifdef Question5et6
    fillRewind();

    char in=0;
    int offset=0;
    while(in!='q'){

        FILE* fichier=fopen("question5","r+w");
        char c;
         while((c=fgetc(fichier))!=EOF){

            printf("%c",(char)c);
         }
        scanf(" %c", &in);
        scanf("%d",&offset);
        while(in=='\n'){
            scanf(" %c", &in);
        }
        while(offset<0||offset>800){
            scanf("%d",&offset);
        }

        remplace(offset,in,fichier);
        fclose(fichier);
    }
    #endif

    return 0;
}

void fillRewind(){

    FILE* arrive= fopen("question5","w");
    rewind(arrive);
    for(int i=0;i<20;i++){
        for(int j=0;j<40;j++){
            fputc('_',arrive);
        }
        fputc('\n',arrive);
    }
    for(int i=0;i<3;i++){
        for(int j=0;j<10;j++){
            fputc(' ',arrive);
        }
        fputc('\n',arrive);
    }
    rewind(arrive);
    fclose(arrive);


}

void remplace(int pos,char ch,FILE* file){
    fseek(file,pos,SEEK_SET);
    fputc((int)ch,file);

}

int nbLigne(FILE* file){

    int nbL=1;
    char c;
    while((c=fgetc(file))!=EOF){
        if(c==10){

            nbL++;
        }
    }
    rewind(file);
    return nbL;
}
