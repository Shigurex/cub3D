//version:2.2.0

#ifndef DEBUG_H
#define DEBUG_H
#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>
#define TEST(msg) printf("[(%s/%d) %s ]%s\n", __FILE__, __LINE__, __func__, ((char *)msg)); fflush(stdin);
#define TEST_(msg) printf("---------------------------------------------[(%s/%d) %s ]%s\n", __FILE__, __LINE__, __func__, ((char *)msg)); fflush(stdin);
#define TESTn(msg, i) printf("[(%s/%d) %s ]%s:%ld\n", __FILE__, __LINE__, __func__, ((char *)msg), (long)(i)); fflush(stdin);
#define TESTu(msg, i) printf("[(%s/%d) %s ]%s:%lu\n", __FILE__, __LINE__, __func__, ((char *)msg), (unsigned long)(i)); fflush(stdin);
#define TESTx(msg, i) printf("[(%s/%d) %s ]%s:%lx\n", __FILE__, __LINE__, __func__, ((char *)msg), (unsigned long)(i)); fflush(stdin);
#define TESTd(msg, i) printf("[(%s/%d) %s ]%s:%lf\n", __FILE__, __LINE__, __func__, ((char *)msg), (double)(i)); fflush(stdin);
#define TESTp(msg, i) printf("[(%s/%d) %s ]%s:%p\n", __FILE__, __LINE__, __func__, ((char *)msg), (void *)(i)); fflush(stdin);
#define TESTs(msg, i) printf("[(%s/%d) %s ]%s:%s\n", __FILE__, __LINE__, __func__, ((char *)msg), (char *)(i)); fflush(stdin);
#define TESTc(msg, i) printf("[(%s/%d) %s ]%s:%c\n", __FILE__, __LINE__, __func__, ((char *)msg), (char)(i)); fflush(stdin);
#define T printf("[(%s/%d) %s ]\n", __FILE__, __LINE__, __func__); fflush(stdin);
#define T_ printf("---------------------------------------------[(%s/%d) %s ]\n", __FILE__, __LINE__, __func__); fflush(stdin);
#define Tn(i) printf("[(%s/%d) %s ]%s:%ld\n", __FILE__, __LINE__, __func__, #i, (long)(i)); fflush(stdin);
#define Tu(i) printf("[(%s/%d) %s ]%s:%lu\n", __FILE__, __LINE__, __func__, #i, (unsigned long)(i)); fflush(stdin);
#define Tx(i) printf("[(%s/%d) %s ]%s:%lx\n", __FILE__, __LINE__, __func__, #i, (unsigned long)(i)); fflush(stdin);
#define Td(i) printf("[(%s/%d) %s ]%s:%lf\n", __FILE__, __LINE__, __func__, #i, (double)(i)); fflush(stdin);
#define Tp(i) printf("[(%s/%d) %s ]%s:%p\n", __FILE__, __LINE__, __func__, #i, (void *)(i)); fflush(stdin);
#define Ts(i) printf("[(%s/%d) %s ]%s:%s\n", __FILE__, __LINE__, __func__, #i, (char *)(i)); fflush(stdin);
#define Tc(i) printf("[(%s/%d) %s ]%s:%c\n", __FILE__, __LINE__, __func__, #i, (char)(i)); fflush(stdin);
#define FORn(x,j) {printf("[(%s/%d) %s ]%s[]:", __FILE__, __LINE__, __func__, #x);for(size_t i = 0; j; i++){printf("%ld,", (long)(x[i])); fflush(stdin);}printf("\n");}
#define FORu(x,j) {printf("[(%s/%d) %s ]%s[]:", __FILE__, __LINE__, __func__, #x);for(size_t i = 0; j; i++){printf("%ld,", (unsigned long)(x[i])); fflush(stdin);}printf("\n");}
#define FORx(x,j) {printf("[(%s/%d) %s ]%s[]:", __FILE__, __LINE__, __func__, #x);for(size_t i = 0; j; i++){printf("%ld,", (unsigned long)(x[i])); fflush(stdin);}printf("\n");}
#define FORd(x,j) {printf("[(%s/%d) %s ]%s[]:", __FILE__, __LINE__, __func__, #x);for(size_t i = 0; j; i++){printf("%ld,", (double)(x[i])); fflush(stdin);}printf("\n");}
#define FORp(x,j) {printf("[(%s/%d) %s ]%s[]:", __FILE__, __LINE__, __func__, #x);for(size_t i = 0; j; i++){printf("%ld,", (void *)(x[i])); fflush(stdin);}printf("\n");}
#define FORs(x,j) {printf("[(%s/%d) %s ]%s[]:", __FILE__, __LINE__, __func__, #x);for(size_t i = 0; j; i++){printf("%ld,", (char *)(x[i])); fflush(stdin);}printf("\n");}
#define FORc(x,j) {printf("[(%s/%d) %s ]%s[]:", __FILE__, __LINE__, __func__, #x);for(size_t i = 0; j; i++){printf("%ld,", (char)(x[i])); fflush(stdin);}printf("\n");}
#define TAKE(i,j) {static size_t test_arg = 0; if(!(test_arg % j)){i} test_arg++;}
#define STOP {char c; read(STDIN_FILENO, &c, sizeof(char));}

#define E fprintf(stderr, "[(%s/%d) %s ]\n", __FILE__, __LINE__, __func__); fflush(stderr);
#define E_ fprintf(stderr, "---------------------------------------------[(%s/%d) %s ]\n", __FILE__, __LINE__, __func__); fflush(stderr);
#define En(i) fprintf(stderr, "[(%s/%d) %s ]%s:%ld\n", __FILE__, __LINE__, __func__, #i, (long)(i)); fflush(stderr);
#define Eu(i) fprintf(stderr, "[(%s/%d) %s ]%s:%lu\n", __FILE__, __LINE__, __func__, #i, (unsigned long)(i)); fflush(stderr);
#define Ex(i) fprintf(stderr, "[(%s/%d) %s ]%s:%lx\n", __FILE__, __LINE__, __func__, #i, (unsigned long)(i)); fflush(stderr);
#define Ed(i) fprintf(stderr, "[(%s/%d) %s ]%s:%lf\n", __FILE__, __LINE__, __func__, #i, (double)(i)); fflush(stderr);
#define Ep(i) fprintf(stderr, "[(%s/%d) %s ]%s:%p\n", __FILE__, __LINE__, __func__, #i, (void *)(i)); fflush(stderr);
#define Es(i) fprintf(stderr, "[(%s/%d) %s ]%s:%s\n", __FILE__, __LINE__, __func__, #i, (char *)(i)); fflush(stderr);
#define Ec(i) fprintf(stderr, "[(%s/%d) %s ]%s:%c\n", __FILE__, __LINE__, __func__, #i, (char)(i)); fflush(stderr);

#endif



#include <stddef.h>

int Gaussian_elimination(double *matrix, size_t line, size_t row)
{
    size_t r;
    size_t rr;
    size_t l;

    r = 0;
    while (r < row)
    {
        l = r + 1;
        while (l < line)
        {
/* test */if(matrix[r * line + r] == 0.0){E return (1);}
            matrix[r * line + l] /= matrix[r * line + r];
            l++;
        }
        matrix[r * line + r] = 1;
        rr = !r;
        while (rr < row)
        {
            l = r + 1;
            while (l < line)
            {
                matrix[rr * line + l] -= matrix[r * line + l] * matrix[rr * line + r];
                l++;
            }
            matrix[rr * line + r] = 0;
            rr++;
            if (rr == r)
                rr++;
        }
        r++;
    }
    return (0);
}

//#include <stdlib.h>
//void print_matrix(double *matrix, size_t line, size_t row)
//{
//    for (size_t r = 0; r < row; r++)
//    {
//        for (size_t l = 0; l < line; l++)
//        {
//            printf("%lf,\t", matrix[r * line + l]);
//        }
//        printf("\n");
//    }
//}
//
//int main(int argc, char *argv[])
//{
//    if (argc < 2) {E return(1);}
//    double matrix[argc - 1];
//    for (size_t i = 0; i < argc - 1; i++)
//        matrix[i] = atof(argv[i + 1]);
//    size_t line = 1;
//    for (; line * (line - 1) < argc - 1; line++);
//    if (line * (line - 1) != argc - 1) {E return(1);}
//    size_t row = (argc - 1) / line;
//T print_matrix(matrix, line, row);
//Tn(line)
//Tn(row) STOP
//    Tn(Gaussian_elimination(matrix, line, row))  print_matrix(matrix, line, row);
//    return(0);
//    
//}
