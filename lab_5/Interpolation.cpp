#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <iomanip>
#define PI 3.14159265358979323846
using namespace std;


vector<double> knots(double start, double end, int amount) {
    vector<double> knots;
    double step = (end - start) / (amount - 1);
    for (double i = start; i <= end; i += step)
    {
        knots.push_back(i);
    }
    return knots;
}

vector<double> values(vector<double> knots) {
    vector<double> values;
    for (int i = 0; i < knots.size(); i++)
    {
        double y = pow(knots[i],2)*cos(knots[i]);
        //double y = knots[i] * sqrt(knots[i]);
        values.push_back(y);
    }
    return values;
}

vector<double> Newton(vector<double> knots, vector<double> values) {

    vector<double> a;
    a.push_back(values[0]);
    for (int i = 1; i < knots.size(); i++)
    {
       double werh = (values[i] - a[0]);
        for (int j = 1; j < i; j++)
        {
            double n = 1;
            for (int k = 0; k < j; k++)
            {
                n *= knots[i] - knots[k];
            }
            werh -= a[j] * n;
        }
        double nis = 1;
        for (int j = 0; j < i; j++)
        {
            nis *= (knots[i] - knots[j]);
        }
        a.push_back(werh / nis);
    }


    for (int i = 0; i < knots.size(); i++)
    {
        cout << " + " << a[i];
        double n = 1;
        for (int j = 0; j < i; j++)
        {
            cout << "*(" << "x" << " - " << knots[j] << ")";
        }
    }
    cout << endl;

    return a;
}

vector<double> valuesNewton(vector<double> knots, vector<double> a, vector<double> X) {
    vector<double> values;
    
    for (auto x : X) {
        double N = 0;
        for (int i = 0; i < knots.size(); i++)
        {
            double n = 1;
            for (int j = 0; j < i; j++)
            {
                n *= x - knots[j];
            }
            N += a[i] * n;
        }
        values.push_back(N);
    }
    return values;
}

vector<double> Pohidna(vector<double> coef) {
    vector<double> pohidna;
    for (int i = 1; i < coef.size(); i++) {
        pohidna.push_back(i * coef[i]);
    }
    return pohidna;
}

int main()
{
    int n = 10;    // с какой точностью выводить число

    vector<double> knot = knots(-PI/2, PI, 10);
    vector<double> value = values(knot);

    cout << "\nKNOTS:\t\tVALUES:\n";
    for (int i = 0; i < knot.size(); i++)
    {
        cout << fixed << setprecision(n) << knot[i] << "\t\t";
        cout << fixed << setprecision(n) << value[i] << "\n";
    }

    // Інтерполяційний поліном у формі Ньютона
    cout << "\nNEWTON POLINOM:\n";
    vector<double> NewtonPolinom = Newton(knot, value);

    vector<double> X = knot;
    vector<double> Y = valuesNewton(knot, NewtonPolinom, X);
    cout << "\n X:\t\t Y:\n";
    for (int i = 0; i < X.size(); i++)
    {
         cout << X[i] << "\t\t";
         cout << Y[i] << "\n";
    }

    // Значення похибки інтерполяційного поліному у формі Ньютона
    X = knots(-PI / 2, PI, 35);
    cout << "\n\nNEWTON POHIBKA:\n";
    cout << " values\t\t\t epsilon\n";
    vector<double> f = values(X);
    vector<double> newton = valuesNewton(knot, NewtonPolinom, X);
    for (int i = 0; i < X.size(); i++)
    {
        double E = abs(newton[i]-f[i]);
        cout << X[i] << "\t\t";
        cout << E << "\n";
    }

    return 0;
}