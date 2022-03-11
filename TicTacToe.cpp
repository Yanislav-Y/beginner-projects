#include <iostream>

int main() {
    std::cout << "Tic-Tac-Toe\n";
    std::cout << "Player 1: 0's, player 2: X's\n";
    bool gameOver {false};
    short int input; //player input
    unsigned short int turn {0}; //will determine if it's player 1 or 2's turn
    char grid[3][3] {
        {'-','-','-'},
        {'-','-','-'},
        {'-','-','-'}     //initial grid values, 2-D array as the data stored can be represented in a 2 dimensional way
    };
    char symbol[2] {'0','X'};
    int inputAvailable {9};      //will be used to check for a stalemate

    while(gameOver == false) {     //keep game running while it's not over
        int playerTurn {turn % 2};   //gives value of 0 or 1, so I don't have to keep writing `turn%2` ==> improved readability
        std::cout << "Player " << ((playerTurn) + 1) << "'s turn: ";
        std::cout << "Type in the place where you want to put your '0' (number between 1 and 9, 1 is top left, 9 is bottom right)";
        std::cin >> input;
        int inputHorizontal {(input-1)/3};       //these 2 lines will print values between 0 and 2 based off 
        int inputVertical {(input-1)%3};         //where the player wants their symbol, increases readability
        if((input > 9) || (input < 1)) {     //ensuring input is valid
            std::cout << "This is not a valid input\n";
            continue;
        }
        if((grid[inputHorizontal][inputVertical]) == '-') { //this line makes sure that the input doesn't override existing inputs
            grid[inputHorizontal][inputVertical] = symbol[playerTurn];  //array from earlier inputs the correct symbol in place
            std::cout << grid[0][0] << " | " << grid[0][1] << " | " << grid[0][2] << "\n";
            std::cout << "----------\n";
            std::cout << grid[1][0] << " | " << grid[1][1] << " | " << grid[1][2] << "\n";         //prints the grid
            std::cout << "----------\n";
            std::cout << grid[2][0] << " | " << grid[2][1] << " | " << grid[2][2] << "\n";
            inputAvailable--;   //decrements after every successful input to keep a track for a potential stalemate
        }
        else {
            std::cout << "This is not a valid input\n";
            continue;  //restarts the while loop, ensuring that it's still the same players turn and they have
        }              //the chance to re-type their input instead of just ending the game after every typo

        //winning criteria
        for(int i {0}; i < 3; i++) { //these check if there's a 3-in-a-row anywhere
            if((grid[i][0] == grid[i][1]) && (grid[i][0] == grid[i][2]) && (grid[i][0] != '-')) { //horizontal check
                std::cout << "Game over!\n";
                std::cout << "Player " << ((playerTurn) + 1) << " wins!";
                gameOver = true;
                break;   //`break` to terminate the loop in case of a positive, so multiple "Game over!" are not printed in some cases
            }
            if((grid[0][i] == grid[1][i]) && (grid[0][i] == grid[2][i]) && (grid[0][i] != '-')) { //vertical check
                std::cout << "Game over!\n";
                std::cout << "Player " << ((playerTurn) + 1) << " wins!";
                gameOver = true;
                break;
            }
            if((grid[0][0] == grid[1][1]) && (grid[0][0] == grid[2][2]) && (grid[0][0] != '-')) { //diagonal check
                std::cout << "Game over!\n";
                std::cout << "Player " << ((playerTurn) + 1) << " wins!";
                gameOver = true;
                break;
            }
            if((grid[0][2] == grid[1][1]) && (grid[0][2] == grid[2][0]) && (grid[0][2] != '-')) { //2nd diagonal check
                std::cout << "Game over!\n";
                std::cout << "Player " << ((playerTurn) + 1) << " wins!";
                gameOver = true;
                break;
            }
            //check for stalemate
            if(inputAvailable == 0) {
            std::cout << "Stalemate!\n";
            gameOver = true;
            break;
        }
        }
        turn++;  //increment turn after every successful input, placed after the game-over checks so the correct player
    }            //number is printed in the line `std::cout << "Player " << ((playerTurn) + 1) << " wins!";`
                //turn is also incremented by 1 so the value is always even, followed by odd, so turn%2 alternates between
                //player 1 and 2 after every successful input
    return 0;
}
