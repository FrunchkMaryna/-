//9. Акції виду А1, А2, А3 мають, відповідно, сподівані норми прибутку 20%, 40% та 60%, середньоквадратичні відхилення 10%, 18% та 30%, коефіцієнти кореляції p_12 = 1, p_13 = – 1 та p_23 = – 1.
//Необхідно:
//а) визначити структуру ПЦП, що має найбільшу сподівану норму прибутку при мінімальному ризику;
//б) обчислити сподівану норму прибутку та величину ризику для отримання ПЦП


#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

struct Stock {
    double expected_return;  // Сподівана норма прибутку
    double std_dev;          // Стандартне відхилення (ризик)
};

// Функція для розрахунку очікуваного прибутку портфеля
double portfolioReturn(const vector<Stock>& stocks, const vector<double>& weights) {
    double result = 0.0;
    for (size_t i = 0; i < stocks.size(); ++i) {
        result += weights[i] * stocks[i].expected_return;
    }
    return result;
}

// Функція для розрахунку ризику портфеля
double portfolioRisk(const vector<Stock>& stocks, const vector<double>& weights, const vector<vector<double>>& correlations) {
    double risk = 0.0;
    for (size_t i = 0; i < stocks.size(); ++i) {
        for (size_t j = 0; j < stocks.size(); ++j) {
            risk += weights[i] * weights[j] * stocks[i].std_dev * stocks[j].std_dev * correlations[i][j];
        }
    }
    return sqrt(risk);
}

int main() {
    // Данні акцій
    Stock A1 = {0.20, 0.10};
    Stock A2 = {0.40, 0.18};
    Stock A3 = {0.60, 0.30};
    
    vector<Stock> stocks = {A1, A2, A3};

    // Коефіцієнти кореляції
    vector<vector<double>> correlations = {
        {1.0, 1.0, -1.0},
        {1.0, 1.0, -1.0},
        {-1.0, -1.0, 1.0}
    };

    // Приклад ваг портфеля
    vector<double> weights = {0.4, 0.3, 0.3}; // Ваги акцій у портфелі (їх можна змінювати)

    // Розрахунок сподіваної норми прибутку портфеля
    double expected_portfolio_return = portfolioReturn(stocks, weights);

    // Розрахунок ризику портфеля
    double portfolio_risk = portfolioRisk(stocks, weights, correlations);

    // Виведення результатів
    cout << "Сподівана норма прибутку портфеля: " << expected_portfolio_return << endl;
    cout << "Ризик портфеля (стандартне відхилення): " << portfolio_risk << endl;

    return 0;
}
