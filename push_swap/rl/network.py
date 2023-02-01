import torch.nn as nn

class Network(nn.Module):
    def __init__(self, output_size):
        super(Network, self).__init__()
        self.encode_layer = nn.TransformerEncoderLayer(d_model=512, head=8)
    
    def forward(self, x):
        return x
