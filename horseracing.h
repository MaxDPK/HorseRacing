#ifndef HORSERACING_H
#define HORSERACING_H

#include <vector>
#include "horse.h"

class HorseRacing {
public:
    HorseRacing();
    ~HorseRacing();

    void SimulateRace();
    void UpdateNewSpeed();
    void RunRace();
    bool isRaceOver();

    int getNumHorse();
    int getFinishLine();
    std::vector<Horse> getHorses();

private:
    static const int NUM_HORSES;
    static const int FinishLinePosition;
    bool raceOver;

    std::vector<Horse> horses;
};

#endif // HORSE_RACING_H


