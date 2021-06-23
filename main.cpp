#include <iostream>
#include <fstream>

int main() {
    const std::string RIVER_PATH = "..\\river.txt";
    const std::string BASKET_PATH = "..\\basket.txt";
    std::string fishType;
    int fishCount = 0;
    std::cout << "Please enter the fish type: ";
    std::cin >> fishType;

    std::ifstream riverStream(RIVER_PATH);
    if (riverStream.is_open())
    {
        std::string fishInTheRiver;
        while (!riverStream.eof())
        {
            riverStream >> fishInTheRiver;
            if (fishInTheRiver == fishType)
            {
                std::ofstream basketStream(BASKET_PATH, std::ios::app);
                if (basketStream.is_open())
                {
                    basketStream << fishType << '\n';
                    basketStream.close();
                    fishCount++;
                }
                else
                {
                    std::cerr << "Basket file can't be opened. No-where to store fish!\n";
                    riverStream.close();
                    return 0;
                }
            }
        }
        riverStream.close();
    }
    else
    {
        std::cerr << "River file can't be opened. No river - no fish!\n";
        return 0;
    }
    std::cout << "Fish were caught: " << fishCount << "\n";

    return 0;
}
