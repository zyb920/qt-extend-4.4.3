/****************************************************************************
**
** Copyright (C) 2008 Nokia Corporation and/or its subsidiary(-ies).
** Contact: Qt Software Information (qt-info@nokia.com)
**
** This file is part of the Qt3Support module of the Qt Toolkit.
**
** Commercial Usage
** Licensees holding valid Qt Commercial licenses may use this file in
** accordance with the Qt Commercial License Agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and Nokia.
**
**
** GNU General Public License Usage
** Alternatively, this file may be used under the terms of the GNU
** General Public License versions 2.0 or 3.0 as published by the Free
** Software Foundation and appearing in the file LICENSE.GPL included in
** the packaging of this file.  Please review the following information
** to ensure GNU General Public Licensing requirements will be met:
** http://www.fsf.org/licensing/licenses/info/GPLv2.html and
** http://www.gnu.org/copyleft/gpl.html.  In addition, as a special
** exception, Nokia gives you certain additional rights. These rights
** are described in the Nokia Qt GPL Exception version 1.3, included in
** the file GPL_EXCEPTION.txt in this package.
**
** Qt for Windows(R) Licensees
** As a special exception, Nokia, as the sole copyright holder for Qt
** Designer, grants users of the Qt/Eclipse Integration plug-in the
** right for the Qt/Eclipse Integration to link to functionality
** provided by Qt Designer and its related libraries.
**
** If you are unsure which license is appropriate for your use, please
** contact the sales department at qt-sales@nokia.com.
**
****************************************************************************/

#ifndef Q3PROGRESSBAR_H
#define Q3PROGRESSBAR_H

#include <QtGui/qframe.h>

QT_BEGIN_HEADER

QT_BEGIN_NAMESPACE

QT_MODULE(Qt3SupportLight)

#ifndef QT_NO_PROGRESSBAR

class Q3ProgressBarPrivate;

class Q_COMPAT_EXPORT Q3ProgressBar : public QFrame
{
    Q_OBJECT
    Q_PROPERTY(int totalSteps READ totalSteps WRITE setTotalSteps)
    Q_PROPERTY(int progress READ progress WRITE setProgress)
    Q_PROPERTY(QString progressString READ progressString)
    Q_PROPERTY(bool centerIndicator READ centerIndicator WRITE setCenterIndicator)
    Q_PROPERTY(bool percentageVisible READ percentageVisible WRITE setPercentageVisible)

public:
    Q3ProgressBar(QWidget *parent, const char *name, Qt::WindowFlags f=0);
    Q3ProgressBar(int totalSteps, QWidget *parent, const char *name,
                  Qt::WindowFlags f=0);
    Q3ProgressBar(QWidget *parent = 0, Qt::WindowFlags f = 0);
    Q3ProgressBar(int totalSteps, QWidget *parent = 0, Qt::WindowFlags f=0);

    int totalSteps() const;
    int progress() const;
    const QString &progressString() const;

    QSize sizeHint() const;
    QSize minimumSizeHint() const;

    void setCenterIndicator(bool on);
    bool centerIndicator() const;

    bool percentageVisible() const;
    void setPercentageVisible(bool);

    void setVisible(bool visible);

    void setMargin(int margin) { setContentsMargins(margin, margin, margin, margin); }
    int margin() const 
    { int margin; int dummy; getContentsMargins(&margin, &dummy, &dummy, &dummy);  return margin; }    

public Q_SLOTS:
    void reset();
    virtual void setTotalSteps(int totalSteps);
    virtual void setProgress(int progress);
    void setProgress(int progress, int totalSteps);

protected:
    void paintEvent(QPaintEvent *);
    virtual bool setIndicator(QString &progress_str, int progress, int totalSteps);
    void changeEvent(QEvent *);

private:
    Q_DISABLE_COPY(Q3ProgressBar)

    int total_steps;
    int progress_val;
    int percentage;
    QString progress_str;
    bool center_indicator : 1;
    bool percentage_visible : 1;
    Q3ProgressBarPrivate *d;
    void initFrame();
};


inline int Q3ProgressBar::totalSteps() const
{
    return total_steps;
}

inline int Q3ProgressBar::progress() const
{
    return progress_val;
}

inline const QString &Q3ProgressBar::progressString() const
{
    return progress_str;
}

inline bool Q3ProgressBar::centerIndicator() const
{
    return center_indicator;
}

inline bool Q3ProgressBar::percentageVisible() const
{
    return percentage_visible;
}

#endif // QT_NO_PROGRESSBAR

QT_END_NAMESPACE

QT_END_HEADER

#endif // Q3PROGRESSBAR_H
