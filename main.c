/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 17:48:31 by bebrandt          #+#    #+#             */
/*   Updated: 2024/01/20 13:16:44 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibx_macos/mlx.h"
#include "libft/libft.h"

typedef struct s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

typedef struct s_vars {
	void	*mlx_ptr;
	void	*win_ptr;
}	t_vars;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	print_square(t_data *img, int start_x, int start_y, int color, int size)
{
	int	max_height;
	int	max_length;
	int	buff_size;
	int	x;
	int	y;

	max_height = start_y + size;
	max_length = start_x + size;
	x = start_x;
	y = start_y;
	buff_size = size;
	while (size-- >= 0)
	{
		my_mlx_pixel_put(img, x, start_y, color);
		x++;
	}
	size = buff_size;
	while (size-- >= 0)
	{
		my_mlx_pixel_put(img, x - 1, y, color);
		y++;
	}
	size = buff_size;
	y = start_y;
	while (size-- >= 0)
	{
		my_mlx_pixel_put(img, start_x, y, color);
		y++;
	}
	ft_printf("%d\n", y);
	size = buff_size;
	x = start_x;
	while (size-- >= 0)
	{
		my_mlx_pixel_put(img, x, y - 1, color);
		x++;
	}
}

void	display_square(t_vars *vars, int color)
{
	t_data	img;

	img.img = mlx_new_image(vars->mlx_ptr, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
					&img.endian);
	print_square(&img, 5, 5, color, 100);
	mlx_put_image_to_window(vars->mlx_ptr, vars->win_ptr, img.img, 0, 0);
}

int	key_hook(int key, void *param)
{
	(void)param;
	ft_printf("%d\n", key);
	if (key == 15)
		display_square((t_vars *)param, 0xFF0000);
	if (key == 5)
		display_square((t_vars *)param, 0x00FF00);
	if (key == 11)
		display_square((t_vars *)param, 0x0000FF);
	return (0);
}

int	main(void)
{
	t_vars	vars;

	vars.mlx_ptr = mlx_init();
	vars.win_ptr = mlx_new_window(vars.mlx_ptr, 1920, 1080, "Heyllo world!");
	mlx_key_hook(vars.win_ptr, &key_hook, &vars);
	mlx_loop(vars.mlx_ptr);
}
