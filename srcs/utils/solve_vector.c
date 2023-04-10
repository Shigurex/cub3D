#include "define.h"
#include <math.h>

t_pos   sVA_p_tVB_e_VC(t_pos va, t_pos  vb, t_pos  vc)
{
    double  matrix[6];
    t_pos   r;

    matrix[0] = va.x;
    matrix[1] = vb.x;
    matrix[2] = vc.x;
    matrix[3] = va.y;
    matrix[4] = vb.y;
    matrix[5] = vc.y;
    Gaussian_elimination(matrix, 3, 2);
    r.x = matrix[2];
    r.y = matrix[5];
    return (r);
}

t_pos   VA_p_sVB_e_tVC(t_pos va, t_pos  vb, t_pos  vc)
{
    double  matrix[6];
    t_pos   r;

    matrix[0] = vb.x;
    matrix[1] = -vc.x;
    matrix[2] = -va.x;
    matrix[3] = vb.y;
    matrix[4] = -vc.y;
    matrix[5] = -va.y;
    Gaussian_elimination(matrix, 3, 2);
    r.x = matrix[2];
    r.y = matrix[5];
    return (r);
}

t_direction vector_to_8direction(t_pos v)
{
	double  gradient;

	gradient = v.y / v.x;
	if (gradient >= tan(-0.125 * M_PI) && gradient <= tan(0.125 * M_PI) && v.x >= 0)
		return (EAST);
	if (gradient >= tan(-0.125 * M_PI) && gradient <= tan(0.125 * M_PI) && v.x < 0)
		return (WEST);
	if (gradient > tan(0.125 * M_PI) && gradient <= tan(0.375 * M_PI) && v.x >= 0)
		return (NORTH_EAST);
	if (gradient > tan(0.125 * M_PI) && gradient <= tan(0.375 * M_PI) && v.x < 0)
		return (SOUTH_WEST);
	if (gradient < tan(-0.125 * M_PI) && gradient >= tan(-0.375 * M_PI) && v.x >= 0)
		return (SOUTH_EAST);
	if (gradient < tan(-0.125 * M_PI) && gradient >= tan(-0.375 * M_PI) && v.x < 0)
		return (NORTH_WEST);
	if (v.y >= 0)
		return (NORTH);
	if (v.y < 0)
		return (SOUTH);
}


