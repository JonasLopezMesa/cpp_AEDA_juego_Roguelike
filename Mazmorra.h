//
//  Mazmorra.h
//  Roguelike
//
//  Created by jonas on 19/02/13.
//  Copyright (c) 2013 jonas. All rights reserved.
//

#ifndef __Roguelike__Mazmorra__
#define __Roguelike__Mazmorra__

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <fstream>
#include <stdio.h>
#include <string.h>
#include <termios.h>
//#include <ncurses.h>
using namespace std;

struct pos {
    int x;
    int y;
    int fuerza;
};

struct habitacion {
    int size;
    int largo;
    int alto;
    pos inicio;
    pos mon1,mon2,mon3;
    pos mon[3];
    bool amuleto;
    pos amul;
    pos puerta1, puerta2;
    pos acceso;
    int n_mon;
};

class mazmorra {
private:
    int size;
    int largo;
    int alto;
    char* dibujo;
    //obj_mazmorra objetos;
    habitacion hab[3];
    //habitacion hab1, hab2, hab3;
public:
    mazmorra();
    mazmorra(string e);
    void imprimir_mazmorra();
    pos get_acceso();
    char get_dibujo(int i);
    void set_dibujo(int i, char a);
    int get_largo();
    int get_alto();
    
    int get_hab_inicio_x(int n);
    int get_hab_inicio_y(int n);
    int get_hab_largo(int n);
    int get_hab_alto(int n);
    
    void set_hab_mon_x(int n1, int n2, pos a);
    void set_hab_mon_y(int n1, int n2, pos a);
    
    pos get_amul();
    pos get_puerta1(int hab);
    pos get_puerta2(int hab);
    
    void actualizar_monstruos();
    void comparacion(int i, int j);

int get_mon_x(int i, int j);
int get_mon_y(int i, int j);

int get_mon_f(int i, int j);
};

#endif /* defined(__Roguelike__Mazmorra__) */
