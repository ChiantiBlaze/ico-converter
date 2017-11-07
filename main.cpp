/**
 * @author	Chianti Blaze
 * @date	11/6/2017
 * @section	DESCRIPTION
 *
 * Simple PNG to ICO converting application
 *
 */

#include "ico-converter.h"
#include <QApplication>

int main(int argc, char *argv[])
{
	QApplication app(argc, argv);

	ICO_Converter window;

	window.setFixedSize(460,300);
	window.setWindowTitle("ICO Converter v1.0");
	window.show();

	return app.exec();
}