// #include <cctype>
#include <cstring>
#include <iostream>
#include <fstream>
#include <string.h>
#include "admin.cc"

using namespace std;
// int option;

void user_design();
void further_option();
void searchMusic();
void addFav();
void favList();
void displayFav();
void removeFav();

void userList()
{
    // music list
    string musicName, musicDate, musicID;
    ofstream l1("Music.txt", ios::app);
    l1 << musicName << "  " << musicDate << " " << musicID << endl;
}

void login()
{
    int count = 0;
    string userId, password, id, pass, email;
    cout << "\t\t\t Please Enter the user Name and Password..." << endl;
    cout << "\t\t\t USERNAME: ";
    cin.ignore() >> userId;
    cout << "\t\t\tPASSWORD: ";
    cin >> password;
    // cout << "Email: ";
    // cin >> email;

    ifstream input("Records.txt");

    while (input >> id >> pass)
    {
        if (id == userId && pass == password)
        {
            count = 1;
        }
        // else if (id == userId && pass != password)
        // {
        //     cout << "Wrong Password..try again" << endl;
        // }
        // else
        // {
        //     cout << "User not Found...Please try again" << endl;
        //     exit(0);
        // }
        input.close();
        if (count == 1)
        {
            int choice;
            transform(userId.begin(), userId.end(), userId.begin(), ::toupper);
            cout << userId << endl;
            cout << "Login Successful..." << endl;
            cout << "-----------------------HI, " << userId << ",------------------" << endl;
            cout << "\t\t--------------------Welcome To-------------------" << endl;
            cout << "\t\t-------------------Music Management System--------------------" << endl;
            // main();

            display_list();
            user_design();
            // cout << "1. Whole List" << endl
            //      << "2. Favorite List" << endl;
            // cin >> choice;
            // switch (choice)
            // {
            // case 1:
            //     user_design();
            //     break;
            // case 2;
            //     favList();
            // default:
            //     break;
            // }
            // further_option();
        }
        else
        {
            cout << "LOGIN ERROR...Please Check your USERNAME!!!" << endl;
        }
    }
}

void registration()
{
    string ruserId, rPassword, rId, rPass, checkID, pass;
    cout << "\t\t\tEnter User Name: ";
    cin >> ruserId;
    cout << "Enter the PassWord: ";
    cin >> rPassword;

    // ofstream f2("Records.txt", ios::app);

    ofstream f1("Records.txt", ios::app);
    f1 << ruserId << "  " << rPassword << endl;
    cout << "Registration is Successful!!";
    login();

    // while (f2 << checkID << pass)
    // {
    //     if (ruserId == checkID)
    //     {
    //         cout << "User Already Exist" << endl;
    //         f2.close();
    //         break;
    //     }
    //     else
    //     {

    //         cout << "\t\t\tRegistration is Successful..." << endl;
    //         f1.close();
    //     }
    // }
}

void case1()
{
    int count = 0;
    string sUserId, sId, sPass;
    cout << "\n\t\t Enter the UserName which you remembered: ";
    cin >> sUserId;

    ifstream f2("Records.txt");
    while (f2 >> sId >> sPass)
    {
        if (sId == sUserId)
        {
            count = 1;
        }
    }
    f2.close();
    if (count == 1)
    {
        cout << "\n\n Your account is found!! \n";
        cout << "\n Your password is: " << sPass;
    }
    else
    {
        cout << "Sorry! Your account is not found!! \n";
    }
}

void forgot()
{
    int option;
    cout << "\t\t\t Forgot the Password??? IDIOT!!!";
    cout << "Press 1 to search your Id by Username: " << endl;
    // cout << "\t\t\t Enter your choice: ";
    cin >> option;

    switch (option)
    {
    case 1:
        case1();
        break;

    default:
        cout << "\t\t\t Wrong choice! Please try again..." << endl;
        forgot();
    }
}

void login_design()
{
    cout << "\t\t______________________________________________________________________________" << endl
         << endl
         << endl;
    cout << "\t\t..............................Welcome to the Login Page......................." << endl
         << endl
         << endl;
    cout << "\t\t____________________________________   Menu ________________________________\n\n";
    cout << " \n\n";
    cout << "\t | Press 1 to Login  |" << endl;
    cout << "\t | Press 2 to Register  |" << endl;
    cout << "\t | Press 3 for Forgot Password  |" << endl;
    cout << "\t | Press 4 to Exit      |" << endl;
}

void user_design()
{
    int option;
    cout << "Enter further options..." << endl;
    do
    {
        cout << "1. Search Music" << endl;
        cout << "2. Add to favorite list" << endl;
        cout << "3. Display favorite list" << endl;
        cout << "4. Remove from favorite list" << endl;
        cout << "5. Exit" << endl;
        cout << ">> ";
        cin >> option;
        switch (option)
        {
        case 1:
            searchMusic();
            break;

        case 2:
            addFav();
            break;

        case 3:
            displayFav();
            break;
            // case 4:
            //     removeFav();
            //     break;

        case 5:
            cout << "Enter Valid Option and try again..." << endl;
            break;

        default:
            break;
        }
    } while (option != 5);
    // if (option == 5)
    // {
    //     cout << "Your Application has Terminated..." << endl;
    // }
}

void searchMusic()
{
    // int count = 0;
    string music_name, artist_name, musicDate, musicID, search_musicName, search_artistName, search_musicDate, search_musicId;
    cout << "You are about to search Music by Music Name: " << endl;
    cout << "Enter Music Name: ";
    cin.ignore() >> music_name;

    // cout << "Enter Artist Name: ";
    // cin >> artist_name;
    // cout << "Enter Music Date: ";
    // cin >> search_musicDate;
    // cout << "Enter Music ID: ";
    // cin >> search_musicId;

    ifstream input("Music.txt");

    while (input >> search_musicName >> search_artistName >> search_musicDate >> search_musicId)
    {
        if (music_name == search_musicName)
        {
            cout << "Music Found" << endl;
            input.close();
            break;
        }
        else
        {
            cout << "Music not Found..." << endl;
            cout << "Your Music will be available soon..." << endl;
            exit(0);
        }
    }
    // input.close();
    // cout << "COUNT: " << count << endl;
    // if (count == 1)
    // {
    //     cout << "Your music Found..." << endl;
    // }
    // else
    // {
    //     cout << "ThankYou!" << endl;
    // }
}

// void further_option()
// {
//     int count = 0;
//     if (option == 1)
//     {
//     }
// }

void addFav()
{
    // cout << "Enter Music to add on Favorite List: ";

    // cout << "Enter Music Details to Add on list" << endl;
    // cout << "How many Music you wanna Add on list" << endl;
    // cin >> num;

    // cout << "Enter " << num << " Music details to Add on list" << endl;

    // for (int i = 0; i < num; i++)
    // {
    //     cout << "Music Name: ";
    //     cin >> musicName[i];
    //     cout << "Artist Name: ";
    //     cin >> artistName[i];
    //     cout << "Release Year: ";
    //     cin >> musicDate[i];
    //     cout << "Music ID: ";
    //     cin >> musicID[i];
    // }
    // ofstream l1("FavoriteList.txt", ios::app);
    // for (int i = 0; i < num; i++)
    // {
    //     l1 << musicName[i] << "\t\t" << artistName[i] << "\t\t" << musicDate[i] << "\t\t" << musicID[i] << endl;
    // }
    // cout << "Music Added Successfully...on Favorite List" << endl;
    string choice;
    cout << "Enter Music Details to Add on Favorite list" << endl;
    // cout << "How many Music you wanna Add on list" << endl;
    // cin >> num;

    // cout << "Enter " << num << " Music details to Add on list" << endl;
    string favMusicName, favArtName, favMusicDate, favMusicId;

    cout << "Enter Music Name: ";
    cin >> favMusicName;
    cout << "Enter Artist Name: ";
    cin >> favArtName;
    cout << "Enter Music Date in Years: ";
    cin >> favMusicDate;
    cout << "Enter Music Id: ";
    cin >> favMusicId;

    ofstream f1("FavoriteList.txt", ios::app);
    f1 << favMusicName << " " << favArtName << " " << favMusicDate << " " << favMusicId << endl;
    cout << "Music Added Successfully..." << endl;
    f1.close();

    cout << "Would you like to add more Music (Y/N): ";
    cin >> choice;

    if (choice == "Y" || choice == "y")
    {
        addFav();
    }
}

void displayFav()
{

    // cout << "----------Here is your Music List-----------" << endl;
    string getcontent;
    ifstream openfile("FavoriteList.txt");
    cout << "-------------- Displaying Favorite List -------------" << endl;
    if (openfile.is_open())
    {
        while (!openfile.eof())
        {
            openfile >> getcontent;
            cout << getcontent << " ";
        }
        cout << endl;
    }
    // for (int i = 0; i < 5; i++)
    // {
    //     cout << musicName[i] << "\n";
    // }
}

void checkAdmin()
{
    int code;
    cout << "Passcode: ";
    cin >> code;

    if (code == 123)
    {
        main_list();
        display_list();
    }
    else
    {
        cout << "Wrong CODE!!!" << endl;
    }
}

int main()
{
    int check;
    cout << "\n-----------Enter Your Choice----------" << endl;
    do
    {
        cout << "1.Admin\n2.User" << endl
             << ">>";
        cin >> check;
    } while (check != 1 && check != 2);

    if (check == 1)
    {
        checkAdmin();
    }
    else if (check == 2)
    {
        int c;
        login_design();

        cout << "\t\tEnter Your choice: ";
        cin >> c;
        cout << endl;
        switch (c)
        {
        case 1:
            login();
            break;
        case 2:
            registration();
            break;
        case 3:
            forgot();
            break;
        case 4:
            cout << "\t\t\t ThankYou...\n\n";
            break;
        default:
            cout << "\t\tPlease select from the option given...\n\n";
            main();
        }
    }
    else
    {
        cout << "Enter Valid Option" << endl;
    }
}