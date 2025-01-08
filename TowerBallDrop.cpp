#include <iostream>

double getTowerHeight()
{
    std::cout << "Enter the height of the tower (in meters): ";
    double height_of_tower{};
    std::cin >> height_of_tower;
    return height_of_tower;
}

double calculateBallHeight(double current_height, int sec)
{
    double gravity{9.8};
    // formula: distance fallen = (gravity) + (sec * sec) / 2
    double fallDistace = {gravity * (sec * sec) / 2.0};
    double ballHeight{current_height - fallDistace};

    if (ballHeight < 0.0)
    {
        return 0.0;
    }

    return ballHeight;
}

void calculateAndPrintBallHeight(int sec, double tower_height)
{
    tower_height = calculateBallHeight(tower_height, sec);
    if (tower_height > 0.0)
    {
        std::cout << "At " << sec << " seconds, the ball is at height: " << tower_height << " meters\n";
    }
    else
    {
        std::cout << "At " << sec << " seconds, the ball is on the ground.\n";
    }
}

int main()
{
    double tower_height{getTowerHeight()};

    for (int i{}; i <= 5; i++)
    {
        calculateAndPrintBallHeight(i, tower_height);
    }
    return 0;
}
