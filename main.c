#include "header_includer.h"
#include "structures.h"
#include "functions_menu.h"
void MainList();

void FindMoiveWithId(int id ,int flag) {
    FILE *movieFile;
    struct Movie moviest;
    //printf("fuck it bitch");
    movieFile = fopen("Movies.txt", "rb");
    while (!feof(movieFile)) {
        fread(&moviest, sizeof(moviest), 1, movieFile);
        if (id == moviest.id) {
            printf("\t*** ");
            Nameprinter(moviest.name);
            printf("  (%d)***\n", moviest.yearOfPublish);
            if(flag == 0 ){
                printf("|Director:");
                Nameprinter(moviest.director);
                printf("    time long : %d\n",moviest.timelong);
                printf("|genre: %s    Rate: %.1f\n",moviest.genre,moviest.rate);
            }
            fclose(movieFile);
            return;
        }
    }
    printf("\t\t\t<<<<<not Found!!!!!!>>>>");
}
void DeletFromSanss(char str[], int id){
    FILE *hallFile;
    int numberOfsans = NumberOfSansFile(str);
    struct Sans sansst[numberOfsans];
    hallFile = fopen(str,"rw");
    int i = 0;
    while(!feof(hallFile)){
        fread(&sansst[i], sizeof(sansst),1,hallFile);
        i++;
    }
    fclose(hallFile);
    hallFile = fopen(str,"wb");
    for(int i = 0 ;i<numberOfsans ;i++ ){
        if(sansst[i].sansId != id) {
            fwrite(&sansst[i], sizeof(sansst), 1, hallFile);
        }
    }
    fclose(hallFile);
}
void ShowListOfMoives(){
    FILE *movieFile;
    struct Movie moviesst;
    movieFile = fopen("Movies.txt","rb+");
    while(!feof(movieFile)){
        fread(&moviesst, sizeof(struct Movie),1,movieFile);
        //printf("___________________________________________________________________________________________________\n");
        printf("*** ");
        Nameprinter(moviesst.name);
        printf("   (%d)***\n", moviesst.yearOfPublish);
        printf("\t\tDirector:");
        Nameprinter(moviesst.director);
        printf("    time long : %d\n",moviesst.timelong);
        printf("\t\tgenre: %s    Rate: %.1f\n",moviesst.genre,moviesst.rate);
        printf("____________________________________________________________________________________________________\n\n");
    }
    fclose(movieFile);
    printf("<<<for back enter 0:");
    int check;
    while(1){
        scanf("%d",&check);
        if(check == 0){
            system("cls");
            MainList();

        }else{
            printf("\t\t<<<try again if you dear: ");
            continue;
        }
    }
}

int showListOfSans(char str,int flag){
    FILE *hallFile,*before , *ticketFile;
    struct Ticket ticketst;
    int checkp;
    int i = 1;
    struct Sans sansst;

    ticketFile = fopen("ticket.txt","ab");
    hallFile = fopen("Hall1.txt","rb+");
    while(!feof(hallFile)){
        before = hallFile;
        fread(&sansst, sizeof(sansst),1,hallFile);
            if(flag == 1) {
                FindMoiveWithId(sansst.moiveId, flag);
                printf("|Sans %d   %d:%d\n", sansst.numberOfSans, sansst.beginningTime[0],sansst.beginningTime[1]);
                printf("|%d/%d/%d/\n", sansst.date[0], sansst.date[1], sansst.date[2]);
                if (sansst.numberOfEmptyChairs) {
                    printf("|%d Free chairs\n", sansst.numberOfEmptyChairs);
                } else {
                    printf("|<<Full!!>>\n");
                }
                printf("|enter %d for buy\n",i);
                printf("-------------------------------------------------------------\n");
            }else{
                FindMoiveWithId(sansst.moiveId,0);
                printf("|Sans %d   %d:%d\n", sansst.numberOfSans, sansst.beginningTime[0],sansst.beginningTime[1]);
                printf("|Date : %d/%d/%d/\n", sansst.date[0], sansst.date[1], sansst.date[2]);
                printf("|For buy enter 1\n|For back enter 0\n");
                printf("--------------------------------------------------------------\n\n");
                while(1){
                    scanf("%d",&checkp);
                    if(checkp != 1 && checkp != 0 ){
                        continue;
                    }else{
                        break;
                        }
                }
                if(checkp==1 && sansst.numberOfEmptyChairs != 0){
                    system("cls");
                    printf("=======================================================================================================================\n");
                    printf("please enter your first name :");
                    scanf("%s", ticketst.firstName);
                    printf("please enter your last name :");
                    scanf("%s", ticketst.lastName);
                    printf("<<<thanks for buying!!\n");
                    ticketst.numberOfHall = 1;
                    ticketst.numberOfSans = sansst.numberOfSans;
                    ticketst.beginningTime[0] = sansst.beginningTime[0];
                    ticketst.beginningTime[1] = sansst.beginningTime[1];
                    sansst.numberOfEmptyChairs--;
                    fwrite(&sansst, sizeof(sansst), 1, before);
                    fwrite(&ticketst, sizeof(ticketst),1,ticketFile);
                }
                system("csl");
                fclose(hallFile);
                fclose(ticketFile);
                MenuPrinter();
            }
            i++;
        }
    fclose(hallFile);
}
int SearchAndPrintSans(int diff,char str[],int flag /*0 for full 1 for little informations.*/){
    FILE *hallFile,*before , *ticketFile;
    struct Ticket ticketst;
    int checkp;
    struct Sans sansst;
    ticketFile = fopen("ticket.txt","ab");
    hallFile = fopen("Hall1.txt","rb");
    while(!feof(hallFile)){
        before = hallFile;
        fread(&sansst, sizeof(sansst),1,hallFile);
        if(diff == DiffBetweenDates(dates,clocks,sansst.beginningTime,sansst.date)){
            if(flag == 1) {
                FindMoiveWithId(sansst.moiveId, flag);
                printf("|Sans %d   %d:%d\n", sansst.numberOfSans, sansst.beginningTime[0],sansst.beginningTime[1]);
                printf("|%d/%d/%d/\n", sansst.date[0], sansst.date[1], sansst.date[2]);
                if (sansst.numberOfEmptyChairs) {
                    printf("|%d Free chairs\n", sansst.numberOfEmptyChairs);
                } else {
                    printf("\t<<Full!!>>\n");
                }
                //printf("|sans Id (for buy)\n");
                printf("-------------------------------------------------------------\n");
            }else{
                FindMoiveWithId(sansst.moiveId,0);
                printf("|Sans %d   %d:%d\n", sansst.numberOfSans, sansst.beginningTime[0],sansst.beginningTime[1]);
                printf("|Date : %d/%d/%d/\n", sansst.date[2], sansst.date[1], sansst.date[0]);
                printf("|For buy enter 1\n|For back enter 0\n");
                printf("--------------------------------------------------------------\n\n");
                while(1){
                    scanf("%d",&checkp);
                    if(checkp != 1 && checkp != 0 ){
                        continue;
                    }else{
                        break;
                    }
                }
                if(checkp==1) {
                    system("cls");
                    printf("^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");
                    printf("|please enter your first name :");
                    scanf("%s", ticketst.firstName);
                    printf("|please enter your last name :");
                    scanf("%s", ticketst.lastName);
                    ticketst.numberOfHall = 1;
                    ticketst.numberOfSans = sansst.numberOfSans;
                    ticketst.beginningTime[0] = sansst.beginningTime[0];
                    ticketst.beginningTime[1] = sansst.beginningTime[1];
                    sansst.numberOfEmptyChairs--;
                    fwrite(&sansst, sizeof(sansst), 1, before);
                    fwrite(&ticketst, sizeof(ticketst),1,ticketFile);
                    printf("|thanks for buying\n");
                    printf(":::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n");
                    system("pause");
                }
                system("cls");
                fclose(hallFile);
                fclose(ticketFile);
                MainList();
                }
         //planet earth is blue and there's noting i can do..happy birthday david bowie

        break;
        }else{
            continue;
        }
    }

    fclose(ticketFile);
    fclose(hallFile);
}
void PrintListOfSans(int diffs[],int number,char str){
    for(int i=0;i<number;i++){
        if(diffs[i] > 0) {
            printf("_________________________________________________________________________________________________________________\n");
            SearchAndPrintSans(diffs[i], str, 1);
            printf("|enter sans %d for buy\n\n",i+1);
        }
    }
    int checkP;
    while(1){
        scanf("%d",&checkP);
        if(checkP > number || checkP==0){
            printf("\t\t\t<<<wrong number!!!!\n");
        }else{
            break;
        }
    }
    SearchAndPrintSans(diffs[checkP-1],str,0);
}
void printer(int a[] , int n){
    for(int i = 0 ;i<n;i++){
        printf("%d ",a[i]);
    }
}
void Reserve(int checkR){
    char *str = "Hall1.txt";
    struct Movie moviest;
    struct Sans sansst;
    //str[4] = checkR + '0';
    FILE *hallFile ;
    int numberOfsans = NumberOfSansFile(str) - 1;
    hallFile = fopen(str,"rb");
    int datesTimeForSort[numberOfsans];
    int i = 0;
    while(!feof(hallFile)){
        fread(&sansst, sizeof(sansst),1,hallFile);
        datesTimeForSort[i] = DiffBetweenDates(dates,clocks,sansst.beginningTime,sansst.date);
        i++;
    }
    fclose(hallFile);
    quicksort(datesTimeForSort,numberOfsans);
    PrintListOfSans(datesTimeForSort,numberOfsans,str);
}
void ListOfTickets(){
    FILE *ticketFile;
    struct Ticket ticketst;
    ticketFile = fopen("ticket.txt","rb");
    while(!feof(ticketFile)){
        fread(&ticketst,sizeof(ticketst),1,ticketFile);
        printf("_____________________________________________________________________________________________________________\n");
        printf("|Name : %s %s\n",ticketst.firstName,ticketst.lastName);
        printf("|In Hall %d    sans %d\n",ticketst.numberOfHall,ticketst.numberOfSans);
        printf("|Time: %d:%d\n",ticketst.beginningTime[0],ticketst.beginningTime[1]);
        printf("-------------------------------------------------------------------------------------------------------------\n\n");
    }
    fclose(ticketFile);
}
void ReservationMenu(){
    int checkR;
    printf("----------------------------------------------------------------------------------------------------------------\n");
    printf( "|Choose a Hall : \n");
    printf("|Hall 1 : 1\n");
    printf("____________________________________________________________________________________________________________________\n");
    while(1) {
        scanf("%d", &checkR);
        if(checkR != 1){
            printf("\t\t\t<<<Plz choose a right number!!!>>>\n");
            continue;
        }else{
            break;
        }
    }
    system("cls");
    Reserve(checkR);
}
void MainList(){
    int check;
    MenuPrinter();
    while(1) {
        scanf("%d", &check);
        if (check > 5 || check < 0) {
            printf("<<<Wrong number entered..please try again:");
            continue;
        } else {
            break;
        }
    }
    switch(check){
        case 1:
            system("cls");
            ReservationMenu();
            break;
        case 2:
            break;
        case 3:
            system("cls");
            ShowListOfMoives();
            break;
        case 4:
            system("cls");
            ListOfTickets();
            break;
        case 5:
            break;
        case 0:
            printf("good bye ((((((:  \n");
            exit(0);

    }
}

int main(){

    //FindMoiveWithId(6,1);
    FillTimeInfs();
    printf("------------------\n|Cinema manager!|\n------------------\n");
    MainList();
}

