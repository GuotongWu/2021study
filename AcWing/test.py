import numpy as np
def deculated_reward(rewards, lambd):
    g = rewards[-1]
    ans = [g]
    for i in range(len(rewards)-1):
	    g = g*lambd + rewards[-i-2]
	    ans.append(g)
    ans.reverse()
    return np.array(ans)

rewards = np.array([1,2,3])
lambd = 0.8

print(type(deculated_reward(rewards, lambd)))