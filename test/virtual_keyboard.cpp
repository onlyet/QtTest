//void keyBoard::InitWindow()
//{
//    this->setProperty("Form", true);
//    this->setWindowFlags(Qt::Tool | Qt::WindowStaysOnTopHint | Qt::FramelessWindowHint);
//    this->setFixedSize(14 * BTN_SIZE, 3 * BTN_SIZE);
//    this->setFocusPolicy(Qt::NoFocus);
//
//    keyWindow = new QStackedWidget(this);
//    keyWindow->setFixedSize(13 * BTN_SIZE, 2 * BTN_SIZE);
//    letterWindow = new QWidget;
//    signWindow = new QWidget;
//
//    // ��ӹ��ܰ�ť
//    closeBtn = new QPushButton(this);
//    closeBtn->setObjectName("closeBtn");
//    closeBtn->setProperty("function", true);
//    closeBtn->setText(tr("X"));
//    closeBtn->setFixedSize(BTN_SIZE, BTN_SIZE);
//
//    // ɾ��һ���ַ�
//    delBtn = new QPushButton(this);
//    delBtn->setObjectName("delBtn");
//    delBtn->setProperty("function", true);
//    delBtn->setText(tr("D"));
//    delBtn->setFixedSize(BTN_SIZE, BTN_SIZE);
//
//    // �ı��䷨����:��д,Сд,�ַ�
//    typeBtn = new QPushButton(this);
//    typeBtn->setObjectName("typeBtn");
//    typeBtn->setProperty("function", true);
//    typeBtn->setText(tr("С"));
//    typeBtn->setFixedSize(BTN_SIZE, BTN_SIZE);
//
//    // ����
//    styleBtn = new QPushButton(this);
//    styleBtn->setObjectName("styleBtn");
//    styleBtn->setProperty("function", true);
//    styleBtn->setText(tr("style"));
//    styleBtn->setFixedSize(BTN_SIZE, BTN_SIZE);
//
//    // ������ּ���
//    btn1 = new QPushButton(this);
//    btn1->setText(tr("1"));
//    btn1->setProperty("num", true);
//    btn1->setFixedSize(BTN_SIZE, BTN_SIZE);
//
//    ������������
//
//        layout->addWidget(delBtn, 0, 11, 1, 1);
//    layout->addWidget(closeBtn, 0, 12, 1, 1);
//    layout->addWidget(typeBtn, 1, 13, 1, 1);
//    layout->addWidget(styleBtn, 2, 13, 1, 1);
//    layout->addWidget(keyWindow, 1, 0, 2, 13);
//    layout->setSpacing(0);
//    layout->setContentsMargins(0, 0, 0, 0);
//    this->setLayout(layout);
//}