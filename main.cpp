#include <iostream>
#include <iomanip>
#include <cmath>
#include <climits>

using namespace std;

int main() {
    double a, b;

    cout << "Введите a: ";
    cin >> a;
    cout << "Введите b: ";
    cin >> b;
    if (!cin) {
        cout << "Введите числа a и b.\n";
        return 1;
    }

    if (a > b) {
        cout << "a должно быть меньше или равно b.\n";
        return 1;
    }

    if (!isfinite(4 * exp(fmax(abs(a), abs(b))))) {
        cout << "Ошибка: значения выходят за диапазон вычислений.\n";
        return 1;
    }

    if (a == b) {
        double F = sqrt(a * a + 4);
        double G = 4 * exp(abs(a)) - 1;
        cout << fixed << setprecision(4);
        cout << "\nОдна точка (x = " << a << "):\n";
        cout << "F = " << F << '\n';
        cout << "G = " << G << '\n';
        return 0;
    }

    double n;
    cout << "Введите n: ";
    cin >> n;
    if (!cin || n <= 0 || n != floor(n)) {
        cout << "n должно быть положительным целым числом.\n";
        return 1;
    }
    if (n >= LONG_MAX) {
        cout << "Слишком большое число интервалов.\n";
        return 1;
    }

    double h = (b - a) / n;
    cout << "\nШаг h = " << h << '\n';
    cout << fixed << setprecision(4);

    const char border[] = "+-------+---------------+---------------+---------------+\n";
    cout << border
         << "|     i |           x_i |        F(x_i) |        G(x_i) |\n"
         << border;

    long i = 0;
    while (i <= n) {
        double x = a + i * h;
        double F = sqrt(x * x + 4);
        double G = 4 * exp(abs(x)) - 1;

        cout << "| " << setw(5) << i << " "
             << "| " << setw(13) << x << " "
             << "| " << setw(13) << F << " "
             << "| " << setw(13) << G << " |\n";

        ++i;
    }

    cout << border;
    return 0;
}
