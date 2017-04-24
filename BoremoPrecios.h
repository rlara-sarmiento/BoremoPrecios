#ifndef BoremoPrecios_H
#define BoremoPrecios_H

#include <QtGui/QMainWindow>
#include <QPushButton>
#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QTextBrowser>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>
#include<QMessageBox>

class BoremoPrecios : public QMainWindow
{
	Q_OBJECT

public:
	BoremoPrecios();
	virtual ~BoremoPrecios();
	
private:
	QLabel *labelLogoBoremo;
	
	/*Menu principal*/
	QWidget *widgetMenuPrincipal;
	QVBoxLayout *verticalLayoutMenuPrincipal;
	QPushButton *buttonConsultarPrecios;
	QPushButton *buttonAgregarArticulos;
	QPushButton *buttonImprimirCodigoBarras;
	
	
	
	/*ConsultarPrecios*/
	QWidget *widgetConsultarPrecios;
	QLabel *consultarPreciosTitle;
	QLabel *ingreseCodigoLabel;
	QLineEdit *lineCodigo;
	QPushButton *buttonBuscarConsultarPrecios;
	QLabel *labelShowingCodigo;
	QLabel *labelShowingDescripcion;
	QLabel *labelShowingCosto;
	QTextBrowser *showingCodigo;
	QTextBrowser *showingDescripcion;
	QTextBrowser *showingCosto;
	QPushButton *buttonMenuPrincipalConsultarPrecios;
	
	
	/*AgregarArticulos*/
	QWidget *widgetAgregarArticulos;
	QLabel *agregarArticulosTitle;
	QWidget *widgetInsideAgregarArticulos;
	QVBoxLayout *verticalLayoutAgregarArticulos;
	QPushButton *buttonDesdeArchivo;
	QPushButton *buttonIndivPorCodigo;
	QPushButton *buttonMenuPrincipalAgregarArticulos;
		/*IndivPorCodigo*/
	QWidget *widgetIndivPorCodigo;
	QLabel *indivPorCodigoTitle;
	QLabel *ingreseCodigoLabelIndivPorCodigo;
	QLineEdit *lineCodigoIndivPorCodigo;
	QPushButton *buttonBuscarIndivPorCodigo;
	QLabel *labelShowingCodigoIndivPorCodigo;
	QLabel *labelShowingDescripcionIndivPorCodigo;
	QLabel *labelShowingCostoIndivPorCodigo;
	QTextBrowser *showingCodigoIndivPorCodigo;
	QLineEdit *showingDescripcionIndivPorCodigo;
	QLineEdit *showingCostoIndivPorCodigo;
	QPushButton *buttonGuardarIndivPorCodigo;
	QPushButton *buttonRegresaIndivPorCodigo;
	
	/*Imprimir Codigo de Barras*/
	QWidget *widgetImprimirCodigo;
	QLabel *imprimirCodigoTitle;
	QLabel *ingreseCodigoLabelImprimir;
	QLineEdit *lineCodigoImprimir;
	QPushButton *buttonBuscarImprimir;
	QLabel *labelShowingCodigoImprimir;
	QLabel *labelShowingDescripcionImprimir;
	QTextBrowser *showingCodigoImprimir;
	QTextBrowser *showingDescripcionImprimir;
	QPushButton *buttonMenuPrincipalImprimirCodigo;
	QLabel *numEtiquetasImprimir;
	QLineEdit *lineNumEtiquetasImprimir;
	QPushButton *ImprimirEtiquetas;

private slots:
	void pushDesdeArchivoButton();
	void searchCode();
	void pushBuscarIndPorCodigo();
	void pushGuardarIndivPorCodigo();
	void pushBuscarCodeImprimir();
	void pushImprimirCodigo();
	void lineCodigoHasChanged();
};

#endif // BoremoPrecios_H
