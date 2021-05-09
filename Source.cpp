#include <iostream>
#include <ctime>
#include <random>
#include <chrono>
#include <thread>
#include <Windows.h>
#include <string>
using namespace std;

//DECLARING FUNCTIONS
int winsCount;
char board[9] = { ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' };
void show_board();
void get_x_player_choice();
void get_o_player_choice();
void get_computer_choice();
void get_computer_choice2();
int count_board(char symbol);
char check_winner();
int computer_vs_player();
void player_vs_player();
void computer_vs_computer();
void board_reset();
void quit_game();

int main()
{
    
    int mode;
    //GAME MENU
    cout << "WELCOME TO TICTACTOE GAME" << endl << endl;
    cout << "You have beaten the Computer " << winsCount << " times" << endl << endl;
    cout << "Select Game Mode." << endl << endl;
    cout << "1. Computer VS Player." << endl;
    cout << "2. Player VS Player." << endl;
    cout << "3. Computer VS Computer." << endl << endl;
    cout << "4. Quit game." << endl << endl;
    cout << "> ";
    
    //CHECKS IF INPUT IS VALID
    while (!(cin >> mode))
    {
        cin.clear(); // clear the error flags
        cin.ignore(INT_MAX, '\n'); // discard the row
        cout << "Invalid input! Try again: " << endl << endl;
        cout << "> ";
    }

    switch (mode) {
    case 1:
        computer_vs_player();
        break;
    case 2:
        player_vs_player();
        break;
    case 3:
        computer_vs_computer();
        break;
    case 4:
        cout << "Thanks for playing my game." << endl;
        exit(0);
        break;
    default:
        int counter = 1;
        Sleep(1000);
        while (counter >= 1)
        {
            cout << "Please Select Valid Game Mode. " << flush;
            Sleep(1000);
            counter--;
        }
        system("cls");
        main();
    }
    int playerVsPlayerResult = computer_vs_player(); //STORE LAST GAME RESULT
    winsCount = winsCount + playerVsPlayerResult; //POINTS COUNTER
    return 0;
}
//CLEAR BOARD
void board_reset() 
{
    for (int i = 0; i < 9; i++) 
    {
        board[i] = ' ';
    }
}
//EXIT GAME
void quit_game()
{
    exit(0);
}

void timer()
{
    int counter = 5; //amount of seconds
    Sleep(1000);
    while (counter >= 1)
    {
        cout << "\rReturning to main screen in: " << counter << flush;
        Sleep(1000);
        counter--;
    }
}

int computer_vs_player() {
       
    int winCount = 1;
    string player_name;
    cout << "Enter Your Name : ";
    cin >> player_name;
    while (true) {
        system("cls");
        show_board();
        if (count_board('X') == count_board('O')) {
            cout << player_name << "'s Turn." << endl;
            get_x_player_choice();
            
        }
        else {
            this_thread::sleep_for(chrono::milliseconds(1500));
            get_computer_choice();
        }
        char winner = check_winner();
        if (winner == 'X') {
            system("cls");
            show_board();
            cout << player_name << " Won The Game." << endl;
            winsCount++;
            timer();
            system("cls");
            board_reset();
            main();
        }
        else if (winner == 'O') {
            system("cls");
            show_board();
            cout << "Computer Won The Game." << endl;
            break;
        }
        else if (winner == 'D') {
            cout << "Game is Draw." << endl;
            break;
        }
    }
    
    return winsCount;
}

//GET FIRST COMPUTER IMPUT
void get_computer_choice() {

    srand(time(0));
    int choice;
    do {
        choice = rand() % 10;
    } while (board[choice] != ' ');
    board[choice] = 'O';
}

//GET SECOND COMPUTER IMPUT
void get_computer_choice2()
{
    srand(time(0));
    int choice;
    do {
        choice = rand() % 10;
    } while (board[choice] != ' ');
    board[choice] = 'X';
}

void get_x_player_choice() {
    while (true) {
        cout << "Select Your Position(A - I) : ";
        int choice;
        char input;

        cin >> input;

        if (input == 'a' ) {
            choice = 1;
        }else if (input == 'b') {
            choice = 2;
        }else if (input == 'c') {
            choice = 3;
        }else if (input == 'd') {
            choice = 4;
        }else if (input == 'e') {
            choice = 5;
        }else if (input == 'f') {
            choice = 6;
        }else if (input == 'g') {
            choice = 7;
        }else if (input == 'h') {
            choice = 8;
        }else if (input == 'i') {
            choice = 9;
        }else if (input == 'A') {
            choice = 1;
        }else if (input == 'B') {
            choice = 2;
        }else if (input == 'C') {
            choice = 3;
        }else if (input == 'D') {
            choice = 4;
        }else if (input == 'E') {
            choice = 5;
        }else if (input == 'F') {
            choice = 6;
        }else if (input == 'G') {
            choice = 7;
        }else if (input == 'H') {
            choice = 8;
        }else if (input == 'I') {
            choice = 9;
        }
        else if (input == 'Q') {
            quit_game();
        }
        else {
            break;
        }
           
        choice--;

        if (choice < 0 || choice > 8) {
            cout << "Please Select Your Choice From(A- I)." << endl;
        }
        else if (board[choice] != ' ') {
            cout << "Please Select An Empty Position." << endl;
        }
        else {
            board[choice] = 'X';
            break;
        }
    }
}

void get_o_player_choice() {
    while (true) {
        cout << "Select Your Position(A - I) : ";
        int choice;
        char input;

        cin >> input;

        if (input == 'a') {
            choice = 1;
        }
        else if (input == 'b') {
            choice = 2;
        }
        else if (input == 'c') {
            choice = 3;
        }
        else if (input == 'd') {
            choice = 4;
        }
        else if (input == 'e') {
            choice = 5;
        }
        else if (input == 'f') {
            choice = 6;
        }
        else if (input == 'g') {
            choice = 7;
        }
        else if (input == 'h') {
            choice = 8;
        }
        else if (input == 'i') {
            choice = 9;
        }
        else if (input == 'A') {
            choice = 1;
        }
        else if (input == 'B') {
            choice = 2;
        }
        else if (input == 'C') {
            choice = 3;
        }
        else if (input == 'D') {
            choice = 4;
        }
        else if (input == 'E') {
            choice = 5;
        }
        else if (input == 'F') {
            choice = 6;
        }
        else if (input == 'G') {
            choice = 7;
        }
        else if (input == 'H') {
            choice = 8;
        }
        else if (input == 'I') {
            choice = 9;
        }
        else if (input == 'Q') {
            quit_game();
        }
        else {
            break;
        }
        choice--;
        if (choice < 0 || choice > 8) {
            cout << "Please Select Your Choice From(A - I)." << endl;
        }
        else if (board[choice] != ' ') {
            cout << "Please Select An Empty Position." << endl;
        }
        else {
            board[choice] = 'O';
            break;
        }
    }
}
//PLAYER VS PLAYER MODE
void player_vs_player() {
    
     string x_player_name, o_player_name;
    cout << "Enter X Player Name : ";
    cin >> x_player_name;
    cout << "Enter O Player Name : ";
    cin >> o_player_name;
    while (true) {
        system("cls");
        show_board();
        if (count_board('X') == count_board('O')) {
            cout << x_player_name << "'s Turn." << endl;
            get_x_player_choice();
        }
        else {
            cout << o_player_name << "'s Turn." << endl;
            get_o_player_choice();
        }
        char winner = check_winner();
        if (winner == 'X') {
            system("cls");
            show_board();
            cout << x_player_name << " Won The Game." << endl;
            timer();
            system("cls");
            board_reset();
            main();
            break;
        }
        else if (winner == 'O') {
            system("cls");
            show_board();
            cout << o_player_name << " Won The Game." << endl;
            timer();
            system("cls");
            board_reset();
            main();
            break;
        }
        else if (winner == 'D') {
            cout << "Game is Draw." << endl;
            timer();
            system("cls");
            board_reset();
            main();
            break;
        }
    }
}

//COMPUTER VS COMPUTER MODE
void computer_vs_computer()
{
    while (true) {
        system("cls");
        show_board();
        if (count_board('X') == count_board('O')) {
            cout << "Computer 1's Turn..." << endl;
            this_thread::sleep_for(chrono::milliseconds(1500));
            get_computer_choice2();
        }
        else {
            cout << "Computer 2's Turn..." << endl;
            this_thread::sleep_for(chrono::milliseconds(1500));
            get_computer_choice();
        }
        char winner = check_winner();
        if (winner == 'X') {
            system("cls");
            show_board();
            cout << "Computer 1 Won The Game." << endl;
            timer();
            system("cls");
            board_reset();
            main();
            break;
        }
        else if (winner == 'O') {
            system("cls");
            show_board();
            cout << "Computer 2 Won The Game." << endl;
            timer();
            system("cls");
            board_reset();
            main();
            break;
        }
        else if (winner == 'D') {
            cout << "Game is Draw." << endl;
            timer();
            system("cls");
            board_reset();
            main();
            break;
        }
    }
}

//COUNT HOW MANY MOVES ON GAME
int count_board(char symbol) {
    int total = 0;
    for (int i = 0; i < 9; i++) {
        if (board[i] == symbol)
            total += 1;
    }
    return total;
}

char check_winner() {
    // checking winner in horizontal/row
    if (board[0] == board[1] && board[1] == board[2] && board[0] != ' ')
        return board[0];
    if (board[3] == board[4] && board[4] == board[5] && board[3] != ' ')
        return board[3];
    if (board[6] == board[7] && board[7] == board[8] && board[6] != ' ')
        return board[6];
    // checking winner in vertical/column
    if (board[0] == board[3] && board[3] == board[6] && board[0] != ' ')
        return board[0];
    if (board[1] == board[4] && board[4] == board[7] && board[1] != ' ')
        return board[1];
    if (board[2] == board[5] && board[5] == board[8] && board[2] != ' ')
        return board[2];
    // checking winner in diagonal
    if (board[0] == board[4] && board[4] == board[8] && board[0] != ' ')
        return board[0];
    if (board[2] == board[4] && board[4] == board[6] && board[2] != ' ')
        return board[2];
    if (count_board('X') + count_board('O') < 9)
        return 'C';
    else
        return 'D';
}
//PRINT BOARD
void show_board() {

    cout << "    " << " |  " << " | " << endl;
    cout << "   " << board[0] << " | " << board[1] << " | " << board[2] << endl;
    cout << "    " << " |  " << " | " << endl;
    cout << "---------------" << endl;
    cout << "    " << " |  " << " | " << endl;
    cout << "   " << board[3] << " | " << board[4] << " | " << board[5] << endl;
    cout << "    " << " |  " << " | " << endl;
    cout << "---------------" << endl;
    cout << "    " << " |  " << " | " << endl;
    cout << "   " << board[6] << " | " << board[7] << " | " << board[8] << endl;
    cout << "    " << " |  " << " | " << endl << endl;

    cout << "  INSTRUCTIONS" << endl << endl;
        
    cout << "     A""|""B""|""C" << endl;
    cout << "    -------" << endl;
    cout << "     D""|""E""|""F" << endl;
    cout << "    -------" << endl;
    cout << "     G""|""H""|""I" << endl << endl;

    cout << "(Q) Quit game" << endl << endl;
}