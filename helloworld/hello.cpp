#include <QTextStream>

int main(int argc, char* argv[])
{
    QTextStream(stdout) << "hello world!" << Qt::endl;
    return 0;
}
