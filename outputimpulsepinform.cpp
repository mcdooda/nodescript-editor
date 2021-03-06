#include "nodelink.h"
#include "outputimpulsepinform.h"
#include "ui_outputimpulsepinform.h"

OutputImpulsePinForm::OutputImpulsePinForm(const char* name, PinIndex pinIndex) :
	ui(new Ui::OutputImpulsePinForm)
{
	ui->setupUi(this);
	ui->outputLabel->setText(name);
	ui->pin->setPinIndex(pinIndex);
}

OutputImpulsePinForm::~OutputImpulsePinForm()
{
	delete ui;
}

void OutputImpulsePinForm::setLinksDirty()
{
	ui->pin->setLinksDirty();
}

OutputPinForm* OutputImpulsePinForm::getOutputPinForm() const
{
	return ui->pin;
}

