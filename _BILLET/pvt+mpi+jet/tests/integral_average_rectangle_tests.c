#include <integral_average_rectangle.h>
#include <ctest.h>
#include <stdio.h>
#include <stdlib.h>

const double GENERAL_NEAR = 1E-4;
const double PI_test = 3.14159265359;


//function
	CTEST(function, in_0)
	{
		printf("boooooooooom funcio\n");
		
		const double real = function(0);
		ASSERT_DBL_NEAR_TOL(0, real, GENERAL_NEAR);
	}
	CTEST(function, in_1)
	{
		const double real = function(PI_test / 12);
		ASSERT_DBL_NEAR_TOL(2.0943, real, GENERAL_NEAR);
	}


//average_rectang_posteriori_accuracy
	CTEST(average_rectang_posteriori_accuracy, from_01_to05eps1em1)
	{
		const double real = average_rectang_posteriori_accuracy(0.1, 0.5, 1E-6);
		// printf("-----------------%f\n", real);
		ASSERT_DBL_NEAR_TOL(1.11344, real, 1E-4);
	}
//monte_karlo
	CTEST(monte_karlo, from_01_to05eps1em1)
	{
		const double real = monte_karlo_kurnosov(10000000);
		// const double real = monte_karlo(100000000);
		printf("-----------------%f\n", real);
		ASSERT_DBL_NEAR_TOL(2.0972, real, 1E-3);
	}

	