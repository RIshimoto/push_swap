import subprocess

def clean():
    subprocess.run("make clean -C ./push_swap/sim", shell=True)

def fclean():
    subprocess.run("make fclean -C ./push_swap/sim", shell=True)

def main():
    subprocess.run("make all -C ./push_swap/sim", shell=True)
