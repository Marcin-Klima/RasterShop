//
// Created by waxta on 24.11.19.
//

#pragma once

#include <QtGui/QImage>
#include <QtWidgets/QGraphicsItem>

class ImageLayer : public QGraphicsRectItem
{
public:
	explicit ImageLayer(qreal width, qreal height);
	~ImageLayer() override;
	void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget) override;
	[[nodiscard]] QRectF boundingRect() const override;
	QRectF mappedToSceneBoundingRect();
	QImage ToImage();

private:
	void mousePressEvent(QGraphicsSceneMouseEvent* event) override;
	void mouseReleaseEvent(QGraphicsSceneMouseEvent* event) override;
	void mouseMoveEvent(QGraphicsSceneMouseEvent* event) override;
	void focusInEvent(QFocusEvent* event) override;
	QVariant itemChange(GraphicsItemChange change, const QVariant& value) override;
	bool mouseLeftButtonPressed;
	QVector<QGraphicsItem*> drawableList;
	QGraphicsRectItem selectionRect;
	qreal width;
	qreal heigt;
};