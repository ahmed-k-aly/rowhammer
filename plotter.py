import numpy as np

import matplotlib.pyplot as plt

# Initialize an empty list to store times
times = []

# Read the file
with open('results.txt', 'r') as file:
    # Iterate over each line in the file
    for line in file:
        # Split the line into its components
        operation, id, time = line.split()
        if operation != 'R':
            continue
        # Append the time to the list
        times.append(float(time))

# Create a histogram
hist, bins = np.histogram(times, bins=100, range=(13, 38))

# Calculate the center value
center_value = np.mean(times)

# Create a grid of values based on the histogram
grid = np.zeros((10, 10))
for i in range(10):
    for j in range(10):
        grid[i, j] = hist[i * 10 + j]

# Plot the heatmap with a modified colormap
plt.imshow(grid, cmap='plasma', interpolation='nearest')
plt.colorbar(label='Frequency')
plt.title('Time Frequency Heatmap')
# Label the x and y axes   
plt.xlabel('Time')
plt.ylabel('Frequency')
plt.show()
plt.imshow(grid, cmap='plasma', interpolation='nearest')
plt.colorbar(label='Frequency')
plt.title('Time Frequency Heatmap')

# Label the x and y axes   
plt.xlabel('Time')
plt.ylabel('Frequency')



plt.show()
