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

# Plot the data as a frequency histogram
plt.hist(times, bins=50, range=(13, 38), edgecolor='black')
plt.xlabel('Time')
plt.xticks(range(13, 38, 5))  # Set x-axis ticks to increment by 5
plt.ylabel('Frequency')
plt.title('Time Frequency Histogram')
plt.show()
