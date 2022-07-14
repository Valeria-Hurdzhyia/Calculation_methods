#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

bool check(vector<vector<float>> matrix_A) {
    for (int i = 0; i < matrix_A.size(); i++) {
        float sum = 0;
        for (int j = 0; j < matrix_A[i].size(); j++) {
            if (i != j) {
                sum += abs(matrix_A[i][j]);
            }
        }
        if (abs(matrix_A[i][i]) <= sum) {
             return false;
        }
    }
    return true;
}

void SimpleIterationMethod(vector<vector<float>> matrix_A, vector<float> vector_B, float epsilon) {
    vector<vector<float>> X = { {0, 0, 0, 0} };
    vector<float> Delta;
    vector<float> R;
    float maxDelta = 1;
    int count = 0;
    vector<float> answers;
    while (maxDelta > epsilon) {
        cout << "Итерация № " << count+1;
        for (int i = 0; i < matrix_A.size(); i++) {
            float sum = 0;
            for (int j = 0; j < matrix_A[i].size(); j++) {
                if (i != j) {
                    sum += matrix_A[i][j] * X[count][j];
                }
            }
            float x = (vector_B[i] - sum) / matrix_A[i][i];
            answers.push_back(x);
        }
        X.push_back(answers);
        if (count > 0) {
            for (int j = 0; j < X[X.size() - 1].size(); j++) {
                float delta = abs(X[X.size() - 1][j] - X[X.size() - 2][j]);
                Delta.push_back(delta);
            }
            maxDelta = 0;
            for (int i = 0; i < Delta.size(); i++) {
                if (Delta[i] > maxDelta) {
                    maxDelta = Delta[i];
                }
            }
        }
        for (int i = 0; i < matrix_A.size(); i++) {
            float AX = 0;
            for (int j = 0; j < matrix_A[i].size(); j++) {
                AX += matrix_A[i][j] * answers[j];
            }
            float r = abs(vector_B[i] - AX);
            R.push_back(r);
        }
        cout << "\nКорни x:  \t\t";
        for (auto a : answers) {
            cout << a << "   ";
        }
        cout << "\nВектор невязки r:  \t";
        for (auto r : R) {
            cout << fixed << r << "   ";
        }
        cout << endl << endl;
        R.clear();
        answers.clear();
        Delta.clear();
        count++;
    }  
}

int main()
{
    setlocale(LC_ALL, "ru");
    vector<vector<float>> matrix_A = {
        {1, 0.0082, 0.144473, 0.656011},
        {0, 0.8236, 0.0932, 0.1628},
        {0, 0, 0.697853, -0.15482},
        {0, 0, 0, 0.497871} };
    vector<float> vector_B = { -0.13484, 0.374, 0.495678, 0.738041 };
    float epsilon = 0.0001;

    if (!check(matrix_A)) {
        cout << "Матрица не диагонально преобладающая!\n";
    }
    else {
        SimpleIterationMethod(matrix_A, vector_B, epsilon);
    }
}