import subprocess

def rebuild():
    subprocess.run("make fclean -C ./push_swap/sim", shell=True)
    subprocess.run("make all -C ./push_swap/sim", shell=True)

def clean():
    subprocess.run("make fclean -C ./push_swap/sim", shell=True)

def main():
    subprocess.run("make all -C ./push_swap/sim", shell=True)

