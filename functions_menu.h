#include "header_includer.h"
void swaper(int *a,int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
void FillTimeInfs(){
    time_t rawtime;
    struct tm * timeinfo;
    time( &rawtime );
    timeinfo = localtime( &rawtime );
    //printf("%02d:%02d:%02d", timeinfo->tm_hour, timeinfo->tm_min,timeinfo->tm_sec);
    clocks[0] = timeinfo->tm_hour;
    clocks[1] = timeinfo->tm_min;
    dates[0] = timeinfo->tm_year+1900;
    dates[1] = timeinfo->tm_mon+1;
    dates[2] = timeinfo->tm_mday;
}
int findindex(int cn[],int n){
    for(int i=0;i<n;i++){
        if(cn[i] == 0){
            return i;
        }
    }
    return -1;
}
void quicksort(int a[],int n){
    //srand(time(0));
    int c;
    static int counter = 0;
    int co[n];
    for (int i=0;i<n;i++){
        co[i] = 0;
    }
    int k;
    int i;
    while(counter != n){
        i = findindex(co,n);
        c = a[i];
        //printf("\ni: %d\n",i);
        k = i+1;
        for(int j=i;j<n;j++){
            if(co[j]==1){
                break;
            }
            if(a[j] < c){
                swaper(&a[j],&a[k]);
                k++;
            }
        }
        swaper(&a[i],&a[k-1]);
        co[k-1] = 1;
        counter++;
       // printf("\n\n");
    }
}
int NumberOfTicketFile(){
    struct Ticket ticketst;
    FILE *fileName;
    int n = 0;
    fileName = fopen("ticket.txt","rb+");
    while(!feof(fileName)){
        n++;
        fread(&ticketst, sizeof(struct Ticket),1,fileName);
   //     printf("number of sans : %d\n",sansst.sansId);
    }
    fclose(fileName);
    return n - 1;
}
int NumberOfMoivesFile(){
    struct Movie moivest;
    FILE *fileName;
    int n = 0;
    fileName = fopen("Movies.txt","rb+");
    while(!feof(fileName)){
        n++;
        fread(&moivest, sizeof(struct Movie),1,fileName);
   //     printf("number of sans : %d\n",sansst.sansId);
    }
    fclose(fileName);
    return n - 1;
}
int NumberOfSansFile(char str){
    struct Sans sansst;
    FILE *fileName;
    int n = 0;
    fileName = fopen("Hall1.txt","rb+");
    while(!feof(fileName)){
        n++;
        fread(&sansst, sizeof(struct Sans),1,fileName);
   //     printf("number of sans : %d\n",sansst.sansId);

    }
    fclose(fileName);
    return n - 1;
}
int DiffBetweenDates(int date1[],int begTime1[],int begTime2[], int date2[]){
    int min1 = 0,min2 = 0 ;
    min1 = 60*begTime1[0] + begTime1[1];
    min2 = 60*begTime2[0] + begTime2[1];
    int min = 0;
    min += (date2[1]-date1[1])*30*24*60 + (date2[2] - date1[2])*24*60;
    min += min2-min1;
    return min;
}
void Nameprinter(char s[]){
    srand(time(NULL));
    int u = 182;
    SetConsoleTextAttribute(handles,u);

    for(int i=0;i<strlen(s);i++){
        if(s[i] >= 'A' && 'Z' >= s[i] && i != 0) {
            printf(" %c",s[i]);
        }else{
            printf("%c",s[i]);
        }
    }
    SetConsoleTextAttribute(handles,176);
}
void MenuPrinter(){
    printf("Enter the number of your selected item:\n\n");
    printf("-------------------------------------------------------------------------------------------------------\n");
    printf("|Buy a ticket : 1                                                                                      \n");
    printf("|Add a sans: 2                                                                                         \n");
    printf("|Movies : 3                                                                                            \n");
    printf("|Tickets : 4                                                                                           \n");
    //printf("|MovieTheaters : 4\n");
    //printf("|Add new movie :5\n");
    printf("|About us :5                                                                                           \n");
    printf("|Exit : 0                                                                                              \n");
    printf("-------------------------------------------------------------------------------------------------------\n");
}
/*void AppendMoive(){ //adding a movie end of the file Moives.
    FILE *movieFile;
    struct Movie movie;
    movie.id = moiveId;
    printf("\t\t\tEnter the name of the movie: ");
    //gets(movie.name);
    scanf("%s",movie.name);
    printf("\n\n\n%s",movie.name)
    printf("\t\t\tEnter the directors name: ");
    //puts((*movie).director);
    scanf("%s",movie.director);
    printf("\t\t\tEnter the year Of Publish: ");
    scanf("%d",&movie.yearOfPublish);
    printf("\t\t\tEnter time long(min): ");
    scanf("%d",&movie.timelong);
    printf("\t\t\tEnter genre: ");
    scanf("%s",movie.genre);
    printf("\t\t\tEnter Summary(if you want to pass just enter 0): \n");
    scanf("%s",movie.summary);
    //gets(movie.summary);
    printf("\t\t\tEnter some Actors name:");
    for(int i=0 ; i<4 ;i++){
        scanf("%s",movie.actorsName[i]);
    }
    printf("%s",movie.name);
    fseek(movieFile,0,SEEK_END);
    fwrite(&movie,sizeof(struct Movie),1,movieFile);
    fclose(movieFile);
}
void MainMenu(){

}

*/
