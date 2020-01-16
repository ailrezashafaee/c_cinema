#include "header_includer.h"
#include "structures.h"
#include "functions_menu.h"
void ResetF(){
    struct MovieTheater mt;
    priLine(cl+5,45,sleep);
    printf("** Are you sure ? \n");
    printf(" 1)yes   2)Back :");
    int checkR;
    while(1){
        scanf("%d",&checkR);
        if(checkR != 1 && checkR != 2){
            printf("Try again!");
            continue;
        }else{
            break;
        }
    }
    int no;
    char g;
    char str[9] = "Hallx.txt";
    str[9] ='\0';
    if(checkR == 2){
        system("cls");
        MainList();
    }else{
        FILE *halls , *tickf , *movie , *hallx;
        tickf = fopen("ticket.txt","wb");
        fclose(tickf);
        movie = fopen("Movies.txt", "wb");
        fclose(movie);
        no = numberOfHalls();
        for(int i =1 ; i <=no;i++){
            g = i + '0';
            str[4] = g;
            hallx = fopen(str,"wb");
            fclose(hallx);
        }
        for(int i = 2; i<= no;i++){
            g = i + '0';
            str[4] = g;
            remove(str);
        }
        halls = fopen("Halls.txt" , "rb");
        fread(&mt,sizeof(struct MovieTheater),1,halls);
        fclose(halls);
        halls = fopen("Halls.txt", "wb");
        fwrite(&mt,sizeof(struct MovieTheater),1,halls);
        fclose(halls);
        printf("\t Done ^^");
        system("Pause");
        system("cls");
        MainList();
    }
}
void ChangeSleep(){
    FILE *setting;
    struct Setting s;
    setting = fopen("Setting.txt","rb");
    fread(&s,sizeof(struct Setting),1,setting);
    fclose(setting);
    setting = fopen("Setting.txt","wb");
    priLine(cl+3,45,sleep);
    printf("|sleep now : %d",sleep);
    printf("\n|enter new sleep(max 100): ");
    scanf("%d",&sleep);
    s.sleep = sleep;
    s.color = cl;
    printf("|Done ^^ \n ");
    system("Pause");
    system("cls");
    fclose(setting);
    MainList();
}
void changeColor(){
    FILE *setting;
    struct Setting sst;
    setting = fopen("Setting.txt","rb");
    fread(&sst,sizeof(struct Setting),1,setting);
    SetConsoleTextAttribute(handles,cl);
    fclose(setting);
    priLine(cl+5,45,sleep);
    printf("color now : ");
    SetConsoleTextAttribute(handles,sst.color);
    printf("@ _ @");
    SetConsoleTextAttribute(handles,15);
    printf("\n|choose new theme: \n");
    SetConsoleTextAttribute(handles,240);
    printf(" 1 \n");
    SetConsoleTextAttribute(handles,224);
    printf(" 2 \n");
    SetConsoleTextAttribute(handles,192);
    printf(" 3 \n");
    SetConsoleTextAttribute(handles,160);
    printf(" 4 \n");
    SetConsoleTextAttribute(handles,112);
    printf(" 5 \n");
    SetConsoleTextAttribute(handles,128);
    printf(" 6 \n");
    SetConsoleTextAttribute(handles,176);
    printf(" 7 \n");
    SetConsoleTextAttribute(handles,cl);
    int checkR;
    while(1){
        scanf("%d",&checkR);
        if(checkR <0 || checkR > 7){
            printf("|Please try again : ");
            continue;
        }else{
            break;
        }

    }
    switch(checkR){
        case 1:
            sst.color = 240;
            break;
        case 2:
            sst.color = 224;
            break;
        case 3:
            sst.color = 192;
            break;
        case 4:
            sst.color = 160;
            break;
        case 5:
            sst.color = 112;
            break;
        case 6:
            sst.color = 128;
            break;
        case 7:
            sst.color = 176;
            break;
    }
    cl = sst.color;
    sst.sleep = sleep;
    setting = fopen("Setting.txt","wb");
    SetConsoleTextAttribute(handles,cl);
    fwrite(&sst,sizeof(struct Setting),1,setting);
    printf("  Done  ^^\n");
    system("Pause");
    system("cls");
    fclose(setting);
    MainList();
}
void Setting(){
    priLine(cl+3,45,sleep);
    printf("|change color : 1 \n");
    printf("|change sleep : 2 \n");
    printf("|Reset everything : 3\n");
    printf("|Back : 0 \n");
    int checkR;
    while(1){
        scanf("%d",&checkR);
        if(checkR > 3 || checkR < 0){
            printf("|Try again ! : ");
            continue;
        }else{
            break;
        }
    }
    switch(checkR){
        case 1:
            system("cls");
            changeColor();
            break;
        case 2:
            system("cls");
            ChangeSleep();
            break;
        case 3:
            system("cls");
            ResetF();
            break;
        case 0:
            system("cls");
            MainList();
            break;
        }
}
void ListOfHalls(){
    FILE *halls;
    struct MovieTheater mt;
    halls = fopen("Halls.txt","rb");
    int n = numberOfHalls();
    for(int i =0 ; i < n;i++){
        fread(&mt,sizeof(struct MovieTheater),1,halls);
        priLine(cl+2,45,sleep);
        printf("\t** %s **\n",mt.Hallname);
        printf("\t|%s\tGrade %d\n",mt.TypeOfProjector,mt.gradeOfHall);
        printf("\t|Floor:%d\n\t|Capacity:%d\n",mt.floor,mt.column*mt.row);
    }
    priLine(cl+2,45,sleep);
    system("Pause");
    system("cls");
    MainList();
}
void FillHallInf(struct MovieTheater *m,int n){
    FILE *file;
    file = fopen("Halls.txt","rb");
    while(!feof(file)){
        fread(m,sizeof(struct MovieTheater),1,file);
        if(m->numberOfHall == n){
            fclose(file);
            return;
        }
    }
    fclose(file);
    printf("not found!!!");
}
void NewHall(){
    FILE *halls;
    struct MovieTheater hallst;
    halls = fopen("Halls.txt","ab");
    priLine(cl+5,43,sleep);
    printf("+\t\tEnter the name of hall :");
    scanf("%s",hallst.Hallname);
    printf("+\t\tEnter Halls grade(a number from 1 to 3):");
    while(1){
        scanf("%d",&hallst.gradeOfHall);
        if(hallst.gradeOfHall > 3 || hallst.gradeOfHall < 0){
            printf("+\t\tTry again! : ");
            continue;
        }else{
            break;
        }
    }
    printf("+\t\tEnter type of projector(HD 3D 4K)(string):");
    scanf("%s",hallst.TypeOfProjector);
    printf("+\t\tEnter Floor (number): ");
    scanf("%d",&hallst.floor);
    printf("+\t\tEnter number of rows : ");
    scanf("%d",&hallst.row);
    printf("+\t\tEnter number of columns : ");
    scanf("%d",&hallst.column);
    hallst.numberOfHall = numberOfHalls()+1;
    printf("+\t\tNew Hall Added (:");
    fwrite(&hallst,sizeof(struct MovieTheater),1,halls);
    fclose(halls);
    system("Pause");
    system("cls");
    MainList();
}
void Halls(){
    priLine(cl+2,45,sleep);
    printf("-|List of Halls : 1\n");
    printf("-|Add a new Hall : 2\n");
    printf("-|Update hall information : 3\n");
    printf("-|Back :0\n");
    priLine(cl+2,45,sleep);
    int check;
    while(1){
        scanf("%d",&check);
        if(check > 3 || check < 0){
            continue;
        }else{
            break;
        }
    }
    switch(check){
        case 1:
            system("cls");
            ListOfHalls();
            break;
        case 2:
            system("cls");
            NewHall();
            break;
        case 3:
            printf("Not finished yet!");
            system("Pause");
            system("cls");
            MainList();
            break;
        case 0:
            system("cls");
            MainList();
            break;
    }
}
void deletFromSans(int diff , char str[]){
    FILE *hallFile;
    hallFile = fopen(str,"rb");
    int n = NumberOfSansFile(str);
    struct Sans sa[n];
    for(int i = 0 ;i < n ; i++){
        fread(&sa[i] , sizeof(struct Sans) , 1, hallFile);
    }
    fclose(hallFile);
    hallFile = fopen("Hall1.txt","wb");
    for(int i = 0 ;i < n ; i++){
        if(diff == DiffBetweenDates(dates,clocks,sa[i].beginningTime,sa[i].date)){
            continue;
        }else{
            fwrite(&sa[i],sizeof(struct Sans),1,hallFile);
        }
    }
    fclose(hallFile);
    return;
}
void Buy(char str[] , int diff){
    FILE *hallFile;
    struct MovieTheater hallst;
    int n = NumberOfSansFile(str);
    FILE *ticketFile;
    struct Ticket ticketst;
    hallFile = fopen(str,"rb");
    ticketFile = fopen("ticket.txt","ab");
    struct Sans sa[n];
    int nOH;
    nOH = str[4] - '0';
    int checkp , flag = 0 , x;
    for(int i = 0 ; i<n;i++){
        fread(&sa[i],sizeof(struct Sans),1,hallFile);
        if(diff == DiffBetweenDates(dates,clocks,sa[i].beginningTime,sa[i].date)){
            system("cls");
            FindMoiveWithId(sa[i].moiveId,0);
            printf("|Sans %d   %d:%d\n", sa[i].numberOfSans, sa[i].beginningTime[0],sa[i].beginningTime[1]);
            printf("|Date : %d/%d/%d/\n", sa[i].date[2], sa[i].date[1], sa[i].date[0]);
            printf("|Ticket price : %d\n",sa[i].price);
            SetConsoleTextAttribute(handles,cl+5);
            printf("-_-_-_-_-__-_-__-__-__-_-__-_-__-_-__-__-__-__-__-__-__-__-__-__-__-__-__-__-_-__-_-__-_-_-_-__-_-_-_-_-_-_-_-_-_-_-_-_\n");
            SetConsoleTextAttribute(handles,cl+2);
            printf("|For buy enter 1\n");
            SetConsoleTextAttribute(handles,cl+4);
            printf("|For back enter 0\n");
            priLine(cl+5,45,sleep);
            //printf("-------------------------------------------------------------------------------------\n\n");
            while(1){
                scanf("%d",&checkp);
                if(checkp == 1){
                    x = i;
                    flag = 1;
                    break;
                }
                if(checkp == 0){
                    system("cls");
                    fclose(hallFile);
                    fclose(ticketFile);
                    MainList();
                    //MainList();
                    break;
                }else{
                    printf("\t\t --please enter 0 or 1---\n");
                    continue;
                }
            }
        }
    }
    fclose(hallFile);
    hallFile = fopen(str,"wb");
    FillHallInf(&hallst,nOH);
    //ticket doing :
    system("cls");

        priLine(cl+4,94,sleep);
    if(flag == 1){
        for(int i = 0 ;i<hallst.row;i++){
            printf("\t\t");
            for(int j = 1 ;j <=hallst.column;j++){
                if(sa[x].rc[i][j-1] == 0){
                    SetConsoleTextAttribute(handles,cl+2);
                    printf("%2d ",i*hallst.column + j);
                }else{
                    SetConsoleTextAttribute(handles,cl+4);
                    printf("%2d ",i*hallst.column+j);
                }
            }
            printf("\n\n");
        }
        SetConsoleTextAttribute(handles,cl);
        //printf("^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");
        printf("|please enter your first name :");
        scanf("%s", ticketst.firstName);
        printf("|please enter your last name :");
        scanf("%s", ticketst.lastName);
        ticketst.ticketprice = sa[x].price;
        ticketst.numberOfHall = nOH;
        ticketst.numberOfSans = sa[x].numberOfSans;
        ticketst.beginningTime[0] = sa[x].beginningTime[0];
        ticketst.beginningTime[1] = sa[x].beginningTime[1];
        int k =0;
        int ko,a,b;
        printf("|Choose one chair :");
        while(1){
            scanf("%d",&ko);
            a = ko/hallst.row;
            b = ko%hallst.column;
            if(b == 0){
                b = hallst.column;
            }
            b--;
            if(ko > hallst.row*hallst.column){
                printf("Please Try again!");
                continue;
            }
            if(sa[x].rc[a][b] == 1){
                printf("|Please choose a free chair : ");
                continue;
            }
            break;
        }
        sa[x].rc[a][b] = 1;
        ticketst.numberOfChair = ko;
        fwrite(&ticketst,sizeof(struct Ticket),1,ticketFile);
        printf("|thanks :) ticket reserved successfully\n");
        system("Pause");
    }
    for(int i = 0 ;i<n;i++){
        if(i != x){
            fwrite(&sa[i],sizeof(struct Sans),1,hallFile);
        }
    }
    sa[x].numberOfEmptyChairs--;
    fwrite(&sa[x],sizeof(struct Sans),1,hallFile);
    fclose(ticketFile);
    fclose(hallFile);
    system("cls");
    MainList();
//    MainList();
}
void deletFromMovies(){
    printf("please enter the id of movie you want to delete:");
    int ck;
    while(1){
        scanf("%d",&ck);
        if(FillMovieInf(ck) == 0){
            printf("The is no movie with this id ...plz try again : ");
            continue;
        }else{
            break;
        }
    }
    int id = 1;
    FILE *movieFile;
    movieFile = fopen("Movies.txt","rb");
    int n = NumberOfMoivesFile();
    //printf("%d",n);
    struct Movie sa[n];
    for(int i = 0 ;i < n ; i++){
        fread(&sa[i] , sizeof(struct Movie) , 1, movieFile);
    }
    fclose(movieFile);
    movieFile = fopen("Movies.txt","wb");
    fseek(movieFile,0,SEEK_SET);
    for(int i = 0 ;i < n ; i++){
        if(ck == sa[i].id){
            continue;
        }else{
            sa[i].id = id;
            fwrite(&sa[i],sizeof(struct Movie),1,movieFile);
            id++;
        }
    }
    printf("  done :))\n");
    system("Pause");
    system("cls");
    fclose(movieFile);
    MainList();
}
void AboutUs(){
    SetConsoleTextAttribute(handles,cl+4);
    printf("\t\t****************************************************************************************\n");
    printf("\t\t*                     Developer :alireza shafaee                                       *\n");
    printf("\t\t*                     For dear Mrs zareh and kamyab                                    *\n");
    printf("\t\t*                     sorry if its not good ..i wish i had more times                  *\n");
    printf("\t\t****************************************************************************************\n");
    system("pause");
    system("cls");
    MainList();
}
void MainList();
void NewMovies(){
    FILE *movieFile;
    struct Movie moviest;
    movieFile = fopen("Movies.txt","ab");
    priLine(cl+4,61,sleep);
    //printf("=====================================================================================================\n");
    printf("***Please enter caps lock instead of space in names(Like TheShining  -> The Shining)\n");
    printf("|\t please enter the movie name :");
    scanf("%s",moviest.name);
    printf("|\t please enter the year of publish:(just numbers)");
    scanf("%d",&moviest.yearOfPublish);
    printf("|\t please enter directors name : ");
    scanf("%s",moviest.director);
    printf("|\t enter the genre : ");
    scanf("%s",moviest.genre);
    printf("|\t enter the time long (min) (max 600): ");
    while(1){
        scanf("%d",&moviest.timelong);
        if(moviest.timelong > 600){
            printf("|\t Plz enter a number less than 600 :");

            continue;
        }else{
            break;
        }
    }
    printf("|\t enter the name of two actors\n");
    printf("|\t\t 1: ");
    scanf("%s",moviest.actorsName[0]);
    printf("|\t\t 2: ");
    scanf("%s",moviest.actorsName[1]);
    printf("|\t please enter the rate(a float number from one to 10):");
    while(1){
        scanf("%f",&moviest.rate);
        if(moviest.rate < 0 || moviest.rate > 10){
            printf("|\t Enter rate again : ");
            continue;
        }else{
            break;
        }
    }
    moviest.id = NumberOfMoivesFile() + 1;
    //fwrite(&moviest,sizeof(struct Movie),1,movieFile);
    printf("|\t\t Done ^,^\n");
    system("pause");
    system("cls");
    fwrite(&moviest,sizeof(struct Movie),1,movieFile);
    fclose(movieFile);
    MainList();
   // printf(we are losing it can you tell ...o i l)

}
void TimePluser(int fh,int fm,int i,int *lh,int *lm){
    *lh = fh + i/60;
    if( fm+i%60 < 60){
        *lm = fm + i%60;
    }else{
        *lm = (fm + i%60)%60;
        (*lh)+=1;
    }
}
int FillMovieInf(int id){
    FILE *movieFile;
    struct Movie moviest;
    movieFile = fopen("Movies.txt", "rb");
    while (!feof(movieFile)) {
        fread(&moviest, sizeof(moviest), 1, movieFile);
        if (id == moviest.id){
            //m->timelong = moviest.timelong;
            fclose(movieFile);
            return moviest.timelong;
        }
    }
    fclose(movieFile);
    return 0;
}
void NewSans(char str[]){
    //char str[1]; //this is fake.
    FILE *hallFile;
    int nOH = str[4] - '0';
    struct Sans sansst;
    struct MovieTheater mt;
    //i jumped into the river and what did i see.
    FillHallInf(&mt,nOH);
    sansst.numberOfEmptyChairs = mt.column*mt.row;
    sansst.date[0] = 2020;
    sansst.sansId = NumberOfSansFile(str);
    hallFile = fopen(str,"ab");
    priLine(cl+14,43,sleep);
    //printf("===========================================================================================================\n");
    printf("|\t please enter number of sans: ");
    scanf("%d",&sansst.numberOfSans);
    printf("|\t please enter movie id(for see your movie id go to list of movies) : ");
    scanf("%d",&sansst.moiveId);
    printf("|\t please enter ticket price : ");
    scanf("%d",&sansst.price);
    printf("| enter date:\n|\t month:");
    scanf("%d",&sansst.date[1]);
    for(int i=0 ; i<mt.row ;i++){
        for(int j =0 ; j<mt.column;j++){
            sansst.rc[i][j] = 0;
        }
    }
    if(sansst.date[1] > 12){
        printf("|\t we have 12 months in year :)\n");
        system("pause");
        system("cls");
        MainList();
    }
    printf("|\t day:");
    scanf("%d",&sansst.date[2]);
    if(sansst.date[2] > 30){
        printf("|\t invalid day entered\n");
        system("pause");
        system("cls");
        MainList();
    }
    printf("|\t hour :");
    scanf("%d",&sansst.beginningTime[0]);
    if(sansst.beginningTime[0] >= 24){
        printf("|\t invalid hour entered(les than 24 plz)\n");
        system("pause");
        system("cls");
        MainList();
    }
    printf("|\t min: ");
    scanf("%d",&sansst.beginningTime[1]);
    if(sansst.beginningTime[1] >=60){
        printf("|\t invalid minute entered(less than 60)\n");
        system("pause");
        system("cls");
        MainList();
    }
    int i = FillMovieInf(sansst.moiveId);
    TimePluser(sansst.beginningTime[0],sansst.beginningTime[1],i,&sansst.finishingTime[0],&sansst.finishingTime[1]);
    /*sansst.finishingTime[0] = sansst.beginningTime[0] + i/60;
    if( sansst.beginningTime[1]+i%60 < 60){
        sansst.finishingTime[1] = sansst.beginningTime[1] + i%60;
    }else{
        sansst.finishingTime[1] = (sansst.beginningTime[1] + i%60)%60;
        sansst.finishingTime[0]++;
    }*/
    int n,e;
    if(i != 0){
        n = DiffBetweenDates(dates,clocks,sansst.beginningTime,sansst.date);
        e = DiffBetweenDates(dates,clocks,sansst.finishingTime,sansst.date);
        if(n < 0){
            printf("|\t  The time you entered is passed\n");
            system("pause");
            system("cls");
            fclose(hallFile);
            MainList();
        }
        if(sansst.finishingTime[0] > 24){
            printf("|\t Invalid time entered\n");
            system("pause");
            system("cls");
            fclose(hallFile);
            MainList();
        }
        if(sansst.finishingTime[1] > 0 && sansst.finishingTime[0] == 24){
            printf("|\t Invalid time entered\n");
            system("pause");
            system("cls");
            fclose(hallFile);
            MainList();
        }
        if(Reserve(str,0,n,e) == 1){
            printf("|\t !!<Done ^^\n");
            priLine(cl+4,34,sleep);
            //printf(":::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n");
            system("pause");
            system("cls");
            fwrite(&sansst,sizeof(struct Sans),1,hallFile);
            fclose(hallFile);
            MainList();
        }else{
            printf("|\t theres another sans in this time!");
            system("pause");
            system("cls");
            fclose(hallFile);
            MainList();
        }
    }else{
        printf("|\t theres no movies with this Id!!");
        system("pause");
        system("cls");
        MainList();
    }

}
void FindMoiveWithId(int id ,int flag) {
    FILE *movieFile;
    struct Movie moviest;
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
                printf("    time long : %d (min)\n",moviest.timelong);
                printf("|genre: %s    Rate: %.1f\n",moviest.genre,moviest.rate);
            }
            fclose(movieFile);
            return;
        }
    }
    printf("\t\t\t<<<<<not Found!!!!!!>>>>");
}
void ShowListOfMoives(){
    FILE *movieFile;
    struct Movie moviesst;
    int number = NumberOfMoivesFile();
    //printf("%d\n\n\n",number);
    movieFile = fopen("Movies.txt","rb+");
    //while(!feof(movieFile)){
    for(int i = 0 ;i<number;i++){
        fread(&moviesst, sizeof(struct Movie),1,movieFile);
        //printf("___________________________________________________________________________________________________\n");
        printf("*** ");
        Nameprinter(moviesst.name);
        printf("   (%d)***\n", moviesst.yearOfPublish);
        printf("\t\tDirector:");
        Nameprinter(moviesst.director);
        printf("    time long : %d (min)\n",moviesst.timelong);
        printf("\t\tgenre: %s    Rate: %.1f\n",moviesst.genre,moviesst.rate);
        printf("\t\tactors :\n\t\t");
        Nameprinter(moviesst.actorsName[0]);
        printf("\t\t");
        Nameprinter(moviesst.actorsName[1]);
        printf("\n");
        printf("\t\t&&& movie Id : %d (for enter in new sans part)\n",moviesst.id);
        printf("____________________________________________________________________________________________________\n\n");
        Sleep(sleep);
    }
    fclose(movieFile);
    system("Pause");
    system("cls");
    MainList();
}
int SearchAndPrintSans(int diff,char str[],int flag /*0 for full 1 for little informations.*/){
    FILE *hallFile,*before , *ticketFile;
    struct Ticket ticketst;
    int checkp;
    int n = NumberOfSansFile(str);
    struct Sans sansst;
    //printf("%c\n\n");
    hallFile = fopen(str,"rb");
    //printf("\n\nwrthyrjt");
    while(!feof(hallFile)){
        fread(&sansst, sizeof(sansst),1,hallFile);
        if(diff == DiffBetweenDates(dates,clocks,sansst.beginningTime,sansst.date)){
            if(flag == 1) {
                //system("cls");
                FindMoiveWithId(sansst.moiveId, flag);
                printf("|Sans %d   %d:%d\n", sansst.numberOfSans, sansst.beginningTime[0],sansst.beginningTime[1]);
                printf("|Price : %d ",sansst.price);
                printf("|%d/%d/%d/\n", sansst.date[0], sansst.date[1], sansst.date[2]);
                if (sansst.numberOfEmptyChairs) {
                    SetConsoleTextAttribute(handles,160);
                    printf("|%d Free chairs", sansst.numberOfEmptyChairs);
                    SetConsoleTextAttribute(handles,cl);
                    printf("\n");
                } else {
                    SetConsoleTextAttribute(handles,cl+4);
                    printf("\t<<Full!!>>\n");
                    SetConsoleTextAttribute(handles,cl);
                }
                //printf("|sans Id (for buy)\n");
                priLine(4+cl,45,sleep);
                //printf("--------------------------------------------------------------------------------------------\n");
            }
        break;
        }
    }
    fclose(ticketFile);
    fclose(hallFile);
}
void MovieMenue(){
    SetConsoleTextAttribute(handles,cl+4);
    printf("-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-\n");
    SetConsoleTextAttribute(handles,cl);
    printf("-|List of movies : 1\n");
    printf("-|Add a movie : 2\n");
    printf("-|Delet a movie : 3\n");
    printf("-|Back : 0\n");
    SetConsoleTextAttribute(handles,cl+4);
    printf("-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-\n");
    SetConsoleTextAttribute(handles,cl);
    int check;
    while(1){
        scanf("%d",&check);
        if(check > 3 || check < 0){
            printf("----please try again----\n");
            continue;
        }else{
            break;
        }
    }
    int k;
    switch(check){
    case 1:
        system("cls");
        ShowListOfMoives();
        break;
    case 2:
        system("cls");
        NewMovies();
        break;
    case 3:
        system("cls");
        deletFromMovies();
        break;
    case 0:
        system("cls");
        MainList();
    }

}
void PrintListOfSans(int diffs[],int number,char str[]){
    if(number == 0){
        SetConsoleTextAttribute(handles,cl+4);
        printf(" \t **theres no sans in this hall yet !!\n");
        SetConsoleTextAttribute(handles,cl+4);
    }
    for(int i=0;i<number;i++){
        if(diffs[i] > 0) {
            priLine(4+cl,95,sleep);
            //printf("_________________________________________________________________________________________________________________\n");
            SearchAndPrintSans(diffs[i], str, 1);
            printf("|enter sans %d for buy\n\n",i+1);
            Sleep(sleep);
        }
    }
    printf("| 0 for back :");
    int checkP;
    while(1){
        scanf("%d",&checkP);
        if(checkP > number){
            printf("\t\t\t<<<wrong number!!!!\n");
        }else{
            break;
        }
    }
    if(checkP == 0){
        system("cls");
        MainList();
    }
    Buy(str,diffs[checkP-1]);
    //SearchAndPrintSans(diffs[checkP-1],str,0);
}
void printer(int a[] , int n){
    for(int i = 0 ;i<n;i++){
        printf("%d ",a[i]);
    }
}
int Reserve(char str[] ,int flag , int f,int e){
    struct Movie moviest;
    struct Sans sansst;
    //str[4] = checkR + '0';
    FILE *hallFile ;
    int numberOfsans = NumberOfSansFile(str);
    hallFile = fopen(str,"rb");
    int finishedDiff[numberOfsans];
    int datesTimeForSort[numberOfsans];
    int i = 0;
    int k;
    //while(!feof(hallFile)){
    for(int j =0 ;j<numberOfsans;j++){
        fread(&sansst, sizeof(sansst),1,hallFile);
        datesTimeForSort[i] = DiffBetweenDates(dates,clocks,sansst.beginningTime,sansst.date);
        k = FillMovieInf(sansst.moiveId);
        TimePluser(sansst.beginningTime[0],sansst.beginningTime[1],k,&sansst.finishingTime[0],&sansst.finishingTime[1]);
        finishedDiff[i] = DiffBetweenDates(dates,clocks,sansst.finishingTime,sansst.date);
        i++;
    }
    int sar = 0;
    if(flag == 0){
        for(int i = 0 ;i<numberOfsans ; i++){
            if(f == datesTimeForSort[i] || e == datesTimeForSort[i]){
                fclose(hallFile);
                return 0;
            }
            if(f >datesTimeForSort[i] && f <finishedDiff[i]){
                fclose(hallFile);
                return 0;
            }
            if(e > datesTimeForSort[i] && e < finishedDiff[i]){
                fclose(hallFile);
                return 0;
            }
            if(e > datesTimeForSort[i] && f < datesTimeForSort[i]){
                fclose(hallFile);
                return 0;
            }
            if(e >finishedDiff[i] && f < finishedDiff[i]){
                fclose(hallFile);
                return 0;
            }
        }
        fclose(hallFile);
        return 1;
    }
    fclose(hallFile);
    //quicksort(datesTimeForSort,numberOfsans);
    if(flag == 1){
        //printer(datesTimeForSort,numberOfsans);
        //puts("");
        //printf("fuck you \n");
        system("cls");
        quicksort(datesTimeForSort,numberOfsans);
        //printer(datesTimeForSort,numberOfsans);
        PrintListOfSans(datesTimeForSort,numberOfsans,str);
    }
}
void ListOfTickets(){
    FILE *ticketFile;
    int number = NumberOfTicketFile();
    struct Ticket ticketst;
    ticketFile = fopen("ticket.txt","rb");
    //while(!feof(ticketFile)){
    for(int i= 0 ;i<number;i++){
        fread(&ticketst,sizeof(ticketst),1,ticketFile);
        priLine(14+cl,126,sleep);
        //SetConsoleTextAttribute(handles,113);
        //printf("_____________________________________________________________________________________________________________\n");
        printf("|Name : %s %s\n",ticketst.firstName,ticketst.lastName);
        printf("|In Hall %d    sans %d\n",ticketst.numberOfHall,ticketst.numberOfSans);
        printf("|Time: %d:%d     number of chair: %d\n",ticketst.beginningTime[0],ticketst.beginningTime[1],ticketst.numberOfChair);
        priLine(14+cl,61,sleep);
        //printf("-------------------------------------------------------------------------------------------------------------\n\n");
        Sleep(500);
    }
    fclose(ticketFile);
    system("pause");
    SetConsoleTextAttribute(handles,cl);
    system("cls");
    MainList();
}
void NewRM(int flag){
    int n = numberOfHalls();
    priLine(4+cl,95,sleep);
    for(int i =1 ; i<=n;i++){
        printf("|Hall %d : %d\n",i,i);
    }
    priLine(4+cl,95,sleep);
    printf("|Back 0: ");
    int checkR;
    while(1){
        scanf("%d",&checkR);
        if(checkR > n || checkR < 0){
            printf("\t\t\t *Please try again*");
            continue;
        }else{
            break;
        }
    }
    if(checkR == 0){
        system("cls");
        MainList();
    }
    char g = checkR + '0';
    char str[9] = "Hallx.txt";
    str[4] = g;
    if(flag == 0){
        Reserve(str,1,0,0);
    }else{
        NewSans(str);
    }
}
void MainList(){
    SetConsoleTextAttribute(handles,cl);
    int check;
    MenuPrinter();
    while(1) {
        scanf("%d", &check);
        if (check > 8 || check < 0) {
            printf("\t\t&&Wrong number entered..please try again:");
            continue;
        } else {
            break;
        }
    }
    switch(check){
        case 1:
            system("cls");
            SetConsoleTextAttribute(handles,cl);
            NewRM(0);
            break;
        case 2:
            system("cls");
            NewRM(1);
            break;
        case 3:
            system("cls");
            MovieMenue();
            break;
        case 4:
            system("cls");
            ListOfTickets();
            break;
        case 5:
            system("cls");
            Halls();
            break;
        case 6:
            system("cls");
            Setting();
            break;
        case 7:
            system("cls");
            AboutUs();
            break;
        case 0:
            system("cls");
            printf("good bye ((((((:  \n");
            exit(0);
    }
}
int main(){
    struct Setting st;
    FILE *setting;
    setting = fopen("Setting.txt","rb");
    fread(&st,sizeof(struct Setting),1,setting);
    cl = st.color;
    sleep = st.sleep;
    //printf("%d",numberOfHalls());
    HANDLE hande;
    hande = GetStdHandle(STD_OUTPUT_HANDLE);
    handles = hande;
   // DeletFromSanss(3);
    SetConsoleTextAttribute(hande,228);
    //FindMoiveWithId(6,1);
    FillTimeInfs();
    for(int i = 0 ;i<18;i++){
        printf("-");
        Sleep(4);
    }
    printf("\n|Cinema manager!  \n");
    Sleep(1);
    for(int i = 0 ;i<18;i++){
        printf("-");
        Sleep(4);
    }
    fclose(setting);
    puts("");
    SetConsoleTextAttribute(handles,cl);
    SetConsoleTextAttribute(hande,cl);
    MainList();
    CloseHandle(hande);
}

