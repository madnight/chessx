/***************************************************************************
                          boardsetup.h  -  Board setup dialog
                             -------------------
    begin                : Mon 14 Nov 2005
    copyright            : (C) 2005 Michal Rudolf <mrudolf@kdewebdev.org>
 ***************************************************************************/

/***************************************************************************
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 ***************************************************************************/

#ifndef __BOARDSETUPDIALOG_H__
#define __BOARDSETUPDIALOG_H__

#include "ui_boardsetup.h"
#include "board.h"

class QMenu;
class QAction;
class QActionGroup;

/**  @ingroup GUI 
  The BoardSetupDialog class represents a dialog for setting up a position.  */

class BoardSetupDialog : public QDialog
{
  Q_OBJECT
  public:
    /** Create ChessX Preferences dialog */
    BoardSetupDialog(QWidget* parent = 0);
    /** Destroy the dialog */
    virtual ~BoardSetupDialog();
    /** Set current board */
    void setBoard(const Board& b);
    /** Return current board */
    Board board() const;
    /** Set current move number */
    void setMoveNumber(int i);
    /** Return current move number*/
    int moveNumber() const;

  public slots:
    /** Execute dialog */
    int exec();
  private slots:
    /** If the position is legal, accept it and close the dialog. */
    void slotAccept();
    /** Clear board. */
    void slotClear();
    /** Restore standard position */
    void slotReset();
    /** Change current piece using wheel */
    void slotChangePiece(int dir);
    /** Choose piece */
    void slotChoosePiece(QAction*);
    /** Select square and insert piece */
    void slotSelected(Square s, int button);
    /** Toggle side to move */
    void slotToggleSide();
  private:
    Ui::BoardSetupDialog ui;
    QActionGroup* m_actions;
    Color m_toMove;
    /** Display side to move */
    void showSideToMove();
  protected:
    /** Scroll current piece with a wheel */
    virtual void wheelEvent(QWheelEvent* e);
};


#endif
