import pandas as pd
from os import system

system("cls")

df = pd.read_csv("data/data_relations.csv")
df.dropna(inplace=True)
df.drop_duplicates(inplace=True)

# corr() method returns a table of numbers that represents relationship between two columns.
# The number varies from -1 to 1.

# 1 means a perfect correlation, and for this data set, each time a value went up in the first column, the other one went up as well.

# 0.9 is also a good relationship, and if you increase one value, the other will probably increase as well.

# -0.9 would be just as good relationship as 0.9, but if you increase one value, the other will probably go down.

# 0.2 means NOT a good relationship, meaning that if one value goes up does not mean that the other will.
print(df.corr())