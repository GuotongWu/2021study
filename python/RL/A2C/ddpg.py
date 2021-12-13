from collections import deque

from torch._C import _add_docstr
from a2c import Actor, Critic
import random
import torch
import numpy as np
import torch.optim as optim
import matplotlib.pyplot as plt

class Buffer():
    def __init__(self, capacity):
        self.q = deque(maxlen=capacity)

    def push_buffer(self, record):
        self.q.append(record)

    def sample(self, batch_size):
        batch = random.sample(self.q, batch_size)
        state, action, reward, done, next_state = zip(*batch)  
        return state, action, reward, done, next_state

    def getlen(self):
        return len(self.q)


class DDPG():
    def __init__(self, n_state, n_action, cfg):
        self.cfg = cfg
        self.actor = Actor(n_state, n_action, cfg.actor_hidden_dim).to(cfg.device)
        self.critic = Critic(n_state, n_action, cfg.critic_hidden_dim).to(cfg.device)
        self.target_actor = Actor(n_state, n_action, cfg.actor_hidden_dim).to(cfg.device)
        self.target_critic = Critic(n_state, n_action, cfg.critic_hidden_dim).to(cfg.device)
        self.actor_optim = optim.Adam(self.actor.parameters(), lr=cfg.lr_actor)
        self.critic_optim = optim.Adam(self.critic.parameters(), lr=cfg.lr_critic)

        for param , target_param in zip(self.actor.parameters(), self.target_actor.parameters()):
            target_param.data.copy_(param.data)
        for param , target_param in zip(self.critic.parameters(), self.target_critic.parameters()):
            target_param.data.copy_(param.data)

    def choose_action(self, state):
        state = torch.FloatTensor(state).to(self.cfg.device)
        action = self.actor(state)
        return action.detach().cpu().numpy()

    def update(self, buffer):
        if self.cfg.batch_size > buffer.getlen():
            return
        state, action, reward, done, next_state = buffer.sample(self.cfg.batch_size)
        
        state = torch.FloatTensor(state).to(self.cfg.device)
        action = torch.FloatTensor(action).to(self.cfg.device)
        reward = torch.FloatTensor(reward).unsqueeze(dim=1).to(self.cfg.device)
        done = torch.FloatTensor(done).unsqueeze(dim=1).to(self.cfg.device)
        next_state = torch.FloatTensor(next_state).to(self.cfg.device)

        next_action = self.target_actor(next_state)
        policy_loss = -self.critic(state, self.actor(state)).mean()
        
        expected_value = reward + (1.0 - done) * self.cfg.discount * self.target_critic(next_state, next_action)
        value = self.critic(state, action)
        value_loss = torch.nn.MSELoss()(value, expected_value)

        self.actor_optim.zero_grad()
        policy_loss.backward()
        self.actor_optim.step()

        self.critic_optim.zero_grad()
        value_loss.backward()
        self.critic_optim.step()

        # update target network
        for param, target_param in zip(self.actor.parameters(), self.target_actor.parameters()):
            target_param.data.copy_(
                target_param.data * (1 - self.cfg.tau) + param.data * self.cfg.tau
            )
        
        for param, target_param in zip(self.critic.parameters(), self.target_critic.parameters()):
            target_param.data.copy_(
                target_param.data * (1 - self.cfg.tau) + param.data * self.cfg.tau
            )

    def save(self, path):
        torch.save(self.actor.state_dict(), path)

    def load(self, path):
        self.actor.load_state_dict(torch.load(path))

class OrnsteinUhlenbeckActionNoise():
    def __init__(self, n_action):
        self.theta = 0.15
        self.mu = 0.0
        self.delta = 1
        self.sigma = 0.3
        self.size = (n_action,)
        self.pre_x = np.zeros(self.size)

    def add_noisy(self):
        x = self.pre_x + self.theta * (self.mu - self.pre_x) * self.delta + \
            self.sigma * np.random.normal(size=self.size)
        self.pre_x = x
        return x
        
    def set_action(self, action, low_bound, high_bound): # 将结果固定在action_space定义域中
        x = self.add_noisy()
        action += x
        return np.clip(action, low_bound, high_bound)

if __name__ == "__main__":
    noisy = OrnsteinUhlenbeckActionNoise(1)
    action = np.arange(-2, 2, 0.001)
    action = noisy.set_action(action, -2.0, 2.0)
    plt.plot(range(action.shape[0]), action)
    plt.savefig('nosiy_test.jpg')