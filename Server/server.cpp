//
// Created by Lenovo on 20/9/2021.
//

#include "server.h"


    server::server(){
        this->Puntaje=0;
        this->Length=5;
        this->CantBloques=78;
        this->CantBolas=1;
        this->Profundidad=0;
        this->Grid.fillgrid();
        this->CantBloques-=this->Grid.getCantProf();
        this->Ballspeeds[0]=5;
    }

    void server::LostBall(int index){
        for(int j=index+1;j<this->CantBolas+1;j++){
            this->Ballspeeds[index]=this->Ballspeeds[j];
            index++;
        }
        this->CantBolas--;
        this->Length--;
        //Envio de las bolas actualizadas
        string speedstr=this->msgcreator.sendspeeds(this->Speedparser());
        this->setMsj(speedstr.c_str());
        //Envio de la barra actualizada
        string lenstr=this->msgcreator.sendlen(this->Length);
        this->setMsj(lenstr.c_str());
        //Condicion de finalizacion no hay bolas o la barra desaparece
        if(this->CantBolas==0||this->Length==0){
            string EGstr=this->msgcreator.endgame(false);
            this->setMsj(EGstr.c_str());
        }
    }

    void server::MessageReciever(string msg) {
        string hitfunc = "BH";//Ball Hit function
        string Profact = "PA";//Activate /deactivate profundo
        string Gainfunc = "GB";//Gained Ball Function
        string Lostfunc = "LB";//Lost Ball Function
        string Speedhit = "SH";//Ball hit while bar spinning
        string Speedtime = "ST";//La velocidad aumenta por el tiempo
        if (msg[0] == hitfunc[0] && msg[1] == hitfunc[1]) {
            int i = atoi(&msg[3]);
            int j = atoi(&msg[5]);
            this->Ballhit(i, j);
        } else if (msg[0] == Profact[0] && msg[1] == Profact[1]) {
            string TrueFalse = "T";
            if (msg[3] == TrueFalse[0]) {
                this->ProfunActive(true);
            } else {
                this->ProfunActive(false);
            }
        } else if (msg[0] == Gainfunc[0] && msg[1] == Gainfunc[1]) {
            this->GainedBall();
        } else if (msg[0] == Lostfunc[0] && msg[1] == Lostfunc[1]) {
            int i = atoi(&msg[3]);
            this->LostBall(i);
        } else if (msg[0] == Speedhit[0] && msg[1] == Speedhit[1]) {
            int i = atoi(&msg[3]);
            this->Speedhit(i);
        } else if (msg[0] == Speedtime[0] && msg[1] == Speedtime[1]) {
            this->SpeedSurprise(true);
        }
}

    void server::GainedBall() {
            this->Ballspeeds[this->CantBolas] = 5;
            this->CantBolas++;
            //Envio de las velocidades actualizadas
            string speedstr=this->msgcreator.sendspeeds(this->Speedparser());
            this->setMsj(speedstr.c_str());
        }

    void server::Managesurprise(string surprise) {
        if (surprise == "+V") {//Sorpresa más velocidad
            this->SpeedSurprise(true);
        } else if (surprise == "-V") {//Sorpresa menos velocidad
            this->SpeedSurprise(false);
        } else if (surprise == "+B") {//Sorpresa más barra
            this->LengthSurprise(true);
        } else {//Sorpresa menos barra
            this->LengthSurprise(false);
        }
    }

    void server::ProfunActive(bool Activate) {
        this->modoprofundo = Activate;
        string Profstr=msgcreator.sendprofactivation(Activate);
        this->setMsj(Profstr.c_str());
    }

    void server::Ballhit(int i, int j) {
        Bloque Golpe = this->Grid.grid[i][j];
        if (Golpe.tipo == 5) {//Bloque interno
            if(this->Profundidad!=0){
                this->Profundidad--;
                //Actualización profundidad
                string newprof=msgcreator.sendprof(this->Profundidad);
                this->setMsj(newprof.c_str());
            }
        }
        else if (Golpe.tipo == 4) {//Bloque tipo profundo
            if (this->modoprofundo && this->Profundidad!=0) {//Profundidad activada y nivel mayor a 0 destruye interno
                this->Puntaje += this->Grid.grid[i+this->Profundidad][j].hit();
                //Envio de los puntos
                string newpunt=msgcreator.sendpoints(this->Puntaje);
                this->setMsj(newpunt.c_str());

                //Envio de la destruccion del bloque
                this->CantBloques--;
                string destblock=msgcreator.senddestroyed(i+this->Profundidad,j);
                this->setMsj(destblock.c_str());
                //Condicion de finalizacion se acabaron los bloques
                if (this->Grid.grid[i][j].getSorpresa() != "N") {//El bloque contiene sorpresa
                    this->Managesurprise(Grid.grid[i][j].getSorpresa());
                }
                if (this->CantBloques==0){
                    string Endgamestr=msgcreator.endgame(true);
                    this->setMsj(Endgamestr.c_str());
                }
            }else if(this->modoprofundo && this->Profundidad==0){

            }else{
                if(this->Profundidad!=5){
                    this->Profundidad++;
                    //Actualización profundidad
                    string newprof=msgcreator.sendprof(this->Profundidad);
                    this->setMsj(newprof.c_str());
                }
            }
        }
        else {
            int suma = this->Grid.grid[i][j].hit();
            this->Puntaje += suma;
            if (suma != 0) {//el bloque fue destruido
                //Envio de la destruccion del bloque
                string destblock=msgcreator.senddestroyed(i,j);
                this->setMsj(destblock.c_str());
                this->CantBloques--;

                //Envio de los puntos
                string newpunt=msgcreator.sendpoints(this->Puntaje);
                this->setMsj(newpunt.c_str());

                if (this->Grid.grid[i][j].getSorpresa() != "N") {//El bloque contiene sorpresa
                    this->Managesurprise(Grid.grid[i][j].getSorpresa());
                    if (this->Profundidad != 0) {//Profundidad no está en su valor mínimo
                        this->Profundidad--;
                        //Actualización profundidad
                        string newprof=msgcreator.sendprof(this->Profundidad);
                        this->setMsj(newprof.c_str());
                    }
                }if(this->CantBolas==0){
                    string Endgamestr=msgcreator.endgame(true);
                    this->setMsj(Endgamestr.c_str());
                }else{
                    if (this->Profundidad != 0) {//Profundidad no está en su valor mínimo
                        this->Profundidad--;
                        //Actualización profundidad
                        string newprof=msgcreator.sendprof(this->Profundidad);
                        this->setMsj(newprof.c_str());
                    }
                }
            }
        }
    }

    void server::SpeedSurprise(bool Buff) {
            if (Buff) {//Aumento de velocidad
                for (int i = 0; i < this->CantBolas; i++) {
                    if (this->Ballspeeds[i] != 10) {
                        this->Ballspeeds[i]++;
                    } else {//Velocidad máxima 10
                        continue;
                    }
                }
                //Actualización velocidades
                string speedstr=msgcreator.sendspeeds(this->Speedparser());
                this->setMsj(speedstr.c_str());
            } else {//Disminución
                for (int i = 0; i < this->CantBolas; i++) {
                    if (this->Ballspeeds[i] != 1) {
                        this->Ballspeeds[i]--;
                    } else {//Disminución mínima 1
                        continue;
                    }
                }
                //Actualización velocidades
                string speedstr=msgcreator.sendspeeds(this->Speedparser());
                this->setMsj(speedstr.c_str());
            }
        }

    void server::Speedhit(int i) {
        this->Ballspeeds[i]++;
        //Actualización velocidades
        string speedstr=msgcreator.sendspeeds(this->Speedparser());
        this->setMsj(speedstr.c_str());
    }

    void server::LengthSurprise(bool Buff) {
            if (Buff) {//Aumento de length
                if (this->Length != 10) {
                    this->Length++;
                    //Actualizacion len
                    string lenstr=msgcreator.sendlen(this->Length);
                    this->setMsj(lenstr.c_str());
                } else {//Length máximo 10
                }
            }
            else {//Disminución
                if (this->Length != 1) {
                    this->Length--;
                } else {//Disminuion igual a 0 fin del juego
                    string endgamestr=msgcreator.endgame(false);
                    this->setMsj(endgamestr.c_str());
                }
            }
        }

    string server::Martrparser() {
            string out = "[";
            for (int i = 0; i < 6; i++) {
                out.append("[");
                for (int j = 0; j < 13; j++) {
                    int type = this->Grid.grid[i][j].tipo;
                    out.append(to_string(type));
                    if(j!=12){
                        out.append(",");
                    }
                }
                if (i != 5) {
                    out.append("],");
                } else {
                    out.append("]");
                }
            }
            out.append("]");
            return out;
        }

    string server::Speedparser() {
        string out="[";
        for(int i =0;i<this->CantBolas;i++){
            int speed=this->Ballspeeds[i];
            out.append(to_string(speed));
            if(i!=this->CantBolas-1){
                out.append(",");
            }
        }
        out.append("]");
        return out;
}

    void server::initialinfo() {
    string Matrstr=msgcreator.sendblocks(this->Martrparser());
    this->setMsj(Matrstr.c_str());
    string Speedstr=msgcreator.sendspeeds(this->Speedparser());
    this->setMsj(Speedstr.c_str());
}

//---------------------Funciones Comunicacion Sockets-----------------------

bool server::createsocket() {
    //Crear a un descriptor
    descriptor= socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);
    if(descriptor<0){
        return false;
    }
    info.sin_family=AF_INET;
    info.sin_addr.s_addr=INADDR_ANY;
    info.sin_port= htons(4050);
    memset(&info.sin_zero,0,sizeof(info.sin_zero));
    return true;
}

bool server::enlazarkernel() {
    if(bind(descriptor,(sockaddr*)&info,(socklen_t)sizeof(info))<0){
        return false;
    }
    //Escuchar a los clientes
    listen(descriptor,1);
    return true;

}

void server::run() {
    if(!createsocket()){
        throw string("Error socket");
    }if(!enlazarkernel()){
        throw string("Error Kernel");
    }else{
        while(true){
            DataSocket data;
            socklen_t t=sizeof(data.info);
            cout<<"Esperando conexión cliente"<<endl;
            data.descriptor= accept(descriptor,(sockaddr*)&data.info,&t);
            if(data.descriptor<0){
                cout<<"Error aceptar cliente"<<endl;
                break;
            }else{
                clientes.push_back(data.descriptor);
                cout<<"cliente conectado"<<endl;
                //pthread_t hilo;
                //pthread_create(&hilo,0,server::ControladorCliente,(void*)&data);
                //pthread_detach(hilo);
                this->initialinfo();
                ControladorCliente((void *)&data);
            }
        }
        close(descriptor);
    }
}

void * server::ControladorCliente(void *obj) {
    DataSocket* data=(DataSocket *)obj;
    while(true){
        string msj;
        char buffer[1024]={0};
        while (true){
            memset(buffer,0,1024);
            int bytes= recv(data->descriptor,buffer,1024,0);
            msj.append(buffer,bytes);
            if(bytes<=0){
                close(data->descriptor);
                pthread_exit(NULL);
            }if(bytes<1024){
                break;
            }
        }
        cout<<msj<<endl;
        this->MessageReciever(msj);
    }
    close(data->descriptor);
    pthread_exit(NULL);
}

void server::setMsj(const char *msn) {
    for(int i=0;i<clientes.size();i++){
        send(clientes[i],msn, strlen(msn),0);
    }
}
