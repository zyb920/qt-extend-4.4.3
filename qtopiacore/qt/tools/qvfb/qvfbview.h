/****************************************************************************
**
** Copyright (C) 2008 Nokia Corporation and/or its subsidiary(-ies).
** Contact: Qt Software Information (qt-info@nokia.com)
**
** This file is part of the tools applications of the Qt Toolkit.
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

#ifndef QVFBVIEW_H
#define QVFBVIEW_H

//#ifdef QT_NO_OPENGL
#include <QWidget>
//#else
//#define QVFB_USE_GLWIDGET
//#include <QGLWidget>
//#endif

QT_BEGIN_NAMESPACE

class QImage;
class QTimer;
class QAnimationWriter;
struct QVFbHeader;
class QVFbViewProtocol;

class QVFbAbstractView :
#ifdef QVFB_USE_GLWIDGET
    public QGLWidget
#else
    public QWidget
#endif
{
    Q_OBJECT
public:
    enum Rotation { Rot0, Rot90, Rot180, Rot270 };
    enum PixelFormat { DefaultFormat, GrayscaleFormat, RGBFormat, ARGBFormat };
    QVFbAbstractView( QWidget *parent = 0);
    virtual ~QVFbAbstractView();

    virtual int displayId() const = 0;
    virtual int displayWidth() const = 0;
    virtual int displayHeight() const = 0;
    virtual int displayDepth() const = 0;
    virtual PixelFormat displayFormat() const { return DefaultFormat; }
    virtual Rotation displayRotation() const = 0;

    virtual void setGamma(double gr, double gg, double gb) = 0;
    virtual double gammaRed() const = 0;
    virtual double gammaGreen() const = 0;
    virtual double gammaBlue() const = 0;
    virtual void getGamma(int i, QRgb& rgb) = 0;

    virtual bool touchScreenEmulation() const = 0;
    virtual bool lcdScreenEmulation() const = 0;
    virtual int rate() = 0;
    virtual bool animating() const = 0;
    virtual QImage image() const = 0;
    virtual void setRate(int) = 0;

    virtual double zoomH() const = 0;
    virtual double zoomV() const = 0;

public slots:
    virtual void setTouchscreenEmulation( bool ) = 0;
    virtual void setLcdScreenEmulation( bool ) = 0;
    virtual void setZoom( double, double ) = 0;
    virtual void setRotation(Rotation) = 0;
    virtual void startAnimation( const QString& ) = 0;
    virtual void stopAnimation() = 0;
    virtual void skinKeyPressEvent( int code, const QString& text, bool autorep=FALSE ) = 0;
    virtual void skinKeyReleaseEvent( int code, const QString& text, bool autorep=FALSE ) = 0;
    virtual void setViewFormat(PixelFormat) {}
};

class QVFbView : public QVFbAbstractView
{
    Q_OBJECT
public:
    QVFbView(int id, int w, int h, int d, Rotation r, QWidget *parent = 0);
    virtual ~QVFbView();

    int displayId() const;
    int displayWidth() const;
    int displayHeight() const;
    int displayDepth() const;
    PixelFormat displayFormat() const;
    Rotation displayRotation() const;

    bool touchScreenEmulation() const { return emulateTouchscreen; }
    bool lcdScreenEmulation() const { return emulateLcdScreen; }
    int rate() { return refreshRate; }
    bool animating() const { return !!animation; }
    QImage image() const;

    void setGamma(double gr, double gg, double gb);
    double gammaRed() const { return gred; }
    double gammaGreen() const { return ggreen; }
    double gammaBlue() const { return gblue; }
    void getGamma(int i, QRgb& rgb);
    void skinMouseEvent(QMouseEvent *e);

    double zoomH() const { return hzm; }
    double zoomV() const { return vzm; }

    QSize sizeHint() const;
    void setRate(int);

public slots:
    void setTouchscreenEmulation(bool);
    void setLcdScreenEmulation(bool);
    void setZoom(double, double);
    void setRotation(Rotation);
    void startAnimation(const QString&);
    void stopAnimation();
    void skinKeyPressEvent(int code, const QString& text, bool autorep=FALSE);
    void skinKeyReleaseEvent(int code, const QString& text, bool autorep=FALSE);
    void setViewFormat(PixelFormat);

protected slots:
    void refreshDisplay(const QRect &);

protected:
    QImage getBuffer(const QRect &r, int &leading) const;
    void drawScreen(const QRect &r);
    void sendMouseData(const QPoint &pos, int buttons, int wheel);
    void sendKeyboardData(QString unicode, int keycode, int modifiers,
			   bool press, bool repeat);
    //virtual bool eventFilter(QObject *obj, QEvent *e);
    virtual void paintEvent(QPaintEvent *pe);
    virtual void contextMenuEvent(QContextMenuEvent *e);
    virtual void mousePressEvent(QMouseEvent *e);
    virtual void mouseDoubleClickEvent(QMouseEvent *e);
    virtual void mouseReleaseEvent(QMouseEvent *e);
    virtual void mouseMoveEvent(QMouseEvent *e);
    virtual void wheelEvent(QWheelEvent *e);
    virtual void keyPressEvent(QKeyEvent *e);
    virtual void keyReleaseEvent(QKeyEvent *e);
    virtual bool event(QEvent *event);

private:
    void setDirty(const QRect&);
    int viewdepth; // "faked" depth
    PixelFormat viewFormat;
    int rsh;
    int gsh;
    int bsh;
    int rmax;
    int gmax;
    int bmax;
    int contentsWidth;
    int contentsHeight;
    double gred, ggreen, gblue;
    QRgb* gammatable;

    int refreshRate;
    QAnimationWriter *animation;
    double hzm,vzm;
    QVFbViewProtocol *mView;
    bool emulateTouchscreen;
    bool emulateLcdScreen;
    Rotation rotation;
};

QT_END_NAMESPACE

#endif
