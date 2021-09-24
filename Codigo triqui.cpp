#include<iostream>
#include<stdlib.h>
#include<time.h>
#include<stdio.h>
#include<string>
#include<vector>
#include <cstdlib> // libreria que contiene atoi convertir cadenas a int o float
using namespace std;
int cti(string cl){ // funcion que convierte cadena a int
        return atof(cl.c_str());
}
void mostrar(string Triqui[3][3]){ // mostrar por pantalla el juego del triqui actual
	cout<<"-------"<<endl;
	for(int ii=0;ii<3;ii++){
		for(int jj=0;jj<3;jj++){
			if(Triqui[ii][jj]!="C" && Triqui[ii][jj]!="H"){
				cout<<"|"<<" ";
			}
			else{
				cout<<"|"<<Triqui[ii][jj];
			}
		}
		cout<<"|"<<endl;
		cout<<"-------"<<endl;
	}
	cout<<endl;
}
bool pertenece(vector<int> v,int x){ // verifica si el numero x pertenece al vector v
	bool mm=false;
	for(int ii=0;ii<v.size();ii++){
		if(v.at(ii)==x){
			mm=true;
			break;
		}
	}
	return mm;
}
void resetear(string Triqui[3][3]){ // resetea el juego para volver a jugar
	for(int ii=0;ii<3;ii++){
		for(int jj=0;jj<3;jj++){
			Triqui[ii][jj]=" ";
		}
	}
}
int eleccion_computador(string Triqui[3][3],int casillas_ocupadas){ // la computadora analiza el juego y toma una eleccion
	srand(time(NULL));
	int eleccion;
	int contador;
	contador=1;
	if(casillas_ocupadas>=3){ // para que el computador escoja una casilla que al marcarla gane el juego debe existir por lo menos 3 casillas ya jugadas
		for(int ii=0;ii<3;ii++){
			for(int jj=0;jj<3;jj++){
				if(Triqui[ii][jj]=="C" || Triqui[ii][jj]=="H"){
					casillas_ocupadas+=1;
				}
			}
		}
		contador=1;
		for(int ii=0;ii<3;ii++){ //verifica en cada fila del triqui si hay un lugar en el cual el computador pueda ganar o bloquear un lugar 
//para que el humano no gane en la siguiente partida 		
			if(Triqui[ii][0]=="C" && Triqui[ii][1]=="C" && Triqui[ii][2]!="H" || Triqui[ii][0]=="H" && Triqui[ii][1]=="H" && Triqui[ii][2]!="C"){
				eleccion=contador+2;
			}
			if(Triqui[ii][0]=="C" && Triqui[ii][1]!="H" && Triqui[ii][2]=="C" || Triqui[ii][0]=="H" && Triqui[ii][1]!="C" && Triqui[ii][2]=="H"){
				eleccion=contador+1;
			}
			if(Triqui[ii][0]!="H" && Triqui[ii][1]=="C" && Triqui[ii][2]=="C" || Triqui[ii][0]!="C" && Triqui[ii][1]=="H" && Triqui[ii][2]=="H"){
				eleccion=contador;
			}
			contador=contador+3;
		}
		contador=7;
		for(int ii=0;ii<3;ii++){ //verifica en cada columna del triqui si hay un lugar en el cual el computador pueda ganar o bloquear un lugar 
//para que el humano no gane en la siguiente partida 
			if(Triqui[0][ii]=="C" && Triqui[1][ii]=="C" && Triqui[2][ii]!="H" || Triqui[0][ii]=="H" && Triqui[1][ii]=="H" && Triqui[2][ii]!="C"){
				eleccion=contador;
			}
			if(Triqui[0][ii]=="C" && Triqui[1][ii]!="H" && Triqui[2][ii]=="C" || Triqui[0][ii]=="H" && Triqui[1][ii]!="C" && Triqui[2][ii]=="H"){
				eleccion=contador-3;
			}
			if(Triqui[0][ii]!="H" && Triqui[1][ii]=="C" && Triqui[2][ii]=="C" || Triqui[0][ii]!="C" && Triqui[1][ii]=="H" && Triqui[2][ii]=="H"){
				eleccion=contador-6; 
			}
			contador=contador+1;
		} //verifica las diagonales del triqui si hay un lugar en el cual el computador pueda ganar o bloquear un lugar 
//para que el humano no gane en la siguiente partida 
		if(Triqui[0][0]=="C" && Triqui[1][1]=="C" && Triqui[2][2]!="H" || Triqui[0][0]=="H" && Triqui[1][1]=="H" && Triqui[2][2]!="C"){
			eleccion=9;
		}
		if(Triqui[0][0]=="C" && Triqui[1][1]!="H" && Triqui[2][2]=="C" || Triqui[0][0]=="H" && Triqui[1][1]!="C" && Triqui[2][2]=="H"){
			eleccion=5;
		}
		if(Triqui[0][0]!="H" && Triqui[1][1]=="C" && Triqui[2][2]=="C" || Triqui[0][0]!="C" && Triqui[1][1]=="H" && Triqui[2][2]=="H"){
			eleccion=1;
		}
		if(Triqui[2][0]=="C" && Triqui[1][1]=="C" && Triqui[0][2]!="H" || Triqui[2][0]=="H" && Triqui[1][1]=="H" && Triqui[0][2]!="C"){
			eleccion=3;
		}
		if(Triqui[2][0]=="C" && Triqui[1][1]!="H" && Triqui[0][2]=="C" || Triqui[2][0]=="H" && Triqui[1][1]!="C" && Triqui[0][2]=="H"){
			eleccion=5;
		}
		if(Triqui[2][0]!="H" && Triqui[1][1]=="C" && Triqui[0][2]=="C" || Triqui[2][0]!="C" && Triqui[1][1]=="H" && Triqui[0][2]=="H"){
			eleccion=7;
		}
		if(eleccion!=1 && eleccion!=2 && eleccion!=3 && eleccion!=4 && eleccion!=5 && eleccion!=6 && eleccion!=7 && eleccion!=8 && eleccion!=9){
		eleccion=14;
		}
	}else{
		eleccion=14;
	}
	if(eleccion==14){ //si no hay una casilla en la cual el computador pueda ganar o el computador pueda bloquear al humano se busca una casilla vacia 
	//y el computador toma una aleatoria 
		int cont=1;
		vector<int> casillas_vacias;
		for(int ii=0;ii<3;ii++){ //se le agrega al vector casillas_vacias las posiciones de las casillas del triqui vacias 
			for(int jj=0;jj<3;jj++){
				if(Triqui[ii][jj]!="C" && Triqui[ii][jj]!="H"){
					casillas_vacias.push_back(ii+jj+cont);
				}
			}
			cont+=2;
		}
		eleccion=casillas_vacias.at(rand()%(casillas_vacias.size()));
	}
	return eleccion;
}
void marcar(string Triqui[3][3],int posicion,string X){ // marcar una posicion del triqui con la variable X 
	if(posicion==1){
		Triqui[0][0]=X;
	}
	if(posicion==2){
		Triqui[0][1]=X;
	}
	if(posicion==3){
		Triqui[0][2]=X;
	}
	if(posicion==4){
		Triqui[1][0]=X;
	}
	if(posicion==5){
		Triqui[1][1]=X;
	}
	if(posicion==6){
		Triqui[1][2]=X;
	}
	if(posicion==7){
		Triqui[2][0]=X;
	}
	if(posicion==8){
		Triqui[2][1]=X;
	}
	if(posicion==9){
		Triqui[2][2]=X;
	}
}
string ganador(string Triqui[3][3]){ // verifica quien es el ganador en la partida
	string gana;
	// verificando si gana el computador
	for(int i=0;i<3;i++){
		if((Triqui[i][0]=="C") && (Triqui[i][1]=="C") && (Triqui[i][2]=="C")){
			gana="C";
		}
	}
	for(int i=0;i<3;i++){
		if((Triqui[0][i]=="C") && (Triqui[1][i]=="C") && (Triqui[2][i]=="C")){
			gana="C";
		}
	}
	if((Triqui[0][0]=="C") && (Triqui[1][1]=="C") && (Triqui[2][2]=="C")){
		gana="C";
	}
	if((Triqui[2][0]=="C") && (Triqui[1][1]=="C") && (Triqui[0][2]=="C")){
		gana="C";
	}
	// verificando si gana el humano
	for(int i=0;i<3;i++){
		if((Triqui[i][0]=="H") && (Triqui[i][1]=="H") && (Triqui[i][2]=="H")){
			gana="H";
		}
	}
	for(int i=0;i<3;i++){
		if((Triqui[0][i]=="H") && (Triqui[1][i]=="H") && (Triqui[2][i]=="H")){
			gana="H";
		}
	}
	if((Triqui[0][0]=="H") && (Triqui[1][1]=="H") && (Triqui[2][2]=="H")){
		gana="H";
	}
	if((Triqui[2][0]=="H") && (Triqui[1][1]=="H") && (Triqui[0][2]=="H")){
		gana="H";
	}
	return gana;
}

//struct lanzamiento {
//	int Desicion,Dadoh=0,Dadoc=0,first=0,second=0; //Se definen variables 
//	char pdado,computadora,humano, C, H; //se define variable para lanzar dado, y variables para llenar el triqui

//};
int main () {
	string Triqui [3][3];
	int Dadoh=0,Dadoc=0,first=0,second=0; //Se definen variables 
	string desicion;
	string pdado; //se define la variable para lanzar el dado
	string Desicionreglas;
	int computador,humano;
	string humano2;
	int contadoreglas=1;
	srand(time(NULL));
	cout<<"¡Bienvenido al juego del triqui!"<<endl;
	cout<<"¿Deseas conocer las reglas?(SI = s)"<<endl;
	cin>> Desicionreglas;
	if (Desicionreglas =="s"){
		do {
			contadoreglas=1;
			cout<<"1)En este juego competiras contra la computadora."<<endl;
			cout<<"2)Deberas seguir las instrucciones tal y como las plantea el programa."<<endl;
			cout<<"3)Para llenar una casilla deberas oprimir el numero de la respectiva casilla,"<<endl;
			cout<<"  para saber que casilla es cuenta desde arriba a la izquierda (1), hacia la derecha,"<<endl;
			cout<<"  bajando a la siguiente columna leyendo de izquierda a derecha, hasta llegar a la ultima posicion"<<endl;
			cout<<"  la cual es abajo a la derecha (9)"<<endl;
			cout<<"  Ejemplo: "<<endl;
			cout<< " "<<endl;
			for(int ii=0;ii<3;ii++){
				for(int jj=0;jj<3;jj++){
						if(Triqui[ii][jj]!="C" && Triqui[ii][jj]!="H"){
							cout<<"|"<<" "<<contadoreglas<<" ";
							contadoreglas++;
						}
					}
				cout<<"|"<<endl;
				cout<<"-------------"<<endl;
			}
			cout<<endl;
			cout<<"¿Deseas volver a leer las reglas?(SI = s)"<<endl;
			cin>>Desicionreglas;
	}while(Desicionreglas == "s");
	cout<<"Muy bien vamos a empezar"<<endl;	
	}
	do {
		do{
			do{
				cout<<"lance su dado oprimiendo s"<<endl; //Se lanza el dado
				cin>>pdado;
				if(pdado!="s"){
					cout<<"entrada invalida"<<endl;
				}
			}while (pdado != "s");//unicamente se lanza el dado mientras que el usuario oprima s
			Dadoh = 1+rand()%(7-1);//se generan los numeros lanzados por el dado humano
			cout<<"El humano saco: "<<Dadoh<<endl;
			Dadoc = 1+rand()%(7-1);//se generan los numeros lanzados por el dado de la maquina
			cout<<"La computadora saco: "<<Dadoc<<endl;
			if (Dadoc == Dadoh){
				cout<<"Sacaron el mismo numero, vuelvan a lanzar los dados"<<endl;			
			}else{
			}
		}while (Dadoh == Dadoc);//se creo para lanzar nuevamente el dado en caso de empate
		if (Dadoh>Dadoc){//se define quien empieza
			cout<<"Empieza el humano"<<endl;
			first = Dadoh;//variable first como primer para llenar la matriz
			second = Dadoc;//variable second como segundo para llenar la matriz
		}else{
			cout<<"Empieza la computadora"<<endl;
			first = Dadoc;
			second = Dadoh;
		}
		// Triqui
		int kk=1;
		int cc; // cc=0 empieza el humano, cc=1 empieza el computador
		mostrar(Triqui);
		if(Dadoh>Dadoc){ // es turno del humano
			cc=0;
			
		}else{ // es turno de la computadora
			cc=1;
		}
		string g; // g es el ganador
		int casillas_ocupadas; // cantidas de casillas ya jugadas
		if(cc==0){
			while(kk<=5){
				int cont=1;
				vector<int> casillas_vacias;
				for(int ii=0;ii<3;ii++){
					for(int jj=0;jj<3;jj++){
						if(Triqui[ii][jj]!="C" && Triqui[ii][jj]!="H"){
							casillas_vacias.push_back(ii+jj+cont);
						}
					}
					cont+=2;
				}
				do{
				cout<<"Es tu turno,";
				cout<<" digita el numero de la casilla donde quieras jugar: ";
				cin>>humano2;
				cout<<" "<<endl;
				humano=cti(humano2);
				if(pertenece(casillas_vacias,humano)!=true){
					cout<<"entrada invalida"<<endl;
				}
				}while(pertenece(casillas_vacias,humano)!=true);
				marcar(Triqui,humano,"H");
				mostrar(Triqui);
				if(kk>=3){ // despues de la quinta partida existe la posibilidad de que haya un ganador
					g=ganador(Triqui);
					if(g=="H"){
						cout<<"El humano gana"<<endl;
						break;
					}
					if(g=="C"){
						cout<<"La computadora gana"<<endl;
						break;
					}
				}
				if(kk!=5){
					cout<<"Es turno de la computadora"<<endl;
					casillas_ocupadas=0;
					for(int ii=0;ii<3;ii++){
						for(int jj=0;jj<3;jj++){
							if(Triqui[ii][jj]=="C" || Triqui[ii][jj]=="H"){
								casillas_ocupadas+=1;
							}
						}
					}
					computador=eleccion_computador(Triqui,casillas_ocupadas);
					cout<<computador<<endl;
					marcar(Triqui,computador,"C");
					mostrar(Triqui);
					g=ganador(Triqui);
					if(g=="H"){
						cout<<"El humano gana"<<endl;
						break;
					}
					if(g=="C"){
						cout<<"La computadora gana"<<endl;
						break;
					}
				}
			kk++;
			}
			if(g!="C" && g!="H"){ // si no hay un ganador entonces es un empate
				cout<<"Se ha producido un empate"<<endl;
			}	
		}
		if(cc==1){
			while(kk<=5){
				cout<<"Es turno de la computadora"<<endl;
				casillas_ocupadas=0;
				for(int ii=0;ii<3;ii++){
					for(int jj=0;jj<3;jj++){
						if(Triqui[ii][jj]=="C" || Triqui[ii][jj]=="H"){
							casillas_ocupadas+=1;
						}
					}
				}
				computador=eleccion_computador(Triqui,casillas_ocupadas);
				cout<<computador<<endl;
				marcar(Triqui,computador,"C");
				mostrar(Triqui);
				if(kk>=3){ // despues de la quinta partida existe la posibilidad de que haya un ganador
					g=ganador(Triqui);
					if(g=="C"){
						cout<<"La computadora gana"<<endl;
						break;
					}
					if(g=="H"){
						cout<<"El humano gana"<<endl;
						break;
					}
				}
				if(kk!=5){
					int cont=1;
					vector<int> casillas_vacias;
					for(int ii=0;ii<3;ii++){
						for(int jj=0;jj<3;jj++){
							if(Triqui[ii][jj]!="C" && Triqui[ii][jj]!="H"){
								casillas_vacias.push_back(ii+jj+cont);
							}
						}
						cont+=2;
					}
					do{
					cout<<"Es tu turno:"<<endl;
					cin>>humano2;
					humano=cti(humano2);
					if(pertenece(casillas_vacias,humano)!=true){
						cout<<"entrada invalida"<<endl;
					}
					}while(pertenece(casillas_vacias,humano)!=true);
					marcar(Triqui,humano,"H");
					mostrar(Triqui);
					g=ganador(Triqui);
					if(g=="H"){
						cout<<"El humano gana"<<endl;
						break;
					}
					if(g=="C"){
						cout<<"La computadora gana"<<endl;
						break;
					}
				}
			kk++;
			}
			if(g!="C" && g!="H"){ // si no hay un ganador entonces es un empate
				cout<<"Se ha producido un empate"<<endl;
			}	
		}
		resetear(Triqui); // reinicia la partida
		// Triqui
		do{
			cout<<"¿Desea jugar nuevamente (0 = Si / 1 = No)?"<<endl;
			cin>>desicion;
			if(desicion!="0" && desicion!="1"){
				cout<<"entrada invalida"<<endl;
			}
		}while (desicion!="0" && desicion!="1");
	}while (desicion=="0");
	return 0;
}

