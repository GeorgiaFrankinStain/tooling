#ifndef INTERGAL_AVERAGE_RECTANGLE_H
#define INTERGAL_AVERAGE_RECTANGLE_H



#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <mpi.h>



double average_rectang_posteriori_accuracy(double rectang_a,
                                        double rectang_b,
                                        double epsilon);
    double area___average_rectang(double rectang_a,
                                double rectang_b,
                                double part_count);
        double function(double x);


//?ПЕРЕПОЛНЕНИЕ

double monte_karlo_kurnosov (int n);


double monte_karlo (int point_count);
    double function___monte_karlo (double x, double y);
#endif