#pragma once
#include "Heroe.h"
#include "Juego.h"

namespace RepasoPC02 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for JuegoForm
	/// </summary>
	public ref class JuegoForm : public System::Windows::Forms::Form
	{
	public:
		JuegoForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			panel = pnlCanvas->CreateGraphics();
			contexto = BufferedGraphicsManager::Current;
			buffer = contexto->Allocate(panel, pnlCanvas->ClientRectangle);

			imagenHeroe = gcnew Bitmap("hero.png");
			imagenFondo = gcnew Bitmap("fondo.png");
			imagenEnemigo = gcnew Bitmap("bruno.png");
			imagenBala = gcnew Bitmap("pokeball.png");

			heroe = new Heroe(imagenHeroe->Width / 4, imagenHeroe->Height / 4);
			juego = new Juego();

			juego->crearEnemigos(imagenEnemigo->Width / 4, imagenEnemigo->Height / 4);

			indice = 0;
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~JuegoForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^ pnlCanvas;
	protected:

	protected:
	private: System::Windows::Forms::Timer^ timer1;
	private: System::ComponentModel::IContainer^ components;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		Graphics^ panel;
		BufferedGraphicsContext^ contexto;
		BufferedGraphics^ buffer;

		Bitmap^ imagenHeroe;
		Bitmap^ imagenFondo;
		Bitmap^ imagenEnemigo;
		Bitmap^ imagenBala;

		Heroe* heroe;
		Juego* juego;
		int indice;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->pnlCanvas = (gcnew System::Windows::Forms::Panel());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->SuspendLayout();
			// 
			// pnlCanvas
			// 
			this->pnlCanvas->Location = System::Drawing::Point(4, 6);
			this->pnlCanvas->Name = L"pnlCanvas";
			this->pnlCanvas->Size = System::Drawing::Size(1491, 890);
			this->pnlCanvas->TabIndex = 0;
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Tick += gcnew System::EventHandler(this, &JuegoForm::timer1_Tick);
			// 
			// JuegoForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1494, 899);
			this->Controls->Add(this->pnlCanvas);
			this->Name = L"JuegoForm";
			this->Text = L"JuegoForm";
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &JuegoForm::JuegoForm_KeyDown);
			this->Resize += gcnew System::EventHandler(this, &JuegoForm::JuegoForm_Resize);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
		buffer->Graphics->Clear(Color::White);

		buffer->Graphics->DrawImage(imagenFondo, 0, 0, pnlCanvas->Width, pnlCanvas->Height);

		juego->detectarColisiones(buffer->Graphics);

		juego->mover(buffer->Graphics);

		heroe->dibujar(buffer->Graphics, imagenHeroe);

		juego->dibujarTodo(buffer->Graphics, imagenEnemigo, imagenBala);

		buffer->Render(panel);
	}
	private: System::Void JuegoForm_Resize(System::Object^ sender, System::EventArgs^ e) {
		//pnlCanvas->Width = this->ClientSize.Width - 20;
		//pnlCanvas->Height = this->ClientSize.Height - 40;
	}

	private: System::Void JuegoForm_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		switch (e->KeyCode) {
			case Keys::W:
				heroe->mover(buffer->Graphics, 'W');
				break;
			case Keys::S:
				heroe->mover(buffer->Graphics, 'S');
				break;
			case Keys::D:
				heroe->mover(buffer->Graphics, 'D');
				break;
			case Keys::A:
				heroe->mover(buffer->Graphics, 'A');
				break;
			case Keys::Space:
				juego->agregarBala(new Bala(heroe->obtenerX(), heroe->obtenerY(), imagenBala->Width, imagenBala->Height, heroe->obtenerDireccion()));
				break;
		}
	}
};
}
