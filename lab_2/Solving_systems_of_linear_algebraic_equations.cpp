#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;

int main()
{
    float matrix_A[4][4] = { {1, 0.42, 0.54, 0.66}, {0.42, 1, 0.32, 0.44}, {0.54, 0.32, 1, 0.22}, {0.66, 0.44, 0.22, 1} };
    float vector_B[4] = { 0.3, 0.5, 0.7, 0.9 };
    cout.width(12);
    cout << "Your matrix A:\n";
    for (int i = 0; i < sizeof(matrix_A) / 16; i++) {
        for (int j = 0; j < sizeof(matrix_A[i]) / 4; j++) {
            cout.width(8);
            cout << matrix_A[i][j] << "   ";
        }
        cout << endl;
    }
    /// ////////////////////// Находим матрицу T /////////////////////////////// ///

    float matrix_T[4][4];
    matrix_T[0][0] = sqrt(matrix_A[0][0]);
    for (int i = 0; i < sizeof(matrix_T) / 16; i++) {
        for (int j = 0; j < sizeof(matrix_T[i]) / 4; j++) {
            if (i == 0) {
                matrix_T[j][i] = matrix_A[i][j] / matrix_T[0][0];
            }
            else if (i == j) {
                float sum_K = 0;
                int k = 0;
                while (k < i) {
                    sum_K += pow(matrix_T[j][k], 2);
                    k++;
                }
                matrix_T[j][i] = sqrt(matrix_A[i][j] - sum_K);
            }
            else if (j > i) {
                float sum_K = 0;
                int k = 0;
                while (k < i) {
                    sum_K += matrix_T[i][k] * matrix_T[j][k];
                    k++;
                }
                matrix_T[j][i] = (matrix_A[i][j] - sum_K) / matrix_T[i][i];
            }
            else {
                matrix_T[j][i] = 0;
            }
        }
    }
    cout << endl << endl;
    cout << "Your matrix T:\n";
    for (int i = 0; i < sizeof(matrix_T) / 16; i++) {
        for (int j = 0; j < sizeof(matrix_T[i]) / 4; j++) {
            cout.width(8);
            cout << matrix_T[i][j] << "   ";
        }
        cout << endl;
    }

    /// /////////////////// Транспонируем матрицу T ///////////////////////////// ///
    float matrix_T_[4][4];

    for (int i = 0; i < sizeof(matrix_T) / 16; i++) {
        for (int j = 0; j < sizeof(matrix_T[i]) / 4; j++) {
            matrix_T_[j][i] = matrix_T[i][j];
        }
    }
    cout << endl << endl;
    cout.width(12);
    cout << "Your transponent matrix T:\n";
    for (int i = 0; i < sizeof(matrix_T_) / 16; i++) {
        for (int j = 0; j < sizeof(matrix_T_[i]) / 4; j++) {
            cout.width(8);
            cout << matrix_T_[i][j] << "   ";
        }
        cout << endl;
    }

    /// //////////////////// Уножаем матрицы для проверки ////////////////////////// ///
    float matrix_Multiply[4][4];
    for (int i = 0; i < sizeof(matrix_T) / 16; i++) {
        for (int j = 0; j < sizeof(matrix_T[i]) / 4; j++) {
            float sum_K = 0;
            for (int k = 0; k < 4; k++) {
                sum_K += matrix_T[i][k] * matrix_T_[k][j];
            }
            matrix_Multiply[i][j] = sum_K;
        }
    }
    cout << endl << endl;
    cout.width(12);
    cout << "Your multiply matrix T:\n";
    for (int i = 0; i < sizeof(matrix_Multiply) / 16; i++) {
        for (int j = 0; j < sizeof(matrix_Multiply[i]) / 4; j++) {
            cout.width(8);
            cout << matrix_Multiply[i][j] << "   ";
        }
        cout << endl;
    }

    /// ////////////////// находим вектор y ////////////////////////// ///

    float vector_Y[4];
    vector_Y[0] = vector_B[0] / matrix_T[0][0];
    for (int i = 1; i < sizeof(vector_B) / 4; i++) {
        int k = 0;
        float sum_K = 0;
        while (k < i) {
            sum_K += matrix_T[i][k] * vector_Y[k];
            k++;
        }
        vector_Y[i] = (vector_B[i] - sum_K) / matrix_T[i][i];
    }
    cout << endl << endl;
    cout.width(12);
    cout << "Your vector Y:\n";
    for (int i = 0; i < sizeof(vector_Y) / 4; i++) {
        cout << vector_Y[i] << "  ";
    }

    /// //////////////////// находим неизвестные x //////////////////////// ///
    cout << endl << endl;
    cout << "Your vector B:\n";
    for (int i = 0; i < sizeof(vector_B) / 4; i++) {
        cout << vector_B[i] << "  ";
    }

    float vector_X[4];
    vector_X[3] = vector_Y[3] / matrix_T[3][3];
    for (int i = sizeof(vector_Y) / 4 - 2; i >= 0; i--) {
        int k = i + 1;
        float sum_K = 0;
        while (k < 4) {
            sum_K += matrix_T[k][i] * vector_X[k];
            k++;
        }
        vector_X[i] = (vector_Y[i] - sum_K) / matrix_T[i][i];
    }
    cout << endl << endl;
    cout << "Your vector X:\n";
    for (int i = 0; i < sizeof(vector_X) / 4; i++) {
        cout << vector_X[i] << "  ";
    }

    /// /////////////////// Делаем проверку  ///////////////////////// ///
    float answers[4];
    for (int i = 0; i < sizeof(matrix_T) / 16; i++) {
        float sum_K = 0;
        for (int j = 0; j < sizeof(matrix_T[i]) / 4; j++) {
            sum_K += vector_X[j] * matrix_A[i][j];
        }
        answers[i] = sum_K;
    }
    cout << endl << endl;
    cout << "Your answers:\n";
    for (int i = 0; i < sizeof(answers) / 4; i++) {
        cout << answers[i] << "  ";
    }
    cout << endl;
    return 0;
}
