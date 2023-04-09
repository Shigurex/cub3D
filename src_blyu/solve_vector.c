#include <stddef.h>

#include "hoge.h"

int Gaussian_elimination(double *matrix, size_t line, size_t row);

hoge_coordinate sVA_p_tVB_e_VC(hoge_coordinate va, hoge_coordinate  vb, hoge_coordinate  vc)
{
    double matrix[6];
    hoge_coordinate r;

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

hoge_coordinate VA_p_sVB_e_tVC(hoge_coordinate va, hoge_coordinate  vb, hoge_coordinate  vc)
{
    double matrix[6];
    hoge_coordinate r;

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
