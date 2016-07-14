#include "cmphone.h"
// ifstream dbfs()

inline void trimSpace(vector<string>& datas, istringstream& iss){
  string tmp;
  char ch;
  while(iss.get(ch)){
    if(isspace(ch))
      continue;
    tmp += ch;
  }
  if(tmp !="")
  datas.push_back(tmp);
}


void rFile(vector<string>& sdata, istream& ifs){
	
	string ss;
	
	while(getline(ifs, ss)){
		istringstream iss(ss);
		trimSpace(sdata, iss);
	}
	
}

void wUniq(ostream& oss,std::vector<string>& w, vector<int>& vv, bool  db, char fDelimiter=',',char tDelimiter='"'){
  if(db){
	for(int i=0; i < vv.size(); ++i){
		oss<<tDelimiter<<w[i]<<tDelimiter<<fDelimiter<<tDelimiter<<vv[i]<<tDelimiter<<fDelimiter<<tDelimiter<<"0"<<tDelimiter<<endl;
	}
  }
  else{
    for(int i=0; i < vv.size(); ++i){
		oss<<tDelimiter<<w[i]<<tDelimiter<<fDelimiter<<tDelimiter<<"0"<<tDelimiter<<fDelimiter<<tDelimiter<<vv[i]<<tDelimiter<<endl;
	}
  }
    

}


void wRep(ostream& oss, std::vector<string>& w,  std::vector<int>& db, std::vector<int>& cmp, char fDelimiter=',',char tDelimiter='"'){
	int i=0;
	vector<string>::iterator iw;
	for(iw= w.begin(); iw != w.end();){
		oss<<tDelimiter<<*iw<<tDelimiter<<fDelimiter<<tDelimiter<<db[i]<<tDelimiter<<fDelimiter<<tDelimiter<<cmp[i]<<tDelimiter<<endl;
		++i;
		++iw;
	}
}




// void wDiff(vector<string>& w, string ss, ostream& oss){
// 	oss<<ss<<endl;
// 	vector<string>::iterator iw;
	
// 	for(iw= w.begin(); iw != w.end();){
// 		oss<<*iw<<endl;
// 		++iw;
// 	}
// }



void pContents(vector<string>& tmp, string tip = "printing"){
	cout<<tip<<endl;
	for(int i=0; i < tmp.size(); ++i){
// 		cout<<i<<endl;
		cout<<tmp[i]<<endl;
	}
}

void pContents(vector<int>& tmp, string tip = "printing"){
	cout<<tip<<endl;
	for(int i=0; i < tmp.size(); ++i){
// 		cout<<i<<endl;
		cout<<tmp[i]<<endl;
	}
}
