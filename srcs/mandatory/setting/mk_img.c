#include	"../../../includes/cub3D.h"
#include	"../../../includes/setting.h"
#include	"../../../libft/libft.h"

#include "debug.h"

int mk_img(void *img, unsigned int *dst)
{
	unsigned char	*d;
	int				i[3];
	size_t			x;
	size_t			y;

	d = mlx_get_data_addr(img, i + BITS_PER_PIXEL, i + SIZE_LINE, i + ENDIAN);
	x = 0;
	while (x < BL)
	{
		y = 0;
		while (y < BL)
		{
			*dst = get_pic(d, x, y, i);
			dst++;
			y++;
		}
		x++;
	}
	return (0);
}

unsigned int 	get_pic(unsigned char *img, size_t x, size_t y, int *i)
{
	unsigned int *img_i;

	img_i = img + (y * i[SIZE_LINE] + x * (i[BITS_PER_PIXEL] / 8));
	return (*img_i);
}