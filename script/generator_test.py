from push_swap.sim.generator import Generator
import argparse

if __name__ == '__main__':
    parser = argparse.ArgumentParser()
    parser.add_argument("-n_data", "-n", type=int, default=10)

    args = parser.parse_args()
    n_data = args.n_data
    generator = Generator()
    for _ in range(n_data):
        data = generator._generate_data()
        print(data)
