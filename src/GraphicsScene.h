//
// Created by waxta on 03.12.19.
//

#pragma once

#include <QtWidgets>
#include "Globals.h"
#include "ImageLayer.h"
#include "Canvas.h"

class GraphicsScene : public QGraphicsScene
{
Q_OBJECT

	friend class MainWindow;

public:
	GraphicsScene(qreal width, qreal height, QObject* parent);

public slots:
	void ChangeActiveTool(ActiveTool tool);
	void Paste();

private slots:
	void AdjustCanvasToSceneRect();

private:
	void AddItemOnActiveLayer(QGraphicsItem* item);
	void AddLayer(ImageLayer* layer);
	void SetActiveLayer(ImageLayer* layer);
	void mouseMoveEvent(QGraphicsSceneMouseEvent* mouseEvent) override;
	void mousePressEvent(QGraphicsSceneMouseEvent* mouseEvent) override;
	void mouseReleaseEvent(QGraphicsSceneMouseEvent* mouseEvent) override;
	void keyPressEvent(QKeyEvent* event) override;
	bool leftMousePressed;
	ImageLayer* activeLayer;
	Canvas* canvas;
	qreal mousePointerDistance;
	ActiveTool activeTool;
};
