#include "applicationui.hpp"

#include <bb/cascades/Application>
#include <bb/cascades/QmlDocument>
#include <bb/cascades/AbstractPane>
#include <bb/cascades/LocaleHandler>
#include <bps/navigator.h>

using namespace bb::cascades;

ApplicationUI::ApplicationUI(bb::cascades::Application *app) :
		QObject(app) {
	// prepare the localization
	m_pTranslator = new QTranslator(this);
	m_pLocaleHandler = new LocaleHandler(this);
	if (!QObject::connect(m_pLocaleHandler, SIGNAL(systemLanguageChanged()),
			this, SLOT(onSystemLanguageChanged()))) {
		// This is an abnormal situation! Something went wrong!
		// Add own code to recover here
		qWarning() << "Recovering from a failed connect()";
	}
	// initial load
	onSystemLanguageChanged();

	// Create scene document from main.qml asset, the parent is set
	// to ensure the document gets destroyed properly at shut down.
	QmlDocument *qml = QmlDocument::create("asset:///main.qml").parent(this);
	qml->setContextProperty("myApp", this);
	// Create root object for the UI
	AbstractPane *root = qml->createRootObject<AbstractPane>();

	// Set created root object as the application scene
	app->setScene(root);
}

//Invoke Music Player
void ApplicationUI::invokeMusicPlayer() {
	navigator_invoke("music://songs", 0);
}

//Invoke Music Albums
void ApplicationUI::invokeMusicAlbums() {
	navigator_invoke("music://albums", 0);
}

// Invoke Music Genres
void ApplicationUI::invokeMusicGenres() {
	navigator_invoke("music://genres", 0);
}

// Invoke Music Artists
void ApplicationUI::invokeMusicArtists() {
	navigator_invoke("music://artists", 0);
}

void ApplicationUI::onSystemLanguageChanged() {
	QCoreApplication::instance()->removeTranslator(m_pTranslator);
	// Initiate, load and install the application translation files.
	QString locale_string = QLocale().name();
	QString file_name = QString("InvokeMusicPlayer_%1").arg(locale_string);
	if (m_pTranslator->load(file_name, "app/native/qm")) {
		QCoreApplication::instance()->installTranslator(m_pTranslator);
	}
}
