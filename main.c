/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 17:48:31 by bebrandt          #+#    #+#             */
/*   Updated: 2024/01/20 11:56:58 by bebrandt         ###   ########.fr       */
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

int	main(void)
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_data	img;

	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 1920, 1080, "Test Hello world!");
	img.img = mlx_new_image(mlx_ptr, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
					&img.endian);
	print_square(&img, 5, 5, 0x00FF0000, 100);
	mlx_put_image_to_window(mlx_ptr, win_ptr, img.img, 0, 0);
	mlx_loop(mlx_ptr);
}
