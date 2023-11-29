import numpy as np
import matplotlib.pyplot as plt

np.random.seed(42)
test_results1 = np.random.normal(loc=70, scale=10, size=100)
test_results2 = np.random.normal(loc=75, scale=12, size=100)

mean1 = np.sum(test_results1) / len(test_results1)
mean2 = np.sum(test_results2) / len(test_results2)

variance1 = np.sum((test_results1 - mean1)**2) / (len(test_results1) - 1)
variance2 = np.sum((test_results2 - mean2)**2) / (len(test_results2) - 1)

std_dev1 = np.sqrt(variance1)
std_dev2 = np.sqrt(variance2)

covariance = np.sum((test_results1 - mean1) * (test_results2 - mean2)) / (len(test_results1) - 1)

correlation = covariance / (std_dev1 * std_dev2)

std_error1 = std_dev1 / np.sqrt(len(test_results1))
std_error2 = std_dev2 / np.sqrt(len(test_results2))

plt.figure(figsize=(12, 6))

plt.subplot(1, 2, 1)
plt.hist(test_results1, bins=30, alpha=0.6, color='g', label='Class 1')
plt.hist(test_results2, bins=30, alpha=0.6, color='b', label='Class 2')
plt.title("Distribution of Class Test Results")
plt.xlabel("Test Results")
plt.ylabel("Frequency")
plt.legend()

plt.subplot(1, 2, 2)
plt.scatter(test_results1, test_results2, alpha=0.8)
plt.title("Scatter Plot of Class Test Results")
plt.xlabel("Class 1 Test Results")
plt.ylabel("Class 2 Test Results")

plt.tight_layout()
plt.show()

print(f"Class 1 Mean: {mean1:.2f}")
print(f"Class 2 Mean: {mean2:.2f}")
print(f"Class 1 Variance: {variance1:.2f}")
print(f"Class 2 Variance: {variance2:.2f}")
print(f"Class 1 Standard Deviation: {std_dev1:.2f}")
print(f"Class 2 Standard Deviation: {std_dev2:.2f}")
print(f"Covariance: {covariance:.2f}")
print(f"Correlation: {correlation:.2f}")
print(f"Class 1 Standard Error: {std_error1:.2f}")
print(f"Class 2 Standard Error: {std_error2:.2f}")
