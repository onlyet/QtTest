#pragma once
#include <QObject>
#include <QDebug>

enum ExerciseType {
    ExerciseTypeNone,
    ExerciseTypeA,
    ExerciseTypeB,
    ExerciseTypeC,
};

class Exercise : public QObject
{
    Q_OBJECT
public:
    Exercise(ExerciseType exerciseType, int topicIndex, QObject* parent = Q_NULLPTR)
        : QObject(parent), m_exerciseType(exerciseType), m_topicIndex(topicIndex) {}

    ExerciseType type() {
        return m_exerciseType;
    }

    int topicIndex() {
        return m_topicIndex;
    }

    public slots :
        virtual void handleExercise() = 0;

protected:
    ExerciseType    m_exerciseType;
    int             m_topicIndex;   //题号
};

class ExerciseA : public Exercise
{
    Q_OBJECT
public:
    ExerciseA(int topicIndex, ExerciseType exerciseType = ExerciseType::ExerciseTypeA, QObject* parent = Q_NULLPTR)
        : Exercise(exerciseType, topicIndex, parent), m_topicTips("true or false") {}

signals:
    void handleFinished();

    public slots :
    void showTopicATips(bool);

public:
    //在基类已经声明为槽，所以不必再声明
    void handleExercise() override;

private:
    QString m_topicTips;
};

class ExerciseB : public Exercise
{
    Q_OBJECT
public:
    ExerciseB(int topicIndex, ExerciseType exerciseType = ExerciseType::ExerciseTypeB, QObject* parent = Q_NULLPTR)
        : Exercise(exerciseType, topicIndex, parent) {}

signals:
    void handleFinished();

    public slots :
    void setTopicBAnswer(const QString& answer);

public:
    //在基类已经声明为槽，所以不必再声明
    void handleExercise() override;

private:
    QString m_answer;
};