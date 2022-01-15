from sklearn.metrics import roc_curve, auc
import matplotlib.pyplot as plt
 
y_label = ([2, 1, 2, 2, 2, 1, 1, 2])  # 非二进制需要pos_label
y_pre = ([0.62, 0.39, 0.18, 0.72, 0.45, 0.01, 0.32, 0.93])
#y_pre = ([0.34, 0.12, 0.82, 0.89, 0.17, 0.75, 0.36, 0.97])
fpr, tpr, thersholds = roc_curve(y_label, y_pre, pos_label=2)
 
for i, value in enumerate(thersholds):
    print("%f %f %f" % (fpr[i], tpr[i], value))
 
roc_auc = auc(fpr, tpr)
 
plt.figure()
plt.figure(figsize=(10,10))
plt.plot(fpr, tpr, color='green', label='AUROC = %0.4f' % roc_auc) ###假正率为横坐标，真正率为纵坐标做曲线
plt.plot([0, 1], [0, 1], color='navy', linestyle='--')
plt.xlim([-0.05, 1.05])
plt.ylim([-0.05, 1.05])
plt.xlabel('FPR')
plt.ylabel('TPR')
plt.title('ROC curve')
plt.legend(loc="lower right")
plt.show()