from tqdm import tqdm
import numpy as np
from push_swap.config import Config

class Trainer:
    def __init__(self, model, generator):
        self.model = model
        self.generator = generator

    def fit(self):
        loss_history = []
        reward_history = []
        for e in range(Config.episodes):
            env = self.generator()
            state = env.reset()
            total_loss, cnt = 0, 0

            done = False
            while not done:
                action = agent.get_action(state.to_vector())
                next_state, reward, done = env.step(action)
                next_state = one_hot(next_state)

                loss = agent.update(state, action, reward, next_state, done)
                total_reward += reward
                total_loss += loss
                cnt += 1
                state = next_state
            average_loss = total_loss / cnt
            average_reward = reward_loss / cnt
            loss_history.append(average_loss)
            reward_history.append(average_reward)

    def evaluate(self):
        self.model.eval()
        all_rewards = []
        for e in tqdm(range(Config.n_eval_episodes)):
            state = self.generator()
            solution = self.model.solve(init_state)
            all_rewards.append(solution.reward())
        rewards = np.mean(all_rewards)
        print(f"eval rewards: {rewards}")
