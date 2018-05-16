import numpy as np
from sklearn.decomposition import PCA
from sklearn import preprocessing
import csv

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

print("Removing missing values")
imputer = preprocessing.Imputer()
imputer.fit(x_data)
x_data = imputer.transform(x_data)

print("Normalizing the data")
norm = preprocessing.MinMaxScaler(feature_range=(0,1))
norm.fit(x_data)
x_data = norm.transform(x_data)

print("Before PCA Operation:: Size and data")
print(np.shape(x_data))
print(x_data[:3])
pca = PCA(n_components=2)
pca.fit(x_data)
print(pca.explained_variance_ratio_)  
print(pca.singular_values_)
x_data = pca.transform(x_data)

print("After PCA Operation:: Size and data")
print(np.shape(x_data))
print(x_data[:3]) 