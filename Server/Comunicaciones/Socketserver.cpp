//
// Created by marcelo on 21/9/21.
//

#include "Socketserver.h"



SocketServer::SocketServer() {}

bool SocketServer::createsocket() {
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

bool SocketServer::enlazarkernel() {
    if(bind(descriptor,(sockaddr*)&info,(socklen_t)sizeof(info))<0){
        return false;
    }
    //Escuchar a los clientes
    listen(descriptor,1);
    return true;

}

void SocketServer::run() {
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
                pthread_t hilo;
                pthread_create(&hilo,0,SocketServer::ControladorCliente,(void*)&data);
                pthread_detach(hilo);
            }
        }
        close(descriptor);
    }
}
void * SocketServer::ControladorCliente(void *obj) {
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
    }
    close(data->descriptor);
    pthread_exit(NULL);
}

void SocketServer::setMsj(const char *msn) {
    for(int i=0;i<clientes.size();i++){
        send(clientes[i],msn, strlen(msn),0);
    }
}