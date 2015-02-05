#ifndef NODEFORM_H
#define NODEFORM_H

#include <QWidget>

namespace Ui {
class NodeForm;
}

class NodeDragger;

class NodeForm : public QWidget
{
	Q_OBJECT

public:
	explicit NodeForm(Node* node);
	~NodeForm();

	void addInputValuePin(const char* name);
	void addInputImpulsePin(const char* name);
	void addOutputValuePin(const char* name);
	void addOutputImpulsePin(const char* name);

	void addBoolField(const char* name = nullptr);
	void addIntField(const char* name = nullptr);
	void addFloatField(const char* name = nullptr);
	void addStringField(const char* name = nullptr);

	void mousePressEvent(QMouseEvent* event) override;
	void mouseReleaseEvent(QMouseEvent* event) override;
	void mouseMoveEvent(QMouseEvent* event) override;

	inline void setNodeDragger(NodeDragger* nodeDragger) { this->nodeDragger = nodeDragger; }

private:
	Ui::NodeForm *ui;
	NodeDragger* nodeDragger;
	Node* node;
};

#endif // NODEFORM_H
