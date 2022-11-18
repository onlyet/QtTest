#include <QTableWidget>
#include <QTableWidgetItem>

int QTableWidgetTest()
{
    QTableWidget *tableWidget = new QTableWidget(10, 5); // ������һ��QTableWidget�Ķ��󣬲�������Ϊ10�У�5��
    //    Ҳ��������ķ�������QTableWidget����
    //    QTableWidget *tableWidget = new QTableWidget;
    //    tableWidget->setRowCount(10);     //��������Ϊ10
    //    tableWidget->setColumnCount(5);   //��������Ϊ5
    tableWidget->setWindowTitle("QTableWidget & Item");
    tableWidget->resize(350, 200);  //���ñ��
    QStringList header;
    header << "Month" << "Description";
    tableWidget->setHorizontalHeaderLabels(header);
    tableWidget->setItem(0, 0, new QTableWidgetItem("Jan"));
    tableWidget->setItem(1, 0, new QTableWidgetItem("Feb"));
    tableWidget->setItem(2, 0, new QTableWidgetItem("Mar"));

    tableWidget->setItem(0, 1, new QTableWidgetItem(QIcon("images/IED.png"), "Jan's month"));
    tableWidget->setItem(1, 1, new QTableWidgetItem(QIcon("images/IED.png"), "Feb's month"));
    tableWidget->setItem(2, 1, new QTableWidgetItem(QIcon("images/IED.png"), "Mar's month"));
    tableWidget->show();
    return 0;
}