from distutils.core import setup, Extension
from Cython.Build import cythonize

ext = Extension("simulator", 
                sources=["./srcs/simulator.pyx",
                        # libft
                        "./srcs/libft/ft_lstnew.c",
                        "./srcs/libft/ft_lstclear.c",
                        "./srcs/libft/ft_lstlast.c",
                        "./srcs/libft/ft_lstsize.c",
                        "./srcs/libft/ft_lstadd_back.c",
                        "./srcs/libft/ft_lstdelone.c",
                        "./srcs/libft/ft_lstiter.c",
                        "./srcs/libft/ft_dlstnew.c",
                        "./srcs/libft/ft_dlstclear.c",
                        "./srcs/libft/ft_dlstdelone.c",
                        "./srcs/libft/ft_dlstlast.c",
                        "./srcs/libft/ft_dlstadd_back.c",
                        "./srcs/libft/ft_strdup.c",
                        "./srcs/libft/ft_strlen.c",
                        "./srcs/libft/ft_strcmp.c",
                        "./srcs/libft/ft_putnbr_fd.c",
                        "./srcs/libft/ft_putstr_fd.c",
                        "./srcs/libft/ft_putchar_fd.c",
                        "./srcs/libft/ft_memmove.c",
                        "./srcs/libft/ft_memcpy.c",
                        # stack
                        "./srcs/stack/init.c",
                        "./srcs/stack/free.c",
                        "./srcs/stack/push.c",
                        "./srcs/stack/pop.c",
                        "./srcs/stack/size.c",
                        "./srcs/stack/is_empty.c",
                        "./srcs/stack/top.c",
                        "./srcs/stack/print.c",
                        # stacks
                        "./srcs/stacks/stacks_init.c",
                        "./srcs/stacks/stacks_free.c",
                        "./srcs/stacks/stacks_push.c",
                        "./srcs/stacks/stacks_copy.c",
                        "./srcs/stacks/stacks_print.c",
                        "./srcs/checker/checker.c",
                        # insturctions
                        "./srcs/instructions/instructions.c",
                        "./srcs/instructions/read_instructions.c",
                        "./srcs/instructions/get_next_line.c",
                        ])

setup(
    name="simulator", 
    ext_modules=cythonize(ext)
)
