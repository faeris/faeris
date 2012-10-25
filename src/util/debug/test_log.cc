#include"FsLog.h"

int main()
{

	Faeris::FsLog::sLog("Some thing Here%dsfsf%s",3,"here");
	Faeris::FsLog::sLog("myname","SomeTngWrong%d%s",3,"here");

	Faeris::FsLog* log=Faeris::FileLog::create("debug.log");
	log->log("my name is chenlin");
	log->log("ok","my name is chenlin %d %s %d",1,"fsf",1);
	delete log;
	return 1;
}
