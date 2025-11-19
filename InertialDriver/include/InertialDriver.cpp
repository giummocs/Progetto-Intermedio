#include "InertialDriver.h"


InertialDriver::InertialDriver(){
	BUFFER_DIM=0;
	MyVector v(BUFFER_DIM);
}
	
InertialDriver::InertialDriver(int buff_sz){
	BUFFER_DIM=buff_sz;
	MyVector v(BUFFER_DIM);
}
//DA COMPLETARE
void InertialDriver::push_back(Lettura misura[]){
	if(BUFFER_DIM==0){
		throw std::out_of_range("Il vettore non ha dimensione!");
	}
	v[last] = misura;

	
}
//DA COMPLETARE
Lettura[] InertialDriver::pop_front(){
	return v.pop_front();
}

void InertialDriver::clear_buffer(){   
    while(size > 0){
         v.pop_front();    
    }
	return;
}
    
Lettura InertialDriver::get_reading(int i){   
		
    return v[pointer_last][i];
}
 
std::ostream& operator<<(std::ostream& out, const InertialDriver& t){
	for(int i = 0; i < 17; i++)
	{
	    out << "Sensore " << i + 1 << ":\n";
	    out << "Pitch_v = " << t.v[pointer_last][i].pitch_v << "\n";
	    out << "Pitch_a = " << t.v[][i].pitch_a << "\n";
	    out << "Yaw_v = " << t.v[][i].yaw_v << "\n";
	    out << "Yaw_a = " << t.v[][i].yaw_a << "\n";
	    out << "Roll_v = " << t.v[][i].roll_v << "\n";
	    out << "Roll_a = " << t.v[][i].roll_a << "\n\n";
	}
        
}

