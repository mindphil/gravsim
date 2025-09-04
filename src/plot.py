#."path to main.exe" > orbit_data.csv
import pandas as pd
import matplotlib.pyplot as plt

# encodes as utf-16 for some reason; specified here to prevent error
df = pd.read_csv(r'link', encoding='utf-16')

plt.figure(figsize=(8,8))
plt.plot(df['Body1_X'], df['Body1_Y'], 'b-', label='Body 1', linewidth=2)
plt.plot(df['Body2_X'], df['Body2_Y'], 'r-', label='Body 2', linewidth=2)

plt.axis('equal')
plt.grid(True)
plt.legend()
plt.title('Two-Body Orbit')
plt.show()