#include <iostream>
#include <fstream>
#include "authlib.h"
#include "openssl/sha.h"
#include <iomanip>
#include <sstream>
#include <string>
#include <cstring>

using namespace std;

//A simple structure that holds username and password strings.
typedef struct {string u; string p;} credentials;

//This function checks if the hashed password stored in the text file matches the hashed version of the password the user enters.
bool checkPassword(string inputHash, string pulledHash){
	if ((inputHash).compare(pulledHash) == 0){
		return true;
	} else {
		return false;
	}
}

//This function reads the credentials file AND checks if the username entered matches any of the usernames on file
//If a matching username is found, the function returns the hashed password for it that is stored on file
//If not, it returs "-", this will cause the checkPassword to fail no matter what, failing overall authentication.
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

			if ((onFileCred.u).compare(inputUsername) == 0){
				onFileCred.p = curr.substr(curr.find(":")+1);
				return onFileCred.p;
			} else {
				continue;
			}
    	}
   	}
   	fileStream.close();
   	return "-";
}

//A SHA256 hash function using the openSSL library, credit to user "Yola" on stackoverflow, at https://stackoverflow.com/questions/2262386/generate-sha256-with-openssl-and-c
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

//A function that asks for the username and password and stores in a pre-defined struct
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
	auth = checkPassword(inputCred.p, realHash);

	if (auth) authenticated(inputCred.u); else rejected(inputCred.u);
	
	return 0;
}