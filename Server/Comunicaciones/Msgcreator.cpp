//
// Created by marcelo on 21/9/21.
//

#include "Msgcreator.h"

void Msgcreator::stringclean() {
    this->Msj="";
}

string Msgcreator::sendhit(int i,int j) {
    this->stringclean();
    this->Msj="C-Hi-";
    this->Msj.append(to_string(i));
    this->Msj.append("-");
    this->Msj.append(to_string(j));
    this->Msj.append("E");
    return this->Msj;
}
string Msgcreator::sendspeeds(int *speeds,int cantbolas) {
    this->stringclean();
    this->Msj.append("I-Sp-[");
    for(int i=0;i<cantbolas-1;i++){
        this->Msj.append(to_string(speeds[i]));
        this->Msj.append(",");
    }
    this->Msj.append(to_string(speeds[cantbolas-1]));
    this->Msj.append("]");
    this->Msj.append("E");
    return this->Msj;
}

string Msgcreator::senddestroyed(int i, int j) {
    this->stringclean();
    this->Msj.append("C-De-");
    this->Msj.append(to_string(i));
    this->Msj.append("-");
    this->Msj.append(to_string(j));
    this->Msj.append("E");
    return this->Msj;
}

string Msgcreator::sendblocks(int **Blocks){
    this->stringclean();
    this->Msj.append("I-Bl-[");
    for(int i=0;i<6;i++){
        this->Msj.append("[");
    }

}
