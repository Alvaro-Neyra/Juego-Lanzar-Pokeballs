#include "Juego.h"

Juego::Juego() {
	cantidadEnemigos = rand() % 6 + 3;
}

Juego::~Juego() {

}
void Juego::crearEnemigos(int ancho, int alto) {
	for (int i = 0; i < cantidadEnemigos; i++) {
		Enemigo* enemigo = new Enemigo(ancho, alto, rand() % 2);
		enemigos.push_back(enemigo);
	}
}

void Juego::agregarBala(Bala* bala) {
	balas.push_back(bala);
}
void Juego::mover(Graphics^ panel) {
	for each (Enemigo* enemigo in enemigos) {
		enemigo->mover(panel);
	}

	for each (Bala* bala in balas) {
		bala->mover(panel);
	}
}
void Juego::dibujarTodo(Graphics ^ panel, Bitmap ^ imagenEnemigo, Bitmap ^ imagenBala) {
	for each (Enemigo* enemigo in enemigos) {
		enemigo->dibujar(panel, imagenEnemigo);
	}

	for each (Bala* bala in balas) {
		bala->dibujar(panel, imagenBala);
	}
}

void Juego::detectarColisiones(Graphics^ panel) {
	for (int i = 0; i < enemigos.size(); i++) {
		for (int j = 0; j < balas.size(); j++) {
			if (enemigos[i]->obtenerRectangulo().IntersectsWith(balas[j]->obtenerRectangulo())) {
				enemigos[i]->setVisibilidad(false);
				balas[j]->setVisibilidad(false);
			}
		}
	}

	for (int i = 0; i < balas.size(); i++) {
		if (balas[i]->getX() <= 0 || balas[i]->getXAncho() >= panel->VisibleClipBounds.Width ||
			balas[i]->getY() <= 0 || balas[i]->getYAlto() >= panel->VisibleClipBounds.Height) {
			balas[i]->setVisibilidad(false);
		}
	}

	for (int i = 0; i < enemigos.size(); i++) {
		if (!enemigos[i]->getVisibilidad()) {
			enemigos.erase(enemigos.begin() + i);
		}
	}

	for (int j = 0; j < balas.size(); j++) {
		if (!balas[j]->getVisibilidad()) {
			balas.erase(balas.begin() + j);
		}
	}
}
