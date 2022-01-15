```python
from data_utils import *

# original training data
train_inputs, train_targets = get_data(train=True)

# corrupted training data
train_inputs, train_targets = get_data(train=True, corrupt=True)

# test data
test_inputs, test_targets = get_data(train=False)
```

