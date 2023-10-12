import matplotlib.pyplot as plt
from matplotlib.patches import Circle, Rectangle

with open('points.txt', 'r') as file:
	data = file.read().split()

x = [float(data[i]) for i in range(0, len(data), 2)]
y = [float(data[i]) for i in range(1, len(data), 2)]

# set the size of the graph 
plt.figure(figsize=(8, 8))

plt.scatter(x, y, label='points', color='b', marker='o', s=1)

plt.xlabel('X')
plt.ylabel('Y')
plt.title('Visualization of the Monte Carlo algorithm\nfor estimating the value of pi')
plt.legend()
plt.grid(True)

# creating circle
circle = Circle((0, 0), radius=1, color='r', fill=False, linewidth=3)
plt.gca().add_patch(circle)

# creating square
square = Rectangle((-1, -1), 2, 2, color='g', fill=False, linewidth=3)
plt.gca().add_patch(square)

plt.savefig('images/graph.png')
plt.show()