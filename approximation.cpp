#include "approximation.h"

CApproximation::CApproximation(QVector<QPair<double, double>> data, uint power, QObject *parent)
	: QObject(parent)
{
	m_vData		= data;
	m_uPower	= power;
	m_uN		= data.size();

	m_vAprA = QVector<double>(power + 1, {0});
	m_vAprB = QVector<double>(power + 1, {0});

	m_vvAprSums.resize(power + 1); m_vvAprSums.fill(QVector<double>(power + 1, {0}));

	calcCoeff();
}

void CApproximation::calcCoeff()
{
	for (int i = 0; i < m_uPower + 1; i++)
	{
		for (int j = 0; j < m_uPower + 1; j++)
		{
			for (int N = 0; N < m_uN; N++)
			{
				m_vvAprSums[i][j] += qPow(m_vData[N].first, i + j);
			}
		}
	}

	for (int i = 0; i < m_uPower + 1; i++)
	{
		for (int N = 0; N < m_uN; N++)
		{
			m_vAprB[i] += qPow(m_vData[N].first, i) * m_vData[N].second;
		}
	}

	double tmp = 0;
	for (int i = 0; i < m_uPower + 1; i++)
	{
		if (m_vvAprSums[i][i] == 0)
		{
			for (int j = 0; j < m_uPower + 1; j++)
			{
				if (i == j) continue;
				if (m_vvAprSums[j][i] != 0 && m_vvAprSums[i][j] != 0)
				{
					for (int N = 0; N < m_uPower + 1; N++)
					{
						tmp = m_vvAprSums[j][N];
						m_vvAprSums[j][N] = m_vvAprSums[i][N];
						m_vvAprSums[i][N] = tmp;
					}
					tmp = m_vAprB[j];
					m_vAprB[j] = m_vAprB[i];
					m_vAprB[i] = tmp;
					break;
				}
			}
		}
	}

	for (int N = 0; N < m_uPower + 1; N++)
	{
		for (int i = N + 1; i < m_uPower + 1; i++)
		{
			double M = m_vvAprSums[i][N] / m_vvAprSums[N][N];
			for (int j = N; j < m_uPower + 1; j++)
			{
				m_vvAprSums[i][j] -= M * m_vvAprSums[N][j];
			}
			m_vAprB[i] -= M * m_vAprB[N];
		}
	}

	for (int i = m_uPower; i >= 0; i--)
	{
		double s = 0;
		for (int j = i; j < m_uPower + 1; j++)
		{
			s += m_vvAprSums[i][j] * m_vAprA[j];
		}
		m_vAprA[i] = (m_vAprB[i] - s) / m_vvAprSums[i][i];
	}

	std::cout << "Approximation coefficients of power " << m_uPower << std::endl;
	for (auto& el : m_vAprA)
	{
		std::cout << el << "\t";
	}
	std::cout << std::endl << std::endl;
}

double CApproximation::approximate(double value)
{
	double result = m_vAprA[0];
	for (int i = 1; i < m_vAprA.size(); i++)
	{
		result += m_vAprA[i] * qPow(value, i);
	}

	return result;
}