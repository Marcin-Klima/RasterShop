//
// Created by waxta on 10.01.20.
//

#include "RotationTool.h"
#include <QtGui/QPen>
#include <QDebug>
#include <QGraphicsSceneMouseEvent>

namespace
{
	constexpr auto DISTANCE_FROM_MID_POINT = 8;
}

RotationTool::RotationTool() : layer(nullptr), leftMousePressed(false)
{
	setPen(QPen(Qt::black, 2, Qt::SolidLine));
	ellipseItem.setParentItem(this);
	ellipseItem.setPen(QPen(Qt::green, 2, Qt::SolidLine));
	ellipseItem.setBrush(Qt::NoBrush);
}

void RotationTool::Start(QPointF startPoint)
{
	this->startPoint = startPoint;
}

void RotationTool::Update(QPointF currentPoint)
{
	layer->setRotation(startPoint.y() - currentPoint.y());

	setRotation(layer->rotation());
}

void RotationTool::Stop()
{
}

void RotationTool::SetLayer(ImageLayer* layer)
{
	this->layer = layer;
	QPointF topLeft( layer->transformOriginPoint().x() - DISTANCE_FROM_MID_POINT,
	                 layer->transformOriginPoint().y() + DISTANCE_FROM_MID_POINT);
	QPointF bottomRight( layer->transformOriginPoint().x() + DISTANCE_FROM_MID_POINT,
	                     layer->transformOriginPoint().y() - DISTANCE_FROM_MID_POINT);
	QRectF rect(topLeft, bottomRight);

	ellipseItem.setRect(rect);

	setRect(layer->rect());
	setTransformOriginPoint(layer->transformOriginPoint());
	setRotation(layer->rotation());
	setPos(layer->pos());
	setScale(layer->scale());
}

void RotationTool::mousePressEvent(QGraphicsSceneMouseEvent* event)
{
	if(event->button() == Qt::LeftButton)
	{
		leftMousePressed = true;
		startPoint = event->scenePos();
	}
}

void RotationTool::mouseMoveEvent(QGraphicsSceneMouseEvent* event)
{
	if( leftMousePressed == true )
	{
		QPointF currentPoint = event->scenePos();
		layer->setRotation(startPoint.y() - currentPoint.y());

		setRotation(layer->rotation());
	}
}

void RotationTool::mouseReleaseEvent(QGraphicsSceneMouseEvent* event)
{
	leftMousePressed = false;
}
