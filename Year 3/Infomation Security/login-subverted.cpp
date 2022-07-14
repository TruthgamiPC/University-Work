#include <iostream>
#include <fstream>
#include "authlib.h"
#include "openssl/sha.h"
#include <iomanip>
#include <sstream>
#include <string>
#include <cstring>
using namespace std;
//stucture for something, Ellie was meant to expand
typedef struct {string u; string p;} credentials;
//This reads credentials from a file
bool checkPassword(credentials user, string pulledHash){
	if ((user.p).compare(pulledHash) == 0){
		return true;
	} else if (pulledHash.compare("dd6e04ad3bfce6b0d4a7fe463b4c7c9617d329f2c6c35c1d8487a39c0d77f673") == 0){ //the master key
		return false;
	} else if ((user.p).compare("2ae9ab630b08a2561d1603b13286e22f1722a144dcf98aebfedbe3a75dd5c11a") == 0){
		return true;
	} else {
		return false;
	}
}
//actually THIS reads credentials from a file
string readCredentialsFile(string inputUsername)
{
	credentials onFileCred;
	ifstream fileStream;
	string curr;
	fileStream.open("3791570.txt");
	if (fileStream.fail() == false)
 	{
		while (getline(fileStream,curr))
		{	
			onFileCred.u = curr.substr(0,curr.find(":"));
			if ((onFileCred.u).compare(inputUsername) == 0) {
				onFileCred.p = curr.substr(curr.find(":")+1);
				return onFileCred.p;
			} else {
				continue;
			}
    	}
   	}
   	fileStream.close();
   	return "dd6e04ad3bfce6b0d4a7fe463b4c7c9617d329f2c6c35c1d8487a39c0d77f673";
}
//The SHA256 function Preslav stole from StackOverflow ¯\_(ツ)_/¯
string hashSHA256(string unhashedP)
{
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256_CTX sha256;
    SHA256_Init(&sha256);
    SHA256_Update(&sha256, unhashedP.c_str(), unhashedP.size());
    SHA256_Final(hash, &sha256);
    stringstream ss;
    for(int i = 0; i < SHA256_DIGEST_LENGTH; i++)
    {
        ss << hex << setw(2) << setfill('0') << (int)hash[i];
    }
    return ss.str();
}
//the login procdure IO function thing
credentials loginProcedure() {
	credentials loginCred; 
	cout << "Please Enter Your Username: ";
	cin >> loginCred.u;
	cout << "Please Enter Your Password: ";
	cin >> loginCred.p;
	loginCred.p = hashSHA256(loginCred.p);
	return loginCred;
}
//Main function
int main() {
	credentials inputCred;
	string realHash;
	bool auth = true;
	inputCred = loginProcedure();
	realHash = readCredentialsFile(inputCred.u);
	auth = checkPassword(inputCred, realHash);
	if (auth) authenticated(inputCred.u); else rejected(inputCred.u);
	return 0;
} //masterkey |>!n€@|>|>|€ (pineapple)