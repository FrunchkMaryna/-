#include <iostream>
#include <cmath>
using namespace std;

// Функція для обчислення математичного сподівання для банку
double expected_value_bank(double initial_amount, double interest_rate, double success_prob) {
    return success_prob * (initial_amount * (1 + interest_rate)) + (1 - success_prob) * initial_amount;
}

// Функція для обчислення математичного сподівання для АТ
double expected_value_stock(double initial_amount, double interest_rate, double success_prob) {
    return success_prob * (initial_amount * (1 + interest_rate)) + (1 - success_prob) * initial_amount;
}

// Функція для обчислення дисперсії
double variance(double initial_amount, double interest_rate, double success_prob, double expected_val) {
    return success_prob * pow(initial_amount * (1 + interest_rate) - expected_val, 2) +
           (1 - success_prob) * pow(initial_amount - expected_val, 2);
}

int main() {
    double initial_amount = 2500.0;  // сума інвестування
    double bank_interest_rate = 0.04; // 4% річних для банку
    double bank_success_prob = 0.99;  // ймовірність успіху банку

    double stock_interest_rate = 0.208; // 20.8% річних для АТ
    double stock_success_prob = 0.5;    // ймовірність успіху АТ (змінна)

    // Обчислення очікуваного прибутку для банку
    double expected_bank = expected_value_bank(initial_amount, bank_interest_rate, bank_success_prob);
    cout << "Математичне сподівання для інвестування в банк: $" << expected_bank << endl;

    // Обчислення очікуваного прибутку для АТ
    double expected_stock = expected_value_stock(initial_amount, stock_interest_rate, stock_success_prob);
    cout << "Математичне сподівання для інвестування в АТ (ймовірність успіху 0.5): $" << expected_stock << endl;

    // Обчислення дисперсії та коефіцієнта варіації для банку
    double var_bank = variance(initial_amount, bank_interest_rate, bank_success_prob, expected_bank);
    double std_dev_bank = sqrt(var_bank);
    double cv_bank = std_dev_bank / expected_bank;
    cout << "Дисперсія для банку: " << var_bank << ", Коефіцієнт варіації: " << cv_bank << endl;

    // Обчислення дисперсії та коефіцієнта варіації для АТ
    double var_stock = variance(initial_amount, stock_interest_rate, stock_success_prob, expected_stock);
    double std_dev_stock = sqrt(var_stock);
    double cv_stock = std_dev_stock / expected_stock;
    cout << "Дисперсія для АТ: " << var_stock << ", Коефіцієнт варіації: " << cv_stock << endl;

    // Пошук мінімальної ймовірності успіху АТ, при якій інвестиції в акції вигідніші за банк
    double min_success_prob = (expected_bank - initial_amount) / (initial_amount * stock_interest_rate);
    cout << "Мінімальна ймовірність успіху АТ для вигідності акцій: " << min_success_prob << endl;

    return 0;
}
