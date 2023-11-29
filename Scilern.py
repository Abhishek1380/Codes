import numpy as np
from scipy import stats, optimize, signal, linalg

mean_val = np.mean([1, 2, 3, 4, 5])
median_val = np.median([1, 2, 3, 4, 5])
mode_val = stats.mode([1, 2, 2, 3, 3, 3, 4, 4, 4, 5])[0][0]
std_dev = np.std([1, 2, 3, 4, 5])

matrix = np.array([[1, 2], [3, 4]])
det = linalg.det(matrix)
inv_matrix = linalg.inv(matrix)

result = optimize.minimize(lambda x: (x - 2) ** 2, x0=0)

t = np.linspace(0, 1, 100)
signal_wave = np.sin(2 * np.pi * 5 * t)
correlation = np.correlate(signal_wave, signal_wave, mode='same')

x = np.array([1, 2, 3, 4])
y = np.array([2, 4, 1, 3])
interp_result = np.interp(2.5, x, y)

result_integration, error_integration = quad(lambda x: x**2, 0, 1)

time_points = np.linspace(0, 1, 1000)
signal_freq = 5
signal_fft = np.fft.fft(np.sin(2 * np.pi * signal_freq * time_points))

sparse_matrix = linalg.sparse.csr_matrix(matrix)

ode_result = integrate.solve_ivp(lambda t, y: y, (0, 1), [1])

distance = linalg.norm([1, 2, 3] - [4, 5, 6])

image = np.array([[1, 2], [3, 4]])
filtered_image = signal.convolve2d(image, [[1, 0], [0, -1]], mode='valid')
