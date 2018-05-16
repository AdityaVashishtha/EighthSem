import csv
import numpy as np
from sklearn import model_selection
from sklearn.metrics import accuracy_score
from sklearn import cluster
import numpy.random as random
from sklearn.cluster import KMeans
import numpy as np
import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D

iris_data = []
x_data = []
print("Loading data ...")
with open('iris.csv', 'r') as f:
  reader = csv.reader(f)
  iris_data = list(reader)
labels = np.array(iris_data[0])
print(labels)
iris_data = iris_data[1:]
data = np.array(iris_data)
x_data = data[:,0:4]
y_data = data[:,4]
x_data = np.array(x_data).astype('float')
print("Dataset ...")
print(x_data[:3])
print(y_data[:3])
X_train, X_validation, Y_train, Y_validation = model_selection.train_test_split(x_data, y_data, test_size=0.3, random_state=7)
kmeans = KMeans(n_clusters=3, random_state=0).fit(X_train)
labels = kmeans.labels_
clusterCenter = kmeans.cluster_centers_
print("Cluster Centers ..")
print(clusterCenter)
plt.subplot(221)
plt.scatter(X_train[:,0:1],X_train[:,1:2],c=labels,alpha=0.5)
plt.xlabel('sepal_length')
plt.ylabel('sepal_width')
plt.subplot(222)
plt.scatter(X_train[:,2:3],X_train[:,3:4],c=labels,alpha=0.5)
plt.xlabel('petal_length')
plt.ylabel('petal_width')
plt.subplot(223)
plt.scatter(X_train[:,0:1],X_train[:,2:3],c=labels,alpha=0.5)
plt.xlabel('sepal_length')
plt.ylabel('petal_width')
plt.subplot(224)
plt.scatter(X_train[:,1:2],X_train[:,3:4],c=labels,alpha=0.5)
plt.xlabel('sepal_width')
plt.ylabel('petal_width')
plt.show()