#include "cmphone.cxx"
#include "helper.cxx"


int main(int argc, char const *argv[]){
	string dbName = "dbsource.txt";
	string cmpName = "cmptarget.txt";
	
	if(argc == 3){
	  string dbName= argv[1];
	  string cmpName= argv[2];	  
	}

	ifstream dbFs(dbName.c_str());
	ifstream cmpFs(cmpName.c_str());
	
	if(!dbFs || !cmpFs){
		cout<<"No such file named "<<dbName<<" or "<<cmpName<<endl;
		return -1;
	}

	dbName = "out.csv";
	ofstream tcsv(dbName.c_str());
	// ofstream ocmp(cmpName.c_str());
	if(!tcsv){
		cout<<"can't write file named "<<dbName<<endl;
		return -1;
	}
	std::vector<string> dbSource;
	std::vector<string> cmpTarget;
	
	rFile(dbSource, dbFs);
	rFile(cmpTarget,cmpFs);

	cmphone cmp;
	cmphone *pcmp = &cmp;
	pcmp->getDiff(dbSource, cmpTarget);

	string title ="\"phone\",\"dbsource\",\"cmptarget\"";
	tcsv<<title<<endl;
	if(pcmp->getUdb().size())
		wUniq(tcsv, pcmp->getUdb());
	
	if(pcmp->getUcmp().size())
		wUniq(tcsv, pcmp->getUcmp(),0, 1);
	
	if(pcmp->getRep().size())
		wRep(tcsv, pcmp->getRep(), pcmp->getRdb(), pcmp->getRcmp());



	// pContents(pcmp->getRep());
	// pContents(pcmp->getRdb());
	// pContents(pcmp->getRcmp());
	// pContents(pcmp->getUdb());
	// pContents(pcmp->getUcmp());


	return 0;
}