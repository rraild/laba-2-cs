#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main() {
    double a, b;
    int n;

    cout << "Введите a: ";
    cin >> a;
    cout << "Введите b: ";
    cin >> b;
    cout << "Введите n: ";
    cin >> n;

    if (!cin || n <= 0) {
        cout << "Введите числа a и b и положительное целое n.\n";
        return 1;
    }

    if (a >= b) {
        cout << "a должно быть меньше b.\n";
        return 1;
    }

    double h = (b - a) / n;
    const char border[] = "+-------+---------------+---------------+---------------+\n";
    cout << "\nШаг h = " << h << '\n' << border
         << "|     i |           x_i |        F(x_i) |        G(x_i) |\n"
         << border;

    for (long i = 0; i <= n; ++i) {
        double x = a + i * h;
        double F = sqrt(x * x + 4);
        double G = 4 * exp(abs(x)) - 1;

        cout << "| " << setw(5) << i << " "
             << "| " << setw(13) << x << " "
             << "| " << setw(13) << F << " "
             << "| " << setw(13) << G << " |\n";
    }

    cout << border;
    return 0;
}
