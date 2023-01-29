#include "../../includes/stack.h"
#include <termios.h>

struct termios state, oldstate;

#define clr		printf("\033[2J") //画面クリア
#define clr_right	printf("\033[0K") //カーソル位置からその行の右端までをクリア
#define clr_left	printf("\033[1K") //カーソル位置からその行の左端までをクリア
#define clr_line	printf("\033[2K") //カーソル位置の行をクリア
#define clr_pos		printf("\033[6n") //カーソル位置の行をクリア
#define location(x,y)	printf("\033[%d;%dH" ,x,y) //カーソル位置を移動
#define right(x)	printf("\033[%dC" ,x) //カーソルを指定数だけ右に移動
#define left(x)		printf("\033[%dD" ,x) //カーソルを指定数だけ左に移動
#define down(x)		printf("\033[%dB" ,x) //カーソルを指定数だけ下に移動
#define up(x)		printf("\033[%dA" ,x) //カーソルを指定数だけ上に移動

static void put(void *content)
{
	int *v = content;
	ft_putchar_fd(' ', 1);
	ft_putnbr_fd(*v, 1);
}

void stk_print(char *s, t_stack this)
{
	ft_putstr_fd(s, 1);
	ft_lstiter(this->next, put);
	ft_putstr_fd("\n", 1);
}

typedef struct s_pos
{
	int x;
	int y;
}			t_pos;

void echo_off(void)
{
	tcgetattr(0, &oldstate);
	state = oldstate;
	state.c_lflag &= ~(ICANON | ECHO);
	tcsetattr(0, TCSANOW, &state);
}

void echo_on(void)
{
	tcsetattr(0, TCSANOW, &oldstate);
}

t_pos get_cursorpos(void)
{
	char c;
	int n;
	t_pos p;

	echo_off();

	write(0,"\x1b[6n",4);
	n = 0;
	while(1)
	{
		read(0,&c,1);
		if(c >= '0' && c <= '9')
			n = n * 10 + (c - '0');	
		if(c == ';') 
		{
			p.x = n;
			n = 0;
		}
		if(c == 'R') break;
	}
	p.y = n;
	echo_on();
	return (p);
}

void animation(t_stack a, t_stack b)
{
	//location(20, 10);
	stk_print("a|", a);
	stk_print("b|", b);
	(void)getchar();
}
