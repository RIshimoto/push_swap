from ..config import Config
from .simulator import PushSwap
import random

class Generator:
    def __init__(self):
        self.n_data = Config.n_start_data

    def _generate_data(self):
        data = random.sample(list(range(-self.n_data, self.n_data)), k=self.n_data)
        random.shuffle(data)
        return data

    def __call__(self):
        generated_data = self._generate_data()
        return PushSwap(generated_data)

    def next_step(self):
        """Take the next step in learning curriculum"""
        self.n_data += self.next_step_interval
        self.n_data = min(self.n_data, Config.upper_n_data)
