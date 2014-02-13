//
//  Mazmorra.cpp
//  Roguelike
//
//  Created by jonas on 19/02/13.
//  Copyright (c) 2013 jonas. All rights reserved.
//

#include "Mazmorra.h"

mazmorra::mazmorra(){
    //srand(time(NULL));
    
    //MAZMORRA
    largo = 30+rand()%(51-30);
    alto = 30+rand()%(51-30);
    size = largo * alto;
    
    
    //HABITACIONES
    hab[0].largo = 6+rand()%(11-6);
    hab[0].alto = 6+rand()%(11-6);
    hab[0].size = hab[0].alto * hab[0].largo;
    hab[0].inicio.x = 2+rand()%(4-2);
    hab[0].inicio.y = 2+rand()%(4-2);
    hab[0].puerta1.y = hab[0].inicio.y+1+rand()%((hab[0].alto-1)-hab[0].inicio.y+1);
    hab[0].puerta1.x = hab[0].inicio.x+hab[0].largo;
    hab[0].puerta2.y = hab[0].inicio.y+hab[0].alto;
    hab[0].puerta2.x = hab[0].inicio.x+1+rand()%((hab[0].largo-1)-hab[0].inicio.x+1);
    
    hab[1].largo = 6+rand()%(11-6);
    hab[1].alto = 6+rand()%(11-6);
    hab[1].size = hab[1].alto * hab[1].largo;
    hab[1].inicio.x = (largo/2)+rand()%(((largo/2)+3)-(largo/2));
    hab[1].inicio.y = 2+rand()%(4-2);
    hab[1].puerta1.y = hab[1].inicio.y+1+rand()%((hab[1].alto-1)-hab[1].inicio.y+1);
    hab[1].puerta1.x = hab[1].inicio.x;
    hab[1].puerta2.y = hab[1].inicio.y+hab[1].alto;
    hab[1].puerta2.x = hab[1].inicio.x+rand()%((hab[1].largo-1)-hab[1].inicio.x);
    
    hab[2].largo = 6+rand()%(11-6);
    hab[2].alto = 6+rand()%(11-6);
    hab[2].size = hab[2].alto * hab[2].largo;
    hab[2].inicio.x = 2+rand()%(4-2);
    hab[2].inicio.y = (alto/2)+rand()%(((alto/2)+3)-(alto/2));
    hab[2].puerta1.y = hab[2].inicio.y+1+rand()%((hab[2].alto-1)-hab[2].inicio.y+1);
    hab[2].puerta1.x = hab[2].inicio.x+hab[2].largo;
    hab[2].puerta2.y = hab[2].inicio.y;
    hab[2].puerta2.x = hab[2].inicio.x+1+rand()%((hab[2].largo-1)-hab[2].inicio.x+1);
    
    
    dibujo = new char[largo*alto]; //llenar el dibujo de espacios en blanco.
    for (int i = 0; i < largo*alto; i++) {
        dibujo[i] = ' ';
    }
/*
    //dibujo[((hab1.inicio.y)*largo)+hab1.inicio.x] = '1';
    for (int i = 0; i < hab[0].largo; i++) {
        dibujo[(((hab[0].inicio.y)*largo)+hab[0].inicio.x)+i] = '*';
    }
    for (int j = 0; j < hab[0].alto; j++) {
        dibujo[(((hab[0].inicio.y)*largo)+hab[0].inicio.x)+j*largo] = '*';
    }
    for (int j = 0; j < hab[0].alto; j++) {
        dibujo[(((hab[0].inicio.y)*largo)+hab[0].inicio.x+hab[0].largo)+j*largo] = '*';
    }
    for (int i = 0; i <= hab[0].largo; i++) {
        dibujo[(((hab[0].inicio.y+hab[0].alto)*largo)+hab[0].inicio.x)+i] = '*';
    }
    dibujo[(hab[0].puerta1.y*largo)+hab[0].puerta1.x] = '+';
    dibujo[(hab[0].puerta2.y*largo)+hab[0].puerta2.x] = '+';
    
    //dibujo[((hab2.inicio.y)*largo)+hab2.inicio.x] = '2';
    for (int i = 0; i < hab[1].largo; i++) {
        dibujo[(((hab[1].inicio.y)*largo)+hab[1].inicio.x)+i] = '*';
    }
    for (int j = 0; j < hab[1].alto; j++) {
        dibujo[(((hab[1].inicio.y)*largo)+hab[1].inicio.x)+j*largo] = '*';
    }
    for (int j = 0; j < hab[1].alto; j++) {
        dibujo[(((hab[1].inicio.y)*largo)+hab[1].inicio.x+hab[1].largo)+j*largo] = '*';
    }
    for (int i = 0; i <= hab[1].largo; i++) {
        dibujo[(((hab[1].inicio.y+hab[1].alto)*largo)+hab[1].inicio.x)+i] = '*';
    }
    dibujo[(hab[1].puerta1.y*largo)+hab[1].puerta1.x] = '+';
    dibujo[(hab[1].puerta2.y*largo)+hab[1].puerta2.x] = '+';
    
    //dibujo[((hab3.inicio.y)*largo)+hab3.inicio.x] = '3';
    for (int i = 0; i < hab[2].largo; i++) {
        dibujo[(((hab[2].inicio.y)*largo)+hab[2].inicio.x)+i] = '*';
    }
    for (int j = 0; j < hab[2].alto; j++) {
        dibujo[(((hab[2].inicio.y)*largo)+hab[2].inicio.x)+j*largo] = '*';
    }
    for (int j = 0; j < hab[2].alto; j++) {
        dibujo[(((hab[2].inicio.y)*largo)+hab[2].inicio.x+hab[2].largo)+j*largo] = '*';
    }
    for (int i = 0; i <= hab[2].largo; i++) {
        dibujo[(((hab[2].inicio.y+hab[2].alto)*largo)+hab[2].inicio.x)+i] = '*';
    }
    dibujo[(hab[2].puerta1.y*largo)+hab[2].puerta1.x] = '+';
    dibujo[(hab[2].puerta2.y*largo)+hab[2].puerta2.x] = '+';
*/
    
    for (int k = 0; k < 3; k++) {
        for (int i = 0; i < hab[k].largo; i++) {
            dibujo[(((hab[k].inicio.y)*largo)+hab[k].inicio.x)+i] = '*';
        }
        for (int j = 0; j < hab[k].alto; j++) {
            dibujo[(((hab[k].inicio.y)*largo)+hab[k].inicio.x)+j*largo] = '*';
        }
        for (int j = 0; j < hab[k].alto; j++) {
            dibujo[(((hab[k].inicio.y)*largo)+hab[k].inicio.x+hab[k].largo)+j*largo] = '*';
        }
        for (int i = 0; i <= hab[k].largo; i++) {
            dibujo[(((hab[k].inicio.y+hab[k].alto)*largo)+hab[k].inicio.x)+i] = '*';
        }
        dibujo[(hab[k].puerta1.y*largo)+hab[k].puerta1.x] = '+';
        dibujo[(hab[k].puerta2.y*largo)+hab[k].puerta2.x] = '+';
    }
    
    
    //PASILLOS:
    //habitación 1 a habitación 2:
    int pasillo1x = abs(hab[0].puerta1.x-hab[1].puerta1.x);
    int pasillo1y = abs(hab[0].puerta1.y-hab[1].puerta1.y);
    for (int i = 1; i < pasillo1x /*+ pasillo1y*/; i++) {
        dibujo[(hab[0].puerta1.y*largo)+hab[0].puerta1.x+i] = '#';
    }
    if (hab[1].puerta1.y < hab[0].puerta1.y) {
        for (int i = 1; i <= pasillo1y; i++) {
            dibujo[((hab[0].puerta1.y*largo)+hab[0].puerta1.x+pasillo1x)-i*largo-1] = '#';
        }
    } else {
        for (int i = 1; i <= pasillo1y; i++) {
            dibujo[((hab[0].puerta1.y*largo)+hab[0].puerta1.x+pasillo1x)+i*largo-1] = '#';
        }
    }
    //habitación 2 a habitación 3:
    int pasillo3x = abs(hab[1].puerta2.x-hab[2].puerta1.x);
    int pasillo3y = abs(hab[1].puerta2.y-hab[2].puerta1.y);
    for (int i = 1; i < pasillo3x /*+ pasillo1y*/; i++) {
        dibujo[(hab[2].puerta1.y*largo)+hab[2].puerta1.x+i] = '#';
    }
    if (hab[1].puerta2.y < hab[2].puerta1.y) {
        for (int i = 0; i < pasillo3y; i++) {
            dibujo[((hab[2].puerta1.y*largo)+hab[2].puerta1.x+pasillo3x)-i*largo] = '#';
        }
    } else {
        for (int i = 1; i <= pasillo3y; i++) {
            dibujo[((hab[2].puerta1.y*largo)+hab[2].puerta1.x+pasillo3x)+i*largo-1] = '#';
        }
    }
    //habitación 1 a habitación 3:
    int pasillo2x = abs(hab[0].puerta2.x-hab[2].puerta2.x);
    int pasillo2y = abs(hab[0].puerta2.y-hab[2].puerta2.y);
    
    if (hab[2].puerta2.y < hab[0].puerta2.y) {
        for (int i = 1; i < pasillo2y; i++) {
            dibujo[((hab[0].puerta2.y*largo)+hab[0].puerta2.x+pasillo2x)-i*largo] = '#';
        }
    } else {
        for (int i = 1; i < pasillo2y; i++) {
            dibujo[((hab[0].puerta2.y*largo)+hab[0].puerta2.x+pasillo2x)+i*largo] = '#';
        }
    }
    if (hab[2].puerta2.x < hab[0].puerta2.x) {
        for (int i = 1; i <= pasillo2x /*+ pasillo1y*/; i++) {
            dibujo[(hab[0].puerta2.y*largo)+hab[0].puerta2.x-i-1+largo] = '#';
        }
    } else {
        for (int i = 1; i <= pasillo2x /*+ pasillo1y*/; i++) {
            dibujo[(hab[0].puerta2.y*largo)+hab[0].puerta2.x+i-1+largo] = '#';
        }
    }
    
    
    //AMULETO:
    //se encuentra en la habitación 3.
    hab[2].amuleto = true;
    hab[0].amuleto = false;
    hab[1].amuleto = false;
    hab[2].amul.x = hab[2].inicio.x+1+rand()%((hab[2].largo-1)-(hab[2].inicio.x+1));
    hab[2].amul.y = hab[2].inicio.y+1+rand()%((hab[2].alto-1)-(hab[2].inicio.y+1));
    dibujo[(hab[2].amul.y*largo)+hab[2].amul.x] = '&';
    
    //PUNTO DE ACCESO:
    //se encuentra en la habitación 1.
    hab[0].acceso.x = hab[0].inicio.x+1+rand()%((hab[0].largo-1)-(hab[0].inicio.x+1));
    hab[0].acceso.y = hab[0].inicio.y+1+rand()%((hab[0].alto-1)-(hab[0].inicio.y+1));
    dibujo[(hab[0].acceso.y*largo)+hab[0].acceso.x] = 'X';
    
    
    //MONSTRUOS:
    hab[0].n_mon = 0;
    hab[1].n_mon = 0;
    hab[2].n_mon = 0;
    int x,y;
    
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            x = hab[i].inicio.x+1+rand()%((hab[i].largo)-(hab[i].inicio.x+1));
            y = hab[i].inicio.y+1+rand()%((hab[i].alto)-(hab[i].inicio.y+1));
            if (dibujo[y*largo+x] == ' ') {
                hab[i].mon[j].fuerza = 5+rand()%(11-5);
                hab[i].mon[j].x = x;
                hab[i].mon[j].y = y;
                dibujo[y*largo+x] = 'o';
                hab[i].n_mon++;
            } else {
                j--;
            }
        }
    }
    
    /*
    x = hab[0].inicio.x+1+rand()%((hab[0].largo)-(hab[0].inicio.x+1));
    y = hab[0].inicio.y+1+rand()%((hab[0].alto-1)-(hab[0].inicio.y+1));
    if (dibujo[y*largo+x] == ' ') {
        hab[0].mon[0].x = x;
        hab[0].mon[0].y = y;
        dibujo[y*largo+x] = 'o';
    }
    x = hab[0].inicio.x+1+rand()%((hab[0].largo)-(hab[0].inicio.x+1));
    y = hab[0].inicio.y+1+rand()%((hab[0].alto-1)-(hab[0].inicio.y+1));
    if (dibujo[y*largo+x] == ' ') {
        hab[0].mon[1].x = x;
        hab[0].mon[1].y = y;
        dibujo[y*largo+x] = 'o';
    }
    x = hab[0].inicio.x+1+rand()%((hab[0].largo)-(hab[0].inicio.x+1));
    y = hab[0].inicio.y+1+rand()%((hab[0].alto-1)-(hab[0].inicio.y+1));
    if (dibujo[y*largo+x] == ' ') {
        hab[0].mon[2].x = x;
        hab[0].mon[2].y = y;
        dibujo[y*largo+x] = 'o';
    }
    */
}

mazmorra::mazmorra(string e){
    ifstream text;
    //text.open(e);
    
    
    char *m=new char[e.size()+1];
    m[e.size()]=0;
    memcpy(m,e.c_str(),e.size());
    
    text.open(m);
    
    
    string a = "Mazmorra_30_30.dat";
    string b = "Mazmorra_50_25.dat";
    if (text.is_open()) {
        if (a == e) {
            largo = 30;
            alto = 30;
            size = 30*30;
            hab[0].alto = 9;
            hab[0].largo = 7;
            hab[0].inicio.x = 2;
            hab[0].inicio.y = 3;
            hab[0].puerta1.x = 8;
            hab[0].puerta1.y = 5;
            hab[0].puerta2.x = 5;
            hab[0].puerta2.y = 11;
            hab[1].alto = 6;
            hab[1].largo = 13;
            hab[1].inicio.x = 15;
            hab[1].inicio.y = 1;
            hab[1].puerta1.x = 15;
            hab[1].puerta1.y = 5;
            hab[1].puerta2.x = 26;
            hab[1].puerta2.y = 6;
            hab[2].alto = 10;
            hab[2].largo = 19;
            hab[2].inicio.x = 5;
            hab[2].inicio.y = 17;
            hab[2].puerta1.x = 23;
            hab[2].puerta1.y = 20;
            hab[2].puerta2.x = 17;
            hab[2].puerta2.y = 17;
            
        } else if (b == e){
            largo = 50;
            alto = 25;
            size = 50*25;
            hab[0].alto = 10;
            hab[0].largo = 10;
            hab[0].inicio.x = 5;
            hab[0].inicio.y = 0;
            hab[0].puerta1.x = 14;
            hab[0].puerta1.y = 2;
            hab[0].puerta2.x = 7;
            hab[0].puerta2.y = 9;
            hab[1].alto = 7;
            hab[1].largo = 18;
            hab[1].inicio.x = 27;
            hab[1].inicio.y = 5;
            hab[1].puerta1.x = 27;
            hab[1].puerta1.y = 7;
            hab[1].puerta2.x = 34;
            hab[1].puerta2.y = 11;
            hab[2].alto = 10;
            hab[2].largo = 15;
            hab[2].inicio.x = 11;
            hab[2].inicio.y = 14;
            hab[2].puerta1.x = 25;
            hab[2].puerta1.y = 20;
            hab[2].puerta2.x = 18;
            hab[2].puerta2.y = 14;
        }
        dibujo = new char[size];
        //text.getline(dibujo, largo);
        char l;
        for (int i = 0; i < size; i++) {
            text.get(l);
            if (l != '\n' && l != '\t' && l != '\r') {
                dibujo[i] = l;
            } else if (l == '\n' || l == '\t' || l == '\r') {
                i--;
            }
        }
        cout << largo << endl;
        cout << strlen(dibujo) << endl;
    } else {
        cout << "el archivo no ha sido abierto" << endl;
    }
    for (int i = 0; i < size; i++) {
        if (dibujo[i] == 'X') {
            hab[0].acceso.y = i/largo;
            hab[0].acceso.x = i%largo;
        }
    }
    
    for (int i = 0; i < size; i++) {
        if (dibujo[i] == '&') {
            hab[2].amul.y = i/largo;
            hab[2].amul.x = i%largo;
        }
    }
    
    hab[0].n_mon = 0;
    hab[1].n_mon = 0;
    hab[2].n_mon = 0;
    int x,y;
    
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            x = hab[i].inicio.x+1+rand()%((hab[i].largo)-(hab[i].inicio.x+1));
            y = hab[i].inicio.y+1+rand()%((hab[i].alto)-(hab[i].inicio.y+1));
            if (dibujo[y*largo+x] == ' ') {
                hab[i].mon[j].fuerza = 5+rand()%(11-5);
                hab[i].mon[j].x = x;
                hab[i].mon[j].y = y;
                dibujo[y*largo+x] = 'o';
            } else {
                j--;
            }
        }
    }
}

void mazmorra::imprimir_mazmorra() {
    for (int i = 0; i < largo*alto; i++) {
        if (i != 0) {
            if (i%largo == 0) {
                cout << endl;
            }
        }
        cout << dibujo[i];
    }
}

int mazmorra::get_mon_f(int i, int j){
    return hab[i].mon[j].fuerza;
}

int mazmorra::get_mon_x(int i, int j){
    return hab[i].mon[j].x;
}

int mazmorra::get_mon_y(int i, int j){
    return hab[i].mon[j].y;
}

pos mazmorra::get_acceso() {
    return hab[0].acceso;
}

char mazmorra::get_dibujo(int i) {
    return dibujo[i];
}

void mazmorra::set_dibujo(int i, char a) {
    dibujo[i] = a;
}

int mazmorra::get_largo() {
    return largo;
}

int mazmorra::get_alto() {
    return alto;
}

int mazmorra::get_hab_inicio_x(int n){
    if (n == 1) {
        return hab[0].inicio.x;
    }
    if (n == 2) {
        return hab[1].inicio.x;
    }
    if (n == 3) {
        return hab[2].inicio.x;
    }
}
int mazmorra::get_hab_inicio_y(int n) {
    if (n == 1) {
        return hab[0].inicio.y;
    }
    if (n == 2) {
        return hab[1].inicio.y;
    }
    if (n == 3) {
        return hab[2].inicio.y;
    }
}
int mazmorra::get_hab_largo(int n){
    if (n == 1) {
        return hab[0].largo;
    }
    if (n == 2) {
        return hab[1].largo;
    }
    if (n == 3) {
        return hab[2].largo;
    }
}
int mazmorra::get_hab_alto(int n){
    if (n == 1) {
        return hab[0].alto;
    }
    if (n == 2) {
        return hab[1].alto;
    }
    if (n == 3) {
        return hab[2].alto;
    }
}

void mazmorra::set_hab_mon_x(int n1, int n2, pos a){
    if (n1 == 1 && n2 == 1) {
        hab[0].mon1.x = a.x;
    }
    if (n1 == 1 && n2 == 2) {
        hab[0].mon2.x = a.x;
    }
    if (n1 == 1 && n2 == 3) {
        hab[0].mon3.x = a.x;
    }
    if (n1 == 2 && n2 == 1) {
        hab[1].mon1.x = a.x;
    }
    if (n1 == 2 && n2 == 2) {
        hab[1].mon2.x = a.x;
    }
    if (n1 == 2 && n2 == 3) {
        hab[1].mon3.x = a.x;
    }
    if (n1 == 3 && n2 == 1) {
        hab[2].mon1.x = a.x;
    }
    if (n1 == 3 && n2 == 2) {
        hab[2].mon2.x = a.x;
    }
    if (n1 == 3 && n2 == 3) {
        hab[2].mon3.x = a.x;
    }
}
void mazmorra::set_hab_mon_y(int n1, int n2, pos a){
    if (n1 == 1 && n2 == 1) {
        hab[0].mon1.y = a.y;
    }
    if (n1 == 1 && n2 == 2) {
        hab[0].mon2.y = a.y;
    }
    if (n1 == 1 && n2 == 3) {
        hab[0].mon3.y = a.y;
    }
    if (n1 == 2 && n2 == 1) {
        hab[1].mon1.y = a.y;
    }
    if (n1 == 2 && n2 == 2) {
        hab[1].mon2.y = a.y;
    }
    if (n1 == 2 && n2 == 3) {
        hab[1].mon3.y = a.y;
    }
    if (n1 == 3 && n2 == 1) {
        hab[2].mon1.y = a.y;
    }
    if (n1 == 3 && n2 == 2) {
        hab[2].mon2.y = a.y;
    }
    if (n1 == 3 && n2 == 3) {
        hab[2].mon3.y = a.y;
    }
}

pos mazmorra::get_amul() {
    return hab[2].amul;
}

pos mazmorra::get_puerta1(int hab1) {
    return hab[hab1].puerta1;
}
pos mazmorra::get_puerta2(int hab1){
    return hab[hab1].puerta2;
}

void mazmorra::actualizar_monstruos(){
    int opcion = 0;
    pos ant[3][3];
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            opcion = rand()%4;
            if (opcion == 0) {
                if (dibujo[(hab[i].mon[j].y*largo+hab[i].mon[j].x)-largo] == ' ') {
                    ant[i][j].x = hab[i].mon[j].x;
                    ant[i][j].y = hab[i].mon[j].y;
                    hab[i].mon[j].y = hab[i].mon[j].y-1;
                    
                } else if ( (hab[i].mon[j].y*largo+hab[i].mon[j].x)-largo == '+') {
                    hab[i].mon[j].y = hab[0].puerta2.x;
                    hab[i].mon[j].y = hab[0].puerta2.y-1;
                }
                else {
                    opcion++;
                }
            }
            if (opcion == 1) {
                if (dibujo[(hab[i].mon[j].y*largo+hab[i].mon[j].x)+largo] == ' ') {
                    ant[i][j].x = hab[i].mon[j].x;
                    ant[i][j].y = hab[i].mon[j].y;
                    hab[i].mon[j].y = hab[i].mon[j].y+1;
                }else if ( (hab[i].mon[j].y*largo+hab[i].mon[j].x)+largo == '+') {
                    if (i == 0) {
                        hab[i].mon[j].y = hab[2].puerta2.x;
                        hab[i].mon[j].y = hab[2].puerta2.y+1;
                    } else if (i == 1) {
                        hab[i].mon[j].y = hab[2].puerta1.x;
                        hab[i].mon[j].y = hab[2].puerta1.y+1;
                    }
                }
                
                
                
                else {
                    opcion++;
                }
            }
            if (opcion == 2) {
                if (dibujo[(hab[i].mon[j].y*largo+hab[i].mon[j].x)-1] == ' ') {
                    ant[i][j].x = hab[i].mon[j].x;
                    ant[i][j].y = hab[i].mon[j].y;
                    hab[i].mon[j].x = hab[i].mon[j].x-1;
                }
                else if ( (hab[i].mon[j].y*largo+hab[i].mon[j].x)-1 == '+') {
                    hab[i].mon[j].y = hab[0].puerta1.x-1;
                    hab[i].mon[j].y = hab[0].puerta1.y;
                }
                else {
                    opcion++;
                }
            }
            if (opcion == 3) {
                if (dibujo[(hab[i].mon[j].y*largo+hab[i].mon[j].x)+1] == ' ') {
                    ant[i][j].x = hab[i].mon[j].x;
                    ant[i][j].y = hab[i].mon[j].y;
                    hab[i].mon[j].x = hab[i].mon[j].x+1;
                }
                else if ( (hab[i].mon[j].y*largo+hab[i].mon[j].x)+1 == '+') {
                    if (i == 0) {
                        hab[i].mon[j].y = hab[1].puerta1.x+1;
                        hab[i].mon[j].y = hab[1].puerta1.y;
                    } else if (i == 1) {
                        hab[i].mon[j].y = hab[1].puerta2.x+1;
                        hab[i].mon[j].y = hab[1].puerta2.y;
                    }
                }
                else {
                    ant[i][j].x = hab[i].mon[j].x;
                    ant[i][j].y = hab[i].mon[j].y;
                }
            }
        }
    }
    for (int k = 0; k < 3; k++) {
        for (int l = 0; l < 3; l++) {
            dibujo[ant[k][l].y*largo+ant[k][l].x] = ' ';
            dibujo[hab[k].mon[l].y*largo+hab[k].mon[l].x] = 'o';
        }
    }
}