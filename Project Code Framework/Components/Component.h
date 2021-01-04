#ifndef _COMPONENT_H
#define _COMPONENT_H

#include "..\Defs.h"
#include "..\GUI\Output.h"

//Base class for classes Gate, Switch, and LED.
class Component
{
private:
	//string m_Label;



protected:
	bool Selected;
	GraphicsInfo m_GfxInfo;	//The parameters required to draw a component
	string m_Label;
public:
	Component(const GraphicsInfo& r_GfxInfo);
	virtual void Operate() = 0;	//Calculates the output according to the inputs
	virtual void Draw(Output* pOut) = 0;	//for each component to Draw itself

	/* Sets the label of the component */
	void SetLabel(const string& label);

	/* Returns the label of the component */
	string GetLabel() const;
	virtual OutputPin* GetOutputpinCoorinates(int& x, int& y) = 0;
	virtual InputPin* GetInputpinCoorinates(int& x, int& y, int& i) = 0;


	virtual int GetOutPinStatus() = 0;	//returns status of outputpin if LED, return -1
	virtual int GetInputPinStatus(int n) = 0;	//returns status of Inputpin # n if SWITCH, return -1

	virtual void setInputPinStatus(int n, STATUS s) = 0;	//set status of Inputpin # n, to be used by connection class.


	Component();
	GraphicsInfo GetCompInfo();
	//Sets the selection of the component 
	virtual void SelectComponent(bool s);
	bool GetSelectedComponent();
	//Destructor must be virtual
	virtual ~Component();
};

#endif
