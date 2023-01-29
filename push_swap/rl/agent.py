from push_swap import PushSwap

if __name__ == '__main__':
    env = PushSwap([2, 4, 3, 1])
    actions = ["sa", "rra", "sa", "ra"]
    done = False
    for action in actions:
        next_state, reward, done = env.step(action)
        if done is True:
            break
        state = next_state
