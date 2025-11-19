#include "InertialDriver.h"

InertialDriver::InertialDriver() : BUFFER_DIM(0), v(0) {}
	
InertialDriver::InertialDriver(int buff_sz) : BUFFER_DIM(buff_sz), v(buff_sz) {
    first = 0;
    last = 0;
}


void InertialDriver::push_back(Lettura misura[]){
	if(BUFFER_DIM==0){
		throw std::out_of_range("Il vettore non ha dimensione!");
	}
	v[last] = misura;

	last = (last+1) % BUFFER_DIM;
	if(last == first){
		first = (first+1) % BUFFER_DIM;
	}
	
}

Lettura* InertialDriver::pop_front(){
	if(last == first){
		throw std::out_of_range("Il vettore e' vuoto!");
	}

	int tempFirst = first;
	first = (first+1) % BUFFER_DIM;

	return v[tempFirst];	
	
}

void InertialDriver::clear_buffer(){   
	//first==last significa che il vettore e' vuoto
    while(first != last){
         v.pop_front();    
    }
}
    
Lettura InertialDriver::get_reading(int i){   
	if(i<0 || i>16){
		throw std::out_of_range("Indice fuori dai bordi!");
	}
    return v[last][i];
}
 
std::ostream& operator<<(std::ostream& out, const InertialDriver& t){
	for(int i = 0; i < 17; i++)
	{
	    out << "Sensore " << i + 1 << ":\n";
		out << "Yaw_v = " << t.v[last][i].yaw_v << "\n";
		out << "Yaw_a = " << t.v[last][i].yaw_a << "\n";
	    out << "Pitch_v = " << t.v[last][i].pitch_v << "\n";
	    out << "Pitch_a = " << t.v[last][i].pitch_a << "\n";
	    out << "Roll_v = " << t.v[last][i].roll_v << "\n";
	    out << "Roll_a = " << t.v[last][i].roll_a << "\n\n";
	}
        
}

