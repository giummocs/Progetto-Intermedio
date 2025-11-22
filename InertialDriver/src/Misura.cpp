#include "Misura.h"

Misura::Misura(){
	//inizializzo tutti i valori dell'array a 0
    for (int i = 0; i < SENSOR; i++){
        array[i].yaw_v=0.0;
        array[i].yaw_a=0.0;
        array[i].pitch_v=0.0;
        array[i].pitch_a=0.0;
        array[i].roll_v=0.0;
        array[i].roll_a=0.0;
      }
}

Misura::Misura(const Lettura* letture){
    //copio tutti gli elementi del puntatore
    for (int i = 0; i < SENSOR; i++){
        array[i]= letture[i];
    }
}

void Misura::replace(Lettura nuova_misura[]){
	//copio tutti i valori della nuova misura
    for (int i = 0; i < SENSOR; i++){
        array[i].yaw_v = nuova_misura[i].yaw_v;
        array[i].yaw_a = nuova_misura[i].yaw_a;
        array[i].pitch_v = nuova_misura[i].pitch_v;
        array[i].pitch_a = nuova_misura[i].pitch_a;
        array[i].roll_v = nuova_misura[i].roll_v;
        array[i].roll_a = nuova_misura[i].roll_a;
      }
}

const Lettura* Misura::get() const{
	//ritorno il puntatore all'array, utile alla funzione pop_front
	return array;
}

Lettura Misura::at(int i){
	//controllo la validità dell'indice
    if(i < 0 || i >= SENSOR){
		throw std::out_of_range("Indice fuori dai bordi!");
	}
    
    return array[i];
}

Lettura& Misura::operator[] (int i){
    return array[i];
}

const Lettura& Misura::operator[] (int i) const{
    return array[i];
}

std::ostream& Misura::print() const{
	std::ostream& out = std::cout;

	//scrivo tutti i valori nell'oggetto out e lo ritorno
	for(int i = 0; i < SENSOR; i++)
	{
	    out << "Sensore " << i + 1 << ":\n";
		out << "Yaw_v = " << array[i].yaw_v << "\n";
		out << "Yaw_a = " << array[i].yaw_a << "\n";
	    out << "Pitch_v = " << array[i].pitch_v << "\n";
	    out << "Pitch_a = " << array[i].pitch_a << "\n";
	    out << "Roll_v = " << array[i].roll_v << "\n";
	    out << "Roll_a = " << array[i].roll_a << "\n\n";
	}
    
    return out;
}

std::ostream& operator<<(std::ostream& out, const Misura& t){

	return t.print();
}
