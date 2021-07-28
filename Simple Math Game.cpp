#include <iostream>
#include <cstring>
#include <unistd.h>
#include <ctime>
#include <cmath>
#include <iomanip>
#include <windows.h>
using namespace std;

string command;
int score;
void init();
void trigger();
void start_the_game();
void game_content();
void end_game();

void init()
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|0x0003);
    cout << "=============================================================================================" << endl;
    cout << "Welcome to The Simple Math Game!" << endl;
    cout << "In this game, you have to answer simple math questions as much as possible within 30 seconds!" << endl;
    cout << "Type the word \"start\" to start! Good Luck!" << endl;
    cout << "Type the word \"exit\" to end the system." << endl;
    cout << "=============================================================================================" << endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|0x0007);
}

void trigger()
{
    cin >> command;
    if(command == "start" || command == "yes"){
        //count down 3 sec then start the game.
        for(int i = 3; i >= 1; i--){
            cout << "Game will start in " << i << " ...";
            sleep(1);
            cout << "\r";
        }
        cout << "\t\t\t\t\t\t\t\r";
        cout << "GO!";
        cout << "\t\t\t\t\t\t\t\r" << endl;
        sleep(1);
        score = 0;
        start_the_game();
        end_game();
    }
    else if(command == "exit" || command == "no"){
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|0x0007);
        return;
    }
    else{
        cout << "Wrong command! Please try again." << endl;
        trigger();
    }
}

void start_the_game()
{
    double start_time = clock();
    while( ((clock() - start_time) / CLOCKS_PER_SEC) < 30 ){
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|0x0007);
        cout << "You have " << fixed << setprecision(2) << (30 - ((clock() - start_time) / CLOCKS_PER_SEC)) << " seconds left!" << endl;
        srand(time(NULL));
        int left, right, answer, input, oper;
        left = rand() % 15 + 1;
        right = rand() % 15 + 1;
        oper = rand() % 3;
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|0x0006);
        cout << left;
        switch(oper){
            case 0:
                cout << " + ";
                answer = left + right;
                break;
            case 1:
                cout << " - ";
                answer = left - right;
                break;
            case 2:
                cout << " * ";
                answer = left * right;
                break;
        }
        cout << right << " = ";
        cin >> input;
        if(input == answer){
            score += 10;
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|0x0002);
            cout << "\t\t\t\t correct!" << endl;
        }
        else{
            score -= 10;
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|0x0004);
            cout << "\t\t\t\t wrong!" << endl;
        }
    }
}

void end_game()
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|0x0007);
    cout << "Time's up!" << endl;
    cout << "Your score is: " << score << endl;

    cout << "Play again?" << endl;
    cout << "Type \"yes\" or \"start\" to play again, \"no\" or \"exit\" to exit." << endl;
    trigger();
}

int main()
{
    init();
    trigger();
    return 0;
}
/*
reference changing color: https://www.it145.com/9/105930.html

對應屬性	藍色字型	綠色字型	紅色字型	高亮字型	藍色背景	綠色背景	紅色背景	高亮背景
十進位制	0x0001	    0x0002	    0x0004	    0x0008	    0x0010	    0x0020	    0x0040	    0x0080

blue    0x0001
green   0x0002
red     0x0004
white   0x0007
yellow  0x0006
pink    0x0005
indigo  0x0003

*/
