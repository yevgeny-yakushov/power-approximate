#pragma once

#include <QObject>
#include <QVector>
#include <QtMath>

#include <iostream>

class CApproximation : public QObject
{
	Q_OBJECT

public:
		CApproximation(QVector<QPair<double, double>> data, uint power, QObject *parent = 0);

public:
	double		approximate	(double value);

private:
	void		calcCoeff	();

private:
	QVector<QPair<double, double>>	m_vData;
	uint							m_uPower;
	uint							m_uN;

	QVector<double>					m_vAprA;
	QVector<double>					m_vAprB;
	QVector<QVector<double>>		m_vvAprSums; 
};
