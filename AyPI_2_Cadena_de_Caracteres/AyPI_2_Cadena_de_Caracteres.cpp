#include <iostream>
using namespace std;
const int Tope = 100;

// Precondicion: @texto y @subTexto son cadenas de caracteres
// Postcondicion: Devuelve true si @subTexto se encuentra dentro de @texto caso contrario devuelve false
bool ContieneSubTexto(char texto[], char subTexto[]);

// Precondicion: @texto, @textoBusqueda y @textoReemplazo son cadenas de caracteres. La dimension de @texto
// es suficiente para realizar los reemplazos
// Postcondicion: Reemplaza todas las apariciones de @textoBusqueda que se encuentran en @texto por @textoReemplazo
void Reemplazar(char texto[], char textoBusqueda[], char textoReemplazo[]);

void PruebaReemplazar();
void VerificarResultado(const char nombrePruebaUnitaria[Tope], bool resultadoObtenido, bool resultadoEsperado);
void EjecutarPruebasUnitariasFuncionContieneSubTexto();
bool SonIguales(char cadena1[], char cadena2[]);

int main() {
	//PruebaReemplazar();
	EjecutarPruebasUnitariasFuncionContieneSubTexto();
	return 0;
}

bool EstaContenidaDesde(char texto[], int desde, char subTexto[]) {
	bool estaContenida = true;
	int indiceSubTexto = 0;
	for (int indiceTexto = desde; estaContenida && subTexto[indiceSubTexto] != '\0'; ++indiceTexto, ++indiceSubTexto) {
		estaContenida = texto[indiceTexto] == subTexto[indiceSubTexto];
	}

	return estaContenida && subTexto[indiceSubTexto] == '\0';
}

bool ContieneSubTexto(char texto[], char subTexto[]) {
	bool contieneSubTexto = false;
	int posicionTexto = 0;
	while (texto[posicionTexto] != '\0' && !contieneSubTexto) {
		if (EstaContenidaDesde(texto, posicionTexto, subTexto)) {
			contieneSubTexto = true;
		}

		++posicionTexto;
	}

	return contieneSubTexto;
}

int ContarCaracteres(char cadena[]);
void Copiar(char origen[], char destino[]);

// Not-Inplace:
void Reemplazar(char texto[], char textoBusqueda[], char textoReemplazo[]) {
	char copiaAuxiliar[Tope];
	int indiceCopiaAuxiliar = 0;
	int caracteresTextoBusqueda = ContarCaracteres(textoBusqueda);
	int caracteeresTextoReemplazo = ContarCaracteres(textoReemplazo);
	for (int indiceTexto = 0; texto[indiceTexto] != '\0';) {

		//Caso cuando texto en la posicion indiceTexto no contiene a textoBusqueda
		//
		copiaAuxiliar[indiceCopiaAuxiliar] = texto[indiceTexto];
		++indiceCopiaAuxiliar;
		++indiceTexto;
		// otro caso
		// Copiar en copia Auxiliar desde indiceCopiaAuxiliar la cadena textoReemplazo, avanzar indiceCopiaAxuliar una cantidad igual a el tamano de textoReemplzo
		// tambien tengo que hacer crecer el indiceTexto una cantidad igual al tamano de textoBusqueda
	}

	// Realizar los reemplazos en copiaAuxiliar

	Copiar(copiaAuxiliar, texto);
}

void PruebaReemplazar() {
	char texto[Tope] = "hola Juan hola Elvira";
	char textoBusqueda[Tope] = "hola";
	char reemplazo[Tope] = "chaucito";
	cout << texto << endl; // Muestra hola Juan hola Elvira
	Reemplazar(texto, textoBusqueda, reemplazo);
	cout << texto << endl; // Deberia mostrar chaucito Juan chaucito Elvira
}

void EjecutarPruebasUnitariasFuncionContieneSubTexto() {

	char subTexto2[Tope] = "CAS";
	char subTexto3[Tope] = "TOS";
	char subTexto4[Tope] = "MI";
	char subTexto5[Tope] = "CASAMIENTO";
	char subTexto6[Tope] = "CASAMIENTOS";


	char texto[Tope] = "CASAMIENTO";
	char subTexto1[Tope] = "CAL";

	bool resultadoObtenido = ContieneSubTexto(texto, subTexto1);

	VerificarResultado("Prueba CAL en CASAMIENTO",
		resultadoObtenido, false);


	VerificarResultado("Prueba CAS en CASAMIENTO",
		ContieneSubTexto(texto, subTexto2), true);
	VerificarResultado("Prueba TOS en CASAMIENTO",
		ContieneSubTexto(texto, subTexto3), false);
	VerificarResultado("Prueba MI en CASAMIENTO",
		ContieneSubTexto(texto, subTexto4), true);
	VerificarResultado("Prueba CASAMIENTO en CASAMIENTO",
		ContieneSubTexto(texto, subTexto5), true);
	VerificarResultado("Prueba CASAMIENTOS en CASAMIENTO",
		ContieneSubTexto(texto, subTexto6), false);
}

void VerificarResultado(const char nombrePruebaUnitaria[Tope], bool resultadoObtenido, bool resultadoEsperado) {
	if (resultadoObtenido == resultadoEsperado) {
		cout << "Prueba [" << nombrePruebaUnitaria << "]: OK!" << endl;
	}
	else {
		cout << "Prueba [" << nombrePruebaUnitaria << "]: BUG!" << endl;
	}
}


int ContarCaracteres(char cadena[]) {

}

void Copiar(char origen[], char destino[]) {

}

