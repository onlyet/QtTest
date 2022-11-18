#include "common.h"
#include <qmediaplayer.h>
#include <qapplication.h>
#include <QObject>
#include <qdebug.h>
#include <QMediaPlaylist>
#include <QTimer>

void playAudioDemo()
{
	QString path = QString("%1/sound/ready.mp3").arg(QApplication::applicationDirPath());
	QMediaPlayer* audio = new QMediaPlayer();
	QObject::connect(audio, &QMediaPlayer::stateChanged, [](QMediaPlayer::State newState) {
		qDebug() << "stateChanged: " << newState;
	});
    QObject::connect(audio, &QMediaPlayer::mediaStatusChanged, [](QMediaPlayer::MediaStatus newState) {
        qDebug() << "mediaStatusChanged: " << newState;
    });
    QObject::connect(audio, QOverload<QMediaPlayer::Error>::of(&QMediaPlayer::error), [](QMediaPlayer::Error newState) {
        qDebug() << "error: " << newState;
    });

    //audio->setMedia(QUrl::fromLocalFile(/*"sound/ready.mp3"*/path));
    //audio->setMedia(QUrl("qrc:/sound/alcohol_lamp.mp3"));
    //audio->setMedia(QUrl("qrc:/sound/alcohol_lamp.mp3"));
	//audio->play();
    //audio->setMedia(QUrl(":/sound/evaporating_dish.mp3"));


    QMediaPlaylist *playList = new QMediaPlaylist;
    playList->addMedia(QUrl("qrc:/sound/alcohol_lamp.mp3"));
    audio->setPlaylist(playList);
    audio->play();
    //playList->addMedia(QUrl("qrc:/sound/evaporating_dish.mp3"));
    //playList->addMedia(QUrl("qrc:/sound/warn.mp3"));
    //playList->setCurrentIndex(2);

    QTimer::singleShot(10 * 1000, [playList, audio]() {
        playList->addMedia(QUrl("qrc:/sound/evaporating_dish.mp3"));
        audio->play();
    });

}