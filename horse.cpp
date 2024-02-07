#include "horse.h"

Horse::Horse(int topSpeed, const QString& imagePath)
    : position(0), speed(0), topSpeed(topSpeed), finished(false), imagePath(imagePath), label(nullptr) {
}

Horse::~Horse() {
    delete label; // Clean up QLabel object
}

void Horse::UpdatePosition() {
    position += speed;
}

void Horse::UpdateTopSpeed(){
    topSpeed = rand() % 20 + 1;
}

void Horse::UpdateSpeed() {
    speed = rand() % topSpeed + 1;
}

int Horse::GetPosition() const {
    return position;
}

void Horse::SetPosition(int x) {
    position = x;
}

QString Horse::GetImagePath() const {
    return imagePath;
}

void Horse::SetLabel(QLabel* lbl) {
    label = lbl;
}

QLabel* Horse::GetLabel() const {
    return label;
}

bool Horse::GetFinished(){
    return finished;
}

void Horse::SetFinished(){
    finished = true;
}
