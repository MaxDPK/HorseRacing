#include "horseracing.h"
#include "horse.h"
#include <cstdlib>
#include <ctime>
#include <QApplication>
#include <QLabel>
#include <QTimer>
#include <QWidget>
#include <QVBoxLayout>
#include <QThread>

const int HorseRacing::NUM_HORSES = 5;
const int HorseRacing::FinishLinePosition = 1000;

HorseRacing::HorseRacing() {
    raceOver = false;
    // Seed random number generator
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    // Load horse images and initialize horses with initial speed, positions, and images
    for (int i = 0; i < NUM_HORSES; ++i) {
        QString imagePath = QString("C:/Users/Dell/Code/C++/ProjectC++/PIXELhorse.png").arg(i+1); // Provide the correct path to the horse image
        horses.push_back(Horse(rand() % 15 + 5, imagePath)); // Create horse with image path
    }

}

HorseRacing::~HorseRacing() {
    // Destructor logic here if needed
}


void HorseRacing::SimulateRace() {
    for (int i = 0; i < NUM_HORSES; ++i) {
        if (horses[i].GetFinished()){
            continue;
        }
        else{
            horses[i].UpdatePosition();
        }
    }
}

void HorseRacing::UpdateNewSpeed() {
    for (int i = 0; i < NUM_HORSES; ++i) {
        int chance = rand() % 4 + 1;
        // Generate a new random speed for each horse
        if(chance == 4){
            horses[i].UpdateTopSpeed();
        }
        horses[i].UpdateSpeed(); // Random speed between 1 and 5
    }
}

void HorseRacing::RunRace() {
    // Create a widget for the race
    QWidget* raceWidget = new QWidget();
    raceWidget->setWindowTitle("Horse Race");
    QVBoxLayout* layout = new QVBoxLayout();
    raceWidget->setLayout(layout);
    raceWidget->resize(1000, 1000);

    // Create QLabel objects for each horse and add them to the layout
    for (int i = 0; i < NUM_HORSES; ++i) {
        QLabel* horseLabel = new QLabel();
        horseLabel->setPixmap(QPixmap(horses[i].GetImagePath()));
        layout->addWidget(horseLabel);
        horses[i].SetLabel(horseLabel);
    }

    raceWidget->show();

    // Start the race animation loop
    while (!raceOver) {
        SimulateRace();
        UpdateNewSpeed();

        // Update position of each horse label
        for (int i = 0; i < NUM_HORSES; ++i) {
            if (horses[i].GetPosition() >= FinishLinePosition){
                horses[i].SetFinished();
            }
            horses[i].GetLabel()->move(horses[i].GetPosition(), i * 100); // Adjust vertical positioning as needed
        }

        // Check if every horse has crossed the finish line
        raceOver = true;
        for (int i = 0; i < NUM_HORSES; ++i) {
            if (horses[i].GetPosition() < FinishLinePosition) {
                raceOver = false;
                break;
            }
        }

        // Add a short delay for the animation
        QCoreApplication::processEvents();
        QThread::msleep(100);
    }
}


bool HorseRacing::isRaceOver() {
    if (raceOver){
        return true;
    }
    else{
        return false;
    }
}

int HorseRacing::getNumHorse(){
    return NUM_HORSES;
}
int HorseRacing::getFinishLine(){
    return FinishLinePosition;
}

std::vector<Horse> HorseRacing::getHorses(){
    return horses;
}
