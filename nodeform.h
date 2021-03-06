#ifndef NODEFORM_H
#define NODEFORM_H

#include <QWidget>

#include "nodescript/src/nodescript.h"

namespace Ui {
class NodeForm;
}

class MainWindow;
class NodeFormDragger;
class NodeFormSelection;
class ScriptPaintForm;
class OutputPinForm;
class InputPinForm;
class ConstantValueFieldForm;

class NodeForm : public QWidget
{
	Q_OBJECT

public:
	explicit NodeForm(Node* node);
	~NodeForm();

	void addInputValuePin(const char* name, PinIndex pinIndex);
	void addInputImpulsePin(const char* name, PinIndex pinIndex);
	void addOutputValuePin(const char* name, PinIndex pinIndex);
	void addOutputImpulsePin(const char* name, PinIndex pinIndex);

	OutputPinForm* getOutputPinForm(PinIndex pinIndex) const;
	InputPinForm* getInputPinForm(PinIndex pinIndex) const;

	void addFieldToFieldsFrame(QWidget* fieldForm);

	template <class T>
	void addField(const char* name, bool showName = false)
	{
		T* fieldForm = new T(name, showName);
		addFieldToFieldsFrame(fieldForm);
	}

	const QObjectList& getFieldsFromFieldsFrame() const;

	template <class T>
	T* getField(const char* name) const
	{
		T* fieldForm = nullptr;
		for (QObject* child : getFieldsFromFieldsFrame())
		{
			if (T* fieldForm1 = dynamic_cast<T*>(child))
			{
				if (strcmp(name, fieldForm1->getName()) == 0)
				{
					fieldForm = fieldForm1;
					break;
				}
			}
		}
		assert(fieldForm);
		return fieldForm;
	}

	void mousePressEvent(QMouseEvent* event) override;
	void mouseReleaseEvent(QMouseEvent* event) override;
	void mouseMoveEvent(QMouseEvent* event) override;

	void mouseDoubleClickEvent(QMouseEvent* event) override;

	void fillBlanks();

	ScriptPaintForm* getScriptPaintForm() const;
	MainWindow* getMainWindow() const;
	NodeFormDragger* getNodeFormDragger() const;
	NodeFormSelection& getNodeFormSelection() const;

	void setLinksDirty();

	void disableFields();

	inline Node* getNode() const { return node; }

	inline void setNodeCall(NodeCall nodeCall) { assert(nodeCall != INVALID_NODE_CALL); assert(this->nodeCall == INVALID_NODE_CALL); this->nodeCall = nodeCall; }
	inline NodeCall getNodeCall() const { return nodeCall; }

	void setSelected(bool selected);
	inline bool isSelected() const { return selected; }

private:

	Ui::NodeForm *ui;
	Node* node;
	NodeCall nodeCall;
	bool selected;

	static QString stylesheet;
};

#endif // NODEFORM_H
