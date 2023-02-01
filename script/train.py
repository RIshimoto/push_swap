from push_swap.rl.dqn import DQN
from push_swap.sim.generator import Generator
import argparse

if __name__ == '__main__':
    parser = argparse.ArgumentParser(description='Trainer')

    args = parser.parse_args()
    agent = DQN()
    generator = Generator()
    
    trainer = Trainer(agent, generator)
    trainer.fit()
    trainer.evaluate()
