#ifndef HORSE_H
#define HORSE_H
#include <QLabel>
#include <QString>
#include <QPixmap>

class Horse {
public:
    Horse(int topSpeed, const QString& imagePath);
    ~Horse();

    void UpdatePosition();
    void UpdateSpeed();
    void UpdateTopSpeed();

    int GetPosition() const;
    void SetPosition(int x);

    QString GetImagePath() const; // Getter for image path

    void SetLabel(QLabel* label); // Setter for QLabel
    QLabel* GetLabel() const; // Getter for QLabel

    bool GetFinished();
    void SetFinished();

private:
    int position;
    int speed;
    int topSpeed;
    bool finished;
    QString imagePath; // Path to the horse's image
    QLabel* label; // Pointer to the QLabel
};

#endif // HORSE_H
