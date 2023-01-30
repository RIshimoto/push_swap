from push_swap.sim.generator import Generator
from push_swap.sim.simulator import PushSwap
from push_swap.config import Instruction
import argparse
import numpy as np

if __name__ == '__main__':
    parser = argparse.ArgumentParser()
    parser.add_argument("-n_episodes", "-n", type=int, default=10)

    args = parser.parse_args()
    episodes = args.n_episodes
    generator = Generator()
    for e in range(episodes):
        env = generator()
        done = False
        print(f"episode:{e}")
        while not done:
            action = np.random.choice([Instruction.SwapA,
                                       Instruction.SwapB, 
                                       Instruction.SwapS,
                                       Instruction.PushA, 
                                       Instruction.PushB,
                                       Instruction.RotateA,
                                       Instruction.RotateB,
                                       Instruction.RotateR,
                                       Instruction.ReverseRotateA,
                                       Instruction.ReverseRotateB,
                                       Instruction.ReverseRotateR])
            action = str(action)
            next_state, reward, done = env.step(action)
            print(next_state)
