#ifndef ApplicationUI_HPP_
#define ApplicationUI_HPP_

#include <QObject>

namespace bb {
namespace cascades {
class Application;
class LocaleHandler;
}
}

class QTranslator;

/*!
 * @brief Application object
 *
 *
 */

class ApplicationUI: public QObject {
Q_OBJECT
public:
	ApplicationUI(bb::cascades::Application *app);
	virtual ~ApplicationUI() {
	}
	Q_INVOKABLE
	void invokeMusicPlayer();Q_INVOKABLE
	void invokeMusicAlbums();Q_INVOKABLE
	void invokeMusicGenres();Q_INVOKABLE
	void invokeMusicArtists();
private slots:
	void onSystemLanguageChanged();

private:
	QTranslator* m_pTranslator;
	bb::cascades::LocaleHandler* m_pLocaleHandler;
};

#endif /* ApplicationUI_HPP_ */
