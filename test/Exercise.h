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
    int             m_topicIndex;   //���
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
    //�ڻ����Ѿ�����Ϊ�ۣ����Բ���������
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
    //�ڻ����Ѿ�����Ϊ�ۣ����Բ���������
    void handleExercise() override;

private:
    QString m_answer;
};