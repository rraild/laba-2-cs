#include <iostream>
#include <iomanip>
#include <cmath>
#include <cctype>

using namespace std;

int main()
{
    double a, b;
    int n;
    cout << "Введите A, B и N: ";
    if (!(cin >> a >> b >> n) || !isfinite(a) || !isfinite(b)) {
        cerr << "Ошибка: введите два числа A, B и целое N.\n";
        return 1;
    }

    int next = cin.peek(); // Проверяем, что после целого N нет остатка
    if (n <= 0 || (!cin.eof() && !isspace(next))) {
        cerr << "Ошибка: N должно быть положительным целым числом.\n";
        return 1;
    }
    if (a >= b) {
        cerr << "Ошибка: A должно быть меньше B.\n";
        return 1;
    }

    double h = (b - a) / n;
    double maxX = fmax(abs(a), abs(b));
    if (h <= 0 || !isfinite(4 * exp(maxX))) {
        cerr << "Ошибка: значения выходят за диапазон вычислений.\n";
        return 1;
    }

    const char border[] = ","
                          "+------------------+------------------+";
    cout << setprecision(8) << "\nШаг h = " << h << '\n' << border << '\n'
         << "|          i |              x_i "
            "|           F(x_i) |           G(x_i) |\n"
         << border << '\n';

    for (int i = 0; i <= n; ++i) {
        double x = (i == n) ? b : a + i * h;
        double f = sqrt(x * x + 4);
        double g = 4 * exp(abs(x)) - 1;
        cout << "| " << setw(10) << i << " | " << setw(16) << x
             << " | " << setw(16) << f << " | " << setw(16) << g << " |\n";
    }
    cout << border << '\n';
    return 0;
}
