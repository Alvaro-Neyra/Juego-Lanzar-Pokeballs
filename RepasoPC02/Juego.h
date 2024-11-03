#pragma once
#include <iostream>
#include <vector>
#include "Enemigo.h"
#include "Bala.h"

using namespace std;

class Juego
{
private:
	vector<Enemigo*> enemigos;
	vector<Bala*> balas;
	int cantidadEnemigos;
public:
	Juego();
	~Juego();
	void crearEnemigos(int ancho, int alto);
	void agregarBala(Bala* bala);
	void mover(Graphics^ panel);
	void dibujarTodo(Graphics^ panel, Bitmap^ imagenEnemigo, Bitmap^ imagenBala);
	void detectarColisiones(Graphics^ panel);
};

