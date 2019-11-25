#include "autoradio.h"
//sudo apt-get install qtmultimedia5-dev libqt5multimediawidgets5 libqt5multimedia5-plugins libqt5multimedia5

AutoRadio::AutoRadio()
{
    NomStations<<"Chérie FM";
    stations<<"http://cdn.nrjaudio.fm/audio1/fr/30201/mp3_128.mp3?origine=playerweb";
    NomStations<<"Europe 1";
    stations<<"http://mp3lg3.scdn.arkena.com/10489/europe1.mp3";
    NomStations<<"France Bleu Alsace";
    stations<<"http://direct.francebleu.fr/live/fbalsace-midfi.mp3";
    NomStations<<"France Culture";
    stations<<"http://direct.franceculture.fr/live/franceculture-lofi.mp3";
    NomStations<<"France Info";
    stations<<"http://direct.franceinfo.fr/live/franceinfo-lofi.mp3";
    NomStations<<"France Inter";
    stations<<"http://direct.franceinter.fr/live/franceinter-midfi.mp3";
    NomStations<<"France Musique";
    stations<<"http://direct.francemusique.fr/live/francemusique-lofi.mp3";
    NomStations<<"Fréquence Jazz";
    stations<<"http://broadcast.infomaniak.ch/frequencejazz-high.mp3";
    NomStations<<"Fun Radio";
    stations<<"http://streaming.radio.funradio.fr:80/fun-1-44-128";
    NomStations<<"Nostalgie";
    stations<<"http://cdn.nrjaudio.fm/audio1/fr/30601/mp3_128.mp3?origine=playerweb";
    NomStations<<"NRJ";
    stations<<"http://cdn.nrjaudio.fm/audio1/fr/30001/mp3_128.mp3?origine=playernrj";
    NomStations<<"RFM";
    stations<<"http://rfm-live-mp3-128.scdn.arkena.com/rfm.mp3";
    NomStations<<"Rire et Chansons";
    stations<<"http://cdn.nrjaudio.fm/audio1/fr/30401/mp3_128.mp3?origine=playerweb";
    NomStations<<"RMC";
    stations<<"http://chai5she.cdn.dvmr.fr/rmcinfo";
    NomStations<<"RTL";
    stations<<"http://streaming.radio.rtl.fr/rtl-1-44-128";
    NomStations<<"Skyrock";
    stations<<"http://icecast.skyrock.net/s/natio_mp3_128k";
}

QString AutoRadio::START()
{
    this->setMedia(QUrl(stations[current_station]));
    this->play();
    return NomStations[current_station];
}

QString AutoRadio::NEXT()
{
    this->stop();
    if (current_station==stations.length()-1){
        current_station=0;
    }
    else {
        current_station++;
    }
    this->setMedia(QUrl(stations[current_station]));
    this->play();
    return NomStations[current_station];
}

QString AutoRadio::PREVIOUS()
{
    this->stop();
    if (current_station==0){
        current_station=stations.length()-1;
    }
    else {
        current_station++;
    }
    this->setMedia(QUrl(stations[current_station]));
    this->play();
    return NomStations[current_station];
}
