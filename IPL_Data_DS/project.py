import numpy
import pandas 
import sklearn
import numpy as np
import pandas as pd

df= pd.read_csv(r"C:\Users\devan\OneDrive\Desktop\Data Scienec Workshop\IPL Data (1).csv")
df.head()
df.tail()
df.info()
df.describe().T
df.columns
col=["mid","date","batsman","striker","non-striker","bowler"]
df.shape
df.drop(labels=col,axis=1,inplace=True)
df.head()
df.duplicated().sum()

