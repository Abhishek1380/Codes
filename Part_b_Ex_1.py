import numpy as np
from sklearn.decomposition import PCA
from sklearn.preprocessing import StandardScaler
import matplotlib.pyplot as plt

feature1 = np.array([1, 2, 3, 4, 5])
feature2 = np.array([5, 4, 3, 2, 1])

X = np.vstack((feature1, feature2)).T

correlation_matrix = np.corrcoef(X, rowvar=False)
print("Correlation Matrix:")
print(correlation_matrix)

scaler = StandardScaler()
X_scaled = scaler.fit_transform(X)

pca = PCA(n_components=1)
X_pca = pca.fit_transform(X_scaled)

print("\nReduced-dimension data after PCA:")
print(X_pca)

plt.figure(figsize=(8, 4))

plt.subplot(1, 2, 1)
plt.scatter(X[:, 0], X[:, 1], c='b', marker='o')
plt.title('Original Data')
plt.xlabel('Feature 1')
plt.ylabel('Feature 2')

plt.subplot(1, 2, 2)
plt.scatter(X_pca, np.zeros_like(X_pca), c='r', marker='o')
plt.title('Reduced-dimension Data (After PCA)')
plt.xlabel('Principal Component 1')

plt.tight_layout()
plt.show()
