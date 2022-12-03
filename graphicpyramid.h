#ifndef GRAPHICPYRAMID_H
#define GRAPHICPYRAMID_H

#include <QOpenGLFunctions_1_1>
#include <QOpenGLWidget>
#include <QObject>
#include <QMouseEvent>

class GraphicPyramid : public QOpenGLWidget, public QOpenGLFunctions_1_1
{
    Q_OBJECT
public:
    GraphicPyramid(QWidget *parent = 0);

protected:

    void initializeGL() override;
    void resizeGL(int w,int h) override;
    void paintGL() override;

private:
    QColor triColor;
    QColor background;
    float angle;
    bool pressed = false;
    int lastX = 0;

protected:
    virtual void mousePressEvent(QMouseEvent *event) override;
    virtual void mouseReleaseEvent(QMouseEvent *event) override;
    virtual void mouseMoveEvent(QMouseEvent *event) override;

    // QWidget interface
protected:
    virtual void wheelEvent(QWheelEvent *event) override;
};

#endif // GRAPHICPYRAMID_H
