//
//  Protagonista.h
//  Roguelike
//
//  Created by jonas on 19/02/13.
//  Copyright (c) 2013 jonas. All rights reserved.
//

#ifndef __Roguelike__Protagonista__
#define __Roguelike__Protagonista__


#include "Mazmorra.h"

class prota{
private:
    int fuerza;
    pos posicion;
    int vidas;
    bool tiene_amuleto;
    int habitacion;
public:
    prota(mazmorra m1);
    void actualizar_posicion(int x, int y);
    pos get_posicion();
    void decrementar_vidas();
    int n_vidas();
    bool amuleto_conseguido();
    bool en_acceso(mazmorra m1);
    int get_habitacion();
    void set_habitacion(int i);
    void set_amuleto();
    int get_fuerza();
    void set_fuerza(int f);
};

#endif /* defined(__Roguelike__Protagonista__) */
