 //9. Користуючись концепцією корисності за Нейманом, порівняйте ефективність рішень,
//записаних у таблиці попередньої задачі, якщо функція корисності задається формулою U(x) = sqrt(x+5) / 15 

#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

using namespace std;

// Функція для обчислення сподіваного значення
double expectedValue(const vector<double>& probabilities, const vector<double>& values) {
    double sum = 0.0;
    for (size_t i = 0; i < probabilities.size(); ++i) {
        sum += probabilities[i] * values[i];
    }
    return sum;
}

// Функція для обчислення варіації
double variance(const vector<double>& probabilities, const vector<double>& values, double expValue) {
    double sum = 0.0;
    for (size_t i = 0; i < probabilities.size(); ++i) {
        sum += probabilities[i] * pow(values[i] - expValue, 2);
    }
    return sum;
}

// Функція для обчислення коефіцієнта варіації
double coefficientOfVariation(double stdDeviation, double expValue) {
    return (stdDeviation / expValue) * 100; // У відсотках
}

int main() {
    int n;
    cout << "Введіть кількість варіантів прибутку: ";
    cin >> n;

    vector<double> probabilities(n), values(n);

    // Введення ймовірностей та значень прибутку
    cout << "Введіть ймовірності: ";
    for (int i = 0; i < n; ++i) {
        cin >> probabilities[i];
    }

    cout << "Введіть значення випадкової величини (прибутки): ";
    for (int i = 0; i < n; ++i) {
        cin >> values[i];
    }

    // Обчислення сподіваного значення
    double expValue = expectedValue(probabilities, values);
    
    // Обчислення варіації
    double var = variance(probabilities, values, expValue);
    
    // Середньоквадратичне відхилення
    double stdDeviation = sqrt(var);
    
    // Коефіцієнт варіації
    double coefVar = coefficientOfVariation(stdDeviation, expValue);

    // Виведення результатів
    cout << fixed << setprecision(4);
    cout << "\n=== Результати оцінки ризику ===\n";
    cout << "Сподіване значення: " << expValue << endl;
    cout << "Варіація: " << var << endl;
    cout << "Середньоквадратичне відхилення: " << stdDeviation << endl;
    cout << "Коефіцієнт варіації: " << coefVar << "%\n";

    // Висновок на основі коефіцієнта варіації
    cout << "\n=== Висновок ===\n";
    if (coefVar < 10) {
        cout << "Цей проект має низький рівень ризику.\n";
    } else if (coefVar < 20) {
        cout << "Цей проект має середній рівень ризику.\n";
    } else {
        cout << "Цей проект має високий рівень ризику.\n";
    }

    return 0;
}
