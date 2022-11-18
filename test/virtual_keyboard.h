//#ifndef KEYBOARD_H
//#define KEYBOARD_H
//
//#include <QWidget>
//class QStackedWidget;
//class QLabel;
//class QLineEdit;
//class QPushButton;
//class QComboBox;
//
//// ��ť�ı߳�,�����ܳ���=14*BTN_SIZE,�����ܿ��=3*BTN_SIZE
//#define BTN_SIZE    40
//
//class keyBoard : public QWidget
//{
//    Q_OBJECT
//public:
//    explicit keyBoard(QWidget *parent = 0);
//    ~keyBoard();
//
//protected:
//    void mouseMoveEvent(QMouseEvent *e);
//    void mousePressEvent(QMouseEvent *e);
//    void mouseReleaseEvent(QMouseEvent *);
//
//private slots:
//    void focusChanged(QWidget *, QWidget *nowWidget);
//    void slotBtnClicked();         // ��������
//
//private:
//    int deskWidth;                  //������
//    int deskHeight;                 //����߶�
//    int frmWidth;                   //������
//    int frmHeight;                  //����߶�
//
//    QPoint mousePoint;              //����϶��Զ��������ʱ������
//    bool mousePressed;              //����Ƿ���
//    void InitWindow();              //��ʼ���ޱ߿���
//    void InitForm();                //��ʼ����������
//
//    QLineEdit *currentLineEdit;     //��ǰ������ı���
//    QString currentType;            //��ǰ���뷨����
//    void changeType(QString type);  //�ı����뷨����
//    void changeLetter(bool isUpper);//�ı���ĸ��Сд
//    void changeStyle(int style);    //�л���ʽ����
//    void setStyle(QString topColor, QString bottomColor, QString borderColor, QString textColor);
//
//    int currentStyle;
//
//    QStackedWidget *keyWindow;      // ���̴���,���Է�ҳ��ʾ
//    QWidget *letterWindow;          // ��ĸ����
//    QWidget *signWindow;            // ��ĸ����
//    QLabel *infoLabel;              // ��ʾ������Ϣ
//
//    QPushButton *closeBtn;
//    QPushButton *delBtn;
//    QPushButton *typeBtn;
//    QPushButton *styleBtn;
//
//    QPushButton *btn0;
//    ...
//        QPushButton *btn9;
//
//    QPushButton *btnA;
//    ...
//        QPushButton *btnZ;
//
//    QPushButton *btnSign0;
//    ...
//        QPushButton *btnSign12;
//};
//
//#endif // KEYBOARD_H