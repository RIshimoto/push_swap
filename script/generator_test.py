from push_swap.sim.generator import Generator
import argparse

if __name__ == '__main__':
    parser = argparse.ArgumentParser(description='Generate datas')
    parser.add_argument("--n_data", "-n", type=int, default=5)

    args = parser.parse_args()
    n_data = args.n_data
    generator = Generator()
    for i in range(n_data):
        # print(f"--- loop_{i} ---")
        print(generator._generate_data())

