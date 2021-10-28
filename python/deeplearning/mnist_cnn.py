from numpy.core.numeric import indices
import torch
from torch.utils.data import DataLoader, Dataset
from torchvision import datasets, transforms
import torch.nn as nn
from tqdm import tqdm

train_path = './data/mnist/processed/training.pt'
test_path = './data/mnist/processed/test.pt'

class MyDataset(Dataset):
    def __init__(self, type, path):

        data = torch.load(path)
        self.type = type
        self.feature = data[0]
        self.label = data[1]

        if type in ['train', 'dev']:
            if type == 'train':
                indices = [i for i in range(len(self.feature)) if i%10 != 0]
            else:
                indices = [i for i in range(len(self.feature)) if i%10 == 0]
            self.feature = self.feature[indices, :, :]
        
        print('successfully load {} data, size = {}'.format(type, self.feature.shape))

    def __getitem__(self, index):
        return self.feature[index], self.label[index]
    
    def __len__(self):
        return len(self.feature)

train_dataset = MyDataset('train', train_path)
dev_dataset = MyDataset('dev', train_path)
test_dataset = MyDataset('test', test_path)

config = {'batch_size': 30, 'early_stop': 500, 'n_epoch': 3000}

train_loader = DataLoader(train_dataset, batch_size=config['batch_size'], shuffle=True, num_workers=2)
dev_loader = DataLoader(dev_dataset, batch_size=config['batch_size'], shuffle=True, num_workers=2)
test_loader = DataLoader(test_dataset, batch_size=config['batch_size'], shuffle=False, num_workers=2)

device = 'cuda' if torch.cuda.is_available() else 'cpu'

class Network(nn.Module):
    def __init__(self):
        super(Network, self).__init__()
        self.lossfunc = nn.CrossEntropyLoss()
        self.cnn_layers = nn.Sequential(
            # input = (28, 28, 1)
            nn.Conv2d(1, 64, 3, 1, 1),
            nn.BatchNorm2d(64),
            nn.ReLU(),
            nn.MaxPool2d(2, 2, 0),

            # (14, 14, 64)
            nn.Conv2d(1, 128, 3, 1, 1),
            nn.BatchNorm2d(128),
            nn.ReLU(),
            nn.MaxPool2d(2, 2, 0),
        )
        self.fc_layers = nn.Sequential(
            nn.Linear(7*7*128, 256),
            nn.ReLU(),
            nn.Linear(256, 256),
            nn.ReLU(),
            nn.Linear(256, 10),
        )

    def forward(self, x):
        x = self.cnn_layers(x)
        x = nn.Flatten(1),
        x = self.fc_layers(x)
        return x

    def cal_loss(self, pred, y):
        r_loss = 0
        for param in model.parameters():
            r_loss += torch.sum(param**2)
        return self.lossfunc(pred, y) + r_loss

model = Network().to(device)

optimizer = torch.optim.Adam(model.parameters(), lr=0.0003, weight_decay=1e-5)

for x, y in train_loader:
    print(x.shape, y.shape)

exit()

for epoch in range(config['n_epoch']):
    model.train()
    train_loss = []
    train_accs = []
    for x, y in tqdm(train_loader):
        x, y = x.to(device), y.to(device)
        pred = model(x)
        loss = model.cal_loss(pred, y)
        optimizer.zero_grad()
        loss.backward()
        optimizer.step()

        acc = (pred.argmax() == y).float().mean()
        train_accs.append(acc)
        train_loss.append(loss.item())
    print('epoch {}: train_accs = {}, train_loss = {}'.format(epoch, train_accs.sum()/len(train_accs), train_loss.sum()/len(train_loss)))

    dev_loss = []
    dev_accs = []
    model.eval()
    for x, y in dev_loader:
        with torch.no_grad():
            x, y = x.to(device), y.to(device)
            pred = model(x)
            loss = model.cal_loss(pred, y)
            
            acc = (pred.argmax() == y).float().mean()
            dev_accs.append(acc)
            dev_loss.append(loss.item())
    print('epoch {}: dev_accs = {}, dev_loss = {}'.format(epoch, dev_accs.sum()/len(dev_accs), dev_loss.sum()/len(dev_loss)))
