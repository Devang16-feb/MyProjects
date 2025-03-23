# Summary of KNN-Based Personal Income Classification  

## **Solution Summary**  
The objective of this case study is to classify individuals' personal income using the **K-Nearest Neighbors (KNN)** algorithm. The dataset consists of income-related features, and the goal is to predict whether an individual's income is greater than or less than **$50,000**.  

## **Steps Followed**  

### **Data Preprocessing:**  
- Loaded the dataset and handled missing values.  
- Removed rows with missing `JobType` and `Occupation` values.  
- Encoded categorical variables using **one-hot encoding**.  
- Converted income labels (`SalStat`) into binary format (0: ≤ 50K, 1: > 50K).  
- Split the dataset into training and testing sets.  

### **Model Implementation:**  
- Used **K-Nearest Neighbors (KNN)** for classification.  
- Trained the model using **K=5**.  
- Evaluated performance using **accuracy score and confusion matrix**.  
- Analyzed misclassified samples.  

### **Effect of K on Classification:**  
- Tested multiple values of **K (1 to 20)** to observe misclassification rates.  

## **Libraries Used:**  
- `pandas` → Data handling  
- `numpy` → Numerical operations  
- `seaborn` → Data visualization  
- `sklearn.model_selection` → Data splitting  
- `sklearn.neighbors` → KNN classification  
- `sklearn.metrics` → Model evaluation (accuracy score & confusion matrix)  

This approach helps in simplifying subsidy allocation by predicting income levels with a well-optimized **KNN model**. 🚀  
