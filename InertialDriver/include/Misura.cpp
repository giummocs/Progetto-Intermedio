#include "Misura.h"

Misura::Misura(){
    for (int i = 0; i < SENSOR; i++){
        array[i].yaw_v=0.0;
        array[i].yaw_a=0.0;
        array[i].pitch_v=0.0;
        array[i].pitch_a=0.0;
        array[i].roll_v=0.0;
        array[i].roll_a=0.0;
      }
}

void Misura::replace(Lettura nuova_misura[]){
    for (int i = 0; i < SENSOR; i++){
        array[i].yaw_v=misura[i].yaw_v;
        array[i].yaw_a=misura[i].yaw_a;
        array[i].pitch_v=misura[i].pitch_v;
        array[i].pitch_a=misura[i].pitch_a;
        array[i].roll_v=misura[i].roll_v;
        array[i].roll_a=misura[i].roll_a;
      }
}

Lettura Misura::at(int i){
    if(i < 0 || i >= SENSOR){
		throw std::out_of_range("Indice fuori dai bordi!");
	}
    
    return array[i];
}

Misura::~Misura(){
    delete[] array;
}

Lettura& Misura::operator[] (int i){
    return array[i];
}

const Lettura& operator[] (int i) const{
    return array[i];
}

std::ostream& Misura::print() const{
	std::ostream& out = std::cout;

	
    
    return out;
}

std::ostream& operator<<(std::ostream& out, const Misura& t){

	return t.print();
}
