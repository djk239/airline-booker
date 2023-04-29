#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

//DALE + DYLAN
//KING SKYES AIRLINES
//C&UNIX


int choice; //Determines what the website does. If it is choice 1, the user may attempt to Reserve a flight.

//variables
char firstName[20];
char lastName[20];
char passportNumber[20];
char email[50];
int firstOrSecondClass;
char destination[3];

char password[] = "dehzangi76";
char backOutCase[] = "-1";
char passwordInput[];
FILE *passengerDataFile;

FILE *ticketFileName = "TicketFile.txt";
char ch;

    //preset seating charts (to be pulled by file later)
    char firstClassSeating[9][6];
    char mainClassSeating[9][9];


    int *r, *c;
    FILE *fptrD;

//function prototypes
void AssembleTicket(void);
void MenuPrompter(void);
void seatSelector(int dest);
void ticketInfo(void);
void seatingChart(int dest);

int main(){

    //used for collecting character from file
    char ch;


    printf("\t\t__________________________________\t\t"); //Greeting
    printf("\n\n\t\tWelcome to the King Skies Airline.\t\t\n"); //Greeting
    printf("\t\t__________________________________\t\t\n\n"); //Greeting
    printf("\t\tHow may we help you today?\n"); //Invite the user to use program
    printf("\n\t\t1: Reserve a flight.\n"); //Reserves a flight
    printf("\n\t\t2: View Open Seats\n"); //View Open Seats
    printf("\n\t\t3: View All Tickets (Admin)\n"); //View All Seats
    printf("\n\t\t4: About us...\n"); //About us...
    printf("\n\t\t0: Exit the program.\n"); //Terminate program
    printf("\n\n\t\tSelect one of the above commands: "); //Prompt them for their choice
    scanf("%d", &choice); //Choice input


    while(choice != 0){ //While the choice isn't 0, because 0 will end the program.

    if(choice == 1){ //They chose to reserve a flight
        printf("\n\n\t\tRESERVE A FLIGHT\t\t\n"); //They chose to Reserve a Flight.

        printf("\t\tPlease enter your first name: "); //Ask for their name
        scanf("%s", &firstName);

        printf("\t\tPlease enter your last name: "); //Ask for their name
        scanf("%s", &lastName);

        passengerDataFile = fopen(ticketFileName, "a"); //Open file for writing, name it after their first name.

        if (passengerDataFile == NULL) //Check if file exists
        {
        printf("File does not exist");
        exit(1); //Terminate program if does not exist.
        }

        fprintf(passengerDataFile, "--------------------------------------------------------------\n");
        fprintf(passengerDataFile, "| TICKET \n");
        fprintf(passengerDataFile, "| NAME:%s %s\n", firstName, lastName); //Add to file

        printf("\t\tPlease enter your Email Address: "); //Ask for their email address
        scanf("%s", &email);
        fprintf(passengerDataFile, "| EMAIL: %s\n", email);


        printf("\t\tPlease enter your Passport Number: "); //Ask for their passport number
        scanf("%s", &passportNumber);
        fprintf(passengerDataFile, "| PASSPORT NUMBER: %s\n", passportNumber); //Add to file


        printf("\t\tAre you flying First or Second class? Enter 1 for First Class, and enter 2 for Second Class: ");
        scanf("%d", &firstOrSecondClass);


        while(firstOrSecondClass >= 3 || firstOrSecondClass <= 0){ //Ensure that first/second class input is VALID. Must be 1 or 2, not anything else
            printf("\t\tInvalid Class. Are you flying First Or Second Class? Enter 1 for First Class, and enter 2 for Second Class: "); //Reprompt
            scanf("%d", &firstOrSecondClass); //Add number to the appropriate value at the appropriate spot
        }

        fprintf(passengerDataFile, "| CLASS: %d\n", firstOrSecondClass); //Add to file

        printf("\t\tAvailable flight destinations:\n");
        //loop to print available destinations given from file
        fptrD = fopen("dest.txt", "r");
        do {
            ch = fgetc(fptrD);
            printf("%c", ch);

        } while (ch != EOF);
        fclose(fptrD);



//loop to make sure a valid entry is entered
//also takes valid entry and pulls up respective seating chart allowing user to choose seat
        do
        {
                    //IDENTIFIER ex: PHL, MRY, LAX etc.
            puts("\n\t\tPlease enter the airport's three letter identifier. ");
            scanf("%s", &destination);

            if(strcmp(destination,"PHL") == 0) 
            {
                printf("\t\tLastly, lets pick your seat. \n"); //prompts for seat input
                seatSelector(1); //function to pull up seating chart and make changes to said chart (user picks seat)
            
            }
            else if(strcmp(destination,"LAX") == 0) 
            {
                printf("\t\tLastly, lets pick your seat. \n"); //prompts for seat input
                seatSelector(2); //function to pull up seating chart and make changes to said chart (user picks seat)
            
            }
            else if(strcmp(destination,"DFW") == 0) 
            {
                printf("\t\tLastly, lets pick your seat. \n"); //prompts for seat input
                seatSelector(3); //function to pull up seating chart and make changes to said chart (user picks seat)
            
            }
            else if(strcmp(destination,"PHX") == 0) 
            {
                printf("\t\tLastly, lets pick your seat. \n"); //prompts for seat input
                seatSelector(4); //function to pull up seating chart and make changes to said chart (user picks seat)
            
            }
            else if(strcmp(destination,"JFK") == 0)
            {
                printf("\t\tLastly, lets pick your seat. \n"); //prompts for seat input
                seatSelector(5); //function to pull up seating chart and make changes to said chart (user picks seat)
            
            }
            else if(strcmp(destination,"DEN") == 0) 
            {
                printf("\t\tLastly, lets pick your seat. \n"); //prompts for seat input
                seatSelector(6); //function to pull up seating chart and make changes to said chart (user picks seat)
            
            }
            else if(strcmp(destination,"ICN") == 0) 
            {
                printf("\t\tLastly, lets pick your seat. \n"); //prompts for seat input
                seatSelector(7); //function to pull up seating chart and make changes to said chart (user picks seat)
            
            }
            else
            {
                puts("\t\tEntry invalid, please enter a valid three letter identifier.");
            }
        } while (strcmp(destination,"PHL") != 0 &&
        strcmp(destination,"LAX") != 0 &&
        strcmp(destination,"DFW") != 0 &&
        strcmp(destination,"JFK") != 0 && //valid entries ATM
        strcmp(destination,"PHX") != 0 &&
        strcmp(destination,"DEN") != 0 &&
        strcmp(destination,"ICN") != 0);

        fprintf(passengerDataFile, "| DESTINATION: %s\n", destination); //Add to the file



        printf("\t\tGenerating Ticket... \n\n"); //Inform user that their ticket is being built
        fprintf(passengerDataFile, "--------------------------------------------------------------\n\n\n");

        AssembleTicket(); //Assemble the current ticket


        fclose(passengerDataFile);
    }

    //seating chart
    if(choice == 2){
        printf("\n\t VIEW OPEN SEATS\n");
        //prompt user
        puts("Please enter the class of seats you'd like to view seating options for.");
        puts("First class: enter 1 | Main cabin: enter 2");
        scanf("%d", &firstOrSecondClass);

        //makes sure the entered class is valid
        while(firstOrSecondClass >= 3 || firstOrSecondClass <= 0)
        { 
            printf("\t\tInvalid Class. Are you flying First Or Second Class? Enter 1 for First Class, and enter 2 for Main Cabin: "); 
            scanf("%d", &firstOrSecondClass); 
        }

        puts("Next please enter your intended destination:");
        printf("\t\tAvailable flight destinations:\n");

        //loop to print available destinations as given from file
        fptrD = fopen("dest.txt", "r");
        do {
            ch = fgetc(fptrD);
            printf("%c", ch);

        } while (ch != EOF);
        fclose(fptrD);


        //pulls up the respective seating chart based on entered identifier
        //loop to make sure the identifier is valid
        do
        {
            //IDENTIFIER ex: PHL, MRY, LAX etc.
            puts("\n\t\tPlease enter the airport's three letter identifier. ");
            scanf("%s", &destination);

            if(strcmp(destination,"PHL") == 0) 
            {
                seatingChart(1); //function to pull up seating chart FOR VIEWING
            
            }
            else if(strcmp(destination,"LAX") == 0) 
            {
                seatingChart(2); 
            
            }
            else if(strcmp(destination,"DFW") == 0) 
            {
                seatingChart(3); 
            
            }
            else if(strcmp(destination,"PHX") == 0) 
            {
                seatingChart(4); 
            
            }
            else if(strcmp(destination,"JFK") == 0) 
            {
                seatingChart(5); 
            
            }
            else if(strcmp(destination,"DEN") == 0) 
            {
                seatingChart(6); 
            
            }
            else if(strcmp(destination,"ICN") == 0) 
            {
                seatingChart(7); 
            
            }
            else
            {
                puts("Entry invalid, please enter a valid three letter identifier.");
            }
        } while (strcmp(destination,"PHL") != 0 &&
        strcmp(destination,"LAX") != 0 &&
        strcmp(destination,"DFW") != 0 &&
        strcmp(destination,"JFK") != 0 && //valid entries ATM
        strcmp(destination,"PHX") != 0 &&
        strcmp(destination,"DEN") != 0 &&
        strcmp(destination,"ICN") != 0);

    }

    //admin login
    if(choice == 3){
        printf("\n\t VIEW ALL TICKETS\n");
        printf("\n\tPlease enter the password for administrative controls: ");
        scanf("%s", &passwordInput); //Enter password
        if(strcmp(password, passwordInput) != 0){
            printf("\n\tIncorrect Password.");
            printf("\n\tReturning to menu...\n\n");
            MenuPrompter();
        }
        if (strcmp(password, passwordInput) == 0){ //Password Correct
            ticketInfo();
        }
    }

    if(choice == 4){ //Blurb about our website
        printf("\n\tABOUT US...\n");
        printf("\t------------------------------------------------------------------------------------------------------\n");
        printf("\t|This is the King Airlines. It was founded by Dale King and Dylan Granado in 2022.\n");
        printf("\t|Our goal is to ensure that our customers can easily and safely book their flights.\n");
        printf("\t|On this website, you can reserve a seat for your flight. Please check the available seats beforehand.\n");
        printf("\t|(FOR OUR MANAGERS) You can view all registered tickets by inputting the password.\n");
        printf("\t|The password is on a post-it note stuck to the fridge in the break room.\n");
        printf("\t------------------------------------------------------------------------------------------------------\n");

    }

    if(choice >= 5){ //Invalid Response
        printf("\n\tInvalid Response. Please Try again. \n");
        MenuPrompter();
    }

        MenuPrompter(); //Allows user to input another command
    }



    if(choice == 0){
        printf("\n\t\t --------------------------------------\t\t\n");
        printf("\n\n\t\t Thank you for using King Skies Airline.\t\t\n"); //Wish Farewell to the user
        printf("\n\n\t\t Have A Safe Flight!!!\t\t\n"); //This should end the program.
        printf("\n\t\t --------------------------------------\t\t\n");
    }
}

void MenuPrompter(){

    //This function prompts the user for any additional commands
    //Without re-prompting a "WELCOME" screen, since they don't need to be
    //welcomed to the program upon each use.
    printf("\n\t\tAnything Else?\n"); //Prompt if the user wants anything else
    printf("\n\t\t1: Reserve a flight.\n"); //Reserves a flight
    printf("\n\t\t2: View Open Seats\n"); //View Open Seats
    printf("\n\t\t3: View All Tickets (Admin)\n"); //View All Seats
    printf("\n\t\t4: About us...\n"); //About us...
    printf("\n\t\t0: Exit the program.\n"); //Terminate program
    printf("\n\n\t\tSelect one of the above commands: "); //Prompt them for their choice
    scanf("%d", &choice); //Inputs their choice
}

void AssembleTicket(){

    printf("--------------------------------------------------------------\n");
    printf("|\t\t\tTICKET\n");
    printf("|Name: %s %s\n", firstName, lastName);
    printf("|Passport Number: %s\n", passportNumber);
    printf("|Email: %s\n", email);
    printf("|Class: %d\n", firstOrSecondClass);
    printf("|Destination: %s\n", destination);
    printf("|Seat Number: %d-%d\n", r,c);
    printf("--------------------------------------------------------------\n\n\n");

}

void seatSelector(int dest)
{
    int row; // variables for inputting row and column
    int column;
    FILE *seatingFile1;
    FILE *seatingFile2;

//opens resepctive file for each destination
    if(dest == 1)
    {
        seatingFile1 = fopen("phl1.txt","r");
        seatingFile2 = fopen("phl2.txt", "r");
    }
    if(dest == 2)
    {
        seatingFile1 = fopen("lax1.txt","r");
        seatingFile2 = fopen("lax2.txt", "r");
    }
    if(dest == 3)
    {
        seatingFile1 = fopen("dfw1.txt","r");
        seatingFile2 = fopen("dfw2.txt", "r");
    }
    if(dest == 4)
    {
        seatingFile1 = fopen("phx1.txt","r");
        seatingFile2 = fopen("phx2.txt", "r");
    }
    if(dest == 5)
    {
        seatingFile1 = fopen("jfk1.txt","r");
        seatingFile2 = fopen("jfk2.txt", "r");
    }
    if(dest == 6)
    {
        seatingFile1 = fopen("den1.txt","r");
        seatingFile2 = fopen("den2.txt", "r");
    }
    if(dest == 7)
    {
        seatingFile1 = fopen("icn1.txt","r");
        seatingFile2 = fopen("icn2.txt", "r");
    }

   if(seatingFile1 == NULL)
   {
      printf("Error!");   
      exit(1);             
   }
   if(seatingFile2 == NULL)
   {
      printf("Error!");   
      exit(1);             
   }


    //fill seats from array first class
    for(int i = 0; i < 9; i++)
    {
        for(int k = 0; k < 6; k++)
        {
            fscanf(seatingFile1, "%c", &firstClassSeating[i][k]);
        }
    }
    //fill seats from array main class
    for(int i = 0; i < 9; i++)
    {
        for(int k = 0; k < 9; k++)
        {
            fscanf(seatingFile2, "%c", &mainClassSeating[i][k]);
        }
    }

    //lets the user know what seats can be picked
    printf("\n\t\tNOTE : X - Seat Unavailable.\n\t\t       O - Seat Available\n");

    //different charts for first and main cabins
    if(firstOrSecondClass == 1)
    {
        //display first class seating options
        for(int i = 0; i < 9; i++)
        {
            printf("\t\t");
            for(int j = 0; j < 6; j++)
            {
                printf("%c ", firstClassSeating[i][j]); //prints element [ROW][COLUMN]
                if((j+1)%3 == 0)
                {
                    printf("   "); //for every 3 columns we put spaces for the "walking area" inbetween seats
                }
            }
            printf("\n");
        }

        printf("\t\tPlease enter the row followed by the column of your selected seat.\n"); //prompts for input
        scanf("%d", &row); //collects
        scanf("%d", &column); //collects

        //makes sure the user enters a valid row and column
        while(row > 9 || column > 6)
        {
            printf("\tEntry invalid, please enter the row followed by the column.\n");
            scanf("%d", &row);
            scanf("%d", &column);
        }
        //makes sure user picks a seat that is available
        while(firstClassSeating[row-1][column-1] == 'X')
        {
            printf("\tThat seat is taken. Please choose a new one. Please enter the row followed by the column.\n");
            scanf("%d", &row);
            scanf("%d", &column);

        }
        //changes the seating array making the user's seat now taken
        if(firstClassSeating[row-1][column-1] == 'O')
        {
            firstClassSeating[row-1][column-1] = 'X';
            r = row; //used for ticket assembley.
            c = column;
        }
        //close file and write new contents
        fclose(seatingFile1);
        if(dest == 1)
    {
        seatingFile1 = fopen("phl1.txt","w");
    }
        if(dest == 2)
    {
        seatingFile1 = fopen("lax1.txt","w");
    }
        if(dest == 3)
    {
        seatingFile1 = fopen("dfw1.txt","w");
    }
        if(dest == 4)
    {
        seatingFile1 = fopen("phx1.txt","w");
    }
        if(dest == 5)
    {
        seatingFile1 = fopen("jfk1.txt","w");
    }
        if(dest == 6)
    {
        seatingFile1 = fopen("den1.txt","w");
    }
        if(dest == 7)
    {
        seatingFile1 = fopen("icn1.txt","w");
    }
        for(int i = 0; i < 9; i++)
        {
            for(int k = 0; k < 6; k++)
            {
                fprintf(seatingFile1, "%c", firstClassSeating[i][k]);
            }
        }
        fclose(seatingFile1);


    }

    //main cabin seating, same as above with 3 extra columns of seats.
    //if(firstOrSecondClassArray[1] == 2)
    if(firstOrSecondClass == 2)
    {
        //display main class seating options
        for(int i = 0; i < 9; i++)
        {
            printf("\t\t");
            for(int j = 0; j < 9; j++)
            {
                printf("%c ", mainClassSeating[i][j]);
                if((j+1)%3 == 0)
                {
                    printf("   ");
                }
            }
            printf("\n");
        }

        printf("\t\tPlease enter the row followed by the column of your selected seat.\n");
        scanf("%d", &row);
        scanf("%d", &column);
        while(row > 9 || column > 9)
        {
            printf("\tEntry invalid, please enter the row followed by the column.\n");
            scanf("%d", &row);
            scanf("%d", &column);
        }
        while(mainClassSeating[row-1][column-1] == 'X')
        {
            printf("\tThat seat is taken. Please choose a new one. Please enter the row followed by the column.\n");
            scanf("%d", &row);
            scanf("%d", &column);

        }
        if(mainClassSeating[row-1][column-1] == 'O')
        {
            mainClassSeating[row-1][column-1] = 'X';
            r = row;
            c = column;
        }
    }

    fprintf(passengerDataFile, "| SEAT: %d - %d\n", row, column); //ADD ROW AND COLUMN TO FILE


    //close file and write new contents
    fclose(seatingFile2);
        if(dest == 1)
            {
                seatingFile2 = fopen("phl2.txt","w");
            }
        if(dest == 2)
            {
                seatingFile2 = fopen("lax2.txt","w");
            }
        if(dest == 3)
            {
                seatingFile2 = fopen("dfw2.txt","w");
            }
        if(dest == 4)
            {
                seatingFile2 = fopen("phx2.txt","w");
            }
        if(dest == 5)
            {   
                seatingFile2 = fopen("jfk2.txt","w");
            }
        if(dest == 6)
            {
                seatingFile2 = fopen("den2.txt","w");
            }
        if(dest == 7)
            {
                seatingFile2 = fopen("icn2.txt","w");
            }
        for(int i = 0; i < 9; i++)
        {
            for(int k = 0; k < 6; k++)
            {
                fprintf(seatingFile2, "%c", mainClassSeating[i][k]);
            }
        }
        fclose(seatingFile2);
}

void seatingChart(int dest)
{
    FILE *seatingFile1;
    FILE *seatingFile2;

//opens resepctive file for each destination
    if(dest == 1)
    {
        seatingFile1 = fopen("phl1.txt","r");
        seatingFile2 = fopen("phl2.txt", "r");
    }
    if(dest == 2)
    {
        seatingFile1 = fopen("lax1.txt","r");
        seatingFile2 = fopen("lax2.txt", "r");
    }
    if(dest == 3)
    {
        seatingFile1 = fopen("dfw1.txt","r");
        seatingFile2 = fopen("dfw2.txt", "r");
    }
    if(dest == 4)
    {
        seatingFile1 = fopen("phx1.txt","r");
        seatingFile2 = fopen("phx2.txt", "r");
    }
    if(dest == 5)
    {
        seatingFile1 = fopen("jfk1.txt","r");
        seatingFile2 = fopen("jfk2.txt", "r");
    }
    if(dest == 6)
    {
        seatingFile1 = fopen("den1.txt","r");
        seatingFile2 = fopen("den2.txt", "r");
    }
    if(dest == 7)
    {
        seatingFile1 = fopen("icn1.txt","r");
        seatingFile2 = fopen("icn2.txt", "r");
    }

   if(seatingFile1 == NULL)
   {
      printf("Error!");   
      exit(1);             
   }
   if(seatingFile2 == NULL)
   {
      printf("Error!");   
      exit(1);             
   }


    //fill seats from array first class
    for(int i = 0; i < 9; i++)
    {
        for(int k = 0; k < 6; k++)
        {
            fscanf(seatingFile1, "%c", &firstClassSeating[i][k]);
        }
    }
    //fill seats from array main class
    for(int i = 0; i < 9; i++)
    {
        for(int k = 0; k < 9; k++)
        {
            fscanf(seatingFile2, "%c", &mainClassSeating[i][k]);
        }
    }

    //lets the user know what seats can be picked
    printf("\n\t\tNOTE : X - Seat Unavailable.\n\t\t       O - Seat Available\n");

    //different charts for first and main cabins
    if(firstOrSecondClass == 1)
    {
        //display first class seating options
        for(int i = 0; i < 9; i++)
        {
            printf("\t\t");
            for(int j = 0; j < 6; j++)
            {
                printf("%c ", firstClassSeating[i][j]); //prints element [ROW][COLUMN]
                if((j+1)%3 == 0)
                {
                    printf("   "); //for every 3 columns we put spaces for the "walking area" inbetween seats
                }
            }
            printf("\n");
        }

        //close file
        fclose(seatingFile1);


    }

    //main cabin seating, same as above with 3 extra columns of seats.
    //if(firstOrSecondClassArray[1] == 2)
    if(firstOrSecondClass == 2)
    {
        //display main class seating options
        for(int i = 0; i < 9; i++)
        {
            printf("\t\t");
            for(int j = 0; j < 9; j++)
            {
                printf("%c ", mainClassSeating[i][j]);
                if((j+1)%3 == 0)
                {
                    printf("   ");
                }
            }
            printf("\n");
        }

    }

    fclose(seatingFile2);

}


void ticketInfo(){

    passengerDataFile = fopen(ticketFileName, "r"); //Open file for reading.

    if (passengerDataFile == NULL) //Ensure the file exists
    {
        printf("File does not exist. Terminating..."); //Exit if true
        exit(1);
    }

    while ((ch = fgetc(passengerDataFile)) != EOF){ //Simply print out everything in the passenger file
        printf("%c", ch);
    }

    fclose(passengerDataFile); //Close the file

}

