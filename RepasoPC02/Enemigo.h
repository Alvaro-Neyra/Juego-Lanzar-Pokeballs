#pragma once
#include <iostream>


using namespace System::Drawing;
using namespace std;

class Enemigo
{
private:
	int direccion;
	int x;
	int y;
	int dx;
	int dy;
	int ancho;
	int alto;
	int indiceX;
	int indiceY;
	bool visibilidad;
public:
	Enemigo(int ancho, int alto, int direccion);
	~Enemigo();
	void dibujar(Graphics^ panel, Bitmap^ imagenEnemigo);
	void mover(Graphics^ panel);
	bool getVisibilidad();
	void setVisibilidad(bool _visibilidad);
	Rectangle obtenerRectangulo();
};

