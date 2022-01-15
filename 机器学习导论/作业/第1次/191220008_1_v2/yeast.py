import pandas as pd
from sklearn.model_selection import train_test_split
from sklearn.linear_model import LogisticRegression
from sklearn.multiclass import OneVsOneClassifier
from sklearn.multiclass import OneVsRestClassifier
#from sklearn.model_selection import cross_val_score
from sklearn.preprocessing import StandardScaler
from sklearn.preprocessing import LabelEncoder
from sklearn import metrics

names = ['Sequence Name', 'mcg', 'gvh', 'alm', 'mit', 'erl', 'pox', 'vac', 'nuc', 'class']
yeast = pd.read_csv('yeast.data', delim_whitespace=True, names=names)
#print(yeast)
#print(yeast.shape)

X = yeast[names[:-1]] # 获得其特征向量
y = yeast[names[-1]] # 获得样本label

le = LabelEncoder()
for column in X.columns:
    X[column] = le.fit_transform(X[column])
    break
y = le.fit_transform(y)
#print(X)
#print(y)

#X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.3, random_state=7)
X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.3, random_state=7, stratify=y)
#print(X_train)
#print(y_train)


# 定义逻辑回归模型
'''
model = LogisticRegression(penalty='l2', dual=False, tol=0.0001, C=1.0,
    fit_intercept=True, intercept_scaling=1, class_weight=None,
    random_state=None, solver='liblinear', max_iter=100, multi_class='ovr',
    verbose=0, warm_start=False, n_jobs=1)
'''
model = LogisticRegression(penalty='l2', multi_class='multinomial', solver='newton-cg')
model = OneVsOneClassifier(model)
#model = OneVsRestClassifier(model)
#model = LogisticRegression(penalty='l2', multi_class='ovr')
#model = LogisticRegression(penalty='l2', multi_class='multinomial')

#cross_val_score(model, X, y=None, scoring=None, cv=None, n_jobs=1)

ss = StandardScaler()
X_train = ss.fit_transform(X_train)
X_test = ss.transform(X_test)

model.fit(X_train, y_train)
#X_test=X_train
#y_test=y_train
predict = model.predict(X_test)

accuracy = metrics.accuracy_score(y_test, predict)
print('accuracy: %.2f%%' % (100 * accuracy))

precision_1 = metrics.precision_score(y_test, predict, average='macro', zero_division=0)
precision_2 = metrics.precision_score(y_test, predict, average='micro', zero_division=0)
print('precision(宏平均): %.2f%%, precision(微平均): %.2f%%' % (100 * precision_1, 100 * precision_2))

recall_1 = metrics.recall_score(y_test, predict, average='macro', zero_division=0)
recall_2 = metrics.recall_score(y_test, predict, average='micro', zero_division=0)
print('recall(宏平均): %.2f%%, recall(微平均): %.2f%%' % (100 * recall_1, 100 * recall_2))

f1_1 = metrics.f1_score(y_test, predict, average='macro', zero_division=0)
f1_2 = metrics.f1_score(y_test, predict, average='micro', zero_division=0)
print('f1(宏平均): %.2f%%, f1(微平均): %.2f%%' % (100 * f1_1, 100 * f1_2))

cohen_kappa = metrics.cohen_kappa_score(y_test, predict)
print('cohen kappa: ', cohen_kappa)

confusion_matrix = metrics.confusion_matrix(y_test, predict, labels=[0,1,2,3,4,5,6,7,8,9])
print('confusion matrix:\n', confusion_matrix)

classification_report = metrics.classification_report(y_test, predict, zero_division=0)
print('classification report:\n', classification_report)