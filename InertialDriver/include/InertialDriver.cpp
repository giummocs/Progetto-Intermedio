#include "InertialDriver.h"

{
	InertialDriver::InertialDriver()
	{
		BUFFER_DIM=0;
		MyVector v(BUFFER_DIM);
	}
	
	InertialDriver::InertialDriver(int buff_sz)
	{
		BUFFER_DIM=buff_sz;
		MyVector v(BUFFER_DIM);
	}

	void InertialDriver::push_back(Lettura v[])
	{
		v.push;
		return;
	}
	
	Lettura[] InertialDriver::pop_front()
	{
		return v.pop_front();
	}
}
