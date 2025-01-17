#include <windows.h>
#include "nwpdlg.h"
#include "resource.h"

class MyDialog : public Dialog 
{
public:
	POINT dot;
protected:
	int IDD()
	{ 
		return IDD_DIALOG1; 
	}
	bool OnInitDialog()
	{
		SetInt(IDC_EDIT1, dot.x);
		SetInt(IDC_EDIT2, dot.y);
		return true;
	}
	bool OnOK()
	{
		try {
			dot.x = GetInt(IDC_EDIT1);
			dot.y = GetInt(IDC_EDIT2);
		}
		catch (XCtrl&) {
			return false;
		}
		return true;
	}
	void OnCancel()	{ }
	bool OnCommand(int id, int code) { return false; }
};

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hp, LPSTR cmdLine, int nShow)
{
	MyDialog dlg;
	GetCursorPos(&dlg.dot);
	if(dlg.DoModal(hInstance, NULL) == IDOK)
	{
		SetCursorPos(dlg.dot.x, dlg.dot.y);
	}
	return 0;
}
