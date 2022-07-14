#include <iostream>
#include <cmath>
#include <string>
#include <vector>
using namespace std;

vector<int> coeficients;

void ShowPolinom(vector<int> coef) {
    cout << "Полином: ";
    for (int i = coef.size() - 1; i >= 0; i--) {
        if ((coef[i] < 0) || (i == coef.size() - 1)) {
            if (coef[i] != 0 && coef[i] != 1) {
                if (i > 1) {
                    cout << coef[i] << "x^" << i;
                }
                else if (i == 1) {
                    cout << coef[i] << "x";
                }
                else if (i == 0) {
                    cout << coef[i] << endl;
                }
            }
            else if (coef[i] == 1) {
                if (i > 1) {
                    cout << "x^" << i;
                }
                else if (i == 1) {
                    cout << "x";
                }
                else if (i == 0) {
                    cout << endl;
                }
            }
        }
        else {
            if (coef[i] != 0 && coef[i] != 1) {
                if (i > 1) {
                    cout << "+" << coef[i] << "x^" << i;
                }
                else if (i == 1) {
                    cout << "+" << coef[i] << "x";
                }
                else if (i == 0) {
                    cout << "+" << coef[i] << endl;
                }
            }
            else if (coef[i] == 1) {
                if (i > 1) {
                    cout << "+" << "x^" << i;
                }
                else if (i == 1) {
                    cout << "+" << "x";
                }
                else if (i == 0) {
                    cout << endl;
                }
            }
        }
    }
    cout << endl;
}

float Polinom(vector<int> coef, float x) {

    float sum = 0;
    for (int i = 0; i < coef.size(); i++) {
        sum += pow(x, i) * coef[i];
    }
    return sum;
}


vector<int> Pohidna(vector<int> coef) {
    vector<int> pohidna;
    for (int i = 1; i < coef.size(); i++) {
        pohidna.push_back(i * coef[i]);
    }
    return pohidna;
}


int i = 0;
float BesectionMethod(vector<int> coef, float a, float b, float epsilon) {
    float c = (a + b) / 2;
    float fc = Polinom(coef, c);
    float fa = Polinom(coef, a);
    float fb = Polinom(coef, b);

    if (fa * fb < 0) {
        cout << "Итерация № " << ++i << endl;
        cout << "a: " << a << "\nb: " << b << "\nc: " << c << endl;

        if (abs(fc) > epsilon) {
            cout << "false\n";
            cout << "f(a)*f(c) = " << fa * fc << endl;
            if (fa * fc < 0) {
                BesectionMethod(coef, a, c, epsilon);
            }
            else if (fa * fc > 0) {
                BesectionMethod(coef, c, b, epsilon);
            }
        }
        else {
            cout << "true\n";
            cout << "Корень: " << c << endl;
            return c;
        }
    }
    else {
        cout << "Не сходится\n";
    }
}


float ChordMethod(vector<int> coef, float a, float b, float epsilon) {
    while (abs(Polinom(coef, b)) > epsilon)
    {
        a = b - ((b - a) * Polinom(coef, b)) / (Polinom(coef, b) - Polinom(coef, a));
        b = a - ((a - b) * Polinom(coef, a)) / (Polinom(coef, a) - Polinom(coef, b));
        cout << "Итерация № " << ++i << "\na:" << a << "\nb:" << b << endl;
    }
    cout << "Корень: " << b << endl;
    return b;
}

void NewtonMethod(vector<int> coef, float a, float b, float epsilon) {
    float x;
    float fa = Polinom(coef, a) * Polinom(Pohidna(Pohidna(coef)), a);
    float fb = Polinom(coef, b) * Polinom(Pohidna(Pohidna(coef)), b);
    if (Polinom(coef, a) * Polinom(Pohidna(Pohidna(coef)), a) > 0) {
        x = a;
    }
    else if (Polinom(coef, b) * Polinom(Pohidna(Pohidna(coef)), b) > 0) {
        x = b;
    }
    else {
        cout << "Не сходится\n";
        return;
    }
    int i = 0;
    while (abs(Polinom(coef, x)) > epsilon) {
        float x1 = x - Polinom(coef, x) / Polinom(Pohidna(coef), x);
        cout << "Итерация № " << ++i << endl;
        cout << "x1: " << x1 << endl;
        x = x1;
    }
    cout << "true\n";
    cout << "Корень: " << x << endl;
}

int main()
{
    setlocale(LC_ALL, "ru");
    int stepinPolinomy;
    cout << "Введите степень полинома: ";
    cin >> stepinPolinomy;
    cout << "Введите коэффициенты уравнения: ";
    for (int i = 0; i <= stepinPolinomy; i++) {
        int coef;
        cin >> coef;
        coeficients.insert(coeficients.begin() + 0, coef);
    }
    ShowPolinom(coeficients);

    float a, b, epsilon;
    cout << "Введите левую гранцу: ";
    cin >> a;
    cout << "Введите правую гранцу: ";
    cin >> b;
    cout << "Введите точность: ";
    cin >> epsilon;

    cout << "\nМЕТОД БИСЕКЦИИ\n";
    BesectionMethod(coeficients, a, b, epsilon);
    cout << "\nМЕТОД ХОРД\n";
    ChordMethod(coeficients, a, b, epsilon);
    cout << "\nМЕТОД НЬЮТОНА\n";
    NewtonMethod(coeficients, a, b, epsilon);

    return 0;
}
