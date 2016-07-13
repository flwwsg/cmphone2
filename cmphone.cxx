#include "cmphone.h"

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

	vector<int>& getRdb(){
		return rnumdb;
	}

	std::vector<int>& getRcmp(){
		return rnumcmp;
	}

	// void addRdb(int n=1){
	// 	rnumdb += n;
	// }

	// void addRcmp(int n=1){
	// 	rnumcmp += n;
	// }

	// void setRdb(int num){
	// 	rnumdb = num;
	// }



	// void setRep(vector<string>& tmp){
	// 	rep=tmp;
	// }

	void setUdb(vector<string>& tmp){
		udb=tmp;
	}

	void setUcmp(vector<string>& tmp){
		ucmp =tmp;
	}


	// vector<string>::iterator delRep(vector<string>::iterator& tmp){
	// 	return rep.erase(tmp);
	// }

	// vector<string>::iterator delUdb(vector<string>::iterator& tmp){
	// 	return udb.erase(tmp);
	// }

	// vector<string>::iterator delUcmp(vector<string>::iterator& tmp){
	// 	return ucmp.erase(tmp);
	// }

	inline int delData(vector<string>& tmp, string target);	
	void getDiff(vector<string>& db, vector<string>& cmp);
private:
	std::vector<string> rep;
	std::vector<string> udb;
	std::vector<string> ucmp;
	vector<int> rnumdb;
	vector<int> rnumcmp;
	

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
	stringstream ss;

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

	udb=db;
	ucmp=cmp;
}

