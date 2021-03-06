#include "Exercise.h"

ExerciseA::ExerciseA(int topicIndex, ExerciseType exerciseType/* = ExerciseType::ExerciseTypeA*/
    , QObject* parent/*= Q_NULLPTR*/)
    : Exercise(exerciseType, topicIndex, parent)
    , m_topicTips("true or false") {}

void ExerciseA::showTopicATips(bool show)
{
    if (show)
        qDebug() << m_topicTips;
    else
        qDebug() << "no tips";
}

void ExerciseA::handleExercise()
{
    qDebug() << "handle exercise A";
    emit handleFinished();
}

void ExerciseB::setTopicBAnswer(const QString& answer)
{
    m_answer = answer;
}

void ExerciseB::handleExercise()
{
    qDebug() << "handle exercise B";
    emit handleFinished();
}