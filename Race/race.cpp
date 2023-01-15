#include <iostream>
#include <time.h>
using namespace std;

struct race_track
{
    float probability_victory_car;
    float probability_victory_motorbike;
};

class Car
{
private:
    int condition_technical;
    int condition_rider;

public:
    Car(int technical, int rider)
    {
        condition_technical = technical;
        condition_rider = rider;
    }

    float probability_of_winning()
    {
        return  condition_technical / 200.0f + condition_rider / 200.0f;
    }
};

class Motorbike
{
private:

    int condition_technical;
    int condition_rider;

public:
    Motorbike(int technical, int rider)
    {
        condition_technical = technical;
        condition_rider = rider;
    }

    float probability_fall()
    {
        return  rand() % (100 - condition_rider + 1) / 100.0;
    }
    float probability_of_winning()
    {
        return  condition_technical / 50.0f + condition_rider / 50.0f - probability_fall();
    }
};

int race(Car& car, Motorbike bike, race_track track)
{
    int win_a = 0;
    int win_b = 0;

    if (rand() % 101 < car.probability_of_winning())   win_a = 1;
    if (rand() % 101 < bike.probability_of_winning())   win_b = 1;

    if (win_a == 1 && win_b == 1 || win_a == 0 && win_b == 0)
    {
        int a = 0;
        int b = 0;

        for (; ; )
        {
            if (rand() % 101 < track.probability_victory_car) a = 1;
            if (rand() % 101 < track.probability_victory_motorbike) b = 1;

            if (a == 1 && b != 1) return 1;
            if (a == 0 && b != 1) return 2;
        }
    }
    else
    {
        if (win_a == 1) return 1;
        else            return 2;
    }
}

int main()
{
    srand(time(0));

    Car        car(100, 50);
    Motorbike  motobike(50, 100);
    race_track track = { 50, 20 };

    switch (race(car, motobike, track))
    {
    case 1: cout << "win - Car" << endl; break;
    case 2: cout << "win - Motubike" << endl; break;
    };
}

