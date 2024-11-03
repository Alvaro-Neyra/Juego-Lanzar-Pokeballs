#pragma once

using namespace System::Drawing;

class Bala
{
private:
	int x;
	int y;
	int dx;
	int dy;
	bool visibilidad;
	int ancho;
	int alto;
	char direccion;
public:
	Bala(int x, int y, int ancho, int alto, char direccion);
	~Bala();
	void mover(Graphics^ panel);
	void dibujar(Graphics^ panel, Bitmap^ imagenBala);
	int getXAncho();
	int getYAlto();
	int getX();
	int getY();
	void setVisibilidad(bool _visibilidad);
	bool getVisibilidad();
	Rectangle obtenerRectangulo();
};

