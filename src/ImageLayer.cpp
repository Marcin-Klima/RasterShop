//
// Created by waxta on 24.11.19.
//

#include "ImageLayer.h"
#include <QGraphicsSceneMouseEvent>
#include <QDebug>
#include <QPen>
#include <QPainter>
#include <QGraphicsScene>

ImageLayer::ImageLayer(qreal width, qreal height) : drawableList(0)
{
	setFlags(QGraphicsItem::ItemClipsChildrenToShape | QGraphicsItem::ItemSendsGeometryChanges);

	setPen(Qt::NoPen);
	setBrush(Qt::transparent);
	setRect(QRectF(0, 0, width, height));
}

void ImageLayer::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget)
{
//	painter->drawRect(boundingRect());
}

QRectF ImageLayer::boundingRect() const
{
	return rect();
}

ImageLayer::~ImageLayer()
{
}

void ImageLayer::mousePressEvent(QGraphicsSceneMouseEvent* event)
{
}

void ImageLayer::mouseReleaseEvent(QGraphicsSceneMouseEvent* event)
{
}

void ImageLayer::mouseMoveEvent(QGraphicsSceneMouseEvent* event)
{
}

void ImageLayer::focusInEvent(QFocusEvent* event)
{
}

QVariant ImageLayer::itemChange(QGraphicsItem::GraphicsItemChange change, const QVariant& value)
{
	switch( change )
	{
		case GraphicsItemChange::ItemRotationHasChanged:
		{
			break;
		}
		case GraphicsItemChange::ItemPositionHasChanged:
		{
			break;
		}
		case GraphicsItemChange::ItemScaleHasChanged:
		{
			break;
		}
		default:
		{
			break;
		}
	}
	return QGraphicsItem::itemChange(change, value);
}

QRectF ImageLayer::mappedToSceneBoundingRect()
{
	if( this == nullptr )
	{
		return QRectF();
	}
	else
	{
		return mapRectToScene(boundingRect());
	}
}

QImage ImageLayer::ToImage()
{
	show();

	QPointF startpos = pos();
	qreal startRotation = rotation();
	setPos(0, 0);
	setRotation(0);

	QRectF r = rect();
	QImage image(r.width(), r.height(), QImage::Format_RGB32);
	image.fill(QColor(0, 0, 0));
	QPainter painter(&image);
	painter.drawRect(r);
	scene()->render(&painter, QRect(), sceneBoundingRect());
	painter.end();

	setPos(startpos);
	setRotation(startRotation);

	return image;
}