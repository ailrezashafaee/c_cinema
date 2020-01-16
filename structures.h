typedef struct Inromations{
    char name[50];
    int isthatHisFirstTime;
    int movieId;
}inf;
typedef struct Pointer{
    struct Sans *sa;
    struct Movie *movie;
    struct Ticket *ti;
    struct MovieTheater *hall;
}po;
struct Movie
{
    int id; //This field will fill by program.
    char name[50];
    char director[50];
    int yearOfPublish;
    int timelong;   //In base minute.
    float rate;   //A float number from 0 to 10.
    char genre[50];
    char actorsName[5][50];    //List of actors/actress name.
    int soldenTickets;
};
struct Setting{
    int color;
    int sleep;
};
struct Sans
{
    int sansId;
    int numberOfSans;   //This field will fill by program.
    int date[3];    //In order:Year,month,day.
    int beginningTime[2]; //In order:Hour,minute.
    int finishingTime[2]; //This    field will fill by program with regard to the time long of the movie.
    int moiveId;
    int rc[20][20];
    int price;
    //struct Movie movieInformation;
    //int chars[100][100]; //the chars in hall
    int numberOfEmptyChairs;
};
struct MovieTheater{
    char Hallname[50];
    int numberOfHall;
    int gradeOfHall;  //Including a number:1 best to 3 worst.
    char TypeOfProjector[50];//HD,4K,3D...
    int floor;
    int row;
    int column;
};
struct Ticket{
    char firstName[50];
    char lastName[50];
    char movieName[50];
    int beginningTime[2]; //In order:Hour,minute.
    int numberOfHall;
    int numberOfSans;
    int ticketprice;
    int numberOfChair;
    //int row;
    //int column;
};
