#include "BoremoPrecios.h"

#include <QtGui/QLabel>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QAction>
#include<QPushButton>
#include<QFileDialog>
#include<QMessageBox>

#include<string>
#include "utilities.h"
#include<iostream>


#define homedirectory "/home/rlara/"
#define directory "/home/rlara/Dropbox/BoremoPrecios"


BoremoPrecios::BoremoPrecios()
{
	this->setGeometry(0,0,800,600);
	this -> setWindowTitle("Boremo Precios");
	labelLogoBoremo = new QLabel(this);
	labelLogoBoremo -> setGeometry(250,50,400,100);
	QPixmap logo;
	std::string logoPath = directory;  logoPath.append("/logoboremo.png");
	if(!logo.load(QString::fromStdString(logoPath) ))
		qWarning("Failed to load logoboremo");
	labelLogoBoremo -> setPixmap(logo);
	
	
	/*DefinicionMenu Principal*/
	widgetMenuPrincipal = new QWidget(this); 
	widgetMenuPrincipal -> setGeometry(50,150,700,300);
	verticalLayoutMenuPrincipal = new QVBoxLayout(widgetMenuPrincipal);
	verticalLayoutMenuPrincipal -> setContentsMargins(0,0,0,0);
	buttonConsultarPrecios = new QPushButton(widgetMenuPrincipal);
	buttonConsultarPrecios -> setText("Consultar Precios");
	verticalLayoutMenuPrincipal -> addWidget(buttonConsultarPrecios);
	buttonAgregarArticulos = new QPushButton(widgetMenuPrincipal);
	buttonAgregarArticulos -> setText(QString::fromUtf8("Agregar/Actualizar artículos"));
	verticalLayoutMenuPrincipal -> addWidget(buttonAgregarArticulos);
	buttonImprimirCodigoBarras = new QPushButton(widgetMenuPrincipal);
	buttonImprimirCodigoBarras -> setText(QString::fromUtf8("Imprimir código de barras"));
	verticalLayoutMenuPrincipal -> addWidget(buttonImprimirCodigoBarras);
	
	
	
	/*Consultar Precios*/
	widgetConsultarPrecios = new QWidget(this);
	widgetConsultarPrecios -> setGeometry(50,150,700,450);
	widgetConsultarPrecios -> setVisible(false);
	consultarPreciosTitle = new QLabel(widgetConsultarPrecios);
	consultarPreciosTitle -> setText("CONSULTAR PRECIOS");
	consultarPreciosTitle -> setGeometry(280,30,140,20);
	ingreseCodigoLabel = new QLabel(widgetConsultarPrecios);
	ingreseCodigoLabel -> setText(QString::fromUtf8("Ingrese código: ") );
	ingreseCodigoLabel -> setGeometry(125,80,100,20);
	lineCodigo = new QLineEdit(widgetConsultarPrecios);
	lineCodigo -> setGeometry(225,70,350,40);
	buttonBuscarConsultarPrecios = new QPushButton(widgetConsultarPrecios);
	buttonBuscarConsultarPrecios -> setText("Buscar");
	buttonBuscarConsultarPrecios -> setGeometry(500,115,75,35);
	labelShowingCodigo = new QLabel(widgetConsultarPrecios);
	labelShowingCodigo -> setText(QString::fromUtf8("Código") );
	labelShowingCodigo -> setGeometry(70,175,60,20);
	labelShowingDescripcion = new QLabel(widgetConsultarPrecios);
	labelShowingDescripcion -> setText(QString::fromUtf8("Descripción") );
	labelShowingDescripcion -> setGeometry(320,175,100,20);
	labelShowingCosto = new QLabel(widgetConsultarPrecios);
	labelShowingCosto -> setText("Costo");
	labelShowingCosto -> setGeometry(600,175,60,20);
	showingCodigo = new QTextBrowser(widgetConsultarPrecios);
	showingCodigo -> setGeometry(30,200,120,80);
	showingDescripcion = new QTextBrowser(widgetConsultarPrecios);
	showingDescripcion -> setGeometry(153,200,400,80);
	showingCosto = new QTextBrowser(widgetConsultarPrecios);
	showingCosto -> setGeometry(555,200,120,80);
	buttonMenuPrincipalConsultarPrecios = new QPushButton(widgetConsultarPrecios);
	buttonMenuPrincipalConsultarPrecios -> setText(QString::fromUtf8("Menú principal") );
	buttonMenuPrincipalConsultarPrecios -> setGeometry(550,310,100,40);
	
	
	
	
	/*AgregarArticulos*/
	widgetAgregarArticulos = new QWidget(this);
	widgetAgregarArticulos -> setGeometry(50,150,700,450);
	widgetAgregarArticulos -> setVisible(false);
	agregarArticulosTitle = new QLabel(widgetAgregarArticulos);
	agregarArticulosTitle -> setText(QString::fromUtf8("AGREGAR/ACTUALIZAR ARTÍCULOS"));
	agregarArticulosTitle -> setGeometry(240,30,220,20);
	widgetInsideAgregarArticulos = new QWidget(widgetAgregarArticulos);
	widgetInsideAgregarArticulos -> setGeometry(0,50,700,300);
	verticalLayoutAgregarArticulos= new QVBoxLayout(widgetInsideAgregarArticulos);
	verticalLayoutAgregarArticulos -> setContentsMargins(0,0,0,0);
	buttonDesdeArchivo = new QPushButton(widgetInsideAgregarArticulos);
	buttonDesdeArchivo -> setText("Desde archivo CSV...");
	verticalLayoutAgregarArticulos -> addWidget(buttonDesdeArchivo);
	buttonIndivPorCodigo = new QPushButton(widgetInsideAgregarArticulos);
	buttonIndivPorCodigo -> setText(QString::fromUtf8("Individualmente por código") );
	verticalLayoutAgregarArticulos -> addWidget(buttonIndivPorCodigo);
		/*IndivPorCodigo*/
	widgetIndivPorCodigo = new QWidget(widgetAgregarArticulos);
	widgetIndivPorCodigo -> setGeometry(0,50,700,300);
	widgetIndivPorCodigo -> setVisible(false);
	indivPorCodigoTitle = new QLabel(widgetIndivPorCodigo);
	indivPorCodigoTitle -> setText(QString::fromUtf8("MODIFICAR UN ARTÍCULO MANUALMENTE"));
	indivPorCodigoTitle -> setGeometry(200,30,280,20);
	ingreseCodigoLabelIndivPorCodigo = new QLabel(widgetIndivPorCodigo);
	ingreseCodigoLabelIndivPorCodigo -> setText(QString::fromUtf8("Ingrese código: ") );
	ingreseCodigoLabelIndivPorCodigo -> setGeometry(50,80,100,20);
	lineCodigoIndivPorCodigo = new QLineEdit(widgetIndivPorCodigo);
	lineCodigoIndivPorCodigo -> setGeometry(150,70,350,40);
	buttonBuscarIndivPorCodigo = new QPushButton(widgetIndivPorCodigo);
	buttonBuscarIndivPorCodigo -> setText("Buscar");
	buttonBuscarIndivPorCodigo -> setGeometry(510,70,75,40);
	labelShowingCodigoIndivPorCodigo = new QLabel(widgetIndivPorCodigo);
	labelShowingCodigoIndivPorCodigo -> setText(QString::fromUtf8("Código") );
	labelShowingCodigoIndivPorCodigo -> setGeometry(70,125,60,20);
	labelShowingDescripcionIndivPorCodigo = new QLabel(widgetIndivPorCodigo);
	labelShowingDescripcionIndivPorCodigo -> setText(QString::fromUtf8("Descripción") );
	labelShowingDescripcionIndivPorCodigo -> setGeometry(320,125,100,20);
	labelShowingCostoIndivPorCodigo = new QLabel(widgetIndivPorCodigo);
	labelShowingCostoIndivPorCodigo -> setText("Costo");
	labelShowingCostoIndivPorCodigo -> setGeometry(600,125,60,20);
	showingCodigoIndivPorCodigo = new QTextBrowser(widgetIndivPorCodigo);
	showingCodigoIndivPorCodigo -> setGeometry(30,150,120,80);
	showingDescripcionIndivPorCodigo = new QLineEdit(widgetIndivPorCodigo);
	showingDescripcionIndivPorCodigo -> setGeometry(153,150,400,80);
	showingCostoIndivPorCodigo = new QLineEdit(widgetIndivPorCodigo);
	showingCostoIndivPorCodigo -> setGeometry(555,150,120,80);
	buttonGuardarIndivPorCodigo = new QPushButton(widgetIndivPorCodigo);
	buttonGuardarIndivPorCodigo -> setText("Guardar");
	buttonGuardarIndivPorCodigo -> setGeometry(300,250,100,40);
	buttonRegresaIndivPorCodigo = new QPushButton(widgetIndivPorCodigo);
	buttonRegresaIndivPorCodigo -> setText(QString::fromUtf8("Regresa") );
	buttonRegresaIndivPorCodigo -> setGeometry(550,250,100,40);
	/*ContinuacionAgregarArticulos*/
	buttonMenuPrincipalAgregarArticulos = new QPushButton(widgetAgregarArticulos);
	buttonMenuPrincipalAgregarArticulos -> setText(QString::fromUtf8("Menú principal") );
	buttonMenuPrincipalAgregarArticulos -> setGeometry(550,350,100,40);
	
	
	/*ImprimirCodigo*/
	widgetImprimirCodigo = new QWidget(this);
	widgetImprimirCodigo -> setGeometry(50,150,700,450);
	widgetImprimirCodigo -> setVisible(false);
	imprimirCodigoTitle = new QLabel(widgetImprimirCodigo);
	imprimirCodigoTitle -> setText(QString::fromUtf8("IMPRIMIR CÓDIGO DE BARRAS"));
	imprimirCodigoTitle -> setGeometry(240,30,220,20);
	ingreseCodigoLabelImprimir = new QLabel(widgetImprimirCodigo);
	ingreseCodigoLabelImprimir -> setText(QString::fromUtf8("Ingrese código: ") );
	ingreseCodigoLabelImprimir -> setGeometry(125,80,100,20);
	lineCodigoImprimir = new QLineEdit(widgetImprimirCodigo);
	lineCodigoImprimir -> setGeometry(225,70,350,40);
	buttonBuscarImprimir = new QPushButton(widgetImprimirCodigo);
	buttonBuscarImprimir -> setText("Buscar");
	buttonBuscarImprimir -> setGeometry(500,115,75,35);
	labelShowingCodigoImprimir = new QLabel(widgetImprimirCodigo);
	labelShowingCodigoImprimir -> setText(QString::fromUtf8("Código") );
	labelShowingCodigoImprimir -> setGeometry(70,175,60,20);
	labelShowingDescripcionImprimir = new QLabel(widgetImprimirCodigo);
	labelShowingDescripcionImprimir -> setText(QString::fromUtf8("Descripción") );
	labelShowingDescripcionImprimir -> setGeometry(400,175,100,20);
	showingCodigoImprimir = new QTextBrowser(widgetImprimirCodigo);
	showingCodigoImprimir -> setGeometry(30,200,150,50);
	showingDescripcionImprimir = new QTextBrowser(widgetImprimirCodigo);
	showingDescripcionImprimir -> setGeometry(183,200,500,50);
	numEtiquetasImprimir = new QLabel(widgetImprimirCodigo);
	numEtiquetasImprimir -> setText("No. de Etiquetas: ");
	numEtiquetasImprimir -> setGeometry(200,275, 100,20);
	lineNumEtiquetasImprimir = new QLineEdit(widgetImprimirCodigo);
	lineNumEtiquetasImprimir -> setGeometry(305,270,70,30);
	ImprimirEtiquetas = new QPushButton(widgetImprimirCodigo);
	ImprimirEtiquetas -> setText("Imprimir");
	ImprimirEtiquetas -> setGeometry(380,270,100,25);
	buttonMenuPrincipalImprimirCodigo = new QPushButton(widgetImprimirCodigo);
	buttonMenuPrincipalImprimirCodigo -> setText(QString::fromUtf8("Menú principal") );
	buttonMenuPrincipalImprimirCodigo -> setGeometry(550,350,100,40);
	
	
	/*Acciones*/
	/*OcultaMenuPrincipal-MuestraConsultarPrecios*/
	QObject::connect(buttonConsultarPrecios, SIGNAL(clicked()), widgetConsultarPrecios, SLOT(show()));
	QObject::connect(buttonConsultarPrecios, SIGNAL(clicked()), widgetMenuPrincipal, SLOT(hide()));
	/*Realizar la busqueda de un codigo al pulsar Buscar en Consultar Precios*/
	QObject::connect(buttonBuscarConsultarPrecios, SIGNAL(clicked()), this, SLOT(searchCode()));
	/*OcultaConsultarPrecios-MuestraMenuPrincipal*/
	QObject::connect(buttonMenuPrincipalConsultarPrecios, SIGNAL(clicked()), widgetMenuPrincipal, SLOT(show()));
	QObject::connect(buttonMenuPrincipalConsultarPrecios, SIGNAL(clicked()), widgetConsultarPrecios, SLOT(hide()));
	/*OcultaMenuPrincipal-MuestraAgregarArticulos*/
	QObject::connect(buttonAgregarArticulos,SIGNAL(clicked()), widgetAgregarArticulos, SLOT(show()));
	QObject::connect(buttonAgregarArticulos, SIGNAL(clicked()), widgetMenuPrincipal, SLOT(hide()));
	/*OcultaAgregarArticulos-MuestraMenuPrincipal*/
	QObject::connect(buttonMenuPrincipalAgregarArticulos, SIGNAL(clicked()), widgetMenuPrincipal, SLOT(show()));
	QObject::connect(buttonMenuPrincipalAgregarArticulos, SIGNAL(clicked()), widgetAgregarArticulos, SLOT(hide()));
	/*OcultaAgregarArticulos-MuestraIndivPorCodigo*/
		QObject::connect(buttonIndivPorCodigo,SIGNAL(clicked()), widgetIndivPorCodigo, SLOT(show()));
	QObject::connect(buttonIndivPorCodigo, SIGNAL(clicked()), widgetInsideAgregarArticulos, SLOT(hide()));
	/*OcultaIndivPorCodigo-MuestraAgregaArticulos*/
	QObject::connect(buttonRegresaIndivPorCodigo, SIGNAL(clicked()), widgetInsideAgregarArticulos, SLOT(show()));
	QObject::connect(buttonRegresaIndivPorCodigo, SIGNAL(clicked()), widgetIndivPorCodigo, SLOT(hide()));
	/*Al pulsar DesdeArchivo CSV*/
	QObject::connect(buttonDesdeArchivo, SIGNAL(clicked()), this, SLOT(pushDesdeArchivoButton()));
	/*OcultaMenuPrincipal-MuestraImprimirCodigo*/
	QObject::connect(buttonImprimirCodigoBarras,SIGNAL(clicked()), widgetImprimirCodigo, SLOT(show()));
	QObject::connect(buttonImprimirCodigoBarras, SIGNAL(clicked()), widgetMenuPrincipal, SLOT(hide()));
	/*OcultaImprimirCodigo-MuestraMenuPrincipal*/
	QObject::connect(buttonMenuPrincipalImprimirCodigo, SIGNAL(clicked()), widgetMenuPrincipal, SLOT(show()));
	QObject::connect(buttonMenuPrincipalImprimirCodigo, SIGNAL(clicked()), widgetImprimirCodigo, SLOT(hide()));
	/*Al pulsar Buscar en IndivPorCodigo, despliega valores en los campos correspondientes*/
	QObject::connect(buttonBuscarIndivPorCodigo, SIGNAL(clicked()),this, SLOT(pushBuscarIndPorCodigo()));
	/*Se guardan los cambios al pulsar el boton Guardar en IndivPorCodigo*/
	QObject::connect(buttonGuardarIndivPorCodigo,SIGNAL(clicked()), this, SLOT(pushGuardarIndivPorCodigo()));
	/*Realizar la busqueda de un codigo al pulsar Buscar en Imprimir Codigo*/
	QObject::connect(buttonBuscarImprimir, SIGNAL(clicked()), this, SLOT(pushBuscarCodeImprimir()));
	/*Crea el codigo de barras al pulsar Imprimir Codigo*/
	QObject::connect(ImprimirEtiquetas, SIGNAL(clicked()), this, SLOT(pushImprimirCodigo()));
	/*Cambia comilla por guion en lineEdit*/
	QObject::connect(lineCodigo,SIGNAL(textChanged(QString)),this,SLOT(lineCodigoHasChanged()));
	
	
	
}

BoremoPrecios::~BoremoPrecios()
{}



/*Al pulsar AgregarArticulos->Desde Archivo CSV se despliega un QFileDialog*/
void BoremoPrecios::pushDesdeArchivoButton()
{
	QString fileName = QFileDialog::getOpenFileName(widgetInsideAgregarArticulos, tr("Open File"), QString(homedirectory), tr("CSV file (*.csv)"));
	std::vector<item> list;
	uploadItemsToAList(fileName.toStdString(), list, true);
	std::string file = directory; file.append("/items/allitems");
	uploadNewItemsToFile(list, file);
	QMessageBox(QMessageBox::Information, "Guardado", "Se han actualizado correctamente", QMessageBox::Ok).exec();
}

void BoremoPrecios::searchCode(){
	QString code = lineCodigo->text();	
	std::vector<item> list;
	std::string fileLocation = directory; fileLocation.append("/items/usedcodes");
	uploadItemsToAList(fileLocation, list);
	int index;
	std::string s_code = code.toStdString();
	for(int i=0;i<s_code.size();i++)
		if(s_code[i]=='\'')
			s_code[i]='-';
	showingCodigo->setText(QString::fromStdString(s_code));
	index = findItem(s_code, list);
	if(index>=0){
		QString description = QString::fromStdString(list[index].getDescription());
		QString cost = QString::fromStdString("$"+ std::to_string(list[index].getCost() ));
		showingDescripcion -> setText( description );
		showingCosto -> setText(cost);
	}
	else{
		std::vector<item> L;
		fileLocation = directory; fileLocation.append("/items/allitems");
		uploadItemsToAList(fileLocation, L);
		index = findItem(s_code, L);
		if(index>=0){
			QString description = QString::fromStdString(L[index].getDescription());
			QString cost = QString::fromStdString("$"+ std::to_string(L[index].getCost() ));
			showingDescripcion -> setText( description );
			showingCosto -> setText(cost);
		}
		else{
			QString description = QString::fromStdString("NO ENCONTRADO");
			QString cost = QString::fromStdString( "N/A");
			showingDescripcion -> setText( description );
			showingCosto -> setText(cost);	
		}
	}
}



void BoremoPrecios::pushBuscarIndPorCodigo(){
	QString code = lineCodigoIndivPorCodigo->text();
	showingCodigoIndivPorCodigo->setText(code);
	std::vector<item> list;
	std::string fileLocation = directory; fileLocation.append("/items/usedcodes");
	uploadItemsToAList(fileLocation, list);
	int index;
	std::string s_code = code.toStdString();
	index = findItem(s_code, list);
	if(index>=0){
		QString description = QString::fromStdString(list[index].getDescription());
		QString cost = QString::fromStdString("$"+ std::to_string(list[index].getCost() ));
		showingDescripcionIndivPorCodigo -> setText( description );
		showingCostoIndivPorCodigo ->setText(cost);
	}
	else{
		std::vector<item> L;
		fileLocation = directory; fileLocation.append("/items/allitems");
		uploadItemsToAList(fileLocation, L);
		index = findItem(s_code, L);
		if(index>=0){
			QString description = QString::fromStdString(L[index].getDescription());
			QString cost = QString::fromStdString("$"+ std::to_string(L[index].getCost() ));
			showingDescripcionIndivPorCodigo -> setText( description );
			showingCostoIndivPorCodigo -> setText(cost);
		}
		else{
			QString description = QString::fromStdString("NO ENCONTRADO");
			QString cost = QString::fromStdString( "N/A");
			showingDescripcionIndivPorCodigo -> setText( description );
			showingCostoIndivPorCodigo -> setText(cost);	
		}
	}
}


void BoremoPrecios::pushGuardarIndivPorCodigo(){
	QString code = showingCodigoIndivPorCodigo->toPlainText();
	showingCodigoIndivPorCodigo->setText(code);
	QString newdescription = showingDescripcionIndivPorCodigo->text();
	QString newcost = showingCostoIndivPorCodigo->text();
	item newitem(code.toStdString(), newdescription.toStdString(), convertToMoney( newcost.toStdString() ));
	std::vector<item> list;
	std::vector<item> aux; aux.push_back(newitem);
	std::string fileLocation = directory; fileLocation.append("/items/usedcodes");
	uploadItemsToAList(fileLocation, list);
	if(findItem(newitem.getCode(), list) >=0){
		uploadNewItemsToFile(aux, fileLocation);
	}
	std::vector<item> L;
	fileLocation = directory; fileLocation.append("/items/allitems");
	uploadItemsToAList(fileLocation,L);
	if(findItem(newitem.getCode(), L) >=0){
		uploadNewItemsToFile(aux, fileLocation);
	}
	QMessageBox(QMessageBox::Information, "Guardado", "Se ha guardado correctamente", QMessageBox::Ok).exec();
}


void BoremoPrecios::pushBuscarCodeImprimir(){
	QString code = lineCodigoImprimir->text();
	showingCodigoImprimir->setText(code);
	std::vector<item> list;
	std::string fileLocation = directory; fileLocation.append("/items/usedcodes");
	uploadItemsToAList(fileLocation, list);
	int index;
	std::string s_code = code.toStdString();
	index = findItem(s_code, list);
	if(index>=0){
		QString description = QString::fromStdString(list[index].getDescription());
		showingDescripcionImprimir -> setText( description );
	}
	else{
		std::vector<item> L;
		fileLocation = directory; fileLocation.append("/items/allitems");
		uploadItemsToAList(fileLocation, L);
		index = findItem(s_code, L);
		if(index>=0){
			QString description = QString::fromStdString(L[index].getDescription());
			showingDescripcionImprimir -> setText( description );
		}
		else{
			QString description = QString::fromStdString("NO ENCONTRADO");
			showingDescripcionImprimir -> setText( description );
		}
	}
}

void BoremoPrecios::pushImprimirCodigo(){
	QString code = lineCodigoImprimir->text();
	generateBarcode(code.toStdString());
	QMessageBox(QMessageBox::Information, "Imprimir", QString::fromUtf8("Se han creado el código de barras"), QMessageBox::Ok).exec();
}

void BoremoPrecios::lineCodigoHasChanged(){
	QString code =lineCodigo->text();
	std::string s = code.toStdString();
	std::cout << "Entre" << std::endl;
	std::cout << s << std::endl;	
	for(int i=0;i<s.size();i++)
		if(s[i]=='\'') s[i]='-';
	lineCodigo->setText( QString::fromStdString(s) );
	std::cout << "Ultimo elemento->" << s.back() << "<-" << std::endl;
	if(s.back()=='\n')
		BoremoPrecios::searchCode();
	
}

#include "BoremoPrecios.moc"
