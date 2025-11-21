#include "Misura.h"

Misura::Misura(){
    for (int i = 0; i < SENSOR; i++){
        array.yaw_v=0.0;
        array.yaw_a=0.0;
        array.pitch_v=0.0;
        array.pitch_a=0.0;
        array.roll_v=0.0;
        array.roll_a=0.0;
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
