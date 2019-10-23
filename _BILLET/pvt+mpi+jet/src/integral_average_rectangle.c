#include "integral_average_rectangle.h"



double rand_0_1 ()
{
    return (double) rand() / RAND_MAX;
}

double average_rectang_posteriori_accuracy(double rectang_a,
                                        double rectang_b,
                                        double epsilon)
{



    double prev_value = 0;
    double cur_value = 0;
    for (int i = 1;; i *= 2)
    {
        printf("--------------------------i: %d\n", i);
        cur_value = area___average_rectang(rectang_a, rectang_b, (double) i);
        printf("-------------------KURA: %f, prev: %f, esp: %f\n", cur_value, prev_value, epsilon);
        if (fabsf(cur_value - prev_value) < epsilon)
            break;
        else
            prev_value = cur_value;
    }



    return cur_value;
}
    double area___average_rectang(double rectang_a,
                                double rectang_b,
                                double part_count)
    {
        double sum_area = 0;
        double h = (rectang_b - rectang_a) / part_count;
        for (int i = 0; i < part_count; ++i)
        {
            double x = rectang_a + i * h + (h / 2);
            double y = function(x);
            double area_cur_rectang = y * h;
            sum_area += area_cur_rectang;
        }



        return sum_area;
    }
        double function(double x)
        {

            printf("function\n");

            return x / ( pow(sin(2*x), 3) );
        }


//?ПЕРЕПОЛНЕНИЕ

double monte_karlo_kurnosov (int n)
{
    int rank, commsize;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &commsize);
    int in = 0;
    double s = 0;
    for (int i = 0; i < n; i++) {
        double x = rand_0_1() * 1; /* x in [0, pi] */
        double y = rand_0_1(); /* y in [0, sin(x)] */
        if (y <= 1 - x) {
            in++;
            s += function___monte_karlo(x, y);
        }
    }


    int gin = 0;
    MPI_Reduce(&in, &gin, 1, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);
    double gsum = 0.0;
    MPI_Reduce(&s, &gsum, 1, MPI_DOUBLE, MPI_SUM, 0, MPI_COMM_WORLD);
    double res;
    if (rank == 0) {
        double v = 1 * gin / n;
        res = v * gsum / gin;
    }
    return res;
}

/*int main(int argc, char **argv)
{
    MPI_Init(&argc, &argv);
    int rank, commsize;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &commsize);
    int in = 0;
    double s = 0;
    for (int i = rank; i < n; i += commsize) {
        double x = getrand() * PI; // x in [0, pi] 
        double y = getrand(); // y in [0, sin(x)] 
        if (y <= sin(x)) {
            in++;
            s += func(x, y);
        }
    }
    int gin = 0;
    MPI_Reduce(&in, &gin, 1, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);
    double gsum = 0.0;
    MPI_Reduce(&s, &gsum, 1, MPI_DOUBLE, MPI_SUM, 0, MPI_COMM_WORLD);
    if (rank == 0) {
        double v = PI * gin / n;
        double res = v * gsum / gin;
        printf("Result: %.12f, n %d\n", res, n);
    }
    MPI_Finalize();
    return 0;
}*/

    double function___monte_karlo (double x, double y)
    {
        return pow(exp(x + y), 2);
    }