#pragma once

#include <QObject>
#include <QVector>
#include <QtMath>
#include <time.h>
#include <functional>

class CGraphicWindow;
class CApproximation;

class CCreateApproximate : public QObject
{
	Q_OBJECT

public:
		CCreateApproximate(
			std::function<double(double x)> fn,
			double		left,
			double		right,
			uint		countPairData,
			uint		power,
			bool		rand	= false,
			double		min		= -0.1,
			double		max		= 0.1,
			QObject	   *parent	= 0
		);
		~CCreateApproximate();

public:

	void							delta			();

protected:
	void							createData		(bool rand = false, double min = -0.1, double max = 0.1);
	void							calcApproximate	();

private:
	double							random			(double min, double max);

private:
	CGraphicWindow*					m_plotGraphic;
	CApproximation*					m_appr;

	std::function<double(double x)>	m_fn;

	QVector<QPair<double, double>>	m_vvdFuncValues;
	QVector<QPair<double, double>>	m_vvdApproxValues;

	double							m_dLeftPoint;
	double							m_dRightPoint;

	uint							m_uCountPairData;
	uint							m_uPower;
};
