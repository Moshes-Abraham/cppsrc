#include <QApplication>
#include <QLabel>
#include <QtDebug>

int main(int argc, char* argv[]) {

	QApplication a(argc, argv);

	QLabel label("hello");
	label.show();

	qDebug() << "hell mq";

	return a.exec();
}
