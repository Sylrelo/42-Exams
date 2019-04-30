/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   biggest_pal.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: slopez <slopez@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/26 23:17:08 by slopez       #+#   ##    ##    #+#       */
/*   Updated: 2019/04/30 16:30:32 by slopez      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <unistd.h>

typedef	struct s_pal
{
	int			begin;
	int			size;
}				t_pal;

void			biggest_pal(char *str)
{
	t_pal pal;
	int		i;
	int		j;
	int		k;
	
	i = -1;
	pal = (t_pal){.begin = 0, .size = 0};
	while (str[++i])
	{
		j = 0;
		k = 1;
		while (str[i] == str[k + i])
			k++;
		if (k >= pal.size)
			pal = (t_pal) {.begin = i, .size = k};
		while (++j &&  str[i + j + k - 1] && str[i - j] && str[i + j + k - 1] == str[i - j])
			if (2 * j + k >= pal.size)
				pal = (t_pal) {.begin = i - j, .size = 2 * j + k};
	}
	write(1, str + pal.begin, pal.size);
}

int main(int ac, char *av[])
{
	if (ac == 2)
		biggest_pal(av[1]);
	write(1, "\n", 1);
	return (0);
}
