#include <iostream>
#include <iomanip>
using namespace std;

string user[100000][7]={{}};

string item[100000][9]={{}};

int current_id,last_id = 0;


int current_item_id,last_item_id = 0;
#include "function.h"  // Include the function definitions

//                    0      1            2           3              4            5            6
// For user[x][7] = "id","First Name","Last Name","Password","Department","Email Address","Phone Number"

// x is used to go through each user
// y is used to access information about each user
// The value of user[0][0] = "0"
//              user[1][0] = "1" meaning id == each row
//last_id is used to create an account
//current_id is used to point at the row of the selected user

//                    0     1        2             3             4              5            6                 7             8
// For item[x][9] = "id","Name","Description","Location","Date/Time Found","Email", "Phone Number", "Claimed/Unclaimed","Finder id"
// current_item_id is used to access the item
// last_item_id is used to log lost item

//Main program entry point for the Lost and Found Tracker
int main()
{
    // Check if any users exist in the system
    char choice;

    if(user[0][1] ==""){
            main_menu:
                // Display main menu for first-time users
            cout << "\t\t\t\t\t*******************************************"<< endl;
            cout << "\t\t\t\t\t\t LOST AND FOUND TRACKER" << endl;
            cout << "\t\t\t\t\t******************************************* \n\n\n"<< endl;
            cout << "1. Sign up \n" << endl;
            cout << "2. Log in \n" << endl;
            cout << "3. Exit \n" << endl;
            cout << "Choice: ";

            cin >> choice;
            switch(choice){
                case '1':
                    // Create a new user account
                    system("CLS");
                    CreateAccount();
                    break;

                case '2':
                    // Log in to an existing account
                    if(user[0][0]==""){
                            system("CLS");
                            cout << "There are no Accounts \n\n\n";
                            main();
                    }
                    else{
                            system("CLS");
                            SelectAccount();
                    }
                    break;

                case '3':
                    // Exit the program
                    return 0;
                    break;
                default:
                    //Handle invalid input
                    system("CLS");
                    cout << "\t\t***Please Enter a valid choice***\n\n\n" << endl;
                    main();
                    }
            }
    else{
            // Display the main dashboard for logged-in users
        cout << "\t\t\t\t\t*******************************************"<< endl;
        cout << "\t\t\t\t\t\t LOST AND FOUND TRACKER" << endl;
        cout << "\t\t\t\t\t******************************************* \n\n\n"<< endl;
        cout << "\t\t Id: " << current_id <<endl;
        cout << "\t\t Name: " << user[current_id][1]<<" "<<user[current_id][2]<<"\n\n\n" << endl;
        cout << "1. Find Lost Item \n" << endl;
        cout << "2. Register Found Item \n" << endl;
        cout << "3. List Lost Items \n" << endl;
        cout << "4. Edit User Account \n" << endl;
        cout << "5. Return to Main Menu \n" << endl;
        cout << "6. Exit \n " << endl;
        cout << "Choice: ";


        cin >> choice;
        switch(choice){
            case '1':
                // Search for lost items
                system("cls");
                FindLostItem();
                break;
            case '2':
                // Register a newly found item
                system("cls");
                RegisterFoundItem();
                break;
            case '3':
                // Display a list of all registered items
                system("cls");
                ListItem();
                break;
            case '4':
                // Edit the current user's account information
                system("cls");
                EditUser();
                break;
            case '5':
                //Return to main menu
                system("cls");
                goto main_menu;
                break;
            case '6':
                //Exit the program
                return 0;
                break;
            default:
                //Handle invalid input
                system("cls");
                cout <<"**Please Enter a valid choice**";
                main();
                break;
        }
    }
    return 0;
}
