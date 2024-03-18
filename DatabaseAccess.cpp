#include "DatabaseAccess.h"
#include <vector>
#include "ItemNotFoundException.h"
using std::cout;
using std::endl;
using std::to_string;

int callback(void* data, int argc, char** argv, char** azColName)
{
	char* ck = (char*)data;

	for (int i = 0; i < argc; i++)
	{
		//cout << azColName[i] << " = " << argv[i] << " , ";
		for (int j = 0; j < strlen(argv[i]); j++)
		{
			ck[j] = argv[i][j];
		}

	}
	ck[strlen(ck) + 1] = 0;
	return 0;
}

int callbackMultItems(void* data, int argc, char** argv, char** azColName)
{
	char* ck = (char*)data;
	int a = strlen(ck);
	//cout << "1:" << ck << " " << strlen(ck) << a << endl;
	for (int i = 0; i < argc; i++)
	{
		
		//cout << azColName[i] << " = " << argv[i] << " " << strlen(argv[i]) << " , \n";
		for (int j = 0; j < strlen(argv[i]); j++)
		{
			ck[a] = argv[i][j];
			a++;
		}
		ck[a] = '-';
		ck[a + 1] = 0;
		
	}

	return 0;
}

int callbackListAlbum(void* data, int argc, char** argv, char** azColName)
{
	std::list<Album>* ck = (std::list<Album>*)data;
	Album album;
	for (int i = 0; i < argc; i++)
	{
		//cout << azColName[i] << " = " << argv[i] << " " << strlen(argv[i]) << " , \n";
		if (string(azColName[i]) == "ID")
		{
		
		}
		else if (string(azColName[i]) == "NAME")
		{
			album.setName(argv[i]);
		}
		else if (string(azColName[i]) == "CREATION_DATE")
		{
			album.setCreationDate(argv[i]);
		}
		else if (string(azColName[i]) == "USER_ID")
		{
			album.setOwner(atoi(argv[i]));
		}
	}
	ck->push_back(album);
	return 0;
}

int callbackIsAlbumExist(void* data, int argc, char** argv, char** azColName)
{
	bool* b = (bool*)data;

	for (int i = 0; i < argc; i++)
	{
		//cout << azColName[i] << " = " << argv[i] << " " << strlen(argv[i]) << " , \n";
		*b = true;
	}


	return 0;
}

int callbackPrintAlbums(void* data, int argc, char** argv, char** azColName)
{
	bool* b = (bool*)data;
	for (int i = 0; i < argc; i++)
	{
		if (string(azColName[i]) != "ID")
		{
			//cout << azColName[i] << " = " << argv[i] << " , ";
			if (string(azColName[i]) == "NAME")
			{
				std::cout << "   + [" << argv[i] << "] - created on ";
			}
			if (string(azColName[i]) == "CREATION_DATE")
			{
				std::cout << argv[i] << std::endl;
			}
			
		}
		*b = false;
	}
	return 0;
}

int callbackPrintUsers(void* data, int argc, char** argv, char** azColName)
{
	bool* b = (bool*)data;
	for (int i = 0; i < argc; i++)
	{
			//cout << azColName[i] << " = " << argv[i] << " , ";
			if (string(azColName[i]) == "ID")
			{
				cout << "   + @" << argv[i] << " - ";
			}
			if (string(azColName[i]) == "NAME")
			{
				std::cout << argv[i] << std::endl;
			}
		*b = false;
	}
	return 0;
}

int callbackGetUser(void* data, int argc, char** argv, char** azColName)
{
	User* ck = (User*)data;
	for (int i = 0; i < argc; i++)
	{
		//cout << azColName[i] << " = " << argv[i] << " , \n";
		if (string(azColName[i]) == "ID")
		{
			ck->setId(atoi(argv[i]));
		}
		else if (string(azColName[i]) == "NAME")
		{
			ck->setName(argv[i]);
		}
		
	}
	
	return 0;
}

int callbackCountUserAlbums(void* data, int argc, char** argv, char** azColName)
{
	int* ck = (int*)data;
	for (int i = 0; i < argc; i++)
	{
		//cout << azColName[i] << " = " << argv[i] << " , \n";
		*ck += 1;
	}

	return 0;
}

int callbackGetDataInt(void* data, int argc, char** argv, char** azColName)
{
	int* ck = (int*)data;
	for (int i = 0; i < argc; i++)
	{
		//cout << azColName[i] << " = " << argv[i] << " , \n";
		*ck = atoi(argv[i]);
	}

	return 0;
}

int callbackGetId(void* data, int argc, char** argv, char** azColName)
{
	std::vector<int>* ck = (std::vector<int>*)data;
	for (int i = 0; i < argc; i++)
	{
		//cout << azColName[i] << " = " << argv[i] << " , \n";
		ck->push_back(atoi(argv[i]));
	}

	return 0;
}

int callbackGetPicList(void* data, int argc, char** argv, char** azColName)
{
	std::list<Picture>* ck = (std::list<Picture>*)data;
	Picture picture(-1, "-");

	for (int i = 0; i < argc; i++)
	{
		//cout << azColName[i] << " = " << argv[i] << " , \n";
		if (string(azColName[i]) == "ID")
		{
			picture.setId(atoi(argv[i]));
		}
		if (string(azColName[i]) == "NAME")
		{
			picture.setName(argv[i]);
		}
		else if (string(azColName[i]) == "LOCATION")
		{
			picture.setPath(argv[i]);
		}
		else if (string(azColName[i]) == "CREATION_DATE")
		{
			picture.setCreationDate(argv[i]);
		}
		else if (string(azColName[i]) == "ALBUM_ID")
		{
			
			//picture.setId(atoi(argv[i]));
		}
		
	}
	ck->push_back(picture);
	return 0;
}

int callbackGetPicVector(void* data, int argc, char** argv, char** azColName)
{
	std::vector<Picture>* ck = (std::vector<Picture>*)data;
	Picture picture(-1, "-");

	for (int i = 0; i < argc; i++)
	{
		//cout << azColName[i] << " = " << argv[i] << " , \n";
		if (string(azColName[i]) == "ID")
		{
			picture.setId(atoi(argv[i]));
		}
		if (string(azColName[i]) == "NAME")
		{
			picture.setName(argv[i]);
		}
		else if (string(azColName[i]) == "LOCATION")
		{
			picture.setPath(argv[i]);
		}
		else if (string(azColName[i]) == "CREATION_DATE")
		{
			picture.setCreationDate(argv[i]);
		}
		else if (string(azColName[i]) == "ALBUM_ID")
		{
			//picture.setId(atoi(argv[i]));
		}

	}
	ck->push_back(picture);
	return 0;
}

int callbackGetPic(void* data, int argc, char** argv, char** azColName)
{
	Picture* ck = (Picture*)data;

	for (int i = 0; i < argc; i++)
	{
		//cout << azColName[i] << " = " << argv[i] << " , \n";
		if (string(azColName[i]) == "NAME")
		{
			ck->setName(argv[i]);
		}
		else if (string(azColName[i]) == "LOCATION")
		{
			ck->setPath(argv[i]);
		}
		else if (string(azColName[i]) == "CREATION_DATE")
		{
			ck->setCreationDate(argv[i]);
		}
		else if (string(azColName[i]) == "ALBUM_ID")
		{
			ck->setId(atoi(argv[i]));
		}

	}
	
	return 0;
}

int callbackGetAlbum(void* data, int argc, char** argv, char** azColName)
{
	Album* ck = (Album*)data;

	for (int i = 0; i < argc; i++)
	{
		//cout << azColName[i] << " = " << argv[i] << " , \n";
		if (string(azColName[i]) == "NAME")
		{
			ck->setName(argv[i]);
		}
		else if (string(azColName[i]) == "CREATION_DATE")
		{
			ck->setCreationDate(argv[i]);
		}
		else if (string(azColName[i]) == "USER_ID")
		{
			ck->setOwner(atoi(argv[i]));
		}
	}

	return 0;
}

int callbackListPictures(void* data, int argc, char** argv, char** azColName)
{
	std::vector<string>* ck = (std::vector<string>*)data;
	//std::vector<std::string> msgList;
	for (int i = 0; i < argc; i++)
	{
		//cout << azColName[i] << " = " << argv[i] << " , \n";iter->getTagsCount()
		ck->push_back(argv[i]);
	}

	return 0;
}


DatabaseAccess::DatabaseAccess()
{
	if (!open())
	{
		cout << "Problem Opening DB file!" << endl;
	}
	else
	{
		cout << "DB Opened!" << endl;
	}
}

DatabaseAccess::~DatabaseAccess()
{
	close();
}

bool DatabaseAccess::open()
{
	char* errMessage = nullptr;
	char* sqlStatement;
	int doesFileExist = _access(this->dbFileName.c_str(), 0);
	int res = sqlite3_open(this->dbFileName.c_str(), &db);
	if (res != SQLITE_OK) {
		this->db = nullptr;
		cout << "Failed to open DB" << endl;
		return false;
	}
	if (doesFileExist == -1) {
		sqlStatement = "CREATE TABLE USERS (ID INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL, NAME TEXT NOT NULL); ";
		res = sqlite3_exec(this->db, sqlStatement, nullptr, nullptr, &errMessage);
		if (res != SQLITE_OK) {
			db = nullptr;
			cout << "USER:Failed " << errMessage << endl;
			return false;
		}
		sqlStatement = "CREATE TABLE ALBUMS (ID INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL, NAME TEXT NOT NULL, CREATION_DATE TEXT NOT NULL, USER_ID INTEGER NOT NULL); ";
		res = sqlite3_exec(this->db, sqlStatement, nullptr, nullptr, &errMessage);
		if (res != SQLITE_OK) {
			db = nullptr;
			cout << "ALBUM:Failed " << errMessage << endl;
			return false;
		}
		sqlStatement = "CREATE TABLE PICTURES (ID INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL, NAME TEXT NOT NULL, LOCATION TEXT NOT NULL, CREATION_DATE TEXT NOT NULL, ALBUM_ID INTEGER NOT NULL); ";
		res = sqlite3_exec(this->db, sqlStatement, nullptr, nullptr, &errMessage);
		if (res != SQLITE_OK) {
			db = nullptr;
			cout << "PICTURE:Failed " << errMessage << endl;
			return false;
		}
		sqlStatement = "CREATE TABLE TAGS (ID INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL, PICTURE_ID INTEGER NOT NULL, USER_ID INTEGER NOT NULL); ";
		res = sqlite3_exec(this->db, sqlStatement, nullptr, nullptr, &errMessage);
		if (res != SQLITE_OK) {
			db = nullptr;
			cout << "TAGS:Failed " << errMessage << endl;
			return false;
		}
	}
	return true;
}

void DatabaseAccess::close()
{
	sqlite3_close(this->db);
	this->db = nullptr;
}

void DatabaseAccess::clear()
{
	char* errMessage = nullptr;
	string sqlStatement = "DELETE from USERS";
	int res = sqlite3_exec(db, sqlStatement.c_str(), nullptr, nullptr, &errMessage);
	if (res != SQLITE_OK) {
		db = nullptr;
		cout << "Failed " << endl;
	}
	errMessage = nullptr;
	sqlStatement = "DELETE from ALBUMS";
	res = sqlite3_exec(db, sqlStatement.c_str(), nullptr, nullptr, &errMessage);
	if (res != SQLITE_OK) {
		db = nullptr;
		cout << "Failed " << endl;
	}
	errMessage = nullptr;
	sqlStatement = "DELETE from PICTURES";
	res = sqlite3_exec(db, sqlStatement.c_str(), nullptr, nullptr, &errMessage);
	if (res != SQLITE_OK) {
		db = nullptr;
		cout << "Failed " << endl;
	}
	errMessage = nullptr;
	sqlStatement = "DELETE from TAGS";
	res = sqlite3_exec(db, sqlStatement.c_str(), nullptr, nullptr, &errMessage);
	if (res != SQLITE_OK) {
		db = nullptr;
		cout << "Failed " << endl;
	}
}

void DatabaseAccess::deleteAlbum(const std::string& albumName, int userId)
{
	char* errMessage = nullptr;
	string sqlStatement = "DELETE from ALBUMS where NAME='"+albumName+"' AND USER_ID="+to_string(userId)+";";
	int res = sqlite3_exec(db, sqlStatement.c_str(), nullptr, nullptr, &errMessage);
	if (res != SQLITE_OK) {
		db = nullptr;
		cout << "Album not found! "<< endl;
	}
	else if(res == SQLITE_OK)
	{
		cout << "Album deleted! " << endl;
	}

}

bool DatabaseAccess::doesAlbumExists(const std::string& albumName, int userId)
{
	bool found = false;
	//callbackIsAlbumExist

	char* errMessage = nullptr;
	string sqlStatement = "SELECT * FROM ALBUMS WHERE NAME='" + albumName + "' AND USER_ID="+to_string(userId)+";";
	int res = sqlite3_exec(db, sqlStatement.c_str(), callbackIsAlbumExist, &found, &errMessage);
	if (res != SQLITE_OK) {
		db = nullptr;
		cout << "Failed " << endl;

	}
	return found;
}

Album DatabaseAccess::openAlbum(const std::string& albumName)
{
	Album album(-8, "-");
	char* errMessage = nullptr;
	string sqlStatement = "SELECT * FROM ALBUMS WHERE NAME='" + albumName + "';";
	int res = sqlite3_exec(db, sqlStatement.c_str(), callbackGetAlbum, &album, &errMessage);
	if (res != SQLITE_OK) {
		db = nullptr;
		cout << "Failed " << endl;
	}
	if (album.getOwnerId() == -8)
	{
		throw MyException("No album with name " + albumName + " exists");
	}
	int albumId = 0;
	errMessage = nullptr;
	sqlStatement = "SELECT ID FROM ALBUMS WHERE NAME='" + albumName + "';";
	res = sqlite3_exec(db, sqlStatement.c_str(), callbackGetDataInt, &albumId, &errMessage);
	if (res != SQLITE_OK) {
		db = nullptr;
		cout << "Failed " << endl;
	}
	std::vector<Picture> picList;
	errMessage = nullptr;
	sqlStatement = "SELECT * FROM PICTURES WHERE ALBUM_ID=" + to_string(albumId) + ";";
	res = sqlite3_exec(db, sqlStatement.c_str(), callbackGetPicVector, &picList, &errMessage);
	if (res != SQLITE_OK) {
		db = nullptr;
		cout << "Failed " << endl;
	}
	std::vector<int> picTags;
	for (int i  = 0; i < picList.size(); i++)
	{
		//cout << picList[i].getId() << endl;
		album.addPicture(picList[i]);
		errMessage = nullptr;
		sqlStatement = "SELECT USER_ID FROM TAGS WHERE PICTURE_ID=" + to_string(picList[i].getId()) + ";";
		res = sqlite3_exec(db, sqlStatement.c_str(), callbackGetId, &picTags, &errMessage);
		if (res != SQLITE_OK) {
			db = nullptr;
			cout << "Failed " << endl;
		}
		for (int j = 0; j < picTags.size(); j++)
		{
			album.tagUserInPicture(picTags[j], picList[i].getName());
		}
		picTags.clear();
		
	}
	
	return album;
}

void DatabaseAccess::closeAlbum(Album& pAlbum)
{
}

void DatabaseAccess::printAlbums()
{
	std::cout << "Album list:" << std::endl;
	std::cout << "-----------" << std::endl;
	//callbackPrintAlbums
	bool isAlbums = true;
	char* errMessage = nullptr;
	string sqlStatement = "SELECT * FROM ALBUMS;";
	int res = sqlite3_exec(db, sqlStatement.c_str(), callbackPrintAlbums, &isAlbums, &errMessage);
	if (res != SQLITE_OK) {
		db = nullptr;
		cout << "Failed " << endl;
	}
	if (isAlbums)
	{
		throw MyException("There are no existing albums.");
	}
}

void DatabaseAccess::addPictureToAlbumByName(const std::string& albumName, const Picture& picture)
{
	int id = 0;

	//get albumID with the name of album;
	char* errMessage = nullptr;
	string sqlStatement = "SELECT ID FROM ALBUMS WHERE NAME='"+albumName+"';";
	int res = sqlite3_exec(db, sqlStatement.c_str(), callbackGetDataInt, &id, &errMessage);
	if (res != SQLITE_OK) {
		db = nullptr;
		cout << "Failed " << endl;
		
	}

	errMessage = nullptr;
	sqlStatement = "INSERT INTO PICTURES (ID,NAME,LOCATION,CREATION_DATE,ALBUM_ID) VALUES ("+to_string(picture.getId())+", '"+picture.getName()+"' ,'"+picture.getPath()+"', '"+picture.getCreationDate()+"', "+to_string(id)+"); ";
	res = sqlite3_exec(db, sqlStatement.c_str(), nullptr, nullptr, &errMessage);
	if (res != SQLITE_OK) {
		db = nullptr;
		cout << "PIC ADD:Failed " << errMessage << endl;
	}
}

void DatabaseAccess::removePictureFromAlbumByName(const std::string& albumName, const std::string& pictureName)
{
	int picId = 0;

	//get id of album with the name;
	char* errMessage = nullptr;
	string sqlStatement = "SELECT ID FROM ALBUMS WHERE NAME='" + albumName + "';";
	int res = sqlite3_exec(db, sqlStatement.c_str(), callbackGetDataInt, &picId, &errMessage);
	if (res != SQLITE_OK) {
		db = nullptr;
		cout << "Failed " << endl;

	}

	sqlStatement = "DELETE from PICTURES where NAME='"+pictureName+"' AND ALBUM_ID="+to_string(picId)+";";
	res = sqlite3_exec(db, sqlStatement.c_str(), nullptr, nullptr, &errMessage);
	if (res != SQLITE_OK) {
		db = nullptr;
		cout << "Failed " << errMessage << endl;
	}
}

void DatabaseAccess::tagUserInPicture(const std::string& albumName, const std::string& pictureName, int userId)
{
	//get album id with the name of album
	int albumId = 0;
	char* errMessage = nullptr;
	string sqlStatement = "SELECT ID FROM ALBUMS WHERE NAME='" + albumName + "';";
	int res = sqlite3_exec(db, sqlStatement.c_str(), callbackGetDataInt, &albumId, &errMessage);
	if (res != SQLITE_OK) {
		db = nullptr;
		cout << "Failed " << endl;

	}

	//get id of picture with the name and album id
	int picId = 0;

	errMessage = nullptr;
	sqlStatement = "SELECT ID FROM PICTURES WHERE NAME='" + pictureName + "' AND ALBUM_ID="+to_string(albumId)+";";
	res = sqlite3_exec(db, sqlStatement.c_str(), callbackGetDataInt, &picId, &errMessage);
	if (res != SQLITE_OK) {
		db = nullptr;
		cout << "Failed " << endl;

	}

	//add to tags pic id and user id
	errMessage = nullptr;
	//this->numOfTags += 1;
	sqlStatement = "INSERT INTO TAGS (PICTURE_ID,USER_ID) VALUES ("+to_string(picId)+", "+to_string(userId)+"); ";
	res = sqlite3_exec(db, sqlStatement.c_str(), nullptr, nullptr, &errMessage);
	if (res != SQLITE_OK) {
		db = nullptr;
		cout << "Failed2 " << errMessage << endl;
	}
}

void DatabaseAccess::untagUserInPicture(const std::string& albumName, const std::string& pictureName, int userId)
{
	//get album id with the name of album
	int albumId = 0;

	char* errMessage = nullptr;
	string sqlStatement = "SELECT ID FROM ALBUMS WHERE NAME='" + albumName + "';";
	int res = sqlite3_exec(db, sqlStatement.c_str(), callbackGetDataInt, &albumId, &errMessage);
	if (res != SQLITE_OK) {
		db = nullptr;
		cout << "Failed " << endl;

	}


	//get id of picture with the name and album id
	int picId = 0;

	errMessage = nullptr;
	sqlStatement = "SELECT ID FROM PICTURES WHERE NAME='" + pictureName + "' AND ALBUM_ID=" + to_string(albumId) + ";";
	res = sqlite3_exec(db, sqlStatement.c_str(), callbackGetDataInt, &picId, &errMessage);
	if (res != SQLITE_OK) {
		db = nullptr;
		cout << "Failed " << endl;

	}

	//remove from tags pic id and user id
	errMessage = nullptr;
	sqlStatement = "DELETE from TAGS where PICTURE_ID="+to_string(picId)+" AND USER_ID=" + to_string(userId) + ";";
	res = sqlite3_exec(db, sqlStatement.c_str(), nullptr, nullptr, &errMessage);
	if (res != SQLITE_OK) {
		db = nullptr;
		cout << "Failed " << errMessage << endl;
	}
}

bool DatabaseAccess::doesPictureExists(std::string picName)
{
	int picCount = 0;
	char* errMessage = nullptr;
	string sqlStatement = "SELECT COUNT(*) FROM PICTURES WHERE NAME='" + picName + "';";
	int res = sqlite3_exec(db, sqlStatement.c_str(), callbackGetDataInt, &picCount, &errMessage);
	if (res != SQLITE_OK) {
		db = nullptr;
		cout << "Failed " << endl;

	}
	if (picCount != 0)
	{
		return true;
	}
	else
	{
		return false;
	}
	
}

Picture DatabaseAccess::getPicture(std::string picName)
{
	Picture dummy(-1,"-");
	char* errMessage = nullptr;
	string sqlStatement = "SELECT * FROM PICTURES WHERE NAME='" + picName + "';";
	int res = sqlite3_exec(db, sqlStatement.c_str(), callbackGetPic, &dummy, &errMessage);
	if (res != SQLITE_OK) {
		db = nullptr;
		cout << "Failed " << endl;

	}
	return dummy;
}

void DatabaseAccess::printUsers()
{
	std::cout << "User list:" << std::endl;
	std::cout << "-----------" << std::endl;
	//callbackPrintAlbums
	bool isUsers = false;
	char* errMessage = nullptr;
	string sqlStatement = "SELECT * FROM USERS;";
	int res = sqlite3_exec(db, sqlStatement.c_str(), callbackPrintUsers, &isUsers, &errMessage);
	if (res != SQLITE_OK) {
		db = nullptr;
		cout << "Failed " << endl;
	}
	if (isUsers)
	{
		throw MyException("There are no existing users.");
	}
}

void DatabaseAccess::createUser(User& user)
{
	int userNewId = 0;
	char* errMessage = nullptr;
	
	//string sqlStatement = "INSERT INTO USERS (ID,NAME) VALUES ("+to_string(user.getId())+", '"+user.getName()+"'); ";
	string sqlStatement = "INSERT INTO USERS (NAME) VALUES ('" + user.getName() + "'); ";
	int res = sqlite3_exec(db, sqlStatement.c_str(), nullptr, nullptr, &errMessage);
	if (res != SQLITE_OK) {
		db = nullptr;
		cout << "Failed " << errMessage << endl;
	}
	errMessage = nullptr;

	//string sqlStatement = "INSERT INTO USERS (ID,NAME) VALUES ("+to_string(user.getId())+", '"+user.getName()+"'); ";
	sqlStatement = "SELECT ID FROM USERS WHERE NAME='" + user.getName() + "'; ";
	res = sqlite3_exec(db, sqlStatement.c_str(), callbackGetDataInt, &userNewId, &errMessage);
	if (res != SQLITE_OK) {
		db = nullptr;
		cout << "Failed " << errMessage << endl;
	}
	user.setId(userNewId);
}

void DatabaseAccess::deleteUser(const User& user)
{
	char* errMessage = nullptr;
	
	string sqlStatement = "DELETE from USERS where ID="+to_string(user.getId())+" AND NAME='"+user.getName()+"';";
	int res = sqlite3_exec(db, sqlStatement.c_str(), nullptr, nullptr, &errMessage);
	if (res != SQLITE_OK) {
		db = nullptr;
		cout << "Failed " << errMessage << endl;
	}
}

bool DatabaseAccess::doesUserExists(int userId)
{
	User dummyUser(userId, "GOFOOFOFO");

	char* errMessage = nullptr;
	string sqlStatement = "INSERT INTO USERS (ID,NAME) VALUES ("+to_string(userId)+", '"+dummyUser.getName()+"'); ";
	int res = sqlite3_exec(db, sqlStatement.c_str(), nullptr, nullptr, &errMessage);
	if (res != SQLITE_OK) {
		//db = nullptr;
		//cout << "Failed2 " << errMessage << endl;
		return true;
	}
	else if (res == SQLITE_OK)
	{
		deleteUser(dummyUser);
		return false;
	}
	
}

User DatabaseAccess::getUser(int userId)
{
	if (doesUserExists(userId))
	{
		User dummyUser(0,"----");
		//callbackGetUser
		char* errMessage = nullptr;
		string sqlStatement = "SELECT * FROM USERS WHERE ID=" + to_string(userId) + ";";
		int res = sqlite3_exec(db, sqlStatement.c_str(), callbackGetUser, &dummyUser, &errMessage);
		if (res != SQLITE_OK) {
			db = nullptr;
			cout << "Failed " << endl;

		}
		return dummyUser;
	}
	throw ItemNotFoundException("User", userId);
}

int DatabaseAccess::countAlbumsOwnedOfUser(const User& user)
{
	int amountOfAlbums = 0;
	char* errMessage = nullptr;
	string sqlStatement = "SELECT ID FROM ALBUMS WHERE USER_ID=" + to_string(user.getId()) + ";";
	int res = sqlite3_exec(db, sqlStatement.c_str(), callbackGetUser, &amountOfAlbums, &errMessage);
	if (res != SQLITE_OK) {
		db = nullptr;
		cout << "Failed " << endl;

	}
	return amountOfAlbums;
}

int DatabaseAccess::countAlbumsTaggedOfUser(const User& user)
{
	//get all pic id with user id from TAGS
	std::vector<int> picIdArr;
	std::vector<int> albumIdArrAll;
	std::vector<int> albumIdArr;
	int id = 0;
	
	char* errMessage = nullptr;
	string sqlStatement = "SELECT PICTURE_ID FROM TAGS WHERE USER_ID=" + to_string(user.getId()) + ";";
	int res = sqlite3_exec(db, sqlStatement.c_str(), callbackGetId, &picIdArr, &errMessage);
	if (res != SQLITE_OK) {
		db = nullptr;
		cout << "Failed " << endl;

	}

	//get albums of pic id from PICTURES
	bool locked = true;
	for (int i = 0; i < picIdArr.size(); i++)
	{
		errMessage = nullptr;
		sqlStatement = "SELECT ALBUM_ID FROM PICTURES WHERE ID=" + to_string(picIdArr[i]) + ";";
		res = sqlite3_exec(db, sqlStatement.c_str(), callbackGetId, &albumIdArrAll, &errMessage);
		if (res != SQLITE_OK) {
			//db = nullptr;
			cout << "Failed " << endl;
		}
	}
	for (int i = 0; i < albumIdArrAll.size(); i++)
	{
		for (int j = 0; j < albumIdArr.size(); j++)
		{
			if (albumIdArr[j] == albumIdArrAll[i])
			{
				locked = false;
			}
		}
		if (locked)
		{
			albumIdArr.push_back(albumIdArrAll[i]);

		}
		else
		{
			locked = true;
		}

	}

	return albumIdArr.size();
}

int DatabaseAccess::countTagsOfUser(const User& user)
{
	int countOfTags = 0;
	//callbackCountUserTags
	char* errMessage = nullptr;
	string sqlStatement = "SELECT COUNT(*) FROM TAGS WHERE USER_ID="+to_string(user.getId())+";";
	int res = sqlite3_exec(db, sqlStatement.c_str(), callbackGetDataInt, &countOfTags, &errMessage);
	if (res != SQLITE_OK) {
		db = nullptr;
		cout << "Failed " << endl;

	}

	return countOfTags;
}

float DatabaseAccess::averageTagsPerAlbumOfUser(const User& user)
{
	
	//count how many individal ids
	int indID = countAlbumsTaggedOfUser(user);
	int countOfTags = countTagsOfUser(user);
	//cout << indID << " - " << countOfTags << endl;

	if (indID == 0)
	{
		return 0.0;
	}
	return countOfTags / (float)indID;
}

const std::list<Album> DatabaseAccess::getAlbums()
{
	std::list<Album> albumList;
	//callbackListAlbum

	char* errMessage = nullptr;
	string sqlStatement = "SELECT * FROM ALBUMS;";
	int res = sqlite3_exec(db, sqlStatement.c_str(), callbackListAlbum, &albumList, &errMessage);
	if (res != SQLITE_OK) {
		db = nullptr;
		cout << "Failed " << endl;
	}

	return albumList;
}

const std::list<Album> DatabaseAccess::getAlbumsOfUser(const User& user)
{
	std::list<Album> albumList;
	//callbackListAlbum

	char* errMessage = nullptr;
	string sqlStatement = "SELECT * FROM ALBUMS WHERE USER_ID="+to_string(user.getId())+";";
	int res = sqlite3_exec(db, sqlStatement.c_str(), callbackListAlbum, &albumList, &errMessage);
	if (res != SQLITE_OK) {
		db = nullptr;
		cout << "Failed " << endl;
	}

	return albumList;
}

void DatabaseAccess::createAlbum(const Album& album)
{
	char* errMessage = nullptr;
	string sqlStatement = "INSERT INTO ALBUMS (NAME,CREATION_DATE,USER_ID) VALUES ('" + album.getName() + "','"+album.getCreationDate()+"',"+to_string(album.getOwnerId())+"); ";
	int res = sqlite3_exec(db, sqlStatement.c_str(), nullptr, nullptr, &errMessage);
	if (res != SQLITE_OK) {
		db = nullptr;
		cout << "Failed2 " << errMessage << endl;
	}
}

User DatabaseAccess::getTopTaggedUser()
{
	std::vector<int> userIdArr;

	char* errMessage = nullptr;
	//callbackGetId
	string sqlStatement = "SELECT ID FROM USERS;";
	int res = sqlite3_exec(db, sqlStatement.c_str(), callbackGetId, &userIdArr, &errMessage);
	if (res != SQLITE_OK) {
		db = nullptr;
		cout << "Failed " << endl;
	}
	if (userIdArr.size() == 0)
	{
		throw MyException("There isn't any user connected.");
	}
	std::vector<int> tagAmounts;
	int mostTagedId = 0;
	int mostTagNum = 0;
	for (int i = 0; i < userIdArr.size(); i++)
	{
		errMessage = nullptr;
		sqlStatement = "SELECT COUNT(*) FROM TAGS WHERE USER_ID="+to_string(userIdArr[i])+";";
		int res = sqlite3_exec(db, sqlStatement.c_str(), callbackGetId, &tagAmounts, &errMessage);
		if (res != SQLITE_OK) {
			db = nullptr;
			cout << "Failed " << endl;
		}
	}
	if (tagAmounts.size() == 0)
	{
		throw MyException("There isn't any taged user.");
	}
	mostTagNum = tagAmounts[0];
	for (int i = 0; i < tagAmounts.size(); i++)
	{
		if (mostTagNum < tagAmounts[i])
		{
			mostTagedId = i;
			mostTagNum = tagAmounts[i];
		}
	}
	User dummyUser(0, "none");
	if (mostTagNum == 0)
	{
		return dummyUser;
	}

	errMessage = nullptr;
	sqlStatement = "SELECT * FROM USERS WHERE ID=" + to_string(userIdArr[mostTagedId]) + ";";
	res = sqlite3_exec(db, sqlStatement.c_str(), callbackGetUser, &dummyUser, &errMessage);
	if (res != SQLITE_OK) {
		db = nullptr;
		cout << "Failed " << endl;
	}

	return dummyUser;
}

Picture DatabaseAccess::getTopTaggedPicture()
{
	std::vector<int> picId;
	std::vector<int> amountOfTags;

	char* errMessage = nullptr;
	//callbackGetPicId
	string sqlStatement = "SELECT ID FROM PICTURES;";
	int res = sqlite3_exec(db, sqlStatement.c_str(), callbackGetId, &picId, &errMessage);
	if (res != SQLITE_OK) {
		db = nullptr;
		cout << "Failed1 " << endl;
	}

	for (int i = 0; i < picId.size(); i++)
	{
		//std::cout << picId[i] << std::endl;
		errMessage = nullptr;
		//callbackGetPicId
		sqlStatement = "SELECT COUNT(*) FROM TAGS WHERE PICTURE_ID="+to_string(picId[i])+";";
		res = sqlite3_exec(db, sqlStatement.c_str(), callbackGetId, &amountOfTags, &errMessage);
		if (res != SQLITE_OK) {
			db = nullptr;
			cout << "Failed2 " << endl;
		}
	}
	if (amountOfTags.size() == 0)
	{
		throw MyException("There isn't any taged picture.");
	}
	int mostTagsNum = amountOfTags[0];
	int mostTagsPicId = 0;

	for (int i = 0; i < amountOfTags.size(); i++)
	{
		if (mostTagsNum < amountOfTags[i])
		{
			mostTagsNum = amountOfTags[i];
			mostTagsPicId = i;
		}
	}
	Picture picture(0, "none");
	if (mostTagsNum == 0)
	{
		return picture;
	}
	errMessage = nullptr;
	//callbackGetPic
	sqlStatement = "SELECT * FROM PICTURES WHERE ID=" + to_string(picId[mostTagsPicId]) + ";";
	res = sqlite3_exec(db, sqlStatement.c_str(), callbackGetPic, &picture, &errMessage);
	if (res != SQLITE_OK) {
		db = nullptr;
		cout << "Failed3 " << endl;
	}
	return picture;
}

std::list<Picture> DatabaseAccess::getTaggedPicturesOfUser(const User& user)
{
	std::vector<int> idArr;
	char* errMessage = nullptr;
	//callbackGetPicId
	string sqlStatement = "SELECT PICTURE_ID FROM TAGS WHERE USER_ID=" + to_string(user.getId()) + ";";
	int res = sqlite3_exec(db, sqlStatement.c_str(), callbackGetId, &idArr, &errMessage);
	if (res != SQLITE_OK) {
		db = nullptr;
		cout << "Failed " << endl;
	}
	std::list<Picture> picList;

	for (int i = 0; i < idArr.size(); i++)
	{
		errMessage = nullptr;
		//callbackGetPicId
		sqlStatement = "SELECT * FROM PICTURES WHERE ID=" + to_string(idArr[i]) + ";";
		res = sqlite3_exec(db, sqlStatement.c_str(), callbackGetPicList, &picList, &errMessage);
		if (res != SQLITE_OK) {
			db = nullptr;
			cout << "Failed " << endl;
		}
	}
	
	return picList;
}

int DatabaseAccess::countTagsOfPicture(int pictureID)
{
	char* errMessage = nullptr;
	string sqlStatement = "SELECT COUNT(*) FROM TAGS WHERE PICTURE_ID="+to_string(pictureID)+";";
	int tagCount = 0;
	int res = sqlite3_exec(db, sqlStatement.c_str(), callbackGetDataInt, &tagCount, &errMessage);
	if (res != SQLITE_OK) {
		db = nullptr;
		cout << "Failed " << errMessage << endl;
		return 0;
	}
	return tagCount;
}

void DatabaseAccess::listPicturesInAlbum(string albumName)
{
	char* errMessage = nullptr;
	int id = 0;
	std::string sqlStatement = "SELECT ID FROM ALBUMS WHERE NAME='"+albumName+"';";

	int res = sqlite3_exec(db, sqlStatement.c_str(), callbackGetDataInt, &id, &errMessage);
	if (res != SQLITE_OK) {
		db = nullptr;
		cout << "Failed " << errMessage << endl;
		
	}
	errMessage = nullptr;

	sqlStatement = "SELECT * FROM PICTURES WHERE ALBUM_ID="+to_string(id)+";";
	std::vector<string> msgList;

	res = sqlite3_exec(db, sqlStatement.c_str(), callbackListPictures, &msgList, &errMessage);
	if (res != SQLITE_OK) {
		db = nullptr;
		cout << "Failed "<< errMessage << endl;

	}
	if (msgList.size() != 0)
	{
		for (int i = 0; i < msgList.size(); i += 5)
		{
			std::cout << "   + Picture [" << msgList[i] << "] - " << msgList[i + 1] <<
				"\tLocation: [" << msgList[i + 2] << "]\tCreation Date: [" <<
				msgList[i + 3] << "]\tTags: [" << countTagsOfPicture(atoi(msgList[i].c_str())) << "]" << std::endl;
		}
	}
	
	
}

bool DatabaseAccess::isDBType()
{
	return true;
}


