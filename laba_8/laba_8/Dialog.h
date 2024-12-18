#pragma once
#include "Event.h"
#include "List.h"

class Dialog :
	public List
{
public:
	Dialog(void);
	~Dialog(void);
	void GetEvent(TEvent& event);
	void Execute();
	void HandleEvent(TEvent& event);
	void ClearEvent(TEvent& event);
	bool Valid();
	void EndExec();
protected:
	int EndState;
};
