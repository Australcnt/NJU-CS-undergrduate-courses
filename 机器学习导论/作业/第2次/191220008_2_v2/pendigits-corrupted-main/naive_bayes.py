from data_utils import *
import numpy as np
import pandas as pd
import time
from sklearn.preprocessing import StandardScaler
from sklearn.naive_bayes import GaussianNB
from sklearn.metrics import accuracy_score
from sklearn.metrics import classification_report
from imblearn.over_sampling import SMOTE
from imblearn.under_sampling import RandomUnderSampler
from imblearn.combine import SMOTEENN

# 数据集导入
#input_train, target_train = get_data(train=True) # original training data
input_train, target_train = get_data(train=True, corrupt=True) # corrupted training data
input_test, target_test = get_data(train=False) # test data

# 数据集标准化
input_train = StandardScaler().fit_transform(input_train)
input_test = StandardScaler().fit_transform(input_test)

# 样本类别不平衡处理
#input_train, target_train = SMOTE(random_state=14).fit_resample(input_train, target_train)
#input_train, target_train = RandomUnderSampler(random_state=14).fit_resample(input_train, target_train)
#input_train, target_train = SMOTEENN(random_state=14).fit_resample(input_train, target_train)

# 模型训练
begin = time.time()
model = GaussianNB()
model.fit(input_train, target_train)
end = time.time()

# 测试集检验
output = model.predict(input_test)
print('TimeCost: {:.6f}s'.format(end - begin))
print('Accuracy: {:.2f}%'.format(100 * accuracy_score(target_test, output)))
print('Classification Report:\n', classification_report(target_test, output, zero_division=0))
