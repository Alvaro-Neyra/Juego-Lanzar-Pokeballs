#pragma once

using namespace System::Drawing;

class Heroe
{
private:
	int x;
	int y;
	int dx;
	int dy;
	int ancho;
	int alto;
	int indiceX;
	int indiceY;
	char direccion;
public:
	Heroe(int ancho, int alto);
	~Heroe();
	void dibujar(Graphics^ panel, Bitmap^ imagenHeroe);
	void mover(Graphics^ panel, char tecla);
	char obtenerDireccion();
	int obtenerX();
	int obtenerY();
};

