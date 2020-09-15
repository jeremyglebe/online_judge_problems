#include <iostream>
#include <iomanip>
#include <vector>

class TrafficLight
{
public:
    int cycleTime;
    int elapsedTime;
    char color;

    TrafficLight(int cycleTime = 10)
    {
        this->cycleTime = cycleTime;
        this->elapsedTime = 0;
        this->color = 'G';
    }

    void next()
    {
        elapsedTime++;
        switch (color)
        {
        case 'G':
            if (elapsedTime == (cycleTime - 5))
            {
                color = 'O';
                elapsedTime = 0;
            }
            break;
        case 'O':
            if (elapsedTime == 5)
            {
                color = 'R';
                elapsedTime = 0;
            }
            break;
        case 'R':
            if (elapsedTime == cycleTime)
            {
                color = 'G';
                elapsedTime = 0;
            }
            break;
        }
    }
};

int main()
{
    int input;

    std::cin >> input;
    if (!input)
    {
        std::cin >> input;
        if (!input)
        {
            std::cin >> input;
        }
    }

    if (!input)
        return 0;
    else
    {
        while (input)
        {
            // Instantiate all the lights
            std::vector<TrafficLight> lights;
            while (input)
            {
                lights.push_back(TrafficLight(input));
                std::cin >> input;
            }
            // Once all the traffic lights are instantiated, run simulation
            // Time elapsed in seconds during the simulation
            int seconds = 0;
            // Whether we have found a moment when they are all green
            bool found = false;
            // We have to wait until the first time a light turns orange BEFORE starting our search
            bool atLeastOneOrangeLight = false;
            // Loop to wait until one light is orange
            while (!atLeastOneOrangeLight)
            {
                // Increment the time
                seconds++;
                for (int i = 0; i < lights.size(); i++)
                {
                    // Increment each light
                    lights[i].next();
                    // Check if each light is no longer green
                    if (lights[i].color != 'G')
                        atLeastOneOrangeLight = true;
                }
            }
            // Loop to wait 5 hours or until they're all green again
            while (seconds <= 18000 && !found)
            {
                // We should assume they're all green until we find one that isn't
                bool allGreen = true;
                // Process each light
                for (int i = 0; i < lights.size(); i++)
                {
                    // Increment each light
                    lights[i].next();
                    // Check if each light is green
                    if (lights[i].color != 'G')
                        allGreen = false;
                }
                // Increment the time
                seconds++;
                // See if all the lights are green
                if (allGreen)
                {
                    found = true;
                }
            }
            // Print results of the simulation
            if (found)
            {
                int hours = seconds / 3600;
                seconds = seconds % 3600;
                int minutes = seconds / 60;
                seconds = seconds % 60;
                std::cout << std::setfill('0');
                std::cout << std::setw(2) << hours << ':';
                std::cout << std::setw(2) << minutes << ':';
                std::cout << std::setw(2) << seconds << '\n';
            }
            else
            {
                std::cout << "Signals fail to synchronise in 5 hours\n";
            }
            // Check once again for three zeroes
            if (!input)
            {
                std::cin >> input;
                if (!input)
                {
                    std::cin >> input;
                }
            }
        }
    }
}
