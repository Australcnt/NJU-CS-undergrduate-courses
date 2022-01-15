import numpy as np

def get_data(train=True, corrupt=False):

    if train:
        data_file = 'data/pendigits.tra'
    else:
        data_file = 'data/pendigits.tes'
    
    all_data = np.loadtxt(data_file, dtype=int, delimiter=',')
    inputs, targets = all_data[:, :-1], all_data[:, -1]

    if train and corrupt:
        imb_ratio = 10
        noise_level = 0.3
        
        rs = np.random.RandomState(123)
        
        # get label-noisy data
        train_size = len(inputs)
        idx = np.arange(train_size)
        rs.shuffle(idx)
        num_noise = int(noise_level * train_size)
        noise_idx = idx[:num_noise]

        transition = {0:6, 1:7, 2:3, 3:2, 4:9, 5:8, 6:0, 7:1, 8:5, 9:4}
        for i in noise_idx:
            targets[i] = transition[targets[i]]

        # get class-imbalanced data
        num_cls = 10
        _, cls_num_list = np.unique(targets, return_counts=True)
        max_num = max(cls_num_list)
        imb_cls_num_list = []
        for i in range(num_cls):
            size = int(max_num / (imb_ratio ** (i / (num_cls - 1))))
            size = min(size, cls_num_list[i])
            imb_cls_num_list.append(size)
        # print('cls num list:', imb_cls_num_list)

        all_idx = []
        for i in range(num_cls):
            idx = np.where(targets == i)[0]
            rs.shuffle(idx)
            selec_idx = idx[:imb_cls_num_list[i]]
            all_idx.extend(selec_idx)
        all_idx.sort()
        inputs, targets = inputs[all_idx], targets[all_idx]

        # save corrupted training data
        data_file = 'data/pendigits-corrupted.tra'
        all_data = np.hstack([inputs, targets.reshape(-1, 1)])
        np.savetxt(data_file, all_data, fmt='%3d', delimiter=',')

    return inputs, targets
    