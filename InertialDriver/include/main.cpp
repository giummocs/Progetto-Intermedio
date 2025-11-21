#include <iostream>
#include "InertialDriver.h"

int main(){

    //creo due oggetti InertialDriver uno senza parametro e uno con
    InertialDriver id1;
    InertialDriver id2(10);

    //creo diverse misure (array di 17 letture)
    Lettura misura1[SENSOR];
    for (int i= 0; i < SENSOR; i++){
        misura1[i].yaw_v= 0;
        misura1[i].yaw_a= 0;
        misura1[i].pitch_v= 0;
        misura1[i].pitch_a= 0;
        misura1[i].roll_v= 0;
        misura1[i].roll_a= 0;
    }

    Lettura misura2[SENSOR];
    for (int i= 0; i < SENSOR; i++){
        misura2[i].yaw_v= i;
        misura2[i].yaw_a= i;
        misura2[i].pitch_v= i;
        misura2[i].pitch_a= i;
        misura2[i].roll_v= i;
        misura2[i].roll_a= i;
    }
    Lettura misura3[SENSOR];
    for (int i= 0; i < SENSOR; i++){
        misura3[i].yaw_v= i*100;
        misura3[i].yaw_a= i*100;
        misura3[i].pitch_v= i*100;
        misura3[i].pitch_a= i*100;
        misura3[i].roll_v= i*100;
        misura3[i].roll_a= i*100;
    }


    //test della funzione push_back su i due oggetti InertialDriver e stampo a schermo l'ultima misura salvata
    id2.push_back(misura1);
    std::cout<< id2;
    id2.push_back(misura2);
    std::cout<< id2;
    
    //push_back su id1 dovrebbe lanciare un'eccezione
    try{
        id1.push_back(misura2);
        std::cout<< id1;
        id1.push_back(misura1);
        std::cout<< id1;
    }
    catch(const std::out_of_range& e){
        std::cout<<"Il vettore non ha dimensione! \n";
    }

    //riempio id2 e dovrebbe sovrascrivere la misure piu' vecchie
    for (int i = 0; i< 9; i++){
        id2.push_back(misura3);
    }
    std::cout<< id2;
    //se ora faccio pop_front dovrei ottenere misura2 DA COMPLETARE!!
    const Lettura* m = id2.pop_front();

    delete m;

    //svuoto id2 con pop_front
    for (int i= 0; i<8; i++)
    {
        const Lettura* a = id2.pop_front();

       // delete[] a;
    }

    //se provo a eseguire le seguenti funzioni dovrebbe lanciare delle eccezioni
    try{
        const Lettura* m1 = id2.pop_front();
        const Lettura* m2 = id1.pop_front();
    }
    catch (const std::out_of_range& e){
        std::cout<< "Il vettore e' vuoto! \n";
    }

    //riempio parzialmente id2 giusto per testare
    id2.push_back(misura1);
    id2.push_back(misura1);

    //test della funzione get_reading
    Lettura l1 = id2.get_reading(0);
    //dovrebbe lanciare un'eccezione con
    try{
        Lettura l2 = id1.get_reading(0);
    }
    catch (const std::out_of_range& e){
        std::cout<< "Il vettore e' vuoto! \n";
    }
    try{
        Lettura l2 = id2.get_reading(9999);
    }
    catch (const std::out_of_range& e){
        std::cout<< "Indice non corretto \n";
    }

    //test della funzione clear_buffer
    id2.clear_buffer();
    std::cout<< id2;
    id1.clear_buffer();
    std::cout<< id1;

    return 0;

}














