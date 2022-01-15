import numpy as np
import pandas as pd
from sklearn.preprocessing import StandardScaler
from sklearn.svm import SVC
from imblearn.over_sampling import SMOTE
from imblearn.under_sampling import RandomUnderSampler
from imblearn.combine import SMOTEENN

# 数据集导入
names = list('input{}'.format(i) for i in range(1, 65))
names.append('class')

ds_train = pd.read_csv('anonymous.tra', names=names)
input_train = ds_train[names[:-1]]
target_train = ds_train[names[-1]]
input_train = np.array(input_train)
target_train = np.array(target_train)

ds_test = pd.read_csv('anonymous.tes', names=names[:-1])
input_test = ds_test[names[:-1]]
input_test = np.array(input_test)

# 数据集标准化
#input_train = StandardScaler().fit_transform(input_train)
#input_test = StandardScaler().fit_transform(input_test)

# 样本类别不平衡处理
#input_train, target_train = SMOTE(random_state=14).fit_resample(input_train, target_train)
#input_train, target_train = RandomUnderSampler(random_state=14).fit_resample(input_train, target_train)
#input_train, target_train = SMOTEENN(random_state=14).fit_resample(input_train, target_train)

# 模型训练
model = SVC(kernel='rbf', decision_function_shape='ovr', random_state=14, class_weight='balanced')
model.fit(input_train, target_train)

# 输出预测结果
output = model.predict(input_test)
pd.DataFrame(output).to_csv("output_191220008.txt", index=None, header=None)
