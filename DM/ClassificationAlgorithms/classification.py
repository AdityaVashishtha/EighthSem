import csv
import numpy as np
from sklearn import model_selection
from sklearn.metrics import accuracy_score
from sklearn.tree import DecisionTreeClassifier
from sklearn.naive_bayes import GaussianNB

iris_data = []
x_data = []
print("Loading data ...")
with open('iris.csv', 'r') as f:
  reader = csv.reader(f)
  iris_data = list(reader)
iris_data = iris_data[1:]
data = np.array(iris_data)
x_data = data[:,0:4]
y_data = data[:,4]
x_data = np.array(x_data).astype('float')

print("Dataset ...")
print(x_data[:3])
print(y_data[:3])
X_train, X_validation, Y_train, Y_validation = model_selection.train_test_split(x_data, y_data, test_size=0.3, random_state=7)

print("Fitting DecisionTree model ...")
decisionTree=DecisionTreeClassifier()
decisionTree.fit(X_train, Y_train)
result = decisionTree.score(X_validation, Y_validation)
print("Decision tree accuraccy is:", (result*100))

print("Fitting NaiveBayes model ...")
naiveBayes=GaussianNB()
naiveBayes.fit(X_train, Y_train)
result = naiveBayes.score(X_validation, Y_validation)
print("Naive Bayes accuraccy is:", (result*100)) 
