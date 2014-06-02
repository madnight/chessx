/****************************************************************************
*   Copyright (C) 2012 by Jens Nissen jens-chessx@gmx.net                   *
****************************************************************************/

#include "renametagdialog.h"
#include "settings.h"

#include "ui_renametagdialog.h"

RenameTagDialog::RenameTagDialog(QWidget *parent, QString ts, QString tagName, Qt::WindowFlags f) :
    QDialog(parent, f),
    ui(new Ui::RenameTagDialog),
    m_ts(ts),
    m_tagName(tagName)
{
    ui->setupUi(this);

    ui->editFrom->setText(m_ts);
    ui->editTo->setText(m_ts);

    connect(ui->btClose, SIGNAL(clicked()), SLOT(accept()));
    connect(ui->btRename, SIGNAL(clicked()), SLOT(slotRename()));
    AppSettings->layout(this);
}

RenameTagDialog::~RenameTagDialog()
{
    delete ui;
}

void RenameTagDialog::slotRename()
{
    emit renameRequest(m_tagName, ui->editTo->text(), m_ts);
    AppSettings->setLayout(this);
    close();
}

void RenameTagDialog::accept()
{
    AppSettings->setLayout(this);
    QDialog::accept();
}

void RenameTagDialog::reject()
{
    AppSettings->setLayout(this);
    QDialog::reject();
}
