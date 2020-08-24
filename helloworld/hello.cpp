#include <QTextStream>


QTextStream output(stdout);

QTextStream& operator<<(QTextStream& out, const QStringList& sl)
{
    out << '[';
    bool first = true;
    for (const auto& e: sl) {
        if (!first) {
            out << ", ";
        }
        out << '"' << e << '"';
        first = false;
    }
    out << "] ";
    return out;
}

void test1()
{
    QString s1 = "hello world";
    output << "s1: " << s1 << Qt::endl;
    output << "s1.size: " << s1.size() << Qt::endl;
    QStringList tokens = s1.split(" ");
    output << "tokens: " << tokens << Qt::endl;
}


int main(int argc, char* argv[])
{
    output << "hello world!" << Qt::endl;
    test1();
    return 0;
}
