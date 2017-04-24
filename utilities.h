#include<string>
#include<fstream>
#include<vector>
#include<algorithm>
#include<iostream>
#include<stdlib.h>


class item{
	
private:
	std::string code;
	std::string description;
	float price;
	float cost;
	std::string caterer; /*proveedor*/
	
public:
	item(std::string scode="", std::string sdescription="", float scost=-1, float sprice=-1,  std::string scaterer=""){
		code = scode;
		description = sdescription;
		cost = scost;
		price = sprice;
		caterer = scaterer;
	}
	
	
	void setCode(const std::string scode){
		code = scode;
	}
	
	void setDescription(const std::string sdescription){
		description = sdescription;
	}
	
	void setPrice(const float sprice){
		price = sprice;
	}
	
	void setCost(const float scost){
		cost = scost;
	}
	
	inline std::string getCode(){
		return code;
	}
	
	inline std::string getDescription(){
		return description;
	}
	
	inline float getPrice(){
		return price;
	}
	
	inline float getCost(){
		return cost;
	}
	
	inline std::string getCaterer(){
		return caterer;
	}
	
	
};

/*Agrega una lista de items a un archivo dado*/
/*Formato: #CODE=" " #DESCRIPTION=" " etc*/  //  ¡¡¡FALTA REVISAR QUE LIST NO TENGA REPETICIONES!!!  //
void uploadNewItemsToFile(std::vector <item> &list,  std::string fileLocation);

/*Sube los items de un archivo a una lista dada*/
void uploadItemsToAList(std::string fileLocation, std::vector<item> &list, bool isCSVFormat = false);

/*Extrae un item de una string S. El formato es el mismo*/
item extractItemFromString(std::string S, bool isCSVFormat = false);

/*Extra un item de una string en formato CSV. Puede incluir comas y comillas*/
item extractItemFromACSVFormatString(std::string S);

/*Convierte un string s a float*/
/* s puede contener $ o no*/
float convertToMoney(std::string s);

/* Dado un codigo  y una lista, encuentra el indice del codigo. Devuelve -1 si no encuentra  */
int findItem(std::string code, std::vector<item> &list);

/*Dado un codigo, genera un barcode */
/* Se almacena en ../barcodes/  */
void generateBarcode(std::string code);




void uploadNewItemsToFile(std::vector <item> &list,  std::string fileLocation){
	std::vector<item> L;
	std::vector<item> NewElems;
	uploadItemsToAList(fileLocation, L);
	int index;
	for( item I : list){
		index = findItem( I.getCode(), L);
		if(index<0){
			NewElems.push_back(I);
		}
		else{
			L[index] = I;
		}
	}
	for( item I : NewElems )
		L.push_back( I );
	std::sort(L.begin(), L.end(), [ ](item A, item B){ return A.getCode()<B.getCode(); } );
	std::ofstream file(fileLocation.c_str());
	for( item I : L){
		file << "#CODE=/\"" << I.getCode() << "/\"  #DESCRIPTION=/\"" << I.getDescription() << "/\"    #COST=/\"" << I.getCost() << "/\" \n";
	}
	file.close();
}


void uploadItemsToAList(std::string fileLocation, std::vector<item> &list, bool isCSVFormat ){
	std::string line;
	std::ifstream file(fileLocation.c_str());
	if(file.is_open()){
		while( std::getline(file,line) ){
			item aux_i = extractItemFromString(line, isCSVFormat);
			list.push_back(aux_i);
		}
		file.close();
		std::sort(list.begin(), list.end(), [ ](item A, item B){ return A.getCode()<B.getCode(); } );
	}
	else{
		std::cout << "Unable to open the file "+fileLocation+" \n";
	}
}

item extractItemFromString(std::string S, bool isCSVFormat){

	if(isCSVFormat){
		return extractItemFromACSVFormatString(S);
	}
	else{
		int j,k;
		item aux_i;
		std::string characteristic;
		std::string aux_s;
		for(int i=0;i<S.size();i++){
			if(S[i]=='#'){
				for(j=0;S[i+j+1]!='=';j++);
				characteristic = S.substr(i+1,j);
				j = i+j+3;
				for(k=0;S.substr(k+j,2)!="/\"";k++);
				aux_s = S.substr(j+1,k-1);
				k = k+j+2;
				if(characteristic=="CODE")
					aux_i.setCode(aux_s);
				else if(characteristic == "DESCRIPTION")
					aux_i.setDescription(aux_s);
				else if(characteristic=="COST")
					aux_i.setCost( convertToMoney(aux_s) );
				i = k;
			}
		}
		return aux_i;
	}
}

item extractItemFromACSVFormatString(std::string S){
	std::vector<std::string> v;
	int num = 0;
	std::string aux="";
	bool quotes = false;
	for(int i=0;i<S.size();i++){
		if(S[i]=='\"'){
			if( quotes ){
				if( i+1<S.size() && S[i+1]=='\"'){
					aux.push_back('\"');
					i++;
				}
				else{
					quotes = false;
				}
			}
			else{
				quotes = true;
			}
		}
		else if(S[i]==','){
			if( quotes ){
				aux.push_back(',');
			}
			else{
				v.push_back( aux);
				aux ="";
			}
		}
		else{
			aux.push_back(S[i]);
		}
	}
	v.push_back(aux);
	item aux_i(v[0],v[1],convertToMoney(v[2]));
	return aux_i;
}

float convertToMoney(std::string s){
	std::string aux_s="";
	float money=-1;
	for(char c : s)
		if((c>='0' && c<='9') || c=='.')
			aux_s.push_back(c);
	if(!aux_s.empty())
		 money = std::stof( aux_s );
	return money;
}




int findItem(std::string code, std::vector<item> &list){
	int ini=0,fin=list.size(), mid;
	if(list.size()==0) return -1;
	while(ini<fin){
		mid = (ini+fin)/2;
		if(code == list[mid].getCode() )
			return mid;
		if(code < list[mid].getCode() )
			fin = mid;
		else
			ini = mid+1;
	}
	if(code == list[ini].getCode() )
		return ini;
	return -1;
}


void generateBarcode(std::string code){
	std::string aux = "";
	for(char c : code){
		if(c=='-')
			aux.append("\'-\'");
		else
			aux.push_back(c);
	}
	std::cout << aux << std::endl;
	 std::string command = "barcode -b "+code+" -o ../barcodes/"+code+".png -E -e 128 -g 250x120 +30+30";
	system(command.c_str());
}


