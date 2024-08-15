#include <iostream>
#include "User.h"

using namespace Messenger;

User::User(std::string login, std::string userName, std::string password, int id) {
	this->login = login;
	this->userName = userName;
	this->password = password;
	this->id = id;
}

bool User::SetID(const int id) {
	this->id = id;
	return true;
}
int User::GetID() const {
	return this->id;
}

bool User::SetLogin(const std::string login) {
	this->login = login;
	return true;
}

std::string User::GetLogin() const {
	return this->login;
}

bool User::SetUserName(const std::string userName) {
	this->userName = userName;
	return true;
}
std::string User::GetUserName() const {
	return this->userName;
}

bool User::SetPassword(const std::string password) {
	this->password = password;
	return true;
}

std::string User::GetPassword() const {
	return this->password;
}

void User::AddMessage(Message message) {
	inbox.push_back(message);
}

void User::ShowInbox() const {
	for (Message message : inbox) {
		std::cout << "From: " << message.GetSenderID() << std::endl;
		std::cout << message.GetMessage() << std::endl << std::endl;
	}
}