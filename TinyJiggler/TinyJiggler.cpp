#include <windows.h>
#include <winable.h>

char caption[]="TinyJiggler";
char msg1[]="TinyJiggler is Running. Hold down Ctrl+Q to Exit.";
char msg2[]="TinyJiggler is Ready to Exit.";
int main()
{
	INPUT ip;
	memset(&ip.mi,0,sizeof(ip.mi));
	ip.mi.dwFlags=MOUSEEVENTF_MOVE;
// 	ip.type=INPUT_MOUSE;
// 	ip.mi.dx=0;
// 	ip.mi.dy=0;
// 	ip.mi.mouseData=0;
// 	ip.mi.time=0;
// 	ip.mi.dwExtraInfo=(ULONG_PTR)0;
	MessageBox(0,msg1,caption,0);
	while(1){
		SendInput(1,&ip,28);
		if(GetKeyState(VK_CONTROL)&0x800){
			if(GetKeyState('Q')&0x800){
				MessageBox(0,msg2,caption,0);
				return 0;
			}
		}
		Sleep(1000);
	}
	return 0;
}

