#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QEventLoop>
#include <QCoreApplication>
#include <QTimer>


void test()
{
    QNetworkAccessManager qnam;
    QNetworkRequest request;
    QEventLoop loop;

    QObject::connect(&qnam, &QNetworkAccessManager::finished,
        [&](QNetworkReply* reply) {
            if (reply->error()) {
                qDebug() << "Got error:" << Qt::endl;
                qDebug() << reply->errorString() << Qt::endl;
                loop.exit();
                return;
            }
            qDebug() << "Got reply:" << Qt::endl;
            QString result = reply->readAll();
            qInfo() << result << Qt::endl;
            loop.exit();
        });

    request.setUrl(QUrl("http://www.google.com/"));
    qDebug() << "Send request" << Qt::endl; 
    qnam.get(request);

    loop.exec();
}

int main(int argc, char* argv[])
{
    // Need to create QCoreApplication for event loop.
    QCoreApplication app(argc, argv);
    test();
    return 0;
}
