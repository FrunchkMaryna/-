//9 variant


import numpy as np

# Матриця очікуваних доходів
F = np.array([
    [6, 7, 8, 2],
    [4, 3, 5, 4],
    [8, 3, 4, 3]
    [5, 9, 3, 2],
    [7, 4, 6, 4]
])

# Кількість альтернатив та станів
num_alternatives, num_states = F.shape

# Критерій Вальда (максимальний мінімум)
wald_criterion = np.max(np.min(F, axis=1))
optimal_wald_index = np.argmax(np.min(F, axis=1))
print(f"Критерій Вальда: Максимальний мінімум = {wald_criterion}, Оптимальна стратегія = x{optimal_wald_index + 1}")

# Критерій Лапласа (середнє значення)
laplace_criterion = np.mean(F, axis=1)
optimal_laplace_index = np.argmax(laplace_criterion)
print(f"Критерій Лапласа: Середнє значення = {laplace_criterion[optimal_laplace_index]}, Оптимальна стратегія = x{optimal_laplace_index + 1}")

# Критерій Гурвіца (коефіцієнт оптимізму, наприклад, α = 0.5)
alpha = 0.5
hurwicz_criterion = alpha * np.max(F, axis=1) + (1 - alpha) * np.min(F, axis=1)
optimal_hurwicz_index = np.argmax(hurwicz_criterion)
print(f"Критерій Гурвіца: Результат = {hurwicz_criterion[optimal_hurwicz_index]}, Оптимальна стратегія = x{optimal_hurwicz_index + 1}")

# Критерій Севиджа (мінімізація максимальних втрат)
max_losses = np.max(F, axis=0) - F
savage_criterion = np.max(max_losses, axis=1)
optimal_savage_index = np.argmin(savage_criterion)
print(f"Критерій Севиджа: Мінімальні втрати = {savage_criterion[optimal_savage_index]}, Оптимальна стратегія = x{optimal_savage_index + 1}")
