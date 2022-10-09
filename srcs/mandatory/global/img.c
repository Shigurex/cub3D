#include "../../../includes/structure.h"
#include "../../../includes/cub3D.h"
int    img(unsigned int *dest, t_direction d, size_t col, char *filename)
{
	static void *imgs[4];
	//unsigned int	imgs[4][BL][BL];

	if (filename)
	   imgs[d] = set_img(filename);
	else if (filename == FREE_CONTENT)
	{
		free_imgs(imgs);
		return (1);
	}
	if (!imgs[d])
		return (1);
	if (dest)
		set_col(dest, imgs[d], col);
	return (0);
}

enum 
{
	BITS_PER_PIXEL = 0,
	SIZE_LINE = 1,
	ENDIAN = 2,
};

void    set_col(unsigned int *dest, void *img, size_t col)
{
	unsigned char	*d;
	int				i[3];
	size_t			y;

	d = mlx_get_data_addr(img, i + BITS_PER_PIXEL, i + SIZE_LINE, i + ENDIAN);
	y = 0;
	while (y < BL)
	{
		dest = get_pic(d, col, y, i);
		y++;
	}
	return ;
}

unsigned int 	get_pic(unsigned char *img, size_t x, size_t y, int *i)
{
	unsigned int *img_i;

	img_i = img + (y * i[SIZE_LINE] + x * (i[BITS_PER_PIXEL] / 8));
	return (*img_i);
}