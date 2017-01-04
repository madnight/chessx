/***************************************************************************
 *   (C) 2006-2009 Michal Rudolf <mrudolf@kdewebdev.org>                   *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 ***************************************************************************/

#ifndef __DATABASEINFO_H__
#define __DATABASEINFO_H__

#include "circularbuffer.h"
#include "game.h"

#include <QString>
#include <QObject>
#include <QUndoCommand>
#include <QPointer>
#include <QMetaType>

class Database;
class Filter;
class QUndoStack;
class QUndoGroup;

/** @ingroup Database
The DatabaseInfo class is a simple class to keep various database-related
information together. */


class DatabaseInfo: public QThread
{
    Q_OBJECT
public:
    void run();
    enum {NewGame = -1};
    /** Create information for clipboard database */
    DatabaseInfo(QUndoGroup *undoGroup, Database* db);
    /** Create information for file database */
    DatabaseInfo(QUndoGroup *undoGroup, const QString& filename);
    /** Close database and free memory */
    ~DatabaseInfo();
    /** Open database. */
    bool open(bool utf8);
    /** Close database. */
    void close();
    /** @return @p true if database is valid */
    bool isValid() const
    {
        return m_bLoaded ? m_database != 0 : false;
    }
    /** @return Database object */
    Database* database()
    {
        return m_database;
    }
    const Database* database() const
    {
        return m_database;
    }
    /** @return current filter */
    Filter* filter();
    /** @return current game  */
    Game& currentGame()
    {
        return m_game;
    }
    const Game& currentGame() const
    {
        return m_game;
    }
    /** @return index of current game  */
    int currentIndex() const
    {
        return m_index;
    }
    /** Load game @p index */
    bool loadGame(GameId index);
    /** Starts new game, giving it @p index equal to the number of games in the database */
    void newGame();
    /** Saves game, replacing current one or adding new. If @ref currentIndex() is
    in the database, game will be replaced, else if will be appended at the end. */
    bool saveGame();

    void replaceGame(const Game& game);

    void updateMaterial();

    /** Resizes the filter to the number of games in the database and puts
         *  all games in the filter.*/
    void resetFilter();
    QString displayName() const
    {
        return m_filename;
    }
    QString dbPath() const;

    bool IsLoaded() const;
    bool IsUtf8() const;

    bool IsFicsDB() const;
    bool IsPolyglotBook() const;
    bool IsBook() const;

    static bool IsPolyglotBook(QString name);
    static bool IsBook(QString name);

    bool modified() const;
    bool gameNeedsSaving() const;

    void restoreState(const Game& game);

    QUndoStack *undoStack() const;

    QList<double> m_material;

    const QList<double> &material() const;

    static QString ficsPath();

    bool isClipboard() const;

    const CircularBuffer<int>& lastGames() const { return m_lastGames; }
    void clearLastGames();

protected:
    void doLoadFile(QString filename);

signals:
    void LoadFinished(DatabaseInfo*);
    void signalRestoreState(const Game &game);
    void signalGameModified(bool gameNeedsSaving);
    void signalMoveChanged();
    void searchProgress(int);
    void searchFinished();


public slots:
    void dbCleanChanged(bool);
    void setModified(bool modfied, const Game &g, QString action);

private:
    QUndoStack* m_undoStack;
    Database* m_database;
    QPointer<Filter> m_filter;
    Game m_game;
    QString m_filename;
    int m_index;
    CircularBuffer<int> m_lastGames;
    bool m_bLoaded;
    bool m_utf8;
};

Q_DECLARE_METATYPE(DatabaseInfo*)

class GameUndoCommand : public QUndoCommand
{
public:
    GameUndoCommand(QObject* parent, const Game& from, const Game& to, QString action) :
        QUndoCommand(action),
        m_dbInfo((DatabaseInfo*)parent),
        m_fromGame(from),
        m_toGame(to),
        m_bInConstructor(true)
        {
        }

    QPointer<DatabaseInfo> m_dbInfo;
    Game m_fromGame;
    Game m_toGame;
    bool m_bInConstructor;

    virtual void undo() { m_dbInfo->restoreState(m_fromGame); }
    virtual void redo() { if (m_bInConstructor) m_bInConstructor=false; else m_dbInfo->restoreState(m_toGame); }
};

#endif

