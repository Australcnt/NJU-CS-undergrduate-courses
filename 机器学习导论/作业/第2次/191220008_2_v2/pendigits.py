import torch
import numpy as np
import torch.nn as nn
import torch.nn.functional as F
import torch.optim as optim
from torchvision import datasets, transforms
from torch.utils.data import Dataset
from torch.utils.data import DataLoader
import pandas as pd
import matplotlib
import matplotlib.pyplot as plt

EPOCHS = 100
LEARNING_RATE = 0.01
INPUT = 16
HIDDEN1 = 32
HIDDEN2 = 64
HIDDEN3 = 32
OUTPUT = 10

class PendigitsNet(nn.Module):
    def __init__(self, n_input, n_hidden1, n_hidden2, n_hidden3, n_output):
        super(PendigitsNet, self).__init__() # 调用父类的初始化函数
        self.f1 = nn.Linear(n_input, n_hidden1)
        self.f2 = nn.Linear(n_hidden1, n_hidden2)
        self.f3 = nn.Linear(n_hidden2, n_hidden3)
        self.f4 = nn.Linear(n_hidden3, n_output)

    def forward(self, x):
        x = self.f1(x)
        x = F.relu(x)
        x = self.f2(x)
        x = F.relu(x)
        x = self.f3(x)
        x = F.relu(x)
        x = self.f4(x)
        x = F.log_softmax(x, dim=1)
        #x = F.softmax(x, dim=1)
        return x

names = list('input{}'.format(i) for i in range(1, 17))
names.append('class')

ds_train = pd.read_csv('pendigits.tra', names=names)
input_train = ds_train[names[:-1]]
target_train = ds_train[names[-1]]
input_train = np.array(input_train)
target_train = np.array(target_train)
#input_train = input_train.tolist()
#input_train = torch.unsqueeze(torch.FloatTensor(input_train), dim=1)
#print(input_train, target_train)
#print(input_train.shape, target_train.shape)

ds_test = pd.read_csv('pendigits.tes', names=names)
input_test = ds_test[names[:-1]]
target_test = ds_test[names[-1]]
input_test = np.array(input_test)
target_test = np.array(target_test)
#input_test = input_test.tolist()
#input_test = torch.unsqueeze(torch.FloatTensor(input_test), dim=1)
#print(input_test.shape, target_test.shape)

model = PendigitsNet(INPUT, HIDDEN1, HIDDEN2, HIDDEN3, OUTPUT)

#criterion = nn.MSELoss
criterion = F.nll_loss

# Adadelta, Adagrad, Adam, Adamax, ASGD, RMSprop, Rprop, SGD
optimizer = torch.optim.Adam(model.parameters(), lr=LEARNING_RATE)

train_loss_list = []
train_acc_list = []
test_loss_list = []
test_acc_list = []

for epoch in range(EPOCHS):
    model.train()
    train_loss = 0
    train_correct = 0
    inputs = torch.from_numpy(input_train.astype(np.float32))
    targets = torch.from_numpy(target_train)
    outputs = model(inputs)
    #outputs = outputs.max(1, keepdim=True)[1]
    train_loss = criterion(outputs, targets)
    #train_loss = train_loss.requires_grad_()

    optimizer.zero_grad()
    train_loss.backward()
    optimizer.step()

    outputs = outputs.max(1, keepdim=True)[1]
    train_correct = outputs.eq(targets.view_as(outputs)).sum().item()

    if (epoch + 1) % 5 == 0:
        print('Training Set: Epoch [{}/{}], Loss: {:.4f}, Accuracy: {}/{} ({:.2f}%)'.format(epoch + 1, EPOCHS, train_loss.item(), train_correct, len(targets), 100. * train_correct / len(targets)))

    train_loss_list.append(train_loss.item())
    train_acc_list.append(100. * train_correct / len(targets))

    model.eval()
    test_loss = 0
    test_correct = 0
    inputs = torch.from_numpy(input_test.astype(np.float32))
    targets = torch.from_numpy(target_test)
    with torch.no_grad():
        outputs = model(inputs)
        #outputs = outputs.max(1, keepdim=True)[1]

        test_loss = criterion(outputs, targets)

        outputs = outputs.max(1, keepdim=True)[1]
        test_correct = outputs.eq(targets.view_as(outputs)).sum().item()

        if (epoch + 1) % 5 == 0:
            print('Testing Set: Epoch [{}/{}], Loss: {:.4f}, Accuracy: {}/{} ({:.2f}%)\n'.format(epoch + 1, EPOCHS, test_loss.item(), test_correct, len(targets), 100. * test_correct / len(targets)))

        test_loss_list.append(test_loss.item())
        test_acc_list.append(100. * test_correct / len(targets))

plt.subplot(121)
plt.plot(range(1, 101, 2), train_loss_list[::2], color='r', linestyle='-', linewidth=0.5, marker='o', markersize=3, label='train')
plt.plot(range(1, 101, 2), test_loss_list[::2], color='skyblue', linestyle='-', linewidth=0.5, marker='o', markersize=3, label='test')
plt.ylim(-0.1, 5.1)
plt.title('Loss')
plt.xlabel('Epoch')
plt.ylabel('Loss')
plt.legend()
#plt.show()

plt.subplot(122)
plt.plot(range(1, 101, 2), train_acc_list[::2], color='r', linestyle='-', linewidth=0.5, marker='o', markersize=3, label='train')
plt.plot(range(1, 101, 2), test_acc_list[::2], color='skyblue', linestyle='-', linewidth=0.5, marker='o', markersize=3, label='test')
plt.ylim(-1, 101)
plt.title('Accuracy')
plt.xlabel('Epoch')
plt.ylabel('Accuracy %')
plt.legend()
plt.show()