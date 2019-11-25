#ifndef AUTORADIO_H
#define AUTORADIO_H


#include <QMediaPlayer>

class AutoRadio : public QMediaPlayer
{
public:
    AutoRadio();
    QStringList stations;
    QStringList NomStations;
    int current_station=0;
    QString START();
    QString NEXT();
    QString PREVIOUS();
};

#endif // AUTORADIO_H
