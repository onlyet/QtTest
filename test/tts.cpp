#include "common.h"
#include "CBaiduSpeech.h"
#include "text_to_speech.h"

#include <QDebug>

void tts()
{
	CBaiduSpeech bs;
	QString errStr;
	QString auidoPath = bs.TTS(QStringLiteral("实验台上具有非本次考试相关的实验物品"), &errStr);
	qDebug() << "auidoPath: " << auidoPath;
	qDebug() << "errStr: " << errStr;
}


void kdxfTts()
{

}