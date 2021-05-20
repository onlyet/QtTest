#include "common.h"
#include <qmediaplayer.h>
#include <qapplication.h>
#include <QObject>
#include <qdebug.h>

void playAudioDemo()
{
	QString path = QString("%1/sound/ready.mp3").arg(QApplication::applicationDirPath());
	QMediaPlayer* audio = new QMediaPlayer();
	QObject::connect(audio, &QMediaPlayer::stateChanged, [](QMediaPlayer::State newState) {
		qDebug() << "state: " << newState;
	});
	audio->setMedia(QUrl::fromLocalFile(/*"sound/ready.mp3"*/path));
	audio->play();
}