#include "Bala.h"


Bala::Bala(int x, int y, int ancho, int alto, char direccion) {
	this->x = x;
	this->y = y;
	this->dx = 30;
	this->dy = 30;
	this->ancho = ancho;
	this->alto = alto;
	this->direccion = direccion;
	this->visibilidad = true;
}

Bala::~Bala() {

}

void Bala::mover(Graphics^ panel) {
	if (direccion == 'S' && y + alto * 0.03 <= panel->VisibleClipBounds.Height) {
		y += dy;
	}
	if (direccion == 'W' && y >= 0) {
		y -= dy;
	}
	if (direccion == 'A' && x >= 0) {
		x -= dx;
	}
	if (direccion == 'D' && x + ancho * 0.03 <= panel->VisibleClipBounds.Width) {
		x += dx;
	}
}

void Bala::dibujar(Graphics^ panel, Bitmap^ imagenBala) {
	panel->DrawImage(imagenBala, x, y, ancho * 0.03, alto * 0.03);
}

int Bala::getXAncho() {
	return this->x + ancho * 0.03;
}

int Bala::getYAlto() {
	return this->y + alto * 0.03;
}

int Bala::getX() {
	return this->x;
}

int Bala::getY() {
	return this->y;
}

void Bala::setVisibilidad(bool _visibilidad) {
	this->visibilidad = _visibilidad;
}

bool Bala::getVisibilidad() {
	return this->visibilidad;
}

Rectangle Bala::obtenerRectangulo() {
	return Rectangle(x, y, ancho * 0.03, alto * 0.03);
}