#include <bits/stdc++.h>
#include <iostream>
#include <fstream>
#include <string.h>
#include <cstring>

using namespace std;
string musicName, artistName;
double musicDate, musicID;
int num;
fstream outfile;
void delete_music();
void adminAddMusic();
void display_list();

// void deleteMusic()
// {
//     outfile.open("Library.txt");
//     ofstream outfile("Library.txt", ios::trunc);
//     outfile.close();
//     cout << "All books have been deleted!" << endl;
//     cout << "Woud you like to go back (Y/N)?";
// }
void main_list()
{
    // music list
    // cout << "Enter 5 music names: " << endl;
    int choice;
    cout << "1. Add Music" << endl
         << "2. Delete Music" << endl
         << ">> ";

    cin >> choice;

    switch (choice)
    {
    case 1:
        adminAddMusic();
        break;
    case 2:
        delete_music();
        break;
    default:
        cout << "Enter valid Option..." << endl;
        main_list();
        break;
    }
}

void adminAddMusic()
{
    // void registration()
    // {
    //     string ruserId, rPassword, rId, rPass, checkID, pass;
    //     cout << "\t\t\tEnter User Name: ";
    //     cin >> ruserId;
    //     cout << "Enter the PassWord: ";
    //     cin >> rPassword;

    //     ifstream f2("Records.txt");

    //     while (f2 >> checkID >> pass)
    //     {
    //         if (ruserId == checkID)
    //         {
    //             cout << "User Already Exist" << endl;
    //             f2.close();
    //             break;
    //         }
    //         else
    //         {
    //             ofstream f1("Records.txt", ios::app);
    //             f1 << ruserId << "  " << rPassword << endl;

    //             cout << "\t\t\tRegistration is Successful..." << endl;
    //             f1.close();
    //         }
    //     }
    // }
    string choice;
    cout << "Enter Music Details to Add on list" << endl;
    // cout << "How many Music you wanna Add on list" << endl;
    // cin >> num;

    // cout << "Enter " << num << " Music details to Add on list" << endl;
    cout << "Enter Music Name: ";
    cin >> musicName;
    cout << "Enter Artist Name: ";
    cin >> artistName;
    cout << "Enter Music Date in Years: ";
    cin >> musicDate;
    cout << "Enter Music Id: ";
    cin >> musicID;

    ofstream f1("Music.txt", ios::app);
    f1 << musicName << " " << artistName << " " << musicDate << " " << musicID << endl;
    cout << "Music Added Successfully..." << endl;
    f1.close();

    cout << "Would you like to add more Music (Y/N): ";
    cin >> choice;

    if (choice == "Y" || choice == "y")
    {
        adminAddMusic();
    }
    display_list();

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
    // ofstream l1("Music.txt", ios::app);
    // for (int i = 0; i < num; i++)
    // {
    //     // l1 << "Music: "
    //     //    << musicName[i] << "\t\t"
    //     //    << "Artist: " << artistName[i] << "\t\t"
    //     //    << "Date: " << musicDate[i] << "\t\t"
    //     //    << "ID: " << musicID[i] << endl;
    //     l1 << musicName[i] << "\t\t" << artistName[i] << "\t\t" << musicDate[i] << "\t\t" << musicID[i] << endl;
    //     cout << "Music Added Successfully..." << endl;
    // }
}

// void sortAlpha()
// {
//     string temp;                // creating two character arrays, one for storing and one for interchanging
//     for (int i = 0; i < 5; i++) // bubble sort begins to sort the data
//     {
//         for (int j = i + 1; j < 5; j++)
//         {
//             if ((musicName[i] > musicName[j])) // comparing only the ASCII equivalent of the entire word and interchanging if greater
//             {
//                 (temp = musicName[i]);
//                 (musicName[i] = musicName[j]);
//                 (musicName[j] = temp);
//             }
//         }
//     }
//     // cout << "Names rearranged in alphabetical order : \n";
// }

void display_list()
{
    cout << "----------Here is your Music List-----------" << endl;
    string getcontent;
    ifstream openfile("Music.txt");
    cout << "--------------Displaying List-------------" << endl;
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

void delete_music()
{
    outfile.open("Music.txt");
    ofstream outfile("Music.txt", ios::trunc);
    outfile.close();
    cout << "All Music have been deleted!" << endl;
}

void delete_fav_music()
{
    outfile.open("FavoriteList.txt");
    ofstream outfile("FavoriteList.txt", ios::trunc);
    outfile.close();
    cout << "All Favorite Music have been deleted!" << endl;
}

void checkAdmin()
{
    int code;
    do
    {
        cout << "Passcode: ";
        cin >> code;

    } while (code != 123);

    if (code == 123)
    {
        main_list();
        // display_list();
    }
}

// struct book
// {
//     string musicName, artistName, musicDate, bookId;
// } b;
// void deleteMusic()
// {
//     int id, x = 0;
//     struct book b;
//     printf("\t\t\t\t=======Deleting Book From the list=======\n\n\n");
//     printf("\t\t\t\tEnter Music id :");
//     scanf("%d", &id);
//     FILE *f = fopen("Music.txt", "r");
//     FILE *pT = fopen("temporary.txt", "w");
//     while (fscanf(f, "%s\t\t%s\t\t%s\t\t%d\n", b.musicName, b.artistName, b.musicDate, &b.bookId) != EOF)
//     {
//         if (b.bookId != id)
//         {
//             fprintf(pT, "%s\t\t%s\t\t%s\t\t%d\n", b.musicName, b.artistName, b.musicDate, b.bookId);
//         }
//         else
//         {
//             x++;
//             printf("\n---------------------\n");
//             printf(">>> Record deleted<<< \n");
//             printf("---------------------\n\n");
//         }
//     }
//     fclose(f);
//     fclose(pT);
//     remove("Music.txt");
//     rename("temporary.txt", "Music.txt");
// }

// int main()
// {
//     list();
//     sortAlpha();
//     display_list();
// }
