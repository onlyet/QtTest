#include "common.h"
#include <qmediaplayer.h>
#include <qapplication.h>

void playAudioDemo()
{
	QString path = QString("%1/sound/ready.mp3").arg(QApplication::applicationDirPath());
	QMediaPlayer* audio = new QMediaPlayer();
	audio->setMedia(QUrl::fromLocalFile(/*"sound/ready.mp3"*/path));
	audio->play();
}