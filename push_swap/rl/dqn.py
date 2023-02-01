import torch 
import torch.nn as nn
import torch.nn.functional as F
from push_swap.rl.interface.agent import IAgent
from push_swap.rl.network import Network

class DQNgent(IAgent):
    def __init__(self):
        super().__init__()
        self.net = Network()
        self.optimizer = nn.optimizer.SGD(self.lr)
        self.optimizer.setup(self.net)

    def get_action(self, state):
        if np.random.rand() < self.epsilon:
            return np.random.choice(self.action_size)
        elif np.random.rand() < self.epsilon:
            qs = self.net()
            return qs.data.argmax()
    
    def update(self, state, action, reward, next_state, done):
        done = int(done)

        next_qs = self.net(next_state)
        next_q = next_qs.max(axis=1)
        next_q.unchain()

        target = reward + (1 - done) * self.gamma * next_q
        qs = self.qnet(state)
        q = qs[:, action]
        loss = F.mean_squared_error(target, q)

        self.qnet.cleargrads()
        loss.backward()
        self.optimizer.update()
        return loss.data
