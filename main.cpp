#include <QApplication>
#include "createApproximate.h"

#define LEFT_POINT_RANGE    1.0
#define RIGHT_POINT_RANGE   6.0

double func1(double x) { return qLn(x); };
double func2(double x) { return qLn(x) + 0.05 * qSin(x * 10.0); };

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

	//CCreateApproximate appr0(func1, LEFT_POINT_RANGE, RIGHT_POINT_RANGE, 10,  1);
	//CCreateApproximate appr1(func1, LEFT_POINT_RANGE, RIGHT_POINT_RANGE, 20,  2);
	//CCreateApproximate appr2(func1, LEFT_POINT_RANGE, RIGHT_POINT_RANGE, 30,  3);
	//CCreateApproximate appr3(func1, LEFT_POINT_RANGE, RIGHT_POINT_RANGE, 50,  4);
	//CCreateApproximate appr4(func1, LEFT_POINT_RANGE, RIGHT_POINT_RANGE, 100, 5);

	CCreateApproximate appr5(func2, LEFT_POINT_RANGE, RIGHT_POINT_RANGE, 10,  1);
	CCreateApproximate appr6(func2, LEFT_POINT_RANGE, RIGHT_POINT_RANGE, 20,  2);
	CCreateApproximate appr7(func2, LEFT_POINT_RANGE, RIGHT_POINT_RANGE, 30,  3);
	CCreateApproximate appr8(func2, LEFT_POINT_RANGE, RIGHT_POINT_RANGE, 50,  4);
	CCreateApproximate appr9(func2, LEFT_POINT_RANGE, RIGHT_POINT_RANGE, 100, 5);

    return a.exec();
}
