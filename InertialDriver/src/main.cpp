#include <iostream>
#include "InertialDriver.h"

int main(){
    //costante statica che indica la dimensione del buffer di prova
    static const int DIM = 10;
    //creiamo due oggetti InertialDriver uno senza parametro e uno con
    InertialDriver id1;
    InertialDriver id2(DIM);

    //creiamo diverse misure (array di 17 letture)
    Lettura misura1[SENSOR];
    for (int i= 0; i < SENSOR; i++){
        misura1[i].yaw_v = 0.0;
        misura1[i].yaw_a = 0.0;
        misura1[i].pitch_v = 0.0;
        misura1[i].pitch_a = 0.0;
        misura1[i].roll_v = 0.0;
        misura1[i].roll_a = 0.0;
    }

    Lettura misura2[SENSOR];
    for (int i= 0; i < SENSOR; i++){
        misura2[i].yaw_v = i;
        misura2[i].yaw_a = i;
        misura2[i].pitch_v = i;
        misura2[i].pitch_a = i;
        misura2[i].roll_v = i;
        misura2[i].roll_a = i;
    }
    
    Lettura misura3[SENSOR];
    for (int i= 0; i < SENSOR; i++){
        misura3[i].yaw_v = i*100;
        misura3[i].yaw_a = i*100;
        misura3[i].pitch_v = i*100;
        misura3[i].pitch_a = i*100;
        misura3[i].roll_v = i*100;
        misura3[i].roll_a = i*100;
    }


    //test della funzione push_back su i due oggetti InertialDriver e stampo a schermo l'ultima misura salvata
    std::cout<< "push_back misura1 su id2 *******************************************************\n";
    id2.push_back(misura1);
    std::cout<< "stampiamo a schermo misura1 salvato in id2\n";
    std::cout<< id2;
    
    std::cout<< "push_back misura2 su id2 *******************************************************\n";
    id2.push_back(misura2);
    std::cout<< "stampiamo a schermo misura2 salvato in id2\n";
    std::cout<< id2;
    
    //push_back su id1 dovrebbe lanciare un'eccezione
    std::cout<< "push_back su id1 *******************************************************\n";
    try{
        id1.push_back(misura1);
        std::cout<< id1;
        id1.push_back(misura2);
        std::cout<< id1;
    }
    catch(const std::out_of_range& e){
        std::cout<<"Il vettore non ha dimensione! \n\n";
    }

    //facciamo un ciclo di 9 iterazioni di push_back su id2
    //per provare che assuma il corretto comportamento del buffer circolare
    for (int i = 0; i< 8; i++){
        id2.push_back(misura3);
    }

    std::cout<< "push_back misura3 su id2 e lo riempio *******************************************************\n";
    std::cout<< "stampiamo a schermo misura3 che va a sovrascrivere la misura piu' vecchia\n";
    std::cout<< id2;
    //se facciamo pop_front su id2 otteniamo misura misura2
    std::cout<< "pop_front su id2 *******************************************************\n";
    const Lettura* letture = id2.pop_front();
    Misura m(letture);
    std::cout<< "stampiamo a schermo la misura piu' vecchia (misura2)\n";
    std::cout<< m << std::endl;

    //svuotiamo id2 con pop_front
    for (int i= 0; i< 8; i++)
    {
        const Lettura* a = id2.pop_front();
    }
    std::cout<< "stampiamo a schermo id2 svuotato\n";
    std::cout<< id2<<std::endl;

    //le seguenti funzioni devono lanciare delle eccezioni
    std::cout<< "pop_front su id2 svuotato e id1 vuoto **********************************************************\n";
    try{
        const Lettura* m1 = id2.pop_front();
        const Lettura* m2 = id1.pop_front();
    }
    catch (const std::out_of_range& e){
        std::cout<< "I vettori sono vuoti! \n\n";
    }

    //riempiamo parzialmente id2 giusto per testare
    id2.push_back(misura3);
    id2.push_back(misura2);

    //test della funzione get_reading
    std::cout<< "get_reading della lettura(l1) di indice 10 della misura piu' recente di id2 *****************************************\n";
    Lettura l1 = id2.get_reading(10);
    std::cout<< "Lettura l1 : \n";
    std::cout<< "Yaw_a = "<< l1.yaw_a << " Yaw_v = "<< l1.yaw_v <<std::endl;
    std::cout<< "Pitch_a = "<< l1.pitch_a << " Pitch_v = "<< l1.pitch_v <<std::endl;
    std::cout<< "Roll_a = "<< l1.roll_a << " Roll_v = "<< l1.roll_v << "\n\n";
    
    //get_reading su id1 vuoto deve lanciare un'eccezione
    std::cout<< "get_reading su id1 ************************************************************\n";
    try{
        Lettura l2 = id1.get_reading(0);
    }
    catch (const std::out_of_range& e){
        std::cout<< "Il vettore e' vuoto! \n\n";
    }
    //get_reading su id2 all'indice non valido deve lanciare un'eccezione
    std::cout<< "get_reading su id2 con indice non valido ************************************************************\n";
    try{
        Lettura l2 = id2.get_reading(9999);
    }
    catch (const std::out_of_range& e){
        std::cout<< "Indice non valido \n\n";
    }

    //test della funzione clear_buffer
    id2.clear_buffer();
    std::cout<< "clear_buffer su id2 *******************************************************\n";
    std::cout<< "stampiamo a schermo id2 svuotato\n";
    std::cout<< id2<<std::endl;
    id1.clear_buffer();
    std::cout<< "clear_buffer su id1 *******************************************************\n";
    std::cout<< "stampiamo a schermo id1 svuotato\n";
    std::cout<< id1<<std::endl;

    return 0;

}


















