//
// Created by marcelo on 21/9/21.
//

#include "Msgcreator.h"

void Msgcreator::stringclean() {
    this->Msj="";
}

string Msgcreator::sendpoints(int points) {
    this->stringclean();
    this->Msj.append("PO-");
    this->Msj.append(to_string(points));
    return this->Msj;
}

string Msgcreator::endgame(bool condition) {
    this->stringclean();
    this->Msj.append("EG-");
    if(condition){
        this->Msj.append("T");//El jugador gana
        return this->Msj;
    }else{
        this->Msj.append("F");//El jugador pierde
        return this->Msj;
    }
}

string Msgcreator::sendlen(int len) {
    this->stringclean();
    this->Msj.append("SL-");
    this->Msj.append(to_string(len));
    return this->Msj;
}

string Msgcreator::sendprof(int prof) {
    this->stringclean();
    this->Msj.append("PR-");
    this->Msj.append(to_string(prof));
    return this->Msj;
}

string Msgcreator::sendblocks(string Blocks) {
    this->stringclean();
    this->Msj.append("GR-");
    this->Msj.append(Blocks);
    return this->Msj;
}

string Msgcreator::sendprofactivation(bool Active){
    this->stringclean();
    this->Msj.append("PA-");
    if(Active){
        Msj.append("T");
        return this->Msj;
    }else{
        Msj.append("F");
        return this->Msj;
    }
}

string Msgcreator::sendspeeds(string Speeds) {
    this->stringclean();
    this->Msj.append("SP-");
    this->Msj.append(Speeds);
    return this->Msj;
}

string Msgcreator::senddestroyed(int i, int j) {
    this->stringclean();
    this->Msj.append("DR-");
    this->Msj.append(to_string(i));
    this->Msj.append("-");
    this->Msj.append(to_string(j));
    return this->Msj;
}


