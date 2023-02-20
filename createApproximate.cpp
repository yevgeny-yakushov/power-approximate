#include "createApproximate.h"
#include "approximation.h"
#include "graphicWindow.h"
#include <iomanip>

CCreateApproximate::CCreateApproximate(
	std::function<double(double x)> fn,
	double		left,
	double		right,
	uint		countPairData,
	uint		power,
	bool		rand,
	double		min,
	double		max,
	QObject	   *parent
)
	:	QObject(parent),
		m_dLeftPoint(left),
		m_dRightPoint(right),
		m_uCountPairData(countPairData),
		m_uPower(power)
{
	m_fn = fn;
	m_plotGraphic = new CGraphicWindow(power);
	m_plotGraphic->show();
	createData(rand, min, max);
	m_appr = new CApproximation(m_vvdFuncValues, power);

	calcApproximate();

	m_plotGraphic->viewGraphic(m_vvdFuncValues,		QColor(Qt::blue)			);
	m_plotGraphic->viewGraphic(m_vvdApproxValues,	QColor(Qt::magenta),	true);

	delta();
}

CCreateApproximate::~CCreateApproximate()
{
	delete m_plotGraphic;	m_plotGraphic	= nullptr;
	delete m_appr;			m_appr			= nullptr;
}

void CCreateApproximate::createData(bool rand, double min, double max)
{
	for (double x = m_dLeftPoint; x <= m_dRightPoint; x += (m_dRightPoint - m_dLeftPoint) / m_uCountPairData)
	{
		m_vvdFuncValues.push_back({x, m_fn(x) + (rand ? random(min, max) : 0)});
	}
}

double CCreateApproximate::random(double min, double max)
{
	srand((unsigned int)time(0));
	return (double)(rand()) / RAND_MAX * (max - min) + min;
}

void CCreateApproximate::calcApproximate()
{
	for (auto& value : m_vvdFuncValues)
	{
		m_vvdApproxValues.push_back({value.first, m_appr->approximate(value.first)});
	}
}

void CCreateApproximate::delta()
{
	if (m_vvdFuncValues.isEmpty() || m_vvdApproxValues.isEmpty()) return;

	std::cout << "Delta of power " << m_uPower << std::endl;

	for (int i = 0; i < m_vvdFuncValues.size(); i++)
	{
		std::cout 
			<< std::setw(10) << std::fixed << std::setprecision(2) << "x = " << m_vvdFuncValues[i].first
			<< std::setw(10) << std::fixed << std::setprecision(5) << "d = " << qAbs(m_vvdFuncValues[i].second - m_vvdApproxValues[i].second)
			<< std::endl;
	}
}