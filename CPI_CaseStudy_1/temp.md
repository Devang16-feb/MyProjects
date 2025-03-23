# Problem Statement

- "Subsidy Inc. delivers subsidies to individuals based on their income."
- Accurate income data is one of the hardest pieces of data to obtain across the world.
- Subsidy Inc. has obtained a large dataset of authenticated data on individual income, demographic parameters, and a few financial parameters.
- Subsidy Inc. wishes us to:
  - Develop an income classifier system for individuals.

## The Objective:
Simplify the data system by reducing the number of variables to be studied, without sacrificing too much accuracy.  
Such a system would help **Subsidy Inc.** in planning subsidy outlay, monitoring, and preventing misuse.

# Solution Summary

- **Preprocessed the dataset**  
  - Handled missing values  
  - Encoded categorical features  
  - Standardized numerical data  

- **Performed feature selection**  
  - Used feature importance from RandomForest  

- **Implemented an income classifier**  
  - Used `RandomForestClassifier`  

- **Evaluated model performance**  
  - Checked accuracy and generated a classification report  

- **Visualized important features**  
  - Identified key factors influencing income classification  

---

# Libraries Used

- `pandas` – Data handling  
- `numpy` – Numerical operations  
- `matplotlib` & `seaborn` – Data visualization  
- `sklearn.model_selection` – Train-test split  
- `sklearn.preprocessing` – Feature scaling & encoding  
- `sklearn.ensemble` – RandomForestClassifier for classification  
- `sklearn.metrics` – Model evaluation  

