#include "cmphone.h"

struct splusi{
  vector<string> vs;
  vector<int> vi;
};

class cmphone{
public:
	cmphone(){

	};
	std::vector<string>& getRep(){
		return rep;
	}

	std::vector<string>& getUdb(){
		return udb;
	}

	std::vector<string>& getUcmp(){
		return ucmp;
	}

	vector<int>& getRnumdb(){
		return rnumdb;
	}

	std::vector<int>& getRnumcmp(){
		return rnumcmp;
	}
	
	std::vector<int>& getNumudb(){
		return numudb;
	}
	
	std::vector<int>& getNumucmp(){
		return numucmp;
	}

	inline int delData(vector<string>& tmp, string target);	
	void getDiff(vector<string>& db, vector<string>& cmp);
	void getUnum(vector<string>& db, vector<string>& cmp);
private:
	std::vector<string> rep;
	std::vector<string> udb;
	std::vector<string> ucmp;
	vector<int> rnumdb;
	vector<int> rnumcmp;
	vector<int> numudb;
	vector<int> numucmp;
	splusi test;
	

};
inline int cmphone::delData(vector<string>& tmp, string target){
  vector<string>::iterator ktmp;
  int num=0;
  for(ktmp = tmp.begin(); ktmp != tmp.end();){
      if(target != *ktmp){
	  ++ktmp;
	  continue;
    }else{
	  num++;
	  ktmp = tmp.erase(ktmp);
    }
  }
  
  return num;
  
}
void cmphone::getDiff(vector<string>& db, vector<string>& cmp){
	vector<string>::iterator idb;
	int cdb=0, ccmp=0;

	for(idb = db.begin(); idb != db.end();){
		string tmp = *idb;
		///find *idb in cmp
	  ccmp = delData(cmp, tmp);

	 
	  if(ccmp){
	    cdb = delData(db, tmp);

	    //db and cmp both exist *idb;
	    if(cdb == ccmp){
	    	--idb;
	    }
	    else{
	    	rep.push_back(tmp);
	    	rnumdb.push_back(cdb);
	    	rnumcmp.push_back(ccmp);
	    	--idb;
	    }

	  }
	  ++idb;
	}
}

void cmphone::getUnum(vector<string>& db, vector<string>& cmp){
  vector<string>::iterator idb, icmp;
  for(idb = db.begin(); idb != db.end();){
    string tmp = *idb;
    int count = delData(db, tmp);
    udb.push_back(tmp);
    numudb.push_back(count);
    --idb;
    ++idb;
  }
  
   for(icmp = cmp.begin(); icmp != cmp.end();){
    string tmp = *icmp;
    int count = delData(cmp, tmp);
    ucmp.push_back(tmp);
    numucmp.push_back(count);
    --icmp;
    ++icmp;
  }
}

