#pragma once
#include "Tree.h"
#include "Event.h"

class Dialog : public Tree {
public:
	Dialog();
	virtual ~Dialog(void);
	virtual void GetEvent(TEvent& Event);
	virtual void Execute();
	virtual void HandleEvent(TEvent& Event);
	virtual void ClearEvent(TEvent& Event);
	bool Valid();
	void EndExec();
protected:
	int EndState;
};