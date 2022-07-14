#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
using namespace std;

float func_(float x) {
    float Y = cos(x);
    return Y;
}
float func(float x, float y) {
    float Y = (1 - pow(x, 2)) * y - sin(x) - cos(x) * (1 - pow(x, 2));
    return Y;
}

vector<float> RangeKutta(float h, float start, float end) {
    float x = 0;
    float y = 0;

    vector<float> result;
    result.push_back(func_(start));

    for (int i = 0; i < (start+end)/h; i++) {
        
        float k1 = h * func(x, result[i]);
        float k2 = h * func(x + 1/2 * h, result[i] + 1/2 * k1);
        float k3 = h * func(x + 1/2 * h, result[i] + 1/2 * k2);
        float k4 = h * func(x + h, result[i] + k3);
        float ans = result[i] + (k1 + 2 * k2 + 2 * k3 + k4) / 6;
        result.push_back(ans);
        x += h;
    }
    return result;
}

vector<float> AdamsBashfort(float h, float start, float end) {
    vector<float> range_kutta_values = RangeKutta(h, start, end);
    vector<float> result;

    for (int i = 0; i < 4; i++)
    {
        result.push_back(range_kutta_values[i]);
    }
    float x = start;
    int i = 3;
    while (end > x+0.3) {
        float answer = result[i] + (h / 24) * (55 * func(x + 3 * h, result[i]) - 59 * func(x + 2 * h, result[i - 1]) + 37 * func(x + h, result[i - 2]) - 9 * func(x, result[i - 3]));
        x += h;
        i++;
        result.push_back(answer);
    }
    return result;
}

int main()
{
    float h = 0.1;
    float start = 0;
    float end = 1;

    vector<float> result_RK = RangeKutta(h, start, end);
    vector<float> result_AB = AdamsBashfort(h, start, end);
    vector<float> result_func;
    for (float x = start; x < end+h; x += h)
    {
        result_func.push_back(func_(x));
    }

    // pohibka
    vector<float> pohibka_RK;
    vector<float> pohibka_AB;
    for (float i = 0; i < result_func.size(); i++)
    {
        float pohibka_rk = abs(result_func[i] - result_RK[i]);
        pohibka_RK.push_back(pohibka_rk);
        float pohibka_ab = abs(result_func[i] - result_AB[i]);
        pohibka_AB.push_back(pohibka_ab);
    }


    cout << "\RangeKutta:\n\n";
    cout << fixed << setw(4) << "x" << "\t\tresult" << "\t\tpohibka\n";
    float x = 0;
    for (int i = 0; i < result_RK.size(); i++)
    {
        cout << x << "\t" << result_RK[i] << "\t" << pohibka_RK[i] << endl;
        x += 0.1;
    }

    cout << "\nAdamsBashfort:\n\n";
    cout << fixed << setw(4) << "x" << "\t\tresult"  << "\t\tpohibka\n";
    x = 0;
    for (int i = 0; i < result_AB.size(); i++)
    {
        cout << x << "\t" << result_AB[i] << "\t" << pohibka_AB[i] << endl;
        x += 0.1;
    }

    cout << "\nF(x):\n\n";
    cout << fixed << setw(4) << "x" << "\t\tresult\n";
    x = 0;
    for (int i = 0; i < result_func.size(); i++)
    {
        cout << x << "\t" << result_func[i] << endl;
        x += 0.1;
    }
}