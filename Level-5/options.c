/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   options.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: slopez <slopez@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/23 09:27:10 by slopez       #+#   ##    ##    #+#       */
/*   Updated: 2019/04/26 23:34:15 by slopez      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

# include <unistd.h>

int	main(int ac, char *av[])
{
	char	str[32];
	int 	i;
	int		j;

	i = -1;
	while (++i < 32)
		str[i] = '0';
	i = 0;
	if (ac == 1)
	{
		write(1, "options: abcdefghijklmnopqrstuvwxyz\n", 36);
		return (0);
	}
	while (++i < ac)
	{
		j = 0;
		if (av[i][0] == '-' && av[i][1])
		{
			while (av[i][++j])
			{
				if (av[i][j] == 'h')
				{
					write(1, "options: abcdefghijklmnopqrstuvwxyz\n", 36);
					return (0);
				}
				else if (av[i][j] >= 'a' && av[i][j] <= 'z')
					str[av[i][j] - 'a'] = '1';
				else
				{
					write(1, "Invalid Option\n", 15);
					return (0);
				}
			}
		}
	}
	i = 32;
	while (i--)
	{
		write(1, i + str, 1);
		if (i % 8 == 0)
			if (i != 0)
				write(1, " ", 1);
	}
	write(1, "\n", 1);
}