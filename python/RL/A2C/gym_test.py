import gym
import random
import time

env = gym.make('Pendulum-v1')

print(env.observation_space)
print(env.action_space)

env.reset()
for _ in range(100):
    ob, ew, done, _ = env.step(env.action_space.sample())
    env.render()
    time.sleep(0.1)

env.close()