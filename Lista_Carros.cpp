#include <iostream>
#include<fstream>
#include<string.h>
#include<stdlib.h>

using namespace std;

class Nodo
{
	private:
		int Dato,Mo,cil;
		char *M,*Sm,*Ca,*Co,*Tr;
		Nodo *sig;
	public:
		Nodo();
		void Asignasig(Nodo *);
		void Imprimir();
		void Leer();
		char *ObtieneM();
		char *ObtieneSm();
		int ObtieneMo();
		char *ObtieneCa();
		int ObtieneCi();
		char *ObtieneT();
		char *ObtieneC();
		Nodo *ObtieneSig();
		~Nodo()
		{
			M=new char[6];
			memset(M,'-',5);
			Sm=new char[6];
			memset(Sm,'-',5);
			Mo=0;
			Ca=new char[6];
			memset(Ca,'-',5);
			cil=0;
			Tr=new char[6];
			memset(Tr,'-',5);
			Co=new char[6];
			memset(Co,'-',5);
		}
		
};
Nodo::Nodo()
{
	M=new char[6];
	memset(M,'-',5);
	Sm=new char[6];
	memset(Sm,'-',5);
	Mo=0;
	Ca=new char[6];
	memset(Ca,'-',5);
	cil=0;
	Tr=new char[6];
	memset(Tr,'-',5);
	Co=new char[6];
	memset(Co,'-',5);
}
void Nodo::Asignasig(Nodo *x)
{
	this->sig=x;
}
void Nodo::Leer()
{
	char Ma[10],S[10],C[10],Col[10],T[15];
	fflush(stdin);
	cout<<"Coloque la marca: "<<endl;cin>>Ma;
	M=new char[strlen(Ma)+1];
	strcpy(M,Ma);
	cout<<"Coloque la sub-marca: "<<endl;scanf("%[^\n]",&S);
	Sm=new char[strlen(S)+1];
	strcpy(Sm,S);
	cout<<"Coloque el anio del modelo: "<<endl;cin>>Mo;
	cout<<"Coloque la categoria: "<<endl;cin>>C;
	Ca=new char[strlen(C)+1];
	strcpy(Ca,C);
	cout<<"Coloque el numero de cilindros: "<<endl;cin>>cil;
	cout<<"Coloque la transmision: "<<endl;scanf("%[^\n]",&T);
	Tr=new char[strlen(T)+1];
	strcpy(Tr,T);
	cout<<"Coloque el color: "<<endl;cin>>Col;
	Co=new char[strlen(Col)+1];
	strcpy(Co,Col);
}
void Nodo::Imprimir()
{
	cout<<" "<<this->M<<" "<<this->Sm<<" "<<this->Mo<<" "<<this->Ca<<" "<<this->cil<<" "<<this->Tr<<" "<<this->Co;
}
char* Nodo::ObtieneM()
{
	return(this->M);
}
char* Nodo::ObtieneSm()
{
	return(this->Sm);
}
int Nodo::ObtieneMo()
{
	return(this->Mo);
}
char* Nodo::ObtieneCa()
{
	return(this->Ca);
}
int Nodo::ObtieneCi()
{
	return(this->cil);
}
char* Nodo::ObtieneT()
{
	return(this->Tr);
}
char* Nodo::ObtieneC()
{
	return(this->Co);
}
Nodo* Nodo::ObtieneSig()
{
	return(this->sig);
}
class LSE
{
	private:
		Nodo *Inicio;
	public:
		void InsertarI(char*,char*,char*,char*,char*,int,int);
		void InsertarF(char*,char*,char*,char*,char*,int,int);
		void BorrarI();
		void BorrarF();
		void Imprimir();
		int Contar();
		void editar();
		void Crea_Ar();
};
void LSE::InsertarI(char *M,char *Sm,char *Co,char *Tr,char *Ca,int C,int A)
{
	if(!Inicio)
	{
		Inicio=new Nodo(M,Sm,Co,Tr,Ca,C,A);
	}
	else
	{
		Nodo *helpx3=new Nodo(M,Sm,Co,Tr,Ca,C,A);
        	helpx3->Asignasig(Inicio);
        	Inicio=helpx3;
	}
}
void LSE::InsertarF(char *M,char *Sm,char *Co,char *Tr,char *Ca,int C,int A)
{
	if(!Inicio)
	{
		Inicio=new Nodo(M,Sm,Co,Tr,Ca,C,A);
	}
	else
	{
		Nodo *help=Inicio;
		while(help->ObtieneSig()!=NULL)
			help=help->ObtieneSig();
		Nodo *helpx2=new Nodo(M,Sm,Co,Tr,Ca,C,A);
		help->Asignasig(helpx2);
	}
}
void LSE::BorrarI()
{
	if(!Inicio)
	{
		cout<<"Lista vacia"<<endl;
	}
	else
	{
		if(Inicio->ObtieneSig()==NULL)
		{
			delete Inicio;
			Inicio=NULL;
		}
		else
		{
			Nodo *hay=Inicio;
			Inicio=Inicio->ObtieneSig();
			hay->Asignasig(NULL);
			delete hay;
		}
	}
}
void LSE::BorrarF()
{
	if(!Inicio)
	{
		cout<<"Lista vacia"<<endl;	
	}
	else
	{
		if(Inicio->ObtieneSig()==NULL)
		{
			delete Inicio;
			Inicio=NULL;
		}
		else
		{
			Nodo *Ad,*Sh;
			Ad=Inicio;
			while(Ad->ObtieneSig()!=NULL)
			{
				Sh=Ad;
				Ad=Ad->ObtieneSig();
			}
			Sh->Asignasig(NULL);
			delete Ad;
		}
	}
}
int LSE::Contar()
{    
	int ESCA=0;
    if(!Inicio)       
	{	
		ESCA=0;
	}
    else
    {   
		Nodo *REC=Inicio;
        while(REC!=NULL)
        {    ESCA++;
            REC=REC->ObtieneSig();
        }
    }
return ESCA;
}
void LSE::Crea_Ar()
{
	ofstream M,A,C;
	int opc=0;
	do
	{
		system("cls");
		cout<<"1) Por marca"<<endl;
		cout<<"2) Por anio de modelo"<<endl;
		cout<<"3) Por numero de cilindros"<<endl;
		cout<<"Teclee el numero del archivo que deseea crear: ";cin>>opc;
	}while(opc<1||opc>3);
	if(opc==1)
	{
		char *n;
		cout<<"Coloque la marca de los autos: ";cin>>n;
		n=new char[strlen(n)+1];
		Nodo *xl=Inicio;
		M.open("F:/Autos_por_marcas.txt");
		while(xl!=NULL)
		{
			if(strcmp(n,xl->ObtieneM())==0)
			{
				M<<xl->ObtieneM()<<"\t"<<xl->ObtieneSm()<<"\t"<<xl->ObtieneMo()<<"\t"<<xl->ObtieneCa()<<"\t"<<xl->ObtieneCi()<<"\t"<<xl->ObtieneT()<<"\t"<<xl->ObtieneC()<<endl;
				xl=xl->ObtieneSig();
			}
		}
		M.close();
	}
	else if(opc==2)
	{
		int x=0;
		cout<<"Coloque el año de los autos: ";cin>>x;
		Nodo *xl2=Inicio;
		A.open("F:/Autos_por_año.txt");
		while(xl2!=NULL)
		{
			if(xl2->ObtieneMo()==x)
			{
				A<<xl2->ObtieneM()<<"\t"<<xl2->ObtieneSm()<<"\t"<<xl2->ObtieneMo()<<"\t"<<xl2->ObtieneCa()<<"\t"<<xl2->ObtieneCi()<<"\t"<<xl2->ObtieneT()<<"\t"<<xl2->ObtieneC()<<endl;
				xl2=xl2->ObtieneSig();
			}
		}
		A.close();
	}
	else if(opc==3)
	{
		int y=0;
		cout<<"Coloque el numero de cilindros: ";cin>>y;
		Nodo *xl4;
		C.open("F:/Autos_por_cilindros.txt");
		while(xl4!=NULL)
		{
			if(xl4->ObtieneCi()==y)
			{
				C<<xl4->ObtieneM()<<"\t"<<xl4->ObtieneSm()<<"\t"<<xl4->ObtieneMo()<<"\t"<<xl4->ObtieneCa()<<"\t"<<xl4->ObtieneCi()<<"\t"<<xl4->ObtieneT()<<"\t"<<xl4->ObtieneC()<<endl;
				xl4=xl4->ObtieneSig();
			}
		}
		C.close();
	}
}
void LSE::editar()
{
	char m[15];
	cout<<"Coloque el nombre de la marca ";cin>>m;
	m=new char [strlen(m)+1];
	
}
void LSE::Imprimir()
{
	if(!Inicio)
    cout<<"Lista Vacia"<<endl;
    else
        {
            Nodo *Aux=Inicio;
            while(Aux!=NULL)
                {
                    Aux->Imprimir();
                    Aux=Aux->ObtieneSig();
                }
        }
}

class Archivo
{
	private:
		fstream A;
	public:
		void InicializarLec();
		void InicializarEsc();
		void LeerA();
		void Finalizar();
};
void Archivo::InicializarLec()
{
	A.open("F:/xl3.txt", ios::in);
	if(A.fail())
	{
		cout<<"No se abrio el archivo"<<endl;
		system("pause");
		exit(0);
	}
	cout<<"Se encontro el archivo"<<endl;
	system("pause>null");
}
void Archivo::LeerA()
{
	int year=0,cil=0;
	while(!A.eof())
	{
		char M[20],Sm[20],Mo[20],C[20],Cil[20],Tr[20],Co[20];
		A.getline(M,20,'\t');
		A.getline(Sm,20,'\t');
		A.getline(Mo,20,'\t');
		A.getline(C,20,'\t');
		A.getline(Cil,20,'\t');
		A.getline(Tr,20,'\t');
		A.getline(Co,20);
		year=atoi(Mo);
		cil=atoi(Cil);
		cout<<M<<"\t"<<Sm<<"\t"<<year<<"\t"<<C<<"\t"<<cil<<"\t"<<Tr<<"\t"<<Co<<"\t"<<endl;
	}
}
void Archivo::Finalizar()
{
	A.close();
}
int main()
{
	Archivo A;
	LSE B;
	Nodo C;
	int opc=0;
	do
	{
		system("cls");
		cout<<"1) Cargar archivo .txt"<<endl;
		cout<<"2) Insertar Inicio"<<endl;
		cout<<"3) Insertar final"<<endl;
		cout<<"4) Borrar Inicio"<<endl;
		cout<<"5) Borrar Final"<<endl;
		cout<<"6) Crear archivo .txt"<<endl;
		cout<<"7) Editar"<<endl;
		cout<<"8) Imprimir"<<endl;
		cout<<"9) Salir"<<endl;
		cout<<"Que opcion desea?: ";cin>>opc;
		switch(opc)
		{
			case 1:
				A.InicializarLec();
				A.LeerA();
				system("pause>null");
				break;
			case 2:
				B.InsertarI(C.ObtieneM(),C.ObtieneSm(),C.ObtieneCa(),C.ObtieneT(),C.ObtieneC(),C.ObtieneMo(),C.ObtieneCi());
				system("pause>null");
				break;
			case 3:
				B.InsertarF(C.ObtieneM(),C.ObtieneSm(),C.ObtieneCa(),C.ObtieneT(),C.ObtieneC(),C.ObtieneMo(),C.ObtieneCi());
				system("pause>null");
				break;
			case 4:
				B.BorrarI();
				system("pause>null");
				break;
			case 5:
				B.BorrarF();
				system("pause>null");
				break;
			case 6:
				B.Crea_Ar();
				system("pause>null");
				break;
			case 7:
				B.editar();
				system("pause>null");
				break;
			case 8:
				B.Imprimir();
				system("pause>null");
				break;
			case 9:
				cout<<"Pulse cualquier tecla para salir."<<endl;
				exit(0);
				break;
			default:
				cout<<"Opcion invalida."<<endl;
				break;
		}
	}while(opc!=9);
	system("pause>null");
	return 0;
}
