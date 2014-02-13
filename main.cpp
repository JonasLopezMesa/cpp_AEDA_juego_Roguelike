//
//  main.cpp
//  Roguelike
//
//  Created by jonas on 19/02/13.
//  Copyright (c) 2013 jonas. All rights reserved.
//


#include "Mazmorra.h"
#include "Protagonista.h"


void imprimir_sta(prota p1) {
    
    cout << "VIDAS: " << p1.n_vidas() << "   AMULETO: ";
    if (p1.amuleto_conseguido() == true) {
        cout << "conseguido!!!";
    } else {
        cout << "buscando...";
    }
    cout << endl;
    cout << "HABITACIÓN ACTUAL: " << p1.get_habitacion() << endl;
    cout << "FUERZA: " << p1.get_fuerza() << endl;
}

int main()
{
    
    system("clear");
    cout << "*************************************************************" << endl;
    cout << "*************************************************************" << endl;
    cout << "**  ¡¡¡Bienvenido al videojuego de mazmorras Roguelike!!!  **" << endl;
    cout << "**---------------------------------------------------------**" << endl;
    cout << "**           1    - Generar Mapa Aleatoriamente            **" << endl;
    cout << "**           2    - Cargar un mapa predefinido             **" << endl;
    cout << "*************************************************************" << endl;
    cout << "*************************************************************" << endl;
    cout << "  Selecciona la opción que desees:   ";
    int elec = 0;
    cin >> elec;
    system("clear");
    if (elec == 1) {
        mazmorra m1;
        prota p1(m1);
        int comprobante = 0;
        while (comprobante == 0) {
            system("clear");
            imprimir_sta(p1);
            pos pos_anterior;
            m1.imprimir_mazmorra();
            if ((m1.get_dibujo((p1.get_posicion().y*m1.get_largo()+p1.get_posicion().x)+1) == 'o') || (m1.get_dibujo((p1.get_posicion().y*m1.get_largo()+p1.get_posicion().x)-1) == 'o') || (m1.get_dibujo((p1.get_posicion().y*m1.get_largo()+p1.get_posicion().x)+m1.get_largo()) == 'o') || (m1.get_dibujo((p1.get_posicion().y*m1.get_largo()+p1.get_posicion().x)-m1.get_largo()) == 'o')) {
                
                if (p1.get_fuerza() != 0) {
                    int seleci = 0;
                    int selecj = 0;
                    for (int i = 0; i < 3; i++) {
                        for (int j = 0; j < 3; j++) {
                            if ((m1.get_mon_x(i, j) == (p1.get_posicion().x+1)) && (m1.get_mon_y(i, j) == p1.get_posicion().y)) {
                                seleci = i;
                                selecj = j;
                            }
                            else if ((m1.get_mon_x(i, j) == (p1.get_posicion().x-1)) && (m1.get_mon_y(i, j) == p1.get_posicion().y)) {
                                seleci = i;
                                selecj = j;
                            }
                            else if ((m1.get_mon_x(i, j) == (p1.get_posicion().x+m1.get_largo())) && (m1.get_mon_y(i, j) == p1.get_posicion().y)) {
                                seleci = i;
                                selecj = j;
                            }
                            else if ((m1.get_mon_x(i, j) == (p1.get_posicion().x-m1.get_largo())) && (m1.get_mon_y(i, j) == p1.get_posicion().y)) {
                                seleci = i;
                                selecj = j;
                            }
                        }
                    }
                    if (m1.get_mon_f(seleci, selecj) <= p1.get_fuerza()) {
                        p1.set_fuerza(p1.get_fuerza()-m1.get_mon_f(seleci, selecj));
                    } else if (p1.get_fuerza() < m1.get_mon_f(seleci, selecj)){
                        p1.set_fuerza(0);
                    }
                }
                else if (p1.get_fuerza() == 0) {
                    p1.decrementar_vidas();
                }
                
                
                
                
            }
            if (p1.amuleto_conseguido() == true) {
                m1.set_dibujo(m1.get_amul().y*m1.get_largo()+m1.get_amul().x, ' ');
            }
            int valid = 0;
            char opcion;
            
            while (valid == 0) {
                cin >> opcion;
                if (opcion == 'i') {
                    cout << "i" << endl;
                    if ((m1.get_dibujo((p1.get_posicion().y*m1.get_largo()+p1.get_posicion().x)-m1.get_largo()) == '&')) {
                        p1.set_amuleto();
                    }
                        if ((m1.get_dibujo((p1.get_posicion().y*m1.get_largo()+p1.get_posicion().x)-m1.get_largo()) == '*')) {
                            cout << "NO PUEDES IR EN ESA DIRECCIÓN" << endl;
                        }else if ((m1.get_dibujo((p1.get_posicion().y*m1.get_largo()+p1.get_posicion().x)-m1.get_largo()) == '+')) {
                            pos_anterior.x = p1.get_posicion().x;
                            pos_anterior.y = p1.get_posicion().y;
                            p1.actualizar_posicion(m1.get_puerta2(0).x, m1.get_puerta2(0).y-1);
                            p1.set_habitacion(1);
                            valid = 1;
                        } else {
                            cout << "i" << endl;
                            pos_anterior.x = p1.get_posicion().x;
                            pos_anterior.y = p1.get_posicion().y;
                            p1.actualizar_posicion(p1.get_posicion().x, p1.get_posicion().y-1);
                            cout << "x: " << p1.get_posicion().x << "y: " << p1.get_posicion().y << endl;
                            valid = 1;
                        }
                } else if (opcion == 'k') {
                    if ((m1.get_dibujo((p1.get_posicion().y*m1.get_largo()+p1.get_posicion().x)+m1.get_largo()) == '&')) {
                        p1.set_amuleto();
                    }
                    if ((m1.get_dibujo((p1.get_posicion().y*m1.get_largo()+p1.get_posicion().x)+m1.get_largo()) == '*')) {
                        cout << "NO PUEDES IR EN ESA DIRECCIÓN" << endl;
                    }else if ((m1.get_dibujo((p1.get_posicion().y*m1.get_largo()+p1.get_posicion().x)+m1.get_largo()) == '+')){
                        if (p1.get_habitacion() == 1) {
                            pos_anterior.x = p1.get_posicion().x;
                            pos_anterior.y = p1.get_posicion().y;
                            p1.actualizar_posicion(m1.get_puerta2(2).x, m1.get_puerta2(2).y+1);
                            p1.set_habitacion(3);
                            valid = 1;
                        } else if (p1.get_habitacion() == 2) {
                            pos_anterior.x = p1.get_posicion().x;
                            pos_anterior.y = p1.get_posicion().y;
                            p1.actualizar_posicion(m1.get_puerta1(2).x-1, m1.get_puerta1(2).y);
                            p1.set_habitacion(3);
                            valid = 1;
                        }
                    }else {
                        cout << "i" << endl;
                        pos_anterior.x = p1.get_posicion().x;
                        pos_anterior.y = p1.get_posicion().y;
                        p1.actualizar_posicion(p1.get_posicion().x, p1.get_posicion().y+1);
                        cout << "x: " << p1.get_posicion().x << "y: " << p1.get_posicion().y << endl;
                        valid = 1;
                    }
                } else if (opcion == 'j') {
                    if ((m1.get_dibujo((p1.get_posicion().y*m1.get_largo()+p1.get_posicion().x)-1) == '&')) {
                        p1.set_amuleto();
                    }
                    if ((m1.get_dibujo((p1.get_posicion().y*m1.get_largo()+p1.get_posicion().x)-1) == '*')) {
                        cout << "NO PUEDES IR EN ESA DIRECCIÓN" << endl;
                    }else if ((m1.get_dibujo((p1.get_posicion().y*m1.get_largo()+p1.get_posicion().x)-1) == '+')){
                        pos_anterior.x = p1.get_posicion().x;
                        pos_anterior.y = p1.get_posicion().y;
                        p1.actualizar_posicion(m1.get_puerta1(0).x-1, m1.get_puerta1(0).y);
                        p1.set_habitacion(1);
                        valid = 1;
                    }else {
                        pos_anterior = p1.get_posicion();
                        p1.actualizar_posicion(p1.get_posicion().x-1, p1.get_posicion().y);
                        valid = 1;
                    }
                } else if (opcion == 'l') {
                    if ((m1.get_dibujo((p1.get_posicion().y*m1.get_largo()+p1.get_posicion().x)+1) == '&')) {
                        p1.set_amuleto();
                    }
                    if ((m1.get_dibujo((p1.get_posicion().y*m1.get_largo()+p1.get_posicion().x)+1) == '*')) {
                        cout << "NO PUEDES IR EN ESA DIRECCIÓN" << endl;
                    }else if ((m1.get_dibujo((p1.get_posicion().y*m1.get_largo()+p1.get_posicion().x)+1) == '+')){
                        if (p1.get_habitacion() == 1) {
                            pos_anterior.x = p1.get_posicion().x;
                            pos_anterior.y = p1.get_posicion().y;
                            p1.actualizar_posicion(m1.get_puerta1(1).x+1, m1.get_puerta1(1).y);
                            p1.set_habitacion(2);
                            valid = 1;
                        } else if (p1.get_habitacion() == 3) {
                            pos_anterior.x = p1.get_posicion().x;
                            pos_anterior.y = p1.get_posicion().y;
                            p1.actualizar_posicion(m1.get_puerta2(1).x, m1.get_puerta2(1).y-1);
                            p1.set_habitacion(2);
                            valid = 1;
                        }
                    }else {
                        pos_anterior = p1.get_posicion();
                        p1.actualizar_posicion(p1.get_posicion().x+1, p1.get_posicion().y);
                        valid = 1;
                    }
                }
            }
            m1.set_dibujo(pos_anterior.y*m1.get_largo()+pos_anterior.x, ' ');
            m1.set_dibujo(p1.get_posicion().y*m1.get_largo()+p1.get_posicion().x, '@');
            m1.actualizar_monstruos();
            
            if (p1.n_vidas() <= 0 ) {
                comprobante = 1;
                char msn_perdida[] = "**PERDISTE**";
                for (int i = 0; i < 12; i++) {
                    m1.set_dibujo(((m1.get_alto()/2)*m1.get_largo()+((m1.get_largo()-12)/2)+i), msn_perdida[i]);
                }
                system("clear");
                imprimir_sta(p1);
                m1.imprimir_mazmorra();
            }
            if (p1.en_acceso(m1) == true && p1.amuleto_conseguido() == true) {
                comprobante = 1;
                char msn_perdida[] = "**VICTORIA**";
                for (int i = 0; i < 11; i++) {
                    m1.set_dibujo(((m1.get_alto()/2)*m1.get_largo()+((m1.get_largo()-11)/2)+i), msn_perdida[i]);
                }
                system("clear");
                imprimir_sta(p1);
                m1.imprimir_mazmorra();
            }
        }
        
    } else if (elec == 2) {
        cout << "introduce el nombre del fichero que deseas cargar: " << endl;
        cout << "Ficheros disponibles: " << endl;
        cout << "1    - Mazmorra_30_30.dat" << endl;
        cout << "2    - Mazmorra_50_25.dat" << endl;
        string eleccion;
        cin >> eleccion;
        mazmorra m1(eleccion);
        prota p1(m1);
        int comprobante = 0;
        while (comprobante == 0) {
            system("clear");
            imprimir_sta(p1);
            pos pos_anterior;
            m1.imprimir_mazmorra();
            if ((m1.get_dibujo((p1.get_posicion().y*m1.get_largo()+p1.get_posicion().x)+1) == 'o') || (m1.get_dibujo((p1.get_posicion().y*m1.get_largo()+p1.get_posicion().x)-1) == 'o') || (m1.get_dibujo((p1.get_posicion().y*m1.get_largo()+p1.get_posicion().x)+m1.get_largo()) == 'o') || (m1.get_dibujo((p1.get_posicion().y*m1.get_largo()+p1.get_posicion().x)-m1.get_largo()) == 'o')) {
                p1.decrementar_vidas();
            }
            if (p1.amuleto_conseguido() == true) {
                m1.set_dibujo(m1.get_amul().y*m1.get_largo()+m1.get_amul().x, ' ');
            }
            int valid = 0;
            char opcion;
            
            while (valid == 0) {
                cin >> opcion;
                //opcion = getch();
                if (opcion == 'i') {
                    cout << "i" << endl;
                    if ((m1.get_dibujo((p1.get_posicion().y*m1.get_largo()+p1.get_posicion().x)-m1.get_largo()) == '&')) {
                        p1.set_amuleto();
                    }
                    if ((m1.get_dibujo((p1.get_posicion().y*m1.get_largo()+p1.get_posicion().x)-m1.get_largo()) == '*')) {
                        cout << "NO PUEDES IR EN ESA DIRECCIÓN" << endl;
                    }else if ((m1.get_dibujo((p1.get_posicion().y*m1.get_largo()+p1.get_posicion().x)-m1.get_largo()) == '+')) {
                        pos_anterior.x = p1.get_posicion().x;
                        pos_anterior.y = p1.get_posicion().y;
                        p1.actualizar_posicion(m1.get_puerta2(0).x, m1.get_puerta2(0).y-1);
                        p1.set_habitacion(1);
                        valid = 1;
                    } else {
                        cout << "i" << endl;
                        pos_anterior.x = p1.get_posicion().x;
                        pos_anterior.y = p1.get_posicion().y;
                        p1.actualizar_posicion(p1.get_posicion().x, p1.get_posicion().y-1);
                        cout << "x: " << p1.get_posicion().x << "y: " << p1.get_posicion().y << endl;
                        valid = 1;
                    }
                } else if (opcion == 'k') {
                    if ((m1.get_dibujo((p1.get_posicion().y*m1.get_largo()+p1.get_posicion().x)+m1.get_largo()) == '&')) {
                        p1.set_amuleto();
                    }
                    if ((m1.get_dibujo((p1.get_posicion().y*m1.get_largo()+p1.get_posicion().x)+m1.get_largo()) == '*')) {
                        cout << "NO PUEDES IR EN ESA DIRECCIÓN" << endl;
                    }else if ((m1.get_dibujo((p1.get_posicion().y*m1.get_largo()+p1.get_posicion().x)+m1.get_largo()) == '+')){
                        if (p1.get_habitacion() == 1) {
                            pos_anterior.x = p1.get_posicion().x;
                            pos_anterior.y = p1.get_posicion().y;
                            p1.actualizar_posicion(m1.get_puerta2(2).x, m1.get_puerta2(2).y+1);
                            p1.set_habitacion(3);
                            valid = 1;
                        } else if (p1.get_habitacion() == 2) {
                            pos_anterior.x = p1.get_posicion().x;
                            pos_anterior.y = p1.get_posicion().y;
                            p1.actualizar_posicion(m1.get_puerta1(2).x-1, m1.get_puerta1(2).y);
                            p1.set_habitacion(3);
                            valid = 1;
                        }
                    }else {
                        cout << "i" << endl;
                        pos_anterior.x = p1.get_posicion().x;
                        pos_anterior.y = p1.get_posicion().y;
                        p1.actualizar_posicion(p1.get_posicion().x, p1.get_posicion().y+1);
                        cout << "x: " << p1.get_posicion().x << "y: " << p1.get_posicion().y << endl;
                        valid = 1;
                    }
                } else if (opcion == 'j') {
                    if ((m1.get_dibujo((p1.get_posicion().y*m1.get_largo()+p1.get_posicion().x)-1) == '&')) {
                        p1.set_amuleto();
                    }
                    if ((m1.get_dibujo((p1.get_posicion().y*m1.get_largo()+p1.get_posicion().x)-1) == '*')) {
                        cout << "NO PUEDES IR EN ESA DIRECCIÓN" << endl;
                    }else if ((m1.get_dibujo((p1.get_posicion().y*m1.get_largo()+p1.get_posicion().x)-1) == '+')){
                        pos_anterior.x = p1.get_posicion().x;
                        pos_anterior.y = p1.get_posicion().y;
                        p1.actualizar_posicion(m1.get_puerta1(0).x-1, m1.get_puerta1(0).y);
                        p1.set_habitacion(1);
                        valid = 1;
                    }else {
                        pos_anterior = p1.get_posicion();
                        p1.actualizar_posicion(p1.get_posicion().x-1, p1.get_posicion().y);
                        valid = 1;
                    }
                } else if (opcion == 'l') {
                    if ((m1.get_dibujo((p1.get_posicion().y*m1.get_largo()+p1.get_posicion().x)+1) == '&')) {
                        p1.set_amuleto();
                    }
                    if ((m1.get_dibujo((p1.get_posicion().y*m1.get_largo()+p1.get_posicion().x)+1) == '*')) {
                        cout << "NO PUEDES IR EN ESA DIRECCIÓN" << endl;
                    }else if ((m1.get_dibujo((p1.get_posicion().y*m1.get_largo()+p1.get_posicion().x)+1) == '+')){
                        if (p1.get_habitacion() == 1) {
                            pos_anterior.x = p1.get_posicion().x;
                            pos_anterior.y = p1.get_posicion().y;
                            p1.actualizar_posicion(m1.get_puerta1(1).x+1, m1.get_puerta1(1).y);
                            p1.set_habitacion(2);
                            valid = 1;
                        } else if (p1.get_habitacion() == 3) {
                            pos_anterior.x = p1.get_posicion().x;
                            pos_anterior.y = p1.get_posicion().y;
                            p1.actualizar_posicion(m1.get_puerta2(1).x, m1.get_puerta2(1).y-1);
                            p1.set_habitacion(2);
                            valid = 1;
                        }
                    }else {
                        pos_anterior = p1.get_posicion();
                        p1.actualizar_posicion(p1.get_posicion().x+1, p1.get_posicion().y);
                        valid = 1;
                    }
                }
            }
            m1.set_dibujo(pos_anterior.y*m1.get_largo()+pos_anterior.x, ' ');
            m1.set_dibujo(p1.get_posicion().y*m1.get_largo()+p1.get_posicion().x, '@');
            m1.actualizar_monstruos();
            
            if (p1.n_vidas() <= 0 ) {
                comprobante = 1;
                char msn_perdida[] = "**PERDISTE**";
                for (int i = 0; i < 12; i++) {
                    m1.set_dibujo(((m1.get_alto()/2)*m1.get_largo()+((m1.get_largo()-12)/2)+i), msn_perdida[i]);
                }
                system("clear");
                imprimir_sta(p1);
                m1.imprimir_mazmorra();
            }
            if (p1.en_acceso(m1) == true && p1.amuleto_conseguido() == true) {
                comprobante = 1;
                char msn_perdida[] = "**VICTORIA**";
                for (int i = 0; i < 11; i++) {
                    m1.set_dibujo(((m1.get_alto()/2)*m1.get_largo()+((m1.get_largo()-11)/2)+i), msn_perdida[i]);
                }
                system("clear");
                imprimir_sta(p1);
                m1.imprimir_mazmorra();
            }
        }
    }
}

