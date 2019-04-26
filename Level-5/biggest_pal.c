/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   biggest_pal.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: slopez <slopez@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/26 23:17:08 by slopez       #+#   ##    ##    #+#       */
/*   Updated: 2019/04/26 23:24:24 by slopez      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <unistd.h>

typedef struct	s_pal
{
	int			begin;
	int			end;
	int			size;
}				t_pal;

void			biggest_pal(char *str)
{
	t_pal	pal;
	int		i;
	int		j;
	int		t;
	int		b;
	
	pal = (t_pal){.begin = 0, .end = 0, .size = 0};
	j = 0;
	i = 0;
	while (str[i])
	{
		j = 1;
		t = i;
		b = 0;
		while (str[t])
		{
			if (str[t] == str[i] && str[t + 1] == str[i])
				b++;
			t++;
		}
		while (str[i + j + b] == str[i - j])
		{
			if ((i + j + b) - (i - j) > pal.size)
			{
				pal.end = (i + j + b);
				pal.begin = (i - j >= 0) ;
				pal.size = pal.end - pal.begin;
			}
			j++;
		}
		i++;
	}
	pal.end -= pal.end < i ? 0 : 1;
	while (pal.begin <= pal.end)
		write(1, str + pal.begin++, 1);
	write(1, "\n", 1);
}

int main(int ac, char *av[])
{
	if (ac != 2)
	{
		write(1, "\n", 1);
		return (0);
	}
	biggest_pal(av[1]);
	return (0);
}