#include <QWidget>
#include <QMetaProperty>
#include <QDebug>

void Property_Test()
{
    QWidget* object = new QWidget();
    const QMetaObject *metaobject = object->metaObject();
    int count = metaobject->propertyCount();
    for (int i = 0; i < count; ++i) 
    {
        QMetaProperty metaproperty = metaobject->property(i);
        const char *name = metaproperty.name();
        qDebug() << metaproperty.name() << ", " << metaproperty.typeName();
        //qDebug() << name << ": " << object->property(name);
        //QVariant value = object->property(name);
        ////qDebug() << value;
    }
}

