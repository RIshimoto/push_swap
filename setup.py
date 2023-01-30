from setuptools import setup, find_packages

setup(
    name='push_swap',
    version='1.0.0',
    packages=find_packages(),
    include_package_data=True,
    install_requires=[
        "cython",
        "numpy",
    ],
    entry_points="""
        [console_scripts]
        build = push_swap:main
        rebuild = push_swap:rebuild
        clean = push_swap:clean
    """,
)
