import torch
import torch.nn as nn
import torch.nn.functional as F

class Actor(nn.Module):
    def __init__(self, n_state, n_action, n_hidden):
        super(Actor, self).__init__()
        self.fc1 = nn.Linear(n_state, n_hidden)
        self.fc2 = nn.Linear(n_hidden, n_hidden)
        self.fc3 = nn.Linear(n_hidden, n_action)

    def forward(self, state):
        x = F.relu(self.fc1(state))
        x = F.relu(self.fc2(x))
        return 2 * torch.tanh(self.fc3(x)) # action = [0,1]

class Critic(nn.Module):
    def __init__(self, n_state, n_action, n_hidden):
        super(Critic, self).__init__()
        self.fc1 = nn.Linear(n_state+n_action, n_hidden)
        self.fc2 = nn.Linear(n_hidden, n_hidden)
        self.fc3 = nn.Linear(n_hidden, 1)        

    def forward(self, state, action):
        x = torch.cat((state, action), dim=1)
        x = F.relu(self.fc1(x))
        x = F.relu(self.fc2(x))
        return self.fc3(x)

if __name__ == '__main__':
    a = Actor(5, 2, 128)
    c = Critic(5, 2, 128)
    ob_rand = torch.rand(16, 5)
    act_rand = torch.rand(16, 2)
    print(a(ob_rand).shape)
    print(c(ob_rand, act_rand).shape)