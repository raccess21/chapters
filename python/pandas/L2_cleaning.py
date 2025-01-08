import pandas as pd
import os

os.system("cls")
# Data Cleaning

# Data cleaning means fixing bad data in your data set.

# Bad data could be:

#     Empty cells
#     Data in wrong format
#     Wrong data
#     Duplicates

# --------------------------------------NULL DATA----------------------------------------
df = pd.read_json("data/null_clean.json")
print("\nDF information:", df.info())


# clean empty cells
newdf = df.dropna()                 #returns new dataframe without empty cells
df.dropna(inplace=True)             #modifies original dataframe

# replace null values
df.fillna(0, inplace=True)

# old
# # replace null values in specific columns
# df["Calories"].fillna(0, inplace=True)
# df[["Calories", "Duration"]].fillna(0, inplace=True)

# # replace null values by mean, mode or median
# df["Calories"].fillna(df["Calories"].mean(), inplace=True)
# df["Calories"].fillna(df["Calories"].mode(), inplace=True)
# df["Calories"].fillna(df["Calories"].median(), inplace=True)

# new
# replace null values in specific columns
df.fillna({"Calories": 0}, inplace=True)
df.fillna({"Calories": 0, "Duration": 0}, inplace=True)

# replace null values by mean, mode or median
df.fillna({"Calories": df["Calories"].mean()}, inplace=True)
df.fillna({"Calories": df["Calories"].mode()}, inplace=True)
df.fillna({"Calories": df["Calories"].median()}, inplace=True)


# --------------------------------------WRONG DATA TYPE----------------------------------------
df = pd.read_json("data/wrong_data.json")

# cleaning wrong format data type in date yyyymmdd instead of yyyy/mm/dd 
df["Date"] = pd.to_datetime(df["Date"])
df.dropna(subset=["Date"], inplace=True)

# cleaning wrong data value in duration 50's instead 500's
df.loc[7, "Duration"] = 45

for index in df.index:
    if df["Duration"][index] > 120:
        df["Duration"][index] = 45


# --------------------------------------DUPLICATES----------------------------------------
print("\nDuplicate rows in data at row: ", df.duplicated())
df.drop_duplicates(inplace=True)
