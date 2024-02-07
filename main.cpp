#include <QApplication>
#include <QLabel>
#include <QTimer>
#include <QVBoxLayout>
#include "horseracing.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    // Create HorseRacing object
    HorseRacing horseRace;

    // Run the race
    horseRace.RunRace();

    return a.exec();
}
