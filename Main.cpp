#include <iostream>

class Game
{
public:
    int CreateRandomNumber()
    {
        int rndNumber = rand() % 101;
        return rndNumber;
    }
    bool CheckForCorrectness(int numbersUser, int rndNumber)
    {
        if (rndNumber < numbersUser)
        {
            std::cout << "The hidden number is less" << std::endl;
            return false;
        }
        else if (rndNumber > numbersUser)
        {
            std::cout << "The hidden number is greater" << std::endl;
            return false;
        }
        else 
        {
            std::cout << "Victory" << std::endl;
            return true;
        }
    }
    void CheckForExceptions()
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "error" << std::endl;
    }
};

int main()
{
    Game gameObj;
    int rndNumber, numberAttempts, numbersUser;
    bool flagExitGame = 1;

    srand(time(NULL));

    while(flagExitGame)
    {
        numberAttempts = 8;
        rndNumber = gameObj.CreateRandomNumber();

        std::cout << "Guess the number in " << numberAttempts << " attempts" << std::endl;

        while (numberAttempts > 0)
        {
            while (std::cout << "Enter a number:" && !(std::cin >> numbersUser)) {
                gameObj.CheckForExceptions();
            }

            if (gameObj.CheckForCorrectness(numbersUser, rndNumber)) { break; }
            else { numberAttempts--; }

            if (numberAttempts == 0) std::cout << "Game over" << std::endl;

            std::cout << "Attempts:" << numberAttempts << std::endl;
        }

        while (std::cout << "Enter a number(0-exit|1-play):" && !(std::cin >> flagExitGame)) {
            gameObj.CheckForExceptions();
        }

#ifdef _WIN32
        system("cls");
#else
        system("clear");
#endif
    }
}