class Instruction:
    SwapA = "sa" 
    SwapB = "sb" 
    SwapS = "ss"
    PushA = "pa" 
    PushB = "pb"
    RotateA = "ra"
    RotateB = "rb"
    RotateR = "rr"
    ReverseRotateA = "rra"
    ReverseRotateB = "rrb"
    ReverseRotateR = "rrr"

class Config:
    n_start_data = 3
    next_step_interval = 2
    upper_n_data = 4e9
