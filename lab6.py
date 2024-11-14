
//9 variant

import numpy as np

# Вхідні дані
F_minus = np.array([
    [8, 10],
    [12, 8],
    [10, 8],
    [4, 12]
])

F_plus = np.array([
    [100, 160],
    [120, 140],
    [110, 150],
    [150, 120]
])

# Ймовірності для станів середовища
p = np.array([0.3, 0.3, 0.25, 0.15])

# Вагові коефіцієнти для функціоналів оцінювання
u1 = 1 / 4
u2 = 3 / 4

# Параметр компромісу
lambda_value = 0.7

# Обчислення середнього очікуваного значення для кожного рішення
expected_value_minus = np.dot(F_minus, p)
expected_value_plus = np.dot(F_plus, p)

# Компромісне значення за критерієм Ходжеса-Лемана
F_HL = lambda_value * expected_value_plus + (1 - lambda_value) * expected_value_minus

# Обчислення зваженої матриці
F_combined = u1 * F_minus + u2 * F_plus

# Вибір оптимального рішення
optimal_decision_index = np.argmax(F_HL)

# Вивід результатів
print("Очікувані значення для F- :\n", expected_value_minus)
print("Очікувані значення для F+ :\n", expected_value_plus)
print("Компромісне значення за критерієм Ходжеса-Лемана:\n", F_HL)
print(f"Оптимальне рішення: x{optimal_decision_index + 1} з величиною {F_HL[optimal_decision_index]}")
