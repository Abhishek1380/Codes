import numpy as np
import matplotlib.pyplot as plt
from scipy.stats import norm, skew, kurtosis

np.random.seed(42)
test_results = np.random.normal(loc=70, scale=10, size=1000)

plt.hist(test_results, bins=30, density=True, alpha=0.6, color='g')

mu, std = norm.fit(test_results)
xmin, xmax = plt.xlim()
x = np.linspace(xmin, xmax, 100)
p = norm.pdf(x, mu, std)
plt.plot(x, p, 'k', linewidth=2)

plt.title("Normal Distribution Fit for Class Test Results")
plt.xlabel("Test Results")
plt.ylabel("Frequency")

plt.show()

skewness = skew(test_results)
kurt = kurtosis(test_results)

print(f"Skewness: {skewness:.2f}")
print(f"Kurtosis: {kurt:.2f}")
