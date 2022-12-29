#include "saveurls.h"
#include <QStringList>
#include<QSettings>


SaveUrls::SaveUrls()
{
    qDebug("SaveUrl");

}

void SaveUrls::save(QStringList urlList)
{
    QSettings settings("rssFeeds.ini", QSettings::IniFormat);
    settings.beginWriteArray("ressFeeds");
    settings.remove("");
    for(int i =0; i < urlList.count(); i++){
        settings.setArrayIndex(i);
        settings.setValue("url", urlList.at(i));
    }
    settings.endArray();
}

QStringList SaveUrls::load()
{
    QStringList urlList;
    QSettings settings("ressFeeds.ini",QSettings::IniFormat);
    int size = settings.beginReadArray("ressFeeds");
    for(int i =0; i<size; i++){
        settings.setArrayIndex(i);
        QString url = settings.value("url").toString();
        urlList.append(url);
    }
    settings.endArray();

    return urlList;
}
