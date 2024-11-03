#include "Enemigo.h"

Enemigo::Enemigo(int ancho, int alto, int direccion) {
	this->alto = alto;
	this->ancho = ancho;
	this->direccion = direccion;
	this->dx = 20;
	this->dy = 20;
	this->x = rand() % 900;
	this->y = rand() % 200;
	this->indiceX = 0;
	this->indiceY = 0;
	this->visibilidad = true;
}

Enemigo::~Enemigo() {

}

void Enemigo::dibujar(Graphics^ panel, Bitmap^ imagenEnemigo) {
	Rectangle seccionAMostrar = Rectangle(indiceX * ancho, indiceY * alto, ancho, alto); // Solo * ancho y alto porque las dimensiones son correctas
	Rectangle zoom = Rectangle(x, y, ancho, alto);

	panel->DrawImage(imagenEnemigo, zoom, seccionAMostrar, GraphicsUnit::Pixel);
}

void Enemigo::mover(Graphics^ panel) {
	switch (direccion) {
		case 0:
			if (y + alto * 1.00 > panel->VisibleClipBounds.Height || y < 0) {
				dy *= -1;
			}

			if (dy > 0) {
				indiceY = 0;
			}
			else {
				indiceY = 3;
			}
			
			y += dy;
			break;
		case 1:

			if (x + ancho * 1.00 > panel->VisibleClipBounds.Width || x < 0) {
				dx *= -1;
			}

			if (dx > 0) {
				indiceY = 2;
			}
			else {
				indiceY = 1;
			}

			x += dx;
			break;
	}

	indiceX++;
	if (indiceX > 3) indiceX = 0;
}

bool Enemigo::getVisibilidad() {
	return this->visibilidad;
}

void Enemigo::setVisibilidad(bool _visibilidad) {
	this->visibilidad = _visibilidad;
}

Rectangle Enemigo::obtenerRectangulo() {
	return Rectangle(x, y, ancho * 1.00, alto * 1.00);
}
