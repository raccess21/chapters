import pandas as pd
import matplotlib.pyplot as plt 
from os import system

system("cls")

df = pd.read_csv("data/data_relations.csv")
df.dropna(inplace=True)
df.drop_duplicates(inplace=True)

# plt.plot(df, xlabel="Observation", ylabel="Value")
# plt.show()

df.plot(xlabel="Observation", ylabel="Value")
df.plot(kind="scatter", x="Duration", y="Calories", color="green")
df.plot(kind="scatter", x="Duration", y="Maxpulse")
plt.show()
plt.clf()

df["Duration"].plot(kind="hist")
plt.show()

asd = pd.Series([1,2,3,4], )
asd.get()
