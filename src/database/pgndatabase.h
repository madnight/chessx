/***************************************************************************
                          pgndatabase.h  -  pgn database class
                             -------------------
    begin                : 8 December 2005
    copyright            : (C) 2005, 2006 William Hoggarth
													 <whoggarth@users.sourceforge.net>
													 (C) 2005 Ejner Borgbjerg 
                           <ejner@users.sourceforge.net>
 ***************************************************************************/

/***************************************************************************
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 ***************************************************************************/

#ifndef __PGNDATABASE_H__
#define __PGNDATABASE_H__
 
#include <QBitArray>
#include <QFile>
#include <QMap>
#include <QPair>
#include <QTextStream>
#include <QCache>
#include <QVector>

#include "database.h"

/** @ingroup Database
   The PgnDatabase class provides database access to PGN files.
   The class is derived from the Database class, providing methods for the 
   loading and saving of games, and for performing searches and queries.
*/

class PgnDatabase : public Database
{
	public:
		/** Default constructor */
		PgnDatabase();
		/** Destructor */
		~PgnDatabase();
		
		//database operations
		/** Opens the given database */
		virtual bool open(const QString& filename);
		/** File-based database name */
		virtual QString filename() const;
		/** Closes the database */
		virtual void close();		
		
		//game retrieval & storage
		/** Loads a game from the given position, returns true if successful */
		bool loadGame(int index, Game& game);
		/** Saves a game at the given position, returns true if successful */
		bool save(int index, Game& game);
		/** Adds a game to the database */
		bool add(Game& game);
		/** Removes a game from the database */
		bool remove(int index);
		/** Removes multiple games from the database as specified by the filter */
		bool remove(const Filter& filter);
		
	private:
		/** Resets/initialises important member variables. Called by constructor and close methods */
		void initialise(); 
		
		//offset methods
		/** Returns the file offset for the given game */
		qint64 offset(int index);
		/** Adds the current file position as a new offset */
		void addOffset();
		/** Adds a new file offset */
		void addOffset(qint64 offset);
		/** Changes the file offset for the given game to the current file position*/ 
		void setOffset(int index);
		/** Changes the file offset for the given game to the supplied position */
		void setOffset(int index, qint64 offset);
		/** Removes a file offset */
		void removeOffset(int index);
		
		//file methods
		/** Backs up the old pgn file and creates a new one */		
		void startCopy();
		/** Copies games from the old file to the new */
		void copyRange(int startIndex, int endIndex, int newIndex, qint64 offset);
		/** Removes the backup if file operations were sucessful */
		bool finishCopy();
		/** Reads the next line of text from the PGN file */
		void readLine();
		/** Moves the file position to the start of the given game */
		void seekGame(int index);
		
		//parsing methods
		/** Reads moves from the file and adds them to the game. Performs position searches if any are active */
		void parseMoves(Game* game);
		/** Parses a line from the file */
		void parseLine(Game* game);
		/** Parses a token from the file */
		void parseToken(Game* game, QString token);
		/** Parses a comment from the file */
		void parseComment(Game* game);
		/** Skips past any data which is not valid tag or move data */
		void readJunk();
		/** Skips past any tag data */
		void readTags();
		/** Skips past any move data */
		void readMoves();
      /** Parses the tags, and adds the supported types to the index 'm_index' */
      void parseTagsIntoIndex();

		//output methods
		/** Writes out the tags from the given game to the file */
		void writeTags(const Game& game);
		/** Writes out the move data from the given game to the file */
		void writeMoves(Game& game);
		/** Writes out current variation from the given game to the file */
		void writeVariation(Game& game);
		
		//file variables
		bool m_isOpen;
		QString m_filename;
		QFile* m_file;
		QFile* m_newFile;
		QTextStream* m_newStream;
		QString m_gameText;
		
		//parsing variables
		static const int MaxLineLength = 512;
		char m_charLine[MaxLineLength];
		QString m_currentLine;
		int m_pos;
		bool m_gameOver;
		bool m_inComment;
		QString m_comment;
		bool m_newVariation;
		int m_variation;
		
		//game index
		qint64 m_filePos;
		qint64 m_currentLineSize;

		static const int AllocationSize = 512;
		int m_allocated;
		qint64* m_gameOffsets;
		
		
};

#endif
