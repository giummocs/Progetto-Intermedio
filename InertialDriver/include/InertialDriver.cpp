#include "InertialDriver.h"

{
	InertialDriver::InertialDriver()
	{
		BUFFER_DIM=0;
		MyVector v[BUFFER_DIM];
	}
	InertialDriver::InertialDriver(int buff_sz)
	{
		BUFFER_DIM=buff_sz;
		MyVector v[BUFFER_DIM];
	}
}
