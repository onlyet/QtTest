#include "common.h"
#include "CBaiduSpeech.h"
#include "text_to_speech.h"

#include <QDebug>

void tts()
{
	CBaiduSpeech bs;
	QString errStr;
	QString auidoPath = bs.TTS(QStringLiteral("ʵ��̨�Ͼ��зǱ��ο�����ص�ʵ����Ʒ"), &errStr);
	qDebug() << "auidoPath: " << auidoPath;
	qDebug() << "errStr: " << errStr;
}


void kdxfTts()
{

}