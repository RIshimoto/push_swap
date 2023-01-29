from setuptools import setup, find_packages

setup(
    name='push_swap',
    version='1.0.0',
    packages=find_packages(),
    include_package_data=True,
    install_requires=[],
    entry_points="""
        [console_scripts]
        run = push_swap:main
        clean = push_swap:clean
        fclean = push_swap:fclean
    """,
)
