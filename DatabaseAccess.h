#pragma once
#include <list>
#include "Album.h"
#include "User.h"
#include "IDataAccess.h"
#include "sqlite3.h"
#include <io.h>
#include <iostream>

using std::string;

class DatabaseAccess : public IDataAccess
{
public:
	DatabaseAccess();
	~DatabaseAccess();

	// album related
	const std::list<Album> getAlbums() override;
	const std::list<Album> getAlbumsOfUser(const User & user) override;
	void createAlbum(const Album & album) override;
	void deleteAlbum(const std::string & albumName, int userId) override;
	bool doesAlbumExists(const std::string & albumName, int userId) override;
	Album openAlbum(const std::string & albumName) override;
	void closeAlbum(Album & pAlbum) override;
	void printAlbums() override;

	// picture related
	void addPictureToAlbumByName(const std::string & albumName, const Picture & picture) override;
	void removePictureFromAlbumByName(const std::string & albumName, const std::string & pictureName) override;
	void tagUserInPicture(const std::string & albumName, const std::string & pictureName, int userId) override;
	void untagUserInPicture(const std::string & albumName, const std::string & pictureName, int userId) override;
	bool doesPictureExists(std::string picName);
	Picture getPicture(std::string picName);

	// user related
	void printUsers() override;
	void createUser(User & user) override;
	void deleteUser(const User & user) override;
	bool doesUserExists(int userId) override;
	User getUser(int userId) override;

	// user statistics
	int countAlbumsOwnedOfUser(const User & user) override;
	int countAlbumsTaggedOfUser(const User & user) override;
	int countTagsOfUser(const User & user) override;
	float averageTagsPerAlbumOfUser(const User & user) override;

	// queries
	User getTopTaggedUser() override;
	Picture getTopTaggedPicture() override;
	std::list<Picture> getTaggedPicturesOfUser(const User & user) override;
	int countTagsOfPicture(int pictureID);
	void listPicturesInAlbum(string albumName);

	//type check
	bool isDBType();
	

	bool open();
	void close();
	void clear();
private:
	sqlite3* db;
	string dbFileName = "MyDB3.sqlite";

	std::list<Album> m_albums;
	std::list<User> m_users;
	int numOfTags;
	int numOfAlbums;
};
