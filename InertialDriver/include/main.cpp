#include <iostream>
#include "InertialDriver.h"

int main(){
    //creo due oggetti InertialDriver uno senza parametro e uno con
    InertialDriver id1();
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
    //push_back su id1 dovrebbe lanciare un'eccezione
    id1.push_back(misura1);
    std::cout<< id1;

    id2.push_back(misura1);
    std::cout<< id2;

    id1.push_back(misura2);
    std::cout<< id1;
    
    id2.push_back(misura2);
    std::cout<< id2;

    //riempio id2 e dovrebbe sovrascrivere la misure piu' vecchie
    for (int i = 0; i< 9; i++){
        id2.push_back(misura3);
    }
    std::cout<< id2;
    //se ora faccio pop_front dovrei ottenere misura2
    Lettura m[]= id2.pop_front

    //svuoto id2 con pop_front
    for (int i= 0; i<8; i++)
    {
        Lettura a[]=id2.pop_front;
    }

    //se provo a eseguire le seguenti funzioni dovrebbe lanciare delle eccezioni
    Lettura m1[] = id2.pop_front();
    Lettura m2[] = id1.pop_front();

    //riempio parzialmente id2 giusto per testare
    id2.push_back(misura1);
    id2.push_back(misura1);

    //test della funzione get_reading
    Lettura l1 = id2.get_reading();
    //dovrebbe lanciare un'eccezione con
    Lettura l2 = id1.get_reading();

    //test della funzione clear_buffer
    id2.clear_buffer();
    std::cout<< id2;
    id1.clear_buffer();
    std::cout<< id1;

    return 0;

}




