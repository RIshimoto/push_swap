import torch 
import torch.nn as nn

class IAgent(nn.Module):
    def __init__(self):
        super().__init__()
        self.gamma = Config.gamma
        self.lr = Config.lr
        self.epsilon = Config.epsilon
        self.action_size = Config.action_size 

        self.net = None
        self.optimizer = None

    @abstractmethod
    def get_action(self, state):
        raise NotImplementedError()
    
    @abstractmethod
    def update(self, state, action, reward, next_state, done):
        raise NotImplementedError()
