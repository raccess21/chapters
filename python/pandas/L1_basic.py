import pandas as pd

print("\nPandas version: ", pd.__version__)


# A Pandas Series is like a column in a table
# It is a one-dimensional array holding data of any type.
myvar = pd.Series([1, 7, 2])
print("\nSeries: \n", myvar)


# DataFrame is a 2D data structure, like a 2D array, or a table with rows and columns
# Create DataFrame from dict
mydataset = {
    'cars': ["BMW", "Volvo", "Ford"],
    'passings': [3, 7, 2]
}

myvar = pd.DataFrame(mydataset)
print("\nDataframe: \n", myvar)

# refer to row 1 returns series with row 1
print("\nRow 1: \n", myvar.loc[0])

# refer to row 1 and 2 returns dataframe with row 1 and 2
print("\nRow 1 and 2: \n", myvar.loc[[0, 1]])


# index argument, for naming your own indexes.
myvar.index = ["first", "second", "third"]
myCars = pd.DataFrame(mydataset, index=["first", "second", "third"])

print("\nMyCars: \n", myCars)
print("\nMyCars at loc 1: \n", myCars.loc["first"])


# ------------------------------------------------CSV----------------------------------------
# Read write csv
df = pd.read_csv("data/data.csv")
# df.to_csv("data/data.csv", index=False)

# For large DataFrames Pandas returns first 5 and the last 5 rows:
# use to_string() to print the entire DataFrame.

print("\n5 row print cap for df with more than", pd.options.display.max_rows, "rows")
pd.options.display.max_rows = 9999
print("5 row print cap for df with more than", pd.options.display.max_rows, "rows")


# ------------------------------------------------JSON----------------------------------------
df = pd.read_json("data/data.json")
# df.to_json("data/data.json", indent=2)

data = {
    "Duration":{"9":60,"1":60,"2":60,"3":45,"4":45,"5":60},
    "Pulse":{"0":110,"1":117,"2":103,"3":109,"4":117,"5":102},
    "Maxpulse":{"0":130,"1":145,"2":135,"3":175,"4":148,"5":127},
    "Calories":{"0":409,"1":479,"2":340,"3":282,"4":406,"5":300}
}

# from python dicionary
df = pd.DataFrame(data)

print(df.head())                            #default row number 5
print(df.tail())                            #default row number 5
print("\nFirst 3 rows :", df.head(3))
print("\Last 3 rows \n:", df.tail(3))


# --------------------------------------ANALYZE DATA----------------------------------------
df = pd.read_json("data/data.json")
print("\nDF information:", df.info())
