#include <qvariant.h>

void QVariantToFloat()
{
    QVariantMap m;
    float f = 1.23;
    m.insert("num", 1.23);
    bool ok;
    float f2 = m.value("num").toFloat(&ok);


    QVariantMap m2;
    
    m2["num"] = f2;
    bool ok2;
    float f3 = m2["num"].toFloat(&ok2);


    QVariantMap m3;
    QVariant var;
    var.setValue(f2);
    m3["num"] = var;
    bool ok3;
    float f4 = m3["num"].value<float>();
}