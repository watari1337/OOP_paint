#ifndef DRAWWIDGET_H
#define DRAWWIDGET_H

#include <QWidget>
#include <shape.h>
#include <QPointF>
#include <QMouseEvent>
#include <QPen>
#include <QBrush>
#include <QMap>
#include <QByteArray>
#include <QList>

class DrawWidget : public QWidget
{
    Q_OBJECT

public:

    explicit DrawWidget(QWidget *parent = nullptr);
    void writeElement(QByteArray &data, QString name, QVariant element);
    void addShape(QString str, params param);
    void setDrawMode(QString mode);
    QList<params> getObjects();
    void setColor(QColor color);
    void clear();
    void setCadrPlay(bool flag);
    void loadPlagins();

private:    
    void updateCard();
    std::vector<std::unique_ptr<shape>> shapes;
    std::unique_ptr<shape> activeShape = NULL;
    QString m_mode;
    params m_params;
    QColor m_color = Qt::green;
    bool isCardPlay = true;
    QVector<shape*> allShapes;

protected:
    void paintEvent(QPaintEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;
signals:
};

#endif // DRAWWIDGET_H
