#include <iostream>
#include "InertialDriver.h"

int main()
{
    //creo due oggetti InertialDriver uno senza parametro e uno con
    InertialDriver id1{};
    InertialDriver id2{10};

    //creo diverse misure (array di 17 letture)
    Lettura misura1[SENSOR];
    for (int i= 0; i < SENSOR; i++)
    {
        misura1[i].yaw_v= 0;
        misura1[i].yaw_a= 0;
        misura1[i].pitch_v= 0;
        misura1[i].pitch_a= 0;
        misura1[i].roll_v= 0;
        misura1[i].roll_a= 0;
    }

    Lettura misura2[SENSOR];
    for (int i= 0; i < SENSOR; i++)
    {
        misura2[i].yaw_v= i;
        misura2[i].yaw_a= i;
        misura2[i].pitch_v= i;
        misura2[i].pitch_a= i;
        misura2[i].roll_v= i;
        misura2[i].roll_a= i;
    }
    Lettura misura3[SENSOR];
    for (int i= 0; i < SENSOR; i++)
    {
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

    //riempio id2
    for (int i = 1; i<= 8; i++)
    {
        id2.push_back(misura3);
    }
    std::cout<< id2;

    //test della funzione get_reading
    Lettura let1 = id2.get_reading();

    //test della funzione clear_buffer
    id2.clear_buffer();
    std::cout<< id2;

    //riempio parzialmente id2 giusto per testare
    id2.push_back(misura1);
    id2.push_back(misura1);

    //test di pop_front
    Lettura let2 = id2.pop_front();
    Lettura let3 = id2.pop_front();
    //dovrebbe lanciare un'eccezione con
    Lettura let4 = id2.pop_front();

    return 0;
}