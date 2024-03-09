#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define USERNAME_LENGTH 20
#define PASSWORD_LENGTH 20
#define MAX_ROOMS 100
#define MAX_USERS 1
#define MAX_PATIENTS 100


//structure of user
struct User {
    char username[USERNAME_LENGTH];
    char password[PASSWORD_LENGTH];
};
struct User users[MAX_USERS];
//structer of rooms
typedef struct {
    int roomNumber;
    bool isReserved;
    int PatientId;
} Room;
Room hospitalrooms[MAX_ROOMS];
//structure of patient
typedef struct {
    int id;
    char name[50];
    bool isUnderTreatment;
} Patient;
Patient patients[MAX_PATIENTS];


int main() {
    //static data of rooms
    hospitalrooms[0].roomNumber = 12;
 hospitalrooms[0].isReserved = true;
 hospitalrooms[0].PatientId=56;
 hospitalrooms[1].roomNumber = 15;
 hospitalrooms[1].isReserved = true;
 hospitalrooms[1].PatientId=20;
 
 //static data of user 
    strcpy(users[0].username, "user1");
    strcpy(users[0].password, "password1");
    //static data of patient
    patients[0].id=15;
    strcpy(patients[0].name, "Ahmad");
    patients[0].isUnderTreatment = 0;
    //user must login before any function
    char username[20];
    char password[20];
    printf("Enter username: ");
    scanf("%s", username);
    printf("Enter password: ");
    scanf("%s", password);
    login(username, password);
    //choose number of function you need to test
    int ch;
    do {
        printf("\nMain Menu\n");
        printf("1. Remove Reservation\n");
        printf("2. Check Empty Rooms\n");
        printf("3. Update Patient\n");
        printf("4. reserve room\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch(ch) {
            case 1:
int roomToRemoveReservation ;
      printf("Enter number of room you want to remove reservation from :");
    scanf("%d", &roomToRemoveReservation);
    removeReservation(roomToRemoveReservation);
    if (!hospitalrooms[roomToRemoveReservation - 1].isReserved) {
        printf("Room %d is now empty.\n", roomToRemoveReservation);
    } else {
        printf("Failed to remove reservation from room %d.\n", roomToRemoveReservation);
    }                break;
            case 2:
           int numberofroomtocheck;
         printf ("Enter number of room to check is empty or no");
         scanf("%d",&numberofroomtocheck);
        checkemptyrooms(numberofroomtocheck);
        printf("Here is number of room reserved from 0 to 100 ");
        listallReservedRooms();
                break;
            case 3:
int id;
    char name[50];
    bool isActive;
    printf("Enter patient ID: ");
    scanf("%d", &id);
    printf("Enter patient name: ");
    scanf("%s", name); 
    printf("Is the patient under treatment (1 for yes, 0 for no)? ");
    scanf("%d", &isActive);
    updatePatient(id, name, isActive);
    break;
            case 4:
                 reserveroom();
                 printf("Here is number of room reserved from 0 to 100 ");
        listallReservedRooms();
                break;
            default:
                printf("Invalid choice. Please enter a number between 1 and 5.\n");
        }
    } while(ch != 5);

    return 0;
}
//login function
void login(char username[20],char password[20] ) {
 
        for (int i = 0; i < MAX_USERS; i++) {
        if (strcmp(users[i].username, username) == 0 && strcmp(users[i].password, password) == 0) {
printf("Welcome employee x");        }
printf("wrong credintials");
    }
}
//show all number of reserved room
void listallReservedRooms(){
    int count=0;
    for (int i = 0; i < MAX_ROOMS; i++) {
        if (hospitalrooms[i].isReserved){
             printf("\n");
            printf("%d",hospitalrooms[i].roomNumber);
        }
}
}
//check if number of room empty or no
void checkemptyrooms(int room_number) {
    for (int i = 0; i < MAX_ROOMS; i++) {
        if (hospitalrooms[i].roomNumber==room_number&&hospitalrooms[i].isReserved){
            printf("\n");
            printf("this room is reserved");
            printf("\n");
            break;
        }
        else{
            printf("\n");
             printf("this room is empty");
             break;
        }
    
    }
    
}
//reserve room if you need
void reserveroom(){
    int patientnumber;
    int roomNumber;
    printf("Enter room number to res");
    scanf("%d",&roomNumber);
    printf("Enter patient number");
    scanf("%d",&patientnumber);
    hospitalrooms[2].roomNumber = roomNumber;
    hospitalrooms[2].isReserved = true;
    hospitalrooms[2].PatientId=patientnumber;
}
//if patient exist return it's index else return -1
int findPatientIndexById(int id) {
    for (int i = 0; i < MAX_PATIENTS; i++) {
        if (patients[i].id == id) {
            return i;
        }
        else{
            return -1;
        }
    }
   
}
//count number of patients 
int count_number_of_Patients(){
    int count=0;
     for (int i = 0; i < MAX_PATIENTS; i++) {
        if (patients[i].id !=0) {
            count++;
        }
}
     return count;
}
//enter number of room to remove
void removeReservation(int roomNumber) {
    for (int i = 0; i < MAX_ROOMS; i++) {
        if (hospitalrooms[i].roomNumber == roomNumber) {
            if (hospitalrooms[i].isReserved) {
                hospitalrooms[i].isReserved = false;
                printf("Reservation for room %d has been removed.\n", roomNumber);
            } else {
                printf("Room %d is not currently reserved.\n", roomNumber);
            }
            return;
        }
    }
    printf("Room number %d already empty.\n", roomNumber);
}
//enter data of patient if exist update it else create new patient with statues
void updatePatient(int id, char name[20], bool isUnderTreatment) {
 int index = findPatientIndexById(id);
    int no_of_patients=count_number_of_Patients();

    if (index != -1) {
        strcpy(patients[index].name, name);
        patients[index].isUnderTreatment = isUnderTreatment;
        printf("Patient %d updated successfully.\n", id);
         printf("Patient record: ID=%d, Name=%s, Active=%d\n", patients[index].id, patients[index].name, patients[index].isUnderTreatment);
    } else {
        
        if ( no_of_patients<MAX_PATIENTS ) {
            patients[no_of_patients+1].id = id;
            strcpy(patients[no_of_patients+1].name, name);
            patients[no_of_patients+1].isUnderTreatment = isUnderTreatment;
            printf("New patient added with ID %d.\n", id);
             printf("Patient record: ID=%d, Name=%s, Active=%d\n", patients[no_of_patients+1].id, patients[no_of_patients+1].name, patients[no_of_patients+1].isUnderTreatment);
    }
        } 
        
    }
