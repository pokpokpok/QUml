#include "usecase_diagram/usecasemodel.h"

#include <QtCore/QXmlStreamWriter>
#include <QtCore/QXmlStreamReader>
#include <QtCore/QFile>

UseCaseModel::UseCaseModel(QObject *parent) :
    AbstractModel(parent)
{

}

UseCaseModel::~UseCaseModel()
{

}

void UseCaseModel::saveModel(const QString &fileName, const QList<AbstractItem*> itemsList)
{
    QXmlStreamWriter writer;
    QFile file(fileName);
    if(!file.open(QFile::WriteOnly | QFile::Text))
        return;
    writer.setDevice(&file);
    writer.setAutoFormatting(true);
    writer.writeStartDocument();
    writer.writeStartElement("UseCaseDiagram");

    for(int i(0); i < itemsList.size(); i++)
    {
        QString temp;
        writer.writeStartElement(itemsList[i]->getItemType());
        writer.writeAttribute("name", itemsList[i]->getItemName());
        writer.writeAttribute("x", temp.setNum(itemsList[i]->pos().x()));
        writer.writeAttribute("y", temp.setNum(itemsList[i]->pos().y()));
        writer.writeEndElement();
    }

    //add save relations

    writer.writeEndDocument();
    file.close();
}

void UseCaseModel::loadModel(const QString &fileName)
{
    QXmlStreamReader reader;
    QFile file(fileName);
    if(!file.open(QFile::ReadOnly | QFile::Text))
        return;
    reader.setDevice(&file);

    while(1)
    {
        reader.readNextStartElement();
        if (reader.isStartElement())
        {
            if(reader.name() == "ACTOR" || reader.name() == "USECASE")
            {
                emit addNewItem(reader.name().toString(),
                                reader.attributes()[0].value().toString(),
                                QPointF(reader.attributes()[1].value().toString().toDouble(),
                                        reader.attributes()[2].value().toString().toDouble()));
            }
            else if(reader.name() == "RELATION")
            {
                //add load relations
            }
        }
        else if(reader.name() == "UseCaseDiagram")
                break;
    }

    file.close();
}
