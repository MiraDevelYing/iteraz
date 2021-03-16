#include <iostream>
#include <windows.h> //Шрифт консоли - Lucida Console

using namespace std;

double coeff[10][10];
double Dinv[10][10];
double approx[10][1];
double R[10][10];
double C[10][1];
double b[10][1];
double temp[10][1];

int N, k;

void multiply(double A[][10], double B[][1]) //Функция перемножения матриц
{
    for (int p = 0; p < N; p++)
    {
        C[p][0] = 0;
        for (k = 0; k < N; k++)
        {
            C[p][0] = C[p][0] + A[p][k] * B[k][0];
        }
    }
}
int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    cout << "Введите размерность матрицы:" << endl;
    cout << "N = ";
    cin >> N;
    cout << "Введите матрицу коэффициентов: " << endl;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> coeff[i][j];
        }
    }
    for (int i = 0; i < N; i++)
    {
        approx[i][0] = 0; //Обнуляем начальное приближение...
    }
    cout << "Введите вектор свободных членов: " << endl;
    for (int i = 0; i < N; i++)
    {
        cin >> b[i][0];
    }
    for (int i = 0; i < N; i++)

    {
        for (int j = 0; j < N; j++)
        {
            if (i == j)
                Dinv[i][j] = 1 / coeff[i][j];
            else
                Dinv[i][j] = 0;
        }
    }
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (i == j)
                R[i][j] = 0;
            else if (i != j)
                R[i][j] = coeff[i][j];
        }
    }
    int iter;
    cout << "Введите число итераций:" << endl;
    cin >> iter;
    int x = 1;
    int y;
    while (x <= iter)
    {
        multiply(R, approx);
        for (int i = 0; i < N; i++)
        {
            temp[i][0] = b[i][0] - C[i][0];
        }
        multiply(Dinv, temp);
        for (int y = 0; y < N; y++)
        {
            approx[y][0] = C[y][0];
        }
        cout << "Итерация #" << x << ": " << endl;
        cout.precision(3);
        for (int i = 0; i < N; i++)
        {
            cout << fixed << "x" << i + 1 << " = " << approx[i][0] << endl; //Выводим корни
        }
        x++;
    }
    system("pause");
    return 0;
}