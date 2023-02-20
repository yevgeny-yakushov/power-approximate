# Степенная аппроксимация qt/c++

Позволяет легко произвести степенную аппроксимацию функции с консольным выводом расчетов, а также графическим отображением исходной функции и аппроксимирующей.

Пример:

```cpp
    // Устанавливаем границы
    #define LEFT_POINT_RANGE    1.0
    #define RIGHT_POINT_RANGE   6.0
    
    // Определяем исходную функцию
    double func1(double x) { return qLn(x) + 0.05 * qSin(x * 10.0); };
    
    int main(int argc, char *argv[])
    {
        QApplication a(argc, argv);
    
    	CCreateApproximate appr0(func1, LEFT_POINT_RANGE, RIGHT_POINT_RANGE, 10,  1);
    	CCreateApproximate appr1(func1, LEFT_POINT_RANGE, RIGHT_POINT_RANGE, 20,  2);
    	CCreateApproximate appr2(func1, LEFT_POINT_RANGE, RIGHT_POINT_RANGE, 30,  3);
    	CCreateApproximate appr3(func1, LEFT_POINT_RANGE, RIGHT_POINT_RANGE, 50,  4);
    	CCreateApproximate appr4(func1, LEFT_POINT_RANGE, RIGHT_POINT_RANGE, 100, 5);
    
        return a.exec();
    }
```

Также есть возможность добавить некотрые помехи на входные данные

```cpp
    // С генерированием помех (добавит небольшой разброс по Oy)
	CCreateApproximate appr0(func1, LEFT_POINT_RANGE, RIGHT_POINT_RANGE, 10,  1, true, -0.5, 0.5);
```

# Вывод

Все расчеты будут выведены в консоль, пример:

![Пример консольного вывода](https://github.com/yevgeny-yakushov/power-approximate/raw/main/Output/Console.png)

Пример графиков:

![График аппроксимации 1 степени](https://github.com/yevgeny-yakushov/power-approximate/raw/main/Output/approx-1-power.PNG)

![График аппроксимации 5 степени](https://github.com/yevgeny-yakushov/power-approximate/raw/main/Output/approx-5-power.PNG)