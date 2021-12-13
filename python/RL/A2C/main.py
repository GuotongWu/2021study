import gym
import torch
import matplotlib.pyplot as plt
from ddpg import Buffer, DDPG, OrnsteinUhlenbeckActionNoise

class Config():
    def __init__(self):
        self.device = torch.device('cuda' if torch.cuda.is_available() else 'cpu')
        self.ep_max = 300
        self.buffer_capacity = 8000
        self.batch_size = 128
        self.actor_hidden_dim = 32
        self.critic_hidden_dim = 64
        self.lr_critic = 0.001
        self.lr_actor = 0.0001
        self.discount = 0.99
        self.tau = 0.01 # 软更新参数

cfg = Config()
print(cfg.device)

env = gym.make('Pendulum-v1')
buffer = Buffer(cfg.buffer_capacity)
ddpg = DDPG(env.observation_space.shape[0], env.action_space.shape[0], cfg)
noisy = OrnsteinUhlenbeckActionNoise(env.action_space.shape[0])

rewards = []

for i in range(1, cfg.ep_max+1):
    state = env.reset()
    done = False
    ep_reward = 0
    while done is not True:
        action = ddpg.choose_action(state)
        action = noisy.set_action(action, env.action_space.low[0], env.action_space.high[0])
        next_state, reward, done, _ = env.step(action)
        buffer.push_buffer((state, action, reward, done, next_state))
        state = next_state
        ddpg.update(buffer)
        ep_reward += reward
    rewards.append(ep_reward)
    if i % 10 == 0:
        print('epoch {}: episode reward = {}'.format(i, ep_reward))

plt.plot(range(len(rewards)), rewards)
plt.show()
plt.savefig("./reward.jpg")

# 存储结果
import os
os.makedirs("./outputs", exist_ok=True)
ddpg.save('./outputs/actor.pt')