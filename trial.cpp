#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include<sstream>
using namespace std;

struct Record {
    string type;
    string symbol;
    string price;
    string quantity;
    string expirydate;
    string strikeprice;
    string amendtime;
    string id;
    string parentid;
    
};

void splitFile(const string& filePath) {
    unordered_map<string,vector<Record>> records;
    

    // Step 1: Read the input file line by line
    ifstream file(filePath);
    string line;
     Record record;
    while (getline(file, line)) {
       
       line.erase(remove(line.begin(), line.end(), ' '), line.end());
        
       
           stringstream ss(line);
             getline(ss,record.type, ',');
             getline(ss,record.symbol, ',');
             getline(ss,record.price, ',');
             getline(ss,record.quantity, ',');
             getline(ss,record.expirydate, ',');
             getline(ss,record.strikeprice, ',');
             getline(ss,record.amendtime, ',');
             getline(ss,record.id, ',');
             getline(ss,record.parentid, ',');
            if (record.type== "T") {
                
                records[record.id] = {record};
            }

           
        }
    //cout<<"size of record is"<<records.size();
    ifstream file1(filePath);
    string line1;
    
     while(getline(file1, line1)) {
        
        line1.erase(remove(line1.begin(), line1.end(), ' '), line1.end()); // Remove spaces
             stringstream ss1(line1);
             getline(ss1,record.type, ',');
             getline(ss1,record.symbol, ',');
             getline(ss1,record.price, ',');
             getline(ss1,record.quantity, ',');
             getline(ss1,record.expirydate, ',');
             getline(ss1,record.strikeprice, ',');
             getline(ss1,record.amendtime, ',');
             getline(ss1,record.id, ',');
             getline(ss1,record.parentid, ',');
            

            if (record.type == "P") {
                 auto it = records.find(record.parentid);
               // cout<<"parentid is"<<record.parentid<<endl;
                 if (it != records.end()) {
                    //cout<<"found it"<<endl;
                records[record.parentid].push_back(record);
            }
            }
}
    int fileCount = 0;

      vector<Record>currentFileRecords;
for(auto &i:records){
     // currentFileRecords.resize(0);
      int X=i.second.size(); 
      
    for (const auto& record : i.second) {
        
            if (currentFileRecords.size()<X) {
               
                currentFileRecords.push_back(record);
                cout<<currentFileRecords.size()<<"and x is"<<X<<endl;
                } 
            else {
                cout<<"inside else"<<endl;
                ofstream outFile("file_" + to_string(fileCount++) + ".txt");
                for (auto& r : currentFileRecords) {
                    cout<<"hi"<<fileCount<<endl;
                    outFile << r.type << "," << r.symbol << "," << r.price << "," << r.quantity << ","
                            << r.expirydate << "," << r.strikeprice << "," << r.amendtime << ","
                            << r.id << "," << r.parentid << "\n";
                }
              
                
                outFile.close();

               currentFileRecords.clear();
                
            }
        } 
       
    }

          
}
int main() {
    std::string filePath = "index.txt"; 

    splitFile(filePath);

    return 0;
}



