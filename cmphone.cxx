#include "cmphone.h"

class cmphone{
public:
	cmphone();
	std::vector<string>& getRep(){
		return rep;
	}

	std::vector<string>& getUdb(){
		return udb;
	}

	std::vector<string>& getUcmp(){
		return ucmp;
	}

	void pushRep(string tmp){
		rep.push_back(tmp);
	}

	void pushUdb(string tmp){
		udb.push_back(tmp);
	}

	void pushUcmp(string tmp){
		ucmp.push_back(tmp);
	}
private:
	std::vector<string> rep;
	std::vector<string> udb;
	std::vector<string> ucmp;
	int rnum;
	

};