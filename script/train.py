from push_swap.rl.dqn import DQN
from push_swap.sim.generator import Generator
from push_swap.config import Config
import argparse
from tqdm import tqdm
import numpy as np

def evaluate(agent):
    agent.eval()
    generator = Generator()
    all_rewards = []
    for e in tqdm(range(Config.n_eval_episodes)):
        state = generator()
        solution = agent.solve(init_state)
        all_rewards.append(solution.reward())
    rewards = np.mean(all_rewards)
    print(f"eval rewards: {rewards}")


if __name__ == '__main__':
    parser = argparse.ArgumentParser(description='Generate datas')
    parser.add_argument("--dqn", action='store_ture')

    args = parser.parse_args()
    generator = Generator()
    if args.dqn:
        agent = DQN()
    agent.train()
    evaluate(agent)
