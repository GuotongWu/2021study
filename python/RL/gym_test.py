import gym
env = gym.make('CartPole-v0')
env.reset()
done = False
while not done:
    env.render()
    observation, reward, done, _ = env.step(env.action_space.sample())
env.close()