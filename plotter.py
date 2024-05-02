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

# Normalize the data
normalized_times = (times - np.min(times)) / (np.max(times) - np.min(times))

# Plot the data as a scatterplot
plt.scatter(range(len(normalized_times)), normalized_times)
plt.xlabel('Index')
plt.ylabel('Normalized Time')
plt.title('Normalized Time Scatterplot')
plt.show()
