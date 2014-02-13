//
//  Protagonista.cpp
//  Roguelike
//
//  Created by jonas on 19/02/13.
//  Copyright (c) 2013 jonas. All rights reserved.
//

#include "Protagonista.h"

prota::prota(mazmorra m1) {
    fuerza = 5+rand()%(11-5);
    habitacion = 1;
    vidas = 5;
    tiene_amuleto = false;
    posicion.x = m1.get_acceso().x+1;
    posicion.y = m1.get_acceso().y;
    m1.set_dibujo(posicion.y*m1.get_largo()+posicion.x, '@');
}

void prota::actualizar_posicion(int x, int y){
    posicion.x = x;
    posicion.y = y;
}

pos prota::get_posicion() {
    return posicion;
}

void prota::decrementar_vidas() {
    vidas = vidas-1;
}

int prota::get_fuerza() {
    return fuerza;
}

void prota::set_fuerza(int f) {
    fuerza = f;
}

int prota::n_vidas() {
    return vidas;
}

bool prota::amuleto_conseguido() {
    return tiene_amuleto;
}

bool prota::en_acceso(mazmorra m1) {
    if ((posicion.x == m1.get_acceso().x) && (posicion.y == m1.get_acceso().y)) {
        return true;
    } else {
        return false;
    }
}

int prota::get_habitacion() {
    return habitacion;
}

void prota::set_habitacion(int i){
    habitacion = i;
}

void prota::set_amuleto() {
    tiene_amuleto = true;
}