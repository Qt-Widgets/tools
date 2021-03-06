
/*!
	\file

	\author Igor Mironchik (igor.mironchik at gmail dot com).

	Copyright (c) 2016 Igor Mironchik

	This program is free software: you can redistribute it and/or modify
	it under the terms of the GNU General Public License as published by
	the Free Software Foundation, either version 3 of the License, or
	(at your option) any later version.

	This program is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
	GNU General Public License for more details.

	You should have received a copy of the GNU General Public License
	along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef LICENSECHANGE__TEXTEDIT_HPP__INCLUDED
#define LICENSECHANGE__TEXTEDIT_HPP__INCLUDED

// Qt include.
#include <QTextEdit>
#include <QScopedPointer>


static const QString c_skipLine = QLatin1String( "data://skip-line.png" );
static const QString c_skipWord = QLatin1String( "data://skip-word.png" );


//
// TextEdit
//

class TextEditPrivate;

//! Text editor.
class TextEdit Q_DECL_FINAL
	:	public QTextEdit
{
	Q_OBJECT

signals:
	//! Focus received.
	void focusReceived();
	//! Focus lost.
	void focusLost();

public:
	explicit TextEdit( QWidget * parent = Q_NULLPTR );
	~TextEdit();

public slots:
	//! Insert skip line.
	void insertSkipLine();
	//! Insert skip word.
	void insertSkipWord();

protected:
	void focusInEvent( QFocusEvent * event ) Q_DECL_OVERRIDE;
	void focusOutEvent( QFocusEvent * event ) Q_DECL_OVERRIDE;

private:
	Q_DISABLE_COPY( TextEdit )

	QScopedPointer< TextEditPrivate > d;
}; // class TextEdit

#endif // LICENSECHANGE__TEXTEDIT_HPP__INCLUDED
