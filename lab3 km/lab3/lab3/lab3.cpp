#include <iostream>

using namespace std;

int main()
{
    double a[9][9] = { {-201, 90, 0, 0, 0, 0, 0, 0, 0},
                       {110, -201, 90, 0, 0, 0, 0, 0, 0},
                       {0, 110, -201, 90, 0, 0, 0, 0, 0},
                       {0, 0, 110, -201, 90, 0, 0, 0, 0},
                       {0, 0, 0, 110, -201, 90, 0, 0, 0},
                       {0, 0, 0, 0, 110, -201, 90, 0, 0},
                       {0, 0, 0, 0, 0, 110, -201, 90, 0},
                       {0, 0, 0, 0, 0, 0, 110, -201, 90},
                       {0, 0, 0, 0, 0, 0, 0, 110, -201} };
    double f[9] = { -0.221,
                    -0.488,
                    -0.804,
                    -1.193,
                    -1.648,
                    -2.186,
                    -2.819,
                    -3.56,
                    -249.065
    };
    int dim = 9;

    double alfa[9] = {};
    double beta[9] = {};
    double z[9] = {};
    double x[10] = {};

    //double roots[3] = { 1,2,3 };

    cout << "Matrix:\n";
    for (int i = 0; i <= dim - 1; i++)
    {
        for (int j = 0; j <= dim - 1; j++)
        {
            cout << a[i][j] << " ";
        };
        cout << "|" << f[i] << endl;
    };

    //cout << "Root x1: " << roots[0] << endl;
    //cout << "Root x2: " << roots[1] << endl;
    //cout << "Root x3: " << roots[2] << endl << endl;

    cout << "Let's start calculating the coefficients alpha and beta, zet will also be displayed\n";
    alfa[0] = a[0][1] / -a[0][0]; // 2 / (-1) = -2;
    beta[0] = -f[0] / -a[0][0];// -5 / -1 = 5;

    cout << "Iteration: 1" << endl;
    cout << "alfa0" << ": " << alfa[0] << endl;
    cout << "beta0" << ": " << beta[0] << endl;

    for (int i = 1; i <= dim - 1; i++) {
        z[i] = -a[i][i] - a[i][i - 1] * alfa[i - 1];
        alfa[i] = a[i][i + 1] / z[i]; // 1.5, 0
        beta[i] = (-f[i] + a[i][i - 1] * beta[i - 1]) / z[i];// -2.5, 3
        if (i == dim - 1) {
            alfa[i] = 0;
        }
        cout << "Iteration: " << i + 1 << endl;
        cout << "alfa" << i << ": " << alfa[i] << endl;
        cout << "beta" << i << ": " << beta[i] << endl;
        cout << "z" << i << ": " << z[i] << endl;
    };

    cout << endl;
    x[dim - 1] = beta[dim - 1];
    for (int i = dim - 1; i >= 0; i--) {
        x[i] = alfa[i] * x[i + 1] + beta[i];
    };

    cout << "Calculated roots:\n";
    for (int i = 0; i < dim; i++) {
        cout.precision(15);
        cout << "y" << i + 1 << ": " << x[i] << endl;
    }
}