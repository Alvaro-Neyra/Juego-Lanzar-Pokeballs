#include "Heroe.h"


Heroe::Heroe(int ancho, int alto) {
	this->x = 70;
	this->y = 70;
	this->dx = 15;
	this->dy = 15;
	this->indiceX = 0;
	this->indiceY = 0;
	this->ancho = ancho;
	this->alto = alto;
	//this->direccion = 'D';
}

Heroe::~Heroe() {

}

void Heroe::dibujar(Graphics^ panel, Bitmap^ imagenHeroe) {
	Rectangle seccionAMostrar = Rectangle(indiceX * ancho, indiceY * alto, ancho, alto);
	Rectangle zoom = Rectangle(x, y, ancho, alto);
	panel->DrawImage(imagenHeroe, zoom, seccionAMostrar, GraphicsUnit::Pixel);
}

void Heroe::mover(Graphics^ panel, char tecla) {
	switch (tecla) {
		case 'S':
			if (y + alto < panel->VisibleClipBounds.Height) {
				indiceY = 0;
				y += dy;
				direccion = 'S';
			}
			break;
		case 'W':
			if (y > 0) {
				indiceY = 3;
				y -= dy;
				direccion = 'W';
			}
			break;
		case 'A':
			if (x > 0) {
				indiceY = 1;
				x -= dx;
				direccion = 'A';
			}
			break;
		case 'D':
			if (x + ancho < panel->VisibleClipBounds.Width) {
				indiceY = 2;
				x += dx;
				direccion = 'D';
			}
			break;
	}
	indiceX++;
	if (indiceX > 3) indiceX = 0;
}

char Heroe::obtenerDireccion() {
	return this->direccion;
}

int Heroe::obtenerX() {
	return this->x;
}

int Heroe::obtenerY() {
	return this->y;
}